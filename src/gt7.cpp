#include "gt7.h"

void GT7Receiver::begin() {
    telemetry.connected = false;
}

void GT7Receiver::update() {
    // GT7 network receiver will go here later.
}

const GT7Telemetry& GT7Receiver::getTelemetry() const {
    return telemetry;
}