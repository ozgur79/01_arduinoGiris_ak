/*
  ak0182 — Yıldız üçgenleri: düz ve ters
  Ne öğreneceğiz: İç içe for'ta içteki döngünün sınırı SABİT olmak zorunda değil —
    dıştaki döngünün O ANKİ değerine BAĞLI olabilir (ak0180'de sabitti: sutun <= 5)
  Malzeme: Arduino Uno kartı, USB kablosu
  Devre: Yok — ekran dersi.

  Şimdilik kara kutu (sonra açacağız):
    void                    -> "fonksiyon" konusunda açılacak
    Serial ve noktalı yazım -> "fonksiyon" konusunda açılacak
  Bunlara şimdilik dokunma, sırası gelince tek tek açacağız.

  kaynak: ..\arsiv\kabaMüfredat.docx, madde 031 (iç içe for iskeleti — ASIL hâli
          üçgendi, ak0180'de kareye uyarlanmıştı; burada üçgene geri dönüldü).
          115200 -> 9600 (Paket 1 kuralı, ak0180'de de yapılmıştı).
*/

// --- KAVRAM ---
// ak0180'de içteki döngü hep 5 kez dönüyordu (sutun <= 5, SABİT sınır). Burada
// içteki döngünün üst sınırı sabit bir sayı değil, dıştaki döngünün O ANKİ değeri:
// sutun <= satir. satir arttıkça bu sınır da büyür — üçgen tam bu yüzden oluşur.
void setup() {
  Serial.begin(9600);

  // Düz üçgen: 1. satırda 1 yıldız, 5. satırda 5 yıldız.
  for (int satir = 1; satir <= 5; satir++) {
    for (int sutun = 1; sutun <= satir; sutun++) {
      Serial.print("* ");
    }
    Serial.println();
  }

  Serial.println(); // iki üçgen arasına boş satır

  // Ters üçgen: aynı iç sınır (sutun <= satir) yeter — sadece DIŞTAKİ döngü 5'ten
  // 1'e geri sayıyor (satir--, ak0130'dan tanıdık).
  for (int satir = 5; satir >= 1; satir--) {
    for (int sutun = 1; sutun <= satir; sutun++) {
      Serial.print("* ");
    }
    Serial.println();
  }
}

void loop() {
  // Bilerek boş: iki üçgen bir kez çizilip duruyor.
}

// --- SEN YAP ---
// 1) Düz üçgeni 7 satıra çıkar (iki for'daki 5'leri de 7 yap; ters üçgeni de aynı
//    şekilde büyütmen gerekir mi, dene).
// 2) Ters üçgeni FARKLI bir yoldan üret: dıştaki döngüyü geri saydırma (satir 1'den
//    5'e ARTSIN), bunun yerine içteki sınırı "sutun <= 6 - satir" yap. İki yol da
//    aynı görüntüyü mü veriyor? [ileri]
// 3) Sayı üçgeni: yıldız yerine satır numarasını yazdır (her satırda "1 2 3..." o
//    satırın numarasına kadar sayar).
// 4) Takılırsan üzülme — zor hâlleri (baklava, içi boş üçgen) meydanOkuma/
//    klasöründe seni bekliyor, ama önce bu dersi bitir.
