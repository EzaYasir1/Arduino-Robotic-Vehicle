# Bluetooth Controlled Robotic Vehicle

In this project, a four wheel robot vehicle was made, which was  controlled wirelessly over Bluetooth. An Android phone running a Bluetooth serial terminal app sends single-character commands to an HC-05 or HC-06 module, which the Arduino reads and translates into motor directions through an L298N driver.



Note: Demonstration Video also included.



## Hardware

|Component|Quantity|
|-|-|
|Arduino Uno|1|
|L298N motor driver module|1|
|DC gear motors|4 (2 left, 2 right)|
|HC-05  Bluetooth module|1|
|4x AAA battery pack|1|

## Circuit

See `circuit diagram.png` in the repository.

* Left motors:  L298N Motor A output; right motors: L298N Motor B output
* L298N IN1–IN4: Arduino pins 13, 12, 11, 10
* L298N ENA/ENB: jumper-capped on the board for fixed full speed
* L298N 12V/GND to 4xAAA battery pack; L298N 5V out to Arduino 5V
* HC-05/06 RX/TX to Arduino TX/RX (pins 1/0), VCC to 5V, GND to GND

## Commands

The Arduino listens on hardware serial at 9600 baud and expects single-character commands:

|Command|Action|
|-|-|
|`F`|Forward|
|`B`|Backward|
|`L`|Left|
|`R`|Right|
|`S`|Stop|

In order to utilize these commands, a compatible serial terminal app must be set up, and connected to Bluetooth module hardware.Once achieved, the character is sent and read by the bluetooth\_car.ino script to update the motor states.

## Code

`bluetooth_car.ino` reads serial input, drives IN1–IN4 accordingly.



## Limitations and Future Work



* The current project implementation is limited to manual teleoperation without sensing ability via sensors.So this is a direction this project can be worked with and hence further improved.
* Commands sent as raw ASCII with no acknowledgement and feedback to the phone app. For further reliability, a structured protocol utilizing telemetry feedback like battery levels and sensor data can be implemented as well.

## 
