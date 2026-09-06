/*
  ak0040 — İki LED sırayla
  Ne öğreneceğiz: Aynı programda iki ayrı pini birlikte yönetmek; biri yanarken
    diğerini sönük tutmak (zıt durum)
  Malzeme: Arduino Uno kartı, USB kablosu, 2 LED (mümkünse farklı renkte), 2 adet
    220 ohm direnç, breadboard, 4 jumper kablo
  Devre: 1. LED uzun bacak (+) -> Arduino pin 8
         1. LED kısa bacak (-) -> 220 ohm direnç -> Arduino GND
         2. LED uzun bacak (+) -> Arduino pin 9
         2. LED kısa bacak (-) -> 220 ohm direnç -> Arduino GND

  Şimdilik kara kutu (sonra açacağız):
    void    -> "fonksiyon" konusunda açılacak (temel düzeyin ilerisinde, numarası o tur belirlenecek)
    OUTPUT  -> buton dersinde (ünite 2), INPUT ile birlikte açılacak (numarası o tur belirlenecek)
  Bunlara şimdilik dokunma, sırası gelince tek tek açacağız.

  kaynak: arsiv/006ikiLed/006ikiLed.ino (pin 13 ve 12 yerine pin 8 ve 9 kullanıldı;
          pin 13'te kartın dahili LED'i var, ikisi birlikte yanınca hangisine baktığın
          ayırt edilemez)
*/

// --- KAVRAM ---
// Her pinin kendi pinMode satırı olur: iki LED kullanıyorsan iki satır yazarsın
// Aynı loop() içinde iki pin birbirinden bağımsız olarak açılıp kapatılabilir
// Bir LED yanarken diğerinin sönük olmasına "zıt durum" denir
void setup() {
  pinMode(8, OUTPUT); // 8. pini, açıp kapatabileceğimiz bir pin yap
  pinMode(9, OUTPUT); // 9. pini, açıp kapatabileceğimiz bir pin yap
}

void loop() {
  digitalWrite(8, HIGH); // 8. pini aç  -> 1. LED yanar
  digitalWrite(9, LOW);  // 9. pini kapat -> 2. LED söner
  delay(300);            // bu durumu 300 milisaniye koru

  digitalWrite(8, LOW);  // 8. pini kapat -> 1. LED söner
  digitalWrite(9, HIGH); // 9. pini aç  -> 2. LED yanar
  delay(300);            // bu durumu da 300 milisaniye koru
}

// --- SEN YAP ---
// 1) İki LED'i zıt değil, BİRLİKTE çalıştır: ikisi aynı anda yansın, aynı anda sönsün.
//    Hangi satırları değiştirmen gerekiyor?
// 2) İlk hâline dön. Şimdi süreleri farklılaştır: 8'e bağlı LED 300 milisaniye yanık
//    kalsın, 9'a bağlı LED 900 milisaniye yanık kalsın.
// 3) İki LED'i de sürekli yanık bırakan bir kod yazabilir misin? Dene ve gördüğünü yaz.

// --- MERAK KÖŞESİ ---
// OUTPUT ne demek?
// pinMode satırında bir pine ne iş yapacağını söylüyorsun. OUTPUT: "bu pin dışarı
// elektrik verecek" demek — LED yakmak için gereken şey bu. Görev bir kez seçilir,
// o yüzden bu satır setup listesinde duruyor, loop'ta değil.
// Bu derste iki ayrı pin için de OUTPUT yazdın, çünkü ikisinde de LED var.
// Bir pinin dışarıdan bilgi alması da mümkün; onu buton dersinde (ünite 2) göreceğiz.
