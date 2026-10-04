/*
  BU KOD NE YAPAR?
  Bu kod iki kişilik bir refleks oyunudur. Kart 2-5 saniye rastgele bekler, sonra 6 numaralı pindeki
  sinyal LED'i yanar ("BAS!"). İlk butona basan kazanır: 2 numaralı pindeki buton Oyuncu 1'in
  (pin 3 LED), 8 numaralı pindeki buton Oyuncu 2'nin (pin 9 LED) butonudur. Sonuç Seri Monitör'e de yazılır;
  3 saniye sonra yeni tur başlar.
*/

/*
  ak0260 — Refleks oyunu (Ünite 2 kapanış projesi)
  Ne öğreneceğiz: Ünite 2'nin bütün aletleri tek projede — buton okuma, `while` ile
    bekleme, if/else, && — ve Ünite 1'den random(). Yeni kavram yok.
  Malzeme: Arduino Uno kartı, USB kablosu, Paket 5 devresi (4 LED, pin 3/5/6/9),
    2 buton (pin 2 ve pin 8), 2 adet 10 kΩ direnç (pull-down) — ak0230'un devresi aynen
  Devre: ak0230'un devresi aynen. Pin 6 = sinyal LED'i ("BAS!"), pin 3 = Oyuncu 1'in
    LED'i (Buton 1, pin 2), pin 9 = Oyuncu 2'nin LED'i (Buton 2, pin 8). Pin 5 kullanılmıyor.

  Şimdilik kara kutu (sonra açacağız):
    void                    -> "fonksiyon" konusunda açılacak
    Serial ve noktalı yazım -> "fonksiyon" konusunda açılacak
  Bunlara şimdilik dokunma, sırası gelince tek tek açacağız.

  kaynak: yok — ak tarafından yazıldı (Ünite 2 kapanış projesi). Kullanılan aletler:
          ak0210 (digitalRead), ak0215 (while ile bekleme), ak0220 (if/else), ak0230
          (&&), ak0165 (random).
*/

// --- KAVRAM ---
// Senaryo: iki oyuncu, iki buton. Kart 2 ile 5 saniye arasında rastgele bir süre
// bekler, sonra sinyal LED'i (pin 6) yanar: "BAS!". İlk basan oyuncunun LED'i yanar.
// random(2000, 5001) 2000 ile 5000 arası bir sayı verir (üst sınır hiç gelmez).
// ÇEKİRDEK SATIR: while (buton1 LOW && buton2 LOW) { } — "İKİSİ DE basmadığı sürece
// bekle". ak0215'in "basılana kadar bekle"si ile ak0230'un && işaretinin birleşimi.
// BERABERLİK: iki oyuncu aynı anda basarsa, kodda Buton 1 ÖNCE kontrol edildiği için
// Oyuncu 1 kazanır — oyun adil değil, bunu bilerek yazdık (SEN YAP 2).
const int buton1Pin = 2;
const int buton2Pin = 8;
const int sinyalLed = 6;
const int oyuncu1Led = 3;
const int oyuncu2Led = 9;

void setup() {
  pinMode(buton1Pin, INPUT);
  pinMode(buton2Pin, INPUT);
  pinMode(sinyalLed, OUTPUT);
  pinMode(oyuncu1Led, OUTPUT);
  pinMode(oyuncu2Led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(sinyalLed, LOW);
  digitalWrite(oyuncu1Led, LOW);
  digitalWrite(oyuncu2Led, LOW);

  Serial.println("Hazir olun...");
  delay(random(2000, 5001));       // 2-5 saniye rastgele bekle

  digitalWrite(sinyalLed, HIGH);   // BAS!
  Serial.println("BAS!");

  // İkisi de basmadığı sürece bekle:
  while (digitalRead(buton1Pin) == LOW && digitalRead(buton2Pin) == LOW) {
    // hiçbir şey yapma, sadece tekrar bak
  }

  if (digitalRead(buton1Pin) == HIGH) {
    digitalWrite(oyuncu1Led, HIGH);
    Serial.println("Oyuncu 1 kazandi!");
  } else {
    digitalWrite(oyuncu2Led, HIGH);
    Serial.println("Oyuncu 2 kazandi!");
  }

  delay(3000);                     // kazananı gör, sonra yeni tur
}

// --- SEN YAP ---
// 1) Yanındaki biriyle (ya da iki elinle) oyna. Butonu erken basılı tutarsan ne olur?
//    Tahminini yaz, sonra dene. "BAS!" yanmadan butona KISA basıp bırakırsan kart bunu
//    görür mü? (İpucu: ak0240'ta delay sırasında kartın butonu okuyup okumadığına bak.)
// 2) Aynı anda basınca Oyuncu 1 kazanıyor — bu adil mi? Kodda bunu adil yapmanın bir
//    yolu var mı, düşün. (Çözmek şart değil.)
// 3) Erken basanı nasıl yakalarsın? Düşün, defterine yaz. (Bu soruya Ünite 3'te geri
//    döneceğiz.)
// 4) Bekleme süresini 1-3 saniyeye indir.
