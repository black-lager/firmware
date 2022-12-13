# Black Lager Firmware

## Overview

This repository contains the device firmware for the Black Lager project.

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

Next step is to locate the firmware file you have downloaded, and open the directory in terminal. Run the code below to flash the firmware on your device.

```bash
bin/device-install.sh -f FIRMWARE_PATH.bin
```

# Developers

Hello fellow programmers and developers, you might wonder how can I build a customized version of firmware so I can develop on top of the Meshtastic firmware. You can follow the [instruction](https://meshtastic.org/docs/development/firmware/build) here to build your own version.
