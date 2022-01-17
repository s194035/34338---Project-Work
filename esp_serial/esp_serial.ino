#include<SoftwareSerial.h>
SoftwareSerial SUART(4, 5); //SRX=Dpin-D2; STX-DPin-D1
//-------------------------
#include <DHT.h>
int temperature;
int humidity;
#define DHTPIN 12
#define DHTTYPE DHT11 
DHT dht11(DHTPIN, DHTTYPE);
//--------------------------------------------

void setup()
{
  Serial.begin(115200); //enable Serial Monitor
  SUART.begin(115200); //enable SUART Port
  dht11.begin();
}

void loop()
{
  //---acquire Temp and Humidity signal and save in variables
  humidity = dht11.readHumidity();
  temperature = dht11.readTemperature();
  
  //---show temp and humidity as integers on Serial moniotr
  Serial.print("Temperature = "); Serial.print((int)temperature); Serial.print(" degC");
  Serial.print("  ");  //space
  Serial.print("Humidity = "); Serial.print((int)humidity); Serial.println(" %H");
  
  //----Send Temp and Humidity signal to Arduino via SUART port----
  SUART.print('<');                   //<(start mark)
  SUART.print((int)temperature,DEC);
  SUART.print(',');                   //,(data seperator)
  SUART.print((int)humidity, DEC); 
  SUART.print('>');                   //>(end mark)
  SUART.println();
  delay(1000);
}
