String current() {
  // Send an HTTP GET request
  if ((millis() - lastTime) > timerDelay) {
    // Check WiFi connection status
    if (WiFi.status() == WL_CONNECTED) {
      String serverPath = "http://api.openweathermap.org/data/2.5/weather?q=" + city + "," + countryCode + "&APPID=" + openWeatherMapApiKey;

      jsonBuffer = httpGETRequest(serverPath.c_str());
      //Serial.println(jsonBuffer);
      JSONVar myObject = JSON.parse(jsonBuffer);

      // JSON.typeof(jsonVar) can be used to get the type of the var
      if (JSON.typeof(myObject) == "undefined") {
        Serial.println("Parsing input failed!");
        return "NONE";
      }

      JSONVar weatherObject = myObject["weather"];

      //      Serial.print("JSON object = ");
      //      Serial.println(myObject);
      //      Serial.print("Temperature: ");
      //      Serial.println(myObject["main"]["temp"]);
      //      Serial.print("Pressure: ");
      //      Serial.println(myObject["main"]["pressure"]);
      //      Serial.print("Humidity: ");
      //      Serial.println(myObject["main"]["humidity"]);
      //      Serial.print("Wind Speed: ");
      //      Serial.println(myObject["wind"]["speed"]);
      //      Serial.print("Description: ");
      //      //Serial.println(myObject[0]);
      //      Serial.println(weatherObject[0]["main"]);
      //Serial.println(myObject["main"]["feels_like"]);
    String crnt = JSON.stringify(weatherObject[0]["main"]);

    return crnt;
    }
    else {
      Serial.println("WiFi Disconnected");
    }
    lastTime = millis();
  }
}

String httpGETRequest(const char* serverName) {
  WiFiClient client;
  HTTPClient http;

  // Your Domain name with URL path or IP address with path
  http.begin(client, serverName);

  // Send HTTP POST request
  int httpResponseCode = http.GET();

  String payload = "{}";

  if (httpResponseCode > 0) {
    //Serial.print("HTTP Response code: ");
    //Serial.println(httpResponseCode);
    payload = http.getString();
  }
  else {
    Serial.print("Error code: ");
    Serial.println(httpResponseCode);
  }
  // Free resources
  http.end();

  return payload;

}
