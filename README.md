# Arduino'ya Giriş

5. sınıf ve üzeri için sıfırdan Arduino müfredatı. Elektronik ya da programlama bilmene
gerek yok — ilk derste kartın üzerindeki küçük bir ışığı yakıyoruz, sonra adım adım
kendi devrelerini kuruyorsun.

Her ders **kendi başına çalışabileceğin** şekilde yazıldı. Sınıfta herkesin aynı yerde
olması gerekmiyor: sen kendi hızında ilerle, takıldığın yerde dur, hazır olduğunda
sıradakine geç.

## Ne gerekiyor

- Arduino Uno kartı ve USB kablosu
- Bilgisayarında **Arduino IDE** (ücretsiz, arduino.cc adresinden indirilir)
- İlk dersten sonra: LED, 220 ohm direnç, breadboard, jumper kablo

Hangi derste tam olarak neyin gerektiği her dersin `ders.md` dosyasının
**2. Malzemeler** başlığında yazıyor.

## Nasıl kullanılır

1. Bu depoyu bilgisayarına indir (yeşil **Code** düğmesi → *Download ZIP*, ya da
   `git clone`).
2. Sıradaki dersin klasörünü aç (ilk kez başlıyorsan `ak0010_dahiliLed`).
3. Önce **`ders.md`** dosyasını oku — hedef, malzeme, devrenin nasıl kurulacağı ve her
   kod satırının ne yaptığı orada.
4. Devreyi kur. Sonra `.ino` dosyasını Arduino IDE ile aç, karta yükle.
5. `ders.md`'deki **7. Mini sınav** sorularını kendi kendine cevapla. Bilemediğin soru
   varsa o başlığa geri dön.
6. Dosyanın en sonundaki **SEN YAP** görevlerini yap. Asıl öğrenme burada.
7. `.ino`'nun en altındaki **MERAK KÖŞESİ**'ni oku — kodda "bu ne ki?" diye merak
   ettiğin şeylerden biri her derste açıklanır.

Bir derste takılırsan `ders.md`'nin **6. Çalıştır ve gözlemle → Sorun giderme**
bölümüne bak; en sık yapılan hatalar orada yazıyor.

**Dersi erken bitirdiysen ve beklemek istemiyorsan** `meydanOkuma/` klasörüne bak.
Oradakiler ders değil, kart: yeni bir şey öğretmezler, öğrendiğin bir aleti daha zor
bir işte kullandırırlar.

## Kod içindeki bölümler

Her `.ino` dosyası aynı sırayla dört bölümden oluşur:

| bölüm | ne işe yarar |
| --- | --- |
| başlık | Ne öğreneceğin, gereken malzeme, devre şeması ve kara kutu listesi |
| `--- KAVRAM ---` | Dersin kendisi: çalışan kod ve satır satır açıklaması |
| `--- SEN YAP ---` | Senin görevin. Cevabı burada yazmaz, sen bulacaksın |
| `--- MERAK KÖŞESİ ---` | Kara kutulardan birinin açıklaması |

**Kara kutu** dediğimiz şey şu: koddaki her şeyi ilk derste anlatamayız, yoksa kafan
karışır. Anlatılmayanlar başlıkta açıkça listelenir ve **ne zaman açılacağı** yazılır —
sessizce geçilen hiçbir şey yok. Her derste bunlardan biri Merak Köşesi'nde açılır.
O yüzden listedeki bir şeyi anlamıyorsan bu normaldir, sırası gelecek.

## Ders sırası

| # | ders | konu | durum |
|---|------|------|-------|
| 1 | `ak0010_dahiliLed` | Kartın üzerindeki LED'i yakıp söndürme | yayında |
| 2 | `ak0020_hariciLed` | Kendi devreni kurup LED yakma (breadboard, direnç) | yayında |
| 3 | `ak0030_hizliLed` | LED'i hızlandırma ve gözün göremediği sınırı bulma | yayında |
| 4 | `ak0040_ikiLed` | İki LED'i sırayla yakıp söndürme | yayında |

Bu tablo her yeni ders eklendiğinde güncellenir. "Sırada ne var" diye buraya bak.
LED bloğu yedi derste tamamlanıyor (LED'e isim verme, kara şimşek, trafik lambası);
ardından seri port ve buton geliyor.
