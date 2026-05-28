#include <Arduino.h>
#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11
#define IR_SENSOR 3

DHT dht(DHTPIN, DHTTYPE);

void sensor_init()
{
    pinMode(IR_SENSOR, INPUT);
    dht.begin();
}

int read_ir_sensor()
{
    return digitalRead(IR_SENSOR);
}

int read_temperature()
{
    return dht.readTemperature();
}
