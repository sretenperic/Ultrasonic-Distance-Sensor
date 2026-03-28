const int trigPin = 9;
const int echoPin = 10;
const int ledPin = 13; 
const int buzzerPin = 8;

const int ledThreshold = 30;   // LED uključi ako je udaljenost manja od 30 cm
const int buzzerThreshold = 15; // Buzzer uključi ako je udaljenost manja od 15 cm

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  
  Serial.begin(9600); 
}

void loop() {
  long duration;
  int distance;
  
  // Send trig pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  
  // Calculate distance in cm
  distance = duration * 0.034 / 2;
  
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if(distance < ledThreshold) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
  
  if(distance < buzzerThreshold) {
    tone(buzzerPin, 1000); // 1 kHz tone
  } else {
    noTone(buzzerPin);
  }

  delay(100); // small delay to stabilize readings
}
