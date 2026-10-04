/*
  ak0215 — çözüm örneği

  SEN YAP 1) "Butona bas..." satırı while'ın İÇİNE taşınırsa: while her turda
    (saniyede muhtemelen on binlerce kez) bu satırı tekrar tekrar yazdırır, Seri
    Monitör aynı yazıyla anında dolup taşar. Bu yüzden yazı while'DAN ÖNCE, tek
    sefer duruyor. Aşağıdaki kod bu deneyi YORUM SATIRI olarak gösteriyor (kalıcı
    açık bırakılmadı, ekranı gerçekten taşırır).

  SEN YAP 2) == LOW yerine == HIGH yazmak İSTENENİ YAPMAZ: kart açılışında buton
    zaten basılı değildir (LOW), bu yüzden "while (digitalRead(butonPin) == HIGH)"
    koşulu AÇILIŞTA hemen YANLIŞ olur ve kara şimşek dokunulmadan başlar — "basılı
    tutunca başla" değil, "hiç dokunma, direkt başla" olur. Bu, ŞU ANKİ ALETLERLE
    (while + digitalRead, hafızasız bir "an"lık okuma) çözülemeyen bir görev: kartın
    "önce basıldı, SONRA bırakıldı" diye bir SIRAYI hatırlaması gerekir, bu Ünite 3'ün
    kenar tetiklemesi. Aşağıdaki kod bu YANLIŞ denemeyi (yorum satırı olarak) gösterir
    — ana kod hâlâ SEN YAP'tan önceki doğru hâliyle (== LOW) duruyor.
*/

const int butonPin = 2;
const int ledSayisi = 4;
const int ledler[4] = {3, 5, 6, 9};

void setup() {
  for (int i = 0; i < ledSayisi; i++) {
    pinMode(ledler[i], OUTPUT);
  }
  pinMode(butonPin, INPUT);
  Serial.begin(9600);

  Serial.println("Butona bas...");

  while (digitalRead(butonPin) == LOW) {
    // hiçbir şey yapma, sadece tekrar bak
  }

  // SEN YAP 2 denemesi (İSTENENİ YAPMAZ, yukarıdaki açıklamaya bak):
  // while (digitalRead(butonPin) == HIGH) { }
}

void loop() {
  for (int i = 0; i < ledSayisi; i++) {
    digitalWrite(ledler[i], HIGH);
    delay(300);
    digitalWrite(ledler[i], LOW);
  }
  for (int i = ledSayisi - 2; i >= 1; i--) {
    digitalWrite(ledler[i], HIGH);
    delay(300);
    digitalWrite(ledler[i], LOW);
  }
}
