/*
  BU KOD NE YAPAR?
  Bu kod, 2 numaralı pindeki butona her basışta bir sayacı artırıp Seri Monitör'e yazar.
  Ama butona TEK basış sayacı birçok kez artırır — sayaç "kaçar". Nedenini bu derste göreceksin.
*/

/*
  ak0310 — Buton sayacı: sayaç neden kaçıyor?
  Ne öğreneceğiz: loop() çok hızlıdır — TEK bir basışı çok kez "görür". Bir
    basışı bir kez saydırmak için kartı butonun bırakılmasına kadar bekletmek gerekir
  Malzeme: Arduino Uno kartı, USB kablosu, Paket 5 devresi (4 LED, pin 3/5/6/9),
    2 buton (pin 2 ve pin 8), 2 adet 10 kΩ direnç (pull-down) — ak0230'un devresi aynen
  Devre: ak0230'un devresi aynen. Bu derste Buton 1 (pin 2) kullanılıyor, ekran dersi.

  Şimdilik kara kutu (sonra açacağız):
    void                    -> "fonksiyon" konusunda açılacak
    Serial ve noktalı yazım -> "fonksiyon" konusunda açılacak
  Bunlara şimdilik dokunma, sırası gelince tek tek açacağız.

  kaynak: ..\arsiv\046butonSayac_amator\046butonSayac_amator.ino (bu dosya) ve
          ..\arsiv\047butonSayac_pro\047butonSayac_pro.ino (çare, SEN YAP 2).
          Kaynaktaki `while(...);` noktalı virgül ve "el freni" yorumu taşınmadı:
          `{ }` yazıldı (ak0250 kalıbı). pin 2 `buttonPin` -> `butonPin` (Türkçe isim).
*/

// --- KAVRAM ---
// Şimdiye kadar butona basmak "bir olay" gibiydi. Ama kart için bir basış çok uzun
// bir zaman: sen parmağını bir saniye basılı tutsan bile loop() bu sürede çok
// kez baştan başlar ve HER TURDA butonun HIGH olduğunu görür.
// Bu kod "buton HIGH ise sayacı artır" diyor — yani her tur bir kez artırıyor.
// Aşağıdaki kodu yükle, Seri Monitör'ü 9600'de aç, butona BİR KEZ kısa bas ve
// ekrana bak.
const int butonPin = 2;
int sayac = 0;

void setup() {
  pinMode(butonPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(butonPin) == HIGH) {
    sayac++;
    Serial.println(sayac);
  }
}

// --- SEN YAP ---
// 1) Yukarıdaki kodu olduğu gibi yükle, butona BİR KEZ bas ve bırak. Ekranda sayaç
//    kaça çıktı? Tahmin etmeden önce bak, sonra defterine yaz. Neden 1 değil?
// 2) Çaresini kendin yaz: ak0250'deki "butonu BIRAKILANA kadar bekle" kalıbını
//    (while, boş gövde { }) sayacı artırdıktan hemen sonra ekle, loop()'un sonuna
//    da delay(20); koy. Bir basış artık kaç sayıyor?
// 3) İkinci buton (pin 8) için ikinci bir sayaç ekle: Buton 1 kendi sayacını, Buton 2
//    kendi sayacını artırsın. Sonra Buton 1'i BASILI TUT ve Buton 2'ye bas. Buton 2
//    sayılıyor mu? Neden böyle olduğunu defterine yaz (bir sonraki dersin sorusu).
// 4) Sayaç 2 olunca pin 6'daki LED yansın (if (sayac == 2)). Üçüncü basışta ne oluyor?
//    LED'in tekrar sönmesi ve sayma baştan başlaması için ne yapman gerekir?
