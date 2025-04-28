#ifndef _ADXL343_H_
#define _ADXL343_H_

#include <stdint.h>
#include "stm32g4xx_hal.h"

#define ADXL_ADDR 0x53

/*=========================================================================
    REGISTERS
    -----------------------------------------------------------------------*/
#define ADXL343_REG_DEVID (0x00)          ///< Device ID
#define ADXL343_REG_THRESH_TAP (0x1D)     ///< Tap threshold
#define ADXL343_REG_OFSX (0x1E)           ///< X-axis offset
#define ADXL343_REG_OFSY (0x1F)           ///< Y-axis offset
#define ADXL343_REG_OFSZ (0x20)           ///< Z-axis offset
#define ADXL343_REG_DUR (0x21)            ///< Tap duration
#define ADXL343_REG_LATENT (0x22)         ///< Tap latency
#define ADXL343_REG_WINDOW (0x23)         ///< Tap window
#define ADXL343_REG_THRESH_ACT (0x24)     ///< Activity threshold
#define ADXL343_REG_THRESH_INACT (0x25)   ///< Inactivity threshold
#define ADXL343_REG_TIME_INACT (0x26)     ///< Inactivity time
#define ADXL343_REG_ACT_INACT_CTL (0x27)  ///< Axis enable control for activity and inactivity detection
#define ADXL343_REG_THRESH_FF (0x28)      ///< Free-fall threshold
#define ADXL343_REG_TIME_FF (0x29)        ///< Free-fall time
#define ADXL343_REG_TAP_AXES (0x2A)       ///< Axis control for single/double tap
#define ADXL343_REG_ACT_TAP_STATUS (0x2B) ///< Source for single/double tap
#define ADXL343_REG_BW_RATE (0x2C)        ///< Data rate and power mode control
#define ADXL343_REG_POWER_CTL (0x2D)      ///< Power-saving features control
#define ADXL343_REG_INT_ENABLE (0x2E)     ///< Interrupt enable control
#define ADXL343_REG_INT_MAP (0x2F)        ///< Interrupt mapping control
#define ADXL343_REG_INT_SOURCE (0x30)     ///< Source of interrupts
#define ADXL343_REG_DATA_FORMAT (0x31)    ///< Data format control
#define ADXL343_REG_DATAX0 (0x32)         ///< X-axis data 0
#define ADXL343_REG_DATAX1 (0x33)         ///< X-axis data 1
#define ADXL343_REG_DATAY0 (0x34)         ///< Y-axis data 0
#define ADXL343_REG_DATAY1 (0x35)         ///< Y-axis data 1
#define ADXL343_REG_DATAZ0 (0x36)         ///< Z-axis data 0
#define ADXL343_REG_DATAZ1 (0x37)         ///< Z-axis data 1
#define ADXL343_REG_FIFO_CTL (0x38)       ///< FIFO control
#define ADXL343_REG_FIFO_STATUS (0x39)    ///< FIFO status
#define ADXL343_MG2G_MULTIPLIER (0.004)   ///< 4mg per lsb

#define SENSORS_GRAVITY_EARTH (9.80665F) /**< Earth's gravity in m/s^2 */
#define SENSORS_GRAVITY_MOON (1.6F)      /**< The moon's gravity in m/s^2 */
#define SENSORS_GRAVITY_SUN (275.0F)     /**< The sun's gravity in m/s^2 */
#define SENSORS_GRAVITY_STANDARD (SENSORS_GRAVITY_EARTH)

extern I2C_HandleTypeDef *adxl_handle;

int ADXL343_Write(uint8_t reg, uint8_t val);
int ADXL343_Read(uint8_t reg, uint8_t *buf, uint16_t buf_size);

int ADXL343_Init(void);
float ADXL343_ReadX(void);
float ADXL343_ReadY(void);
float ADXL343_ReadZ(void);

#endif
