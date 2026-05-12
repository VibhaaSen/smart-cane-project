// Smart Cane Test using Serial Monitor instead of LCD

// Ultrasonic Sensor Pins
const int trigPin = 9;
const int echoPin = 10;

// Vibration Motor Control Pin (goes to base of transistor via resistor)
const int motorPin = 6;

void setup() {
  // Start Serial Monitor
  Serial.begin(9600);
  Serial.println("Smart Cane Test Starting...");

  // Sensor and motor pin setup
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(motorPin, OUTPUT);
}

void loop() {
  // Send trigger pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read echo time
  long duration = pulseIn(echoPin, HIGH);
  float distance = duration * 0.0343 / 2;  // Convert to cm

  // Display distance in Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Vibration logic — stronger vibration as object gets closer
  if (distance < 20) {
    Serial.println("Vibration: STRONG (Object very close)");
    digitalWrite(motorPin, HIGH);  // Constant vibration
  } else if (distance < 40) {
    Serial.println("Vibration: MEDIUM");
    digitalWrite(motorPin, HIGH);
    delay(100);
    digitalWrite(motorPin, LOW);
    delay(100);
  } else if (distance < 70) {
    Serial.println("Vibration: LIGHT");
    digitalWrite(motorPin, HIGH);
    delay(200);
    digitalWrite(motorPin, LOW);
    delay(300);
  } else {
    Serial.println("Vibration: OFF");
    digitalWrite(motorPin, LOW);
  }

  delay(200);  // Small pause before next measurement
}