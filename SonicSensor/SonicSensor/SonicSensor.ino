#define TRIG_PIN 9
#define ECHO_PIN 10

void setup() {
  Serial.begin(9600);             // Start the Serial Monitor
  pinMode(TRIG_PIN, OUTPUT);      // TRIG is an output
  pinMode(ECHO_PIN, INPUT);       // ECHO is an input
}

void loop() {
  long duration;
  float distance;

  // Clear the trigger pin
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  // Send 10µs pulse to trigger
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Read echo duration (time for sound to return)
  duration = pulseIn(ECHO_PIN, HIGH);

  // Calculate distance in cm
  distance = duration * 0.034 / 2;

  // Print distance
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(300); // wait a bit before next read
}