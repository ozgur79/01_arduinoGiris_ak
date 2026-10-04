/*
  ak0340 — çözüm örneği

  SEN YAP 1) BASTI ve BIRAKTI sırayla gelmeli; kod okunarak: sonDurum bir önceki turu
    tuttuğu için arka arkaya iki BASTI olamaz (aralarına BIRAKTI girer). Sıçrama
    olan bir butonda kısa süre içinde BASTI/BIRAKTI/BASTI şeklinde fazladan çift
    görünebilir; kartta gözlenir.

  SEN YAP 2) İki ayrı `if` ile aynı çıktıyı vermesi beklenir: iki koşul aynı turda
    birlikte doğru olamaz. Fark: `else if` "ilk doğruysa ikinciye hiç bakma" der, iki
    `if` ikisini de sorar. Burada sonuç aynıdır; kartta karşılaştırılır.

  SEN YAP 3) Aşağıdaki kod yalnız basışları ve yalnız bırakmaları ayrı sayar. Sayılar
    hep eşit ya da basış sayısı bir fazladır: buton basılıyken (henüz bırakılmadan)
    basış bırakıştan bir önde olur.

  SEN YAP 4) "Hiçbir şey olmadı" turunda iki koşul da yanlış, `else if` zincirinin
    sonunda `else` olmadığı için hiçbir blok çalışmaz. Bunu yapan ayrı bir satır yok.
*/

const int butonPin = 2;
const int basisLed = 3;
const int birakisLed = 9;

int durum = LOW;
int sonDurum = LOW;
int basisSayisi = 0;
int birakisSayisi = 0;

void setup() {
  pinMode(butonPin, INPUT);
  pinMode(basisLed, OUTPUT);
  pinMode(birakisLed, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  durum = digitalRead(butonPin);

  if (durum == HIGH && sonDurum == LOW) {
    basisSayisi++;
    Serial.print("BASTI ");
    Serial.println(basisSayisi);
    digitalWrite(basisLed, HIGH);
    delay(200);
    digitalWrite(basisLed, LOW);
  } else if (durum == LOW && sonDurum == HIGH) {
    birakisSayisi++;
    Serial.print("BIRAKTI ");
    Serial.println(birakisSayisi);
    digitalWrite(birakisLed, HIGH);
    delay(200);
    digitalWrite(birakisLed, LOW);
  }

  sonDurum = durum;
}
