/*
  ak0120 — Sayaç: kart saysın, ekrana yazsın
  Ne öğreneceğiz: Programı çalışırken değeri değişebilen bir isim — değişken — kullanmak
  Malzeme: Arduino Uno kartı, USB kablosu
  Devre: Yok — bu bir ekran dersi, yalnızca kart ve USB kablosu yeter.

  Şimdilik kara kutu (sonra açacağız):
    void                    -> "fonksiyon" konusunda açılacak (temel düzeyin ilerisinde, numarası o tur belirlenecek)
    Serial ve noktalı yazım -> "fonksiyon" konusunda açılacak
  Bunlara şimdilik dokunma, sırası gelince tek tek açacağız.

  kaynak: ..\arsiv\009ak120ham\009ak120ham.ino (Özgür yazdı; 115200 -> 9600,
          sayac++ -> sayac = sayac + 1 [++ ak0130'da açılıyor],
          Serial.print(sayac); Serial.print(" "); -> Serial.println(sayac);)
*/

// --- KAVRAM ---
// ak0050'deki const int, değeri hiç değişmeyen bir isimdi. Değişken tam tersi:
// değeri program çalışırken değişebilen bir isim. const yazmazsan isim değişebilir.
// sayac = sayac + 1; matematikteki eşitlik değil: önce eşittirin SAĞI hesaplanır
// (sayac'ın şu anki değerine 1 eklenir), sonra sonuç yeniden sayac'ın İÇİNE konur.
int sayac = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  sayac = sayac + 1;
  Serial.println(sayac);
  delay(1000);
}

// --- SEN YAP ---
// 1) sayac = sayac + 1; satırını sayac = sayac + 2; yap. Seri Monitör'de ne değişti?
// 2) int sayac = 0; satırını int sayac = 100; yap. Sayma nereden başladı?
// 3) delay(1000); değerini değiştir. Sayıların ekrana çıkma hızı nasıl değişti?

// --- MERAK KÖŞESİ ---
// Serial.begin(9600); ve Serial.println(sayac); satırlarındaki nokta ne işe yarıyor?
// Serial, kartın "bilgisayarla konuşma" yeteneğinin adı. Nokta, o yeteneğe "şunu yap"
// demenin yolu: Serial.begin(...) bağlantıyı açar, Serial.println(...) bir satır yazı
// gönderir. Noktanın tam ayrıntısı "fonksiyon" konusunda açılacak (1. tur).
