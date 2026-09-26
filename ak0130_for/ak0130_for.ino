/*
  ak0130 — for: sayma işini tek satıra topla
  Ne öğreneceğiz: for döngüsü — ak0120'de dağınık duran üç parçayı (başlangıç, koşul,
    artış) tek satırda toplamak
  Malzeme: Arduino Uno kartı, USB kablosu
  Devre: Yok — üst üste ikinci ve son ekran dersi, ondan sonra LED'e döneceğiz.

  Şimdilik kara kutu (sonra açacağız):
    void                    -> "fonksiyon" konusunda açılacak
    Serial ve noktalı yazım -> "fonksiyon" konusunda açılacak
  Bunlara şimdilik dokunma, sırası gelince tek tek açacağız.

  kaynak: ..\arsiv\002for1den100e\002for1den100e.ino (0'dan 255'e, 1000 ms -> 1'den 10'a,
          500 ms; kullanılmayan "int degisken;" satırı silindi; "Sayaç Değeri: " ASCII'ye
          çevrildi: "Sayac: ")
*/

// --- KAVRAM ---
// ak0120'de sayacın üç parçası koddaki üç ayrı yerde duruyordu:
//   başlangıç : int sayac = 0;      (setup'ın dışında, bir kere)
//   artış     : sayac = sayac + 1;  (loop içinde, her turda)
//   durma     : yoktu — sayaç hiç durmadan sayıyordu
// for bu üç parçayı TEK satırda toplar: for (başlangıç; koşul; artış)
// Koşul doğru olduğu sürece döngü içindeki { } bloğu tekrar tekrar çalışır.
// sayac++ , sayac = sayac + 1; ile aynı işi yapar — sadece kısa yazılışı.
void setup() {
  Serial.begin(9600);

  for (int sayac = 1; sayac <= 10; sayac++) {
    Serial.print("Sayac: ");
    Serial.println(sayac);
    delay(500);
  }
}

void loop() {
  // Bilerek boş: for, setup() içinde bir kez çalışıp duruyor. SEN YAP'ta bunu
  // loop() içine taşıyıp farkı göreceksin.
}

// --- SEN YAP ---
// 1) for satırını loop() içine taşı (setup() boş kalsın). Ne değişti? Sayma neden
//    hiç durmuyor?
// 2) 10'dan 1'e geriye say (artış yerine sayac--, koşulu buna göre çevir).
// 3) 0'dan 100'e beşer beşer say (artışı sayac = sayac + 5 ya da sayac += 5 yap).
//
// Not: Bu dersin kodu ak0120'nin üç ayrı satırını tek satıra topladı. Sıradaki
// derste (ak0140) aynı kısaltmayı bir LED devresinde kullanıp ak0060'ın uzun
// kodunu kısaltacağız.

// --- MERAK KÖŞESİ ---
// Bu derste ilk kez Serial.print ile Serial.println yan yana durdu, farkı ne?
// Serial.print("Sayac: ") yazdıktan sonra imleç aynı satırda kalır; Serial.println(sayac)
// sayıyı yazıp imleci bir alt satıra indirir. İkisi ard arda kullanılınca "Sayac: 3" gibi
// tek satırlık bir yazı ortaya çıkar. Noktanın ayrıntısı hâlâ "fonksiyon" konusunda
// (2. tur).
