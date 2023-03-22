#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 2

OneWire oneWire(ONE_WIRE_BUS); 

DallasTemperature sensors(&oneWire);

void setup ()
{
  Serial.begin(9600);
  Serial.print("Test Beginnt");

  sensors.begin();
}
 void loop()
 {
  Serial.println("wird gemessen ...");
  sensors.requestTemperatures();
  Serial.println("Abgeschlossen");

  float temperaturC = sensors.getTempCByIndex(0);

  if (temperaturC !=DEVICE_DISCONNECTED_C)
  {
    Serial.print("Die Temperatur beträgt: ");
    Serial.println(temperaturC);
  }
  else
  {
    Serial.println("Fehler");
  }
 }
