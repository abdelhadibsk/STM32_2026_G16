# HX711 + I2C LCD – STM32 Nucleo-L476RG

## 📌 Description
Ce projet met en œuvre la lecture d’une cellule de charge (Load Cell) à l’aide du **convertisseur ADC** 24 bits HX711, avec affichage du poids mesuré sur un écran LCD via I2C.

La communication avec le HX711 est réalisée via une **interface série synchrone propriétaire 2-fils**, en utilisant un pilotage manuel des GPIO pour générer le signal d’horloge (voir datasheet) et lire les données numériques du capteur.

---

## 🧠 Fonctionnement
1. Envoi du **signal de démarrage** au capteur DHT11
2. Attente de la **fin de conversion HX711** (DOUT = LOW)
3. Génération manuelle de 24 impulsions SCK
4. Lecture série des 24 bits de donnée ADC
5. Application de l’offset et du facteur de calibration
6. Conversion en valeur physique (poids)
7. Affichage du poids sur le LCD
8. Rafraîchissement périodique de la mesure

---

## 🔌 Matériel utilisé
- Carte : STM32 Nucleo-L476RG
- Capteur : Load Cell (Jauge de contrainte)
- Convertisseur : HX711 (ADC 24 bits)
- Écran : LCD I2C avec rétroéclairage RGB
- Bus I2C : affichage LCD
- GPIO : communication HX711
---

## 🔗 Connexions
### HX711
| Signal    | Broche STM32 |
| --------- | ------------ |
| DT (DOUT) | PA0          |
| SCK       | PA1          |
| VCC       | 3.3 V        |
| GND       | GND          |

---

## 🧩 Périphériques STM32 utilisés
- GPIO (entrée DT / sortie SCK)
- I2C1
- TIM6 (temporisations en µs)
- SysTick (temporisations ms)

---

## Lecture du HX711
```c
long HX711_ReadRaw(HX711_HandleTypeDef *hx);
```
- Attente de disponibilité des données
- Lecture série des 24 bits ADC
- Extension du signe sur 32 bits
- Retour de la valeur brute

## Conversion en Poids

```c
float HX711_GetWeight(HX711_HandleTypeDef *hx);
```
Le poids est calculé selon la formule $Poids = \frac{(raw - offset)}{scale}$.

## 📚 Fonctions principales
```c
void HX711_Init(HX711_HandleTypeDef *hx);
long HX711_ReadRaw(HX711_HandleTypeDef *hx);
float HX711_GetWeight(HX711_HandleTypeDef *hx);
```

## 🚀 Exécution

- Ouvrir le projet avec STM32CubeIDE
- Compiler et flasher la carte
- Le poids mesuré est affiché sur le LCD

## How to build
- Open with STM32CubeIDE
- Build & Flash


