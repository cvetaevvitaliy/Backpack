#pragma once

#include "msp.h"
#include "msptypes.h"
#include "module_base.h"
#include <Arduino.h>

#define VRX_BOOT_DELAY  1000

#define VRX_UART_BAUD   115200   // fusion uses 500k baud between the ESP8266 and the STM32

#define frequencyTableSize 48


class StingBee : public MSPModuleBase
{
public:
    StingBee(Stream *port) : MSPModuleBase(port) {};
    void Init();
    void SendIndexCmd(uint8_t index);
    void SendLinkTelemetry(uint8_t *rawCrsfPacket);
    void SendBatteryTelemetry(uint8_t *rawCrsfPacket);
    void SendRawMsp(uint8_t *rawMspPacket, uint8_t len);
    void Loop(uint32_t now);

private:

    uint16_t    m_delay;
    uint32_t    m_delayStartMillis;
};
