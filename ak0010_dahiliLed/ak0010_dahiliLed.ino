/*
  ak0010 — Dahili LED'i yakıp söndür
  Ne öğreneceğiz: setup() bir kez çalışır, loop() sürekli tekrar eder;
    bir pini açıp kapatarak ve arada bekleyerek LED'i yakıp söndürürüz
  Malzeme: sadece Arduino Uno kartı (USB kablosuyla bağlı, devre kurmana gerek yok)
  Devre: yok — bu kartta (Arduino Uno) dahili LED zaten pin 13'e bağlı, hazır

  Şimdilik kara kutu (sonra açacağız):
    void    -> "fonksiyon" konusunda açılacak (temel düzeyin ilerisinde, numarası o tur belirlenecek)
    { }     -> ak0020
    ;       -> ak0020
    OUTPUT  -> buton dersinde (ünite 2), INPUT ile birlikte açılacak (numarası o tur belirlenecek)
  Bunlara şimdilik dokunma, sırası gelince tek tek açacağız.

  kaynak: arsiv/001dahiliLed/001dahiliLed.ino
*/

// --- KAVRAM ---
void setup() {
  // setup() içindeki satırlar kart açılınca sadece 1 kez çalışır
  pinMode(13, OUTPUT); // 13. pini, açıp kapatabileceğimiz bir pin yap
}

void loop() {
  // loop() içindeki satırlar setup bitince sürekli baştan tekrar eder
  digitalWrite(13, HIGH); // 13. pini aç -> LED yanar
  delay(1000);            // 1000 milisaniye (1 saniye) bekle
  digitalWrite(13, LOW);  // 13. pini kapat -> LED söner
  delay(1000);            // 1 saniye bekle
}

// --- SEN YAP ---
// 1) delay(1000) yazan iki satırdaki 1000 sayısını değiştir; LED'i daha hızlı ya da
//    daha yavaş yakıp söndür.
// 2) İki delay() değerini birbirinden farklı yap (ör. yanma kısa, sönme uzun).
