/*
  BU KOD NE YAPAR?
  Bu kod, 2 numaralı pindeki butonun BASILDIĞI anı ve BIRAKILDIĞI anı ayrı ayrı yakalar.
  Basışta Seri Monitör'e "BASTI" yazar ve 3 numaralı pindeki LED'i kısa yakar;
  bırakışta "BIRAKTI" yazar ve 9 numaralı pindeki LED'i kısa yakar.
*/

/*
  ak0340 — Bastı mı, bıraktı mı: else if
  Ne öğreneceğiz: else if — iki olaydan hangisi olduğunu tek zincirde sor:
    "basıldıysa BASTI, DEĞİLSE EĞER bırakıldıysa BIRAKTI"
  Malzeme: Arduino Uno kartı, USB kablosu, Paket 5 devresi (4 LED, pin 3/5/6/9),
    1 buton (pin 2), 1 adet 10 kΩ direnç (pull-down) — ak0320'nin devresi aynen
  Devre: ak0320/ak0330 devresi aynen. Basışta pin 3, bırakışta pin 9 kısa yanar.

  Şimdilik kara kutu (sonra açacağız):
    void                    -> "fonksiyon" konusunda açılacak
    Serial ve noktalı yazım -> "fonksiyon" konusunda açılacak
  Bunlara şimdilik dokunma, sırası gelince tek tek açacağız.

  kaynak: ..\arsiv\030butonBastiBirakti\030butonBastiBirakti.ino — kaynaktaki
          `basildi`/`birakildi` bayrakları ve `!` taşınmadı: sonDurum zaten
          basış ile bırakışın sırayla geldiğini garanti ediyor, bayraklar hiçbir şey
          eklemiyordu (kod okunarak çıkarıldı; kartta ikisinin çıktısı karşılaştırılacak).
          bool ve ! bu dersin konusu değil, sonraki paketin.
*/

// --- KAVRAM ---
// Kenar tetikleme (ak0320) iki yöne bakabilir: LOW -> HIGH = BASTI, HIGH -> LOW =
// BIRAKTI. Bu ikisi AYNI ANDA olamaz: bir tur ya basıştır, ya bırakıştır, ya da
// hiçbiri. `else if` tam bunu söyler: ilk koşul yanlışsa ikincisine bak.
//   if (A) { ... } else if (B) { ... }
// ak0220'nin `else`'i "ilk koşul yanlışsa BAŞKA ne olursa olsun şunu yap"dı;
// `else if` ise "ilk koşul yanlışsa ve şu koşul doğruysa" demek.
// Ünite 1'de `else if` yoktu, Ünite 2'de bekletilmişti — söz tutuldu.
const int butonPin = 2;
const int basisLed = 3;
const int birakisLed = 9;

int durum = LOW;
int sonDurum = LOW;

void setup() {
  pinMode(butonPin, INPUT);
  pinMode(basisLed, OUTPUT);
  pinMode(birakisLed, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  durum = digitalRead(butonPin);

  if (durum == HIGH && sonDurum == LOW) { // yeni basıldı
    Serial.println("BASTI");
    digitalWrite(basisLed, HIGH);
    delay(200);
    digitalWrite(basisLed, LOW);
  } else if (durum == LOW && sonDurum == HIGH) { // yeni bırakıldı
    Serial.println("BIRAKTI");
    digitalWrite(birakisLed, HIGH);
    delay(200);
    digitalWrite(birakisLed, LOW);
  }

  sonDurum = durum;
}

// --- SEN YAP ---
// 1) Butona kısa bas-bırak, sonra basılı tut, sonra bırak. Ekranda ve LED'lerde ne
//    sırayla oluyor? BASTI ve BIRAKTI hep sırayla mı geliyor, arka arkaya iki BASTI
//    gördün mü? (Görürsen sebebi bir önceki dersin konusu.)
// 2) `else if` yerine iki ayrı `if` yaz (`else` olmadan). Sonuç değişti mi? Neden
//    böyle? `else if`'in ikinci koşula bakmaktan vazgeçtiği yeri düşün.
// 3) Basışta ekrana "BASTI" yazmanın yanında sayac da artsın; yalnız BASIŞLARI say.
//    Bırakmaları sayan ikinci bir sayaç ekle. İkisi hep eşit mi, biri bir fazla
//    olabilir mi? Ne zaman?
// 4) [ileri] Üçüncü bir durum ekle: "hiçbir şey olmadı" (ikisi de değil) ise hiçbir şey
//    yazma — bunu zaten yapıyoruz, nerede? Kodda bunu yapan satır var mı?
