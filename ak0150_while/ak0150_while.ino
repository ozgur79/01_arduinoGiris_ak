/*
  ak0150 — while: olduğu sürece say
  Ne öğreneceğiz: while döngüsü — ak0130'daki for'un tek satırda topladığı üç parçayı
    (başlangıç, koşul, artış) yeniden ayrı ayrı yazmak
  Malzeme: Arduino Uno kartı, USB kablosu
  Devre: Yok — ekran dersi.

  Şimdilik kara kutu (sonra açacağız):
    void                    -> "fonksiyon" konusunda açılacak
    Serial ve noktalı yazım -> "fonksiyon" konusunda açılacak
  Bunlara şimdilik dokunma, sırası gelince tek tek açacağız.

  kaynak: ..\arsiv\kabaMüfredat.docx, madde 023 (115200 -> 9600, Serial.print+" " ->
          Serial.println; sayac++ ak0130'da açıldığı için aynen kullanıldı)
*/

// --- KAVRAM ---
// ak0130'daki for (başlangıç; koşul; artış) üç parçayı tek satırda topluyordu.
// while bunları geri dağıtır:
//   başlangıç : while'dan ÖNCE, tek satır  -> int sayac = 1;
//   koşul     : while(...) parantezinde     -> sayac <= 10
//   artış     : { } bloğunun İÇİNDE, en son -> sayac++;
// Okunuşu: "sayac 10'dan küçük ya da eşit OLDUĞU SÜRECE, bloğu çalıştır."
void setup() {
  Serial.begin(9600);

  int sayac = 1;
  while (sayac <= 10) {
    Serial.println(sayac);
    delay(500);
    sayac++;
  }
}

void loop() {
  // Bilerek boş: while, setup() içinde 1'den 10'a sayıp duruyor.
}

// --- SEN YAP ---
// 1) sayac++; satırını sil. Kodu yükle, Seri Monitör'ü aç. Ne oldu? (İpucu: koşul hiç
//    yanlış olmuyor — bu "kazara" kurulmuş bir sonsuz döngü. Bir sonraki derste
//    "bilerek" kurulmuş bir sonsuz döngü göreceksin.)
// 2) 10'dan 1'e geriye say (başlangıcı, koşulu ve artışı buna göre çevir: sayac--).
// 3) Aşağıdaki tabloyu kendi kodunla doldur: for'un üç parçası while'da nereye gitti?
//
// | parça | for (ak0130) | while (ak0150) |
// |-------|--------------|-----------------|
// | başlangıç | for(...) satırının 1. bölmesi | while'dan önce, ayrı satır |
// | koşul | for(...) satırının 2. bölmesi | while(...) içinde |
// | artış | for(...) satırının 3. bölmesi | { } bloğunun son satırı |

// --- MERAK KÖŞESİ (ek kutu — Özgür'ün isteğiyle) ---
// Bu kodu ayrı bir deney olarak dene (bu dersin asıl kodu değil):
//   int sayac = 1;
//   while (sayac > 0) { Serial.println(sayac); sayac++; }
// delay yok, "hiç bitmez" gibi görünür. Ama int kutusunun bir sınırı var: en büyük
// değeri 32767. Bir sonraki adımda kutu taşar, sayı -32768'e düşer — o an
// "sayac > 0" YANLIŞ olur ve döngü biter. Her kutunun bir sınırı var.
// (9600 hızında kartta dene, birkaç dakika sürebilir; hesaba göre ~200 bin karakter
// yazılıyor — tam süreyi ölçüp not düş, "kartta doğrulandı" ancak o zaman yazılır.)
