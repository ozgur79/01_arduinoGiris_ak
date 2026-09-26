/*
  ak0155 — çözüm örneği

  SEN YAP 1) Evet, ikisi de kartta birebir aynı şeyi yapar: LED saniyede bir yanıp
    söner. ak0010'da digitalWrite/delay satırları loop() içindeydi, kart onları
    kendi sonsuz döngüsüyle (loop()) tekrarlıyordu. Burada aynı satırlar setup()
    içine, kendi yazdığımız while (true) döngüsünün içine taşındı; loop() boş kaldı.

  SEN YAP 2) "BITTI" hiç görünmez, çünkü Serial.println("BITTI"); satırı while (true)
    bloğunun bittiği yerden SONRA duruyor — ama while (true) hiçbir zaman bitmiyor.
    Program o satıra hiç sıra gelmeden LED'i yakıp söndürmeye sonsuza kadar devam
    eder. Aşağıdaki kod bu denemenin hâlidir.

  SEN YAP 3) while (false) yapılırsa LED hiç yanmaz: koşul hiçbir zaman doğru
    olmadığı için { } bloğunun içine bir kez bile girilmez.
*/

void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(9600);

  while (true) {
    digitalWrite(13, HIGH);
    delay(1000);
    digitalWrite(13, LOW);
    delay(1000);
  }

  Serial.println("BITTI"); // buraya hiç sıra gelmez
}

void loop() {
}
