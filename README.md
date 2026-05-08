# 🤖 4-DOF Robotic Arm Control (Arduino)

This project features the firmware for a 4-Degree of Freedom (4-DOF) robotic arm controlled by dual analog joysticks. It focuses on low-latency response and smooth servo motor mapping.

## Overview
The system uses an **Arduino Nano/Uno** to translate analog signals from two joysticks into precise movements for four servo motors: **Base**, **Arm**, **Forearm**, and **Claw (Gripper)**.

## Key Features
- **Dual Joystick Control**: 
  - **Left Stick**: Manages Base rotation and Claw aperture.
  - **Right Stick**: Controls the Arm and Forearm elevation.
- **Enhanced Speed & Fluidity**: Optimized with a 20ms refresh rate for real-time responsiveness.
- **Safety Constraints**: Software-defined angle limits (e.g., 10° to 170°) to prevent mechanical strain or servo stall.
- **Asymmetric Gravity Compensation**: Slower descent speed implemented on the main arm for better stability and safety.

## Hardware Requirements
- **Microcontroller**: Arduino (Uno, Nano, or Mega).
- **Actuators**: 4x MG90S or SG90 Servo Motors.
- **Input**: 2x Analog 2-Axis Joysticks.
- **Power**: External 5V power supply (highly recommended for 4 servos).

## Pin Mapping
| Component | Arduino Pin |
|-----------|-------------|
| Base Servo | 11 |
| Arm Servo | 10 |
| Forearm Servo | 9 |
| Claw Servo | 5 |
| Joystick L (X/Y) | A0 / A1 |
| Joystick R (X/Y) | A2 / A3 |

## Installation
1. Open the `.ino` file in the **Arduino IDE**.
2. Connect your Arduino board.
3. Upload the code and power your servos.

Author
- Lina Bennani - High school Student at GSR (Casablanca, Morocco)
