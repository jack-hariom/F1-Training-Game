# F1 Training Game: Reflex Tester  
**Arduino | Ultrasonic Sensors | I2C LCD**  
**Project by:** Hariom Sharma  

---

## Overview  
The F1 Training Game is an interactive reflex testing project built using Arduino.  
It challenges players to respond quickly when an LED lights up by covering the correct ultrasonic sensor within a short reaction window.  
Each correct action earns points, while a miss results in a penalty. The game helps improve reaction speed and hand-eye coordination.

---

## Features  
- Randomized challenge: lights one of five LEDs for the player to react to.  
- Proximity detection: detects hand placement within a defined distance (default: 10 cm).  
- Dynamic scoring: +10 points for a correct response, -5 for a missed attempt.  
- Real-time feedback: displays round number and score on a 16x2 I2C LCD.  
- Game endpoint: automatically ends after 20 rounds and shows the final score.

---

## Components Required  

| Component | Quantity | Description |
|------------|-----------|-------------|
| Arduino Uno / Nano | 1 | Main microcontroller |
| HC-SR04 Ultrasonic Sensor | 5 | For detecting hand proximity |
| Blue LEDs | 5 | Visual indicators for each sensor |
| Resistors | 5 | Current limiting resistors for LEDs |
| I2C 16x2 LCD | 1 | For score and round display |
| Jumper Wires | — | For circuit connections |
| Breadboard / PCB | 1 | For assembling the circuit |
| Power Supply | 1 | USB or 5V external supply |

---

## Wiring & Pin Configuration  

| Sensor | Trig Pin | Echo Pin | LED Pin |
|:------:|:--------:|:--------:|:-------:|
| 1 | A0 | A1 | 10 |
| 2 | 12 | 11 | 9 |
| 3 | A2 | A3 | 8 |
| 4 | 4 | 5 | 7 |
| 5 | 2 | 3 | 6 |

**LCD Connections**  
- SDA → A4 (Arduino Uno/Nano)  
- SCL → A5 (Arduino Uno/Nano)  
- VCC → 5V  
- GND → GND  

---

## How It Works  

1. **Initialization:**  
   Arduino sets up pins, initializes the LCD, and resets the score and round count.  

2. **Random Prompt:**  
   One of the five LEDs lights up randomly to signal which sensor to cover.  

3. **Player Reaction:**  
   The player must cover the corresponding ultrasonic sensor within a short window (default: 200 ms).  

4. **Distance Check:**  
   The sensor measures distance; if within 10 cm → +10 points; otherwise → -5 points.  

5. **Loop:**  
   The game continues for 20 rounds, updating the LCD with the current round and score.  

6. **Game Over:**  
   Displays the final score on the LCD after round 20.  

---

## Installation & Usage  

1. Connect all components as per the wiring table above.  
2. Install the **LiquidCrystal_I2C** library from the Arduino Library Manager.  
3. Upload the `f1_training_game.ino` sketch to your Arduino board.  
4. Play the game: when an LED lights up, quickly cover the corresponding sensor to score points.  
5. (Optional) Open the Serial Monitor at 9600 baud for debugging messages.  

---

## Customization  

| Feature | Variable | Default | Description |
|----------|-----------|----------|-------------|
| Reaction Window | `delayTime` | 200 ms | Increase to make easier, decrease for more challenge |
| Detection Distance | `threshold` | 10 cm | Adjust for sensitivity |
| Total Rounds | `totalRounds` | 20 | Change for longer or shorter gameplay |
| Expansion | — | — | Add more sensors/LEDs for advanced gameplay |
| Feedback | — | — | Add sound or vibration for enhanced feedback |

---

## Applications  
- Reflex and focus training tool  
- Educational Arduino project  
- Science fair or exhibition demonstration  
- Practice in sensor interfacing and I2C communication  

---

## License  
This project is licensed under the **MIT License** – you are free to use, modify, and distribute it with proper attribution.

---

## Author  
**Hariom Sharma**  
Email: [hariomsharma.iitm@gmail.com](mailto:hariomsharma.iitm@gmail.com)  
IIT Madras | Embedded Systems & Robotics Enthusiast  
