/*
  ak0050 — çözüm örneği

  SEN YAP 1) Aşağıdaki kod pin 10 ve 11'e taşınmış hâlidir. Değişen satır sayısı:
  **2** (sadece iki const int satırı). ak0040'ın kodunda aynı taşıma **6 satır**
  değiştirmeyi gerektirirdi: iki pinMode + dört digitalWrite. Dersin bütün fikri bu
  iki sayının farkında: 2 ve 6. Dört LED'lik bir devrede fark 4'e karşı 12 olur.

  SEN YAP 2) İsimler iki yerde tanımlanır (const int satırları), her isim aşağıda üç
  kez kullanılır. Ama isim değiştirmek için hepsini elle bulmak gerekmez — Arduino
  IDE'de Ctrl+H (Değiştir) ile tek seferde yapılır. Öğrenci elle de yapabilir,
  önemli olan kaç yerde geçtiğini fark etmesi.

  SEN YAP 3) Evet, kod `a` ve `b` ile de sorunsuz çalışır. Beklenen cevap: isim
  vermek Arduino'ya değil **insana** yarar. Arduino'ya 8 de yazsan kirmizi de yazsan
  fark etmez (bkz. §5 İleri analiz: isimler derleme sırasında sayılarla değiştirilir).
  Kodu okuyan, altı ay sonra kendine bakan, ya da yardım isteyen arkadaşı için fark eder.
  "Bilgisayar için değil, insan için yazıyoruz" cümlesini öğrenci kendi kelimeleriyle
  kurabiliyorsa ders tutmuştur.
*/

const int kirmizi = 10;
const int yesil = 11;

void setup() {
  pinMode(kirmizi, OUTPUT);
  pinMode(yesil, OUTPUT);
}

void loop() {
  digitalWrite(kirmizi, HIGH);
  digitalWrite(yesil, LOW);
  delay(300);

  digitalWrite(kirmizi, LOW);
  digitalWrite(yesil, HIGH);
  delay(300);
}
