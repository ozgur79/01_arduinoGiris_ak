/*
  ak0040 — çözüm örneği

  SEN YAP 1) Sadece 9. pinin iki satırı yer değiştiriyor: LOW olan HIGH, HIGH olan LOW
  olur. 8. pinin satırlarına hiç dokunulmaz. Sonuç: iki LED birlikte yanıp birlikte söner.

      digitalWrite(8, HIGH);
      digitalWrite(9, HIGH);   // <- LOW idi
      delay(300);
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);    // <- HIGH idi
      delay(300);

  SEN YAP 2) Değişen tek şey ikinci delay: 300 yerine 900. Süreler eşit olmak zorunda
  değil — her delay kendinden önceki duruma aittir. Aşağıdaki kod bu hâlidir.

  SEN YAP 3) İki LED de sürekli yanık kalır, hiçbir şey yanıp sönmez:

      void setup() {
        pinMode(8, OUTPUT);
        pinMode(9, OUTPUT);
        digitalWrite(8, HIGH);
        digitalWrite(9, HIGH);
      }
      void loop() {
      }

  Beklenen gözlem: loop() boş olduğu hâlde LED'ler yanık kalıyor. Sebebi §5 İleri
  analizde: digitalWrite bir çakma değil anahtardır, sen değiştirene kadar durumu tutar.
  Öğrenci "loop boşsa LED neden sönmüyor?" diye sorarsa doğru soruyu sormuş demektir.
*/

void setup() {
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop() {
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);
  delay(300);

  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
  delay(900);
}
