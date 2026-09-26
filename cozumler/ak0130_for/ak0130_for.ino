/*
  ak0130 — çözüm örneği

  SEN YAP 1) for satırını loop() içine taşıyıp setup()'ı boş bırakınca sayma hiç
    durmuyor: setup() yalnızca bir kez çalışır, loop() ise kart açık kaldığı sürece
    baştan tekrar tekrar çalışır. for zaten kendi içinde 1'den 10'a sayıp bitiyordu;
    onu tekrar tekrar çalıştıran artık for'un kendisi değil, loop()'un kendisidir.
    Ekranda 1..10, 1..10, 1..10... şeklinde sürekli tekrar görülür.

  SEN YAP 2) Geriye saymak için başlangıç, koşul ve artışın üçü de ters çevrilir.
    Aşağıdaki kod bu hâlidir (10'dan 1'e).

  SEN YAP 3) 0'dan 100'e beşer saymak için: for (int sayac = 0; sayac <= 100; sayac += 5)
    += , "sağdaki kadar ekle" demenin kısa yazılışıdır (sayac = sayac + 5 ile aynı iş).
*/

void setup() {
  Serial.begin(9600);

  for (int sayac = 10; sayac >= 1; sayac--) {
    Serial.print("Sayac: ");
    Serial.println(sayac);
    delay(500);
  }
}

void loop() {
  // Bilerek boş: for setup() içinde bir kez çalışıp duruyor.
}
