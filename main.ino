#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <SPI.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>

// Definerer id og password til netværksforbindelse som NodeMCU anvender
const char* ssid = "iPhone"; //Indsæt navnet på jeres netværk her
const char* password = "pass"; //Indsæt password her

// Definerer information til mqtt serveren
const char *mqtt_server = "maqiatto.com"; //navn på mqtt-server. Find navnet på cloudmqtt-hjemmesiden
const int mqtt_port = 1883; // Definerer porten
const char *mqtt_user = "email"; // Definerer mqtt-brugeren
const char *mqtt_pass = "pass"; // Definerer koden til mqtt-brugeren
//
int IOpin1 = 4;
String payload; // Definerer variablen 'payload' i det globale scope (payload er navnet på besked-variablen)

void callback(char* byteArraytopic, byte* byteArrayPayload, unsigned int length);

// Opretter en klient der kan forbinde til en specifik internet IP adresse.
WiFiClient espClient; // Initialiserer wifi bibloteket ESP8266Wifi, som er inkluderet under "nødvendige bibloteker"

// Opretter forbindelse til mqtt klienten:
PubSubClient client(mqtt_server, mqtt_port, callback, espClient);



void setup() {

  Serial.begin(115200); // Åbner serial porten og sætter data raten til 115200 baud
  delay(1000);
  setup_wifi(); // Kører WiFi loopet og forbinder herved.
  client.setServer(mqtt_server, mqtt_port); // Forbinder til mqtt serveren (defineret længere oppe)
  client.setCallback(callback); // Ingangsætter den definerede callback funktion hver gang der er en ny besked på den subscribede "cmd"- topic


}


void loop() {

  // Hvis der opstår problemer med forbindelsen til mqtt broker oprettes forbindelse igen ved at køre client loop
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  delay(1000);
}

//////// Loop slut ////////