/*
  BU KOD NE YAPAR?
  Bu kod, 3, 5, 6, 9 numaralı pinlerdeki 4 LED'de kara şimşek efekti verir. Pinler ardışık olmadığı
  için bir dizide (ledler[]) saklanır ve for döngüsüyle sırayla yakılır.
*/

/*
  ak0185 — Dizi: pinler ardışık olmayınca kara şimşek
  Ne öğreneceğiz: dizi (array) — birden fazla değeri TEK bir isimde, sıra numarasıyla
    saklamak
  Malzeme: Arduino Uno kartı, USB kablosu, 4 LED, 4 adet 220 ohm direnç, breadboard,
    5 jumper kablo
  Devre: 1. LED (+) -> pin 3, 2. LED (+) -> pin 5, 3. LED (+) -> pin 6, 4. LED (+) ->
    pin 9 (soldan sağa); her LED'in kısa bacağı (-) kendi 220 ohm direncine. Dirençlerin
    boş uçları breadboard'ın ORTAK GND hattına takılır (hepsi aynı hat), o hat da TEK
    bir jumper ile Arduino'nun GND pinine bağlanır — LED başına ayrı bir GND jumper'ı
    gerekmez. Toplam: 4 sinyal jumper'ı (pin -> LED) + 1 GND jumper'ı = 5.
    DİKKAT: pinler ARDIŞIK DEĞİL (3, 5, 6, 9) — bu dersin sebebi bu.

  Şimdilik kara kutu (sonra açacağız):
    void   -> "fonksiyon" konusunda açılacak
    OUTPUT -> buton dersinde (ünite 2), INPUT ile birlikte açılacak
  Bunlara şimdilik dokunma, sırası gelince tek tek açacağız.

  kaynak: ..\arsiv\004karaSimsekIleri\004karaSimsekIleri.ino (dizi kullanan hâli,
          ak0140'ta dizisiz uyarlanmıştı — burada dizi GERİ geliyor) + kendi
          ak0140_karaSimsekFor
*/

// --- KAVRAM ---
// SEN YAP 1'i (aşağıda) önce dene, sonra buraya dön: ak0140'taki "ilkLed = 3, sonLed
// = 9" hâlini bu devreye yükleyince desen bozulur, çünkü pin 3'ten 9'a kadar HER sayı
// denenir (3,4,5,6,7,8,9) ama 4, 7 ve 8'de hiç LED yok. Pinler ardışık olmayınca
// "ilk pin, son pin" yetmez; her pini ayrı ayrı bir LİSTEYE yazmamız gerekir. Buna
// dizi denir.
//
// const int ledler[4] = {3, 5, 6, 9}; dört pini TEK bir isimde saklar.
// ledler[0] birinci pin (3), ledler[1] ikinci pin (5)... SIFIRDAN başlar.
const int ledSayisi = 4;
const int ledler[4] = {3, 5, 6, 9};

void setup() {
  for (int i = 0; i < ledSayisi; i++) {
    pinMode(ledler[i], OUTPUT);
  }
}

void loop() {
  // ak0140'taki 1-2-3-4-3-2 deseni, artık ledler[i] ile:
  for (int i = 0; i < ledSayisi; i++) {
    digitalWrite(ledler[i], HIGH);
    delay(300);
    digitalWrite(ledler[i], LOW);
  }
  for (int i = ledSayisi - 2; i >= 1; i--) {
    digitalWrite(ledler[i], HIGH);
    delay(300);
    digitalWrite(ledler[i], LOW);
  }
}

// --- SEN YAP ---
// 1) ÖNCE BUNU DENE (bu dersin kodunu yüklemeden önce): ak0140_karaSimsekFor
//    klasöründeki kodu aç, ilkLed = 3 ve sonLed = 9 yap, BU devreye (pin 3,5,6,9) yükle.
//    Ne oluyor? Desen 4, 7 ve 8'de "boşta bekliyor" gibi davranır, ritim bozulur —
//    çünkü orada LED yok. Bu ACI'yı gördükten sonra bu dersin koduna (yukarıdaki
//    KAVRAM) geç.
// 2) ledler dizisinin sırasını değiştir: {9, 3, 6, 5}. Kodun geri kalanına HİÇ
//    dokunmadan desen nasıl değişti?
// 3) ak0170'le birleştir: her LED digitalWrite yerine analogWrite ile yavaşça
//    parlayıp sönsün (nefes alan kara şimşek) — for (int parlaklik = 0; parlaklik <=
//    255; parlaklik++) { analogWrite(ledler[i], parlaklik); delay(2); } gibi bir
//    döngüyü digitalWrite(ledler[i], HIGH) yerine dene.
