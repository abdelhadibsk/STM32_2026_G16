#ifndef LORA_H
#define LORA_H

#include <stdint.h>

// Init module
void Lora_Init(void);

// Send float
void Lora_SendFloat(float value);

// Receive float
float Lora_ReceiveFloat(void);

// Send raw command
void Lora_SendCommand(char *cmd);

// Receive response
void Lora_ReadResponse(char *buffer, uint16_t size);

#endif
