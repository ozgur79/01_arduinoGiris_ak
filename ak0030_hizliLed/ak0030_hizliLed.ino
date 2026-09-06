/*
  ak0030 — LED'i hızlandır
  Ne öğreneceğiz: Yanıp sönmeyi hızlandırmanın bir sınırı vardır; o sınırdan sonra göz
    sönmeyi ayırt edemez ve LED sürekli yanıyormuş gibi görünür
  Malzeme: Arduino Uno kartı, USB kablosu, 1 LED, 1 adet 220 ohm direnç, breadboard,
    2 jumper kablo (ak0020'nin devresi aynen kullanılır, sökmene gerek yok)
  Devre: LED'in uzun bacağı (+) -> Arduino pin 8
         LED'in kısa bacağı (-) -> 220 ohm direnç -> Arduino GND

  Şimdilik kara kutu (sonra açacağız):
    void    -> "fonksiyon" konusunda açılacak (temel düzeyin ilerisinde, numarası o tur belirlenecek)
    OUTPUT  -> buton dersinde (ünite 2), INPUT ile birlikte açılacak (numarası o tur belirlenecek)
  Bunlara şimdilik dokunma, sırası gelince tek tek açacağız.

  kaynak: arsiv/002ledYak/002ledYak.ino (bekleme süresi 500 ms)
         + arsiv/kabaMüfredat.docx, "saniyede 1/5/10/25 kez" hız merdiveni
*/

// --- KAVRAM ---
// delay() içindeki sayı milisaniye cinsindendir: 1000 bir saniye, 500 yarım saniyedir
// delay() içindeki sayı küçüldükçe LED daha sık yanıp söner
// Bir tam tur (bir yanma + bir sönme) iki delay() sürer: 500 + 500 = bir saniye,
// yani LED saniyede 1 kez yanıp sönüyor
void setup() {
  pinMode(8, OUTPUT); // 8. pini, açıp kapatabileceğimiz bir pin yap
}

void loop() {
  digitalWrite(8, HIGH); // 8. pini aç -> LED yanar
  delay(500);            // yarım saniye yanık kal
  digitalWrite(8, LOW);  // 8. pini kapat -> LED söner
  delay(500);            // yarım saniye sönük kal
}

// --- SEN YAP ---
// 1) LED'i sırayla şu hızlarda yakıp söndür. Her hız için iki delay() satırındaki sayıyı
//    İKİSİNİ BİRDEN değiştir, karta yükle ve LED'e bak:
//       saniyede  1 kez  ->  delay(500)
//       saniyede  5 kez  ->  delay(100)
//       saniyede 10 kez  ->  delay(50)
//       saniyede 25 kez  ->  delay(20)
//       saniyede 50 kez  ->  delay(10)
// 2) Hangi hızdan sonra LED'in söndüğünü artık göremiyorsun, sürekli yanıyor gibi
//    görünüyor? O hızı defterine yaz.
// 3) Bulduğun hızı bir arkadaşınınkiyle karşılaştır. Aynı hızı mı buldunuz?

// --- MERAK KÖŞESİ ---
// void ne demek?
// setup ve loop birer "iş listesi". void, listenin adının önünde durur ve "bu liste
// bitince geriye bir sonuç vermeyecek" der. Bu derste listelerin içindeki sayıyı
// değiştirdin, adlarına hiç dokunmadın.
// Listenin kendisini "fonksiyon" dersinde açacağız.
