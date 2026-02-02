# External Interrupts (EXTI) – STM32 Nucleo-L476RG

## 📌 Description
Ce projet démontre l’utilisation des **interruptions externes (EXTI)** sur la carte **STM32 Nucleo-L476RG**.

La LED utilisateur **LD2** change d’état lorsque :
- le bouton poussoir **B1** est relâché
- un **front descendant** apparaît sur les broches **PA8** ou **PA9**

L’application est entièrement **pilotée par interruptions**.  
La boucle principale `while(1)` est vide.

---

## 🧠 Fonctionnement
Chaque événement sur **B1**, **PA8** ou **PA9** génère une interruption EXTI.  
La fonction `HAL_GPIO_EXTI_Callback()` est appelée et provoque le basculement de l’état de la LED **LD2**.

---

## 🔌 Matériel utilisé
- Carte : STM32 Nucleo-L476RG
- LED : LD2 (PA5)
- Bouton utilisateur : B1 (PC13)
- Entrées externes : PA8, PA9

---

## 🧩 Périphériques utilisés
- GPIO
- EXTI (interruptions externes)
- NVIC

---

## 🛠️ Configuration GPIO
| Signal | Broche | Mode | Pull |
|------|-------|------|------|
| LD2 | PA5 | Output Push-Pull | No pull |
| B1 | PC13 | EXTI Falling | pull-up |
| PA8 | PA8 | EXTI Falling | Pull-up |
| PA9 | PA9 | EXTI Falling | Pull-up |

---

## 📄 Callback d’interruption
```c
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    switch(GPIO_Pin)
    {
        case B1_Pin:
        case GPIO_PIN_8:
        case GPIO_PIN_9:
            HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
            break;
    }
}
