#include <Arduino.h>
#include <WiFi.h>

#include "wifi_manager.h"
#include "secrets.h"

void WiFiManager::begin() {
    WiFi.mode(WIFI_STA);

    Serial.print("Connecting to Wi-Fi: ");
    Serial.println(WIFI_SSID);

    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
}

void WiFiManager::update() {
    if (WiFi.status() == WL_CONNECTED) {
        return;
    }
}

bool WiFiManager::isConnected() const {
    return WiFi.status() == WL_CONNECTED;
}