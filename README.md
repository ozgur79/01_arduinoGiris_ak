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
| 5 | `ak0050_ledeIsimVer` | Pin numarası yerine isim kullanma (`const int`) | yayında |
| 6 | `ak0060_karaSimsek` | Dört LED'le gidip gelen ışık deseni | yayında |
| 7 | `ak0070_trafikLambasi` | Üç LED'le trafik lambası kurma | yayında |
| 8 | `ak0110_ledDurumunuYaz` | LED'in durumunu Seri Monitör'e yazdırma | yayında |
| 9 | `ak0115_trafikLambasiYazsin` | Trafik lambasında yanan rengi Seri Monitör'e yazdırma | yayında |
| 10 | `ak0120_sayac` | Kartın kendi kendine saymasını sağlama (değişken) | yayında |
| 11 | `ak0130_for` | Sayma işini `for` döngüsüyle tek satıra toplama | yayında |
| 12 | `ak0140_karaSimsekFor` | Kara şimşek desenini `for` ile kısaltma | yayında |
| 13 | `ak0150_while` | Sayma işini `while` ile yazma | yayında |
| 14 | `ak0155_sonsuzDongu` | `loop()`'un aslında sonsuz bir döngü olduğunu görme | yayında |
| 15 | `ak0160_tekSayilar` | `if` ve `%` ile yalnız tek sayıları yazdırma | yayında |
| 16 | `ak0165_rastgeleKaraSimsek` | `random()` ile kartın rastgele bir LED seçmesi | yayında |
| 17 | `ak0170_nefesAlanLed` | `analogWrite` (PWM) ile yavaşça parlayıp sönen LED | yayında |
| 18 | `ak0180_yildizKaresi` | İç içe `for` ile ekrana yıldız karesi çizme | yayında |
| 19 | `ak0182_yildizUcgenleri` | İç içe `for` ile düz ve ters yıldız üçgeni çizme | teste hazır |
| 20 | `ak0185_dizi` | Dizi ile pinler ardışık olmayınca kara şimşek kurma | yayında |
| 21 | `ak0190_binarySayici` | Dizi + `if` + `%` ile LED'lerin ikilik saydığını görme | yayında |
| 22 | `ak0195_millisIlkTur` | `millis()` ile iki LED'i bağımsız hızlarda yakma | yayında |
| 23 | `ak0197_serialOkuma` | `Serial.read` ile klavyeden komut gönderip LED yakma | teste hazır |
| 24 | `ak0199_bozukKoduOnar` | Bozuk kodu `Serial.println` ile hata ayıklayıp onarma (Ünite 1 kapanışı) | teste hazır |
| 25 | `ak0210_butonOku` | Butonu `INPUT` ve `digitalRead` ile okuyup LED yakma (pull-down direnç) | teste hazır |
| 26 | `ak0215_baslatButonu` | Butona basılana kadar bekleyip kara şimşeği başlatma | teste hazır |
| 27 | `ak0220_ifElse` | `else` ile "basınca yan, bırakınca sön" kararını tek yerde verme | teste hazır |
| 28 | `ak0230_ikiButon` | İki butona birden basınca yanan LED (`&&`) | teste hazır |
| 29 | `ak0240_zamanliTepki` | Butona basınca LED'in 2 saniye yanması | teste hazır |
| 30 | `ak0250_yakSondur` | Biri yakan, biri söndüren iki buton | teste hazır |
| 31 | `ak0260_refleksOyunu` | İki oyunculu refleks oyunu (Ünite 2 kapanışı) | teste hazır |
| 32 | `ak0299_bozukKoduOnar` | Buton kodlarındaki hataları bulup onarma (Ünite 2 kapanışı) | teste hazır |
| 33 | `ak0310_sayacKaciyor` | Buton sayacının neden çok saydığını görüp düzeltme | teste hazır |
| 34 | `ak0320_kenarTetikleme` | Butonun yeni basıldığı anı beklemeden yakalama | teste hazır |
| 35 | `ak0330_butonlaBinary` | Butonla ilerleyen binary sayıcı ve buton sıçraması | teste hazır |
| 36 | `ak0340_bastiBirakti` | `else if` ile basma ve bırakmayı ayırma | teste hazır |

Bu tablo her yeni ders eklendiğinde güncellenir. "Sırada ne var" diye buraya bak.
LED bloğu yedi derste tamamlandı. Seri port bloğunda kartın yaptığı işi bilgisayara
yazdırmaya başladık; döngüler, ilk dallanma (`if`), rastgelelik, PWM, dizi, `millis()`,
iki yönlü seri port ve hata ayıklama geldi. Buton bloğunda (Ünite 2) kart ilk kez
dışarıyı dinliyor: `INPUT`, `digitalRead`, `else`, `&&`, bir refleks oyunu ve yine bir
hata avı var. Ünite 3 başladı: buton ve seri port birlikte (kenar tetikleme, sıçrama, `else if`). Sırada tek butonla yak/söndür ve `millis()`.
