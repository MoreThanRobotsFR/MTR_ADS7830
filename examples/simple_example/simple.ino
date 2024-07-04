#include <Arduino.h>
#include <Wire.h>
#include <MTR_ADS7830.h>

#define ADS7830_ADDRESS 0x48 // I2C Address (assuming A0 and A1 are both tied to GND)

MTR_ADS7830 adc;

void setup() {
    Serial.begin(9600);
    adc.begin(); // Initialize with default SDA, SCL, and baudrate
}

void loop() {
    for (uint8_t i = 0; i < 8; i++) {
        uint8_t value = adc.readChannel(i);
        Serial.print("Channel ");
        Serial.print(i);
        Serial.print(": ");
        Serial.println(value);
    }
    delay(1000); // Wait for a second before the next read
}
