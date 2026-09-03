/*
  ak0020 — çözüm örneği
  SEN YAP 2): delay sürelerini değiştirme örneği (1. madde fiziksel bir gözlem, kod
  değişikliği gerektirmiyor)
*/

void setup() {
  pinMode(8, OUTPUT);
}

void loop() {
  digitalWrite(8, HIGH);
  delay(300);  // kısa yanma süresi
  digitalWrite(8, LOW);
  delay(700);  // uzun sönme süresi
}
