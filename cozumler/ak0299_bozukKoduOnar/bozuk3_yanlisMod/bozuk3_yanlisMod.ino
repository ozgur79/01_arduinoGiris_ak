/*
  ak0299 bozuk 3/3 — çözüm

  HATA: `pinMode(ledPin, INPUT);` — LED'in pini OKUMA görevi almış, YAZMA görevi değil.
    Kod mantığı doğru, digitalWrite satırlarına kart ulaşıyor; ama pin çıkış olmadığı
    için LED çok soluk yanıyor ya da hiç yanmıyor. (Ne kadar soluk yandığı karta ve
    LED'e göre değişir, kartta bakılır.)

  TEŞHİS: if'in İÇİNE, digitalWrite'ın hemen yanına Serial.println("yakiyorum");
    koy. Butona basınca ekranda "yakiyorum" yazıyor ama LED yanmıyor: kart emri
    veriyor, LED dinlemiyor. Buton ve karar doğru, sorun pinin görevinde — setup()'a bak.

  DÜZELTME: INPUT yerine OUTPUT yaz.
*/

const int butonPin = 2;
const int ledPin = 6;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT); // ← OUTPUT
  pinMode(butonPin, INPUT);
}

void loop() {
  if (digitalRead(butonPin) == HIGH) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
}
