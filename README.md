# ADS7830 Arduino Library

This is an Arduino library for interfacing with the ADS7830, an 8-channel 8-bit A/D converter with an I2C interface.

## Features

- Read ADC values from any of the 8 single-ended channels.
- Read ADC values from all channels at once.
- Simple and easy-to-use API.

## Installation

1. Download the library as a ZIP file.
2. In the Arduino IDE, go to `Sketch -> Include Library -> Add .ZIP Library...`
3. Select the downloaded ZIP file and click `Open`.

## Usage

### Include the Library

Include the `ADS7830` library in your sketch:

```cpp
#include <ADS7830.h>
```

### Create an ADS7830 Object

Create an instance of the `ADS7830` class:

```cpp
ADS7830 adc;
```

### Initialize the ADC

Initialize the I2C communication and the ADS7830 ADC in the `setup()` function:

```cpp
void setup() {
    Serial.begin(9600);
    adc.begin(); // Initialize with default SDA, SCL, and baudrate
}
```

### Read ADC Values

Read the ADC value from a specific channel:

```cpp
void loop() {
    uint8_t value = adc.readChannel(0); // Read from channel 0
    Serial.print("Channel 0: ");
    Serial.println(value);
    delay(1000); // Wait for a second before the next read
}
```

Read ADC values from all channels:

```cpp
void loop() {
    uint8_t values[8];
    adc.readAllChannels(values);

    for (uint8_t i = 0; i < 8; i++) {
        Serial.print("Channel ");
        Serial.print(i);
        Serial.print(": ");
        Serial.println(values[i]);
    }
    delay(1000); // Wait for a second before the next read
}
```

### Custom I2C Settings

You can customize the I2C SDA and SCL pins and the baudrate when initializing the ADC:

```cpp
void setup() {
    Serial.begin(9600);
    adc.begin(21, 22, 400000); // SDA = 21, SCL = 22, baudrate = 400kHz
}
```

## API Reference

### Constructor

- `ADS7830(uint8_t i2cAddress = 0x48)`
  - Creates an ADS7830 object.
  - `i2cAddress`: The I2C address of the ADS7830 (default is 0x48).

### Initialization

- `void begin(uint8_t sdaPin = 4, uint8_t sclPin = 5, uint32_t baudrate = 100000)`
  - Initializes the I2C communication and ADS7830 ADC.
  - `sdaPin`: The pin for I2C SDA (default is 4).
  - `sclPin`: The pin for I2C SCL (default is 5).
  - `baudrate`: The I2C baudrate (default is 100000).

### Reading ADC Values

- `uint8_t readChannel(uint8_t channel)`
  - Reads the ADC value from a specific channel.
  - `channel`: The ADC channel to read (0-7).
  - Returns the ADC reading (0-255).

- `void readAllChannels(uint8_t* values)`
  - Reads ADC values from all channels and stores them in an array.
  - `values`: Array to store the ADC readings (must be at least 8 elements).

## License

This library is licensed under the MIT License. See the `LICENSE` file for more details.

## Author

Created by [Your Name].

## Acknowledgments

- [ADS7830 Datasheet](/docs/ads7830.pdf)
