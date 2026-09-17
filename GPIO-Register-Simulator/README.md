**#GPIO Register Simulator**



A small Embedded C project that simulates GPIO register control using bit manipulation and pointers.



**## Concepts Practiced**



\* Bit manipulation

\* Set, clear, toggle, and check operations

\* Bit masks

\* Pointers

\* `volatile`

\* `unsigned char`

\* `#define`

\* Functions

\* GPIO register simulation

\* Device control

\* State-based system modes



**## GPIO Mapping**



| **Bit**   | **Device** |

| ----- | ------ |

| Bit 0 | LED    |

| Bit 1 | MOTOR  |

| Bit 2 | SENSOR |

| Bit 3 | ALARM  |



**## System Modes**



**### IDLE**



\* LED OFF

\* MOTOR OFF

\* ALARM OFF



**### ACTIVE**



\* LED ON

\* MOTOR ON

\* ALARM OFF



**### ALARM**



\* LED ON

\* MOTOR OFF

\* ALARM ON



**## Example**



The GPIO register is simulated using:



```c

volatile unsigned char gpio = 0;

```



The project demonstrates how individual bits can be manipulated to represent hardware device states.



