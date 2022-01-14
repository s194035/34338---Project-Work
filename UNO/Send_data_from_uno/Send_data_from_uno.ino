#include<SoftwareSerial.h>

  //SoftwareSerial unoSerial (2, 3);

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print(12);
  delay(1000);
}
