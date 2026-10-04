/*
  BU KOD NE YAPAR?
  Bu kod, 2 numaralı pindeki butona basılınca 6 numaralı pindeki LED'i 2 saniye yakmak İÇİN yazıldı
  ama istenen gibi çalışmıyor. Görevin: nedenini bul ve düzelt.
*/

/*
  ak0299 — Bozuk kod 1/3: if'in sonunda noktalı virgül
  Bu dosya ak0299 "Bozuk kodu onar" dersinin BİRİNCİ parçası. Görev, yöntem ve
  ipuçları ana klasördeki ders.md'de — burada sadece bozuk kod var.

  Beklenen: butona basınca LED 2 saniye yansın, sönsün (ak0240 ile aynı iş).
  Devre: ak0210'un devresi (pin 2'de buton, pin 6'da LED) — dokunma, aynen kullanılır.
*/

const int butonPin = 2;
const int ledPin = 6;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(butonPin, INPUT);
}

void loop() {
  if (digitalRead(butonPin) == HIGH);
  {
    digitalWrite(ledPin, HIGH);
    delay(2000);
    digitalWrite(ledPin, LOW);
  }
}
