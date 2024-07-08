# Blink LEDs using Core M7 and Core M4 simultaneously

Harness the power of Dual Core STM32h755 Micro-controller to run blink program on both the cores simultaneously.

![Build Passing](https://img.shields.io/badge/build-passing-brightgreen) [![GPLv3 License](https://img.shields.io/badge/License-GPL%20v3-yellow.svg)](https://opensource.org/licenses/)


## Dependencies

* make
    Make utility is required for configuring and building this project. You can install make on linux by running command:

    ```bash
    # for Debian-based Linux distros
    sudo apt install build-essential

    # for macOS 
    xcode-select --install

    # for macOS using brew formulae
    brew install make
    ```

* gcc-arm-none-eabi toolchain
    ARM cross-platform toolchain is required to build applications for arm mcus. Toolchain can be installed by running following command:

    ```bash
    # for Debian-based Linux distros
    sudo apt install gcc-arm-none-eabi

    # for macOS using brew formulae
    brew install arm-none-eabi-gcc
    ```
* STM32 Cube Programmer
    A GUI cum Command Line utility to program any STM32 micro-controller. This tool can be downloaded from https://www.st.com/en/development-tools/stm32cubeprog.html

## Project Structure

* `cm4` directory contains all source code which runs on CM4
* `cm7` directory contains all header code which runs on CM7


## Run Locally

Running the project is super easy. Just clone, build, and flash.

### Clone the project

1. Using https

    ```bash
    git clone https://github.com/csrohit/stm32h7-baremetal.git
    cd stm32h7-baremetal/h755/blink
    ```

2. Using ssh

    ```bash
    git clone git@github.com:csrohit/stm32h7-baremetal.git
    cd stm32h7-baremetal/h755/blink
    ```
## Configuration

All the configuration required for building this project is given below.

1. Build output directory
    In `Makefile`, output directory can be configured using variable `BUILD_DIR`.

2. Build type
    In `Makefile`, build type can be configured using variable`DEBUG`. Possible values are `Debug` and `Release`.

3. Binary name
    In `CMakeLists.txt`, output binary name can be configured using `project(<binary-name>)` macro.
    ** update above info in `.vscode/launch.json` as well for debugging to work.

## Build

Run following command in terminal to generate flashable binaries for blue pill board. Build files will be written to **Build Output Directory** as configured.

```bash
make all
```

## Flash

1. Connect the USB cable to STM32H7 board.
3. Run following to flash board with binary.

```bash
make flash
```
After running the above command, following logs on terminal are expected
```txt
➜  blink git:(main) ✗ make flash
make -C cm4 flash
STM32_Programmer_CLI -c port=SWD ap=3 -w build/blink.elf -rst
      -------------------------------------------------------------------
                        STM32CubeProgrammer v2.16.0
      -------------------------------------------------------------------

ST-LINK SN  : 002C002B3532510A31333430
ST-LINK FW  : V3J13M4
Board       : NUCLEO-H755ZI-Q
Voltage     : 3.28V
SWD freq    : 8000 KHz
Connect mode: Normal
Reset mode  : Software reset
Device ID   : 0x450
Revision ID : Rev V
Device name : STM32H7xx
Flash size  : 2 MBytes (default)
Start Address : 8000000
Device type : MCU
Device CPU  : Cortex-M7/M4
BL Version  : 0x0



Memory Programming ...
Opening and parsing file: blink.elf
  File          : blink.elf
  Size          : 772.00 B
  Address       : 0x08100000


Erasing memory corresponding to segment 0:
Erasing internal memory sector 8
Download in Progress:
[==================================================] 100%

File download complete
Time elapsed during download operation: 00:00:00.954

MCU Reset

Software reset is performed
make -C cm7 flash
STM32_Programmer_CLI -c port=SWD ap=0 -w build/blink.elf -rst
      -------------------------------------------------------------------
                        STM32CubeProgrammer v2.16.0
      -------------------------------------------------------------------

ST-LINK SN  : 002C002B3532510A31333430
ST-LINK FW  : V3J13M4
Board       : NUCLEO-H755ZI-Q
Voltage     : 3.28V
SWD freq    : 8000 KHz
Connect mode: Normal
Reset mode  : Software reset
Device ID   : 0x450
Revision ID : Rev V
Device name : STM32H7xx
Flash size  : 2 MBytes
Start Address : 8000000
Device type : MCU
Device CPU  : Cortex-M7/M4
BL Version  : 0x91



Memory Programming ...
Opening and parsing file: blink.elf
  File          : blink.elf
  Size          : 772.00 B
  Address       : 0x08000000


Erasing memory corresponding to segment 0:
Erasing internal memory sector 0
Download in Progress:
[==================================================] 100%

File download complete
Time elapsed during download operation: 00:00:00.922

MCU Reset

Software reset is performed
```

## Output

Onboard the program to blink Red 🔴 LED is being run on CM4 while the program to blink the Yellow 🟡 LED is being run on CM7.
