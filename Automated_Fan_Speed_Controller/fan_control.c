#include <Arduino.h>

#define FAN_PIN 9

void fan_init()
{
    pinMode(FAN_PIN, OUTPUT);
}

void fan_off()
{
    analogWrite(FAN_PIN, 0);
}

void control_fan_speed(int temp)
{
    if(temp < 20)
    {
        analogWrite(FAN_PIN, 0);
    }
    else if(temp >= 20 && temp < 30)
    {
        analogWrite(FAN_PIN, 100);
    }
    else if(temp >= 30 && temp < 35)
    {
        analogWrite(FAN_PIN, 180);
    }
    else
    {
        analogWrite(FAN_PIN, 255);
    }
}
