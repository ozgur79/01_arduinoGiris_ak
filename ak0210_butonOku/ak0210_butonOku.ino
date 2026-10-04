/*
  ak0210 — Buton: INPUT, digitalRead, pull-down
  Ne öğreneceğiz: kart şimdiye kadar hep DIŞARI yazıyordu (OUTPUT); şimdi bir pin
    İÇERİYİ okuyor (INPUT) — digitalRead() bu pinin HIGH mi LOW mu olduğunu söyler
  Malzeme: Arduino Uno kartı, USB kablosu, Paket 5 devresi (4 LED, pin 3/5/6/9,
    aynen), 1 buton, 1 adet 10 kΩ direnç (pull-down)
  Devre: Paket 5 devresi sökülmez. Yeni: buton bir bacağı 5V'a, öbür bacağı hem
    pin 2'ye hem 10 kΩ direnç üzerinden GND'ye bağlanır (pull-down). Basılı = HIGH,
    bırakılmış = LOW. Bu derste sadece pin 6'daki LED kullanılıyor.

  Şimdilik kara kutu (sonra açacağız):
    void -> "fonksiyon" konusunda açılacak
  (OUTPUT bu derste INPUT ile birlikte GERÇEKTEN açıldı, artık kara kutu değil.)

  kaynak: ..\arsiv\010butonLedKolay\010butonLedKolay.ino — kaynakta iki hata vardı,
          hiçbiri taşınmadı: (1) digitalRead(2)==0 basılıyı 0 sayıyordu (pull-up
          devresinin mantığı); bizim devremiz pull-down, basılı = HIGH, bu yüzden
          ==HIGH yapıldı. (2) Yorum "bıraksan da yanmaya devam eder" diyordu ama kod
          her turda LED'i önce söndürüyor, bu doğru değildi; yorum silindi. Pin
          adları (6, 2) butonPin/ledPin isimlerine bağlandı (ak0050 köprüsü).
*/

// --- KAVRAM ---
// pinMode() bir pine GÖREV verir: OUTPUT (bu pin dışarı yazacak) ya da INPUT
// (bu pin içeriyi okuyacak). Şimdiye kadar hep OUTPUT kullandık (LED'e yazdık);
// burada ilk kez INPUT kullanıyoruz — butonu OKUYORUZ.
// digitalRead(pin), o pinin şu an HIGH mi LOW mu olduğunu söyler — digitalWrite'ın
// tam tersi: digitalWrite biz karara veririz, digitalRead kart bize söyler.
// Bizim devremizde (pull-down): buton BASILI iken pin HIGH, BIRAKILMIŞ iken LOW.
const int butonPin = 2;
const int ledPin = 6;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(butonPin, INPUT);
}

void loop() {
  digitalWrite(ledPin, LOW); // önce söndür (else henüz yok, ak0160'taki gibi)

  if (digitalRead(butonPin) == HIGH) { // butona basıldı mı?
    digitalWrite(ledPin, HIGH); // basılıysa yak
  }
}

// --- SEN YAP ---
// 1) 10 kΩ direnci SÖK (pin 2'yi "havada" bırak). setup()'a Serial.begin(9600);
//    ekle, loop()'a Serial.println(digitalRead(butonPin)); koy (ak0199'daki
//    "değeri yazdırıp bak" yöntemi). Butona hiç dokunmadan Seri Monitör'de ne
//    görüyorsun? (Kartına göre değişebilir — "kesin şu olur" diye bir şey yok,
//    havada kalan bir pin dokunulmadığında zıplayabilir.) Sonra direnci geri tak,
//    fark neydi?
// 2) Devredeki başka bir LED'i (pin 3, 5 ya da 9) de aynı butonla yak.
// 3) [ileri] `if (digitalRead(butonPin) == HIGH)` yerine `if (digitalRead(butonPin))`
//    yazılsa ne olurdu? (İpucu: HIGH'ın kendisi zaten "doğru" sayılan bir değerdir.)
