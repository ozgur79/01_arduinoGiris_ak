---
ak_no: ak0190
baslik: "Binary sayıcı (harcama)"
duzey: 0-temel
unite: 1-LED-ve-Seri-Port
kazanimlar:
  - cpp.setup-loop
  - cpp.delay
  - cpp.pinmode
  - cpp.digitalwrite
  - cpp.serial-begin
  - cpp.serial-println
  - cpp.const-int
  - cpp.for
  - cpp.dizi
  - cpp.dizi_indeks
  - cpp.if
  - cpp.kalan
onkosul:
  - cpp.dizi (ak0185), cpp.if/cpp.kalan (ak0160), cpp.degisken/cpp.atama (ak0120)
kara_kutu: [void, OUTPUT, "Serial ve noktalı yazım"]
merak_kosesi: "atlandı (yük freni — harcama dersi + 3 kaynak hatası düzeltmesi zaten ağır)"
malzeme:
  - Arduino Uno kartı
  - USB kablosu
  - 4 LED
  - 4 adet 220 ohm direnç
  - breadboard
  - 5 jumper kablo
board:
  kart: Arduino Uno
  led_pinleri: [3, 5, 6, 9]
  bit_sirasi: "pin 9 = 1'ler (LSB, en sağ), pin 6 = 2'ler, pin 5 = 4'ler, pin 3 = 8'ler (MSB, en sol)"
  seri_port_pinleri: [0, 1]
  seri_hiz: 9600
  mantik_gerilimi: 5V
  direnc: 220 ohm
kaynak:
  - ..\arsiv\005binarySayici\005binarySayici.ino
---

## 1. Hedef
Yeni fikir yok, bilerek — üç eski aleti (sayaç, `if`+`%`, dizi) bir arada kullanacaksın.
4 LED, 0'dan 15'e kadar **ikilik (binary)** sayacak; seri port aynı sayıyı **onluk**
yazacak. İki gösterimi yan yana karşılaştıracaksın.

## 2. Malzemeler
- Arduino Uno kartı
- USB kablosu
- 4 LED
- 4 adet 220 ohm direnç
- Breadboard
- 5 jumper kablo

## 3. Parça tanıtımı
Yeni parça yok. ak0185'teki 4 LED'lik devre aynen kullanılır.

## 4. Devre kurulumu
ak0185 ile birebir aynı:
1. 4 LED'i breadboard'a soldan sağa, yan yana tak.
2. 1. LED'in uzun bacağını (+) pin 3'e, 2.'yi pin 5'e, 3.'yü pin 6'ya, 4.'yü pin 9'a
   bağla (dört sinyal jumper'ı).
3. Her LED'in kısa bacağını (−) kendi 220 ohm direncine bağla. Dirençlerin boş
   uçlarını breadboard'ın ortak GND hattına tak, o hattı TEK bir jumper ile Arduino
   GND'ye bağla (toplam 5 jumper).
4. Arduino Uno'yu USB kablosuyla bilgisayara bağla.

**Bit sırası (alışılmış onluk yazımla eşleşsin diye):** EN SAĞDAKİ LED (pin 9) =
**1'ler basamağı** (en küçük değerli bit), EN SOLDAKİ LED (pin 3) = **8'ler basamağı**
(en büyük değerli bit) — tıpkı onluk sayılarda birler basamağının en sağda olması
gibi.

## 5. Kod açıklaması
| kod satırı | açıklama |
| --- | --- |
| `(sayi % 2) > 0` | 1'ler basamağı açık mı? (Sayı tek mi? — ak0160'ı hatırla.) |
| `(sayi % 4) > 1` | 2'ler basamağı açık mı? |
| `(sayi % 8) > 3` | 4'ler basamağı açık mı? |
| `(sayi % 16) > 7` | 8'ler basamağı açık mı? |
| `digitalWrite(ledler[i], LOW);` (döngüyle, en başta) | Her turun başında dört LED de söndürülür — `else` olmadan "önce hepsini kapat, sonra yalnız gerekenleri aç" yöntemi. |
| `if (sayi == 16) { sayi = 0; }` | 15'ten sonra sayaç sıfıra döner (else yok, tek koşul). |

### İleri analiz [ileri]
**Neden `(sayi % 4) > 1`?** `sayi % 4` sonucu 0, 1, 2 ya da 3 olabilir. 2'ler basamağı
yalnız `sayi % 4` 2 ya da 3 olduğunda açıktır — yani `1`'den **büyük** olduğunda. Aynı
mantık her basamak için tekrarlanır: `% (basamağın 2 katı)` sonucu, basamağın kendi
değerinden büyükse o basamak açıktır. Bu, ak0160'taki `sayi % 2 != 0` sorusunun dört
basamağa genişletilmiş hâlidir.

**Kaynak koddaki üç hata ve düzeltmesi:** (1) `pinMode(pin[i], LOW)` yazılmıştı —
`pinMode` bir pinin GÖREVİNİ (giriş/çıkış) ayarlar, LED'i söndürmez; doğrusu
`digitalWrite(ledler[i], LOW)`. (2) Kaynakta hem programın en üstünde hem döngü
içinde aynı isimde (`i`) iki değişken vardı, bu kafa karıştırıcıydı; sayaca `sayi`
adı verilip `i` yalnız döngülerde bırakıldı. (3) Kaynak `else` kullanıyordu; bu düzeyde
`else` yok, bu yüzden önce dört LED söndürülüp sonra yalnız açık olması gerekenler
tek tek `if` ile yakıldı.

## 6. Çalıştır ve gözlemle
Devreyi kur, kodu karta yükle. Seri Monitör'ü aç, hızı **9600** seç. LED'ler 0'dan
15'e kadar ikilik sayarken (dördü de sönük = 0, dördü de yanık = 15) Seri Monitör
aynı sayıyı onluk olarak yazar, saniyede bir ilerler.

### Sorun giderme
- **Hiçbir LED yanmıyor** → Kod yüklenmemiş olabilir; doğru kartı ve portu seçip
  tekrar yükle.
- **LED'ler yanıyor ama Seri Monitör'deki sayıyla uyuşmuyor gibi** → Bit sırasını
  (pin 9 = 1'ler, pin 3 = 8'ler) unutmuş olabilirsin; en sağdaki LED en küçük
  basamaktır — tıpkı onluk sayılardaki gibi.
- **15'ten sonra sayı garip davranıyor** → `if (sayi == 16) { sayi = 0; }` satırı
  silinmiş ya da bozulmuş olabilir.
- **Bazı LED'ler hiç yanmıyor** → O LED ters takılmış olabilir; uzun bacağın pine,
  kısa bacağın kendi direncine gittiğini kontrol et.
- **Ekrandaki sayılar Seri Monitör'de anlamsız karakterlerden oluşuyor** → Seri
  Monitör hızı 9600 değil.

## 7. Mini sınav
1. [temel] `sayi` 5 iken hangi LED'ler yanar?
   - A) Yalnız pin 9
   - B) Pin 9 ve pin 5
   - C) Hepsi
   - D) Hiçbiri
   - ipucu: 5 = 4 + 1; 1'ler pin 9'da, 4'ler pin 5'te.

2. [temel] En sağdaki LED (pin 9) hangi basamağı temsil eder?
   - A) 1'ler
   - B) 2'ler
   - C) 4'ler
   - D) 8'ler
   - ipucu: Devre kurulumundaki "Bit sırası" notuna bak.

3. [temel] Kod neden `else` kullanmıyor?
   - A) `else` bu düzeyde henüz öğretilmedi
   - B) `else` Arduino'da yok
   - C) Yazım hatası
   - D) `else` yalnız LED'lerde çalışmaz
   - ipucu: Başlıktaki notu oku.

4. [temel] Bu dersin devresi hangi eski dersle aynıdır?
   - A) ak0185 (dizi)
   - B) ak0070 (trafik lambası)
   - C) ak0040 (iki LED)
   - D) ak0020 (harici LED)
   - ipucu: Pinler 3, 5, 6, 9.

5. [ileri] `(sayi % 4) > 1` ifadesi ne zaman doğru olur?
   - A) sayi % 4 sonucu 0 ya da 1 ise
   - B) sayi % 4 sonucu 2 ya da 3 ise
   - C) sayi çift ise
   - D) Hiçbir zaman
   - ipucu: `%4`'ün sonucu 0,1,2,3 olabilir.

6. [ileri] Kaynak kodun `pinMode(pin[i], LOW)` satırı neden yanlıştı?
   - A) Yazım hatası, çalışırdı
   - B) `pinMode` pinin görevini (giriş/çıkış) ayarlar, LED'i söndürmez
   - C) `LOW` bir sayı değil
   - D) `pinMode` sadece `setup()`'ta kullanılabilir
   - ipucu: LED söndürmek için hangi komut kullanılır?

## 8. AI Yoldaşı promptları

> **Not:** AI Yoldaşı sana devrenin nasıl kurulacağını, hangi pine bağlayacağını ya da
> hangi direnci kullanacağını söylemez — bunlar sadece derste yazar. **AI'ın dediği
> devrende çalışmıyorsa AI yanılmıştır, devren haklıdır.**

- [temel] **Eşleştirme** — "Sen sabırlı bir öğretmensin. Arduino Uno kartında 5V mantık
  gerilimiyle çalışan binary sayıcı devremde 4 LED pin 3, 5, 6, 9'da; pin 9 en küçük
  basamak (en sağ), pin 3 en büyük basamak (en sol). Seri Monitör'deki onluk sayıyla
  yanan LED'leri eşleştirmeme yardım et. Pin veya bağlantı tarifi verme, cevabı
  söyleme; sayıyı 4+2+1 gibi parçalara ayırmamı sağlayan sorular sor."
- [temel] **Hata giderme** — "Sen bir hata ayıklama koçusun. Arduino Uno kartında 5V
  mantık gerilimiyle çalışan binary sayıcı devremde 4 LED pin 3, 5, 6, 9'da. LED'ler
  ekrandaki sayıyla uyuşmuyor gibi görünüyor. Pin veya bağlantı tarifi verme; bit
  sırasını (hangi pin hangi basamak) kontrol etmemi sağlayan sorular sor."
- [ileri] **Kavram derinleştirme** — "Sen ileri seviye bir mentorsun. Arduino Uno
  kartımda seri hız 9600; `(sayi % 4) > 1` gibi ifadelerin bir basamağın açık olup
  olmadığını nasıl söylediğini anlamama yardım et. Cevabı verme, `% 4`'ün
  alabileceği tüm sonuçları (0,1,2,3) listeletecek sorular sor."
- [temel] **Yanındaki Yetişkine** — "Cevabı söylemeyin. Şu üç şeyi sırayla sorun: Seri
  Monitör'de hangi sayı yazıyor? Hangi LED'ler yanık? Yanık LED'lerin basamak
  değerlerini toplarsa ekrandaki sayıyı buluyor mu?"

## 9. SEN YAP
1. Seri Monitör'de yazan onluk sayı ile yanan LED'leri karşılaştır. `Sayi: 5` iken
   hangi LED'ler yanıyor?
2. `delay(1000)` değerini değiştir, sayma hızını ayarla.
3. İleri: sayma yönünü ters çevir — 15'ten 0'a insin.
