/*
  BU KOD NE YAPAR?
  Bu kod, 2 numaralı pindeki butona her basışta bir sayıyı 1 artırır (0'dan 15'e, sonra tekrar 0)
  ve sayıyı 3, 5, 6, 9 numaralı pinlerdeki 4 LED'de ikilik (binary) olarak gösterir.
  Sayı Seri Monitör'e de yazılır; kısa bir bekleme butonun titremesini (sıçramasını) geçirir.
*/

/*
  ak0330 — Butonla binary sayıcı: sıçrama (debounce)
  Ne öğreneceğiz: mekanik buton basılırken "titrer" — kart bir basışı birkaç basış
    gibi görebilir; kenar yakalandıktan sonra kısa bir bekleme bu titremeyi geçirir
  Malzeme: Arduino Uno kartı, USB kablosu, Paket 5 devresi (4 LED, pin 3/5/6/9),
    1 buton (pin 2), 1 adet 10 kΩ direnç (pull-down) — ak0190 + ak0320 devreleri aynen
  Devre: Paket 5'in 4 LED'i (pin 3/5/6/9, en sağ pin 9 = 1'ler, en sol pin 3 = 8'ler)
    + pin 2'deki buton (pull-down). Harcama dersi: sayı LED'lerde görünür.

  Şimdilik kara kutu (sonra açacağız):
    void                    -> "fonksiyon" konusunda açılacak
    Serial ve noktalı yazım -> "fonksiyon" konusunda açılacak
  Bunlara şimdilik dokunma, sırası gelince tek tek açacağız.

  kaynak: kendi ak0190 (binary sayıcı, LED kodu aynen) + ak0320 (kenar tetikleme) +
          ..\arsiv\024kirmiziButon\ fikri ("bu süreyi artırıp azaltırsak ne olur?"
          sorusu SEN YAP 1'e ilham oldu; kaynağın delay(200)'ü ve A1 pini taşınmadı).
*/

// --- KAVRAM ---
// Her basışta sayi 1 artar; ak0190'daki gibi 4 LED sayıyı ikilik gösterir (0-15,
// sonra 0). Basışı ak0320'deki kenar tetiklemeyle yakalıyoruz.
// SIÇRAMA: bir butonun metal kontakları birleşirken çok kısa süre açılıp kapanabilir;
// kart bunu birkaç ayrı basış gibi görebilir ve LED'ler BİR SAYI ATLAYABİLİR.
// Bu her butonda, her seferinde olmaz — atladığını gördüysen sebebi sıçramadır.
// Çare: kenar yakalanınca kısa bir delay — titreme geçsin, sonra devam.
const int ledSayisi = 4;
const int ledler[4] = {3, 5, 6, 9}; // 3=8'ler, 5=4'ler, 6=2'ler, 9=1'ler basamağı
const int butonPin = 2;

int sayi = 0;
int durum = LOW;
int sonDurum = LOW;

void setup() {
  Serial.begin(9600);
  pinMode(butonPin, INPUT);
  for (int i = 0; i < ledSayisi; i++) {
    pinMode(ledler[i], OUTPUT);
  }
}

void loop() {
  durum = digitalRead(butonPin);

  if (durum == HIGH && sonDurum == LOW) { // yeni basıldı
    sayi++;
    if (sayi == 16) {
      sayi = 0; // 15'ten sonra baştan başla
    }

    for (int i = 0; i < ledSayisi; i++) {
      digitalWrite(ledler[i], LOW); // önce hepsi sönsün
    }
    if ((sayi % 2) > 0) {
      digitalWrite(ledler[3], HIGH); // 1'ler basamağı
    }
    if ((sayi % 4) > 1) {
      digitalWrite(ledler[2], HIGH); // 2'ler basamağı
    }
    if ((sayi % 8) > 3) {
      digitalWrite(ledler[1], HIGH); // 4'ler basamağı
    }
    if ((sayi % 16) > 7) {
      digitalWrite(ledler[0], HIGH); // 8'ler basamağı
    }

    Serial.print("Sayi: ");
    Serial.println(sayi);

    delay(50); // sıçrama geçsin
  }

  sonDurum = durum;
}

// --- SEN YAP ---
// 1) Butona yavaş yavaş, tek tek bas. LED'ler 0'dan 15'e doğru tek tek mi sayıyor,
//    yoksa arada bir sayı atlıyor mu? Ekrandaki "Sayi:" ile LED'leri karşılaştır.
//    (Atlamayabilir. Görmediysen de "bu denemede görmedim" yaz.)
// 2) `delay(50)` satırını `delay(0)` yap (ya da sil), yükle, yine tek tek bas. Fark
//    var mı? Sonra `delay(500)` yap ve çok hızlı art arda basmayı dene. Ne oluyor?
//    Tahmin yazma, dene ve gözlemle.
// 3) Kaç basışta 15'ten 0'a dönüyor? Kodda bunu yapan satır hangisi?
// 4) 8 LED olsaydı en büyük sayı kaç olurdu? Düşün, defterine yaz.
