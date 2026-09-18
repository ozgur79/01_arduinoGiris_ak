/*
  ak0110 — LED durumunu yaz
  Ne öğreneceğiz: Kartın, LED yanarken ve sönerken bilgisayara yazı gönderebildiğini görmek
  Malzeme: Arduino Uno kartı, USB kablosu, 1 LED, 1 adet 220 ohm direnç, breadboard,
    2 jumper kablo
  Devre: LED'in uzun bacağı (+) -> Arduino pin 8
         LED'in kısa bacağı (-) -> 220 ohm direnç -> Arduino GND

  Şimdilik kara kutu (sonra açacağız):
    void                    -> "fonksiyon" konusunda açılacak
    OUTPUT                  -> buton dersinde (ünite 2), INPUT ile birlikte açılacak
    Serial ve noktalı yazım -> "fonksiyon" konusunda açılacak
  Bunlara şimdilik dokunma, sırası gelince tek tek açacağız.

  kaynak: ..\arsiv\000seri06ledYandiSondu\000seri06ledYandiSondu.ino
          (pin 6 -> 8 taşındı; Serial.print -> Serial.println düzeltildi.)
*/

// --- KAVRAM ---
// Kart çalışırken bilgisayara yazı gönderebilir; yazıları Seri Monitör'de görürüz
// 9600, kart ile Seri Monitör'ün aynı konuşma hızıdır; monitörde de 9600 seçilir
// Serial.println, tırnak içindeki yazıyı gönderir ve sonraki yazı için yeni satıra geçer
// Bu kartta seri port pin 0 ve 1'i kullanır; LED'leri bu yüzden pin 8'den yukarı bağlarız
void setup() {
  pinMode(8, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(8, HIGH);
  Serial.println("YANDI");
  delay(1000);

  digitalWrite(8, LOW);
  Serial.println("SONDU");
  delay(1000);
}

// --- SEN YAP ---
// LED'in 2 saniye yanık, yarım saniye sönük kalmasını sağla.
// Seri Monitör'de YANDI yerine ISIK ACIK, SONDU yerine ISIK KAPALI yazdır.
// LED ile ekrandaki yazının aynı anda değiştiğini gözlemle.
