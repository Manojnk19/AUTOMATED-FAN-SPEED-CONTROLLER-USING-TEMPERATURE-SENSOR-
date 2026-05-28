#include <DHT.h>
#include <LiquidCrystal_I2C.h>

// Pin Definitions
#define DHTPIN 2
#define DHTTYPE DHT11
#define IR_SENSOR 3
#define FAN_PIN 9

// Initialize DHT Sensor
DHT dht(DHTPIN, DHTTYPE);

// Initialize LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);

int temperature = 0;
int fanSpeed = 0;

void setup()
{
  pinMode(IR_SENSOR, INPUT);
  pinMode(FAN_PIN, OUTPUT);

  Serial.begin(9600);

  dht.begin();

  lcd.begin();
  lcd.backlight();

  lcd.setCursor(0,0);
  lcd.print("FAN CONTROLLER");
  delay(2000);

  lcd.clear();
}

void loop()
{
  int motion = digitalRead(IR_SENSOR);

  temperature = dht.readTemperature();

  lcd.setCursor(0,0);
  lcd.print("Temp: ");
  lcd.print(temperature);
  lcd.print((char)223);
  lcd.print("C ");

  // Motion Detected
  if(motion == HIGH)
  {
    lcd.setCursor(0,1);
    lcd.print("Motion Detected");

    // Fan Speed Control
    if(temperature < 20)
    {
      fanSpeed = 0;
    }
    else if(temperature >= 20 && temperature < 30)
    {
      fanSpeed = 100;
    }
    else if(temperature >= 30 && temperature < 35)
    {
      fanSpeed = 180;
    }
    else
    {
      fanSpeed = 255;
    }

    analogWrite(FAN_PIN, fanSpeed);
  }
  else
  {
    analogWrite(FAN_PIN, 0);

    lcd.setCursor(0,1);
    lcd.print("No Motion      ");
  }

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" C  ");

  Serial.print("Fan Speed: ");
  Serial.println(fanSpeed);

  delay(1000);
}
