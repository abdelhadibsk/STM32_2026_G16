#include "lora.h"

#include "usart.h"     // Pour huart2 (généré par CubeMX)
#include "gpio.h"
#include "stm32l4xx_hal.h"

#include <stdio.h>     // sprintf
#include <string.h>    // strlen, strncpy, strchr
#include <stdlib.h>    // atof

extern UART_HandleTypeDef huart1;

// =======================
// Fonctions internes UART
// =======================

void Lora_SendCommand(char *cmd)
{
    HAL_UART_Transmit(&huart1, (uint8_t*)cmd, strlen(cmd), HAL_MAX_DELAY);
}

void Lora_ReadResponse(char *buffer, uint16_t size)
{
    HAL_UART_Receive(&huart1, (uint8_t*)buffer, size, 2000);
}

// =======================
// Initialisation LoRa
// =======================

void Lora_Init(void)
{
    char cmd[100];

    // Test AT
    sprintf(cmd, "AT\r\n");
    Lora_SendCommand(cmd);
    HAL_Delay(500);

    // Mode TEST (P2P)
    sprintf(cmd, "AT+MODE=TEST\r\n");
    Lora_SendCommand(cmd);
    HAL_Delay(500);

    // Configuration RF (868 MHz Europe)
    sprintf(cmd, "AT+TEST=RFCFG,868,7,125,12,14,ON,OFF,OFF\r\n");
    Lora_SendCommand(cmd);
    HAL_Delay(500);
}

// =======================
// Envoi float
// =======================

void Lora_SendFloat(float value)
{
    char cmd[100];
    char payload[20];

    sprintf(payload, "%.2f", value);
    sprintf(cmd, "AT+TEST=TXLRSTR,\"%s\"\r\n", payload);

    Lora_SendCommand(cmd);
}

// =======================
// Réception float
// =======================

float Lora_ReceiveFloat(void)
{
    char buffer[100] = {0};

    Lora_ReadResponse(buffer, sizeof(buffer));

    char *start = strchr(buffer, '\"');
    char *end   = strrchr(buffer, '\"');

    if (start && end && start != end)
    {
        char value_str[20] = {0};
        strncpy(value_str, start + 1, end - start - 1);

        return atof(value_str);
    }

    return 0.0f;
}
