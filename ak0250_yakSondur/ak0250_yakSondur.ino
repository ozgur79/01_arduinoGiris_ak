/*
  BU KOD NE YAPAR?
  Bu kod iki butonla 6 numaralı pindeki LED'i yönetir: 2 numaralı pindeki buton LED'i yakar,
  8 numaralı pindeki buton söndürür. LED bir kez yanınca buton bırakılsa bile yanık kalır.
  İşlem, buton BIRAKILINCA gerçekleşir.
*/

/*
  ak0250 — İki buton: biri yakar, biri söndürür
  Ne öğreneceğiz: LED'in durumu butondan BAĞIMSIZ kalır — bir kez yakınca butonu
    bıraksan da yanık kalır, söndürmek için ayrı bir butona basman gerekir
  Malzeme: Arduino Uno kartı, USB kablosu, Paket 5 devresi (4 LED, pin 3/5/6/9),
    2 buton (pin 2 ve pin 8), 2 adet 10 kΩ direnç (pull-down) — ak0230'un devresi aynen
  Devre: ak0230'un devresi aynen. Buton 1 (pin 2) = YAK, Buton 2 (pin 8) = SÖNDÜR.
    Bu derste pin 6'daki LED kullanılıyor.

  Şimdilik kara kutu (sonra açacağız):
    void                    -> "fonksiyon" konusunda açılacak
    Serial ve noktalı yazım -> "fonksiyon" konusunda açılacak
  Bunlara şimdilik dokunma, sırası gelince tek tek açacağız.

  kaynak: ..\arsiv\022MaviButonKolay\022MaviButonKolay.ino (ana; 022MaviButonZor yalnız
          karşılaştırma için okundu, #define kalıbı taşınmadı). Kaynakta taşınmayanlar:
          (1) SÖNDÜR butonu pin 3'teydi — bizde pin 3 bir LED; buton pin 8'e alındı.
          (2) while(digitalRead(2)==1); noktalı virgüllü boş gövde — burada { } yazıldı.
          (3) düz sayı pinleri — const int isimleri verildi.
*/

// --- KAVRAM ---
// Burada LED'in durumunu TUTAN şey bir değişken değil, LED'in kendisi: bir kez
// HIGH yaptın mı, sen başka bir şey yazana kadar öyle kalır. Buton yalnızca "karar
// anı"nı bildirir — LED bundan sonra butondan bağımsız.
// while (digitalRead(yakPin) == HIGH) { } "buton BIRAKILANA kadar bekle" demektir.
// ak0215'te tam tersiydi: orada buton BASILANA kadar bekliyorduk.
// delay(100): buton basılıp bırakılırken kontaklar bir anlığına sekebilir (buna
// "sıçrama" denir); 100 milisaniye bekleyip bu sekmenin geçmesini bekliyoruz.
const int yakPin = 2;
const int sondurPin = 8;
const int ledPin = 6;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(yakPin, INPUT);
  pinMode(sondurPin, INPUT);
}

void loop() {
  if (digitalRead(yakPin) == HIGH) { // YAK butonuna basıldı mı?
    while (digitalRead(yakPin) == HIGH) {
      // bırakılana kadar bekle
    }
    delay(100);                      // sıçrama geçsin
    digitalWrite(ledPin, HIGH);      // yak — bundan sonra LED kendi başına yanık
  }

  if (digitalRead(sondurPin) == HIGH) { // SÖNDÜR butonuna basıldı mı?
    while (digitalRead(sondurPin) == HIGH) {
      // bırakılana kadar bekle
    }
    delay(100);
    digitalWrite(ledPin, LOW);       // söndür
  }
}

// --- SEN YAP ---
// 1) YAK'a bas ve bırak: LED ne zaman yanıyor — bastığın anda mı, bıraktığın anda mı?
//    Kodu okuyarak önce tahmin et, sonra dene.
// 2) delay(100) satırlarını sil, tekrar yükle. Butonlara çok hızlı bas-bırak yap. Bir
//    fark görüyor musun? (Görmeyebilirsin — sıçrama her butonda, her seferinde
//    olmaz. Görmediysen de "yok" diye yazma, "bu denemede görmedim" diye yaz.)
// 3) İki butona BİRDEN bas (ak0230'daki gibi). LED ne yapıyor? Hangisi kazanıyor,
//    neden? Kodda hangisi önce kontrol ediliyor?
