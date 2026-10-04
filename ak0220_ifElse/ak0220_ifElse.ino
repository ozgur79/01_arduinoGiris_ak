/*
  BU KOD NE YAPAR?
  Bu kod, 2 numaralı pindeki butona basılı tutulduğu sürece 6 numaralı pindeki LED'i yakar;
  buton bırakılınca LED'i söndürür. Karar if / else ile tek yerde verilir.
*/

/*
  ak0220 — if / else: basınca yan, bırakınca sön
  Ne öğreneceğiz: else — "koşul doğruysa şunu yap, DEĞİLSE bunu yap" diye tek karar
  Malzeme: Arduino Uno kartı, USB kablosu, Paket 5 devresi (4 LED, pin 3/5/6/9),
    1 buton (pin 2), 1 adet 10 kΩ direnç (pull-down) — ak0210'un devresi aynen
  Devre: ak0210'un devresi aynen (Paket 5'in 4 LED'i + pin 2'deki buton, pull-down).
    Bu derste pin 6'daki LED kullanılıyor.

  Şimdilik kara kutu (sonra açacağız):
    void                    -> "fonksiyon" konusunda açılacak
    Serial ve noktalı yazım -> "fonksiyon" konusunda açılacak
  Bunlara şimdilik dokunma, sırası gelince tek tek açacağız.

  kaynak: ..\arsiv\012butonLed\012butonLed.ino — kaynakta üç şey taşınmadı:
          (1) #define BUTON digitalRead(2) kalıbı: okuma işini bir isme saklıyordu,
          digitalRead görünmez oluyordu; const int butonPin + açık digitalRead yazıldı.
          (2) pinMode(BUTON, INPUT): bu satır aslında pin 0 ya da 1'e dokunuyordu
          (seri portun pinleri); pinMode(butonPin, INPUT) yapıldı.
          (3) Süslü parantezsiz if/else: burada hep { } var.
*/

// --- KAVRAM ---
// ak0210'da LED'i iki ayrı işle yönetiyorduk: önce her turda SÖNDÜR, sonra butona
// basılıysa YAK. O kod çalışıyordu ama LED basılıyken de her turda bir anlığına
// söndürülüyordu (gözle görünmese de).
// else bu iki işi TEK karara çevirir: if (koşul) { doğruysa } else { değilse }.
// Kart iki bloktan YALNIZ birini çalıştırır — ya o ya bu, hiçbir zaman ikisi birden.
//
// Eski (else'siz) hâl, karşılaştırman için:
//   digitalWrite(ledPin, LOW);
//   if (digitalRead(butonPin) == HIGH) { digitalWrite(ledPin, HIGH); }
const int butonPin = 2;
const int ledPin = 6;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(butonPin, INPUT);
}

void loop() {
  if (digitalRead(butonPin) == HIGH) { // butona basıldı mı?
    digitalWrite(ledPin, HIGH);        // evet: yak
  } else {
    digitalWrite(ledPin, LOW);         // hayır: söndür
  }
}

// --- SEN YAP ---
// 1) Ünite 1'de else'siz kurduğun ak0160'ı (tek sayıları yazdır) else ile yeniden
//    yaz: tek sayıda "TEK", değilse "CIFT" yazsın. (Yeni bir taslak aç, Serial.begin(9600)
//    ve ekran gerekir.) else ile kod kısaldı mı, uzadı mı?
// 2) İki LED kullan (pin 6 ve pin 9): butona basılıyken biri, basılı değilken ötekisi
//    yansın. Hangi LED "basılı" bloğunda, hangisi else bloğunda? Kod kaç satır?
// 3) [ileri] else'in içine ikinci bir if koyabilir misin? Ne işe yarardı, düşün.
