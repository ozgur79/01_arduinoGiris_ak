/*
  ak0150 — çözüm örneği

  SEN YAP 1) sayac++; silinince koşul (sayac <= 10) hiçbir zaman yanlış olmaz —
    sayac hep 1 kalır, "1" ekrana durmadan yazılır. Bu, KAZARA kurulmuş bir sonsuz
    döngü: artışı unutmak yeter. Bir sonraki derste (ak0155) aynı şeyi BİLEREK
    kuracağız.

  SEN YAP 2) Geriye saymak için üç parça da ters çevrilir. Aşağıdaki kod bu hâlidir.

  SEN YAP 3) Tablo dersin KAVRAM bölümünde zaten dolu; kendi kodunla karşılaştır.
*/

void setup() {
  Serial.begin(9600);

  int sayac = 10;
  while (sayac >= 1) {
    Serial.println(sayac);
    delay(500);
    sayac--;
  }
}

void loop() {
  // Bilerek boş.
}
