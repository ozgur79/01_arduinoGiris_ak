/*
  BU KOD NE YAPAR?
  Bu kod, 3, 5, 6, 9 numaralı pinlerdeki 4 LED'i sırayla yakıp söndürmek İÇİN yazıldı
  ama istenen gibi çalışmıyor. Görevin: nedenini bul ve düzelt.
*/

/*
  ak0199 — Bozuk kod 2/3: artmayan sayaç
  Bu dosya ak0199 "Bozuk kodu onar" dersinin İKİNCİ parçası. Görev, yöntem ve
  ipuçları ana klasördeki ders.md'de — burada sadece bozuk kod var.

  Devre: Paket 5 (4 LED, pin 3/5/6/9, ortak GND hattı) — dokunma, aynen kullanılır.
*/

const int ledSayisi = 4;
const int ledler[4] = {3, 5, 6, 9};

void setup() {
  for (int j = 0; j < ledSayisi; j++) {
    pinMode(ledler[j], OUTPUT);
  }
}

void loop() {
  int i = 0;
  while (i < ledSayisi) {
    digitalWrite(ledler[i], HIGH);
    delay(300);
    digitalWrite(ledler[i], LOW);
  }
}
