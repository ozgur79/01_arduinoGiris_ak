/*
  ak0060 — Kara şimşek (elle)
  Ne öğreneceğiz: Dört LED'i sırayla yakıp söndürerek gidip gelen bir ışık deseni
    kurmak — ve bunu elle yazınca kodun ne kadar uzadığını görmek
  Malzeme: Arduino Uno kartı, USB kablosu, 4 LED, 4 adet 220 ohm direnç, breadboard,
    8 jumper kablo
  Devre: 1. LED uzun bacak (+) -> pin 8,  kısa bacak (-) -> 220 ohm direnç -> GND
         2. LED uzun bacak (+) -> pin 9,  kısa bacak (-) -> 220 ohm direnç -> GND
         3. LED uzun bacak (+) -> pin 10, kısa bacak (-) -> 220 ohm direnç -> GND
         4. LED uzun bacak (+) -> pin 11, kısa bacak (-) -> 220 ohm direnç -> GND
         LED'leri breadboard'a soldan sağa, yan yana diz.

  Şimdilik kara kutu (sonra açacağız):
    void    -> "fonksiyon" konusunda açılacak (temel düzeyin ilerisinde, numarası o tur belirlenecek)
    OUTPUT  -> buton dersinde (ünite 2), INPUT ile birlikte açılacak (numarası o tur belirlenecek)
  Bunlara şimdilik dokunma, sırası gelince tek tek açacağız.

  kaynak: D:\ArduinoProjeleri\002Arduino\004karaSimsek (pin 13/12/11/10 -> 8/9/10/11
          taşındı; pin 13'te kartın dahili LED'i var. Ayrıca kaynakta desen 7 adımdı ve
          son adım ilk adımla aynıydı, bu yüzden 1. LED her turda iki kat uzun yanıyordu
          — 6 adıma indirilip düzeltildi.)
*/

// --- KAVRAM ---
// Dört LED'i dört ayrı pine bağlarsan dördünü de ayrı ayrı yönetebilirsin
// Her adımda dört LED'in de ne yapacağını tek tek yazıyoruz: biri HIGH, üçü LOW
// Desen gidip geliyor: 1-2-3-4-3-2, sonra baştan
const int led1 = 8;
const int led2 = 9;
const int led3 = 10;
const int led4 = 11;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
}

void loop() {
  // 1. adım: sadece led1 yanık
  digitalWrite(led1, HIGH);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  delay(300);

  // 2. adım: sadece led2 yanık
  digitalWrite(led1, LOW);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  delay(300);

  // 3. adım: sadece led3 yanık
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, LOW);
  delay(300);

  // 4. adım: sadece led4 yanık (sağ uca vardık)
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, HIGH);
  delay(300);

  // 5. adım: geri dönüyoruz, sadece led3 yanık
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, LOW);
  delay(300);

  // 6. adım: sadece led2 yanık; buradan sonra loop başa döner ve led1 yanar
  digitalWrite(led1, LOW);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  delay(300);
}

// --- SEN YAP ---
// 1) Deseni ters yönde başlat: ışık soldan değil sağdan başlasın (led4'ten led1'e
//    gidip geri dönsün). Kaç satırın yerini değiştirmen gerekti?
// 2) Beşinci bir LED eklesen (pin 12), loop() içine kaç satır eklemen gerekirdi?
//    Önce tahmin et, defterine yaz; sonra tek tek sayarak kontrol et. (Devreyi
//    kurmana gerek yok, bu bir sayma görevi.)
// 3) Bekleme süresini 300'den 100'e düşür. Kaç satıra dokunman gerekti? Şimdi ak0050'de
//    öğrendiğin şeyi hatırla: bunu tek satırdan değiştirilebilir hâle getirebilir misin?
//
// Not: Bu dersin kodu uzun ve satırların çoğu birbirinin neredeyse aynısı. Yazarken
// hissettiğin o rahatsızlık haklı — aynı deseni çok daha kısa yazmanın bir yolu var.
// Onu seri port ünitesinde öğreneceğiz ve bu devreye geri dönüp aynı işi birkaç
// satırda yapacağız.
