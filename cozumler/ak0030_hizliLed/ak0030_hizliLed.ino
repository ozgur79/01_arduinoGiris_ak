/*
  ak0030 — çözüm örneği

  SEN YAP 1) İki delay() satırı da aynı sayıyı taşımalı. Yalnız birini değiştirmek
  yanma ve sönme sürelerini farklı yapar, hızlanma olmaz.

  SEN YAP 2) Bu sorunun tek bir doğru sayısı YOKTUR — öğrencinin bulduğu sayı doğru
  cevaptır. Sınırı koyan LED değil göz; eşik kişiden kişiye, ortam ışığına ve LED'e
  bakış açısına göre değişir. Beklenen aralık kabaca 10-25 ms arasıdır (yani saniyede
  20-50 tur). Bu aralığın dışında bir sayı bulan öğrenciye "yanlış" denmez; nasıl
  baktığı sorulur (§6 Sorun giderme'deki "başını sallayarak bak" yöntemi).

  SEN YAP 3) İki arkadaşın farklı sayı bulması beklenen sonuçtur, hata değil.

  Aşağıdaki kod delay = 10 ms hâlidir (saniyede 50 tur). Bu, "cevap" değil, öğrencinin
  merdivenin en altına indiğinde elinde olacak koddur.
*/

void setup() {
  pinMode(8, OUTPUT);
}

void loop() {
  digitalWrite(8, HIGH);
  delay(10);
  digitalWrite(8, LOW);
  delay(10);
}
