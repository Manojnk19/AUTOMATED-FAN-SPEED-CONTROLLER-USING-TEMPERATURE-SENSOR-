#include "fan_control.h"
#include "sensor_control.h"
#include "lcd_display.h"

void setup()
{
    lcd_init();
    sensor_init();
    fan_init();
}

void loop()
{
    int motion = read_ir_sensor();
    int temp = read_temperature();

    display_temperature(temp);

    if(motion == 1)
    {
        control_fan_speed(temp);
    }
    else
    {
        fan_off();
    }
}
