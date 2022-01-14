
#include<SoftwareSerial.h>

SoftwareSerial mySerial (D1, D2);

String valFromUno;
void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200);
  mySerial.begin(9600);
}

void loop() {

  if (mySerial.available() > 0) {
    valFromUno = mySerial.readStringUntil('\r');
    Serial.println(valFromUno);
    if (valFromUno == "12") {
      Serial.print("IF STATEMENT TRUE");
      digitalWrite(LED_BUILTIN, HIGH);
      delay(500);
      digitalWrite(LED_BUILTIN, LOW);
      delay(500);
      valFromUno = "0";
    }
  }
}
