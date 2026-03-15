# thumbknoblock

Bare-metal firmware for the Silicon Labs **EFR32MG24B210F1536IM48** on the [xG24 Explorer Kit (BRD2703A)](https://www.silabs.com/development-tools/wireless/efr32xg24-explorer-kit).

- **CPU:** ARM Cortex-M33 @ up to 78 MHz, FPU (fpv5-sp-d16), TrustZone
- **Flash:** 1536 KB @ `0x08000000`
- **RAM:** 256 KB @ `0x20000000`
- **SDK:** Gecko SDK 4.4.x (git submodule)

---

## Prerequisites

| Tool | Version | Notes |
|------|---------|-------|
| `arm-none-eabi-gcc` | ≥ 12 | [Arm GNU Toolchain](https://developer.arm.com/downloads/-/arm-gnu-toolchain-downloads) |
| `cmake` | ≥ 3.20 | |
| `ninja` | any | or pass `-G "Unix Makefiles"` |
| SEGGER J-Link | any | [J-Link Software](https://www.segger.com/downloads/jlink/) |
| SEGGER Ozone | ≥ 3.40 | optional, for GUI debugging |

---

## Clone

```sh
git clone --recurse-submodules <repo-url>
cd thumbknoblock
```

If you already cloned without `--recurse-submodules`:

```sh
git submodule update --init --depth 1
```

---

## Build

```sh
cmake -B build -G Ninja
cmake --build build
```

Build outputs in `build/`:

| File | Description |
|------|-------------|
| `xg24_hello.elf` | ELF with debug symbols |
| `xg24_hello.hex` | Intel HEX for flashing |
| `xg24_hello.bin` | Raw binary |
| `xg24_hello.map` | Linker map |

---

## Flash

Connect the xG24 Explorer Kit over USB. The board's on-board J-Link is used automatically.

```sh
JLinkExe -device EFR32MG24B210F1536IM48 -if SWD -speed 4000 -CommandFile flash.jlink
```

Or via `JLinkExe` interactive mode:

```
J-Link> loadfile build/xg24_hello.hex
J-Link> r
J-Link> g
J-Link> exit
```

---

## Debug (SEGGER Ozone)

1. Open Ozone.
2. **File → Open Project** → select `thumbknoblock.jdebug`.
3. Click **Download & Reset Program** (or press F5).

The project is pre-configured for SWD over the on-board J-Link at 4 MHz with peripheral registers loaded from the Gecko SDK SVD.

> **Note:** The Gecko SDK submodule must be initialized for the device SVD (`gecko_sdk/platform/Device/SiliconLabs/EFR32MG24/SVD/…`) to resolve. Ozone falls back to the built-in Cortex-M33 SVD if it is missing.

---

## Project Structure

```
thumbknoblock/
├── src/            # Application entry point and main loop
├── drivers/        # Low-level peripheral drivers (GPIO, UART)
├── hal/            # Hardware abstraction layer
├── bsp/            # Board support (chip init, clock enable)
├── startup/        # Reset handler and interrupt vector table
├── linker/         # Linker script (efr32mg24b210f1536.ld)
├── cmake/          # Toolchain and device CMake files
├── gecko_sdk/      # Silicon Labs Gecko SDK (git submodule, gsdk_4.4.x)
├── flash.jlink     # J-Link flash script
└── thumbknoblock.jdebug  # SEGGER Ozone project file
```
