/*
  ak0165 — Rastgele kara şimşek: random()
  Ne öğreneceğiz: random(alt, ust) — kart bir sayı "seçer", sen önceden bilemezsin;
    üst sınır DAHİL DEĞİLDİR
  Malzeme: Arduino Uno kartı, USB kablosu, 4 LED, 4 adet 220 ohm direnç, breadboard,
    8 jumper kablo
  Devre: ak0140 ile aynen: 1. LED (+) -> pin 8, 2. LED (+) -> pin 9, 3. LED (+) -> pin 10,
    4. LED (+) -> pin 11; her LED'in kısa bacağı (-) kendi 220 ohm direncine, direncin
    boş ucu GND'ye.

  Şimdilik kara kutu (sonra açacağız):
    void                    -> "fonksiyon" konusunda açılacak
    OUTPUT                  -> buton dersinde (ünite 2), INPUT ile birlikte açılacak
    Serial ve noktalı yazım -> "fonksiyon" konusunda açılacak
  Bunlara şimdilik dokunma, sırası gelince tek tek açacağız.

  kaynak: kaba müfredat madde 025 (kodu yok, fikir kaynağı: 1-100 arası rastgele 10
          sayı); devre ak0140_karaSimsekFor/ak0140_karaSimsekFor.ino'dan aynen alındı
*/

// --- KAVRAM ---
// Önce ekranda zar atalım: random(1, 7) 1'den 6'ya bir sayı üretir. DİKKAT: üst sınır
// (7) HİÇ GELMEZ — random(alt, ust), alt DAHİL, ust HARİÇ bir sayı verir.
const int ilkLed = 8;
const int sonLed = 11;

void setup() {
  Serial.begin(9600);
  delay(2500); // Seri Monitör'ü açman için birkaç saniye bekleniyor — açmadan
               // önce yüklenen kodlar Seri Monitör açık değilken yazılır ve kaybolur

  for (int pin = ilkLed; pin <= sonLed; pin++) {
    pinMode(pin, OUTPUT);
  }

  for (int atis = 1; atis <= 5; atis++) {
    int zar = random(1, 7); // 1,2,3,4,5,6 gelir; 7 hiç gelmez
    Serial.print("Zar: ");
    Serial.println(zar);
    delay(500);
  }
}

void loop() {
  // Aynı alet şimdi LED'e gidiyor: random(8, 12) -> 8, 9, 10 ya da 11 gelir, 12 hiç
  // gelmez. Hangi pin seçildiyse o LED yanar, seri port hangisi olduğunu yazar.
  int secilenPin = random(ilkLed, sonLed + 1);
  digitalWrite(secilenPin, HIGH);
  Serial.print("LED: ");
  Serial.println(secilenPin);
  delay(1500);             // LED yanık kalsın, göz hangi pin olduğunu seçebilsin
  digitalWrite(secilenPin, LOW);
  delay(200);              // kısa bir karanlık an: bir sonraki LED'den ayrı görünsün
}

// --- SEN YAP ---
// 1) loop() içindeki delay(1500) yerine random(100, 500) kullan — her seferinde
//    farklı bir bekleme süresi olsun.
// 2) setup() içindeki zar atma döngüsünü değiştir: 1'den 100'e kadar rastgele 10 sayı
//    yazdır (random(1, 101)).
// 3) Kartı yükledikten sonra RESETLE (kartın üzerindeki reset düğmesine bas) ve
//    zarları tekrar oku. Aynı sırayla mı geldiler? Not al.
// 4) SORU: Zarlar neden her resette AYNI sırayla geliyor? Kartın "rastgele" bir sayı
//    seçtiğini düşünüyorsan bu şaşırtıcı olmalı. Önce kendi tahminini yaz, sonra
//    Merak Köşesi'ni oku ve tahminini karşılaştır.
//
// Not: Aynı LED art arda iki kez seçilebilir — bu bir hata değil, rastgelelik böyle
// çalışır.

// --- MERAK KÖŞESİ (ek kutu) ---
// Kartı resetleyip zarları tekrar okuduysan fark etmişsindir: sıra hep AYNI geliyor.
// Kart aslında hiçbir şeyi "rastgele seçmiyor" — önceden hazırlanmış, çok uzun bir
// sayı listesinden sırayla okuyor ve bu liste her açılışta aynı yerden başlıyor.
// Gerçekten her seferinde farklı bir sırayla başlamak için kart, dışarıdan gerçek bir
// "gürültü" almalı (randomSeed + analogRead ile). analogRead henüz bizim kara
// kutumuz değil — analog giriş dersinde açılacak.
