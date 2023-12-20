//distance sensor setup
const int trigPin = 9;  
const int echoPin = 10; 
float duration, distance;

void setup() {
  pinMode(trigPin, OUTPUT);  
  pinMode(echoPin, INPUT);  
}

void Bounce() {
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2);  
  digitalWrite(trigPin, HIGH);  
  delayMicroseconds(10);  
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);  
  Serial.println(duration);
}

void loop() {
  Bounce();
  delay(500);
}
