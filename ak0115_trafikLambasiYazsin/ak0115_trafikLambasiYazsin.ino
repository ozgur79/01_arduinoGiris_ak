/*
  ak0115 — Trafik lambası rengini yazsın
  Ne öğreneceğiz: Bildiğimiz trafik lambasına, yanan rengi bilgisayara yazdırma
    katmanı eklemek
  Malzeme: Arduino Uno kartı, USB kablosu, kırmızı LED, sarı LED, yeşil LED,
    3 adet 220 ohm direnç, breadboard, 6 jumper kablo
  Devre: Kırmızı LED uzun bacak (+) -> pin 8, kısa bacak (-) -> 220 ohm direnç -> GND
         Sarı LED uzun bacak (+) -> pin 9, kısa bacak (-) -> 220 ohm direnç -> GND
         Yeşil LED uzun bacak (+) -> pin 10, kısa bacak (-) -> 220 ohm direnç -> GND

  Şimdilik kara kutu (sonra açacağız):
    void                    -> "fonksiyon" konusunda açılacak
    OUTPUT                  -> buton dersinde (ünite 2), INPUT ile birlikte açılacak
    Serial ve noktalı yazım -> "fonksiyon" konusunda açılacak
  Bunlara şimdilik dokunma, sırası gelince tek tek açacağız.

  kaynak: ak0070_trafikLambasi/ak0070_trafikLambasi.ino
          ..\arsiv\kabaMüfredat.docx, 030. madde
*/

// --- KAVRAM ---
// Trafik lambasının bildiğimiz koduna, yanan rengi yazan Serial.println satırları ekliyoruz
// Her renk yazısı, o rengin LED durumları ayarlandıktan hemen sonra gönderilir
// Seri Monitör 9600 hızında açılır; LED ile ekrandaki renk adı aynı anda değişir
const int kirmizi = 8;
const int sari = 9;
const int yesil = 10;

void setup() {
  pinMode(kirmizi, OUTPUT);
  pinMode(sari, OUTPUT);
  pinMode(yesil, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Dur: kırmızı yanar, diğer iki LED söner
  digitalWrite(kirmizi, HIGH);
  digitalWrite(sari, LOW);
  digitalWrite(yesil, LOW);
  Serial.println("KIRMIZI");
  delay(4000);

  // Geç: yeşil yanar, diğer iki LED söner
  digitalWrite(kirmizi, LOW);
  digitalWrite(sari, LOW);
  digitalWrite(yesil, HIGH);
  Serial.println("YESIL");
  delay(3000);

  // Hazırlan: sarı yanar, diğer iki LED söner
  digitalWrite(kirmizi, LOW);
  digitalWrite(sari, HIGH);
  digitalWrite(yesil, LOW);
  Serial.println("SARI");
  delay(1000);
}

// --- SEN YAP ---
// Sarı LED'in 1 saniye yerine 2 saniye yanmasını sağla.
// Seri Monitör'deki SARI yazısının da LED ile aynı anda göründüğünü gözlemle.

// --- MERAK KÖŞESİ ---
// void bu derste neyin önünde duruyor?
// setup listesi seri bağlantıyı hazırlıyor, loop listesi renkleri sırayla çalıştırıyor.
// void, bu iki listenin işini yapıp geriye bir sonuç vermeyeceğini söylüyor.
// void'un ayrıntıları "fonksiyon" konusunda açılacak.
