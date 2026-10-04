/*
  ak0197 — Serial.read: klavyeden komutla LED
  Ne öğreneceğiz: seri port İKİ YÖNLÜ — kart şimdiye kadar hep yazdı, şimdi
    DİNLİYOR da; Serial.read() ile Seri Monitör'e yazdığın harfi okuyup LED'i ona
    göre yakıp söndürme
  Malzeme: Arduino Uno kartı, USB kablosu, Paket 5 devresindeki 4 LED'den biri
    (pin 9) — yeni jumper gerekmez
  Devre: ak0185/ak0190/ak0195'in devresi (4 LED, pin 3/5/6/9, ortak GND hattı)
    kuruluysa dokunma. Sıfırdan kuruyorsan: 1 LED (+) -> pin 9, kısa bacak (-) ->
    220 ohm direnç -> breadboard'ın ortak GND hattı -> TEK jumper ile Arduino GND.

  Şimdilik kara kutu (sonra açacağız):
    void   -> "fonksiyon" konusunda açılacak
    OUTPUT -> buton dersinde (ünite 2), INPUT ile birlikte açılacak
  Bunlara şimdilik dokunma, sırası gelince tek tek açacağız.

  kaynak: D:\ArduinoProjeleri\002Arduino\080bluetoothArd\080bluetoothArd.ino ->
          ..\arsiv\080bluetoothArd\080bluetoothArd.ino (KOPYALANDI, taşınmadı).
          Bluetooth modülü hiç taşınmadı, yalnız Serial.read() okuma kalıbı alındı.
          Kaynakta '0' LED'i yakıyor, '1' söndürüyordu (isimle ters, kafa
          karıştırıcı) -> burada '1' yak, '0' söndür yapıldı (sezgisel yön).
          Kaynağın "while (Serial.available() > 0)" döngüsü "if (Serial.available()
          > 0)" yapıldı — while ak0150'de açık ama tek harf okumak için daha az yeni
          şey taşıyor. "led" değişken adı "ledPin" yapıldı (projedeki adlandırma).
*/

// --- KAVRAM ---
// Serial.available(), kutuda (kartın seri tamponunda) okunmayı bekleyen bir harf
// var mı diye SORAR — varsa 0'dan büyük, yoksa 0 döner.
// Serial.read(), kutudaki BİR harfi okur; bu harfi char (tek karakter tutan bir
// kutu türü, "character") tipinde bir değişkende saklarız.
// '1' ve '0' TEK TIRNAKLIDIR — bu bir char'dır. "1" (çift tırnaklı) bir YAZI
// (String) olurdu ve char ile hiç eşleşmez.
// Aşağıda bir if'in İÇİNDE iki if daha var (iç içe if) — ak0180'de bir for'un
// içine for koymayı öğrenmiştin, burada aynı fikir if ile: dıştaki if önce
// "okunacak bir şey var mı" diye sorar, VARSA içindeki iki if hangi harf
// geldiğine ('1' mi '0' mı) bakar.
char gelenKarakter;
const int ledPin = 9; // Paket 5 devresindeki 4 LED'den biri

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    gelenKarakter = Serial.read();

    if (gelenKarakter == '1') {
      digitalWrite(ledPin, HIGH);
    }

    if (gelenKarakter == '0') {
      digitalWrite(ledPin, LOW);
    }
  }
}

// --- SEN YAP ---
// 1) Seri Monitör'ü aç, hızı 9600 seç. Üstteki kutuya 1 yaz, gönder tuşuna bas
//    (ya da Enter) — pin 9'daki LED yanmalı. 0 yaz, gönder — sönmeli.
// 2) Üçüncü bir if ekle: '2' gönderilince pin 3'teki LED de yansın (pinMode'u
//    setup()'a eklemeyi unutma).
// 3) ak0185'teki ledler dizisini buraya taşı ({3, 5, 6, 9}); 'a' gönderilince
//    dizideki dört LED'in HEPSİ birden yansın (for ile, ak0185'teki gibi).
