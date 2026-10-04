/*
  BU KOD NE YAPAR?
  Bu kod, 2 numaralı pindeki butona basılınca 6 numaralı pindeki LED'i 2 saniye yakıp söndürür.
  Butonu bıraksan da LED 2 saniye boyunca yanık kalır; bu sürede kart butonu okumaz (delay).
*/

/*
  ak0240 — Zamanlı tepki: bas, 2 saniye yansın
  Ne öğreneceğiz: butona basış bir OLAYI başlatır; olay kendi süresince sürer —
    butonu bıraksan da LED 2 saniye yanar, sonra söner
  Malzeme: Arduino Uno kartı, USB kablosu, Paket 5 devresi (4 LED, pin 3/5/6/9),
    1 buton (pin 2), 1 adet 10 kΩ direnç (pull-down) — ak0210'un devresi aynen
  Devre: ak0210'un devresi aynen. Bu derste pin 6'daki LED kullanılıyor.

  Şimdilik kara kutu (sonra açacağız):
    void                    -> "fonksiyon" konusunda açılacak
    Serial ve noktalı yazım -> "fonksiyon" konusunda açılacak
  Bunlara şimdilik dokunma, sırası gelince tek tek açacağız.

  kaynak: ..\arsiv\020GriButonLed\020GriButonLed.ino (ana) + ..\arsiv\021YesilButonLed\
          021YesilButonLed.ino (SEN YAP 3, ters hâl). Kaynakta pin numaraları (2, 6)
          düz sayıydı; const int butonPin/ledPin isimleri verildi (ak0050 köprüsü).
*/

// --- KAVRAM ---
// ak0220'de LED butonla BİRLİKTE yanıp sönüyordu: basılıyken yanık, bırakınca söner.
// Burada farklı: butona basmak bir OLAYI başlatıyor. Olay başlayınca kendi süresi
// kadar sürüyor — sen butonu bıraksan da 2 saniye dolana kadar LED yanık kalıyor.
// delay(2000) kartı 2000 milisaniye (2 saniye) bekletir; bu süre içinde kart
// yalnızca bekler.
const int butonPin = 2;
const int ledPin = 6;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(butonPin, INPUT);
  digitalWrite(ledPin, LOW); // başlangıçta sönük
}

void loop() {
  if (digitalRead(butonPin) == HIGH) { // butona basıldı mı?
    digitalWrite(ledPin, HIGH);        // olay başladı: yak
    delay(2000);                       // 2 saniye yanık kalsın
    digitalWrite(ledPin, LOW);         // olay bitti: söndür
  }
}

// --- SEN YAP ---
// 1) LED yanıkken butona tekrar tekrar bas. Ne oluyor? Kart sana cevap veriyor mu?
//    Gördüğünü defterine yaz.
// 2) Butona BASILI TUT. Tahminini önce yaz: 2 saniye sonra LED söner mi, yoksa hemen
//    tekrar mı yanar? Sonra dene — tahminin tuttu mu?
// 3) Ters hâli yap: program yüklenince LED doğrudan YANIK olsun; butona basınca LED
//    3 saniye SÖNSÜN, sonra tekrar yansın.

// --- MERAK KÖŞESİ ---
// SEN YAP 1'de butona bastığında kartın neden cevap vermediğini merak ettin mi?
// delay() sırasında kart butonu hiç okumuyor. Buna Ünite 3'te millis() ile çare
// bulacağız (ak0195'te delay kullanmadan zaman ölçmüştük).
