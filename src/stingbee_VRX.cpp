#include "stingbee_VRX.h"
#include "logging.h"
#include "crc.h"
#include "crsf_protocol.h"
#include <Arduino.h>

GENERIC_CRC8 crsf_crc(CRSF_CRC_POLY);

void StingBee::Init()
{
    ModuleBase::Init();
    m_delay = 0;
    DBGLN("Stingbee backpack init complete");
}

void StingBee::SendIndexCmd(uint8_t index)
{  

}

void StingBee::SendLinkTelemetry(uint8_t *rawCrsfPacket)
{

}

void StingBee::SendBatteryTelemetry(uint8_t *rawCrsfPacket)
{

}


void StingBee::SendRawMsp(uint8_t *rawMspPacket, uint8_t len)
{
    if (!rawMspPacket)
    {
        DBGVLN("SendRawMsp: rawMspPacket is NULL");
        return;
    } 
    else 
    {
        for (uint8_t i = 0; i < len; i++)
        {
            Serial.write(rawMspPacket[i]);
        }
    }    
}

void StingBee::Loop(uint32_t now)
{
    MSPModuleBase::Loop(now);
}