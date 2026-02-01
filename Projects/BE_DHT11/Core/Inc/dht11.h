#ifndef DTH11_H
#define DTH11_H

#include "stm32l4xx_hal.h"
#include <stdint.h>

// Broche DATA du DHT11
#define DHT11_PORT GPIOA
#define DHT11_PIN  GPIO_PIN_0

// Fonctions
uint8_t DHT11_Read(uint8_t *temperature, uint8_t *humidity);

#endif
