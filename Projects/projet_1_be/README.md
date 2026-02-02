# Blink LED – STM32 Nucleo-L476RG

## 📌 Description
Ce projet est un **premier programme de prise en main STM32**.  
Il consiste à faire **clignoter la LED utilisateur (LD2)** de la carte **Nucleo-L476RG** avec des temporisations différentes, en utilisant la **bibliothèque HAL**.

Le projet permet de comprendre :
- la configuration basique d’un projet STM32
- l’utilisation des GPIO
- l’utilisation des temporisations avec `HAL_Delay()`

---

## 🧠 Fonctionnement
Dans la boucle principale (`while(1)`), la LED LD2 :
1. s’allume pendant **500 ms**
2. s’éteint pendant **200 ms**
3. le cycle se répète indéfiniment

---

## 🔌 Matériel utilisé
- Carte : **STM32 Nucleo-L476RG**
- LED : **LD2 (LED utilisateur intégrée)**

📍 LD2 est connectée à la broche **PA5**.

---

## 🧩 Périphériques STM32 utilisés
- **GPIO**
  - Mode : Output Push-Pull
- **SysTick**
  - Utilisé par `HAL_Delay()` pour la temporisation

---

## 🛠️ Logiciel
- IDE : **STM32CubeIDE**
- Bibliothèque : **HAL**
- Génération du code : **STM32CubeMX intégré**

---

## 📄 Extrait de code principal
```c
while (1)
{
    HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET);
    HAL_Delay(500);   // LED ON pendant 500 ms

    HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);
    HAL_Delay(200);   // LED OFF pendant 200 ms
}
