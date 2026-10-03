#pragma once

#include "telemetry.h"

class GT7Receiver {
public:
    void begin();
    void update();

    const GT7Telemetry& getTelemetry() const;

private:
    GT7Telemetry telemetry;
};