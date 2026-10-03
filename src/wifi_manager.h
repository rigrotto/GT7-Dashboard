#pragma once

class WiFiManager {
public:
    void begin();
    void update();

    bool isConnected() const;
};