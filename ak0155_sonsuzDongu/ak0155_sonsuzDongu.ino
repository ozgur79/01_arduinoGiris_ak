/*
  ak0155 — Sonsuz döngü: loop() aslında ne? (harcama)
  Ne öğreneceğiz: Yeni fikir yok, bilerek: loop() aslında kartın senin yerine yazdığı
    sonsuz bir döngüdür. while (true) ile aynı döngüyü kendi ellerinle yazacaksın.
  Malzeme: sadece Arduino Uno kartı (USB kablosuyla bağlı)
  Devre: Yok — ak0010'daki dahili LED (pin 13), yeni malzeme yok.

  Şimdilik kara kutu (sonra açacağız):
    void   -> "fonksiyon" konusunda açılacak
    OUTPUT -> buton dersinde (ünite 2), INPUT ile birlikte açılacak
  Bunlara şimdilik dokunma, sırası gelince tek tek açacağız.

  kaynak: yok — kendi ak0010_dahiliLed kodun, while (true) bloğunun içine taşındı,
          loop() boş bırakıldı
*/

// --- KAVRAM ---
// loop() zaten kartın senin yerine yazdığı bir sonsuz döngüdür: setup() bitince
// baştan tekrar tekrar çalışır, sen ona "dur" demedikçe durmaz.
// while (true), koşulu HİÇ yanlış olmayan bir döngüdür — true (doğru) hep doğru
// olduğu için asla durmaz. Bu derste sonsuz döngüyü artık kartın kendisi değil,
// sen kuruyorsun.
void setup() {
  pinMode(13, OUTPUT);

  while (true) {
    digitalWrite(13, HIGH);
    delay(1000);
    digitalWrite(13, LOW);
    delay(1000);
  }
}

void loop() {
  // Bilerek boş: sonsuz döngüyü artık setup() içinde kendin yazdın, loop()'a hiç
  // sıra gelmiyor.
}

// --- SEN YAP ---
// 1) Bu kodu ak0010'daki koduyla yan yana koy. İkisi de kartta aynı şeyi mi yapıyor?
//    Hangi satırlar loop()'tan setup()'a taşındı?
// 2) setup() içine en başa Serial.begin(9600); ekle. while (true) bloğunun ALTINA
//    (hâlâ setup() içinde, döngüden SONRA) Serial.println("BITTI"); ekle. Kartta
//    yükle, Seri Monitör'ü aç. "BITTI" hiç görünmüyor — neden?
// 3) while (true) satırını while (false) yap. Ne oluyor? (LED hiç yanmaz — "hiçbir
//    zaman doğru olmayan" bir döngünün içine hiç girilmez.)
//
// Şu soruyu defterine yaz, cevabını arama: Bu döngüden nasıl çıkılır? Cevabı iki
// ünite sonra (butonla) göreceğiz.

// --- MERAK KÖŞESİ ---
// Neden while (1) değil while (true) yazdık?
// İkisi de aynı işi yapar: Arduino'da 1, sıfırdan farklı her sayı gibi "doğru" sayılır,
// bu yüzden while (1) de hiç bitmeyen bir döngü kurar. true kelimesi doğrudan "doğru"
// demek, okurken kafa karıştırmaz. Başka kodlarda while (1) da görebilirsin (örneğin
// bir sonraki derste) — ikisi aynı şeyi söylüyor, biri sayı diliyle, biri kelimeyle.
