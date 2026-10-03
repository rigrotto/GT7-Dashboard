#include <Arduino.h>
#include <WiFi.h>
#include <WiFiUdp.h>

#include "gt7.h"
#include "secrets.h"

static const uint16_t GT7_SEND_PORT = 33739;
static const uint16_t GT7_RECEIVE_PORT = 33740;
static IPAddress ps5Address;

void GT7Receiver::begin() {
    telemetry.connected = false;

    if (!ps5Address.fromString(PS5_IP)) {
    Serial.println("ERROR: Invalid PS5 IP address");
    return;
}

    udp.begin(GT7_RECEIVE_PORT);

    Serial.print("GT7 receiver listening on UDP port ");
    Serial.println(GT7_RECEIVE_PORT);
}

void GT7Receiver::update() {
    if (WiFi.status() != WL_CONNECTED) {
        telemetry.connected = false;
        return;
    }

    unsigned long now = millis();

    if (now - lastHeartbeat >= 1000) {
        sendHeartbeat();
        lastHeartbeat = now;
    }

    int packetSize = udp.parsePacket();

    if (packetSize > 0) {
        Serial.print("GT7 UDP packet received: ");
        Serial.print(packetSize);
        Serial.println(" bytes");
    }

}

const GT7Telemetry& GT7Receiver::getTelemetry() const {
    return telemetry;
}

void GT7Receiver::sendHeartbeat() {
    const uint8_t heartbeat = 'A';

    udp.beginPacket(ps5Address, GT7_SEND_PORT);
    udp.write(&heartbeat, 1);
    udp.endPacket();
}