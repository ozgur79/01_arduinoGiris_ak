/*
  ak0240 — çözüm örneği

  SEN YAP 1) Gözlem: LED yanıkken butona basmak hiçbir şey değiştirmez — bu 2 saniye
    boyunca kart delay(2000) satırında bekliyor, butonu okumuyor. (Sonuç kartta
    gözlenir; yazılan bu, kesin ifade değil "ne görüyorsan onu yaz" sorusu.)

  SEN YAP 2) Bu sorunun cevabı KARTTA görülür, burada tahmin yazılmıyor. Kod
    okunarak: delay bitince loop() baştan başlar, buton hâlâ basılıysa ne olacağını
    if'in koşulu belirler — Özgür/öğrenci kartta bakar.

  SEN YAP 3) Ters hâl (kaynak: 021YesilButonLed). Aşağıdaki kod yüklenince LED yanık;
    butona basılınca 3 saniye söner, sonra loop() baştan başlayınca tekrar yanar.
    ÖNEMLİ: ters hâlde "yak" komutu loop()'un başında durur, yoksa 3 saniye sonra
    LED tekrar yanmaz.
*/

const int butonPin = 2;
const int ledPin = 6;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(butonPin, INPUT);
}

void loop() {
  digitalWrite(ledPin, HIGH);          // normalde yanık
  if (digitalRead(butonPin) == HIGH) { // butona basıldı mı?
    digitalWrite(ledPin, LOW);         // 3 saniye sönük
    delay(3000);
  }
}
