/*
  BU KOD NE YAPAR?
  Bu kod, 2 numaralı pine bağlı butona basılana kadar setup() içinde bir while döngüsünde programı bekletir.
  Butona basılınca loop() başlar ve 3, 5, 6, 9 numaralı pinlerdeki 4 LED'de kara şimşek efekti verir
  (ışık soldan sağa gidip geri döner).
*/

/*
  ak0215 — Başlat butonu: butona basılana kadar bekle
  Ne öğreneceğiz: bir while'ın koşulunu bir BUTON kırabilir — kart açılır, "bekle"
    der, butona basılana kadar hiçbir şey yapmaz
  Malzeme: Arduino Uno kartı, USB kablosu, Paket 5 devresi (4 LED, pin 3/5/6/9),
    1 buton (pin 2), 1 adet 10 kΩ direnç (pull-down) — ak0210'un devresi aynen
  Devre: ak0210'un devresi aynen (Paket 5'in 4 LED'i + pin 2'deki buton, pull-down).

  Şimdilik kara kutu (sonra açacağız):
    void                    -> "fonksiyon" konusunda açılacak
    Serial ve noktalı yazım -> "fonksiyon" konusunda açılacak
  Bunlara şimdilik dokunma, sırası gelince tek tek açacağız.

  kaynak: yok (Yol Haritası "sonsuz döngü 3a") + kendi ak0150 (while) ve ak0185
          (kara şimşek, dizi) — kara şimşek kodu ak0185'ten değişmeden alındı,
          yeni kod yalnız bekleme satırı.
*/

// --- KAVRAM ---
// ak0155'te loop() bir sonsuz döngüydü, hiç bitmiyordu. Burada setup() içinde
// AYRI bir while var ve bu bitiyor — koşulu (digitalRead(butonPin) == LOW) buton
// basılınca YANLIŞ olur, döngü biter, program loop()'a geçer.
// while (koşul) { } gövdesi boş olabilir — "hiçbir şey yapma, sadece koşulu
// tekrar tekrar kontrol et" demektir.
const int butonPin = 2;
const int ledSayisi = 4;
const int ledler[4] = {3, 5, 6, 9};

void setup() {
  for (int i = 0; i < ledSayisi; i++) {
    pinMode(ledler[i], OUTPUT);
  }
  pinMode(butonPin, INPUT);
  Serial.begin(9600);

  Serial.println("Butona bas...");

  while (digitalRead(butonPin) == LOW) {
    // hiçbir şey yapma, sadece tekrar bak
  }
}

void loop() {
  // ak0185'in kara şimşek deseni, değişmeden:
  for (int i = 0; i < ledSayisi; i++) {
    digitalWrite(ledler[i], HIGH);
    delay(300);
    digitalWrite(ledler[i], LOW);
  }
  for (int i = ledSayisi - 2; i >= 1; i--) {
    digitalWrite(ledler[i], HIGH);
    delay(300);
    digitalWrite(ledler[i], LOW);
  }
}

// --- SEN YAP ---
// 1) "Butona bas..." satırını while'ın İÇİNE taşı, tekrar yükle. Seri Monitör'de
//    ne oluyor? (Dikkat: ekran çok hızlı dolar, çok fazla satır akar — bu yüzden
//    yazı while'ın DIŞINDA, önce, tek sefer duruyordu.)
// 2) Dene ve gözlemle: butona BASILI TUTUNCA kara şimşek başlasın, BIRAKINCA
//    değil — koşulu (== LOW yerine == HIGH) değiştirerek bunu yapabilir misin?
//    Kodu yükle, karta dokunmadan gözlemle: kara şimşek beklediğin gibi mi
//    başlıyor, yoksa AÇILIŞTA hemen mi başlıyor? Neden böyle olduğunu defterine
//    yaz (ipucu: kart açılışında buton zaten basılı değil, koşul o an ne diyor?).
//    Bu soruya Ünite 3'te (kenar tetikleme) geri döneceğiz.
