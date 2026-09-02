/*
  ak0010 — çözüm örneği
  SEN YAP 1) ve 2): delay sürelerini değiştirme örneği
*/

void setup() {
  pinMode(13, OUTPUT);
}

void loop() {
  digitalWrite(13, HIGH);
  delay(300);  // kısa yanma süresi
  digitalWrite(13, LOW);
  delay(700);  // uzun sönme süresi
}
