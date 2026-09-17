#include <stdio.h>
volatile unsigned char gpio = 0;
#define LED 0
#define MOTOR 1
#define SENSOR 2
#define ALARM 3
#define MODE_IDLE 0
#define MODE_ACTIVE 1
#define MODE_ALARM 2
unsigned char current_mode=MODE_IDLE;
void set_bit(volatile unsigned char *gpio, unsigned char bit)
{
    *gpio |= (1 << bit);
}
void clear_bit(volatile unsigned char *gpio, unsigned char bit)
{
    *gpio &= ~(1 << bit);
}
void toggle_bit(volatile unsigned char *gpio, unsigned char bit)
{
    *gpio ^= (1 << bit);
}
int check_bit(volatile unsigned char *gpio, unsigned char bit)
{
    if (*gpio & (1 << bit))
    {
        return 1;
    }
    return 0;
}
void led_on()
{
    set_bit(&gpio, LED);
}
void led_off()
{
    clear_bit(&gpio, LED);
}
void motor_on()
{
    set_bit(&gpio, MOTOR);
}
void motor_off()
{
    clear_bit(&gpio, MOTOR);
}
int sensor_status()
{
    return check_bit(&gpio, SENSOR);
}
void alarm_on()
{
    set_bit(&gpio, ALARM);
}
void alarm_off()
{
    clear_bit(&gpio, ALARM);
}
void device_on(unsigned char device)
{
    set_bit(&gpio, device);
}
void device_off(unsigned char device)
{
    clear_bit(&gpio, device);
}
void device_toggle(unsigned char device)
{
    toggle_bit(&gpio, device);
}
void system_mode(unsigned char mode)
{
    if (mode == MODE_ACTIVE)
    {
        device_on(LED);
        device_on(MOTOR);
        device_off(ALARM);
        current_mode=MODE_ACTIVE;
    }
    else if (mode == MODE_IDLE)
    {
        device_off(LED);
        device_off(MOTOR);
        device_off(ALARM);
        current_mode=MODE_IDLE;
    }
    else if (mode == MODE_ALARM)
    {
        device_on(LED);
        device_off(MOTOR);
        device_on(ALARM);
        current_mode=MODE_ALARM;
    }
}
int main()
{
    system_mode(MODE_IDLE);
    printf("IDLE: %d\n", gpio);
    printf("Current mode: %d\n", current_mode);

    system_mode(MODE_ACTIVE);
    printf("ACTIVE: %d\n", gpio);
    printf("Current mode: %d\n", current_mode);

    system_mode(MODE_ALARM);
    printf("ALARM: %d\n", gpio);
    printf("Current mode: %d\n", current_mode);
}