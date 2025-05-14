#include "DHT.h"
#define DHTPIN 8     // Connected to pin#8
#include <LiquidCrystal.h>

#define DHTTYPE DHT11   // DHT 11 
//#define DHTTYPE DHT22   // DHT 22  (AM2302)
//#define DHTTYPE DHT21   // DHT 21 (AM2301)
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

// Attach pin 1 (leftmost) of the sensor to the 5V supply
// Link pin 2 of the sensor to the DHTPIN you’ve defined in your code
// Connect pin 4 (rightmost) of the sensor to GND
// Place a 10K pull-up resistor between pin 2 (data line) and pin 1 (VCC)

DHT dht(DHTPIN, DHTTYPE);

void setup() 
{
  Serial.begin(9600); 
  Serial.println("DHTxx test!");
 lcd.begin(16, 2);
  dht.begin();
}

void loop() 
{
  // Reading temperature or humidity takes about 250 milliseconds
  float h = dht.readHumidity();
  float t = dht.readTemperature();

 // Check if the readings are valid; NaN results mean there was a problem retrieving the data
  if (isnan(t) || isnan(h)) {
    Serial.println("Failed to read from DHT");
  } else {
 
  lcd.setCursor(0,0);
  lcd.print("Temp=");
  lcd.print(t);
  lcd.print(" *Celsius");
  lcd.setCursor(0,1);
  lcd.print("Humidity=");
  lcd.print(h);
  lcd.print("% ");
  delay(500);
 
    Serial.print("Humidity: "); 
    Serial.print(h);
    Serial.print(" %\t");
    Serial.print("Temperature: "); 
    Serial.print(t);
    Serial.println(" *Celsius");
  }
}