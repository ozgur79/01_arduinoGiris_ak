/*
  ak0160 — Tek sayılar: if + %
  Ne öğreneceğiz: if (koşul doğruysa çalış) ve % (kalan) — ikisi birlikte, % burada
    if'in koşulunu kurmak için bir alet
  Malzeme: Arduino Uno kartı, USB kablosu
  Devre: Yok — ekran dersi (ak0155 LED'di, ritim tutuyor).

  Şimdilik kara kutu (sonra açacağız):
    void   -> "fonksiyon" konusunda açılacak
    OUTPUT -> buton dersinde (ünite 2), INPUT ile birlikte açılacak
  Bunlara şimdilik dokunma, sırası gelince tek tek açacağız.

  kaynak: ..\arsiv\kabaMüfredat.docx, madde 024 (115200 -> 9600, Serial.print+" " ->
          Serial.println, "->" oku ASCII'ye çevrildi; kaynak loop() içinde while(1)
          kullanıyordu, burada sayaç doğrudan loop()'a bırakıldı ve global yapıldı —
          loop() zaten kendi başına sonsuz döngü, ikinci bir while(true) eklemek
          ak0155'te öğrendiğimiz fikri gereksiz yere tekrarlardı. "int sayac" loop()
          içinde olsaydı her turda 1'e sıfırlanırdı; bu yüzden setup()'ın dışında,
          global tanımlandı.)
*/

// --- KAVRAM ---
// % (kalan) bir bölmenin kalanını verir. 7 % 2 = 1 (7'yi 2'ye böl, kalan 1);
// 8 % 2 = 0 (8'i 2'ye böl, kalan 0). Kalan hep 0 ise sayı ÇİFT, değilse TEK'tir.
// if (koşul) { } koşul DOĞRUYSA içindeki blok çalışır, YANLIŞSA atlanır — else yok,
// bu derste "değilse ne olacağı" hiç yazılmıyor.
// sayac % 2 != 0, "sayac'ın 2'ye bölümünden kalan sıfıra eşit DEĞİLSE" demektir;
// aynı şeyi sayac % 2 == 1 diye de yazabilirsin (kalan tam olarak 1'e eşitse).
int sayac = 1;

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (sayac % 2 != 0) {
    Serial.println(sayac);
  }
  sayac++;
  delay(200);
}

// --- SEN YAP ---
// 1) Yalnız çift sayıları yazdır (koşulu değiştir, else ekleme).
// 2) Yalnız 3'e tam bölünen sayıları yazdır (sayac % 3 == 0).
// 3) 5'e tam bölünen sayılarda "BOM" yazdır, diğer sayılarda hiçbir şey yazma
//    (yine else kullanmadan, tek bir if ile).

// --- MERAK KÖŞESİ ---
// Serial.println bu kez bir if'in İÇİNDE duruyor, farkı ne?
// Önceki derslerde Serial.println her turda çalışıyordu. Burada if'in süslü
// parantezinin içinde olduğu için sadece koşul (sayac % 2 != 0) doğruyken çalışır —
// yanlışken o satıra hiç sıra gelmez, satır atlanır. Nokta işaretinin ayrıntısı hâlâ
// "fonksiyon" konusunda (3. tur, bundan sonra emekli).
