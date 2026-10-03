#pragma once

#include <WiFiUdp.h>
#include "telemetry.h"

class GT7Receiver {
public:
    void begin();
    void update();

    const GT7Telemetry& getTelemetry() const;

private:
    void sendHeartbeat();

    WiFiUDP udp;
    unsigned long lastHeartbeat = 0;
    
    GT7Telemetry telemetry;
};