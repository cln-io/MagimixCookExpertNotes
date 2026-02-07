# Magimix Cook Expert - Firmware Analysis

## Overview

Two firmware binary files were extracted from the Magimix Cook Expert kitchen appliance:

| File | Size | Purpose |
|------|------|---------|
| `lpc1788.bin` | 225,652 bytes (220.4 KB) | Main MCU firmware (ARM Cortex-M3) |
| `flash.bin` | 1,025,067 bytes (1001.0 KB) | External SPI flash — display graphics & assets |

---

## lpc1788.bin — Main Processor Firmware

### Processor Identification

- **MCU**: NXP LPC1788 — ARM Cortex-M3 core
- **Architecture**: ARMv7-M, Thumb-2 instruction set
- **Internal SRAM**: 96 KB (64 KB main + 32 KB AHB)
- **Internal Flash**: 512 KB
- **Max clock**: 120 MHz

The LPC1788 is an ARM Cortex-M3 microcontroller from NXP, commonly used in embedded systems with LCD display requirements. It has a built-in LCD controller, making it a natural choice for a kitchen appliance with a touchscreen.

### Vector Table (ARM Cortex-M3)

The binary starts with a valid ARM Cortex-M3 vector table:

| Vector | Address | Function |
|--------|---------|----------|
| Initial Stack Pointer | `0x1000D468` | Top of 64KB internal SRAM (base `0x10000000` + ~53KB) |
| Reset Handler | `0x0000E48D` | Entry point after power-on/reset |
| NMI | `0x0000E499` | Non-maskable interrupt |
| HardFault | `0x0000E49B` | Hard fault handler |
| MemManage | `0x0000E49D` | Memory management fault |
| BusFault | `0x0000E49F` | Bus fault |
| UsageFault | `0x0000E4A1` | Usage fault |
| SVCall | `0x0000E4A3` | Supervisor call |
| DebugMon | `0x0000E4A5` | Debug monitor |
| PendSV | `0x00014BA7` | Pendable service call (context switching) |
| SysTick | `0x00012295` | System tick timer (likely OS tick) |

**LPC checksum** at vector[7] = `0xEFF9CFFA` — validates correctly (sum of first 8 vectors = 0x00000000). This confirms the binary is a valid LPC bootable image.

### Active Interrupt Handlers

Only one peripheral interrupt has a custom handler:

| IRQ | Peripheral | Handler Address |
|-----|-----------|----------------|
| 21 | **UART0** | `0x0000F435` |

All other peripheral IRQs point to a default/stub handler (`0x0000E4AB`). This means UART0 is the primary serial communication interface — likely used for **Bluetooth module communication**.

The PendSV and SysTick vectors point to distinct addresses (`0x00014BA7` and `0x00012295`), suggesting a **preemptive RTOS or cooperative scheduler** is running. However, no FreeRTOS/CMSIS-RTOS string markers were found, so it may be a custom lightweight scheduler.

### Memory Map

| Address Range | Size | Contents |
|---------------|------|----------|
| `0x00000-0x0E000` | 57 KB | **Executable code** (main application) |
| `0x0E000-0x0F000` | 4 KB | Padding/alignment |
| `0x0F000-0x17000` | 32 KB | **Data tables** (lookup tables, constants, graphic indices) |
| `0x17000-0x18000` | 4 KB | More code |
| `0x18000-0x21000` | 36 KB | Sparse padding |
| `0x21000-0x24000` | 12 KB | Data tables |
| `0x24000-0x2C000` | 32 KB | Sparse padding |
| `0x2C000-0x2D000` | 4 KB | Data tables |
| `0x2D000-0x32000` | 20 KB | Sparse padding |
| `0x32000-0x37174` | ~21 KB | **String data, code, and lookup tables** |

Total active code: ~61 KB. Total active data: ~65 KB. Significant unused/padded space suggests room for firmware updates.

### Peripheral Usage

Analysis of memory-mapped peripheral address references in the firmware:

| Peripheral | References | Purpose (Inferred) |
|-----------|------------|-------------------|
| **System Control** (`0x400FC000`) | ~405 | Clock configuration, PLL, power control |
| **UART0** (`0x40008000`) | ~160 | **Bluetooth module** serial communication |
| **EMC** (`0x50008000`) | ~106 | External Memory Controller — **drives external SPI flash** for graphics |
| **Timer2** (`0x40030000`) | ~89 | Likely motor speed control / PWM timing |
| **SPI** (`0x40014000`) | ~67 | Communication with **external flash** (flash.bin) |
| **I2C0** (`0x40020000`) | ~66 | **Temperature sensor** (NTC) and possibly other sensors |
| **Timer0/Timer1** (`0x40028000`) | ~66 | General-purpose timing (cooking timers, beep duration) |
| **GPIO** (`0x2009C000`) | ~41 | Button inputs, LED outputs, relay control |
| **SSP2** (`0x40058000`) | ~24 | Secondary SPI — possibly **touchscreen controller** |
| **LCD Controller** (`0x400A8000`) | ~10 | Built-in LCD controller driving the display panel |
| **MCPWM** (`0x40060000`) | ~10 | Motor Control PWM — **motor speed regulation** |
| **UART1** (`0x4000C000`) | ~3 | Secondary serial (debug port?) |

### Bluetooth Support

The firmware includes Bluetooth connectivity via an external module connected over UART0:

**Bluetooth state machine identifiers found:**
- `Bt_Started@` — Bluetooth module initialized
- `Bt_Connect@` — Device connected
- `Bt_Disconn@` — Device disconnected

**Bluetooth UI strings (multi-language):**
- "Smart Connect absente" / "No Smart Connect key" — Optional Bluetooth accessory ("Smart Connect" dongle)
- "Aucun appareil connecté" / "No device connected"
- "Connecté au téléphone:" / "Connected to phone:"
- "Android App" / "Apple App" — Mobile companion apps exist for both platforms
- Standby timeout options: 5 minutes, 15 minutes, 30 minutes

The Bluetooth is provided by an **optional accessory** ("Smart Connect key"), not built into every unit.

### Software Timers

Four named software timers were identified:

| Timer | Purpose |
|-------|---------|
| `tmr_gui` | GUI refresh / display update timer |
| `tmr_beep` | Buzzer/beep duration control |
| `tmr_WaitBlade` | Safety: wait for blade to stop before lid unlock |
| `tmr_TimeSet` | Cooking time setting input timeout |

### Firmware Update / Bootloader

The firmware contains a built-in update capability (likely over Bluetooth or USB):

```
" Programming Completed Successfully!"
"Transmission completion. Restarting."
"The image size is higher than the allowed space memory!"
"Verification failed!"
"Aborted by user."
"Failed to receive the file!"
" Size: "
" Bytes"
" Name: "
```

The bootloader can:
1. Receive a firmware image (showing name, size in bytes)
2. Verify the image integrity
3. Flash the new image
4. Restart the device

### Diagnostic Format Strings

```c
"SYSTEM "        // System status screen
"Motor    "      // Motor status
"Motor  %d"      // Motor with numeric value (speed? RPM? error code?)
"NTC        "    // Temperature sensor status
"NTC      %d"    // NTC with numeric value (temperature reading)
"Screen %d"      // Display/screen identifier
"%02d:%02d"      // Time display (HH:MM or MM:SS)
"%2d:%02dh"      // Duration display with 'h' suffix
```

### Error Handling

| Error String | Meaning |
|-------------|---------|
| `Heater error` | Heating element malfunction |
| `NTC short` | Temperature sensor shorted |
| `NTC opened` | Temperature sensor open circuit (disconnected) |
| `Motor overload` / `Surcharge moteur` | Motor overloaded — too much resistance |

### Safety Messages

Critical safety warnings displayed when blade is spinning:

- **French**: "NE PAS OUVRIR AVANT L'ARRET COMPLET DES LAMES"
- **English**: "DO NOT OPEN UNTIL BLADE STOPS"
- **German**: "NICHT ÖFFNEN BEVOR DAS MESSER ZUM STILLSTAND GEKOMMEN IST"
- **Spanish**: "NO ABRIR ANTES DE QUE PARE DE LA CUCHILLAS"
- **Italian**: "APRIRE SOLAMENTE QUANDO LE LAME SARANNO FERME"
- **Dutch**: "NIET OPENEN TOT MES VOLLEDIG TOT STILSTAND IS GEKOMEN"

Also: "WAIT UNTIL BLADE STOPS" and "HOT MIX: PRESS/APPUI/Drücken/PULSA/DRUK 3 S OP" (hold 3 seconds to engage Hot Mix mode).

---

## Multi-Language Support

The firmware supports **6 languages**:

| Language | Evidence |
|----------|----------|
| **French** | Primary language (menu text, error messages, cooking modes) |
| **English** | Full translation |
| **German** (Deutsch) | Full translation |
| **Spanish** (Español) | Full translation |
| **Italian** (Italiano) | Full translation |
| **Dutch** (Nederlands) | Full translation |

All UI strings, cooking program names, error messages, and safety warnings are translated in all 6 languages.

---

## Cooking Programs / Auto Modes

### Main Cooking Programs

| French Name | English Name | Category |
|-------------|-------------|----------|
| Vapeur | Steam | Cooking |
| Vapeur XXL | Steamer XXL | Cooking |
| Mijotage | Simmering | Cooking |
| Soupe velouté | Cream soup | Soup |
| Soupe moulinée | Puréed soup | Soup |
| Rissolage | Stir-Fry | Cooking |
| Rissolage doux | Gentle stir-fry | Cooking |
| Maintien au chaud | Keep warm | Utility |
| Cocotte | Casserole/Dutch oven | Cooking |
| Cuisson | Cooking (generic) | Cooking |

### Prep / Mixing Programs

| French Name | English Name | Category |
|-------------|-------------|----------|
| Smoothie | Smoothie | Blending |
| Blender | Blender | Blending |
| Robot (Food processor) | Food processor | Processing |
| Hot Mix mode | Hot Mix mode | Mixing |
| Blancs en neige | Beaten egg whites | Mixing |
| Pétrin XL | Dough hook XL | Kneading |
| Pâte / Gâteau | Pastry/Cake | Baking |
| Pain / Brioche | Bread/Brioche | Baking |
| Crêpes / Gaufres | Crêpes/Waffles | Baking |
| Chocolat | Chocolate | Dessert |

### Dessert & Ice Programs

| French Name | English Name |
|-------------|-------------|
| Glace pilée | Crushed ice |
| Dessert glacé | Frozen dessert |

### Cleaning Programs

| French Name | English Name |
|-------------|-------------|
| Rinçage eco | Eco rinse |
| Rinçage medium | Regular rinse |
| Rinçage intensive | Intensive rinse |

### Special Modes

- **Expert mode** — Manual control over temperature, speed, and time
- **Demonstration mode** — Store demo mode ("Mode Démonstration activé" / "Demonstration mode ON")
- **Child lock** ("Enfants" / "Child lock" / "Kindersicherung" / "Sicurezza bimbi" / "Kinderslot")
- **Stand-by** — Configurable sleep timeout
- **Boulangerie / Baking** — Bread baking mode

---

## Settings Menu

The settings menu includes:

| Setting | Description |
|---------|-------------|
| Languages / Langues | 6 language options |
| Sound / Sonido / Suono / Geluid | Audio feedback control |
| Brightness / Luminosité / Helderheid | Screen brightness (clair/light, sombre/dark) |
| Display / Affichage / Schermo | Screen appearance settings |
| Menu order / Ordre menus | Customize menu item ordering |
| Counter / Compteur / Contatore | Usage hour counter |
| Working Hours / In bedrijf tijd | Total operating hours tracker |
| 12 Hours / 12 Heures | 12-hour time format toggle |
| User manual / Manuel | Built-in instruction reference |
| Recipes / Recettes / Rezepte / Ricette | Recipe access |
| Auto programmes | Auto cooking program settings |
| Versions | Firmware version display |
| Accessories / Accessoires | Accessory information |
| Stand-by | Sleep mode configuration |

---

## flash.bin — External SPI Flash (Display Assets)

### Purpose

The 1 MB external flash chip stores all graphical assets for the LCD display. This includes:
- **Icons** for cooking modes, settings, and status indicators
- **UI graphics** (buttons, backgrounds, frames)
- **Font glyphs** for multi-language text rendering
- **Bitmap images** (at least one BMP signature detected)

### Data Format

The graphics are stored in a **custom RLE (Run-Length Encoded) format**:

```
Structure per drawing command:
  [count]                    - Number of pixels to draw
  [00 80]                    - Opaque pixel marker
  [RR GG BB]                 - 24-bit RGB color value

  [count]                    - Number of pixels to skip
  [00 00]                    - Transparent/skip marker
  [FF FF FF]                 - Background color (white)
```

This encoding is efficient for the type of graphics used (icons with flat colors and transparency), keeping the external flash requirements to just 1 MB.

### Display Characteristics

- **Color depth**: 24-bit RGB (based on 3-byte color values in the RLE data)
- **Display resolution**: Likely **480x272** (common TFT size for the LPC1788's LCD controller, references to 480 found in the MCU firmware)
- **Color palette**: Grayscale tones dominate the icon data (values like `10 10 10`, `30 30 30`, `50 50 50`, `9F 9F 9F`, `CF CF CF`, `EF EF EF`, `FF FF FF`), suggesting a clean, modern UI design with primarily monochrome icons

### Flash Layout

| Region | Size | Contents |
|--------|------|----------|
| `0x00000-0x0C000` | 48 KB | Icon/graphic assets (high entropy — complex images) |
| `0x0C000-0x18000` | 48 KB | RLE-encoded icons (low entropy — simpler icons/glyphs) |
| `0x18000-0xFA9AB` | ~905 KB | Mixed graphics, fonts, and larger bitmap assets |

The entire 1 MB flash is utilized — no large erased (0xFF) regions were found.

### Repeated Pattern Groups (ASCII interpretation of RGB data)

The strings output shows repeating 3-character groups that are actually RGB pixel values interpreted as ASCII. For example:
- `www` = RGB(0x77, 0x77, 0x77) — medium gray
- `ttt` = RGB(0x74, 0x74, 0x74) — slightly darker gray
- `ooo` = RGB(0x6F, 0x6F, 0x6F) — dark gray
- `sss` = RGB(0x73, 0x73, 0x73) — gray

These confirm the grayscale icon theme.

---

## Hardware Architecture Summary

```
┌─────────────────────────────────────────────────┐
│                  Magimix Cook Expert             │
├─────────────────────────────────────────────────┤
│                                                  │
│   ┌──────────────┐     ┌──────────────────┐     │
│   │  NXP LPC1788 │────▶│  TFT LCD Panel   │     │
│   │  ARM Cortex-M3│     │  (likely 480x272) │     │
│   │  120 MHz      │     │  24-bit color     │     │
│   └──────┬───────┘     └──────────────────┘     │
│          │                                       │
│   ┌──────┴───────┐                               │
│   │ Peripherals: │                               │
│   │              │     ┌──────────────────┐     │
│   │ SPI ─────────┼────▶│ External Flash   │     │
│   │              │     │ 1MB (flash.bin)  │     │
│   │              │     │ Graphics assets  │     │
│   │              │     └──────────────────┘     │
│   │              │                               │
│   │ UART0 ───────┼────▶ Bluetooth Module        │
│   │              │     (Smart Connect key)       │
│   │              │     (optional accessory)      │
│   │              │                               │
│   │ I2C0 ────────┼────▶ NTC Temperature Sensor  │
│   │              │                               │
│   │ MCPWM ───────┼────▶ Motor Driver            │
│   │              │                               │
│   │ Timer2 ──────┼────▶ Motor Speed Control     │
│   │              │                               │
│   │ GPIO ────────┼────▶ Buttons / LEDs /        │
│   │              │     Relays / Heater          │
│   │              │                               │
│   │ SSP2 ────────┼────▶ Touch Controller (?)    │
│   │              │                               │
│   │ LCD Ctrl ────┼────▶ TFT Display Interface   │
│   │              │                               │
│   │ EMC ─────────┼────▶ External Memory Bus     │
│   └──────────────┘                               │
│                                                  │
│   ┌──────────────┐     ┌──────────────────┐     │
│   │   Heater     │     │   Motor          │     │
│   │   Element    │     │   (blade/mixer)  │     │
│   └──────────────┘     └──────────────────┘     │
│                                                  │
│   ┌──────────────┐     ┌──────────────────┐     │
│   │  Buzzer      │     │  Weight Sensor?  │     │
│   └──────────────┘     └──────────────────┘     │
│                                                  │
└─────────────────────────────────────────────────┘
```

---

## Key Technical Findings

1. **No RTOS detected** — Despite having PendSV/SysTick handlers (suggesting task switching), no FreeRTOS or CMSIS-RTOS markers were found. The scheduler is likely **custom/proprietary**.

2. **Bluetooth is optional** — The "Smart Connect" Bluetooth module is an add-on accessory, not standard equipment. When present, it enables mobile app control (Android & iOS).

3. **Over-the-air updates** — The firmware contains a complete update protocol with file transfer, size validation, integrity verification, and restart. Updates likely come via the Bluetooth Smart Connect module.

4. **6-language support baked in** — All languages ship in every unit. No separate language packs.

5. **NTC-based temperature control** — Uses NTC (Negative Temperature Coefficient) thermistors for temperature sensing. Error detection for both short-circuit and open-circuit sensor faults.

6. **Motor monitoring** — Motor overload detection with multi-language error messages. The MCPWM peripheral handles precise motor speed control.

7. **Blade safety interlock** — The `tmr_WaitBlade` timer and safety messages confirm a software-enforced safety system that prevents lid opening while blades are spinning.

8. **Usage tracking** — A "Working Hours" counter tracks total operating time, stored in non-volatile memory.

9. **Demonstration mode** — A store demo mode exists, toggled in settings, for retail display units.

10. **Database key `dba_`** — A `dba_` prefix string suggests settings/recipes are stored in a structured key-value database format in flash memory.
