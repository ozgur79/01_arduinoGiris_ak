/*
  ak0060 — çözüm örneği

  SEN YAP 1) İki yol var ve dersin asıl kazancı ikisinin farkında.
    Zor yol: loop() içindeki 6 adımın hepsini yeniden yazmak — 12 satır düzeltilir
    (her adımda bir HIGH bir LOW yer değiştirir).
    Kolay yol: loop()'a hiç dokunmadan sadece dört const int satırını ters çevirmek —
    4 satır. Kod aynı kalır, isimlerin işaret ettiği pinler değişir:

        const int led1 = 11;
        const int led2 = 10;
        const int led3 = 9;
        const int led4 = 8;

    Öğrenci kolay yolu bulamazsa kötü değil; iki yolu yan yana gösterip "hangisi daha
    az iş?" diye sormak yeterli. ak0050'nin fikri burada ikinci kez işe yarıyor.

  SEN YAP 2) Şu an loop() içinde: 6 adım x (4 digitalWrite + 1 delay) = 30 satır.
    Beş LED'le: 8 adım (1-2-3-4-5-4-3-2) x (5 digitalWrite + 1 delay) = 48 satır.
    Yani loop()'a 18 satır eklenir; bir de const int ve pinMode satırlarıyla toplam 20.
    Beklenen tepki şaşırmaktır — bir LED eklemek koda 20 satır ekliyor. Bu tepki, seri
    port ünitesindeki döngü dersinin motivasyonudur, kaçırılmamalı.

  SEN YAP 3) 300'ü 100 yapmak için altı delay satırına birden dokunmak gerekir.
    ak0050'nin fikri buna da uyar: süreye de isim verilir. Aşağıdaki kod bu hâlidir —
    artık tek satır değiştirmek yetiyor.

  Not: Aşağıdaki kod SEN YAP 3'ün çözümüdür (bekleme sabiti eklenmiş, desen ilk
  hâlindeki gibi soldan sağa). SEN YAP 1'i de uygulamak isteyen öğrenci sadece dört
  const int satırındaki pin numaralarını ters çevirir.
*/

const int led1 = 8;
const int led2 = 9;
const int led3 = 10;
const int led4 = 11;
const int bekleme = 300;   // <- artık süre tek yerde duruyor

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
}

void loop() {
  digitalWrite(led1, HIGH);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  delay(bekleme);

  digitalWrite(led1, LOW);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  delay(bekleme);

  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, LOW);
  delay(bekleme);

  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, HIGH);
  delay(bekleme);

  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, LOW);
  delay(bekleme);

  digitalWrite(led1, LOW);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  delay(bekleme);
}
