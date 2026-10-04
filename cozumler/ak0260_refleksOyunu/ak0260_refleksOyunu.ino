/*
  ak0260 — çözüm örneği

  SEN YAP 1) Erken basma: kod okunarak — "BAS!"tan önceki süre delay() ile geçiyor,
    delay sırasında kart butonları OKUMUYOR (ak0240). Yani bekleme süresinde basıp
    bırakılan kısa bir basış hiç görülmez. Ama butonu BASILI TUTARAK beklersen, "BAS!"
    yanınca while'a gelindiğinde buton zaten HIGH'dır ve oyun hemen biter. Kartta
    Özgür/öğrenci gözler; burada kesin ifade değil kod okuma çıkarımı var.

  SEN YAP 2) Aynı anda basış: if (buton1 HIGH) önce kontrol edildiği için Oyuncu 1
    kazanır. Adil yapmak için iki butonun basış ANINI ayrı ölçmek gerekir — bu
    Ünite 3'te (millis) mümkün; şu aletlerle yalnız sırayı değiştirerek
    (örneğin her turda hangisinin önce kontrol edildiğini değiştirerek) biraz
    dengelenebilir ama tam adil olmaz.

  SEN YAP 3) Erken basanı yakalamak: bekleme SIRASINDA butonları okumak gerekir; oysa
    delay sırasında kart okumuyor. Çare Ünite 3'te, delay yerine millis() ile
    bekleyip aynı anda butonları okumak. (Çözüm şu an yazılmıyor.)

  SEN YAP 4) delay(random(1000, 3001)) — üst sınır hiç gelmediği için 3001 yazıldı.
*/

const int buton1Pin = 2;
const int buton2Pin = 8;
const int sinyalLed = 6;
const int oyuncu1Led = 3;
const int oyuncu2Led = 9;

void setup() {
  pinMode(buton1Pin, INPUT);
  pinMode(buton2Pin, INPUT);
  pinMode(sinyalLed, OUTPUT);
  pinMode(oyuncu1Led, OUTPUT);
  pinMode(oyuncu2Led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(sinyalLed, LOW);
  digitalWrite(oyuncu1Led, LOW);
  digitalWrite(oyuncu2Led, LOW);

  Serial.println("Hazir olun...");
  delay(random(1000, 3001));       // SEN YAP 4: 1-3 saniye

  digitalWrite(sinyalLed, HIGH);
  Serial.println("BAS!");

  while (digitalRead(buton1Pin) == LOW && digitalRead(buton2Pin) == LOW) {
    // hiçbir şey yapma, sadece tekrar bak
  }

  if (digitalRead(buton1Pin) == HIGH) {
    digitalWrite(oyuncu1Led, HIGH);
    Serial.println("Oyuncu 1 kazandi!");
  } else {
    digitalWrite(oyuncu2Led, HIGH);
    Serial.println("Oyuncu 2 kazandi!");
  }

  delay(3000);
}
