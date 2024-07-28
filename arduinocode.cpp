## Arduino Code

##The Arduino code manages the sensor readings, controls the buzzer and LEDs based on water levels, and displays the information on the LCD screen. 


#include <LiquidCrystal.h>

LiquidCrystal lcd(1, 2, 4, 5, 6, 7); 
const int trigPin = 9;
const int echoPin = 10;
long duration;
int distanceCm;
int PowerPin = 3;

void setup() {
  lcd.begin(16, 2); 
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(PowerPin, OUTPUT);       
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distanceCm = duration * 0.034 / 2;
  
  if (distanceCm < 70) {
    digitalWrite(PowerPin, HIGH);
  } else {
    digitalWrite(PowerPin, LOW);
  }
  
  lcd.setCursor(0, 0);
  lcd.print("Distance: ");
  lcd.print(distanceCm);
  lcd.print(" cm");
  delay(10);
  
  lcd.setCursor(0, 1);
  lcd.print("Tank Val: ");
  if (distanceCm < 100) {
    lcd.print("Full");
  } else if (distanceCm >= 100 && distanceCm < 200) {
    lcd.print("Low");
  } else {
    lcd.print("Empty");
  }
  delay(10);
}

