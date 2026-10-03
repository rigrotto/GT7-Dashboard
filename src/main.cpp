#include <Arduino.h>
#include "telemetry.h"
#include "gt7.h"
#include "wifi_manager.h"

GT7Telemetry telemetry;
GT7Receiver gt7;
WiFiManager wifiManager;

void setup() {
  Serial.begin(115200);
  gt7.begin();
  wifiManager.begin();
  delay(1000);

  Serial.println("GT7 Dashboard starting...");
}

void loop() {
  wifiManager.update();
  gt7.update();

  Serial.println("Dashboard running");

  delay(1000);
}