#define BLYNK_TEMPLATE_ID "YourTemplateID"
#define BLYNK_DEVICE_NAME "Fire Alarm"
#define BLYNK_AUTH_TOKEN "YourAuthToken"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// Replace with your Wi-Fi credentials
char ssid[] = "YourWiFiSSID";
char pass[] = "YourWiFiPassword";

const int flameSensorPin = 14;  // GPIO pin connected to flame sensor

void setup() {
  Serial.begin(115200);
  pinMode(flameSensorPin, INPUT);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop() {
  Blynk.run();

  int sensorValue = digitalRead(flameSensorPin);
  if (sensorValue == LOW) {  // LOW means flame detected for most sensors
    Serial.println("Fire detected!");
    Blynk.logEvent("fire_alert", "Fire detected! Take immediate action.");
    delay(10000);  // Avoid spamming notifications
  }
}
