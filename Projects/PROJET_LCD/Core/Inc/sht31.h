#ifndef SHT31_H
#define SHT31_H

#include "stm32l4xx_hal.h"

#define SHT31_ADDR (0x44 << 1)

HAL_StatusTypeDef SHT31_Read(float *temperature, float *humidity);

#endif
