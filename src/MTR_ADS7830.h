#ifndef MTR_ADS7830_H
#define MTR_ADS7830_H

#include <Arduino.h>
#include <Wire.h>


// I2C Address (assuming A0 and A1 are both tied to GND)
#ifndef ADS7830_ADDRESS
#define ADS7830_ADDRESS 0x48
#endif

// ADS7830 Command Definitions for Single-Ended Channels
#define ADS7830_CMD_SD_SE_CH0 0x80 // Single-Ended, Channel 0
#define ADS7830_CMD_SD_SE_CH1 0xC0 // Single-Ended, Channel 1
#define ADS7830_CMD_SD_SE_CH2 0x90 // Single-Ended, Channel 2
#define ADS7830_CMD_SD_SE_CH3 0xD0 // Single-Ended, Channel 3
#define ADS7830_CMD_SD_SE_CH4 0xA0 // Single-Ended, Channel 4
#define ADS7830_CMD_SD_SE_CH5 0xE0 // Single-Ended, Channel 5
#define ADS7830_CMD_SD_SE_CH6 0xB0 // Single-Ended, Channel 6
#define ADS7830_CMD_SD_SE_CH7 0xF0 // Single-Ended, Channel 7

/**
 * @brief ADS7830 ADC driver class
 */
class MTR_ADS7830 {
public:
    /**
     * @brief Construct a new ADS7830 object
     * 
     * @param i2cAddress The I2C address of the ADS7830 (default is 0x48)
     */
    MTR_ADS7830(uint8_t i2cAddress = ADS7830_ADDRESS);

    /**
     * @brief Initialize the I2C communication and ADS7830 ADC
     * 
     * @param baudrate The I2C baudrate to use (default is 100000)
     */
    void init(uint32_t baudrate = 100000);

    /**
     * @brief Read the ADC value from a specific channel
     * 
     * @param channel The ADC channel to read (0-7)
     * @return The ADC reading (0-255)
     */
    uint8_t readChannel(uint8_t channel);

    /**
     * @brief Read ADC values from all channels and store them in an array
     * 
     * @param values Array to store the ADC readings (must be at least 8 elements)
     */
    void readAllChannels(uint8_t* values);

private:
    uint8_t _i2cAddress;
    uint32_t _baudrate;

    /**
     * @brief Write a command to the ADS7830
     * 
     * @param command The command to write
     */
    void writeCommand(uint8_t command);

    /**
     * @brief Read data from the ADS7830
     * 
     * @return The data read from the ADS7830
     */
    uint8_t readData();
};

#endif // MTR_ADS7830_H
