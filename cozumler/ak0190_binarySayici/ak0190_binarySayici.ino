/*
  ak0190 — çözüm örneği

  SEN YAP 1) Sayi: 5 iken 5 = 4 + 1, yani 1'ler (pin 9, en sağ) ve 4'ler (pin 5)
    basamağı açık, 2'ler (pin 6) ve 8'ler (pin 3, en sol) kapalıdır. Gözlem görevi,
    kod değişmez.

  SEN YAP 2) delay(1000) değerini değiştirmek tek satırlık bir değişiklik.

  SEN YAP 3) Geriye saymak için: sayi-- ve sıfırlanma koşulu "sayi == -1" olunca
    "sayi = 15" yapılır (else olmadan, tek if). Aşağıdaki kod bu hâlidir.
*/

const int ledSayisi = 4;
const int ledler[4] = {3, 5, 6, 9};

int sayi = 15;

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < ledSayisi; i++) {
    pinMode(ledler[i], OUTPUT);
  }
}

void loop() {
  for (int i = 0; i < ledSayisi; i++) {
    digitalWrite(ledler[i], LOW);
  }

  if ((sayi % 2) > 0) {
    digitalWrite(ledler[3], HIGH);
  }
  if ((sayi % 4) > 1) {
    digitalWrite(ledler[2], HIGH);
  }
  if ((sayi % 8) > 3) {
    digitalWrite(ledler[1], HIGH);
  }
  if ((sayi % 16) > 7) {
    digitalWrite(ledler[0], HIGH);
  }

  Serial.print("Sayi: ");
  Serial.println(sayi);

  sayi--;
  if (sayi == -1) {
    sayi = 15;
  }

  delay(1000);
}
