# Flame and Smoke Detection System

## Overview
This project is designed to detect the presence of a flame and smoke using an Arduino board. It utilizes a flame sensor and a smoke sensor to monitor the environment. When a flame or smoke is detected, the system will display the status on an LCD screen and sound a buzzer to alert the user.

## Components
- Arduino board
- Flame sensor (connected to digital pin 3)
- Smoke sensor (connected to analog pin A0)
- Buzzer (connected to digital pin 4)
- LCD screen with I2C interface (16x2 characters, I2C address 0x27)
- Connecting wires

## Libraries
- `Wire.h` - Library for I2C communication
- `LiquidCrystal_I2C.h` - Library for controlling the LCD screen with I2C interface

## Circuit Diagram
- **Flame sensor**: Connect the output to digital pin 3
- **Smoke sensor**: Connect the output to analog pin A0
- **Buzzer**: Connect the positive pin to digital pin 4 and the negative pin to GND
- **LCD**: Connect SDA to A4, SCL to A5, VCC to 5V, and GND to GND

## Code Description

### Setup Function
```cpp
void setup() {
    lcd.init();           // Initialize the LCD screen
    lcd.backlight();      // Turn on the LCD backlight
    pinMode(flame, INPUT); // Set the flame sensor pin as an input
    pinMode(buzzer, OUTPUT); // Set the buzzer pin as an output
    Serial.begin(9600);   // Start serial communication at 9600 baud rate
}
