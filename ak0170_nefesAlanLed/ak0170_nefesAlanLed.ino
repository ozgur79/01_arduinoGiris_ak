/*
  ak0170 — Nefes alan LED: analogWrite (PWM)
  Ne öğreneceğiz: analogWrite — LED yalnız açık/kapalı değil, ARASI da var (0-255)
  Malzeme: Arduino Uno kartı, USB kablosu, 1 LED, 1 adet 220 ohm direnç, breadboard,
    2 jumper kablo
  Devre: LED uzun bacak (+) -> pin 11 (~), kısa bacak (-) -> 220 ohm direnç -> GND.
    Pin 11'in yanındaki ~ işareti önemli: Uno'da yalnız ~ işaretli pinler (3, 5, 6, 9,
    10, 11) analogWrite yapabilir. Pin 8'de bu ders çalışmaz.

  Şimdilik kara kutu (sonra açacağız):
    void   -> "fonksiyon" konusunda açılacak
    OUTPUT -> buton dersinde (ünite 2), INPUT ile birlikte açılacak
  Bunlara şimdilik dokunma, sırası gelince tek tek açacağız.

  kaynak: ..\arsiv\002ledParlaklik\002ledParlaklik.ino — üç düzeltme yapıldı:
          (1) analogWrite(11, ...) -> analogWrite(led, ...) (ak0050 kuralı, const int
          isim varken çıplak pin numarası yazılmaz), (2) aralık 0-200 -> 0-255 (tam
          aralık), (3) iniş delay(20) ile çıkış delay(10) farklıydı ve yorum satırı
          yanlıştı ("20 milisaniye" yerine "10 milisaniye" yazıyordu) -> ikisi de
          delay(10) yapılıp nefes alma/verme aynı hızda eşitlendi.
*/

// --- KAVRAM ---
// digitalWrite bir pini sadece HIGH ya da LOW yapabiliyordu — açık ya da kapalı.
// analogWrite ARADAKİ değerleri de verebilir: 0 (tamamen sönük) ile 255 (tamamen
// parlak) arasında herhangi bir sayı. Bu, ~ işaretli pinlerde çalışan özel bir
// yetenektir (PWM — ayrıntısı İleri Analiz'de).
const int led = 11;

void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
  // Nefes al: 0'dan 255'e parlaklık artar
  for (int parlaklik = 0; parlaklik <= 255; parlaklik++) {
    analogWrite(led, parlaklik);
    delay(10);
  }
  // Nefes ver: 255'ten 0'a parlaklık azalır
  for (int parlaklik = 255; parlaklik >= 0; parlaklik--) {
    analogWrite(led, parlaklik);
    delay(10);
  }
}

// --- SEN YAP ---
// 1) LED %50 parlaklığa (analogWrite değeri 127) çıksın, sonra birden ve tamamen
//    sönsün (digitalWrite(led, LOW) ya da analogWrite(led, 0)) — nefes alma var,
//    nefes verme yok.
// 2) İkinci bir LED (başka bir ~ pinine, ör. pin 10) ekleyip ters nefes aldır: biri
//    parlarken öteki sönsün (ikinci LED'in parlaklığı: 255 - parlaklik).
// 3) delay(10) değerlerini değiştir. Nefes alma/verme ne kadar hızlandı ya da yavaşladı?
