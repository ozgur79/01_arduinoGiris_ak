/*
  BU KOD NE YAPAR?
  Bu kod, 2 ve 8 numaralı pinlerdeki iki butona basılma sayısını AYRI AYRI sayar ve Seri Monitör'e yazar.
  Butonun ne zaman YENİ basıldığını, bir önceki turdaki durumla karşılaştırarak yakalar;
  bu yüzden hiç beklemez ve iki buton aynı anda sayılabilir.
*/

/*
  ak0320 — Kenar tetikleme: "az önce nasıldı?"
  Ne öğreneceğiz: kart bir önceki durumu bir değişkende saklar; butonun DEĞİŞTİĞİ
    anı yakalar — artık hiç beklemeden, iki butonu aynı anda sayabilir
  Malzeme: Arduino Uno kartı, USB kablosu, Paket 5 devresi (4 LED, pin 3/5/6/9),
    2 buton (pin 2 ve pin 8), 2 adet 10 kΩ direnç (pull-down) — ak0230'un devresi aynen
  Devre: ak0230'un devresi aynen. Ekran dersi; LED kullanılmıyor.

  Şimdilik kara kutu (sonra açacağız):
    void                    -> "fonksiyon" konusunda açılacak
    Serial ve noktalı yazım -> "fonksiyon" konusunda açılacak
  Bunlara şimdilik dokunma, sırası gelince tek tek açacağız.

  kaynak: ..\arsiv\045butonSayac\045butonSayac.ino (+ 023SariButon'un aynı fikri).
          Kaynaktaki delay(50) bu derste YOK: sıçrama ak0330'un konusu. Kaynak `!=`
          ile değişimi yakalıyordu; burada `&&`'li hâl ana kod (ak0230 köprüsü, daha
          az yeni şey), `!=` SEN YAP'ta ikinci yol. pin 2 `buttonPin` -> `buton1Pin`.
*/

// --- KAVRAM ---
// ak0310'da butonu bırakılana kadar `while` ile bekliyorduk ve bekleyen kart diğer
// butonu göremiyordu. Yeni yol: beklemek yok. Her turda butonu oku, bir önceki
// turdaki değerle (sonDurum) karşılaştır:
//   şimdi HIGH ve az önce LOW -> yeni basıldı (yükselen kenar) -> say.
// Basılı tutarken şimdi HIGH ve az önce de HIGH olduğu için koşul YANLIŞ: sayılmaz.
// Her turun sonunda "şimdiki" değer "az önceki" olur, kart hafızasını böyle yeniler.
const int buton1Pin = 2;
const int buton2Pin = 8;
int sayac1 = 0;
int sayac2 = 0;
int durum1 = LOW;
int durum2 = LOW;
int sonDurum1 = LOW;
int sonDurum2 = LOW;

void setup() {
  pinMode(buton1Pin, INPUT);
  pinMode(buton2Pin, INPUT);
  Serial.begin(9600);
}

void loop() {
  durum1 = digitalRead(buton1Pin);
  durum2 = digitalRead(buton2Pin);

  if (durum1 == HIGH && sonDurum1 == LOW) { // Buton 1 YENİ basıldı
    sayac1++;
    Serial.print("Buton 1: ");
    Serial.println(sayac1);
  }
  if (durum2 == HIGH && sonDurum2 == LOW) { // Buton 2 YENİ basıldı
    sayac2++;
    Serial.print("Buton 2: ");
    Serial.println(sayac2);
  }

  sonDurum1 = durum1; // şimdiki değer bir sonraki turun "az önceki"si
  sonDurum2 = durum2;
}

// --- SEN YAP ---
// 1) Buton 1'i BASILI TUT, Buton 2'ye art arda bas. Şimdi Buton 2 sayılıyor mu?
//    ak0310'daki sorunla karşılaştır, defterine yaz.
// 2) Butona bastığında sayı bazen tek basışta 2 artıyor mu? Denemeden tahmin etme,
//    çok kez bas ve say. (Artıyorsa sebebi bir sonraki dersin konusu, hata değil.)
// 3) "Bırakınca" da bir şey olsun: Buton 1 BIRAKILDIĞINDA ekrana "birakildi" yazsın.
//    Koşulu kendin kur: şimdi LOW, az önce HIGH. (ak0215'te "bırakınca başla" merakın
//    buradan cevap buluyor.)
// 4) `durum1 == HIGH && sonDurum1 == LOW` yerine `durum1 != sonDurum1` yaz ve ekrana
//    yalnız değişimi yazdır. Ne fark var? (`!=` "eşit değilse" demek, ak0160'tan.)
