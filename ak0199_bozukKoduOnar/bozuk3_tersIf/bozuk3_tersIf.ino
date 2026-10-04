/*
  ak0199 — Bozuk kod 3/3: ters if (binary sayıcı)
  Bu dosya ak0199 "Bozuk kodu onar" dersinin ÜÇÜNCÜ parçası. Görev, yöntem ve
  ipuçları ana klasördeki ders.md'de — burada sadece bozuk kod var.

  Devre: Paket 5 (4 LED, pin 3/5/6/9, ortak GND hattı) — dokunma, aynen kullanılır.
*/

const int ledSayisi = 4;
const int ledler[4] = {3, 5, 6, 9}; // 3=8'ler, 5=4'ler, 6=2'ler, 9=1'ler basamağı

int sayi = 0;

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
  if ((sayi % 4) < 1) {
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

  sayi++;
  if (sayi == 16) {
    sayi = 0;
  }

  delay(1000);
}
