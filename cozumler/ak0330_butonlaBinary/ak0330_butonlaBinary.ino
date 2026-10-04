/*
  ak0330 — çözüm örneği

  SEN YAP 1) Sıçramanın görünüp görünmeyeceği butona bağlıdır; kartta gözlenir.
    Görünürse LED'ler iki sayı birden ilerler ("Sayi:" çıktısında bir sayı atlanır).

  SEN YAP 2) delay(0) ile sıçrama olan butonlarda atlamalar görülebilir; olmayan
    butonlarda fark görünmeyebilir. delay(500) ile kart her basıştan sonra yarım saniye
    kör: çok hızlı art arda basışların bir kısmı okunamaz. Sonuçlar kartta gözlenir;
    burada kesin ifade yok. Denge: sıçramayı geçirecek kadar uzun, hızlı basışı
    kaçırmayacak kadar kısa (onlarca milisaniye). Daha iyi bir yol Ünite 3'ün ileri
    derslerinde (millis).

  SEN YAP 3) 15'ten sonra `if (sayi == 16) { sayi = 0; }` satırı 0'a döndürür: 16
    basışta bir tur biter.

  SEN YAP 4) 8 LED ile 2^8 = 256 durum olur, en büyük sayı 255.

  Kod ana dosyayla aynıdır; delay süresi deney için burada bir sabitte.
*/

const int ledSayisi = 4;
const int ledler[4] = {3, 5, 6, 9};
const int butonPin = 2;
const int bekleme = 50; // SEN YAP 2: 0 ve 500 ile dene

int sayi = 0;
int durum = LOW;
int sonDurum = LOW;

void setup() {
  Serial.begin(9600);
  pinMode(butonPin, INPUT);
  for (int i = 0; i < ledSayisi; i++) {
    pinMode(ledler[i], OUTPUT);
  }
}

void loop() {
  durum = digitalRead(butonPin);

  if (durum == HIGH && sonDurum == LOW) {
    sayi++;
    if (sayi == 16) {
      sayi = 0;
    }

    for (int i = 0; i < ledSayisi; i++) {
      digitalWrite(ledler[i], LOW);
    }
    if ((sayi % 2) > 0) {
      digitalWrite(ledler[3], HIGH);
    }
    if ((sayi % 4) > 1) {
      digitalWrite(ledler[2], HIGH);
    }
    if ((sayi % 8) > 3) {
      digitalWrite(ledler[1], HIGH);
    }
    if ((sayi % 16) > 7) {
      digitalWrite(ledler[0], HIGH);
    }

    Serial.print("Sayi: ");
    Serial.println(sayi);

    delay(bekleme);
  }

  sonDurum = durum;
}
