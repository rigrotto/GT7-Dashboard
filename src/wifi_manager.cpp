#include <Arduino.h>
#include <WiFi.h>

#include "wifi_manager.h"

void WiFiManager::begin() {
    WiFi.mode(WIFI_STA);
}

void WiFiManager::update() {
    // Wi-Fi connection handling will go here later.
}

bool WiFiManager::isConnected() const {
    return WiFi.status() == WL_CONNECTED;
}