#include <stdio.h>

// Simulated GPIO register
// volatile is used because a real hardware register can change unexpectedly
volatile unsigned char gpio = 0;

// GPIO bit positions
#define LED 0
#define MOTOR 1
#define SENSOR 2
#define ALARM 3

// Different operating modes of the system
#define MODE_IDLE 0
#define MODE_ACTIVE 1
#define MODE_ALARM 2

// Stores the current system mode
unsigned char current_mode = MODE_IDLE;


// Set a particular GPIO bit to 1
void set_bit(volatile unsigned char *gpio, unsigned char bit)
{
    *gpio |= (1 << bit);
}

// Clear a particular GPIO bit to 0
void clear_bit(volatile unsigned char *gpio, unsigned char bit)
{
    *gpio &= ~(1 << bit);
}

// Toggle a particular GPIO bit
void toggle_bit(volatile unsigned char *gpio, unsigned char bit)
{
    *gpio ^= (1 << bit);
}

// Check whether a particular GPIO bit is set
// Returns 1 if the bit is HIGH, otherwise returns 0
int check_bit(volatile unsigned char *gpio, unsigned char bit)
{
    if (*gpio & (1 << bit))
    {
        return 1;
    }

    return 0;
}


// Turn the LED ON
void led_on()
{
    set_bit(&gpio, LED);
}

// Turn the LED OFF
void led_off()
{
    clear_bit(&gpio, LED);
}

// Turn the motor ON
void motor_on()
{
    set_bit(&gpio, MOTOR);
}

// Turn the motor OFF
void motor_off()
{
    clear_bit(&gpio, MOTOR);
}

// Read the current sensor status
int sensor_status()
{
    return check_bit(&gpio, SENSOR);
}

// Turn the alarm ON
void alarm_on()
{
    set_bit(&gpio, ALARM);
}

// Turn the alarm OFF
void alarm_off()
{
    clear_bit(&gpio, ALARM);
}


// Generic function to turn any device ON
void device_on(unsigned char device)
{
    set_bit(&gpio, device);
}

// Generic function to turn any device OFF
void device_off(unsigned char device)
{
    clear_bit(&gpio, device);
}

// Generic function to toggle any device
void device_toggle(unsigned char device)
{
    toggle_bit(&gpio, device);
}


// Change the system according to the selected mode
void system_mode(unsigned char mode)
{
    // Active mode: LED and motor ON, alarm OFF
    if (mode == MODE_ACTIVE)
    {
        device_on(LED);
        device_on(MOTOR);
        device_off(ALARM);

        current_mode = MODE_ACTIVE;
    }

    // Idle mode: all devices OFF
    else if (mode == MODE_IDLE)
    {
        device_off(LED);
        device_off(MOTOR);
        device_off(ALARM);

        current_mode = MODE_IDLE;
    }

    // Alarm mode: LED and alarm ON, motor OFF
    else if (mode == MODE_ALARM)
    {
        device_on(LED);
        device_off(MOTOR);
        device_on(ALARM);

        current_mode = MODE_ALARM;
    }
}


int main()
{
    // Start the system in IDLE mode
    system_mode(MODE_IDLE);

    printf("IDLE: %d\n", gpio);
    printf("Current mode: %d\n", current_mode);


    // Change the system to ACTIVE mode
    system_mode(MODE_ACTIVE);

    printf("ACTIVE: %d\n", gpio);
    printf("Current mode: %d\n", current_mode);


    // Change the system to ALARM mode
    system_mode(MODE_ALARM);

    printf("ALARM: %d\n", gpio);
    printf("Current mode: %d\n", current_mode);
}
