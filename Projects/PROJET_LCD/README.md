# I2C LCD Display – STM32 Nucleo-L476RG

## 📌 Description
Ce projet met en œuvre une **communication I2C** entre la carte **STM32 Nucleo-L476RG** et un **afficheur LCD avec rétroéclairage RGB**.

L’application initialise le bus I2C, configure l’écran LCD, puis affiche des chaînes de caractères sur deux lignes avec un **réglage dynamique de la couleur du rétroéclairage**.

---

## 🧠 Fonctionnement
- Initialisation des périphériques :
  - GPIO
  - UART2 (debug)
  - I2C1
- Initialisation de l’écran LCD via `lcd_init()`
- Affichage de textes sur le LCD :
  - Ligne 0 : `"Coucou"`
  - Ligne 1 : `"Alex"`
- Réglage de la couleur du rétroéclairage RGB

---

## 🔌 Matériel utilisé
- Carte : STM32 Nucleo-L476RG
- Module LCD I2C avec rétroéclairage RGB
- Interface de communication : I2C

---

## 🧩 Périphériques STM32 utilisés
- **I2C1**
- **GPIO**
- **USART2** (optionnel, debug)

---

## 🔗 Interface I2C
| Signal | Broche STM32 |
|------|-------------|
| SDA | PB9 |
| SCL | PB8 |

*(Configuration par défaut Nucleo-L476RG)*

---

## 🛠️ Logiciel
- IDE : STM32CubeIDE
- Bibliothèque : HAL
- Génération du code : STM32CubeMX

---

## 📄 Extrait de code principal
```c
lcd_init(&hi2c1, &lcd);

lcd_position(&hi2c1, 0, 0);
lcd_print(&hi2c1, "Coucou");

lcd_position(&hi2c1, 0, 1);
lcd_print(&hi2c1, "Alex");

reglagecouleur(255, 0, 0);
```

---


## How to build
- Open with STM32CubeIDE
- Build & Flash

## Report
See detailed report in docs/reports/.

