/*
  BU KOD NE YAPAR?
  Bu kod, 2 numaralı pindeki buton basılıyken 6 numaralı pindeki LED'i yakmak, bırakınca söndürmek İÇİN
  yazıldı ama istenen gibi çalışmıyor. Görevin: nedenini bul ve düzelt.
*/

/*
  ak0299 — Bozuk kod 2/3: bir eşittir, iki eşittir
  Bu dosya ak0299 "Bozuk kodu onar" dersinin İKİNCİ parçası. Görev, yöntem ve
  ipuçları ana klasördeki ders.md'de — burada sadece bozuk kod var.

  Beklenen: butona basılıyken LED yansın, bırakınca sönsün (ak0220 ile aynı iş).
  Devre: ak0210'un devresi (pin 2'de buton, pin 6'da LED) — dokunma, aynen kullanılır.
*/

const int butonPin = 2;
const int ledPin = 6;

int butonDurum = 0;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(butonPin, INPUT);
}

void loop() {
  butonDurum = digitalRead(butonPin);

  if (butonDurum = HIGH) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
}
