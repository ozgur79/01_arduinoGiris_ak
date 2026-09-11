/*
  ak0070 — Trafik lambası
  Ne öğreneceğiz: Bildiğimiz üç LED'i bir trafik lambası işi için birlikte kullanmak;
    sürelerin kodun anlamını değiştirdiğini görmek
  Malzeme: Arduino Uno kartı, USB kablosu, kırmızı LED, sarı LED, yeşil LED,
    3 adet 220 ohm direnç, breadboard, 6 jumper kablo
  Devre: Kırmızı LED uzun bacak (+) -> pin 8, kısa bacak (-) -> 220 ohm direnç -> GND
         Sarı LED uzun bacak (+) -> pin 9, kısa bacak (-) -> 220 ohm direnç -> GND
         Yeşil LED uzun bacak (+) -> pin 10, kısa bacak (-) -> 220 ohm direnç -> GND

  Şimdilik kara kutu (sonra açacağız):
    void    -> "fonksiyon" konusunda açılacak (temel düzeyin ilerisinde, numarası o tur belirlenecek)
    OUTPUT  -> buton dersinde (ünite 2), INPUT ile birlikte açılacak (numarası o tur belirlenecek)
  Bunlara şimdilik dokunma, sırası gelince tek tek açacağız.

  kaynak: D:\ArduinoProjeleri\002Arduino\008trafikLambasi\008trafikLambasi.ino
          (pin 2/3/4 -> 8/9/10 taşındı; pin numaralarına isim verildi.)
*/

// --- KAVRAM ---
// Her LED'e adıyla sesleniyoruz; sayı yerine renk adını yazmak kodu okumayı kolaylaştırır
// Her adımda üç LED'in de durumunu yazıyoruz: kırmızı uzun, yeşil orta, sarı kısa bekler
const int kirmizi = 8;
const int sari = 9;
const int yesil = 10;

void setup() {
  pinMode(kirmizi, OUTPUT);
  pinMode(sari, OUTPUT);
  pinMode(yesil, OUTPUT);
}

void loop() {
  // Dur: kırmızı yanar, diğer iki LED söner
  digitalWrite(kirmizi, HIGH);
  digitalWrite(sari, LOW);
  digitalWrite(yesil, LOW);
  delay(4000);

  // Geç: yeşil yanar, diğer iki LED söner
  digitalWrite(kirmizi, LOW);
  digitalWrite(sari, LOW);
  digitalWrite(yesil, HIGH);
  delay(3000);

  // Hazırlan: sarı yanar, diğer iki LED söner
  digitalWrite(kirmizi, LOW);
  digitalWrite(sari, HIGH);
  digitalWrite(yesil, LOW);
  delay(1000);
}

// --- SEN YAP ---
// 1) Süreleri değiştir. Kırmızı daha uzun, sarı daha kısa, yeşil ortada kalacak başka
//    üç sayı seç. Trafik lambasının davranışı nasıl değişti?
// 2) Türkiye'deki sırayı kur: kırmızı -> kırmızı+sarı -> yeşil -> sarı -> kırmızı.
//    Kırmızı+sarı adımında iki LED'i aynı anda HIGH yap. Her adımda üç LED'in de
//    durumunu yazmayı unutma.

// --- MERAK KÖŞESİ ---
// OUTPUT neyi söylüyor?
// ak0040'ta OUTPUT'un pine dışarı elektrik vereceğini söylediğini gördün.
// Bu derste üç rengin her birini açıp kapatabilmemiz için üç pine de OUTPUT yazıyoruz.
// OUTPUT'un daha ayrıntılı açıklaması buton dersinde (ünite 2), INPUT ile birlikte gelecek.
