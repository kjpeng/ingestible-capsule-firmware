# ADXL343
Creates an STM32 library for use with the ADXL343 (accelerometer) based
heavily off of @Amin98Hosseini's [ADXL345_STM32](https://github.com/Amin98Hosseini/ADXL345_STM32) as
well as [Adafruit_ADXL345](https://github.com/adafruit/Adafruit_ADXL345).

**Note:** This uses the ADXL343 with ALT ADDRESS pin (12) pulled to ground,
making the address 0x53. If pulled up, the address should be adjusted to
become 0x1D instead.
