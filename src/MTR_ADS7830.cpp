#include "MTR_ADS7830.h"

ADS7830::ADS7830(uint8_t i2cAddress) : _i2cAddress(i2cAddress) {}

void ADS7830::begin(uint8_t sdaPin, uint8_t sclPin, uint32_t baudrate) {
    _sdaPin = sdaPin;
    _sclPin = sclPin;
    _baudrate = baudrate;

    Wire.begin(_sdaPin, _sclPin);
    Wire.setClock(_baudrate);
}

uint8_t ADS7830::readChannel(uint8_t channel) {
    uint8_t command;

    switch (channel) {
        case 0: command = ADS7830_CMD_SD_SE_CH0; break; // Single-Ended, Channel 0
        case 1: command = ADS7830_CMD_SD_SE_CH1; break; // Single-Ended, Channel 1
        case 2: command = ADS7830_CMD_SD_SE_CH2; break; // Single-Ended, Channel 2
        case 3: command = ADS7830_CMD_SD_SE_CH3; break; // Single-Ended, Channel 3
        case 4: command = ADS7830_CMD_SD_SE_CH4; break; // Single-Ended, Channel 4
        case 5: command = ADS7830_CMD_SD_SE_CH5; break; // Single-Ended, Channel 5
        case 6: command = ADS7830_CMD_SD_SE_CH6; break; // Single-Ended, Channel 6
        case 7: command = ADS7830_CMD_SD_SE_CH7; break; // Single-Ended, Channel 7
        default: return 0; // Invalid channel
    }

    writeCommand(command);
    return readData();
}

void ADS7830::readAllChannels(uint8_t* values) {
    for (uint8_t i = 0; i < 8; i++) {
        values[i] = readChannel(i);
    }
}

void ADS7830::writeCommand(uint8_t command) {
    Wire.beginTransmission(_i2cAddress);
    Wire.write(command);
    Wire.endTransmission();
}

uint8_t ADS7830::readData() {
    Wire.requestFrom(_i2cAddress, (uint8_t)1);
    if (Wire.available()) {
        return Wire.read();
    }
    return 0;
}
