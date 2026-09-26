/*
  ak0140 — çözüm örneği

  SEN YAP 1) Kartta doğrulama görevi, kod değişmez — ışıklar 8-9-10-11-10-9 sırasıyla
    yanıp söner, sonra baştan başlar. Uç LED'ler (8 ve 11) art arda iki kez yanmaz.

  SEN YAP 2) Beşinci LED (pin 12) eklemek için tek satır yeter: sonLed = 11; ->
    sonLed = 12; . Aşağıdaki kod bu hâlidir. ak0060'ta aynı ekleme için: bir const int
    satırı eklenir, bir pinMode satırı eklenir, loop() içine 5. ve (geri dönüşte) 4.
    LED için toplam en az 10 yeni digitalWrite+delay satırı eklenir — toplam ~12-13
    satır. Burada tek satır (sonLed) değişiyor.

  SEN YAP 3) Doldurulmuş tablo:

  | ders | digitalWrite+delay satırı | pinMode satırı |
  |------|----------------------------|-----------------|
  | ak0060 (elle) | 30 | 4 |
  | ak0140 (for)  | 6  | 1 (for içinde) |
*/

const int ilkLed = 8;
const int sonLed = 12;

void setup() {
  for (int pin = ilkLed; pin <= sonLed; pin++) {
    pinMode(pin, OUTPUT);
  }
}

void loop() {
  for (int pin = ilkLed; pin <= sonLed; pin++) {
    digitalWrite(pin, HIGH);
    delay(300);
    digitalWrite(pin, LOW);
  }

  for (int pin = sonLed - 1; pin >= ilkLed + 1; pin--) {
    digitalWrite(pin, HIGH);
    delay(300);
    digitalWrite(pin, LOW);
  }
}
