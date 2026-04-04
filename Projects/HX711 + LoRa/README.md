# HX711 + I2C LCD + LoRa – STM32 Nucleo-L476RG

## 📌 Description
Ce projet met en œuvre la lecture d’une cellule de charge (Load Cell) à l’aide du **convertisseur ADC 24 bits HX711**, avec affichage du poids sur un écran LCD via I2C.

Une fonctionnalité supplémentaire permet la **transmission sans fil du poids via LoRa (UART AT commands)** vers un autre microcontrôleur.

La communication avec le HX711 est réalisée via une **interface série synchrone propriétaire 2-fils**, en utilisant un pilotage manuel des GPIO.

---

## 🧠 Fonctionnement
1. Attente de la fin de conversion HX711 (DOUT = LOW)
2. Génération manuelle de 24 impulsions SCK
3. Lecture des 24 bits ADC
4. Extension du signe
5. Application offset + calibration
6. Conversion en poids
7. Affichage sur LCD I2C
8. Envoi du poids via LoRa (toutes les 2 secondes)

---

## 📡 Communication LoRa
La communication LoRa est réalisée via un module utilisant des **commandes AT en UART**.

### 🔧 Initialisation
- Passage en mode TEST (P2P)
- Configuration RF (868 MHz - Europe)

```c
void Lora_Init(void);
```
### Commandes envoyées :

- AT
- AT+MODE=TEST
- AT+TEST=RFCFG,868,7,125,12,14,ON,OFF,OFF

### 📤 Transmission

Le poids est converti en chaîne de caractères puis envoyé :
```c
void Lora_SendFloat(float value);
```

### 📥 Réception

Le module peut recevoir une trame et extraire la valeur float :
```c
float Lora_ReceiveFloat(void);
```
- Lecture UART
- Extraction entre guillemets
- Conversion avec atof()

## 🔌 Matériel utilisé
- Carte : STM32 Nucleo-L476RG
- Capteur : Load Cell (jauge de contrainte)
- Convertisseur : HX711 (ADC 24 bits)
- Écran : LCD I2C RGB
- Module LoRa E5

## 🔗 Connexions 
### HX711 
| Signal | Broche STM32 | 
| --------- | ------------ | 
| DT (DOUT) | PA0 | 
| SCK | PA1 | 
| VCC | 3.3 V | 
| GND | GND |

### LoRa 
| Signal | Broche STM32 | 
| --------- | ------------ | 
| TX | RX (USART1) |
| RX | TX (USART1) |
|VCC |	3.3V |
| GND	| GND |


## 🧩 Périphériques STM32 utilisés
- GPIO (HX711)
- I2C1 (LCD)
- USART1 (LoRa)
- TIM6 (delay µs)
- SysTick (delay ms)



## 📚 Fonctions principales
### HX711
```c
void HX711_Init(HX711_HandleTypeDef *hx);
long HX711_ReadRaw(HX711_HandleTypeDef *hx);
float HX711_GetWeight(HX711_HandleTypeDef *hx);
``` 

### LoRa
```c
void Lora_Init(void);
void Lora_SendFloat(float value);
float Lora_ReceiveFloat(void);
``` 

### ⚙️ Calibration

Le poids est calculé selon la formule $Poids = \frac{(raw - offset)}{scale}$.

Exemple :
hx.offset = 498700;
hx.scale  = 224630.0f;

## 🚀 Exécution
- Émetteur (TX)
- Lecture HX711
- Affichage LCD
- Envoi LoRa toutes les 2 secondes
- Récepteur (RX)
- Mode réception :
- Lora_SendCommand("AT+TEST=RXLRPKT\r\n");
- Lecture avec :
- float received = Lora_ReceiveFloat();
- Affichage LCD

## 🛠️ How to build
- Open with STM32CubeIDE
- Build & Flash


