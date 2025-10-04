#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Initialize the LCD with I2C address 0x27 (you may need to adjust this)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Updated pin configuration for ultrasonic sensors and LEDs
const int trigPins[5] = {A0, 12, A2, 4, 2};  // Sensor 2 trigPin is now 12, Sensor 3 trigPin is A2
const int echoPins[5] = {A1, 11, A3, 5, 3};  // Sensor 2 echoPin is now 11, Sensor 3 echoPin is A3
const int ledPins[5] = {10, 9, 8, 7, 6};

int score = 0;
const int totalRounds = 20;
int currentRound = 0;
int delayTime = 200; // Initial delay (1000 ms)

// Function to initialize pins
void setupPins() {
  for (int i = 0; i < 5; i++) {
    pinMode(trigPins[i], OUTPUT);
    pinMode(echoPins[i], INPUT);
    pinMode(ledPins[i], OUTPUT);
  }
}

// Function to measure distance
long measureDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  long duration = pulseIn(echoPin, HIGH);
  long distance = (duration * 0.034) / 2; // Convert to cm
  return distance;
}

void setup() {
  // Start serial communication
  Serial.begin(9600);
  
  // Initialize LCD
  lcd.init();
  lcd.backlight();
  
  // Initialize pins
  setupPins();
  
  // Display initial message
  lcd.setCursor(0, 0);
  lcd.print("F1 Training Game");
  lcd.setCursor(0, 1);
  lcd.print("Score: 0");
  delay(2000);
  lcd.clear();
}

void loop() {
  if (currentRound < totalRounds) {
    int randomSensor = random(0, 5);
    digitalWrite(ledPins[randomSensor], HIGH);
    delay(delayTime);
    
    long distance = measureDistance(trigPins[randomSensor], echoPins[randomSensor]);
    digitalWrite(ledPins[randomSensor], LOW);
    
    if (distance < 10) { // Detected hand close enough
      score += 10;
    } else {
      score -= 5;
    }
    
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Round: ");
    lcd.print(currentRound + 1);
    lcd.setCursor(0, 1);
    lcd.print("Score: ");
    lcd.print(score);
    
    currentRound++;
    delay(500); // Small delay between rounds
  } else {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Game Over");
    lcd.setCursor(0, 1);
    lcd.print("Final Score: ");
    lcd.print(score);
    
    while (1); // Stop the loop
  }
}
