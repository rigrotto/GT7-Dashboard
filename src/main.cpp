#include <Arduino.h>
#include "telemetry.h"
#include "gt7.h"

GT7Telemetry telemetry;
GT7Receiver gt7;

void setup() {
  Serial.begin(115200);
  gt7.begin();
  delay(1000);

  Serial.println("GT7 Dashboard starting...");
}

void loop() {
  gt7.update();
  Serial.println("Dashboard running");

  delay(1000);
}