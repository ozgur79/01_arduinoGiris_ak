/*
  ak0020 — Harici LED'i yakıp söndür
  Ne öğreneceğiz: LED'i Arduino kartının dışında, bir devre üzerinde bağlayıp yakmak
  Malzeme: Arduino Uno kartı, USB kablosu, 1 LED, 1 adet 220 ohm direnç, breadboard,
    2 jumper kablo
  Devre: LED'in uzun bacağı (+) -> Arduino pin 8
         LED'in kısa bacağı (-) -> 220 ohm direnç -> Arduino GND

  Şimdilik kara kutu (sonra açacağız):
    void    -> "fonksiyon" konusunda açılacak (temel düzeyin ilerisinde, numarası o tur belirlenecek)
    OUTPUT  -> buton dersinde (ünite 2), INPUT ile birlikte açılacak (numarası o tur belirlenecek)
  Bunlara şimdilik dokunma, sırası gelince tek tek açacağız.

  kaynak: arsiv/002ledYak/002ledYak.ino
*/

// --- KAVRAM ---
// LED'in iki bacağı var: uzun bacak (+) ve kısa bacak (-) - yönü önemlidir, ters
// takarsan LED yanmaz
// Direnç, LED'e çok fazla akım gitmesini engeller ve LED'i korur
void setup() {
  // { ve } arasındaki satırlar, o fonksiyona ait koddur; bu blok "başlangıç" bloğudur
  pinMode(8, OUTPUT); // 8. pini, açıp kapatabileceğimiz bir pin yap
  // ; işareti, bir komutun bittiğini gösterir
}

void loop() {
  digitalWrite(8, HIGH); // 8. pini aç -> LED yanar
  delay(1000);           // 1000 milisaniye (1 saniye) bekle
  digitalWrite(8, LOW);  // 8. pini kapat -> LED söner
  delay(1000);           // 1 saniye bekle
}

// --- SEN YAP ---
// 1) LED'in bacaklarını yer değiştirerek tak (ters bağla). Ne oluyor, gözlemle.
// 2) LED'in kablosunu pin 8'den pin 9'a taşı. Kodda da neyi değiştirmen gerekiyor?
//    Değiştir ve çalıştır.
