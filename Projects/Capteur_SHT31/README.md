# SHT31 Temperature & Humidity + I2C LCD – STM32 Nucleo-L476RG

## 📌 Description
Ce projet implémente la lecture d’un **capteur de température et d’humidité SHT31** via le bus **I2C**, avec **affichage des mesures sur un écran LCD I2C avec rétroéclairage RGB**.

Le microcontrôleur interroge périodiquement le capteur SHT31, convertit les données brutes en valeurs physiques, puis affiche :
- la **température en °C**
- l’**humidité relative en %**

---

## 🧠 Fonctionnement
1. Initialisation des périphériques (GPIO, I2C1, UART)
2. Vérification de la présence des périphériques I2C (LCD et SHT31)
3. Initialisation de l’écran LCD
4. Lecture périodique du capteur SHT31
5. Conversion et affichage des mesures sur le LCD
6. Gestion d’erreur si le capteur n’est pas détecté

---

## 🔌 Matériel utilisé
- Carte : STM32 Nucleo-L476RG
- Capteur : SHT31 (Température & Humidité)
- Écran : LCD I2C avec rétroéclairage RGB
- Bus de communication : I2C

---

## 🔗 Interface I2C
| Signal | Broche STM32 |
|------|-------------|
| SDA | PB9 |
| SCL | PB8 |

---

## 🧩 Périphériques STM32 utilisés
- I2C1
- GPIO
- SysTick (temporisation)

---

## 📄 Lecture du capteur SHT31
```c
HAL_StatusTypeDef SHT31_Read(float *temperature, float *humidity)
```

## How to build
- Ouvrir le projet avec STM32CubeIDE
- Compiler et flasher la carte
- Les valeurs de température et d’humidité s’affichent sur le LCD
- En cas d’erreur capteur, un message s’affiche à l’écran


