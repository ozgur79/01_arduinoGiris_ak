/*
  ak0250 — çözüm örneği

  Bu dersin SEN YAP soruları KARTTA GÖZLEM ister. Aşağıdakiler yalnız kod okumaya
  dayanır; kartta doğrulanmadı.

  SEN YAP 1) Kod okunarak: while (digitalRead(yakPin) == HIGH) { } buton basılı
    olduğu sürece döner. LED'i yakan digitalWrite bu döngüden SONRA gelir, yani LED
    basılınca değil, BIRAKILINCA yanmalı. Kartta bakılır.

  SEN YAP 2) delay(100) silinince fark görünüp görünmeyeceği butona ve basışa göre
    değişir. "Bu denemede görmedim" doğru bir cevaptır.

  SEN YAP 3) Kod okunarak: YAK bloğu önce kontrol edilir ve içindeki while YAK
    bırakılana kadar döner; SÖNDÜR bloğuna ancak YAK bırakılınca sıra gelir. LED'in
    son durumu hangi sırayla bırakıldığına göre kartta gözlenir.
*/

const int yakPin = 2;
const int sondurPin = 8;
const int ledPin = 6;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(yakPin, INPUT);
  pinMode(sondurPin, INPUT);
}

void loop() {
  if (digitalRead(yakPin) == HIGH) {
    while (digitalRead(yakPin) == HIGH) { }
    // delay(100); // SEN YAP 2: bu satırı sil/geri koy ve dene
    digitalWrite(ledPin, HIGH);
  }

  if (digitalRead(sondurPin) == HIGH) {
    while (digitalRead(sondurPin) == HIGH) { }
    // delay(100);
    digitalWrite(ledPin, LOW);
  }
}
