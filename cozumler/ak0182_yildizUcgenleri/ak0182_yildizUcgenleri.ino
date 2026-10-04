/*
  ak0182 — çözüm örneği

  SEN YAP 1) 7 satırlı düz üçgen: iki for'daki "satir <= 5" ve "sutun <= satir"
    satırlarındaki 5, 7 yapılır (içteki sınır zaten satir'e bağlı olduğu için
    ekstra değişiklik istemez). Ters üçgende de dıştaki "satir = 5" başlangıcı
    7 yapılır.

  SEN YAP 2) Ters üçgenin İKİNCİ yolu: dıştaki döngü ARTAR (satir = 1'den 5'e),
    içteki sınır "sutun <= 6 - satir" olur. satir=1 iken sınır 5 (en uzun satır),
    satir=5 iken sınır 1 (en kısa satır) — aynı ters üçgen, farklı yoldan.
    Aşağıdaki kod bu ikinci yolu gösterir (SEN YAP 1'deki 7 satır BURADA
    uygulanmadı, kıyaslama kolay olsun diye 5 satır bırakıldı).

  SEN YAP 3) Sayı üçgeni: Serial.print("* ") yerine Serial.print(sutun) ve
    Serial.print(" ") kullanılır — tıpkı ak0180 SEN YAP 2'deki gibi.
*/

void setup() {
  Serial.begin(9600);

  // Düz üçgen (değişmedi)
  for (int satir = 1; satir <= 5; satir++) {
    for (int sutun = 1; sutun <= satir; sutun++) {
      Serial.print("* ");
    }
    Serial.println();
  }

  Serial.println();

  // Ters üçgen — İKİNCİ yol: dıştaki döngü artıyor, içteki sınır "6 - satir"
  for (int satir = 1; satir <= 5; satir++) {
    for (int sutun = 1; sutun <= 6 - satir; sutun++) {
      Serial.print("* ");
    }
    Serial.println();
  }
}

void loop() {
}
