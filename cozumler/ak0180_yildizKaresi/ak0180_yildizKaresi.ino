/*
  ak0180 — çözüm örneği

  SEN YAP 1) 3x7 dikdörtgen: dıştaki for 1'den 3'e (satır), içteki for 1'den 7'ye
    (sütun).

  SEN YAP 2) Sayı yazdırmak için Serial.print("* ") yerine Serial.print(sutun) ve
    Serial.print(" ") kullanılır.

  SEN YAP 3) Üçgen: içteki for'un üst sınırı sabit 5 değil, dıştaki satır sayısına
    bağlı (sutun <= satir). Bu, meydanOkuma/'daki üçgen kartının çekirdek fikridir.

  SEN YAP 4) && ya da else olmadan tek bir hücreyi değiştirmek için iç içe for'daki
    mantık if'e taşınır: dıştaki if satırı kontrol eder, İÇİNDEKİ ikinci if sütunu
    kontrol eder. İkisi birden doğruysa (satir == 3 VE sutun == 4) "isaretYildiz"
    bayrağı 0 yapılır; en sonda bu bayrağa göre "*" ya da "+" yazılır. Bayrağın
    varsayılan değeri her sütunda yeniden 1'e kurulur, yoksa bir önceki turdan kalır.

  Aşağıdaki kod SEN YAP 4'ün çözümüdür.
*/

void setup() {
  Serial.begin(9600);

  for (int satir = 1; satir <= 5; satir++) {
    for (int sutun = 1; sutun <= 5; sutun++) {
      int isaretYildiz = 1; // varsayılan: yıldız yaz

      if (satir == 3) {
        if (sutun == 4) {
          isaretYildiz = 0; // tam bu hücrede: + yaz
        }
      }

      if (isaretYildiz == 1) {
        Serial.print("* ");
      }
      if (isaretYildiz == 0) {
        Serial.print("+ ");
      }
    }
    Serial.println();
  }
}

void loop() {
}
