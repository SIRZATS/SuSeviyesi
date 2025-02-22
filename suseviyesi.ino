int motorPin = 9; // Motorun bağlandığı pin
int sensorPin = A0; // Su seviyesi sensörünün bağlandığı analog pin
int threshold = 500; // Su seviyesi için eşik değeri (örnek değer)

void setup() {
  pinMode(motorPin, OUTPUT); // Motor pinini çıkış olarak ayarla
  pinMode(sensorPin, INPUT); // Sensör pinini giriş olarak ayarla
  Serial.begin(9600); // Seri haberleşmeyi başlat
}

void loop() {
  int sensorValue = analogRead(sensorPin); // Sensör değerini oku
  Serial.println(sensorValue); // Seri monitöre sensör değerini yazdır
  
  if (sensorValue < threshold) {
    // Su seviyesi düşükse motoru 3 dakika çalıştır, 1 dakika durdur
    digitalWrite(motorPin, HIGH); // Motoru çalıştır
    delay(1500); // 3 dakika bekle (180,000 ms)
    
    digitalWrite(motorPin, LOW); // Motoru durdur
    delay(750); // 1 dakika bekle (60,000 ms)
  } else {
    // Su seviyesi yeterliyse motoru durdur
    digitalWrite(motorPin, LOW);
    delay(1000); // Su seviyesi kontrolünü sık sık yap
  }
}
