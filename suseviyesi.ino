int motorPin = 9; 
int sensorPin = A0; 
int threshold = 500; 

void setup() {
  pinMode(motorPin, OUTPUT); 
  pinMode(sensorPin, INPUT); 
  Serial.begin(9600); 
}

void loop() {
  int sensorValue = analogRead(sensorPin); 
  Serial.println(sensorValue); 
  
  if (sensorValue < threshold) {
    digitalWrite(motorPin, HIGH); 
    delay(1500); 
    
    digitalWrite(motorPin, LOW); 
    delay(750); 
  } else {
    digitalWrite(motorPin, LOW);
    delay(1000); 
  }
}
