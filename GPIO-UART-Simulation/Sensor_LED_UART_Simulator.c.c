#include <stdio.h>

// Bit positions used for the LED and sensor in our simulated GPIO register
#define LED 0
#define SENSOR 2

// This variable is acting like a GPIO hardware register
volatile unsigned char gpio = 0;

// Set the selected bit to 1
// We use this to turn a device ON
void set_device(unsigned char device)
{
    gpio |= (1 << device);
}

// Clear the selected bit to 0
// We use this to turn a device OFF
void clear_device(unsigned char device)
{
    gpio &= ~(1 << device);
}

// Check whether a particular GPIO bit is set
// Returns a non-zero value if the bit is HIGH
int check_device(unsigned char device)
{
    return gpio & (1 << device);
}

// This function simulates sending a status message through UART
// In a real microcontroller, UART would send the data through the TX pin
void uart_send(const char *message1, const char *message2)
{
    printf("UART: %s,%s\n", message1, message2);
}

// Read the sensor state and control the LED accordingly
void update_led()
{
    // If the sensor bit is HIGH, turn the LED ON
    if (check_device(SENSOR))
    {
        set_device(LED);
        uart_send("SENSOR ON", "LED ON");
    }
    // If the sensor bit is LOW, turn the LED OFF
    else
    {
        clear_device(LED);
        uart_send("SENSOR OFF", "LED OFF");
    }
}

int main()
{
    // Simulate the sensor becoming active
    set_device(SENSOR);
    update_led();

    // Simulate the sensor becoming inactive
    clear_device(SENSOR);
    update_led();
}
