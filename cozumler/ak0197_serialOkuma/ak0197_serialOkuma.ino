/*
  ak0197 — çözüm örneği

  SEN YAP 1) Test adımı, kod değişikliği yok.

  SEN YAP 2) Üçüncü if: '2' gelince pin 3'teki LED yanar. Aşağıda pinMode'lar
    SEN YAP 3'teki ledler[] dizisiyle birlikte for ile ayarlandığı için pin 3'ün
    pinMode'u da orada, dizinin ilk elemanı olarak (ledler[0] = 3) hazır geliyor.

  SEN YAP 3) 'a' gelince ak0185'teki ledler dizisinin HEPSİ birden yanar — for ile
    dört pine tek tek digitalWrite(HIGH) yazılır. Aşağıdaki kod SEN YAP 2 ve 3'ü
    birlikte gösterir.
*/

const int ledSayisi = 4;
const int ledler[4] = {3, 5, 6, 9};

char gelenKarakter;
const int ledPin = 9;

void setup() {
  for (int i = 0; i < ledSayisi; i++) {
    pinMode(ledler[i], OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    gelenKarakter = Serial.read();

    if (gelenKarakter == '1') {
      digitalWrite(ledPin, HIGH);
    }

    if (gelenKarakter == '0') {
      digitalWrite(ledPin, LOW);
    }

    if (gelenKarakter == '2') {
      digitalWrite(3, HIGH);
    }

    if (gelenKarakter == 'a') {
      for (int i = 0; i < ledSayisi; i++) {
        digitalWrite(ledler[i], HIGH);
      }
    }
  }
}
