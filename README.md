# Waste Watcher - MQTT

Waste Watcher is an IoT based sensor module to help keep track of waste data metrics such as bin fullness, bin weight, images of waste, etc. This is intended to help quantify waste data and promote actionable solutions to lower the amount of waste people throw away.

You can view the [original repo here.](https://github.com/zotbins/waste_watcher) This repo is intended to store the changes of the MQTT Waste Watcher version, where the waste metrics are publishes to a MQTT broker, while still optimizing performance for low power consumption.

## Prerequisites
View the [original repo](https://github.com/zotbins/waste_watcher/blob/release-v0/guide/guide.md) for more thorough instructions

### Hardware
- ESP32-CAM
- HC-SR04 Ultrasonic Sensor
- FTDI Adapter
- Jumper Cap

Connect the following pins on the ESP32-CAM -> HC-SR04
- 5V -> 5V
- GND -> GND
- IO13 -> TRIG
- IO12 -> ECHO

Connect the following pins on the ESP32-CAM -> FTDI Adapter
- 5V -> 5V
- GND -> GND
- U0R -> TXD
- U0T -> RXD

Attach a jumper cap on the pins on the ESP32-CAM
- IO0 -> GND

### Software
- [Visual Studio Code](https://code.visualstudio.com/)
- [PlatformIO](https://platformio.org/), a cross-platform VSCode-based IDE for embedded system development
- [CP210x USB to UART Bridge VCP Drivers](https://www.silabs.com/developers/usb-to-uart-bridge-vcp-drivers), only needed if proper FTDI Adapter drivers are not already installed

## Compiling and Uploading the Code

1. First, clone the repo and its dependencies using the command
```bash
git clone --recursive https://github.com/zotbins/Waste-Watcher-AWS-IoT-Core.git
```

2. In the ```include``` directory, create a header file called ```config.h```.

3. Copy the contents of ```config.h.txt``` into ```config.h``` and fill out the header file with the relevant information.

4. Build the project by clicking on the ```Build``` button in the PlatformIO tab in VSCode.

5. **IMPORTANT:** Enter programming mode on the ESP32-CAM by attaching a jumper cap on the pins ```IO0``` and ```GND``` and pressing on the reset push button on the back.

6. Upload the application by clicking on the ```Upload``` Button in the PlatformIO tab.

7. Remove the jumper cap from ```IO0``` and ```GND``` and press on the reset push program to start the application.
