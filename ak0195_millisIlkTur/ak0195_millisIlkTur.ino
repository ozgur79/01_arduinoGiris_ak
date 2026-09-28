/*
  ak0195 — millis() 1. tur: iki LED, iki ritim
  Ne öğreneceğiz: millis() — kart açıldığından beri geçen milisaniyeyi okuyan bir
    "saat"; delay() gibi programı BEKLETMEZ, sen zamanı okursun
  Malzeme: Arduino Uno kartı, USB kablosu, 2 LED (ak0185/ak0190 devresindeki 4
    LED'den ikisi: pin 3 ve pin 9), 2 adet 220 ohm direnç, breadboard, 3 jumper kablo
    (sıfırdan kuruluyorsa: 2 sinyal + dirençlerin ortak GND hattına 1 jumper)
  Devre: 1. LED (+) -> pin 3, 2. LED (+) -> pin 9; her LED'in kısa bacağı (-) kendi
    220 ohm direncine, direnç ortak GND hattına, hat da TEK jumper ile Arduino GND'ye.
    (ak0185/ak0190'ın 4 LED'lik devresi kurulmuşsa hiçbir yeni jumper gerekmez; pin 3
    ve pin 9'daki LED'ler aynen kullanılır, pin 5/6 boşta kalır.)

  ACI (önce dene): pin 3'teki LED'i saniyede BİR, pin 9'daki LED'i saniyede ÜÇ kez
  yanıp söndürmeyi delay() ile dene. İkisi de delay() içinde beklediği için, biri
  beklerken öteki DURUR — ikisini aynı anda, bağımsız hızlarda çalıştıramazsın.
  (Kaynaktaki 1 s / 2 s deseni KATLI olduğu için delay ile "hile" yapılabiliyordu;
  1 s / 3-kez öyle değil, hile çalışmaz.)

  Şimdilik kara kutu (sonra açacağız):
    void      -> "fonksiyon" konusunda açılacak
    OUTPUT    -> buton dersinde (ünite 2), INPUT ile birlikte açılacak
    unsigned  -> sayı türleri ileri konusunda açılacak (numarası o tur belirlenecek)
  Bunlara şimdilik dokunma, sırası gelince tek tek açacağız.

  kaynak: ..\arsiv\003ikiLed_saniyede1saniyede2\003ikiLed_saniyede1saniyede2.ino
          (acının delay'li hâli, iki LED'i pin 12/13'te 1 s / 2 s ile yakıyordu, 2 s
          1 s'in katı olduğu için nested delay ile çalışıyordu). Bu ders 1 s / 3-kez
          kullanır (katı değil) ve delay yerine millis() ile çözer.
*/

// --- KAVRAM ---
// millis(), kart açıldığından beri geçen milisaniyeyi verir — hep artan bir SAAT.
// delay() programı durdurup bekletirken, millis() sadece "şu an kaç" diye SORULUR,
// hiçbir şeyi bekletmez.
//
// Kalıp: "onceki zamandan bu yana ARALIK kadar geçtiyse, işi yap ve onceki'yi güncelle"
//   if (simdi - onceki >= aralik) { onceki = simdi; ... }
//
// millis()'in kutusu int değil, unsigned long: ak0150'de int'in 32767'de taştığını
// görmüştün; millis() birkaç saniyede bile bunu geçer, bu yüzden çok daha büyük bir
// kutuya (unsigned long) ihtiyaç var.
const int ledA = 3; // saniyede 1 kez yanıp söner
const int ledB = 9; // saniyede 3 kez yanıp söner

unsigned long oncekiA = 0;
unsigned long oncekiB = 0;
const unsigned long aralikA = 500; // 500 ms açık + 500 ms kapalı = saniyede 1 tam yanıp sönme
const unsigned long aralikB = 167; // ~167 ms açık + ~167 ms kapalı = saniyede ~3 tam yanıp sönme

int durumA = 0; // 0 = sönük, 1 = yanık
int durumB = 0;

void setup() {
  pinMode(ledA, OUTPUT);
  pinMode(ledB, OUTPUT);
}

void loop() {
  unsigned long simdi = millis();

  if (simdi - oncekiA >= aralikA) {
    oncekiA = simdi;
    durumA = 1 - durumA; // 0 ise 1, 1 ise 0 yapar (! ve else olmadan durum çevirme)
    digitalWrite(ledA, durumA); // durumA 1 ise HIGH, 0 ise LOW ile aynı şeydir
  }

  if (simdi - oncekiB >= aralikB) {
    oncekiB = simdi;
    durumB = 1 - durumB;
    digitalWrite(ledB, durumB);
  }
}

// --- SEN YAP ---
// 1) Üçüncü bir LED ekle (pin 5, ak0185/ak0190 devresinde zaten var): kendi
//    oncekiC/aralikC/durumC değişkenlerini tanımla, üçüncü bir ritimle (ör. saniyede
//    5 kez, aralikC = 100) yanıp söndür.
// 2) aralikA ve aralikB değerlerini değiştir, LED'lerin hızını ayarla.
// 3) loop() içinde hiç delay() OLMADIĞINI fark ettin mi? İki LED birbirini hiç
//    beklemiyor, ikisi de "aynı anda" çalışıyor gibi görünüyor. delay() ile bunu
//    yapmaya çalışsaydın ne olurdu? (Dersin başındaki ACI denemesine geri dön.)
//
// Soru (cevabını arama, defterine yaz): loop() içinde delay() OLSAYDI ve bir yere
// buton eklesen, butona basınca ne olurdu? Üç ünite sonra buton dersinde bu soruya
// geri döneceğiz.
