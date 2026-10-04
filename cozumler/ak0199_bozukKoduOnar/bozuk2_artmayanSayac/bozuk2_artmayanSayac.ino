/*
  ak0199 — çözüm 2/3: artmayan sayaç

  HATA: while bloğunun içinde i'yi artıran bir satır (i++;) yok. i hep 0 kalıyor,
  koşul (i < ledSayisi) hiç yanlış olmuyor — while'dan çıkılamıyor, program
  loop()'un başına asla dönemiyor, sadece ilk LED (pin 3) sonsuza kadar yanıp
  sönüyor.

  NASIL BULUNDU: while'ın içine Serial.println(i); eklenip Seri Monitör
  izlendi — ekranda 0, 1, 2, 3 sırasıyla beklenirken sürekli 0 yazdığı görüldü.
  Sayacın hiç değişmemesi hatayı gösterdi.

  DÜZELTME: while bloğunun sonuna i++; eklendi.
*/

const int ledSayisi = 4;
const int ledler[4] = {3, 5, 6, 9};

void setup() {
  Serial.begin(9600);
  for (int j = 0; j < ledSayisi; j++) {
    pinMode(ledler[j], OUTPUT);
  }
}

void loop() {
  int i = 0;
  while (i < ledSayisi) {
    Serial.println(i); // hatayı bulmak için eklenen satır — kalabilir
    digitalWrite(ledler[i], HIGH);
    delay(300);
    digitalWrite(ledler[i], LOW);
    i++;
  }
}
