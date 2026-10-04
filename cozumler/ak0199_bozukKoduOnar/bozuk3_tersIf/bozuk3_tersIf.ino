/*
  ak0199 — çözüm 3/3: ters if (binary sayıcı)

  HATA: if ((sayi % 4) < 1) — 2'ler basamağı için koşul ters yazılmış, ">1"
  olmalıyken "<1" yazılmış. Bu basamak, açık olması gereken sayılarda SÖNÜK,
  sönük olması gereken sayılarda YANIK görünüyor (tam ters).

  NASIL BULUNDU: Şüpheli satırın yanına Serial.println(sayi % 4); eklenip
  Seri Monitör'deki "Sayi: 2" satırıyla karşılaştırıldı — sayi=2 iken (sayi % 4)
  2 yazıyor, 2'ler basamağının YANMASI gerekiyor (2 > 1 doğru) ama LED sönük
  kaldı; sayi=0 iken (sayi % 4) 0 yazıyor, basamağın SÖNMESİ gerekirken LED
  yanıyordu. Beklenen ile ekrandaki fark, koşulun ters olduğunu gösterdi.

  DÜZELTME: (sayi % 4) < 1  ->  (sayi % 4) > 1.
*/

const int ledSayisi = 4;
const int ledler[4] = {3, 5, 6, 9}; // 3=8'ler, 5=4'ler, 6=2'ler, 9=1'ler basamağı

int sayi = 0;

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < ledSayisi; i++) {
    pinMode(ledler[i], OUTPUT);
  }
}

void loop() {
  for (int i = 0; i < ledSayisi; i++) {
    digitalWrite(ledler[i], LOW);
  }

  Serial.println(sayi % 4); // hatayı bulmak için eklenen satır — kalabilir

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

  sayi++;
  if (sayi == 16) {
    sayi = 0;
  }

  delay(1000);
}
