# STM32 Embedded Systems Projects

## 📌 Overview
Ce dépôt regroupe une collection de **projets embarqués STM32**, développés dans un cadre **académique et pratique**, avec pour objectif de maîtriser les **périphériques bas niveau**, les **protocoles de communication** et les **architectures logicielles embarquées**.

Tous les projets sont réalisés sur **STM32 Nucleo-L476RG**, en utilisant **STM32CubeIDE** et la **bibliothèque HAL**.

---

## 🎯 Objectifs du dépôt
- Apprendre et pratiquer la programmation embarquée STM32  
- Comprendre l’utilisation des périphériques (GPIO, TIM, EXTI, I2C, UART…)  
- Implémenter des protocoles de communication (I2C, One-Wire)  
- Structurer des projets embarqués propres, documentés et réutilisables  

---

## 📁 Contenu du dépôt

Ce dépôt regroupe plusieurs projets embarqués réalisés autour de la plateforme STM32.

### 📄 README (par projet)
Chaque projet contient un fichier README détaillé qui décrit :
- le fonctionnement du système  
- l’architecture du code  
- les étapes d’exécution  
- le câblage matériel  

➡️ En suivant ces README, il est possible de **comprendre rapidement le code** et de **reproduire les projets** de manière autonome.

---

### 📑 Rapports & Présentations
Des rapports détaillés et supports de présentation accompagnent les projets et présentent :
- les choix techniques réalisés  
- les solutions mises en œuvre  
- les aspects matériels (capteurs, modules, architecture)  
- les protocoles de communication utilisés  

📊 Des **slides de présentation** sont également disponibles, notamment pour le projet de **ruche connectée**, permettant une vue synthétique du système et de son fonctionnement.

---

## 🔗 Complémentarité README / Rapports

Les README et les rapports sont **complémentaires** :

- **README** → compréhension du code, mise en œuvre pratique, reproduction  
- **Rapports** → vision globale, justification des choix, aspects théoriques et matériels  

➡️ Pour chaque projet, il est recommandé de **consulter à la fois le README et le rapport associé** afin d’avoir une compréhension complète.

---

## 🧰 Environnement de développement
- **Carte** : STM32 Nucleo-L476RG  
- **Microcontrôleur** : STM32L476RG  
- **IDE** : STM32CubeIDE  
- **Bibliothèque** : HAL  
- **Génération code** : STM32CubeMX  

---

## 📂 Structure du dépôt
```text

STM32L476RG_BEprojects/
├── Projects/
│   ├── Projet1_BE
│   ├── Projet2_BE
│   ├── Projet3_BE
│   ├── Projet_LCD
│   ├── Capteur DHT11
│   ├── Capteur SHT31
│   ├── BE (ruche) HX711
├── Documents/
│   ├── datasheets/
│   ├── Signaux_communication/
│   └── Schémas de cablage/
│   └── Rapports/
│   └── Slides_Presentation/
└── README.md
```

## 📘 Liste des projets
### 🔹 1. Blink LED

- GPIO Output
- Temporisation avec HAL_Delay()
- Première prise en main STM32

### 🔹 2. Button Controlled LED

- Lecture GPIO Input
- Logique conditionnelle
- Contrôle LED par bouton poussoir

### 🔹 3. External Interrupts (EXTI)

- Interruptions externes GPIO
- NVIC
- Application événementielle (boucle while vide)

### 🔹 4. I2C LCD Display

- Communication I2C
- Pilotage écran LCD
- Affichage texte et rétroéclairage RGB

### 🔹 5. SHT31 – Température & Humidité + LCD

- Capteur environnemental numérique
- Communication I2C
- Conversion données brutes → grandeurs physiques
- Affichage LCD

### 🔹 6. DHT11 – One-Wire + LCD

- Implémentation logicielle du protocole One-Wire
- Gestion précise des timings (µs / ms)
- Capteur température & humidité
- Affichage LCD I2C


### 🔹 7. La ruche – HX711 + LoRa + LCD

- Mesure de poids via cellule de charge (HX711 – ADC 24 bits)
- Calibration (offset + facteur d’échelle)
- Affichage du poids sur écran LCD I2C
- Transmission sans fil des données via LoRa (UART – commandes AT)
- Envoi périodique du poids (toutes les 2 secondes)
- Possibilité de réception côté distant et affichage du poids