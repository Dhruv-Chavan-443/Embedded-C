# GPIO + UART Simulation in C

## Overview

This project is a small Embedded C simulation that demonstrates how a microcontroller can read a digital sensor, control an LED, and send the system status through UART.

Since I am working without physical hardware for this exercise, a C variable is used to simulate a GPIO register.

## What This Project Demonstrates

* GPIO bit manipulation
* Setting and clearing individual bits
* Reading the state of a GPIO bit
* Simulating a digital sensor input
* Controlling an LED based on sensor status
* Basic UART communication simulation
* Use of `volatile` for a simulated hardware register

## System Flow

```text
Digital Sensor
      ↓
  GPIO Register
      ↓
 Check Sensor State
      ↓
 ┌────┴────┐
 ON        OFF
 ↓          ↓
LED ON    LED OFF
 ↓          ↓
     UART Status
          ↓
          PC
```

## GPIO Bit Assignment

| Device | Bit |
| ------ | --: |
| LED    |   0 |
| SENSOR |   2 |

The simulated GPIO register is:

```c
volatile unsigned char gpio = 0;
```

For example, when the sensor is ON:

```text
00000100
```

Bit 2 is set.

When the LED is also ON:

```text
00000101
```

Bit 0 and bit 2 are set.

## How It Works

The program uses three basic GPIO operations:

```c
set_device()
clear_device()
check_device()
```

`set_device()` sets a particular bit, `clear_device()` clears it, and `check_device()` reads the state of the bit.

The `update_led()` function checks the sensor state:

* If the sensor is ON → LED is turned ON and the status is sent through simulated UART.
* If the sensor is OFF → LED is turned OFF and the status is sent through simulated UART.

The UART function uses `printf()` to simulate sending data to a PC.

## Example Output

```text
UART: SENSOR ON,LED ON
UART: SENSOR OFF,LED OFF
```

## Embedded Concepts Used

* Bitwise OR `|`
* Bitwise AND `&`
* Bitwise NOT `~`
* Left shift `<<`
* GPIO register concept
* `volatile`
* Digital input/output
* UART concept
* Hardware abstraction through functions

## Note

This is a **software simulation** and does not directly control physical GPIO hardware. In an actual microcontroller, the GPIO register would be a memory-mapped hardware register, and UART communication would use the MCU's UART peripheral and TX pin.
