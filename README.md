# Project Overview

The prosthetic team at LHNT aims to develop a functional prosthetic hand, similar to real-life medical prosthetics through the actuation, 3D modeling, and hardware-software integration teams. The prosthetic hand currently has one degree of freedom with servos, an open and closed hand, but we aim to achieve two degrees of freedom through individual mobility in each finger. The wrist rotates with a stepper motor and the elbow extends with a linear actuator. These movements are performed through a WiFi connection, where we can manually select 'buttons' on the IP website generated from the ESP32 to open and close the hand.

## File Usage Instructions
### Prerequisites
- ESP32 - This project uses the ESP32 Wroom, a microcontroller great for Bluetooth and Wifi interfacing. Any similar microcontroller will work, but some steps, such as driver and library installation, will need to be modified.
    
- Arduino IDE, version 2.3.3. Install Link - https://www.arduino.cc/en/software
  - Necessary libraries - ESP32Servo, WiFi, ESPAsyncWebServer
    
- Drivers for ESP32 (or similar microcontroller). ESP32 Drivers - https://www.silabs.com/developer-tools/usb-to-uart-bridge-vcp-drivers?tab=downloads
  - **The drivers must be installed and updated in the device manager must be updated - if not, Arduino IDE will not recognize the microcontroller.**

### File Setup
The setup for running the files above is as follows:
- Connect the ESP32 (or similar microcontroller) to the laptop.
- On "Select Board" next to "Start Debugging", select the port connected to the ESP32. The exact port can be found in the Device Manager.
  - For Mac, it will generally have *USB_to_UART* in the name.
  - For Windows, it will generally have *(USB)* next to the port name
- Browse all board types and select "ESP32 Dev Module"
- Begin testing and uploading code onto the ESP32 (or similar microcontroller).

## Current Goals/Limitations

3D Modeling - The 3D modeling team is currently working on developing a wearable mount to implement full wearability.

Actuation - The Actuation team is working towards using linear actuators and ensuring taut strings to properly close the hand upon servo movement.

Hardware-Software Interfacing (HSI) - The HSI team is working towards redesigning the current servo setup with 360-degree servos and a spool to ensure the hand fully closes upon signal.
- In addition, the ESP32 design is being modified through custom-made 5-1 male-to-female wires to allow easy access and modification for future use.

## Team Structure

*Actuation Team*:
- Design the joints and tensile forces behind them to allow for the opening and closing of the hand.
- Members - Dharsan Selvakumar, Hatim 

*3D Modeling Team*:
- Design the prosthetic hand and mounts necessary for servo placement and control.
- Members: Kate Long, Liam Ignacio, Mehel Kanhere, Rahul Karthik, Rhyan Stresow, Ruba Siddiqi, Varun Sirigireddy

*Hardware Software Integration*:
- Integrate binary signals from machine learning into servo control for opening and closing the hand
- Designed circuit–software interfaces and signal decoding logic
- Members - Daniel Song, Soorya Narayanan, Anna Ledbetter, Jorge Nunez, Alicia Richard, Zara Siddiqi, Aprameya Sudharsan
