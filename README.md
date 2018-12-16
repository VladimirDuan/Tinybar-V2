
# Tinybar V2

## Enviroment

### Configure the toolchain: Windows

Open the tools folder, install SDCC and WCHISPTool.

Unzip buildtools.zip, add buildtools/bin to $PATH.

** Make sure to have installed the tools above. **

Install of [Git for Windows](https://gitforwindows.org/) and [VSCode](https://code.visualstudio.com/) is recommended.

### Configure the toolchain: Mac OSX

Install xcode for build tools, then download the OSX version of SDCC compiler.

Use this ISPtool [Opensource CH55x ISPtool](https://github.com/rgwan/librech551) to program the flash. Find the binary release, then download the correct version for OSX.

### Configure the toolchain: Linux (Ubuntu)

Get the compiler:

    apt-get install sdcc

Use this ISPtool [Opensource CH55x ISPtool](https://github.com/rgwan/librech551) to program the flash. Find the binary release, then download the correct version for Linux.

## Compiling and flashing

### Compiling:

    cd software/ch554_sdcc_lib/examples/tinybar_v2/
    make

### Flashing:

The tinybar_v2.hex should be generated after a successful compilation, just download it into Tinybar use WCHISPTool (Windows) or librech551 (Linux or Mac OSX).

1. Turn off the tinybar.
2. Press down the red button and insert the USB plug.
3. Flash the tinybar.

Never delete the code for entering bootloader, or you should connect D+ to Vcc for bootloader entering.

# License

GPLv3

# References

* [Opensource CH55x SDK](https://github.com/Blinkinlabs/ch554_sdcc)
* [Opensource CH55x ISPtool](https://github.com/rgwan/librech551)
* [Opensource buildtools for Windows](https://github.com/gnu-mcu-eclipse/windows-build-tools)

