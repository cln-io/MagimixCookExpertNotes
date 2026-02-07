# Magimix Cook Expert Firmware - Decompiled Analysis

## Overview

This document provides a comprehensive analysis of the decompiled firmware for the **Magimix Cook Expert** kitchen appliance. The firmware runs on an **NXP LPC1788 ARM Cortex-M3** processor and was decompiled using Ghidra. The decompiled output contains **13,521 lines** across **329 functions**.

The firmware manages all aspects of the appliance: display rendering, temperature control, motor drive, user input, Bluetooth communication, cooking program execution, and firmware updates.

---

## Table of Contents

1. [Largest and Most Important Functions](#1-largest-and-most-important-functions)
2. [Main Entry Point and Main Loop](#2-main-entry-point-and-main-loop)
3. [Timer / Scheduler System](#3-timer--scheduler-system)
4. [GPIO Initialization](#4-gpio-initialization)
5. [Motor Control](#5-motor-control)
6. [Temperature Reading (NTC Sensor)](#6-temperature-reading-ntc-sensor)
7. [Display / GUI Functions](#7-display--gui-functions)
8. [Bluetooth Communication (UART)](#8-bluetooth-communication-uart)
9. [Cooking Program Logic](#9-cooking-program-logic)
10. [Error Handling](#10-error-handling)
11. [SYSTEM Diagnostic Screen](#11-system-diagnostic-screen)
12. [Firmware Update Protocol](#12-firmware-update-protocol)

---

## 1. Largest and Most Important Functions

The following table lists the largest functions (>100 bytes) sorted by size descending. Functions above 400 bytes represent the core logic of the firmware.

| Function | Address | Size (bytes) | Interpreted Purpose |
|----------|---------|-------------|---------------------|
| FUN_00004aec | 0x00004aec | 2424 | Heater power control - maps temperature/time to power levels |
| FUN_00005a58 | 0x00005a58 | 1544 | Bluetooth serial protocol handler |
| FUN_0000bb42 | 0x0000bb42 | 852 | GUI rendering / screen layout (main cooking screen) |
| FUN_0000c624 | 0x0000c624 | 776 | Font/text rendering engine |
| FUN_00002a8e | 0x00002a8e | 708 | Main cooking state machine |
| FUN_0000bc96 | 0x0000bc96 | 684 | Menu / navigation screen renderer |
| FUN_000002e8 | 0x000002e8 | 656 | EEPROM settings loader (startup config) |
| FUN_00009432 | 0x00009432 | 588 | RTOS task/thread creation |
| FUN_00002610 | 0x00002610 | 584 | Motor speed display update |
| FUN_0000b620 | 0x0000b620 | 504 | SYSTEM diagnostic screen |
| FUN_00000810 | 0x00000810 | 478 | Main UI event handler |
| FUN_0000773e | 0x0000773e | 450 | YMODEM firmware file receiver |
| FUN_0000a7f8 | 0x0000a7f8 | 460 | GUI widget rendering system |
| FUN_0000c34e | 0x0000c34e | 418 | Compressed sprite/bitmap renderer |
| FUN_00002398 | 0x00002398 | 386 | Cooking mode auto-save / timer handler |
| FUN_000067c4 | 0x000067c4 | 332 | LCD timing configuration |
| FUN_0000b8bc | 0x0000b8bc | 326 | Statistics display (per-program runtime hours) |
| FUN_000049b0 | 0x000049b0 | 316 | NTC temperature reading (ADC) |
| FUN_0000c34e | 0x0000c34e | 306 | Compressed bitmap sprite renderer |
| FUN_00001316 | 0x00001316 | 296 | Heater relay switching logic |
| FUN_0000695c | 0x0000695c | 290 | SPI Flash read with checksum |
| FUN_00006582 | 0x00006582 | 274 | LCD controller initialization |

### Interpretation

The single largest function, **FUN_00004aec** (2,424 bytes), is the heater power control algorithm. It contains deeply nested temperature and time range comparisons that map cooking parameters to 8 discrete power levels. This function is the heart of the cooking control system.

The second largest, **FUN_00005a58** (1,544 bytes), handles the entire Bluetooth serial protocol including command parsing, response generation, recipe downloads, and status reporting.

---

## 2. Main Entry Point and Main Loop

### System Initialization: FUN_00000578 (Address: 0x00000578, 164 bytes)

This is the primary initialization function called at boot. It brings up all hardware subsystems in sequence:

```c
void FUN_00000578(void) {
    FUN_00006582();              // Initialize LCD controller hardware
    FUN_000067c4();              // Configure LCD timing parameters
    FUN_00006910(1);             // Turn LCD backlight ON
    FUN_000066b8(0);             // Clear framebuffer to black (fill 0x1FE00 words)
    FUN_0000a2b6(DAT_00000650); // Configure SysTick timer (system heartbeat)
    FUN_000069a0();              // Initialize SPI Flash (I2C-like bus)
    FUN_00007168();              // Initialize secondary SPI bus
    FUN_000063c2();              // Configure GPIO outputs
    // Disable Timer2 (MCPWM) - clear bits 0-2 of control register
    *(uint *)(DAT_00000654 + 0x7c) = *(uint *)(DAT_00000654 + 0x7c) & 0xfffffff8;
    FUN_00000200(DAT_00000658, 0x1f); // Clear bit 31 of clock control
    FUN_000062a6();              // Configure GPIO input pins (6 port groups)
    FUN_00006e1c();              // Initialize EEPROM peripheral
    FUN_000002e8();              // Load settings from EEPROM into RAM
    FUN_00001028();              // Initialize cooking program state machine
    // Calculate initial timer value from program settings
    *DAT_00000660 = (uint)*(ushort *)(DAT_0000065c + (uint)*(byte *)(DAT_0000063c + 1) * 2) * 0x3c;
    FUN_00006206();              // Create software timers (tmr_beep, tmr_TimeSet, etc.)
    uVar1 = FUN_00009432(0);    // Create RTOS task (main processing thread)
    *DAT_00000664 = uVar1;      // Store task handle
    FUN_0000735a(DAT_00000668, &DAT_0001c200); // Initialize UART0 for Bluetooth
    FUN_000060ce();              // Initialize Bluetooth module
    if (*(char *)(DAT_0000063c + 0xd) != '\0') {
        FUN_0000bb0c();          // Restore display state if previously active
        FUN_00006418(1);         // Set GPIO output (buzzer or indicator)
        FUN_00009cc0(500);       // Delay 500ms
    }
    FUN_00000212();              // Start 5 periodic timers (see timer section)
    FUN_000098c6(0xff);         // Enable all interrupts (BASEPRI = 0xFF)
}
```

### Periodic Timer Setup: FUN_00000212 (Address: 0x00000212, 76 bytes)

After initialization, 5 periodic timers are started with different priorities:

```c
void FUN_00000212(void) {
    FUN_00009832(DAT_00000618, 0, DAT_00000614, 3);  // Timer 1 - priority 3
    FUN_00009832(DAT_00000620, 0, DAT_0000061c, 7);  // Timer 2 - priority 7
    FUN_00009832(DAT_00000628, 0, DAT_00000624, 5);  // Timer 3 - priority 5
    FUN_00009832(DAT_00000630, 0, DAT_0000062c, 4);  // Timer 4 - priority 4
    FUN_00009832(DAT_00000638, 0, DAT_00000634, 8);  // Timer 5 - priority 8
}
```

### Interpretation

The system follows a typical embedded initialization pattern: hardware peripherals are configured first (LCD, SPI, GPIO, EEPROM), then software state is restored from non-volatile memory, the RTOS kernel creates the main task, and finally periodic timers begin driving the application logic. The 5 periodic timers likely correspond to:
- Temperature/ADC sampling
- UI refresh / input polling
- Cooking countdown management
- Bluetooth communication polling
- EEPROM auto-save / statistics update

---

## 3. Timer / Scheduler System

### SysTick Configuration: FUN_0000a2b6 (Address: 0x0000a2b6, 42 bytes)

The ARM Cortex-M3 SysTick timer provides the fundamental time base:

```c
void FUN_0000a2b6(int param_1) {
    _DAT_e000e014 = param_1 - 1;        // SysTick Reload Value Register
    *DAT_0000a2ec = 0xff;                // Set SysTick interrupt priority to lowest
    _DAT_e000e010 = _DAT_e000e010 | 7;  // Enable SysTick, interrupt, use processor clock
}
```

The SysTick timer at addresses `0xE000E010` (Control) and `0xE000E014` (Reload) is the standard ARM Cortex-M3 system timer. Setting bits 0-2 of the control register enables the counter, enables the interrupt, and selects the processor clock as source.

### Software Timer Creation: FUN_00009e60 (Address: 0x00009e60, 92 bytes)

Software timers are created through a pool-based allocator:

```c
int FUN_00009e60(undefined4 period, undefined4 mode, undefined auto_reload,
                 undefined4 callback, undefined4 callback_arg,
                 undefined4 param_6, undefined *error_code) {
    if (*DAT_0000a1ac == '\0') {     // Check if scheduler is initialized
        FUN_000081c6();               // Enter critical section
        iVar1 = FUN_00009dfc();       // Allocate timer control block from pool
        if (iVar1 == 0) {
            FUN_000080c2();           // Exit critical section
            *error_code = 0x86;       // Error: no timers available
            return 0;
        }
        *(undefined *)(iVar1 + 0x21) = 1;      // Mark as active
        *(undefined4 *)(iVar1 + 0x18) = period;     // Timer period (ticks)
        *(undefined4 *)(iVar1 + 0x1c) = mode;       // Timer mode
        *(undefined *)(iVar1 + 0x20) = auto_reload;  // Auto-reload flag
        *(undefined4 *)(iVar1 + 4) = callback;       // Callback function pointer
        *(undefined4 *)(iVar1 + 8) = callback_arg;   // Callback argument
        FUN_000080c2();               // Exit critical section
        *error_code = 0;              // Success
    } else {
        *error_code = 0x8b;           // Error: scheduler not ready
        iVar1 = 0;
    }
    return iVar1;
}
```

### Timer Deletion: FUN_00009ebc (Address: 0x00009ebc, 52 bytes)

Timers are returned to a free list when deleted:

```c
void FUN_00009ebc(int timer) {
    *(undefined *)(timer + 0x21) = 0;   // Clear active flag
    *(undefined *)(timer + 0x20) = 0;   // Clear auto-reload
    *(undefined4 *)(timer + 0x1c) = 0;  // Clear mode
    *(undefined4 *)(timer + 0x14) = 0;  // Clear countdown
    *(undefined4 *)(timer + 4) = 0;     // Clear callback
    *(undefined4 *)(timer + 8) = 0;     // Clear callback arg
    *(undefined4 *)(timer + 0x10) = 0;  // Clear user data
    *(int *)(timer + 0xc) = *DAT_0000a1b0;  // Link to free list head
    *DAT_0000a1b0 = timer;                  // Set as new free list head
    *DAT_0000a1b4 = *DAT_0000a1b4 - 1;     // Decrement active count
    *DAT_0000a1b8 = *DAT_0000a1b8 + 1;     // Increment free count
}
```

### Timer Control Block Layout

| Offset | Size | Purpose |
|--------|------|---------|
| +0x00 | 4 | Timer signature / magic byte ('d') |
| +0x04 | 4 | Callback function pointer |
| +0x08 | 4 | Callback argument |
| +0x0C | 4 | Free list next pointer |
| +0x10 | 4 | User data |
| +0x14 | 4 | Current countdown value |
| +0x18 | 4 | Period (reload value) |
| +0x1C | 4 | Timer mode |
| +0x20 | 1 | Auto-reload flag |
| +0x21 | 1 | Active/state (0=free, 1=created, 2=running, 3=active) |

### Named Timers

The firmware creates several named timers via FUN_00006206 (called from init). Based on string references found in the binary, these include:
- `tmr_beep` - Controls buzzer duration
- `tmr_TimeSet` - Manages the cooking time countdown
- `tmr_gui` - GUI refresh interval
- `tmr_WaitBlade` - Blade detection debounce timer

### Interpretation

The timer system is a lightweight RTOS timer module with pool-based allocation. It supports one-shot and auto-reload modes. The free list design avoids dynamic memory allocation, which is typical for embedded systems. The critical section functions (FUN_000081c6 / FUN_000080c2) likely disable/enable interrupts to protect shared timer data.

---

## 4. GPIO Initialization

### GPIO Input Configuration: FUN_000062a6 (Address: 0x000062a6, 52 bytes)

```c
void FUN_000062a6(void) {
    for (uVar1 = 0; uVar1 < 6; uVar1 = uVar1 + 1 & 0xff) {
        puVar2 = *(uint **)(DAT_00006480 + uVar1 * 0xc);  // GPIO port base address
        for (uVar3 = 0; uVar3 < *(byte *)(DAT_00006480 + uVar1 * 0xc + 8); uVar3++) {
            // Calculate pin mask: 1 << pin_number
            uVar4 = 1 << *(sbyte *)(*(int *)(DAT_00006480 + uVar1 * 0xc + 4) + uVar3);
            *puVar2 = *puVar2 | uVar4;   // Set pin direction (output)
            puVar2[7] = uVar4;            // Clear pin (write to GPIO CLR register)
        }
    }
}
```

### GPIO Configuration Table Structure

The configuration is driven by a table at `DAT_00006480` with 6 entries (one per GPIO port), each 12 bytes:

| Offset | Size | Purpose |
|--------|------|---------|
| +0x00 | 4 | Pointer to GPIO port base address (DIR register) |
| +0x04 | 4 | Pointer to array of pin numbers |
| +0x08 | 1 | Number of pins in this group |

The LPC1788 GPIO registers at each port base:
- `base + 0x00` = DIR (direction register) - writing 1 = output
- `base + 0x1C` = CLR (clear register, at offset 7 * 4 = 0x1C) - writing 1 clears pin

### GPIO Output Configuration: FUN_000063c2 (called from init)

Additional GPIO output setup is handled separately, configuring pins used for:
- Heater relay control
- Motor enable/disable
- Buzzer output
- Bluetooth reset/enable

### Motor/Heater Control: FUN_0000632c (Address: 0x0000632c, 96 bytes)

```c
void FUN_0000632c(int param_1) {
    if (param_1 == 0) {
        // Disable: clear bit 11, delay, clear bit 0
        *(uint *)(DAT_00006484 + 0x18) &= 0xfffff7ff;  // CLR bit 11
        for (local_8 = 0x2710; local_8 != 0; local_8--) {}  // Delay ~10000 cycles
        *(uint *)(DAT_00006484 + 0x18) &= 0xfffffffe;  // CLR bit 0
    } else {
        // Enable: set bit 0, delay, set bit 11
        *(uint *)(DAT_00006484 + 0x18) |= 1;           // SET bit 0
        for (local_8 = 0x2710; local_8 != 0; local_8--) {}  // Delay ~10000 cycles
        *(uint *)(DAT_00006484 + 0x18) |= 0x800;       // SET bit 11
    }
}
```

### Interpretation

The GPIO system configures 6 port groups covering all digital I/O. The `FUN_0000632c` function controls what appears to be a power relay with a deliberate sequencing delay (0x2710 = 10,000 loop iterations, approximately a few milliseconds) between enable/disable steps. This is a safety interlock pattern -- the heater element requires two separate signals to be active, preventing accidental activation if one GPIO fails.

---

## 5. Motor Control

### Motor/Heater Power Output: FUN_000063ac (Address: 0x000063ac, 22 bytes)

```c
void FUN_000063ac(void) {
    FUN_0000632c(0);   // Disable heater relay (safety first)
    FUN_0000638c(1);   // Set GPIO group 1 output (motor direction?)
    FUN_0000638c(2);   // Set GPIO group 2 output (motor enable?)
}
```

### GPIO Group Output: FUN_0000638c (Address: 0x0000638c, 32 bytes)

```c
void FUN_0000638c(int param_1) {
    if (param_1 < 5) {
        // Write the predefined value to the GPIO SET register
        *(undefined4 *)(*(int *)(DAT_00006488 + param_1 * 0xc) + 0x1c) =
             *(undefined4 *)(DAT_00006488 + param_1 * 0xc + 4);
    }
}
```

This uses a table at `DAT_00006488` with entries containing GPIO port base addresses and pin mask values. The SET register is at offset `0x1C` from the GPIO port base.

### Timer2/MCPWM Disable at Init

During initialization, the firmware explicitly disables the MCPWM/Timer2 hardware:

```c
// In FUN_00000578:
*(uint *)(DAT_00000654 + 0x7c) = *(uint *)(DAT_00000654 + 0x7c) & 0xfffffff8;
```

This clears the lower 3 bits of the Timer2 control register (at offset 0x7C from the timer base), disabling all three MCPWM channels. The motor appears to be controlled via simple GPIO toggling (on/off) rather than PWM speed control, with speed regulated by duty-cycling in the cooking state machine.

### Motor Speed Display: FUN_00002610 (Address: 0x00002610, 584 bytes)

This large function handles the motor speed animation display on the LCD. The motor has discrete speed settings rather than continuous PWM control, consistent with the appliance using a synchronous AC motor with relay-switched speed taps.

### Interpretation

The Cook Expert appears to use relay-based motor control rather than variable-frequency PWM. The MCPWM peripheral is disabled at boot, and motor control is done through GPIO-driven relay switching. This is consistent with a kitchen appliance that uses a universal motor with discrete speed settings controlled by relay-selected winding taps. The two-step enable/disable sequence in FUN_0000632c provides a hardware safety interlock for the heating element.

---

## 6. Temperature Reading (NTC Sensor)

### ADC Temperature Sampling: FUN_000049b0 (Address: 0x000049b0, 316 bytes)

```c
void FUN_000049b0(void) {
    do { } while ((int)DAT_00004b7c[7] < 0);  // Wait for ADC ready (bit 31)
    uVar5 = FUN_00006ddc(3);                    // Read ADC channel 3
    FUN_00005778(uVar5);                         // Digital filter / averaging

    // Safety checks on raw ADC value (uVar2):
    if (cooking_active) {  // states 3 or 4
        if (uVar2 >= 0xf70) {
            // OVERHEAT: ADC reading too high (NTC shorted / extreme temperature)
            *DAT_00004b20 |= 0x40;
            FUN_0000149e();          // Trigger error handler
        }
        else if (uVar2 < 0x6c) {
            // NTC SHORT: ADC reading too low (sensor shorted)
            *DAT_00004b20 |= 0x20;
            FUN_0000149e();          // Trigger error handler
        }
        else if (uVar2 < 0x217 && (state == 4 || state == 9)) {
            // NTC OPEN: ADC reading in invalid range for active cooking
            *DAT_00004b20 |= 0x02;
            FUN_0000149e();          // Trigger error handler
        }
    }
    // Recovery check for NTC open during error state 7:
    else if (state == 7 && (*DAT_00004b20 & 2) != 0) {
        if (uVar2 > 0x5c8) {
            *DAT_00004b20 &= ~0x02;  // Clear NTC open error
            FUN_0000149e();
        }
        if (uVar2 < *(ushort *)(DAT_00004b24 + 0x1b0)) {
            // NTC value below minimum in lookup table
            *DAT_00004b20 = 0;
            *DAT_00004b20 |= 0x20;   // Set NTC short error
            FUN_0000149e();
        }
    }

    // Convert ADC value to temperature if no sensor errors:
    if ((*DAT_00004b20 & 0xe0) == 0) {
        sVar6 = FUN_000047f4(uVar2);        // Binary search lookup table
        *DAT_00004b1c = sVar6 - 0x1c;       // Apply offset (-28 degrees)
        if (*DAT_00004b1c < 0) {
            *DAT_00004b1c = 0;               // Clamp to minimum 0
        }
        // Call heater control if in active cooking states (3, 4, 5, or 6):
        if (state == 3 || state == 4 || state == 5 || state == 6) {
            FUN_0000483e();   // Update heater power level
            FUN_00001316();   // Switch heater relays
        }
    }
}
```

### Temperature Lookup (Binary Search): FUN_000047f4 (Address: 0x000047f4, 52 bytes)

```c
uint FUN_000047f4(uint adc_value) {
    uint high = 0xd8;  // 216 entries in lookup table
    uint low = 0;
    int mid;

    do {
        mid = (int)(high + low) >> 1;   // Binary search midpoint
        if ((int)(uint)DAT_00004b24[mid] < (int)adc_value) {
            high = mid - 1;              // NTC has inverse relationship
        } else {
            low = mid + 1;
        }
    } while ((low <= high) && (DAT_00004b24[mid] != adc_value));

    return low - 1;  // Return temperature index
}
```

### NTC Lookup Table

Located at `DAT_00004b24`, contains **216 entries** (0xD8). Each entry maps an ADC reading to a temperature index. The table is sorted in descending order (NTC thermistors have an inverse temperature/resistance relationship: higher temperature = lower resistance = higher ADC value).

The offset of `-0x1c` (-28) applied after lookup suggests the table starts at -28 degrees Celsius, or the offset compensates for the table indexing vs. actual temperature scale.

### Error Flag Bits (DAT_00004b20)

| Bit | Value | Meaning |
|-----|-------|---------|
| 1 | 0x02 | NTC open circuit detected |
| 5 | 0x20 | NTC short circuit detected |
| 6 | 0x40 | NTC overheat (extreme temperature) |

### ADC Threshold Values

| Threshold | Decimal | Meaning |
|-----------|---------|---------|
| < 0x6C | < 108 | NTC shorted (resistance too low) |
| < 0x217 | < 535 | NTC open circuit (specific cooking states) |
| > 0x5C8 | > 1480 | NTC recovery threshold |
| > 0xF70 | > 3952 | Overheat / sensor failure |

### Interpretation

The NTC temperature system uses a 12-bit ADC (channel 3) with a 216-entry lookup table for precise temperature conversion. The binary search provides O(log n) lookup performance. Three distinct fault conditions are monitored: short circuit, open circuit, and overheat. The system includes hysteresis for error recovery (different thresholds for entering vs. exiting error states). Temperature readings are filtered/averaged via FUN_00005778 before processing.

---

## 7. Display / GUI Functions

### LCD Controller Initialization: FUN_00006582 (Address: 0x00006582, 274 bytes)

```c
void FUN_00006582(void) {
    FUN_000064d4();              // Pin mux configuration for LCD
    // Enable LCD clock and power
    *DAT_000066a0 |= 0x800;     // Enable LCD peripheral clock
    DAT_000066a0[0x46] |= 8;    // LCD power bit
    DAT_000066a0[0x46] |= 0x800;

    // Configure LCD controller
    *DAT_000066a8 = 1;           // Reset LCD controller
    DAT_000066a8[10] = 1;
    DAT_000066a8[0x41] = 0;
    DAT_000066a8[0x41] |= 0x300; // TFT panel, 24-bit mode

    // LCD timing parameters (horizontal)
    DAT_000066a8[0xc] = 3;   // Horizontal sync pulse width
    DAT_000066a8[0xd] = 6;   // Horizontal front porch
    DAT_000066a8[0xe] = 10;  // Horizontal back porch
    DAT_000066a8[0xf] = 1;

    // LCD timing parameters (vertical)
    DAT_000066a8[0x10] = 6;
    DAT_000066a8[0x11] = 3;
    DAT_000066a8[0x12] = 8;
    DAT_000066a8[0x13] = 8;
    DAT_000066a8[0x14] = 10;
    DAT_000066a8[0x15] = 2;
    DAT_000066a8[0x16] = 3;

    // Resolution: 640 pixels per line (0x280)
    DAT_000066ac[-1] = 0x280;
    // LCD control: power enable, TFT, etc.
    DAT_000066a8[8] = 0x183;

    // Initialization sequence with delays
    // ... delay loops ...
    DAT_000066a8[8] = 0x103;
    DAT_000066a8[9] = 2;        // Framebuffer base address config

    // ... more delay ...
    DAT_000066a8[9] = 0x3a;
    DAT_000066a8[8] = 0x83;
    DAT_000066a8[8] = 0;
    DAT_000066a8[0x40] |= 0x80000;  // Enable LCD output
}
```

### Framebuffer Clear: FUN_000066b8 (Address: 0x000066b8, 18 bytes)

```c
void FUN_000066b8(undefined4 color) {
    puVar2 = DAT_00006970;          // Framebuffer base address
    for (uVar1 = 0; uVar1 < 0x1fe00; uVar1++) {
        *puVar2 = color;             // Write 32-bit color value
        puVar2++;
    }
}
```

The framebuffer size is `0x1FE00` words = 130,560 words = 522,240 bytes. At 4 bytes per pixel (32-bit ARGB): **480 x 272 = 130,560 pixels**. This confirms the LCD resolution is **480 x 272**.

### Pixel Write: FUN_000066ca (Address: 0x000066ca, 36 bytes)

```c
void FUN_000066ca(uint x, uint y, undefined4 color) {
    if (x < 0x1e0 && y < 0x110) {  // Bounds check: 480 x 272
        *(undefined4 *)(DAT_00006970 + y * 0x780 + x * 4) = color;
    }
}
```

The stride is `0x780` = 1920 bytes per row = 480 pixels * 4 bytes.

### Rectangle Fill: FUN_000066ee (Address: 0x000066ee, 58 bytes)

```c
void FUN_000066ee(uint x, uint y, int width, int height, undefined4 color) {
    for (row = y; row < y + height; row++) {
        for (col = x; col < x + width; col++) {
            FUN_000066ca(col, row, color);  // Set pixel
        }
    }
}
```

### Compressed Sprite Renderer: FUN_0000c34e (Address: 0x0000c34e, 306 bytes)

```c
void FUN_0000c34e(ushort *sprite_header, uint x_pos, uint y_pos,
                   byte transparency, uint flip) {
    // Load sprite header (10 bytes):
    // header[0] = width (bit 15 = RLE flag)
    // header[1] = height
    // header[2] = chunk_size (bytes per data block)
    // header[3] = checksum
    // header[4-5] = SPI flash address of pixel data

    // Read compressed data from SPI flash into buffer
    FUN_00006b94(flash_address, DAT_0000c49c, chunk_size);

    // Process pixel data:
    while (buffer_ptr < buffer_end) {
        count = (buffer[2] << 16) | (buffer[1] << 8) | buffer[0];

        if ((count & 0x800000) == 0) {
            // RLE mode: repeat single color 'count' times
            color = (buffer[5] << 16) | (buffer[4] << 8) | buffer[3];
            while (count-- > 0) {
                FUN_0000c2cc(color, flip);  // Write pixel with optional flip
            }
        } else {
            // Raw mode: read 'count' individual pixels
            count &= 0x7FFFFF;  // Clear RLE flag
            while (count-- > 0) {
                color = (ptr[5] << 16) | (ptr[4] << 8) | (ptr[3]);
                FUN_0000c2cc(color, flip);
                ptr += 3;  // Advance by 3 bytes (24-bit color)
            }
        }
    }
}
```

### Text Rendering: FUN_0000a52e

Text is rendered to the framebuffer using `FUN_0000a52e(text, font, x, y, alignment)`. The font data is stored in SPI flash and rendered character-by-character using the sprite system.

### Color Theme Support: FUN_00000e80 / FUN_00000e70

```c
uint FUN_00000e80(uint color) {
    if (*(char *)(DAT_00001244 + 4) == '\x01') {
        color = color ^ 0xffffff;  // Invert colors (dark/light theme toggle)
    }
    return color;
}
```

The display supports a light/dark theme toggle, implemented by XOR-inverting all colors with `0xFFFFFF`.

### Interpretation

The display system is a direct-mapped framebuffer at 480x272 resolution with 24-bit color (stored as 32-bit per pixel). All graphics assets (sprites, icons, fonts) are stored compressed in SPI flash and decompressed on-the-fly using a hybrid RLE/raw encoding scheme. Bit 23 of the pixel count field distinguishes between RLE (single color repeated) and raw (individual pixels) modes. This is an efficient compression scheme for UI graphics that typically contain large areas of flat color.

---

## 8. Bluetooth Communication (UART)

### UART Initialization: FUN_0000735a (Address: 0x0000735a, 144 bytes)

```c
void FUN_0000735a(undefined4 baud_rate, undefined4 buffer_addr) {
    *DAT_000074e4 |= 4;          // Enable UART0 peripheral clock
    // Configure UART pin functions
    *(uint *)(DAT_000074e8 + 8) &= 0xfffffff8;
    *(uint *)(DAT_000074e8 + 8) |= 1;    // TXD0 pin function
    *(uint *)(DAT_000074e8 + 0xc) &= 0xfffffff8;
    *(uint *)(DAT_000074e8 + 0xc) |= 1;  // RXD0 pin function

    DAT_000074d0[0xc] = 0x83;    // Line Control: DLAB=1, 8N1
    // Calculate baud rate divider
    uVar3 = FUN_000072d4(baud_rate, buffer_addr);
    DAT_000074d0[4] = (char)(uVar3 >> 8);   // DLM (divisor high byte)
    *DAT_000074d0 = (char)uVar3;              // DLL (divisor low byte)
    DAT_000074d0[0xc] = 3;       // Line Control: DLAB=0, 8N1
    DAT_000074d0[8] = 0xC7;      // FIFO Control: enable FIFO, trigger level

    // Set up receive buffer
    FUN_00007c5c(DAT_000074e0, DAT_000074ec, 0x40);  // 64-byte ring buffer
    *DAT_000074d4 = 0;            // Clear receive state
    uRame000e100 = 0x20;          // NVIC: Enable UART0 interrupt
    *(undefined4 *)(DAT_000074d0 + 4) = 7;  // IER: Enable RBR, THRE, RLS interrupts
}
```

### Bluetooth Protocol Handler: FUN_00005a58 (Address: 0x00005a58, 1544 bytes)

This is the core Bluetooth command processor. The protocol uses a simple framed format:

**Protocol Frame Format:**
- Byte 0: Header marker `0x5A`
- Byte 1: Command type
- Byte 2: Payload length or checksum position
- Bytes 3+: Payload data
- Last byte: Checksum

```c
void FUN_00005a58(void) {
    // Validate checksum
    if (*(char *)(DAT_00005dec + 1) == 0x10 || *(char *)(DAT_00005dec + 1) == 0x12) {
        checksum_pos = *(byte *)(DAT_00005dec + 2) - 1;
    } else {
        checksum_pos = 2;
    }
    received_checksum = *(byte *)(DAT_00005dec + checksum_pos);
    calculated_checksum = FUN_000059d4(DAT_00005dec, checksum_pos);
    if (received_checksum != calculated_checksum) return;  // Reject bad checksum

    // Process command type
    switch (command_type) {
        case 0x0d:  // PING / Connection test
            if (*DAT_00005e00 < 4) {
                // Send ACK response
                response_checksum = FUN_000059d4(&response, 2);
                FUN_00007480(&response, 3);   // Transmit 3 bytes
                *DAT_00005e04 = 0x8f9;        // Event: BT ping received
                FUN_000096c6(*DAT_00005e08);   // Dispatch event
            }
            break;

        case 0x0e:  // STATUS REPORT (device -> app)
            // Build 18-byte status response with:
            //   - Current cooking program ID
            //   - State, temperature, timer values
            //   - Motor speed settings
            //   - Error flags
            FUN_00007480(&response, 0x12);  // Transmit 18 bytes
            break;

        case 0x0f:  // STATE QUERY (app -> device)
            // Build 16-byte response with detailed cooking state:
            //   - Cooking program, step, temperature target
            //   - Timer remaining, motor speed
            //   - Current phase information
            FUN_00007480(&response, 0x10);  // Transmit 16 bytes
            break;

        case 0x10:  // RECIPE DOWNLOAD (app -> device)
            // Validate recipe parameters:
            //   - Program type (must be < 8 or 0xFF)
            //   - Speed setting (must be < 9 or 0xFF)
            //   - Temperature (validated against per-program limits)
            //   - Duration (validated against per-program limits)
            //   - Motor speed (validated)
            // If validation passes, load recipe into active program
            // Send ACK with validation result code
            break;

        case 0x11:  // STATISTICS REQUEST
            // Send cooking hour statistics
            break;

        case 0x12:  // NAME CHANGE
            // Update device Bluetooth name
            break;

        case 0x13:  // VERSION QUERY
            // Send firmware version
            break;

        case 0x14:  // HISTORY DUMP
            // Send usage history data
            break;
    }
}
```

### Bluetooth Event Codes

| Code | Meaning |
|------|---------|
| 0x8F9 | Bluetooth ping received |
| 0x8FA-0x8FF | Various Bluetooth events |

### Interpretation

The Bluetooth module communicates via UART0 at a configurable baud rate. The protocol is a simple request-response format with single-byte command types and XOR-based checksums. Command `0x10` (recipe download) includes comprehensive parameter validation, checking temperature ranges, speed limits, and duration bounds against per-program tables before accepting a recipe. This prevents the mobile app from sending unsafe cooking parameters.

---

## 9. Cooking Program Logic

### Main Cooking State Machine: FUN_00002a8e (Address: 0x00002a8e, 708 bytes)

This function is called once per second (from a periodic timer) and manages all cooking state transitions.

```c
void FUN_00002a8e(void) {
    switch (*DAT_00002d1c) {  // Current cooking state
        case 0:  // IDLE
        case 1:  // MENU_BROWSE
        case 2:  // PROGRAM_SELECTED
            FUN_0000238c();   // Auto-save current settings
            break;

        case 3:  // PREHEAT / MANUAL MODE
            if (*DAT_00002d54 < 2) {
                // Preheat phase: check if target temperature reached
                // Timeout: if preheat exceeds 5 attempts, abort
                if (timeout_counter > 5) {
                    FUN_00002a70();    // Stop heating
                    FUN_0000234a();    // Clear cooking state
                    *DAT_00002d1c = 1; // Return to menu
                }
            } else {
                // Active heating
                if (motor_running) {
                    FUN_00002610();    // Update motor speed display
                }
                if (motor_timer != 0) {
                    // Load timer duration from program table
                    *DAT_00002d38 = program_table[program_id] * 60;
                    // Increment motor runtime counter
                    *(int *)(stats + 0xc0) += 1;
                }
                // Increment NTC sensor runtime counter
                *(int *)(stats + 0xc4) += 1;
                FUN_00002552();   // Update temperature display
            }
            FUN_0000238c();       // Auto-save
            FUN_0000af94(*DAT_00002d64);  // Refresh GUI
            break;

        case 4:  // COUNTDOWN COOKING
            if (motor_running) {
                *(int *)(stats + 0xc0) += 1;  // Motor hours
            }
            *(int *)(stats + 0xc4) += 1;      // NTC hours

            if (!encoder_active) {
                if (program_id == 0x17) {
                    // Program 0x17: increment counter (special mode)
                    *(short *)(cooking_data + 6) += 1;
                    FUN_000026da();   // Update motor animation
                }
                else if (*(short *)(cooking_data + 6) == 0) {
                    FUN_000029b8();   // Timer reached 0: cooking complete
                }
                else {
                    // Decrement countdown timer (if not in steam mode)
                    if (not_paused && state != 5) {
                        *(short *)(cooking_data + 6) -= 1;
                    }
                    FUN_000029b8();   // Process cooking step
                    if (timer > 0) {
                        FUN_000026da();    // Motor animation
                        FUN_00004734();    // Temperature regulation
                    }
                    // Accumulate per-program usage statistics
                    *(int *)(stats + program_id * 8 + 4) += 1;
                }
            } else {
                FUN_00002610();  // Encoder active: update speed display
            }
            FUN_0000af94(*DAT_00002d64);  // Refresh GUI
            break;

        case 5:  // STEAM MODE
            if (timer == 60 && program_id == 0x12) {
                FUN_00002374();  // Special handling for steam program
            }
            FUN_00002552();       // Update temperature display
            FUN_0000238c();       // Auto-save
            if (motor_running) {
                FUN_00002610();   // Update motor speed display
            }
            FUN_0000af94(*DAT_00002d64);  // Refresh GUI
            break;

        case 6:  // PAUSED / ERROR RECOVERY
            // Beep pattern handling for pause notification
            if (motor_beep_active) {
                beep_counter++;
                if (beep_counter == 1 || beep_counter == 3) {
                    FUN_000062f6(*DAT_00002d24);  // Beep on
                }
                else if (beep_counter == 4) {
                    // Clear beep flag, stop beeping
                    *DAT_00002d3c = 0;
                }
            } else {
                // Resume from pause
                FUN_000062f6(*DAT_00002d68);
            }
            FUN_00002374();    // Temperature maintenance
            FUN_00002552();    // Update display
            FUN_0000238c();    // Auto-save
            FUN_0000af94(*DAT_00002d64);  // Refresh GUI
            break;

        case 7:  // SELF-CLEANING
            if (cleaning_counter != 0) {
                cleaning_counter--;
                if (cleaning_counter % 3 == 2) {
                    // Toggle cleaning relay pattern
                    *(uint *)(register_base + 0x4c) |= 0x1000;
                } else {
                    *(uint *)(register_base + 0x4c) &= ~0x1000;
                }
            }
            FUN_000047ca();    // Temperature check during cleaning
            FUN_0000af94(timer1);
            FUN_0000af94(timer2);
            *(int *)(stats + 0xc4) += 1;  // NTC runtime
            FUN_00002552();
            FUN_0000238c();
            break;
    }

    // Always increment screen runtime counter
    *(int *)(stats + 200) += 1;
}
```

### Cooking State Diagram

```
  [0: IDLE] --> [1: MENU] --> [2: SELECTED]
                                    |
                               [3: PREHEAT] --> [4: COUNTDOWN]
                                    |                |
                               [5: STEAM]      [6: PAUSED]
                                    |                |
                               [7: CLEANING]    [back to 4]
```

### Heater Power Control: FUN_00004aec (Address: 0x00004aec, 2424 bytes)

This is the largest function in the firmware. It maps temperature targets and remaining cook time to heater power levels (1-8):

```c
void FUN_00004aec(int temperature, undefined4 mode, int time_remaining) {
    if (*DAT_00004b64 == 0) {  // Safety check: heating enabled

        // HEATER ZONE 1 (DAT_0000537c / DAT_00005378):
        if (*DAT_0000537c != 0) {
            if (temperature < 90) {       // 0x5a = 90 degrees C
                if (temperature < 80) {   // 0x50 = 80
                    if (temperature < 70) {   // 0x46 = 70
                        if (temperature < 60) {   // 0x3c = 60
                            if (temperature < 50) {   // 0x32 = 50
                                // Below 50C:
                                if (time_remaining < 300) {
                                    if (time_remaining < 180) {    // 0xb4
                                        if (time_remaining < 60) { // 0x3c
                                            power = 3;
                                        } else {
                                            power = 3;
                                        }
                                    } else { power = 2; }
                                } else { power = 1; }
                            }
                            // 50-60C:
                            else if (time_remaining < 300) {
                                if (time_remaining < 180) {
                                    if (time_remaining < 60) { power = 6; }
                                    else { power = 5; }
                                } else { power = 4; }
                            } else { power = 2; }
                        }
                        // 60-70C:
                        else { /* similar nested structure, power = 3-7 */ }
                    }
                    // 70-80C:
                    else { /* power = 3-8 */ }
                }
                // 80-90C:
                else { /* power = 3-8 */ }
            }
            // >= 90C:
            else {
                if (time_remaining < 300) {
                    if (time_remaining < 180) {
                        if (time_remaining < 60) { power = 8; }
                        else { power = 6; }
                    } else { power = 4; }
                } else { power = 2; }
            }
        }

        // HEATER ZONE 2 (DAT_00005380):
        // ... similar structure for second heater zone ...

        // Repeat for up to 8 heater zones total
    }
}
```

### Power Level Matrix (Zone 1)

| Temperature | < 60s | 60-180s | 180-300s | > 300s |
|-------------|-------|---------|----------|--------|
| < 50C | 3 | 3 | 2 | 1 |
| 50-60C | 6 | 5 | 4 | 2 |
| 60-70C | 7 | 6 | 4 | 3 |
| 70-80C | 8 | 7 | 5 | 3 |
| 80-90C | 8 | 7 | 5 | 3 |
| >= 90C | 8 | 6 | 4 | 2 |

### Interpretation

The cooking system implements a sophisticated multi-zone heater control with time-based power management. Higher temperatures and shorter remaining times trigger higher power levels. The notable drop in power at >= 90C with long time remaining (level 2) suggests the system anticipates thermal inertia and prevents overshoot during slow cooking. The 8 power levels likely correspond to different heater relay combinations (e.g., 3 heating elements that can be switched independently, giving 8 power combinations).

The cooking state machine tracks: temperature target, remaining time, motor speed, and program type. Per-program usage statistics (runtime in seconds, divided by 0xE10 = 3600 for hours display) are maintained for the SYSTEM diagnostic screen.

---

## 10. Error Handling

### Error Handler: FUN_0000149e (Address: 0x0000149e, 30 bytes + continuation)

```c
void FUN_0000149e(void) {
    if ((*DAT_0000170c > 1) && (*DAT_000016e0 - 3 < 5)) {
        // Only handle errors in cooking states 3-7

        if (error_code_ptr == 0) {
            error_response = -1;  // 0xFF = critical error
        } else {
            error_response = error_table[error_code_ptr];
        }

        if (error_response == -1) {
            // CRITICAL ERROR: immediate shutdown
            *(uint *)(register_base + 0x4c) &= ~0x1000;  // Disable heater output
            if (previous_state == 4) {
                new_state = 5;  // Go to error recovery
            } else {
                new_state = 3;  // Go to safe state
            }
            *DAT_000016e0 = new_state;
            *(undefined *)(cooking_data + 2) = 0;  // Clear cooking flag
            *DAT_000016e4 = 0x8fc;      // Error event code
            FUN_000096c6(*DAT_000016e8); // Dispatch error event
        }
        else {
            // NON-CRITICAL ERROR: switch to error handling state
            if (*DAT_000016e0 != 7) {
                *previous_state_ptr = *DAT_000016e0;
                if ((flags & 1) == 0) {
                    *saved_timer = *DAT_00001708;
                }
            }
            // Engage appropriate safety measures
            if (error_code_ptr == 0x10) {
                FUN_0000119a();   // Full safety shutdown
            } else {
                FUN_0000120c();   // Partial safety (disable heater + motor)
            }
            // Set recovery timer based on error type
            if ((error_code_ptr & 1) == 0) {
                if ((error_code_ptr & 8) == 0) {
                    *recovery_timer = 0x78;  // 120 seconds
                } else {
                    *recovery_timer = 3;     // 3 seconds
                }
            } else {
                *recovery_timer = 0;  // No auto-recovery
            }
            *DAT_000016e4 = 0x8fd;      // Warning event code
            FUN_000096c6(*DAT_000016e8); // Dispatch warning event
        }
    }
}
```

### Safety Shutdown: FUN_0000120c (Address: 0x0000120c, 24 bytes)

```c
void FUN_0000120c(void) {
    FUN_0000638c(0);   // Disable GPIO group 0 (motor relay)
    FUN_0000638c(4);   // Disable GPIO group 4 (heater relay)
    FUN_0000119a();    // Additional safety measures
}
```

### Event/Message Dispatch: FUN_000096c6 (Address: 0x000096c6, 80 bytes)

```c
undefined4 FUN_000096c6(char *mailbox, undefined4 message) {
    if (*mailbox == '\x01') {      // Check if mailbox is active
        uVar1 = FUN_0000cb64();    // Enter critical section
        if (mailbox[10] == '\0') {
            // Simple mailbox: store single message
            if (*(int *)(mailbox + 4) == 0) {
                *(undefined4 *)(mailbox + 4) = message;
                FUN_0000cb6c(uVar1);
                return 0;  // Success
            } else {
                FUN_0000cb6c(uVar1);
                return 0x14;  // Mailbox full
            }
        } else {
            // Queue mailbox: enqueue message
            FUN_00008aba(mailbox, message, 2, 0);
            FUN_0000cb6c(uVar1);
            FUN_0000806a();  // Signal waiting task
            return 0;
        }
    }
    return 1;  // Mailbox not active
}
```

### Event Codes

| Code | Meaning |
|------|---------|
| 0x880 | System idle event |
| 0x8F8 | Timer event |
| 0x8F9 | Bluetooth ping received |
| 0x8FB | Cooking program change |
| 0x8FC | Critical error (heating shutdown, NTC failure) |
| 0x8FD | Warning (recoverable error, NTC intermittent) |
| 0x8FE | Bluetooth data received |
| 0x8FF | UI update request |

### Interpretation

The error handling system has two tiers:
1. **Critical errors** (error_response = -1): Immediately disable all heating, enter a safe state, and dispatch event 0x8FC. These include NTC short circuit and extreme overheat conditions.
2. **Recoverable errors** (non-critical): Save the current cooking state, disable heaters, set a recovery timer, and dispatch event 0x8FD. The system can auto-resume after the recovery timer expires.

The event dispatch system uses mailbox-style inter-task communication (common in embedded RTOS designs). Messages are posted to mailboxes that other tasks can wait on, allowing the error handler to asynchronously notify the UI and cooking subsystems.

---

## 11. SYSTEM Diagnostic Screen

### SYSTEM Screen: FUN_0000b620 (Address: 0x0000b620, 504 bytes)

```c
void FUN_0000b620(void) {
    // Set up string labels
    local_10 = "SYSTEM";           // s_SYSTEM_0000b854
    local_1c = "Motor";            // s_Motor_0000b85c

    // Invert colors based on theme
    uVar1 = FUN_00000e80(0xffffff, ...);
    FUN_0000a434(*DAT_0000b848, uVar1);  // Set text color

    // Display language-specific labels (from localization table)
    FUN_0000a52e(label_table[language * 4],     color, 0x3c, 0x43, 0);  // Left label
    FUN_0000a52e(label_table[language * 4 + 1], color, 0xf8, 0x43, 0);  // Right label

    // Set contrasting color for data values
    uVar1 = FUN_00000e80(DAT_0000b82c);
    FUN_0000a434(*DAT_0000b848, uVar1);

    // Build and display "SYSTEM" title
    FUN_0000c8bc(auStack_50, &local_10);
    FUN_0000c904(auStack_50, DAT_0000b880);   // Append separator
    FUN_0000a52e(auStack_50, color, 0x3c, 0x5f, 0);

    // Display firmware version as "X.XX"
    local_30 = *DAT_0000b884 / 100 + '0';       // Major version
    local_2f = '.';                                // Decimal point (0x2e)
    local_2e = (*DAT_0000b884 % 100) / 10 + '0'; // Minor version tens
    local_2d = *DAT_0000b884 % 10 + '0';          // Minor version ones
    local_2c = 0;                                  // Null terminator
    // Render "Motor X.XX" (firmware version)
    FUN_0000c8bc(auStack_50, &local_1c);
    FUN_0000c904(auStack_50, &local_30);
    FUN_0000a52e(auStack_50, color, 0x3c, 0x78, 0);

    // Display second version number (possibly hardware version)
    local_30 = *DAT_0000b888 / 100 + '0';
    // ... same pattern ...
    FUN_0000a52e(auStack_50, color, 0x3c, 0x91, 0);

    // Display runtime statistics:
    // Motor runtime hours (offset 0xC0 from stats base, /3600)
    FUN_0000c5d0(auStack_50, "Motor %d", *(uint *)(DAT_0000b88c + 0xc0) / 0xe10);
    FUN_0000a52e(auStack_50, color, 0xfa, 0x5f, 0);

    // NTC sensor runtime hours (offset 0xC4 from stats base, /3600)
    FUN_0000c5d0(auStack_50, "NTC %d", *(uint *)(DAT_0000b88c + 0xc4) / 0xe10);
    FUN_0000a52e(auStack_50, color, 0xfa, 0x78, 0);

    // Screen runtime hours (offset 200=0xC8 from stats base, /3600)
    FUN_0000c5d0(auStack_50, "Screen %d", *(uint *)(DAT_0000b88c + 200) / 0xe10);
    FUN_0000a52e(auStack_50, color, 0xfa, 0x91, 0);
}
```

### Extended Statistics Screen: FUN_0000b8bc (Address: 0x0000b8bc, 326 bytes)

A second diagnostic screen shows per-cooking-program usage:

```c
void FUN_0000b8bc(void) {
    // Display 24 (0x18) cooking program statistics
    for (i = 0; i < 0x18; i++) {
        hours = min(stats[i * 8 + 4] / 0xe10, 999);   // Hours, capped at 999
        count = min(stats[i * 8], 999);                  // Usage count, capped at 999

        // Render in 4-column grid layout
        FUN_0000a52e(hours_str, color, x, y, 0);
        FUN_0000a52e(count_str, color, x + 0x2d, y, 0);

        x += 0x5a;  // Column spacing = 90 pixels
        if ((i + 1) % 4 == 0) {
            y += 0x19;  // Row spacing = 25 pixels
            x = 0x3c;   // Reset to first column
        }
    }

    // Also display total NTC and screen hours at bottom
    ntc_hours = min(stats[0xC4] / 0xe10, 999);
    screen_hours = min(stats[0xC8] / 0xe10, 999);
}
```

### Statistics Data Layout

The statistics block at `DAT_0000b88c` (same as `DAT_0000315c` in the cooking state machine):

| Offset | Size | Purpose |
|--------|------|---------|
| 0x00 - 0xBF | 192 | Per-program stats: 24 programs x 8 bytes (4=count, 4=seconds) |
| 0xC0 | 4 | Total motor runtime (seconds) |
| 0xC4 | 4 | Total NTC/heating runtime (seconds) |
| 0xC8 | 4 | Total screen-on runtime (seconds) |

### Screen Layout

```
+--------------------------------------------+
|  [Left Label]            [Right Label]      | y=0x43
|  SYSTEM [separator]                         | y=0x5f
|  Motor X.XX              Motor: NNNh        | y=0x78
|  [Version2]              NTC: NNNh          | y=0x91
|                          Screen: NNNh       |
+--------------------------------------------+
```

### Interpretation

The SYSTEM diagnostic screen displays two firmware version numbers (possibly for the main processor and a secondary motor controller MCU), plus three runtime counters in hours. The runtime counters track motor usage, heating element usage (via NTC), and total screen-on time. These are useful for maintenance scheduling. The division by `0xE10` (3,600) converts the internally-stored seconds to hours.

The extended statistics screen shows per-program usage for all 24 cooking programs, displayed in a 4-column, 6-row grid. Each program shows both a usage count and total hours. Values are capped at 999 for display.

---

## 12. Firmware Update Protocol

### Firmware Update Entry: FUN_000079b4 (Address: 0x000079b4, 132 bytes)

```c
void FUN_000079b4(void) {
    FUN_00007b5c(&DAT_0001c200);    // Reinitialize UART at specific baud rate
    FUN_000066b8(0);                 // Clear screen to black
    _DAT_e000e010 &= 0xfffffff8;    // Disable SysTick timer
    FUN_0000a52e(&DAT_00007b38, *DAT_00007a78, 0xf0, 0x32, 1);  // Display "Programming" text
    FUN_0000c518();                  // Draw progress bar frame
    FUN_0000790c();                  // Execute YMODEM file transfer

    // After transfer completes: system reset
    disableIRQinterrupts();
    *(uint *)(DAT_00007b50 + 0x7c) |= 0x800000;  // Set system reset pending
    DataSynchronizationBarrier(0xf);
    // Write to AIRCR: SYSRESETREQ + VECTKEY
    *DAT_00007b54 = (*DAT_00007b54 & 0x700 | DAT_00007b58) + 4;
    DataSynchronizationBarrier(0xf);
    // Infinite loop (waiting for reset to take effect)
    do { } while (true);
}
```

### YMODEM Transfer Handler: FUN_0000790c (Address: 0x0000790c, 168 bytes)

```c
void FUN_0000790c(void) {
    local_14 = 0;  // File size
    iVar1 = FUN_0000773e(&local_14);  // Receive file via YMODEM

    if (iVar1 == 0) {
        // SUCCESS
        FUN_00007bda(DAT_00007a44);            // Print filename
        FUN_00007bda(DAT_00007a40);
        FUN_000074f8(&local_10, local_14);     // Convert size to string
        FUN_00007bda("  Size: ");
        FUN_00007bda(&local_10);
        FUN_00007bda(" Bytes");
        FUN_00007bda("---------------------");

        // Write magic marker to SPI flash (validates firmware)
        local_10 = CONCAT22(local_10._2_2_, 0xa55a);  // Magic: 0xA55A
        FUN_00006c9a(0x200000, &local_10);

        // Display completion message
        FUN_0000a52e("Transmission completion. Restart",
                     *DAT_00007a78, 10, 0xbe, 0);
        FUN_00007900(0x2ffffff);  // Long delay (~50M iterations)
    }
    else if (iVar1 == 2) {
        FUN_00007bda(" Aborted by user.");
    }
    else if (iVar1 == 4) {
        FUN_00007bda(" Verification failed.");
    }
    else if (iVar1 == 5) {
        FUN_00007bda(" The image size is higher than t...");  // Too large
    }
    else {
        FUN_00007bda(" Failed to receive the file.");
    }
}
```

### YMODEM File Receiver: FUN_0000773e (Address: 0x0000773e, 450 bytes)

```c
int FUN_0000773e(uint *file_size_out) {
    local_2c = 0;      // Transfer complete flag
    retry_count = 0;
    first_packet = false;
    sector_count = 0;
    error_code = 0;
    flash_address = 0x200000;  // SPI Flash write start address

    while (!transfer_complete && error_code == 0) {
        // Receive YMODEM packet
        result = FUN_00007670(DAT_00007a3c, &packet_type, 0x1000000);

        if (result == 0) {
            // Packet received successfully
            retry_count = 0;

            if (packet_type == 0) {
                // End of transfer (EOT received)
                FUN_00007bc6(ACK);  // Send ACK (0x06)
                transfer_complete = 1;
            }
            else if (packet_type == 2) {
                // Abort
                FUN_00007bc6(CAN);  // Send CAN (0x18)
                FUN_00007bc6(CAN);
                error_code = 2;
            }
            else {
                // Verify sequence number
                if (packet[2] != (sector_count & 0xff)) {
                    FUN_00007bc6(NAK);  // Send NAK (0x15)
                    continue;
                }

                if (sector_count == 0) {
                    // First packet: parse filename and file size
                    if (packet[4] == '\0') {
                        // Empty filename = end of batch
                        FUN_00007bc6(ACK);
                        transfer_complete = 1;
                        continue;
                    }

                    // Extract filename
                    for (i = 0; filename[i] != 0 && i < 64; i++) {
                        stored_filename[i] = filename[i];
                    }

                    // Extract file size (ASCII after filename)
                    FUN_0000754c(size_string, &file_size);

                    // Validate: firmware must be < 0x3002 sectors
                    if (*file_size_out < 0x3002) {
                        FUN_00006d6c(0x200);  // Erase SPI flash sectors
                        *file_size_out = file_size;
                        total_sectors = file_size >> 10;
                        FUN_00007bc6(ACK);   // ACK
                        FUN_00007bc6('C');   // Request CRC mode (0x43)
                    } else {
                        // File too large
                        FUN_00007bc6(CAN);
                        FUN_00007bc6(CAN);
                        error_code = 5;
                    }
                }
                else {
                    // Data packet: write to SPI flash
                    result = FUN_00006c9a(flash_address, packet_data, packet_size);
                    if (result == 0) {
                        FUN_00007bc6(CAN);
                        FUN_00007bc6(CAN);
                        error_code = 4;  // Flash write failure
                    } else {
                        flash_address += packet_size;
                        FUN_00007bc6(ACK);
                    }
                }

                // Update progress bar
                progress = (sector_count * 100) / total_sectors;
                FUN_0000c4a0(progress & 0xff);
                sector_count++;
                first_packet = true;
            }
        }
        else {
            // Receive error: retry
            if (first_packet) retry_count++;
            if (retry_count < 6) {
                FUN_00007bc6('C');  // Send 'C' to request retransmission
            } else {
                FUN_00007bc6(CAN);
                FUN_00007bc6(CAN);
            }
        }
    }

    return error_code;
}
```

### UART Character TX: FUN_00007bc6 (Address: 0x00007bc6, 20 bytes)

```c
void FUN_00007bc6(byte char_to_send) {
    *DAT_00007c54 = char_to_send;            // Write to UART TX holding register
    do { } while ((DAT_00007c54[0x14] & 0x40) == 0);  // Wait for THRE (TX complete)
}
```

### YMODEM Protocol Constants

| Value | Meaning |
|-------|---------|
| 0x06 (ACK) | Acknowledge |
| 0x15 (NAK) | Negative acknowledge |
| 0x18 (CAN) | Cancel transfer |
| 0x43 ('C') | Request CRC mode |

### SPI Flash Layout

| Address | Purpose |
|---------|---------|
| 0x000000 | Graphics assets (sprites, fonts) |
| 0x200000 | Firmware image start |
| 0x200000 (first 4 bytes) | Magic marker 0xA55A + version info |

### Error Codes

| Code | Meaning |
|------|---------|
| 0 | Success |
| 2 | Aborted by user |
| 4 | Flash verification/write failure |
| 5 | Image size too large |
| Other | Failed to receive file |

### System Reset Sequence

After successful firmware update:
1. Disable all interrupts
2. Set bit 23 of system control register (reset pending)
3. Data Synchronization Barrier
4. Write SYSRESETREQ (0x04) to AIRCR register with VECTKEY
5. Data Synchronization Barrier
6. Enter infinite loop (processor resets)

### Interpretation

The firmware update uses the standard YMODEM protocol over the UART serial port. The firmware image is written to SPI flash starting at address 0x200000. A magic marker (0xA55A) is written to the first sector after successful transfer to validate the image. The maximum firmware size is limited to approximately 0x3002 sectors (~12 MB). The progress bar provides visual feedback during the transfer. After completion, the system performs a hard reset via the ARM Cortex-M3 Application Interrupt and Reset Control Register (AIRCR).

---

## Appendix A: Key Data Addresses

| Address/Symbol | Purpose |
|----------------|---------|
| DAT_0000063c | EEPROM settings structure base |
| DAT_00004b1c | Current temperature reading (Celsius) |
| DAT_00004b20 | NTC error flags byte |
| DAT_00004b24 | NTC lookup table (216 entries) |
| DAT_00004b7c | ADC status/control registers |
| DAT_00005378 | Current heater power level |
| DAT_00002d1c | Cooking state machine current state |
| DAT_00002d38 | Cooking countdown timer (seconds) |
| DAT_0000b88c / DAT_0000315c | Runtime statistics block |
| DAT_00006970 | Framebuffer base (480x272x32bpp) |
| DAT_00005dec | Bluetooth receive buffer |
| DAT_000074d0 | UART0 register base |
| 0xE000E010 | SysTick Control and Status Register |
| 0xE000E014 | SysTick Reload Value Register |
| 0xE000E100 | NVIC Interrupt Set Enable Register |

## Appendix B: Deep Sleep / Power Down

### FUN_00001830 (Address: 0x00001830, 278 bytes)

```c
void FUN_00001830(void) {
    FUN_000063ac();                    // Disable all motor/heater outputs
    *(DAT_00001bec + 8) = DAT_00001be8; // Save context
    *(DAT_00001bf0 + 0x26) = 8;       // Configure wake-up source
    _DAT_e000e104 = 0x40;             // NVIC: Enable specific interrupt for wake
    // Configure GPIO for wake-up interrupt
    *(uint *)(DAT_00001bfc + 0x1cc) &= 0xfffffff8;
    DAT_00001c00[0x18] |= 0x80000;    // Enable falling edge interrupt
    DAT_00001c00[0x1f] = 0x80000;     // Clear pending interrupt
    FUN_00006418(3);                    // Set power indicator LED

    // Configure additional wake GPIO pins
    // ... GPIO interrupt setup ...

    // Enter low-power mode
    *(uint *)(DAT_00001c04 + 0x20) |= 0x2000;  // Set SLEEPDEEP bit in SCR
    for (local_8 = 6000; local_8 != 0; local_8--) {}  // Brief delay
    WaitForInterrupt();                 // ARM WFI - enter deep sleep

    // === Woken up ===
    FUN_00001814();                     // Re-initialize clocks

    // Select beep pattern based on cooking program type:
    switch (*DAT_00001c08) {
        case 0: case 1: case 2: case 4: case 7: case 9:
            beep_duration = 0x28;   // 40 units - short beep
            break;
        case 3: case 0x10:
            beep_duration = 0x1d;   // 29 units - different beep
            break;
        case 5: case 6: case 8: case 10: case 0xb: case 0xc:
            beep_duration = 0x32;   // 50 units - long beep
            break;
        default:
            beep_duration = 0x14;   // 20 units - shortest beep
    }
    // Play wake-up beep
}
```

### Interpretation

The deep sleep mode disables all outputs, configures a GPIO interrupt as the wake source (likely a button press), and enters the ARM Cortex-M3 deep sleep using the WFI instruction. Upon wake, it plays a beep pattern that varies by the active cooking program, allowing the user to identify the appliance state by sound.

## Appendix C: Input / Key Scanning

### Key Matrix Scan: FUN_00000d4c (Address: 0x00000d4c, 72 bytes)

```c
void FUN_00000d4c(void) {
    key_state = 0;
    // Scan 13 GPIO inputs across multiple ports
    for (i = 0; i < 13; i++) {
        port_addr = *(int *)(DAT_00000e4c + i * 8);      // GPIO port base
        pin_mask = *(uint *)(DAT_00000e4c + i * 8 + 4);   // Pin bit mask
        if ((*(uint *)(port_addr + 0x14) & pin_mask) == 0) {
            key_state |= (1 << i);  // Pin is low (active)
        }
    }
    *DAT_00000e30 = key_state & 0x1ff;       // Bits 0-8: 9 main keys
    DAT_00000e30[4] = key_state & 0x200;     // Bit 9: Lid sensor
    DAT_00000e30[8] = key_state & 0xc00;     // Bits 10-11: Rotary encoder
    DAT_00000e30[0xc] = key_state & 0x1000;  // Bit 12: Blade detection
}
```

### Input Status: FUN_00000744 (Address: 0x00000744, 64 bytes)

```c
void FUN_00000744(void) {
    *DAT_00000a78 &= 0xe6;            // Clear status bits 0,3,4
    FUN_00000674();                     // Check lid sensor status
    if ((encoder_port & 0xc00) != 0) {
        *DAT_00000a78 |= 0x10;        // Bit 4: Encoder rotation detected
    }
    if ((blade_port & 0x1000) == 0) {
        *DAT_00000a78 |= 1;           // Bit 0: Blade installed
    }
}
```

### Input Bit Map

| Bit | GPIO Source | Function |
|-----|------------|----------|
| 0-8 | Various | 9 front panel buttons |
| 9 | Port + 0x10, bit 0x200 | Lid open/closed sensor |
| 10-11 | Port + 0x20, bits 0xC00 | Rotary encoder (quadrature) |
| 12 | Port + 0x30, bit 0x1000 | Blade/accessory detection |

### Lid Safety Interlock: FUN_00000674 (Address: 0x00000674, 72 bytes)

```c
void FUN_00000674(void) {
    // Complex safety logic for lid sensor
    if ((state == 8 && lid_open) ||
        (state != 8 && state != 5 && !lid_open)) {
        *DAT_00000a78 |= 8;     // Set lid interlock flag
    } else {
        *DAT_00000a78 &= ~8;    // Clear lid interlock flag
    }
}
```

### Interpretation

The input system scans 13 physical inputs organized into 4 groups: buttons, lid sensor, rotary encoder, and blade detection. The lid sensor provides a safety interlock that changes behavior depending on the current cooking state. The rotary encoder (2 bits for quadrature decoding) is used for temperature/time adjustment. Blade detection prevents the motor from running without the correct blade accessory installed.

## Appendix D: SPI Flash and EEPROM Access

### SPI Flash Read: FUN_00006b94

Reads data from external SPI flash memory. Used to load graphics assets (sprites, fonts) and firmware during boot.

### SPI Flash Write: FUN_00006c9a

Writes data to SPI flash. Used during firmware update to store the received firmware image starting at address 0x200000.

### SPI Flash Commands

| Command | Value | Purpose |
|---------|-------|---------|
| 0x03 | Read | Read data from flash |
| 0x02 | Page Program | Write data to flash |
| 0x06 | Write Enable | Enable write operations |
| 0x20 | Sector Erase | Erase a 4KB sector |

### EEPROM Access

The LPC1788 has built-in EEPROM accessed at memory-mapped addresses:

| Function | Address | Purpose |
|----------|---------|---------|
| FUN_00006e1c | EEPROM init | Initialize EEPROM peripheral |
| FUN_00006e9c | EEPROM read | Read from EEPROM (addresses 0x200080-0x200094) |
| FUN_00006f72 | EEPROM write | Write to EEPROM |

The EEPROM stores: cooking program settings, user preferences (language, theme), runtime statistics, and Bluetooth device name.

---

*Document generated from analysis of decompiled_output.c (13,521 lines, 329 functions)*
*Processor: NXP LPC1788 ARM Cortex-M3*
*Decompiler: Ghidra*
