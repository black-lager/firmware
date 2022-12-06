# Supported Hardware

Supported hardware
- LILYGO Lora v2.1-1.6
- LILYGO T-Beam
- Note: Other models listed at [here](https://meshtastic.org/docs/supported-hardware) may also work, but they have not been tested with the Black Lager firmware or application

## Installation
### Install Prerequisite Software
Python3 and pip are required for Black-Lager. Check if you have python3 and pip installed with the following command, if not please install them.

```bash
python3 --version
pip3 --version
```
Install esptool
```bash
pip3 install --upgrade esptool
```
Test if esptool is working
```bash
esptool chip_id
```
```bash
# You should see a result similar to this:
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
