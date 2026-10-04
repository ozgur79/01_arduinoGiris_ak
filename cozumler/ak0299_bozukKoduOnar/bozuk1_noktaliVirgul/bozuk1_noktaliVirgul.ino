/*
  ak0299 bozuk 1/3 — çözüm

  HATA: `if (digitalRead(butonPin) == HIGH);` — satır sonundaki ; "if'in gövdesi
    BOŞ" demek. Kart if'e bakar, doğru ya da yanlış, boş gövdeyi çalıştırır; hemen
    arkasındaki { } bloğu artık if'e ait DEĞİL, her turda kayıtsız şartsız çalışır.
    Sonuç: buton fark etmeksizin LED 2 saniye yanar, çok kısa söner, tekrar yanar.

  TEŞHİS: Serial.println(digitalRead(butonPin)); koyunca buton basılı değilken ekranda
    0 görünür ama LED yine de yanıp sönüyor. Yani buton DOĞRU okunuyor; kararı
    veren satır yanlış. if satırının SONUNA bak.

  DÜZELTME: noktalı virgülü sil.
*/

const int butonPin = 2;
const int ledPin = 6;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(butonPin, INPUT);
}

void loop() {
  if (digitalRead(butonPin) == HIGH) { // ← noktalı virgül yok
    digitalWrite(ledPin, HIGH);
    delay(2000);
    digitalWrite(ledPin, LOW);
  }
}
