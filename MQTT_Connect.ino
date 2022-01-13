// OBS: This function is called everytime the MCU receives a message
void callback(char* byteArraytopic, byte* byteArrayPayload, unsigned int length) {
 pinMode(IOpin1, OUTPUT);

  String topic;
  topic = String(byteArraytopic); //Convert string to byteArray
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.println("] ");
  // Convert payload to a string
  if (topic == "email") { // OBS: Subscribe to topic
    payload = ""; // Reset payload variable
    for (int i = 0; i < length; i++) {
      payload += (char)byteArrayPayload[i];
    }

    Serial.println(payload);
    if(payload == "window_open"){digitalWrite(IOpin1, HIGH);}
    else if(payload == "window_close"){digitalWrite(IOpin1, LOW);}
    
    //client.publish("email", "Hello World"); // Publish besked fra MCU til et valgt topic. Husk at subscribe til topic'et i NodeRed.
  }
}

void setup_wifi() {
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}


//If connection is lost the reconnect funciton is called to get the connection back
void reconnect() {
  while (!client.connected()) {
    Serial.print("Tries to obtain MQTT connection...");

    if (client.connect("GroupNamexMCU", mqtt_user, mqtt_pass)) { // Connects to server
      Serial.println("connected");
      client.subscribe("email"); //Subscribe to topic
      //client.subscribe("Test1"); //You can subscribe to multiple topics
      // Eller til samtlige topics ved at bruge '#' (Se Power Point fra d. 18. marts)
      // client.subscribe("#");

    //If the connection is lost try to gain
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}