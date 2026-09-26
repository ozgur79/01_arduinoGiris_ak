/*
  ak0180 — İç içe for: yıldız karesi
  Ne öğreneceğiz: Bir for'un İÇİNDE başka bir for — dıştaki satırı sayar, içteki
    satırdaki yıldızları sayar
  Malzeme: Arduino Uno kartı, USB kablosu
  Devre: Yok — ekran dersi.

  Şimdilik kara kutu (sonra açacağız):
    void                    -> "fonksiyon" konusunda açılacak
    Serial ve noktalı yazım -> "fonksiyon" konusunda açılacak
  Bunlara şimdilik dokunma, sırası gelince tek tek açacağız.

  kaynak: kaba müfredat madde 029 (5x5 yıldız, kodu yok, fikir kaynağı) — iç içe for
          iskeleti madde 031'deki üçgen kodundan (kareye uyarlandı). 031'deki 115200
          -> 9600; while (!Serial) { } satırı SİLİNDİ (Uno'da gereksiz, yeni ve
          gereksiz bir kara kutu açardı); değişken adları sa/su -> satir/sutun.

  BİLİNÇLİ İSTİSNA: Paket 1'den beri "hep Serial.println kullan" kuralı geçerliydi.
  Bu derste kural bilerek bozuluyor: yıldızları aynı satırda yan yana yazdırmak için
  Serial.print("* ") kullanılıyor (satır sonuna geçmiyor), satır bitince tek bir
  Serial.println() ile alt satıra iniliyor. print/println farkı ak0130'da öğrenilmişti;
  burada ilk kez GERÇEK bir işe yarıyor.
*/

// --- KAVRAM ---
// Dıştaki for (satir), kaç SATIR yıldız olacağını sayar: 1'den 5'e, 5 kez.
// İçteki for (sutun), her satırda kaç YILDIZ yazılacağını sayar: 1'den 5'e, 5 kez.
// Dıştaki for bir kez dönerken içteki for BAŞTAN SONA 5 kez döner — toplam 5 x 5 = 25
// yıldız yazılır.
void setup() {
  Serial.begin(9600);

  for (int satir = 1; satir <= 5; satir++) {
    for (int sutun = 1; sutun <= 5; sutun++) {
      Serial.print("* "); // yıldızı yaz, aynı satırda kal
    }
    Serial.println(); // satır bitti, alt satıra in
  }
}

void loop() {
  // Bilerek boş: kare bir kez çizilip duruyor.
}

// --- SEN YAP ---
// 1) 5x5 yerine 3x7 bir dikdörtgen çiz (3 satır, 7 sütun).
// 2) Yıldız yerine sayı yazdır: her satırda "1 2 3 4 5" görünsün (ipucu: Serial.print
//    yerine Serial.print(sutun) ve aradaki boşluk için Serial.print(" ") kullan).
// 3) Bir üçgen dene: her satırda bir önceki satırdan bir fazla yıldız olsun (1. satır
//    1 yıldız, 2. satır 2 yıldız...). Takılırsan üzülme — üçgenlerin devamı
//    meydanOkuma/ klasöründe, ders değil kart olarak seni bekliyor.
// 4) 5x5 karede TAM OLARAK 3. satır, 4. sütundaki yıldızı "+" yap, geri kalan her
//    yer yıldız kalsın. İpucu: iç içe for'u nasıl yazdığını hatırla — aynı mantıkla
//    bir if'in içine başka bir if de koyabilirsin. && ya da else kullanmadan, yalnızca
//    tek koşullu if'lerle çöz.
