#include <Arduino.h>
#include "telemetry.h"

GT7Telemetry telemetry;

void setup() {
  Serial.begin(115200);

  delay(1000);

  Serial.println("GT7 Dashboard starting...");
}

void loop() {
  Serial.println("Dashboard running");

  delay(1000);
}