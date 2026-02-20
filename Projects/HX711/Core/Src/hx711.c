#include "hx711.h"
#include "stm32l4xx_hal.h"


static void delay_us(uint16_t us)
{
    __HAL_TIM_SET_COUNTER(&htim6, 0);
    while (__HAL_TIM_GET_COUNTER(&htim6) < us);
}

void HX711_Init(HX711_HandleTypeDef *hx)
{
    hx->offset = (455300 + 700);	// vaut zero avant calibration
    hx->scale = 240.0f;			// vaut 1 avant calibration
}

long HX711_ReadRaw(HX711_HandleTypeDef *hx)
{
    long value = 0;

    while(HAL_GPIO_ReadPin(hx->dt_port, hx->dt_pin));

    for(int i = 0; i < 24; i++)
    {	delay_us(1);
        HAL_GPIO_WritePin(hx->sck_port, hx->sck_pin, GPIO_PIN_SET);
        value = value << 1;
        delay_us(1);
        HAL_GPIO_WritePin(hx->sck_port, hx->sck_pin, GPIO_PIN_RESET);

        if(HAL_GPIO_ReadPin(hx->dt_port, hx->dt_pin))
            value++;
    }

    // Gain 128
    HAL_GPIO_WritePin(hx->sck_port, hx->sck_pin, GPIO_PIN_SET);
    delay_us(1);
    HAL_GPIO_WritePin(hx->sck_port, hx->sck_pin, GPIO_PIN_RESET);
    delay_us(1);


    // Sign extend 24-bit
    if(value & 0x800000)
        value |= 0xFF000000;

    return value;
}

float HX711_GetWeight(HX711_HandleTypeDef *hx)
{
    long raw = HX711_ReadRaw(hx);
    return (raw - hx->offset) / hx->scale;
}
