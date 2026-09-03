/*
  ak0020 — çözüm örneği
  SEN YAP 2): LED pin 8 yerine pin 9'a taşındı. Kabloyu taşımak yetmez — koddaki
  pin numarası iki yerde birden değişmeli: pinMode() ve digitalWrite() satırlarında.
  (1. madde fiziksel bir gözlem, kod değişikliği gerektirmiyor.)
*/

void setup() {
  pinMode(9, OUTPUT);
}

void loop() {
  digitalWrite(9, HIGH);
  delay(1000);
  digitalWrite(9, LOW);
  delay(1000);
}
