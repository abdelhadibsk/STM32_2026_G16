# Button Controlled LED – STM32 Nucleo-L476RG

## 📌 Description
Ce projet montre comment **lire l’état d’un bouton poussoir** et **contrôler une LED** sur une carte **STM32 Nucleo-L476RG**.

La LED utilisateur **LD2** clignote **tant que l’utilisateur maintient le bouton B1 appuyé**.  
Lorsque le bouton est relâché, la LED cesse de clignoter et reste éteinte.

Ce projet introduit :
- la lecture d’une entrée GPIO
- la logique conditionnelle (`if / else`)
- le contrôle d’une sortie GPIO
- l’utilisation de temporisations avec `HAL_Delay()`

---

## 🧠 Fonctionnement
- **Bouton B1 appuyé** → la LED LD2 clignote
- **Bouton B1 relâché** → la LED LD2 est éteinte

Séquence de clignotement :
- LED ON pendant **1500 ms**
- LED OFF pendant **200 ms**

---

## 🔌 Matériel utilisé
- Carte : **STM32 Nucleo-L476RG**
- Bouton poussoir : **B1 (bouton utilisateur intégré)**
- LED : **LD2 (LED utilisateur intégrée)**

---

## 🧩 Périphériques STM32 utilisés
- **GPIO**
  - B1 : Input
  - LD2 : Output Push-Pull
- **SysTick**
  - Utilisé pour les temporisations via `HAL_Delay()`

---

## 🛠️ Logiciel
- IDE : **STM32CubeIDE**
- Bibliothèque : **HAL**
- Configuration via **STM32CubeMX**

---

## 📄 Extrait de code principal
```c
while (1)
{
    if (HAL_GPIO_ReadPin(B1_GPIO_Port, B1_Pin) == GPIO_PIN_SET)
    {
        HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);
    }
    else
    {
        HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
        HAL_Delay(1500);
        HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
        HAL_Delay(200);
    }
}
