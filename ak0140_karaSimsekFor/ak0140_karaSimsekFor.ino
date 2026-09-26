/*
  ak0140 — Kara şimşek, for ile (harcama dersi)
  Ne öğreneceğiz: Yeni fikir yok, bilerek — ak0060'ın uzun kodunu for ile kısaltmak
  Malzeme: Arduino Uno kartı, USB kablosu, 4 LED, 4 adet 220 ohm direnç, breadboard,
    8 jumper kablo
  Devre: ak0060 ile aynen: 1. LED (+) -> pin 8, 2. LED (+) -> pin 9, 3. LED (+) -> pin 10,
    4. LED (+) -> pin 11; her LED'in kısa bacağı (-) kendi 220 ohm direncine, direncin
    boş ucu GND'ye. LED'leri breadboard'a soldan sağa, yan yana diz.

  Şimdilik kara kutu (sonra açacağız):
    void   -> "fonksiyon" konusunda açılacak
    OUTPUT -> buton dersinde (ünite 2), INPUT ile birlikte açılacak
  Bunlara şimdilik dokunma, sırası gelince tek tek açacağız.

  kaynak: ..\arsiv\004karaSimsekIleri\004karaSimsekIleri.ino + kendi ak0060_karaSimsek.
          Kaynak dizi (int all_pins[4]) kullanıyordu; dizi henüz öğretilmedi (Modül 2'de
          gelecek), bu yüzden dizi kullanılmadı — pinler ardışık olduğundan döngü
          değişkeni doğrudan pin numarası oldu. Kaynakta ayrıca desen hatası vardı:
          ileri döngü i<3 (8,9,10 — 11'i atlıyor), geri döngü i=3'ten (11,10,9,8) başlıyordu;
          bu da uç LED'lerin (8 ve 11) turlar arasında art arda iki kez yanmasına yol
          açıyordu. Kod okunarak tespit edildi; ak0060'taki 1-2-3-4-3-2 deseniyle birebir
          aynı olacak şekilde düzeltildi: ileri döngü 8'den 11'e (4 adım), geri döngü
          10'dan 9'a (2 adım) — uç LED'ler (8 ve 11) turda yalnızca bir kez yanıyor.
          Düzeltilmiş desen Özgür'ün kart testiyle doğrulandı (2026-09-26).
*/

// --- KAVRAM ---
// ak0060'ta 4 LED'i tek tek, elle yazmıştık. Pinler ardışık olduğu için (8,9,10,11)
// döngü değişkeninin kendisini pin numarası olarak kullanabiliriz.
const int ilkLed = 8;
const int sonLed = 11;

void setup() {
  for (int pin = ilkLed; pin <= sonLed; pin++) {
    pinMode(pin, OUTPUT);
  }
}

void loop() {
  // İleri: 8 -> 9 -> 10 -> 11
  for (int pin = ilkLed; pin <= sonLed; pin++) {
    digitalWrite(pin, HIGH);
    delay(300);
    digitalWrite(pin, LOW);
  }

  // Geri: 10 -> 9 (uçlara, 11 ve 8'e tekrar dokunmuyoruz — onlar zaten yandı)
  for (int pin = sonLed - 1; pin >= ilkLed + 1; pin--) {
    digitalWrite(pin, HIGH);
    delay(300);
    digitalWrite(pin, LOW);
  }
}

// --- SEN YAP ---
// 1) Kartta çalıştır, ak0060 ile aynı deseni gördüğünü doğrula: 8-9-10-11-10-9, sonra
//    baştan.
// 2) Beşinci bir LED eklesen (pin 12), tek satırı (sonLed = 11 -> 12) değiştirmen
//    yeterli mi? ak0060'ta kaç satır değiştirmen gerekiyordu? Karşılaştır.
// 3) Aşağıdaki tabloyu kendi kodunla doldur: iki dersin digitalWrite+delay satır
//    sayısını say.
//
// | ders | digitalWrite+delay satırı | pinMode satırı |
// |------|----------------------------|-----------------|
// | ak0060 (elle) | 30 | 4 |
// | ak0140 (for)  | 6  | 1 (for içinde) |
//
// Aynı ışık deseni, çok daha az yazılan satır.

// --- MERAK KÖŞESİ ---
// OUTPUT burada da mı var, ne değişti?
// ak0040'ta OUTPUT'u tek pin için, ak0070'te üç pin için ayrı ayrı yazmıştık. Burada
// dört pin için de OUTPUT yazılıyor ama tek satır: for döngüsü aynı pinMode satırını
// dört pin için senin yerine tekrarlıyor. OUTPUT'un kendisi değişmedi — hâlâ "bu pin
// dışarı elektrik verecek" diyor. Ayrıntısı buton dersinde (ünite 2) açılacak (3. tur,
// bundan sonra emekli).
