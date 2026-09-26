/*
  ak0160 — çözüm örneği

  SEN YAP 1) Çift sayılar için koşul: sayac % 2 == 0

  SEN YAP 2) 3'e tam bölünenler için koşul: sayac % 3 == 0

  SEN YAP 3) 5'e tam bölünenlerde "BOM" yazdırma, else kullanmadan: tek koşul yeter,
  koşul yanlışken zaten hiçbir şey yazılmaz (else'e ihtiyaç yok).

  Aşağıdaki kod üçünü birleştirmez, SEN YAP 3'ün çözümüdür.
*/

int sayac = 1;

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (sayac % 5 == 0) {
    Serial.println("BOM");
  }
  sayac++;
  delay(200);
}
