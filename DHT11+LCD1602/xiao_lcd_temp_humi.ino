#include <Wire.h>
#include "DHT.h"
#include "rgb_lcd.h"

#define DHTTYPE DHT11
#define DHTPIN 0

DHT dht(DHTPIN, DHTTYPE);
rgb_lcd lcd;

void setup()
{
    dht.begin();
    lcd.begin(16, 2);
    lcd.print("Hello, 3dfuns.");
    lcd.setCursor(0, 1);
    lcd.print("Let's make it!!!");
    delay(3000);
    lcd.clear();
}
void loop()
{
    float temp_hum_val[2] = {0};
    
    if (!dht.readTempAndHumidity(temp_hum_val))
    {
        lcd.setCursor(2, 0);
        lcd.print("Temp: ");
        lcd.print(temp_hum_val[1]);
        lcd.print("C");
        lcd.setCursor(2, 1);
        lcd.print("Humi: ");
        lcd.print(temp_hum_val[0]);
        lcd.print("%");
    }
    else
    {
        lcd.clear();
        lcd.setCursor(2, 0);
        lcd.print("Failed.");
    }
    delay(1500);
}
