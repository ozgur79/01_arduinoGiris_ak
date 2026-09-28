/*
  ak0185 — çözüm örneği

  SEN YAP 1) Deneme görevi, çözüm kodu yok: ak0140'ı ilkLed=3/sonLed=9 ile bu devreye
    yükleyince desen 4, 7, 8'de "boşta bekliyor" gibi davranır — orada LED olmadığı
    için digitalWrite hiçbir şeyi yakmaz ama delay(300) yine de çalışır, ritim bozulur.

  SEN YAP 2) Diziyi {9, 3, 6, 5} yapmak yeterli — kodun geri kalanı hiç değişmez.
    Desen artık 9-3-6-5-6-3 sırasıyla yanıp söner (aynı ALGORİTMA, farklı SIRA).
    Bu, ak0050'nin fikrinin dizi üzerinde ikinci kez işe yaraması: isimlerin (burada
    dizinin içeriğinin) değişmesi kod mantığını değiştirmez.

  SEN YAP 3) Nefes alan kara şimşek: digitalWrite(HIGH)/delay(300)/digitalWrite(LOW)
    yerine bir analogWrite döngüsü konur. Aşağıdaki kod bu hâlidir (basitleştirilmiş:
    yalnız artış, iniş yok — SEN YAP'ın kendisi iniş eklemeyi de dener).
*/

const int ledSayisi = 4;
const int ledler[4] = {9, 3, 6, 5};

void setup() {
  for (int i = 0; i < ledSayisi; i++) {
    pinMode(ledler[i], OUTPUT);
  }
}

void loop() {
  for (int i = 0; i < ledSayisi; i++) {
    for (int parlaklik = 0; parlaklik <= 255; parlaklik++) {
      analogWrite(ledler[i], parlaklik);
      delay(2);
    }
    analogWrite(ledler[i], 0);
  }
  for (int i = ledSayisi - 2; i >= 1; i--) {
    for (int parlaklik = 0; parlaklik <= 255; parlaklik++) {
      analogWrite(ledler[i], parlaklik);
      delay(2);
    }
    analogWrite(ledler[i], 0);
  }
}
