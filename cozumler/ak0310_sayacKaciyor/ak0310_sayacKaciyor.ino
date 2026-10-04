/*
  ak0310 — çözüm örneği

  SEN YAP 1) Sayaç birden çok daha büyük bir sayıya çıkar; tam sayı butona ne
    kadar basılı tuttuğuna ve karta bağlıdır — burada tahmin yazılmıyor, kartta bakılır.
    Sebep: loop() çok hızlı döner, basış sürdükçe her tur sayaç artar.

  SEN YAP 2) while (digitalRead(butonPin) == HIGH) { } butonu BIRAKILANA kadar kartı
    bekletir; sayaç bu yüzden basış başına bir kez artar. delay(20) butonun bırakılırken
    kısa süre sekmesini (ak0250'deki "sıçrama") bekler; ayrıntısı ak0330'da.

  SEN YAP 3) Aşağıdaki kod iki butonlu sayaç. Buton 1 basılı tutulurken kart while'ın
    içinde bekliyor, Buton 2'yi hiç okumuyor: Buton 2'ye bastığın sayılmaz. Bu
    "kilit"in çaresi bir sonraki derste (kenar tetikleme).

  SEN YAP 4) if (sayac1 == 2) LED'i yakar. Üçüncü basışta sayac1 3 olur, koşul
    yanlışlaşır ama LED'i söndüren bir satır YOK, LED yanık kalır. Çare: üçüncü
    basışta sayac1 = 0; ve LED'i söndür (öğrenci bulur; burada yorumda gösterildi).
*/

const int butonPin = 2;
const int buton2Pin = 8;
const int ledPin = 6;
int sayac1 = 0;
int sayac2 = 0;

void setup() {
  pinMode(butonPin, INPUT);
  pinMode(buton2Pin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(butonPin) == HIGH) {
    sayac1++;
    Serial.print("Buton 1: ");
    Serial.println(sayac1);
    while (digitalRead(butonPin) == HIGH) { } // bırakılana kadar bekle
    delay(20);
  }

  if (digitalRead(buton2Pin) == HIGH) {
    sayac2++;
    Serial.print("Buton 2: ");
    Serial.println(sayac2);
    while (digitalRead(buton2Pin) == HIGH) { }
    delay(20);
  }

  if (sayac1 == 2) {
    digitalWrite(ledPin, HIGH);
  }
  // SEN YAP 4 çaresi (yorumu kaldırırsan üçüncü basışta sıfırlanır):
  // if (sayac1 == 3) { sayac1 = 0; digitalWrite(ledPin, LOW); }
}
