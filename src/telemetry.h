#pragma once

struct GT7Telemetry {
    bool connected = false;

    float speedKmh = 0.0;
    float rpm = 0.0;

    int gear = 0;

    float throttle = 0.0;
    float brake = 0.0;

    float fuel = 0.0;
    float fuelCapacity = 0.0;

    int currentLap = 0;
    int totalLaps = 0;
};