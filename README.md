# Project Overview

The prosthetic team at LHNT aims to develop a functional prosthetic hand, similar to real-life medical prosthetics through the actuation, 3D modeling, and hardware-software integration teams. The prosthetic hand currently has one degree of freedom, an open and closed hand, but we aim to achieve two degrees of freedom through individual mobility in each finger. These movements are performed through a WiFi connection, where we can manually select 'buttons' on the IP website generated from the ESP32 to open and close the hand.

## File Usage Instructions
### Prerequisites
- ESP32 - This project uses the ESP32 Wroom, a microcontroller great for Bluetooth and Wifi interfacing. Any similar microcontroller will work, but some steps, such as driver and library installation, will need to be modified.
  - Amazon link: https://www.amazon.com/ESP-WROOM-32-Development-Microcontroller-Integrated-Compatible/dp/B08D5ZD528/ref=sr_1_3?crid=1VQRWBYVUZ902&dib=eyJ2IjoiMSJ9.is-SH_RLGHiZZUrqvTWU_DFFr6XAPKtIzbKWDMtYTKPfP4pfKF5pJnrg5SumFDmGaOotmDMNsjLThAHFW5tguzhOgWdXEc5Yt9X_JYzKxn1NDjjt2MuHnbpO144NCvrHMI8L352Y_CkKsvyTvouuBr4tTC_p0pEAEMhhnAdAeWR5ADbyHhJhVjtOsdwjIxjUzHsmwhfmsBG9zisk2F-LNG_U_q81y01Y7-mTk6nINhw.l5CQTChnKxwzLCJbULXnM_PgUzzCN2kYVPG615fd3Zk&dib_tag=se&keywords=esp32&qid=1740040638&sprefix=esp3%2Caps%2C294&sr=8-3&th=1
    
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

3D Modeling - The 3D modeling team is currently working on developing a wearable mount and a servo holder to implement full wearability.

Actuation - The Actuation team is working towards using linear actuators and ensuring taut strings to properly close the hand upon servo movement.

Hardware-Software Interfacing (HSI) - The HSI team is working towards redesigning the current servo setup with 360-degree servos and a spool to ensure the hand fully closes upon signal.
- In addition, the ESP32 design is being modified through custom-made 5-1 male-to-female wires to allow easy access and modification for future use.

## Team Structure

*Actuation Team*:
- Design the joints and tensile forces behind them to allow for the opening and closing of the hand.
- Team Lead: Hailey Hyde
- Members - Dharsan Selvakumar, Hatim 

*3D Modeling Team*:
- Design the prosthetic hand and mounts necessary for servo placement and control.
- Team Lead - Taru Mishra
- Members: Kate Long, Liam Ignacio, Mehel Kanhere, Rahul Karthik, Rhyan Stresow, Ruba Siddiqi, Varun Sirigireddy

*Hardware Software Integration*:
- Integrate binary signals from machine learning into servo control for opening and closing the hand.
- Team Lead - Daniel Song
- Members - Anna Ledbetter, Soorya Narayanan, Jorge Nunez, Alicia Richard, Zara Siddiqi, Aprameya Sudharsan
