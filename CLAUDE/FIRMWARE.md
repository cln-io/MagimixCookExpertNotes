# Magimix Cook Expert - Firmware Analysis

## Overview

Two firmware binary files were extracted from the Magimix Cook Expert kitchen appliance and fully decompiled using Ghidra (329 functions, 13,521 lines of C pseudocode).

| File | Size | Purpose |
|------|------|---------|
| `lpc1788.bin` | 225,652 bytes (220.4 KB) | Main MCU firmware (ARM Cortex-M3) |
| `flash.bin` | 1,025,067 bytes (1001.0 KB) | External SPI flash — display graphics & assets |

> See [DECOMPILED_ANALYSIS.md](DECOMPILED_ANALYSIS.md) for the full function-by-function breakdown with pseudocode.
> See [BLUETOOTH.md](BLUETOOTH.md) for the complete Bluetooth/Smart Connect protocol reverse-engineering.

---

## Processor & Hardware

### MCU: NXP LPC1788

- **Architecture**: ARM Cortex-M3 (ARMv7-M), Thumb-2 instruction set
- **Internal SRAM**: 96 KB (64 KB main at `0x10000000` + 32 KB AHB)
- **Internal Flash**: 512 KB (firmware base address `0x8000`, 32KB bootloader at `0x0000-0x7FFF`)
- **Max clock**: 120 MHz (PCLK = 60 MHz)
- **Stack pointer**: `0x1000D468` (top of 53 KB into main SRAM)

The LPC checksum at vector[7] = `0xEFF9CFFA` validates correctly (sum of first 8 vectors = 0), confirming a valid LPC bootable image.

### Display

- **Panel**: TFT LCD, **480x272** pixels
- **Color depth**: 32-bit framebuffer (24-bit RGB rendered to display)
- **Controller**: LPC1788 built-in LCD controller (`0x400A8000`)
- **Initialization**: `FUN_00006582` configures the controller, `FUN_000067c4` sets timing
- **Framebuffer**: Located at `DAT_00006970`, size `0x1FE00` words (~130 KB)
- **Theme**: Supports light/dark mode via color inversion (`FUN_00000e80`)

### Physical Inputs (13 GPIOs)

Discovered via decompilation of `FUN_00000d4c` (key scanner):

| Bits | Function |
|------|----------|
| 0-8 | 9 front panel buttons |
| 9 | Lid open/closed sensor (safety interlock) |
| 10-11 | Rotary encoder (quadrature, for temp/time adjustment) |
| 12 | Blade/accessory detection sensor |

The lid sensor implements a safety interlock (`FUN_00000674`) that prevents motor operation when the lid is open during cooking states.

### Temperature Sensing (NTC)

Decompiled from `FUN_000049b0`:

- **Method**: ADC Channel 3 with digital filtering
- **Lookup table**: 216-entry NTC resistance-to-temperature table at `DAT_00004b24`
- **Conversion**: Binary search (`FUN_000047f4`) maps ADC value → Celsius
- **Fault detection**:
  - ADC < `0x6C` → **NTC short circuit**
  - ADC < `0x217` → **NTC open circuit**
  - ADC > `0xF70` → **Overheat condition**

### Motor Control

From decompilation — the motor uses **relay-based switching**, not PWM:

- MCPWM is explicitly **disabled at boot** (bits 0-2 cleared in init)
- `FUN_0000638c` drives GPIO groups for motor enable/direction
- Speed is regulated through discrete relay-switched taps
- Motor overload is monitored with multi-language error messages

### Heater System

The largest function in the firmware — `FUN_00004aec` (2,424 bytes) — is the heater power controller. It maps temperature and remaining cook time to **8 discrete power levels** across multiple heating zones:

#### Heater Power Matrix (Zone 1)

| Temperature | < 60s | 60-180s | 180-300s | > 300s |
|-------------|-------|---------|----------|--------|
| < 50°C | 3 | 3 | 2 | 1 |
| 50-60°C | 6 | 5 | 4 | 2 |
| 60-70°C | 7 | 6 | 4 | 3 |
| 70-80°C | 8 | 7 | 5 | 3 |
| 80-90°C | 8 | 7 | 5 | 3 |
| >= 90°C | 8 | 6 | 4 | 2 |

The drop in power at >= 90°C with long remaining time (level 2) accounts for thermal inertia — preventing overshoot during slow cooking. The 8 levels likely correspond to different heating element relay combinations.

Relay switching logic in `FUN_00001316` uses a two-step safety interlock with deliberate sequencing delays.

---

## Software Architecture

### RTOS / Scheduler

The firmware runs a **custom lightweight RTOS** (no FreeRTOS/CMSIS-RTOS markers found):

- **PendSV** (`0x00014BA7`) — context switching
- **SysTick** (`0x00012295`) — system tick / time base
- **Task creation**: `FUN_00009432` (588 bytes)
- **Inter-task communication**: Mailbox-based message passing (`FUN_000096c6`)
  - Simple mailbox: stores single message
  - Queue mailbox: FIFO with signaling
- **Critical sections**: `FUN_0000cb64` (enter) / `FUN_0000cb6c` (exit)

### Boot Sequence

Decompiled from `FUN_00000578`:

```
1. Initialize LCD controller & backlight
2. Clear framebuffer to black
3. Configure SysTick timer
4. Initialize SPI flash bus
5. Initialize secondary SPI bus
6. Configure GPIO outputs
7. Disable MCPWM (motor off)
8. Configure 6 GPIO input port groups
9. Initialize EEPROM peripheral
10. Load settings from EEPROM into RAM
11. Initialize cooking state machine
12. Create software timers (tmr_beep, tmr_TimeSet, etc.)
13. Create main RTOS task
14. Initialize UART0 for Bluetooth
15. Initialize Bluetooth module
16. Start 5 periodic timers
17. Enable interrupts → main loop
```

### Software Timers

Pool-based allocator (`FUN_00009e60`), timer control blocks are 34 bytes:

| Timer | Purpose |
|-------|---------|
| `tmr_gui` | GUI refresh / display update |
| `tmr_beep` | Buzzer duration control |
| `tmr_WaitBlade` | Safety: wait for blade stop before lid unlock |
| `tmr_TimeSet` | Cooking time input timeout |

### Event System

Mailbox-based event dispatch with identified event codes:

| Code | Meaning |
|------|---------|
| `0x880` | System idle |
| `0x8F8` | Timer event |
| `0x8F9` | Bluetooth ping received |
| `0x8FB` | Cooking program change |
| `0x8FC` | Critical error (heating shutdown) |
| `0x8FD` | Warning (recoverable error) |
| `0x8FE` | Bluetooth data received |
| `0x8FF` | UI update request |

---

## Cooking State Machine

Decompiled from `FUN_00002a8e` (708 bytes):

```
[0: IDLE] → [1: MENU] → [2: SELECTED] → [3: PREHEAT] → [4: COUNTDOWN]
                                              ↓                ↓
                                         [5: STEAM]      [6: PAUSED]
                                              ↓                ↓
                                         [7: CLEANING]    [back to 4]
```

### 24 Cooking Programs

The firmware tracks per-program statistics (usage count + runtime hours) for all 24 programs:

#### Cooking Programs

| French | English | Category |
|--------|---------|----------|
| Vapeur | Steam | Cooking |
| Vapeur XXL | Steamer XXL | Cooking |
| Mijotage | Simmering | Cooking |
| Soupe velouté | Cream soup | Soup |
| Soupe moulinée | Puréed soup | Soup |
| Rissolage | Stir-Fry | Cooking |
| Rissolage doux | Gentle stir-fry | Cooking |
| Maintien au chaud | Keep warm | Utility |
| Cocotte | Casserole | Cooking |
| Cuisson | Cooking (generic) | Cooking |

#### Mixing / Prep Programs

| French | English | Category |
|--------|---------|----------|
| Smoothie | Smoothie | Blending |
| Blender | Blender | Blending |
| Robot | Food processor | Processing |
| Hot Mix | Hot Mix mode | Mixing |
| Blancs en neige | Beaten egg whites | Mixing |
| Pétrin XL | Dough hook XL | Kneading |
| Pâte / Gâteau | Pastry/Cake | Baking |
| Pain / Brioche | Bread/Brioche | Baking |
| Crêpes / Gaufres | Crêpes/Waffles | Baking |
| Chocolat | Chocolate | Dessert |
| Glace pilée | Crushed ice | Ice |
| Dessert glacé | Frozen dessert | Ice |

#### Cleaning Programs

| French | English |
|--------|---------|
| Rinçage eco | Eco rinse |
| Rinçage medium | Regular rinse |
| Rinçage intensive | Intensive rinse |

#### Special Modes

- **Expert** — Manual control of temperature, speed, and time
- **Demonstration** — Store demo mode
- **Child lock** — "Enfants" / "Kindersicherung" / "Sicurezza bimbi" / "Kinderslot"
- **Stand-by** — Configurable sleep timeout (5 / 15 / 30 minutes)
- **Boulangerie** — Bread baking mode

---

## Error Handling

Two-tier system decompiled from `FUN_0000149e`:

### Critical Errors (event `0x8FC`)
Immediate heater shutdown, enter safe state:
- NTC short circuit (ADC < `0x6C`)
- Extreme overheat (ADC > `0xF70`)
- Heater element failure

### Recoverable Errors (event `0x8FD`)
Save cooking state, disable heaters, set recovery timer:
- NTC intermittent open circuit — auto-recovers after 120 seconds
- Motor overload — auto-recovers after 3 seconds

### Safety Shutdown Sequence
`FUN_0000120c`:
1. Disable GPIO group 0 (motor relay)
2. Disable GPIO group 4 (heater relay)
3. Execute additional safety measures

### Safety Messages (6 languages)

| Language | Message |
|----------|---------|
| French | NE PAS OUVRIR AVANT L'ARRET COMPLET DES LAMES |
| English | DO NOT OPEN UNTIL BLADE STOPS |
| German | NICHT ÖFFNEN BEVOR DAS MESSER ZUM STILLSTAND GEKOMMEN IST |
| Spanish | NO ABRIR ANTES DE QUE PARE DE LA CUCHILLAS |
| Italian | APRIRE SOLAMENTE QUANDO LE LAME SARANNO FERME |
| Dutch | NIET OPENEN TOT MES VOLLEDIG TOT STILSTAND IS GEKOMEN |

---

## Bluetooth Communication

### Hardware
- **Interface**: UART0 at configurable baud rate
- **Module**: External, optional "Smart Connect" dongle
- **Init**: `FUN_0000735a` configures UART0, `FUN_000060ce` initializes BT module

### Protocol (decompiled from `FUN_00005a58`, 1,544 bytes)

Framed serial protocol with `0x5A` header byte and checksum validation:

| Command | Code | Description |
|---------|------|-------------|
| Ping | `0x0D` | Keep-alive check |
| Status | `0x0E` | Current cooking state/temperature/time |
| State Query | `0x0F` | Detailed state machine status |
| Recipe Download | `0x10` | Receive cooking recipe from app |
| Statistics | `0x11` | Usage statistics dump |
| Name Change | `0x12` | Set Bluetooth device name |
| Version Query | `0x13` | Firmware version request |
| History Dump | `0x14` | Cooking history export |

### State Machine
- `Bt_Started@` — Module initialized and advertising
- `Bt_Connect@` — Phone connected
- `Bt_Disconn@` — Phone disconnected

### Companion Apps
- Android App
- Apple App (iOS)

---

## Firmware Update (YMODEM)

Decompiled from `FUN_000079b4` (entry), `FUN_0000773e` (receiver, 450 bytes):

### Protocol
- Standard **YMODEM** file transfer over UART
- CRC mode requested with `'C'` (0x43)
- Up to 6 retries per packet

### Process
1. Reinitialize UART at update baud rate
2. Clear screen, display "Programming" text with progress bar
3. Disable SysTick timer
4. Receive firmware via YMODEM (filename + size in first packet)
5. Validate size < `0x3002` sectors (~12 MB max)
6. Erase SPI flash sectors
7. Write received data to SPI flash starting at **`0x200000`**
8. Write magic marker **`0xA55A`** to validate image
9. Display "Transmission completion. Restarting."
10. Hard reset via ARM AIRCR register (`SYSRESETREQ` + `VECTKEY`)

### SPI Flash Layout
| Address | Contents |
|---------|----------|
| `0x000000` | Graphics assets (flash.bin content) |
| `0x200000` | Firmware image (written during update) |

### Error Codes
| Code | Message |
|------|---------|
| 0 | "Programming Completed Successfully!" |
| 2 | "Aborted by user." |
| 4 | "Verification failed!" |
| 5 | "The image size is higher than the allowed space memory!" |
| other | "Failed to receive the file!" |

---

## Display & GUI

### Rendering Pipeline
- **Framebuffer**: 480x272 x 32bpp at `DAT_00006970`
- **Text engine**: `FUN_0000c624` (776 bytes) — font rendering with anti-aliased glyphs
- **Sprite renderer**: `FUN_0000c34e` (418 bytes) — decompresses RLE/raw hybrid sprites from SPI flash
- **Widget system**: `FUN_0000a7f8` (460 bytes) — reusable UI components
- **Main cooking screen**: `FUN_0000bb42` (852 bytes)
- **Menu renderer**: `FUN_0000bc96` (684 bytes)

### Graphics Format (flash.bin)
Custom hybrid RLE/raw encoding stored in external 1 MB SPI flash:

```
Opaque pixel:  [count] [00 80] [RR GG BB]
Transparent:   [count] [00 00] [FF FF FF]
```

Icons are predominantly grayscale (RGB values like `10 10 10`, `50 50 50`, `9F 9F 9F`, `EF EF EF`).

### SYSTEM Diagnostic Screen

`FUN_0000b620` (504 bytes) displays:
- Firmware version formatted as **X.XX** (major.minor)
- Motor runtime hours (offset `0xC0` from stats base, stored in seconds ÷ 3600)
- NTC/heating runtime hours (offset `0xC4`)
- Screen-on runtime hours (offset `0xC8`)

`FUN_0000b8bc` (326 bytes) shows per-program stats in a 4-column × 6-row grid (usage count + hours, capped at 999).

### Statistics Data Block

| Offset | Size | Contents |
|--------|------|----------|
| `0x00-0xBF` | 192 bytes | 24 programs × 8 bytes (4=count, 4=seconds) |
| `0xC0` | 4 bytes | Total motor runtime (seconds) |
| `0xC4` | 4 bytes | Total NTC/heating runtime (seconds) |
| `0xC8` | 4 bytes | Total screen-on runtime (seconds) |

---

## Settings Menu

| Setting | Description |
|---------|-------------|
| Languages / Langues | French, English, German, Spanish, Italian, Dutch |
| Sound / Sonido / Suono | Audio feedback control |
| Brightness / Luminosité | Light (clair) / Dark (sombre) theme |
| Display / Affichage | Screen appearance |
| Menu order / Ordre menus | Customize program ordering |
| Counter / Compteur | Usage hour counter |
| Working Hours | Total operating time |
| 12 Hours / 12 Heures | Time format toggle |
| User manual | Built-in instructions |
| Recipes / Recettes | Recipe access |
| Auto programmes | Auto cooking program config |
| Versions | Firmware version display |
| Accessories | Accessory information |
| Stand-by | Sleep mode (5/15/30 min) |

Settings stored in LPC1788 built-in EEPROM (`0x200080-0x200094`), managed by `FUN_00006e1c` / `FUN_00006e9c` / `FUN_00006f72`.

---

## Deep Sleep / Power Down

Decompiled from `FUN_00001830` (278 bytes):

1. Disable all motor/heater outputs
2. Configure GPIO wake-up interrupt (button press)
3. Set `SLEEPDEEP` bit in ARM System Control Register
4. Brief delay (6000 iterations)
5. Execute `WFI` (Wait For Interrupt) — enters deep sleep
6. On wake: re-initialize clocks, play beep (pattern varies by active cooking program)

---

## Multi-Language Support

All 6 languages ship in every unit — no separate language packs:

| Language | Code |
|----------|------|
| French | Primary (base language for all strings) |
| English | Full translation |
| German (Deutsch) | Full translation |
| Spanish (Español) | Full translation |
| Italian (Italiano) | Full translation |
| Dutch (Nederlands) | Full translation |

---

## Hardware Architecture

```
┌──────────────────────────────────────────────────────┐
│                  Magimix Cook Expert                  │
├──────────────────────────────────────────────────────┤
│                                                       │
│  ┌───────────────┐      ┌─────────────────────┐     │
│  │  NXP LPC1788  │─LCD─▶│  480x272 TFT Panel  │     │
│  │  ARM Cortex-M3│      │  32-bit framebuffer  │     │
│  │  120 MHz      │      └─────────────────────┘     │
│  └───────┬───────┘                                   │
│          │                                            │
│  ┌───────┴────────┐                                  │
│  │  SPI ──────────┼──▶ 1MB External Flash (graphics) │
│  │                │     0x000000: sprites/fonts       │
│  │                │     0x200000: firmware image      │
│  │                │                                   │
│  │  UART0 ────────┼──▶ Bluetooth Module              │
│  │                │    (Smart Connect, optional)      │
│  │                │    Protocol: 0x5A framed, 8 cmds  │
│  │                │                                   │
│  │  ADC Ch3 ──────┼──▶ NTC Thermistor                │
│  │                │    216-entry lookup table         │
│  │                │    Fault: short/open/overheat     │
│  │                │                                   │
│  │  GPIO ─────────┼──▶ Motor Relays (discrete speed) │
│  │                │──▶ Heater Relays (8 power levels) │
│  │                │──▶ 9 Buttons                     │
│  │                │──▶ Rotary Encoder (quadrature)    │
│  │                │──▶ Lid Sensor (safety interlock)  │
│  │                │──▶ Blade Detection Sensor         │
│  │                │──▶ Buzzer                         │
│  │                │──▶ Status LEDs                    │
│  │                │                                   │
│  │  EEPROM ───────┼──▶ Settings / Stats Storage      │
│  │                │    (0x200080-0x200094)            │
│  └────────────────┘                                  │
│                                                       │
└──────────────────────────────────────────────────────┘
```

---

## Key Findings Summary

1. **Custom RTOS** — Lightweight custom scheduler with mailbox IPC, not FreeRTOS. PendSV for context switching, SysTick for time base.

2. **Relay-based motor** — No PWM. Motor speed via discrete relay taps. MCPWM explicitly disabled at boot.

3. **Sophisticated heater control** — 2,424-byte function maps temperature × time → 8 power levels with thermal inertia compensation.

4. **YMODEM firmware update** — Over UART to SPI flash at `0x200000` with `0xA55A` magic validation. Hard reset via AIRCR after flash.

5. **Bluetooth optional** — "Smart Connect" dongle, framed protocol (`0x5A` header), 8 command types including recipe download and history export.

6. **NTC with triple fault detection** — Short, open, and overheat detection via ADC thresholds.

7. **Two-tier error handling** — Critical errors (immediate shutdown, event `0x8FC`) vs recoverable errors (auto-retry with timers, event `0x8FD`).

8. **24 cooking programs** — Each with usage count + runtime hours, displayed on diagnostic screen (capped at 999h).

9. **13 physical inputs** — 9 buttons, lid interlock, rotary encoder (quadrature), blade detection.

10. **Deep sleep with WFI** — ARM deep sleep mode, GPIO wake-up interrupt, beep pattern varies by cooking program.

11. **480x272 TFT** with 32-bit framebuffer, custom RLE sprite compression, light/dark theme support.

12. **All 6 languages baked in** — French (primary), English, German, Spanish, Italian, Dutch.
