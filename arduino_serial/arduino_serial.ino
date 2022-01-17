#include<SoftwareSerial.h>
SoftwareSerial SUART(2, 3); //SRX=Dpin-2; STX-DPin-3
//-------------------------
#include <DHT.h>
#define DHTPIN 9
#define DHTTYPE DHT11
DHT dht11(DHTPIN, DHTTYPE);
int temperature = 0;
int humidity = 0;
//--------------------------------------------

void setup()
{
  Serial.begin(115200); //enable Serial Monitor
  SUART.begin(115200); //enable SUART Port
  dht11.begin();

}

void loop()
{

  byte n = SUART.available(); //n != 0 means a character has arrived
  if (n != 0)
  {
    char x = SUART.read();  //read character
    Serial.print(x);

  }
}
