#include "sht31.h"
#include "i2c.h"

HAL_StatusTypeDef SHT31_Read(float *temperature, float *humidity)
{
    uint8_t cmd[2] = {0x24, 0x00};
    uint8_t data[6];

    // Envoi commande mesure
    if (HAL_I2C_Master_Transmit(&hi2c1, SHT31_ADDR, cmd, 2, 100) != HAL_OK)
        return HAL_ERROR;

    HAL_Delay(20); // temps de mesure

    // Lecture des données
    if (HAL_I2C_Master_Receive(&hi2c1, SHT31_ADDR, data, 6, 100) != HAL_OK)
        return HAL_ERROR;

    uint16_t rawTemp = (data[0] << 8) | data[1];
    uint16_t rawHum  = (data[3] << 8) | data[4];

    *temperature = -45.0f + 175.0f * ((float)rawTemp / 65535.0f);
    *humidity    = 100.0f * ((float)rawHum / 65535.0f);

    return HAL_OK;
}
