/*
  ak0299 bozuk 2/3 — çözüm

  HATA: `if (butonDurum = HIGH)` — tek eşittir KARŞILAŞTIRMA değil ATAMADIR:
    butonDurum'a HIGH'ı yazar ve sonuç olarak HIGH (doğru) verir. Kart butonun gerçekte
    ne olduğuna hiç bakmıyor, if hep doğru. Sonuç: LED hep yanık.

  TEŞHİS: if'ten ÖNCE ve SONRA ikisini yazdır:
      Serial.println(digitalRead(butonPin)); // gerçek buton
      Serial.println(butonDurum);            // değişkenin değeri
    Buton basılı değilken ilki 0, ikincisi (if'ten sonra) 1 görünür — if'in içinde
    bir yerde butonDurum değişmiş. Değişkeni değiştiren tek şey o satır.

  DÜZELTME: = yerine == yaz.
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

  if (butonDurum == HIGH) { // ← iki eşittir
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
}
