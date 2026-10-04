/*
  BU KOD NE YAPAR?
  Bu kod, 2 ve 8 numaralı pinlerdeki İKİ butona aynı anda basılırsa 6 numaralı pindeki LED'i yakar.
  Butonlardan yalnız biri basılıysa ya da hiçbiri basılı değilse LED sönük kalır (&& ile "ikisi birden" kontrolü).
*/

/*
  ak0230 — İki buton: iki elle bas (&&)
  Ne öğreneceğiz: && — "ikisi BİRDEN doğruysa"; LED yalnız iki butona aynı anda
    basılınca yanar (güvenlik kilidi)
  Malzeme: Arduino Uno kartı, USB kablosu, Paket 5 devresi (4 LED, pin 3/5/6/9),
    2 buton (pin 2 ve pin 8), 2 adet 10 kΩ direnç (her buton kendi pull-down'ıyla)
  Devre: ak0210'un devresi + ikinci buton: bir bacağı 5V'a, öbür bacağı hem pin 8'e
    hem 10 kΩ direnç üzerinden GND'ye. Basılı = HIGH. Bu derste pin 6'daki LED.

  Şimdilik kara kutu (sonra açacağız):
    void                    -> "fonksiyon" konusunda açılacak
    Serial ve noktalı yazım -> "fonksiyon" konusunda açılacak
  Bunlara şimdilik dokunma, sırası gelince tek tek açacağız.

  kaynak: ..\arsiv\015ikibutonLed\015ikibutonLed.ino — kaynakta taşınmayanlar:
          #define buton1 digitalRead(2) ve pinMode(buton1, INPUT) (pin 0/1'e
          dokunuyordu); yorumlar kodla çelişiyordu (ledPin "4" diyor, kod 6 yazıyor;
          butonDurum yorumda var, kodda yok). Temiz yazıldı, const int isimleri.
*/

// --- KAVRAM ---
// && "VE" demektir: iki koşulun İKİSİ DE doğruysa sonuç doğru olur, biri bile
// yanlışsa yanlış olur. Senaryo: güvenlik kilidi — iki eliyle iki butona birden
// basmazsan LED yanmaz.
// if (A && B) { } else { } — ak0220'deki if/else'in koşulu iki parçalı oldu.
const int buton1Pin = 2;
const int buton2Pin = 8;
const int ledPin = 6;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buton1Pin, INPUT);
  pinMode(buton2Pin, INPUT);
}

void loop() {
  if (digitalRead(buton1Pin) == HIGH && digitalRead(buton2Pin) == HIGH) {
    digitalWrite(ledPin, HIGH); // iki buton da basılı: kilit açıldı
  } else {
    digitalWrite(ledPin, LOW);  // en az biri basılı değil
  }
}

// --- SEN YAP ---
// 1) Yalnız Buton 1'e bas, sonra yalnız Buton 2'ye bas, sonra ikisine birden. LED
//    ne zaman yanıyor? Bir tablo çiz: (B1 basılı mı, B2 basılı mı) -> LED.
// 2) && yerine || ("VEYA") yaz: iki kapı zili — hangisine basılırsa LED yansın.
//    Tabloyu yeniden çiz, fark neydi?
// 3) Buton 2'nin 10 kΩ direncini SÖK, butonlara hiç dokunma. LED'e ne oluyor? (Kartına
//    göre değişebilir.) ak0210'un "havada kalan pin"iyle bağlantısı ne?
