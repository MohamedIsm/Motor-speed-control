const int trigPin = 2; 
const int echoPin = 3;
const int motorPin = 9; 
const int closeDistance = 200; 
const int farSpeed = 8000; 
const int closeSpeed = 2000; 

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(motorPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  long duration, distance;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = (duration / 2) / 29.1; 

  if (distance <= closeDistance) {
    analogWrite(motorPin, closeSpeed); 
  } else {
    analogWrite(motorPin, farSpeed); 
  }

  Serial.print("Distance: ");
  Serial.println(distance);

  delay(500);
}
