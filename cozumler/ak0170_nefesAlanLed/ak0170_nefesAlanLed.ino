/*
  ak0170 — çözüm örneği

  SEN YAP 1) %50'ye çıkıp birden sönmek için tek bir artış döngüsü yeter, iniş
    döngüsü silinir; en sonda LOW ile birden söndürülür.

  SEN YAP 2) İkinci LED (pin 10) ters nefes alır: onun parlaklığı her zaman
    255 - parlaklik'tir.

  Aşağıdaki kod SEN YAP 1'in çözümüdür.
*/

const int led = 11;

void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
  for (int parlaklik = 0; parlaklik <= 127; parlaklik++) {
    analogWrite(led, parlaklik);
    delay(10);
  }
  digitalWrite(led, LOW); // birden ve tamamen sön
  delay(1000);
}
