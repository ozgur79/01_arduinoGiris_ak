/*
  ak0190 — Binary sayıcı (harcama)
  Ne öğreneceğiz: Yeni fikir yok, bilerek — ak0120 (sayaç), ak0160 (if + %) ve
    ak0185 (dizi) burada birlikte çalışıyor: 4 LED 0'dan 15'e kadar İKİLİK (binary)
    sayıyor, seri port aynı sayıyı ONLUK yazıyor.
  Malzeme: Arduino Uno kartı, USB kablosu, 4 LED, 4 adet 220 ohm direnç, breadboard,
    5 jumper kablo (dirençler ortak GND hattında, hat tek jumper ile Arduino GND'ye
    bağlanır — ak0185'teki gibi)
  Devre: ak0185 ile aynen — 1. LED (+) -> pin 3, 2. LED (+) -> pin 5, 3. LED (+) ->
    pin 6, 4. LED (+) -> pin 9. Alışılmış yazımla eşleşsin diye EN SAĞDAKİ LED (pin 9)
    = 1'ler basamağı (en küçük değerli bit), EN SOLDAKİ LED (pin 3) = 8'ler basamağı
    (en büyük değerli bit) — tıpkı onluk sayılarda birler basamağının en sağda olması
    gibi.

  Şimdilik kara kutu (sonra açacağız):
    void                    -> "fonksiyon" konusunda açılacak
    OUTPUT                  -> buton dersinde (ünite 2), INPUT ile birlikte açılacak
    Serial ve noktalı yazım -> "fonksiyon" konusunda açılacak
  Bunlara şimdilik dokunma, sırası gelince tek tek açacağız.

  kaynak: ..\arsiv\005binarySayici\005binarySayici.ino — kaynakta üç ciddi hata vardı,
          hiçbiri taşınmadı: (1) pinMode(pin[i], LOW) yanlış yazılmış (LED söndürmez,
          pinin GÖREVİNİ bozar) -> digitalWrite(ledler[i], LOW) yapıldı; (2) global
          "int i" ile döngü içindeki "int i" aynı isimdi (biri diğerini gölgeliyordu,
          kafa karıştırıcı) -> sayaca "sayi" adı verildi, "i" yalnız döngülerde kaldı;
          (3) else kullanılıyordu (bu düzeyde yok, Ünite 2'de açılacak) -> önce dört LED
          söndürülüp sonra yalnız "1" olan bitler tek tek yakılarak else'siz kuruldu.
          Ayrıca bitler arası delay(250) kaldırıldı (sayı artık bir kerede gösteriliyor,
          animasyon değil), pinler 5/7/9/11 -> ak0185 devresi (3/5/6/9) ve ledler[]
          dizisiyle taşındı.
*/

// --- KAVRAM ---
// Bir sayının ikilik (binary) hâli, her biri AÇIK ya da KAPALI dört basamaktan oluşur:
// 8'ler - 4'ler - 2'ler - 1'ler. ak0160'ta öğrendiğin % (kalan) ile her basamağın
// AÇIK mı KAPALI mı olduğunu tek tek sorabiliriz:
//   (sayi % 2) > 0   -> 1'ler basamağı açık mı?
//   (sayi % 4) > 1   -> 2'ler basamağı açık mı?
//   (sayi % 8) > 3   -> 4'ler basamağı açık mı?
//   (sayi % 16) > 7  -> 8'ler basamağı açık mı?
// else YOK: önce dört LED de söndürülür, sonra yalnız AÇIK olması gerekenler yakılır.
// Basamaklar alışılmış yazımla eşleşsin diye EN SAĞDAKİ LED (ledler[3], pin 9) en
// küçük basamak (1'ler), EN SOLDAKİ LED (ledler[0], pin 3) en büyük basamak (8'ler).
const int ledSayisi = 4;
const int ledler[4] = {3, 5, 6, 9}; // 3=8'ler, 5=4'ler, 6=2'ler, 9=1'ler basamağı

int sayi = 0;

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < ledSayisi; i++) {
    pinMode(ledler[i], OUTPUT);
  }
}

void loop() {
  for (int i = 0; i < ledSayisi; i++) {
    digitalWrite(ledler[i], LOW); // önce hepsi sönsün
  }

  if ((sayi % 2) > 0) {
    digitalWrite(ledler[3], HIGH); // 1'ler basamağı (pin 9, en sağ)
  }
  if ((sayi % 4) > 1) {
    digitalWrite(ledler[2], HIGH); // 2'ler basamağı (pin 6)
  }
  if ((sayi % 8) > 3) {
    digitalWrite(ledler[1], HIGH); // 4'ler basamağı (pin 5)
  }
  if ((sayi % 16) > 7) {
    digitalWrite(ledler[0], HIGH); // 8'ler basamağı (pin 3, en sol)
  }

  Serial.print("Sayi: ");
  Serial.println(sayi);

  sayi++;
  if (sayi == 16) {
    sayi = 0; // 15'ten sonra baştan başla
  }

  delay(1000);
}

// --- SEN YAP ---
// 1) Seri Monitör'de yazan onluk sayı ile yanan LED'leri karşılaştır. Sayi: 5 iken
//    hangi LED'ler yanıyor? (İpucu: 5 = 4 + 1, yani 4'ler ve 1'ler basamağı açık.)
// 2) delay(1000) değerini değiştir, sayma hızını ayarla.
// 3) İleri: sayma yönünü ters çevir — 15'ten 0'a insin (sayi-- ve sıfırlanma koşulunu
//    buna göre çevir).
