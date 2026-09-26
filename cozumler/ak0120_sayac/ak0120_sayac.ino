/*
  ak0120 — çözüm örneği

  SEN YAP 1) sayac = sayac + 1; -> sayac = sayac + 2; yapınca Seri Monitör'de
    2, 4, 6, 8... görünür. Değişkenin içine her turda ne kadar eklendiğini o satır
    belirliyor; 1 yerine 2 yazmak sayma adımını değiştirir.

  SEN YAP 2) int sayac = 0; -> int sayac = 100; yapınca sayma 101'den başlar (ilk
    Serial.println'den önce zaten bir kez +1 yapılmış olur). Başlangıç değerini
    değiştirmek sayacın "nereden başladığını" belirler, "nasıl arttığını" değil.

  SEN YAP 3) delay(1000) -> delay(200) yapınca sayılar ekrana çok daha hızlı çıkar;
    delay(3000) yapınca çok yavaşlar. delay, sayaç artışıyla ilgisiz — sadece iki
    yazı arasında ne kadar bekleneceğini belirler.

  Aşağıdaki kod SEN YAP 1'in çözümüdür (ikişer sayma).
*/

int sayac = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  sayac = sayac + 2;
  Serial.println(sayac);
  delay(1000);
}
