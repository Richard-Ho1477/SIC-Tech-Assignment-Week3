#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "";
const char* password = "";
const char* serverUrl = "";

float temp;

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }

  Serial.println("Connected to WiFi!");
}

void loop() {
  temp = readTemp();
  sendToServer(temp);

  delay(10000);
}

float readTemp() {
  return 
}

void sendToServer(float temp) {
  HTTPClient http;

  http.begin(serverUrl);
  http.addHeader("Content-Type", "application/json");

  String jsonData = "{\"temperature\": " + String(temp) + "}";
  
  int httpResponseCode = http.POST(jsonData);

  if (httpResponseCode > 0) {
    String response = http.getString();
    Serial.println("Response: " + response);
  } else {
    Serial.println("Error sending POST request!");
  }

  http.end();
}
