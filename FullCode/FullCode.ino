// Smart Cane: Distance-Based Vibration & Serial Output

const int trigPin = 9;
const int echoPin = 10;
const int motorPin = 6;

void setup() {
  Serial.begin(9600);
  Serial.println("Smart Cane Test Starting...");

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(motorPin, OUTPUT);
}

void loop() {
  // Trigger the ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read echo and calculate distance
  long duration = pulseIn(echoPin, HIGH);
  float distance = duration * 0.0343 / 2;

  // Show distance in Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Vibration control based on distance
  if (distance > 150 || distance <= 0) {
    // Too far or invalid reading: turn off motor
    digitalWrite(motorPin, LOW);
    Serial.println("Vibration: OFF");
  } else {
    int vibrationSpeed;

    if (distance < 20) {
      vibrationSpeed = 50;  // super fast pulse
    } else if (distance < 40) {
      vibrationSpeed = 100;
    } else if (distance < 70) {
      vibrationSpeed = 200;
    } else {
      vibrationSpeed = 300; // slower pulses for farther objects
    }

    digitalWrite(motorPin, HIGH);
    delay(vibrationSpeed);
    digitalWrite(motorPin, LOW);
    delay(vibrationSpeed);

    Serial.print("Vibration Delay: ");
    Serial.print(vibrationSpeed);
    Serial.println(" ms");
  }

  delay(10000); // Small pause before next read
}