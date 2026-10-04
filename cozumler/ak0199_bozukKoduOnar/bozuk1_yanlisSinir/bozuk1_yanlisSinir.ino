/*
  ak0199 — çözüm 1/3: yanlış sınırlı for

  HATA: for (int i = 0; i < 3; i++) — 4 LED varken sınır 3 yazılmış (ledSayisi
  yerine sabit 3). ledler[3] (pin 9) döngüye hiç girmiyor, o LED hiç yanmıyor.

  NASIL BULUNDU: Şüpheli satırın (döngünün) yanına Serial.println(i); eklenip
  Seri Monitör'de en büyük i değeri gözlendi — ekranda 0, 1, 2 görülüp bir daha
  hiç 3 görünmedi. Dizinin son indeksi (ledSayisi - 1 = 3) beklenirken en büyük
  değerin 2'de kalması farkı gösterdi.

  DÜZELTME: 3 -> ledSayisi (ya da i <= 3).
*/

const int ledSayisi = 4;
const int ledler[4] = {3, 5, 6, 9};

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < ledSayisi; i++) {
    pinMode(ledler[i], OUTPUT);
  }
}

void loop() {
  for (int i = 0; i < ledSayisi; i++) {
    Serial.println(i); // hatayı bulmak için eklenen satır — kalabilir
    digitalWrite(ledler[i], HIGH);
    delay(300);
    digitalWrite(ledler[i], LOW);
  }
}
