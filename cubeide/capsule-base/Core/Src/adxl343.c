#include "adxl343.h"

int ADXL343_Write(uint8_t reg, uint8_t val) {
  uint8_t buf[2] = {reg, val};
  if (HAL_I2C_Master_Transmit(&adxl_handle,
                              ADXL_ADDR << 1,
                              buf,
                              2,
                              HAL_MAX_DELAY) != HAL_OK) {
    return -1;
  }
  return 0;
}

int ADXL343_Read(uint8_t reg, uint8_t *buf, uint16_t buf_size) {
  if (HAL_I2C_Mem_Read(&adxl_handle,
                       ADXL_ADDR << 1,
                       reg,
                       I2C_MEMADD_SIZE_8BIT,
                       buf,
                       buf_size,
                       HAL_MAX_DELAY) != HAL_OK) {
    return -1;
  }
  return 0;
}

int ADXL343_Init(void) {
  uint8_t adxl_chipid;

  ADXL343_Read(ADXL343_REG_DEVID, &adxl_chipid, 1);
  if (adxl_chipid != 0xE5) {
    return -1;
  }

  ADXL343_Write(ADXL343_REG_POWER_CTL, 0x08); // enable measurements
  ADXL343_Write(ADXL343_REG_DATA_FORMAT, 0x08); // data_format range +- 4g
  return 0;
}

float ADXL343_ReadX(void) {
  uint8_t buf[2];
  HAL_I2C_Mem_Read(&adxl_handle,
                   ADXL_ADDR << 1,
                   ADXL343_REG_DATAX0,
                   I2C_MEMADD_SIZE_8BIT,
                   buf,
                   2,
                   HAL_MAX_DELAY);
  int16_t x;
  x = buf[1] << 8 | buf[0];
  float xf = x * ADXL343_MG2G_MULTIPLIER * SENSORS_GRAVITY_STANDARD;
  return xf;
}

float ADXL343_ReadY(void) {
  uint8_t buf[2];
  HAL_I2C_Mem_Read(&adxl_handle,
                   ADXL_ADDR << 1,
                   ADXL343_REG_DATAY0,
                   I2C_MEMADD_SIZE_8BIT,
                   buf,
                   2,
                   HAL_MAX_DELAY);
  int16_t y;
  y = buf[1] << 8 | buf[0];
  float yf = y * ADXL343_MG2G_MULTIPLIER * SENSORS_GRAVITY_STANDARD;
  return yf;
}

float ADXL343_ReadZ(void) {
  uint8_t buf[2];
  HAL_I2C_Mem_Read(&adxl_handle,
                   ADXL_ADDR << 1,
                   ADXL343_REG_DATAZ0,
                   I2C_MEMADD_SIZE_8BIT,
                   buf,
                   2,
                   HAL_MAX_DELAY);
  int16_t z;
  z = buf[1] << 8 | buf[0];
  float zf = z * ADXL343_MG2G_MULTIPLIER * SENSORS_GRAVITY_STANDARD;
  return zf;
}
