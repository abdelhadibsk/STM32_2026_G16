#include "dht11.h"
#include "stm32l4xx_hal.h"

extern TIM_HandleTypeDef htim6;

/* ===== Fonctions utilitaires ===== */
static void delay_us(uint16_t us)
{
    __HAL_TIM_SET_COUNTER(&htim6, 0);
    while (__HAL_TIM_GET_COUNTER(&htim6) < us);
}

static uint8_t DHT11_WaitForPin(GPIO_PinState state, uint16_t timeout_us)
{
    uint16_t time = 0;
    while (HAL_GPIO_ReadPin(DHT11_PORT, DHT11_PIN) != state)
    {
        delay_us(1);
        if (++time >= timeout_us)
            return 0; // timeout
    }
    return 1;
}

/* ===== Start signal ===== */
static void DHT11_Start(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    // Sortie
    GPIO_InitStruct.Pin = DHT11_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(DHT11_PORT, &GPIO_InitStruct);


    HAL_GPIO_WritePin(DHT11_PORT, DHT11_PIN, GPIO_PIN_RESET);
    HAL_Delay(20);               // ≥ 18 ms

    HAL_GPIO_WritePin(DHT11_PORT, DHT11_PIN, GPIO_PIN_SET);
    delay_us(30);                // 20–40 µs

    // Entrée
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    HAL_GPIO_Init(DHT11_PORT, &GPIO_InitStruct);
}

/* ===== Lecture d’un octet ===== */
static uint8_t DHT11_ReadByte(void)
{
    uint8_t i, byte = 0;

    for (i = 0; i < 8; i++)
    {
        if (!DHT11_WaitForPin(GPIO_PIN_RESET, 100)) return 0; 	// attendre que ça passe à l'état 0
        if (!DHT11_WaitForPin(GPIO_PIN_SET,   100)) return 0;	// attendre que ça passe à l'état 1

        delay_us(40);		// attendre 40 us pour

        if (HAL_GPIO_ReadPin(DHT11_PORT, DHT11_PIN) == GPIO_PIN_SET)
            byte |= (1 << (7 - i));

        if (!DHT11_WaitForPin(GPIO_PIN_RESET, 100)) return 0;
    }

    return byte;
}

/* ===== Lecture complète ===== */
uint8_t DHT11_Read(uint8_t *temperature, uint8_t *humidity)
{
    uint8_t hum_int, hum_dec, temp_int, temp_dec, checksum;

    DHT11_Start();

    if (!DHT11_WaitForPin(GPIO_PIN_RESET, 100)) return 0;
    if (!DHT11_WaitForPin(GPIO_PIN_SET,   100)) return 0;
    if (!DHT11_WaitForPin(GPIO_PIN_RESET, 100)) return 0;

    hum_int  = DHT11_ReadByte();
    hum_dec  = DHT11_ReadByte();
    temp_int = DHT11_ReadByte();
    temp_dec = DHT11_ReadByte();
    checksum = DHT11_ReadByte();

    if (checksum == (hum_int + hum_dec + temp_int + temp_dec))
    {
        *temperature = temp_int;
        *humidity    = hum_int;
        return 1;
    }

    return 0;
}
