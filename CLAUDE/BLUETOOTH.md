# Magimix Cook Expert - Bluetooth / Smart Connect Protocol

> Reverse-engineered from firmware `lpc1788.bin` (225,652 bytes, base address `0x8000`)
> NXP LPC1788 ARM Cortex-M3, 120 MHz, PCLK = 60 MHz

---

## Table of Contents

1. [Hardware Overview](#1-hardware-overview)
2. [UART Configuration](#2-uart-configuration)
3. [Protocol Frame Format](#3-protocol-frame-format)
4. [CRC-8 Checksum](#4-crc-8-checksum)
5. [Command Reference](#5-command-reference)
   - [0x0D - Ping / Keep-Alive](#0x0d---ping--keep-alive)
   - [0x0E - Device Info](#0x0e---device-info)
   - [0x0F - Status Query](#0x0f---status-query)
   - [0x10 - Recipe Download](#0x10---recipe-download)
   - [0x11 - Statistics Summary](#0x11---statistics-summary)
   - [0x12 - Name Change](#0x12---name-change)
   - [0x13 - Version Query](#0x13---version-query)
   - [0x14 - History Dump](#0x14---history-dump)
6. [Cooking States](#6-cooking-states)
7. [Sleep / Wake Mechanism](#7-sleep--wake-mechanism)
8. [BT Connection State Machine](#8-bt-connection-state-machine)
9. [DIY Smart Connect](#9-diy-smart-connect)
10. [Implementation Notes](#10-implementation-notes)

---

## 1. Hardware Overview

### The USB Port is NOT USB

The firmware contains **zero USB peripheral code**. No USB controller registers
(`0x2008C000`, `0x5000C200`) are referenced anywhere in the 329 decompiled functions.

The USB-A connector on the Cook Expert is a **physical connector carrying UART serial
lines**. The pinout maps to the LPC1788's UART0 peripheral on pins P0.2 (TXD) and P0.3 (RXD).

| USB-A Pin | Signal | LPC1788 Pin |
|-----------|--------|-------------|
| 1 (VBUS)  | +5V    | Module power |
| 2 (D-)    | TXD0 or RXD0 | P0.2 (IOCON `0x4002C008`) |
| 3 (D+)    | RXD0 or TXD0 | P0.3 (IOCON `0x4002C00C`) |
| 4 (GND)   | GND    | Ground |

> **Note:** The exact D-/D+ to TX/RX mapping needs physical verification with a
> multimeter or logic analyzer on the PCB.

### The Official Smart Connect Dongle

The Magimix "Smart Connect" accessory is a Bluetooth-to-UART bridge module packaged
in a USB-A form factor. It contains:
- A BT module pre-configured at 115200 baud
- Power from the USB 5V line
- UART TX/RX on the data pins

The firmware UI references it as "Smart Connect key" in multiple languages:
- `"No Smart Connect key"` (English, 0x35F8B)
- `"Smart Connect absente"` (French, 0x35F5F)
- `"Kein Smart Connect Schl..."` (German, 0x35FB3)
- `"Geen Smart Connect key aanwezig"` (Dutch, 0x36010)

---

## 2. UART Configuration

**Peripheral:** UART0 at register base `0x4000C000`
**Initialization function:** `FUN_0000735a` (address `0x735A`, 144 bytes)

| Parameter | Value | Details |
|-----------|-------|---------|
| Baud rate | **115200** | `0x1C200`, confirmed from boot sequence at `0x5E8` |
| Data bits | 8 | LCR = `0x03` |
| Parity | None | LCR bit 3 = 0 |
| Stop bits | 1 | LCR bit 2 = 0 |
| FIFO | Enabled | FCR = `0xC7` (FIFO on, RX/TX reset, trigger level 14 bytes) |
| PCLK | 60 MHz | `DAT_00000668` = `0x03938700` = 60,000,000 |
| Divisor | ~32.55 | With fractional divider for accuracy |
| IRQ | #5 | NVIC IRQ 5 = UART0 on LPC1788 |
| Interrupts | RBR + THRE + RLS | IER = `0x07` |

### UART Register Map (via `DAT_000074d0` = `0x4000C000`)

| Offset | Register | Usage |
|--------|----------|-------|
| `+0x00` | RBR/THR/DLL | Read: receive, Write: transmit, DLAB: divisor low |
| `+0x04` | IER/DLM | Interrupt enable / DLAB: divisor high |
| `+0x08` | IIR/FCR | Read: interrupt ID, Write: FIFO control |
| `+0x0C` | LCR | Line control (data bits, parity, stop, DLAB) |
| `+0x14` | LSR | Line status (data ready, errors, TX empty) |

### Ring Buffer Architecture

```
UART0 ISR (FUN_00007434)
  ├─ RDA (IIR type 2): FUN_0000727c(0) → stores bytes to RX buffer
  ├─ CTI (IIR type 6): FUN_0000727c(1) → stores bytes + signals semaphore
  ├─ THRE (IIR type 1): FUN_000072ae() → drains TX buffer (up to 16 bytes)
  └─ RLS (IIR type 3): reads RBR to clear error flags

Ring Buffer Control Block (8 bytes):
  Offset 0: Write head index (byte)
  Offset 1: Read head index (byte)
  Offset 2: Current count (byte)
  Offset 3: Capacity (byte) = 64
  Offset 4: Data buffer pointer (4 bytes)

TX Ring Buffer: DAT_000074e0 (control) → DAT_000074ec (64-byte data)
RX Buffer:     DAT_000074d8 (256-byte linear buffer, written by ISR)
BT Frame:      DAT_00005dec (64-byte assembled frame)
```

---

## 3. Protocol Frame Format

Every message uses a simple framed format with a `0x5A` header byte:

```
┌──────┬────────┬──────────────────┬──────────┐
│ 0x5A │ CmdID  │ Payload...       │ Checksum │
│  1B  │  1B    │ 0-193B           │   1B     │
└──────┴────────┴──────────────────┴──────────┘
```

### Checksum Position Rules

| Command | Checksum Position |
|---------|-------------------|
| `0x10` (Recipe Download) | `frame[2] - 1` (variable length) |
| `0x12` (Name Change) | `frame[2] - 1` (variable length) |
| All others (`0x0D`, `0x0E`, `0x0F`, `0x11`, `0x13`, `0x14`) | Byte 2 (frame is 3 bytes) |

For simple commands (3-byte request), the frame is:
```
[0x5A] [CmdID] [Checksum]
```

For variable-length commands, byte 2 is the total frame length, and the checksum is the last byte.

---

## 4. CRC-8 Checksum

The checksum is a **CRC-8 using polynomial `0xFF`** with a 16-entry nibble lookup table.

**Function:** `FUN_000059d4` (address `0x59D4`, 60 bytes)

### Algorithm

```c
static const uint8_t crc_table[16] = {
    0x00, 0xFF, 0x01, 0xFE, 0x02, 0xFD, 0x03, 0xFC,
    0x04, 0xFB, 0x05, 0xFA, 0x06, 0xF9, 0x07, 0xF8
};

uint8_t crc8(const uint8_t *data, int len) {
    uint8_t crc = 0;
    for (int i = 0; i < len; i++) {
        crc = crc_table[(crc >> 4) ^ (data[i] >> 4)] ^ ((crc << 4) & 0xFF);
        crc = crc_table[(crc >> 4) ^ (data[i] & 0x0F)] ^ ((crc << 4) & 0xFF);
    }
    return crc;
}
```

### Verification

The CRC is computed over all bytes **before** the checksum position. Appending the
computed CRC and re-computing over the full frame yields `0x00`:

```
CRC8([0x5A, 0x0D])       = 0x10   → Ping request:  [5A 0D 10]
CRC8([0x5A, 0x0D, 0x10]) = 0x00   → Valid ✓

CRC8([0x5A, 0x0E])       = 0xEE   → Info request:  [5A 0E EE]
CRC8([0x5A, 0x0E, 0xEE]) = 0x00   → Valid ✓
```

---

## 5. Command Reference

### 0x0D - Ping / Keep-Alive

Wakes the device from standby and resets the sleep timer. Only accepted in cooking states 0-3.

**Request (3 bytes):**
```
[0x5A] [0x0D] [CRC]
```

**Response (3 bytes):**
```
[0x5A] [0x0D] [CRC]
```

**Side effects:**
- Posts event `0x8F9` (BT ping received) to the main task mailbox
- Resets the standby countdown timer, preventing sleep
- Debug string: `"Bt_Started"` (0x0DAFD)

---

### 0x0E - Device Info

Returns 18 bytes of device information including model, firmware parameters, and status.

**Request (3 bytes):**
```
[0x5A] [0x0E] [CRC]
```

**Response (18 bytes):**
```
Offset  Field
------  -----
0       0x5A
1       0x0E
2       0x12 (length = 18)
3       Program count / model ID (from DAT_00005e0c[2])
4       Config byte 1 (from DAT_00005e10[1])
5       Config byte 2 (from DAT_00005e10[2])
6       Config byte 3
7       Config byte 4
8       Config byte 5
9       Config byte 6
10      Config byte 7
11      (skipped: DAT_00005e10[8])
12      Config byte 9
13      Config byte 10
14      Config byte 11
15      0xFF (sentinel)
16      Config byte 13
17      CRC checksum
```

---

### 0x0F - Status Query

Returns 16 bytes of real-time cooking status. The payload structure changes depending
on the current cooking state and program type.

**Request (3 bytes):**
```
[0x5A] [0x0F] [CRC]
```

**Response (16 bytes):**
```
Offset  Field
------  -----
0       0x5A
1       0x0F
2       0x10 (length = 16)
3       Cooking state (0-7, see §6)
4       Program parameter for current type
5       Speed / temperature / mode (context-dependent)
6       Countdown minutes (high byte) OR packed temp
7       Countdown minutes (low byte) OR motor speed
8       Timer seconds remaining
9       Timer mode / flags
10      Elapsed time indicator
11      Actual temperature reading (0xFF if N/A)
12      Actual motor RPM reading (0xFF if N/A)
13      Error/warning code
14      Safety flags (see below)
15      CRC checksum
```

**Safety flags byte (offset 14):**
| Bit | Meaning |
|-----|---------|
| 0   | Lid sensor (1 = open) |
| 1   | Blade/accessory detected |
| 2   | Active operation in progress |

**Byte 5 varies by program type and state:**

| Program Type | State | Byte 5 Content |
|--------------|-------|----------------|
| 0 (Temperature cooking) | 2 (SELECTED) | Target temperature |
| 0 (Temperature cooking) | 3 (PREHEAT) | Target temperature |
| 1 (Mixing/blending) | 2-3 | Speed setting |
| 2+ (Other modes) | 2 | Speed setting |
| 2+ (Other modes) | 3-6 (Active) | Speed + full timer/temp data |
| Any | 7 (CLEANING) | Speed + error + flags only |

When active (states 3-6, program types 2+), bytes 6-14 carry full data:
speed, countdown timer (min:sec), timer mode, elapsed time, actual temperature,
actual motor RPM, error code, and safety flags.

Bytes default to `0xFF` when not applicable (filled by `FUN_00005a22`).

---

### 0x10 - Recipe Download

Sends a cooking recipe from the phone app to the device. Includes comprehensive
parameter validation before accepting.

**Request (variable, typically ~14 bytes):**
```
Offset  Field
------  -----
0       0x5A
1       0x10
2       Frame length
3       Program type (0-7, or 0xFF = default)
4       Speed setting (raw, remapped via lookup table)
5       Speed minimum threshold
6       Duration (high byte, big-endian uint16)
7       Duration (low byte) — in seconds × 60
8       Temperature setting
9       Motor speed extra parameter
10      Cooking mode / direction (0-1, or 0xFF = default)
N-1     CRC checksum (at position frame[2]-1)
```

**Response (4 bytes):**
```
[0x5A] [RecipeID] [ValidationResult] [CRC]
```

**Validation Error Codes:**

| Code | Meaning |
|------|---------|
| `0x00` | Valid - recipe accepted and loaded |
| `0x01` | Program type out of range (must be < 8 or 0xFF) |
| `0x02` | Speed index out of range (must be < 9 or 0xFF) |
| `0x04` | Speed below minimum for this program |
| `0x08` | Duration exceeds maximum for this program |
| `0x10` | Temperature exceeds maximum for this program |
| `0x20` | Motor speed exceeds program limit |
| `0x40` | Cooking mode invalid (must be < 2 or 0xFF) |

**On success (code 0x00):**
- 8 parameter bytes are copied to the active recipe buffer
- Event `0x8FA` is posted to the cooking task mailbox
- The cooking state machine transitions to execute the recipe

**Lookup Tables:**

| Table | Address | Purpose |
|-------|---------|---------|
| `DAT_00006194` | RAM | Speed remapping: `internal = table[raw_speed]` |
| `DAT_00006198` | RAM | Speed-to-recipe-index mapping |
| `DAT_0000619c` | Flash `0x15692` | Per-recipe temperature limits (10 bytes/entry, max temp at +3) |
| `DAT_000061a0` | RAM | Default parameters (default temp at +5) |

---

### 0x11 - Statistics Summary

Returns three 32-bit aggregate runtime counters.

**Request (3 bytes):**
```
[0x5A] [0x11] [CRC]
```

**Response (16 bytes):**
```
Offset  Field
------  -----
0       0x5A
1       0x11
2       0x10 (length = 16)
3-6     Total motor runtime (seconds, big-endian uint32)
7-10    Total heating runtime (seconds, big-endian uint32)
11-14   Total screen-on runtime (seconds, big-endian uint32)
15      CRC checksum
```

Statistics are stored at offsets from `DAT_00005e40`:
- `+0xC0` = motor runtime
- `+0xC4` = NTC/heating runtime
- `+0xC8` = screen-on runtime

---

### 0x12 - Name Change

Sets the Bluetooth device name. Maximum 26 characters.

**Request (7-30 bytes):**
```
Offset  Field
------  -----
0       0x5A
1       0x12
2       Frame length (max 0x1E = 30)
3..N-2  Name bytes (max 26 chars)
N-1     CRC checksum (at position frame[2]-1)
```

**Response (3 bytes):**
```
[0x5A] [0x12] [CRC]
```

**Side effects:**
- Name is copied to `DAT_000061b4` (settings structure in RAM)
- `FUN_0000bac2` updates the on-screen display immediately (if on BT settings screen)
- Name is persisted to EEPROM by the auto-save mechanism

---

### 0x13 - Version Query

Returns firmware version and build information.

**Request (3 bytes):**
```
[0x5A] [0x13] [CRC]
```

**Response (12 bytes):**
```
Offset  Field
------  -----
0       0x5A
1       0x13
2       0x0C (length = 12)
3-8     Firmware version (6 bytes, likely BCD: X.XX format)
9       Build info byte 1 (possibly HW revision)
10      Build info byte 2 (possibly BT module version)
11      CRC checksum
```

Version data is stored at `DAT_00006184` (6 bytes) + `DAT_00006188` and `DAT_0000618c`
(1 byte each), loaded from EEPROM settings during boot by `FUN_000002e8`.

---

### 0x14 - History Dump

Returns per-program usage statistics for all 24 cooking programs.

**Request (3 bytes):**
```
[0x5A] [0x14] [CRC]
```

**Response (196 bytes):**
```
Offset  Field
------  -----
0       0x5A
1       0x14
2       0xC4 (length = 196)
3-194   24 programs × 8 bytes each = 192 bytes
195     CRC checksum
```

**Per-program entry (8 bytes, big-endian):**
```
Bytes 0-3: Usage count (uint32)
Bytes 4-7: Total runtime in seconds (uint32)
```

Program order is determined by the remapping table at `DAT_00005e44` (24 bytes),
which maps BT protocol program indices to internal storage indices:
```
internal_index = remap_table[bt_program_number]
stats_offset = internal_index * 8
```

---

### Unknown Commands (Default Handler)

Any unrecognized command byte receives a 3-byte ACK and generates a computed event:

```
event_code = (1 << (cmd_byte - 1)) + 0x800
```

---

## 6. Cooking States

The cooking state machine position is reported in Status Query (byte 3) and
controls which BT commands are accepted:

| State | Meaning | BT Ping Accepted? |
|-------|---------|-------------------|
| 0 | IDLE | Yes |
| 1 | MENU / SELECTING | Yes |
| 2 | PROGRAM SELECTED | Yes |
| 3 | PREHEATING / STARTING | Yes |
| 4 | COOKING (active) | No |
| 5 | PAUSED | No |
| 6 | FINISHING | No |
| 7 | CLEANING | No |
| 8 | DEEP SLEEP | N/A (UART disabled) |

---

## 7. Sleep / Wake Mechanism

### Wake via BT Ping

1. BT module sends ping (`0x0D`) over UART0
2. UART0 ISR fires, stores bytes in RX buffer
3. BT task wakes on semaphore, processes frame
4. Event `0x8F9` posted to main task mailbox
5. Main task resets standby countdown timer

### Pre-Sleep Shutdown Sequence

When the standby countdown reaches 1:
```
1. FUN_000073ea()  → Disable UART0 interrupt (silence BT)
2. FUN_00009b10(4) → Stop RTOS timer #4
3. FUN_00004484(0xd6) → Send shutdown to SPI flash
4. Save cooking state to EEPROM
5. Save statistics to EEPROM
```

When countdown reaches 0:
```
6. FUN_00001830() → Enter deep sleep (WFI instruction)
```

UART0 is disabled **one tick before** deep sleep to prevent partial frame reception
during shutdown.

---

## 8. BT Connection State Machine

Debug strings in the firmware reveal three BT states:

| Address | String | State |
|---------|--------|-------|
| `0x0DAFD` | `"Bt_Started"` | Module initialized |
| `0x0DB0A` | `"Bt_Connect"` | Connection established |
| `0x0DB17` | `"Bt_Disconn"` | Disconnected |

UI strings for the user:
- `"Connected to phone"` (0x3610A)
- `"No device connected"` (0x3606E)
- `"Connect"` (0x360F2)

### BT Initialization (Boot Sequence)

BT init is **conditional** on config byte at offset `0x0D` in the settings structure:

```arm
0x5F6: ldr   r0, [pc, #0x44]     ; load config struct
0x5F8: ldrb  r0, [r0, #0xd]      ; read BT enable flag
0x5FA: cbz   r0, #0x60e          ; if zero → skip BT init
0x5FC: bl    #0xbb0c             ; BT splash/screen init
0x600: movs  r0, #1
0x602: bl    #0x6418             ; GPIO pin configuration
0x606: mov.w r0, #500
0x60A: bl    #0x9cc0             ; delay 500ms (module boot time)
```

Units without the Smart Connect module have this flag set to 0, which
skips the BT initialization entirely. The BT module itself requires no
AT command configuration from the firmware — it arrives pre-configured.

---

## 9. DIY Smart Connect

### Why Generic USB BT Dongles Don't Work

- The USB port carries **UART signals, not USB protocol**
- No USB driver exists in the firmware
- Generic dongles speak USB HID/BT, which is incompatible

### What You Need

1. **A UART Bluetooth module** — HC-05 (Classic BT) or HM-10/HM-19 (BLE)
2. **Pre-configure the module** to 115200 baud, 8N1 via AT commands
3. **Wire it to a USB-A plug:**

```
USB-A Pin 1 (VBUS) ──→ Module VCC (+5V, or through 3.3V regulator)
USB-A Pin 2 (D-)   ──→ Module TXD or RXD (verify with multimeter)
USB-A Pin 3 (D+)   ──→ Module RXD or TXD (verify with multimeter)
USB-A Pin 4 (GND)  ──→ Module GND
```

> **WARNING:** The LPC1788 UART0 is 3.3V logic. If the USB connector routes
> directly to the MCU pins, you need a 3.3V BT module or level shifter.
> The original Smart Connect dongle likely handles this internally.

### Even Simpler: Direct Serial Connection

Connect a **USB-to-UART adapter** (FTDI, CP2102, CH340) to the machine's
USB port and talk directly from a computer:

```
USB-A Pin 1 → +5V (or leave unconnected)
USB-A Pin 2 → FTDI TXD or RXD
USB-A Pin 3 → FTDI RXD or TXD
USB-A Pin 4 → FTDI GND
```

Then open a serial terminal at **115200 8N1** and send commands using
the 0x5A protocol documented above.

### Enabling BT in Firmware

The BT feature flag at config offset `0x0D` must be non-zero. Options:
- Write to the LPC1788 internal EEPROM at `0x200080 + 0x0D`
- Or simply keep sending data — the UART0 is initialized regardless
  of the BT flag; the flag only controls the BT splash screen and
  GPIO pin setup at boot

---

## 10. Implementation Notes

### Firmware Architecture

- **Base address:** `0x8000` (32KB bootloader at `0x0000-0x7FFF`)
- **CRC table:** Stored compressed in `.data` section, decompressed to RAM at startup
- **No AT commands:** The firmware sends zero initialization commands to the BT module
- **Ring buffer:** 64-byte circular FIFO for TX, ISR-driven
- **Frame processing:** RX buffer and BT frame buffer share the same address (`0x100074CE`)

### Key Function Addresses

| Function | Address | Size | Purpose |
|----------|---------|------|---------|
| `FUN_0000735a` | `0x735A` | 144B | UART0 init (pins, baud, FIFO, IRQ) |
| `FUN_000060ce` | `0x60CE` | 22B | BT module init (create task + clear buffers) |
| `FUN_00005a58` | `0x5A58` | 1544B | BT protocol handler (all 8 commands) |
| `FUN_000059d4` | `0x59D4` | 60B | CRC-8 checksum calculation |
| `FUN_00007434` | `0x7434` | 76B | UART0 IRQ handler (IIR dispatch) |
| `FUN_0000727c` | `0x727C` | 50B | UART0 RX: bytes → ring buffer |
| `FUN_000072ae` | `0x72AE` | 38B | UART0 TX: ring buffer → THR (16 bytes max) |
| `FUN_00007480` | `0x7480` | 78B | UART0 transmit N bytes |
| `FUN_000072d4` | `0x72D4` | 134B | Baud rate divisor calculation (float math) |
| `FUN_000073ea` | `0x73EA` | 74B | UART0 disable (for sleep) |
| `FUN_00005a10` | `0x5A10` | 18B | Clear BT receive buffer |
| `FUN_00005a36` | `0x5A36` | 34B | Build safety flags byte |
| `FUN_0000bac2` | `0xBAC2` | 74B | BT name change UI update |

### Key Data Addresses

| Symbol | RAM Address | Purpose |
|--------|-------------|---------|
| UART0 base | `0x4000C000` | UART0 peripheral registers |
| IOCON base | `0x4002C000` | Pin configuration (+8 = TXD0, +C = RXD0) |
| PCONP | `0x400FC0C4` | Peripheral clock control (bit 2 = UART0) |
| TX ring buffer ctl | via `DAT_000074e0` | 8-byte control block |
| TX ring buffer data | via `DAT_000074ec` | 64-byte data buffer |
| RX buffer | `0x100074CE` | 256-byte linear buffer (ISR writes here) |
| BT frame buffer | `0x100074CE` | Same as RX buffer (processed in-place) |
| BT frame counter | via `DAT_00005df0` | Current position in frame |
| Cooking state | via `DAT_00005e00` | State machine position (0-8) |
| Event register | via `DAT_00005e04` | Event code for main task |
| Settings struct | `0x10007094` | Config loaded from EEPROM (BT flag at +0xD) |
| BT name storage | via `DAT_000061b4` | Device name (max 26 chars) |
| Statistics base | via `DAT_00005e40` | Per-program usage data |
| Program remap | via `DAT_00005e44` | 24-byte index mapping table |

### Quick Reference: All Request Frames

```
Ping:       5A 0D 10
Dev Info:   5A 0E EE
Status:     5A 0F xx  (compute CRC)
Stats:      5A 11 xx  (compute CRC)
Version:    5A 13 xx  (compute CRC)
History:    5A 14 xx  (compute CRC)
Recipe:     5A 10 [len] [params...] [CRC]
Name:       5A 12 [len] [name...] [CRC]
```
