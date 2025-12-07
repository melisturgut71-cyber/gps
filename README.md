ESP32 GPS Tracking Module (NEO-6M)
📍 Overview
This repository contains firmware for interfacing an ESP32 microcontroller with a NEO-6M GPS Module. Using the TinyGPS++ library and the ESP32's Hardware Serial (UART2), the system reads raw NMEA sentences and parses them into readable navigation data, including latitude, longitude, speed, and satellite count.

This module is designed to be a component of a larger Vehicle Telematics System, providing real-time location data alongside vehicle diagnostics.

🚀 Features
High-Precision Positioning: Retrieves Latitude and Longitude (6 decimal places).

Speed Calculation: Real-time speed monitoring in km/h.

Signal Quality: Monitors the number of connected satellites.

UART Communication: Utilizes ESP32's Serial2 hardware port for reliable data transfer without interfering with USB logging.

Connection Safe-guard: Includes a timeout check to detect wiring or module failures.

🛠️ Hardware Requirements
Microcontroller: ESP32 Development Board (DOIT DEVKIT V1 or similar)

GPS Module: u-blox NEO-6M (or compatible UART GPS module)

Antenna: Ceramic active antenna (usually included with the module)

🔌 Pinout & Wiring
The NEO-6M module communicates via UART (Serial). Note that TX and RX lines must be crossed.

NEO-6M Pin,ESP32 Pin,Description
VCC,3.3V / 5V,"Power Supply (Check module specs, usually 3.3V safe)"
GND,GND,Ground
TX,GPIO 16,Connects to ESP32 RX2
RX,GPIO 17,Connects to ESP32 TX2

Libraries Required
This project relies on the TinyGPS++ library for NMEA parsing.

Arduino IDE: Sketch > Include Library > Manage Libraries > Search for "TinyGPSPlus" > Install.

PlatformIO: Add mikalhart/TinyGPSPlus to your platformio.ini file.

⚠️ Important Notes
First Fix (Cold Start): GPS modules can take 1 to 5 minutes to find satellites when powered on for the first time or after moving a long distance.

Indoor Usage: GPS signals are weak indoors. Test the module outdoors or near a window for best results.

Baud Rate: Most NEO-6M modules default to 9600 baud. If you don't get data, check if your module is configured for a different rate (e.g., 4800 or 38400).

📄 License
This project is open-source and available under the MIT License.
