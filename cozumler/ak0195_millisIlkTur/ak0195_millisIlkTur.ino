/*
  ak0195 — çözüm örneği

  SEN YAP 1) Üçüncü LED (pin 5) için kendi oncekiC/aralikC/durumC üçlüsü eklenir —
    ikinci LED'i eklerken kullanılan kalıbın birebir tekrarı. Aşağıdaki kod bu hâlidir
    (saniyede 5 kez, aralikC = 100).

  SEN YAP 2) aralikA/aralikB/aralikC değerlerini değiştirmek tek satırlık bir iş.

  SEN YAP 3) delay() ile üç bağımsız ritim kurmak neredeyse imkansızdır — her delay()
    programın TAMAMINI durdurur, sadece kendi LED'ini değil. millis() hiçbir şeyi
    bekletmediği için üç LED birbirinden habersiz, kendi hızında ilerleyebiliyor.
*/

const int ledA = 3;
const int ledB = 9;
const int ledC = 5;

unsigned long oncekiA = 0;
unsigned long oncekiB = 0;
unsigned long oncekiC = 0;
const unsigned long aralikA = 500;
const unsigned long aralikB = 167;
const unsigned long aralikC = 100;

int durumA = 0;
int durumB = 0;
int durumC = 0;

void setup() {
  pinMode(ledA, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(ledC, OUTPUT);
}

void loop() {
  unsigned long simdi = millis();

  if (simdi - oncekiA >= aralikA) {
    oncekiA = simdi;
    durumA = 1 - durumA;
    digitalWrite(ledA, durumA);
  }

  if (simdi - oncekiB >= aralikB) {
    oncekiB = simdi;
    durumB = 1 - durumB;
    digitalWrite(ledB, durumB);
  }

  if (simdi - oncekiC >= aralikC) {
    oncekiC = simdi;
    durumC = 1 - durumC;
    digitalWrite(ledC, durumC);
  }
}
