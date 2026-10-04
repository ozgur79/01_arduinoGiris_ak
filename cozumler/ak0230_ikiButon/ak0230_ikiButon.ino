/*
  ak0230 — çözüm örneği

  SEN YAP 1) Tablo (basılı = 1):
      B1 B2 | LED
       0  0 | söner
       1  0 | söner
       0  1 | söner
       1  1 | YANAR
    && yalnız ikisi de doğruyken doğrudur.

  SEN YAP 2) || ile tablo:
      B1 B2 | LED
       0  0 | söner
       1  0 | YANAR
       0  1 | YANAR
       1  1 | YANAR
    || en az biri doğruysa doğrudur. Aşağıdaki kodda && yerine || var.

  SEN YAP 3) Direnci sökülen buton pini havada kalır; okuma kartına göre zıplayabilir.
    && ile bu yüzden LED, öbür butona basılıyken ara sıra kendiliğinden yanıp
    sönebilir ("kesin şu olur" denemez, kartta bakılır). Sebep ak0210'daki gibi:
    pin ne HIGH'a ne LOW'a bağlı.
*/

const int buton1Pin = 2;
const int buton2Pin = 8;
const int ledPin = 6;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buton1Pin, INPUT);
  pinMode(buton2Pin, INPUT);
}

void loop() {
  // SEN YAP 2: && yerine || (iki kapı zili)
  if (digitalRead(buton1Pin) == HIGH || digitalRead(buton2Pin) == HIGH) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
}
