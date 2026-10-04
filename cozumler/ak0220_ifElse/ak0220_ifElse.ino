/*
  ak0220 — çözüm örneği

  SEN YAP 1) ak0160'ın else'li hâli (ayrı taslakta, devre gerekmez):
      if (sayac % 2 != 0) { Serial.println("TEK"); }
      else                { Serial.println("CIFT"); }
    Türkçe karakter (Ç) Seri Monitör'de bozulabildiği için ASCII yazıldı.
    Tek `if` ile yalnız tekleri yazıyorduk; else ile ÇİFTLER de bir blokta yer aldı,
    kod bir blok uzadı ama "sayı ne" sorusu artık iki yoldan birini MUTLAKA seçiyor.

  SEN YAP 2) Aşağıdaki kod: basılıyken pin 6, basılı değilken pin 9 yanar.
    Bu iki LED asla birlikte yanmaz — else'in "ya o ya bu" doğası.

  SEN YAP 3) [ileri] else { if (...) { } } mümkündür: "buton basılı değilse, ayrıca
    şuna da bak" demek. İki yönden fazla karar gerektiğinde işe yarar; kısa yazılışı
    (else if) Ünite 3'te açılacak.
*/

const int butonPin = 2;
const int ledPin = 6;
const int ledPin2 = 9; // SEN YAP 2

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(butonPin, INPUT);
}

void loop() {
  if (digitalRead(butonPin) == HIGH) {
    digitalWrite(ledPin, HIGH);
    digitalWrite(ledPin2, LOW);
  } else {
    digitalWrite(ledPin, LOW);
    digitalWrite(ledPin2, HIGH);
  }
}
