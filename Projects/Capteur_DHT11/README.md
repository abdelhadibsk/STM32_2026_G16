# DHT11 Temperature & Humidity + I2C LCD – STM32 Nucleo-L476RG

## 📌 Description
Ce projet met en œuvre la lecture d’un **capteur DHT11** (température et humidité) utilisant une **communication One-Wire bidirectionnelle**, avec **affichage des mesures sur un écran LCD via I2C**.

La communication avec le DHT11 est réalisée par **pilotage précis du GPIO** et des **temporisations en microsecondes**, tandis que l’affichage est assuré par un LCD I2C.

---

## 🧠 Fonctionnement
1. Envoi du **signal de démarrage** au capteur DHT11
2. Passage dynamique de la broche GPIO en **sortie puis en entrée**
3. Lecture des bits via la durée des impulsions
4. Vérification du **checksum**
5. Affichage de la température et de l’humidité sur le LCD
6. Rafraîchissement toutes les **≥ 1 seconde** (contrainte DHT11)

---

## 🔌 Matériel utilisé
- Carte : STM32 Nucleo-L476RG
- Capteur : DHT11 (Température & Humidité)
- Écran : LCD I2C avec rétroéclairage RGB
- Bus I2C : affichage LCD
- GPIO : communication One-Wire DHT11

---

## 🔗 Connexions
### DHT11
| Signal | Broche STM32 |
|------|-------------|
| DATA | GPIO (ex: PA1) |
| VCC | 3.3 V |
| GND | GND |

### I2C LCD
| Signal | Broche STM32 |
|------|-------------|
| SDA | PB9 |
| SCL | PB8 |

---

## 🧩 Périphériques STM32 utilisés
- GPIO (mode Input / Output dynamique)
- I2C1
- TIM6 (temporisations en µs)
- SysTick (temporisations ms)

---

## ⏱️ Gestion du timing
- Temporisations en **microsecondes** via `TIM6`
- Temporisations en **millisecondes** via `HAL_Delay()`
- Respect strict du timing du protocole DHT11

---

## 📄 Lecture du capteur DHT11
```c
uint8_t DHT11_Read(uint8_t *temperature, uint8_t *humidity);
```

Lecture de 5 octets :

- Humidité entière
- Humidité décimale
- Température entière
- Température décimale
- Checksum
- Validation par somme des octets

## 📺 Affichage LCD

Ligne 1 : Température (°C)
Ligne 2 : Humidité (%)
Message d’erreur affiché si la lecture échoue

## 📚 Fonctions principales
uint8_t DHT11_Read(uint8_t *temperature, uint8_t *humidity);
```c
void lcd_init(I2C_HandleTypeDef* I2Cx, rgb_lcd* DataStruct);
void lcd_print(I2C_HandleTypeDef* I2Cx, char *str);
void lcd_position(I2C_HandleTypeDef* I2Cx, char col, char row);
void clearlcd(void);
```

## 🚀 Exécution

- Ouvrir le projet avec STM32CubeIDE
- Compiler et flasher la carte
- Les valeurs de température et d’humidité s’affichent sur le LCD
- En cas d’erreur, le message "DHT11 ERROR" est affiché

## How to build
- Open with STM32CubeIDE
- Build & Flash


