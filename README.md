# Black Lager Firmware

## Overview

This repository contains the device firmware for the Black Lager project.
In order to use the Black Lager messaging application, you must flash one of the supported devices with the firmware found in this repo.

## Supported Hardware

- LILYGO Lora v2.1-1.6
- LILYGO T-Beam

## Flashing Instructions

### Install Prerequisite Software

python3 and pip must be installed on the computer used to flash the device.
Check if you have python3 and pip installed with the following commands:

```bash
python3 --version
pip3 --version
```

### Install esptool

```bash
pip3 install --upgrade esptool
```

### Confirm Communication With Chip

Connect the radio to your computer using a data USB cable. Confirm your device is talking to your computer using the following command:

```bash
esptool chip_id
```

You should see a result similar to this:

```bash
mydir$ esptool chip_id
esptool.py v2.6
Found 2 serial ports
Serial port /dev/ttyUSB0
Connecting....
Detecting chip type... ESP32
Chip is ESP32D0WDQ6 (revision 1)
Features: WiFi, BT, Dual Core, 240MHz, VRef calibration in efuse, Coding Scheme None
MAC: 24:6f:28:b5:36:71
Uploading stub...
Running stub...
Stub running...
Warning: ESP32 has no Chip ID. Reading MAC instead.
MAC: 24:6f:28:b5:36:71
Hard resetting via RTS pin...
```

### Download the Firmware

Download the latest release from this repository. Unzip the firmware zip file.

### Navigate to Firmware

`cd` into the directory where you unzipped the latest release. For example:

```bash
cd ~/Downloads/firmware/
```

### Install Firmware

```bash
bin/device-install.sh -f FIRMWARE_PATH.bin
```

Note: Be careful to install the correct firmware for your device.

## Developers

This repository is forked from the [Meshtastic firmware](https://github.com/meshtastic/firmware) repository. The main branch is the default branch for Black Lager development, while the master branch is used to sync updates from the Meshtastic repo.

### Development Environment

PlatformIO is used as a development environment for the firmware.

1. Instructions on how to install PlatformIO can be [found here](https://platformio.org/platformio-ide).

2. Clone the Meshtastic Firmware repository

```bash
git clone https://github.com/black-lager/firmware.git
```

or

```bash
git clone git@github.com:black-lager/firmware.git
```

3. Protocol buffer messages are defined in a central [protobufs repository](https://github.com/black-lager/protobufs). To update the repository's submodules, run the following command inside of the firmware repo:

```bash
git submodule update --init
```

### Local Build Instructions

To build a custom version of the firmware after making changes to the firmware code, follow the [instructions here](https://meshtastic.org/docs/development/firmware/build). Devices can be flashed with this build for testing.

### CI/CD

The main branch of this repo is protected. In order to push code to main, you must make a pull request which must pass code review. Automatic CI/CD is set up to make a new release of the firmware when code is pushed to the main branch. This is automated through GitHub actions.
