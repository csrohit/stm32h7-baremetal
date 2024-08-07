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

* `src` directory contains all source files for the project
* `include` directory contains all header files for the project

### Source file description

* `STM32F103C8TX_FLASH.ld`  - linker script
* `src\main.c` - application code
* `src\startup_stm32f103c8tx.s` - assembly startup script for blue pill board
* `system_stm32f1xx.c` - clock configuration and system initialization functions

## Run Locally

Running the project is super easy. Just clone, build, and flash.

### Clone the project

1. Using https

    ```bash
    git clone https://github.com/csrohit/bluepill-template-project.git
    cd bluepill-template-project
    ```

2. Using ssh

    ```bash
    git clone git@github.com:csrohit/bluepill-template-project.git
    cd bluepill-template-project
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

1. Connect Stlink to PC and blue pill board using swd headers.
2. Put blue pill board in programming mode.
3. Run following to flash board with binary.

```bash
make flash
```

## Output

Onboard led connected to Pin C13 can be observed to be blinking after 500ms.

## Debug

Click in `Run and Debug` option in VsCode sidebar. Then launch `Cortex Debug` target.

Happy debugging....