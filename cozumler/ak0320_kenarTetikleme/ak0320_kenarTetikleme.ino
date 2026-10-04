/*
  ak0320 — çözüm örneği

  SEN YAP 1) Buton 1 basılı tutulurken Buton 2 sayılır: kart hiç beklemiyor, her turda
    iki butonu da okuyor. ak0310'da `while` kartı bekletiyordu; burada bekleme yok.

  SEN YAP 2) Tek basışta 2 artış görünüp görünmeyeceği butona bağlıdır; kartta
    gözlenir. Görünürse sebep sıçramadır (ak0250), çaresi ak0330'da.

  SEN YAP 3) Düşen kenar: şimdi LOW ve az önce HIGH (aşağıdaki ilk if).

  SEN YAP 4) `!=` hâli aşağıda yorumda. Fark: `!=` hem basılmayı hem bırakılmayı
    yakalar (ikisi de "değişim"), sonra içeride `durum1 == HIGH` ile yalnız basılmayı
    seçersin. `&&`'li hâl doğrudan yalnız basılmayı yakalar.
*/

const int buton1Pin = 2;
const int buton2Pin = 8;
int sayac1 = 0;
int sayac2 = 0;
int durum1 = LOW;
int durum2 = LOW;
int sonDurum1 = LOW;
int sonDurum2 = LOW;

void setup() {
  pinMode(buton1Pin, INPUT);
  pinMode(buton2Pin, INPUT);
  Serial.begin(9600);
}

void loop() {
  durum1 = digitalRead(buton1Pin);
  durum2 = digitalRead(buton2Pin);

  if (durum1 == HIGH && sonDurum1 == LOW) {
    sayac1++;
    Serial.print("Buton 1: ");
    Serial.println(sayac1);
  }
  if (durum1 == LOW && sonDurum1 == HIGH) { // SEN YAP 3: düşen kenar
    Serial.println("birakildi");
  }
  if (durum2 == HIGH && sonDurum2 == LOW) {
    sayac2++;
    Serial.print("Buton 2: ");
    Serial.println(sayac2);
  }

  // SEN YAP 4 (!= ile aynı Buton 1 kararı):
  // if (durum1 != sonDurum1) {
  //   if (durum1 == HIGH) { sayac1++; Serial.println(sayac1); }
  // }

  sonDurum1 = durum1;
  sonDurum2 = durum2;
}
