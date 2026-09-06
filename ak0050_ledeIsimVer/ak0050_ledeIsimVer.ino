/*
  ak0050 — LED'e isim ver
  Ne öğreneceğiz: Pin numarası yerine ona kendi verdiğin bir isim kullanmak; pin
    değişince tek satırı düzeltmenin yetmesi
  Malzeme: Arduino Uno kartı, USB kablosu, 2 LED (biri kırmızı biri yeşil), 2 adet
    220 ohm direnç, breadboard, 4 jumper kablo — ak0040 ile aynı devre, sökmene gerek yok
  Devre: kırmızı LED uzun bacak (+) -> Arduino pin 8
         kırmızı LED kısa bacak (-) -> 220 ohm direnç -> Arduino GND
         yeşil LED uzun bacak (+) -> Arduino pin 9
         yeşil LED kısa bacak (-) -> 220 ohm direnç -> Arduino GND

  Şimdilik kara kutu (sonra açacağız):
    void    -> "fonksiyon" konusunda açılacak (temel düzeyin ilerisinde, numarası o tur belirlenecek)
    OUTPUT  -> buton dersinde (ünite 2), INPUT ile birlikte açılacak (numarası o tur belirlenecek)
  Bunlara şimdilik dokunma, sırası gelince tek tek açacağız.
*/

// --- KAVRAM ---
// Aşağıdaki satır 8 sayısına "kirmizi" adını verir; bundan sonra 8 yerine kirmizi yazabilirsin
// const, "bu isme verilen sayı bir daha değişmeyecek" demektir
const int kirmizi = 8;
const int yesil = 9;
// İsim satırları setup ve loop'un dışında, en üstte durur; böylece hem setup hem loop
// bu isimleri kullanabilir

void setup() {
  pinMode(kirmizi, OUTPUT); // kirmizi adını verdiğimiz pini, açıp kapatabileceğimiz bir pin yap
  pinMode(yesil, OUTPUT);   // yesil adını verdiğimiz pini, açıp kapatabileceğimiz bir pin yap
}

void loop() {
  digitalWrite(kirmizi, HIGH); // kirmizi pini aç   -> kırmızı LED yanar
  digitalWrite(yesil, LOW);    // yesil pini kapat  -> yeşil LED söner
  delay(300);                  // bu durumu 300 milisaniye koru

  digitalWrite(kirmizi, LOW);  // kirmizi pini kapat -> kırmızı LED söner
  digitalWrite(yesil, HIGH);   // yesil pini aç      -> yeşil LED yanar
  delay(300);                  // bu durumu da 300 milisaniye koru
}

// --- SEN YAP ---
// 1) İki LED'i de taşı: kabloları pin 8 ve 9'dan pin 10 ve 11'e al, kodu da düzelt.
//    Kodda kaç satır değiştirdin? Şimdi ak0040'ın koduna bak: aynı taşımayı orada
//    yapsaydın kaç satır değişecekti? İki sayıyı yan yana yaz.
// 2) kirmizi ve yesil isimlerini kendi LED'lerinin gerçek renklerine göre değiştir.
//    Kaç yerde değiştirmen gerekti?
// 3) İsimleri kirmizi ve yesil yerine a ve b yap. Kod yine çalışıyor mu? Çalışıyorsa
//    isim vermek kime yarıyor — Arduino'ya mı, sana mı? İki satırda yaz.

// --- MERAK KÖŞESİ ---
// void yine karşımızda, ama bu sefer başka bir yerden
// Bu derste "const int kirmizi = 8;" yazdın: bir sayıya isim verdin ve ismin önüne
// int yazdın. int burada "bu isim bir sayı tutuyor" demek.
// void da setup ve loop'un isminin tam olarak aynı yerinde duruyor. Farkı şu:
// int "bu bir sayı" derken, void "bu listeden geriye hiçbir şey gelmez" diyor.
// İkisinin neden aynı yerde durduğunu "fonksiyon" dersinde göreceğiz.
