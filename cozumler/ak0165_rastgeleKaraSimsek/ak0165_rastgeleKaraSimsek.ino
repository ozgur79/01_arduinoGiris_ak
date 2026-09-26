/*
  ak0165 — çözüm örneği

  SEN YAP 1) delay(1500) yerine random(100, 500) kullanmak için sabit bir sayı yerine
    her turda yeni bir rastgele sayı üretilir. Aşağıdaki kod bu hâlidir.

  SEN YAP 2) 1'den 100'e kadar rastgele 10 sayı için setup() içindeki zar atma
    döngüsü: for (int atis = 1; atis <= 10; atis++) { int sayi = random(1, 101);
    Serial.println(sayi); delay(300); }

  SEN YAP 3) Kartı resetleyince zarlar hep aynı sırayla gelir — bu bir gözlem görevi,
    kod değişmez. Sebebi Merak Köşesi'nde.
*/

const int ilkLed = 8;
const int sonLed = 11;

void setup() {
  Serial.begin(9600);
  delay(2500); // Seri Monitör'ü açman için birkaç saniye bekleniyor

  for (int pin = ilkLed; pin <= sonLed; pin++) {
    pinMode(pin, OUTPUT);
  }

  for (int atis = 1; atis <= 5; atis++) {
    int zar = random(1, 7);
    Serial.print("Zar: ");
    Serial.println(zar);
    delay(500);
  }
}

void loop() {
  int secilenPin = random(ilkLed, sonLed + 1);
  digitalWrite(secilenPin, HIGH);
  Serial.print("LED: ");
  Serial.println(secilenPin);
  delay(random(100, 500));
  digitalWrite(secilenPin, LOW);
  delay(200);
}
