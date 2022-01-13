#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <SPI.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>

const char* ssid = "iPhone"; //Name of network
const char* password = "pass"; //Password for network
const char *mqtt_server = "maqiatto.com"; // We use maqiatto
const int mqtt_port = 1883; 
const char *mqtt_user = "email"; // Maqiatto-user name
const char *mqtt_pass = "pass"; // Maqiatto-user password
//
int IOpin1 = 4;
String payload; //Define payload in global scope

void callback(char* byteArraytopic, byte* byteArrayPayload, unsigned int length);

WiFiClient espClient; //WiFi client initialisation

PubSubClient client(mqtt_server, mqtt_port, callback, espClient); //Connect to mqrtt



void setup() {
  Serial.begin(115200);
  delay(1000);
  setup_wifi(); 
  client.setServer(mqtt_server, mqtt_port); //Connect to mqtt server
  client.setCallback(callback); //Initialises the callback function
}


void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  delay(1000);
}