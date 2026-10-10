# Arduino-Based Voltage Protection System

## Overview
This project demonstrates a microcontroller-based voltage protection system using an Arduino Uno and Proteus simulation software. It monitors input voltage and protects electrical appliances from abnormal voltage conditions using automatic relay control.

## Features
- Overvoltage detection (above 250 V)
- Undervoltage detection (below 180 V)
- Automatic relay disconnection during voltage faults
- 20×4 LCD voltage and status display
- LED fault indication
- Serial monitoring through the Arduino IDE or Proteus Virtual Terminal
- Circuit simulation using Proteus

## Components Used
- Arduino Uno
- Voltage sensing circuit
- Relay module
- 20×4 LCD
- LED and current-limiting resistor
- Proteus 8 Professional
- Arduino IDE
- EmonLib library

## Working Principle
The system measures the input voltage and compares it with predefined limits.

- **Normal voltage (180–250 V):** The relay remains ON.
- **Overvoltage (above 250 V):** The relay turns OFF and the LED indicates a fault.
- **Undervoltage (below 180 V):** The relay turns OFF and the LED indicates a fault.

The measured voltage and system status are displayed on the LCD and sent to the serial monitor.

## Pin Connections

| Component | Arduino Pin |
|---|---|
| LCD RS | 13 |
| LCD EN | 12 |
| LCD D4 | 11 |
| LCD D5 | 10 |
| LCD D6 | 9 |
| LCD D7 | 8 |
| Relay | 7 |
| Fault LED | 6 |
| Voltage Sensor Output | A0 |

## Required Library
Install the **EmonLib** library in the Arduino IDE before compiling the code.

## How to Run
1. Open Code.ino in the Arduino IDE.
2. Install the EmonLib library.
3. Compile the code and resolve any errors.
4. Open the circuit in Proteus and load the compiled Arduino HEX file into the microcontroller.
5. Run the simulation.
6. Change the simulated input voltage and observe the LCD, relay, LED, and serial output.

## Safety Notice
This is an educational simulation project. Never connect AC mains voltage directly to an Arduino pin. Use a properly isolated voltage-sensing circuit and suitable protection components for any real hardware implementation.

## Limitations
The current version demonstrates overvoltage and undervoltage protection. Overcurrent protection and automatic fault-recovery delay are not implemented yet. Voltage readings also depend on correct sensor calibration.

## Author
Md. Samiul Islam Sabbir

## License
No license has been specified yet.
