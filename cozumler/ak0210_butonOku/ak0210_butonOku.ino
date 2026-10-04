/*
  ak0210 — çözüm örneği

  SEN YAP 1) Deney adımı, kalıcı kod değişikliği yok (aşağıda deney kodu ayrıca
    gösteriliyor, ana koda karışmasın diye yorum satırı olarak).

  SEN YAP 2) İkinci LED (pin 3) aynı if'in içine eklenir — iki digitalWrite yeter,
    yeni bir if gerekmez.

  SEN YAP 3) if (digitalRead(butonPin)) da çalışırdı: HIGH aslında 1'dir, if bir
    sayıyı 0 değilse "doğru" sayar. Okunurluk için == HIGH tercih edilir.
*/

const int butonPin = 2;
const int ledPin = 6;
const int ledPin2 = 3; // SEN YAP 2

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT); // SEN YAP 2
  pinMode(butonPin, INPUT);

  // SEN YAP 1 deney kodu (10 kΩ sökülüyken denenir):
  // Serial.begin(9600);
}

void loop() {
  digitalWrite(ledPin, LOW);
  digitalWrite(ledPin2, LOW); // SEN YAP 2

  if (digitalRead(butonPin) == HIGH) {
    digitalWrite(ledPin, HIGH);
    digitalWrite(ledPin2, HIGH); // SEN YAP 2
  }

  // SEN YAP 1 deney kodu:
  // Serial.println(digitalRead(butonPin));
}
