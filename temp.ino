// Example testing sketch for various DHT humidity/temperature sensors
// Written by ladyada, public domain

#include "DHT.h"

#define DHTPIN 2 // what pin we're connected to

// Uncomment whatever type you're using!
//#define DHTTYPE DHT11 // DHT 11 
#define DHTTYPE DHT22 // DHT 22 (AM2302)
//#define DHTTYPE DHT21 // DHT 21 (AM2301)

// Connect pin 1 (on the left) of the sensor to +5V
// Connect pin 2 of the sensor to whatever your DHTPIN is
// Connect pin 4 (on the right) of the sensor to GROUND
// Connect a 10K resistor from pin 2 (data) to pin 1 (power) of the sensor

DHT dht(DHTPIN, DHTTYPE);

void setup() {
Serial.begin(9600); 
Serial.println("DHT11-test");
pinMode(8, OUTPUT);
dht.begin();
}

void loop() {
//   float h = dht.readHumidity();
//   float t = dht.readTemperature();
 float h = dht.readHumidity();
 float t = dht.readTemperature();
 float f = dht.readTemperature(true);
 
if (isnan(t) || isnan(h)) {
    Serial.println("Failed to read from DHT");
    return;
  } 
    float hif = dht.computeHeatIndex(f, h);  
    float hic = dht.computeHeatIndex(t, h, false); 
    Serial.print("Humidity: "); 
    Serial.print(h);
    Serial.print(" %\t");
    Serial.print("Temperature: "); 
    Serial.print(t);
    Serial.println(" *C");
  
   digitalWrite(8, HIGH); 
   delay(1000);
   digitalWrite(8, LOW); 
   delay(1000); 
}
