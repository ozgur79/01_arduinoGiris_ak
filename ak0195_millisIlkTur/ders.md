---
ak_no: ak0195
baslik: "millis() 1. tur: iki LED, iki ritim"
duzey: 0-temel
unite: 1-LED-ve-Seri-Port
kazanimlar:
  - cpp.setup-loop
  - cpp.pinmode
  - cpp.digitalwrite
  - cpp.const-int
  - cpp.if
  - cpp.millis
  - cpp.unsigned_long
onkosul:
  - hw.gorme-esigi/delay (ak0010, ak0030), if (ak0160)
kara_kutu: [void, OUTPUT, unsigned]
merak_kosesi: "atlandı (yük freni — millis + unsigned long + durum çevirme kalıbı zaten ağır)"
malzeme:
  - Arduino Uno kartı
  - USB kablosu
  - 2 LED (ak0185/ak0190 devresinden pin 3 ve pin 9)
  - 2 adet 220 ohm direnç
  - breadboard
  - 3 jumper kablo (sıfırdan kuruluyorsa)
board:
  kart: Arduino Uno
  led_pinleri: [3, 9]
  mantik_gerilimi: 5V
  direnc: 220 ohm
kaynak:
  - ..\arsiv\003ikiLed_saniyede1saniyede2\003ikiLed_saniyede1saniyede2.ino (acının delay'li hâli)
---

## 1. Hedef
İki LED'i **aynı anda, birbirinden bağımsız hızlarda** yakıp söndüreceksin: biri
saniyede 1 kez, öteki saniyede 3 kez. Önce bunu `delay()` ile denemenin neden
imkânsıza yakın olduğunu göreceksin, sonra `millis()` ile gerçek çözümü kuracaksın.

**Başlamadan önce dene (ACI):** `delay(1000)` ile pin 3'ü, `delay(333)` ile pin 9'u
aynı `loop()` içinde yakıp söndürmeye çalış. Göreceksin: `delay(1000)` çalışırken
program TAMAMEN durur — pin 9'daki LED de o sırada hiçbir şey yapamaz. İki farklı
hızı `delay()` ile bir arada yürütemezsin.

## 2. Malzemeler
- Arduino Uno kartı
- USB kablosu
- 2 LED (ak0185/ak0190 devresinden pin 3 ve pin 9 kullanılır)
- 2 adet 220 ohm direnç
- Breadboard
- 3 jumper kablo (sıfırdan kuruluyorsa)

## 3. Parça tanıtımı
Yeni parça yok. **ak0185/ak0190'ın 4 LED'lik devresi kurulmuşsa hiçbir yeni jumper
gerekmez** — pin 3 ve pin 9'daki LED'ler aynen kullanılır, pin 5 ve 6 bu derste
boşta kalır.

## 4. Devre kurulumu
Sıfırdan kuruyorsan:
1. 1. LED'in uzun bacağını (+) pin 3'e, 2.'yi pin 9'a bağla (2 sinyal jumper'ı).
2. Her LED'in kısa bacağını (−) kendi 220 ohm direncine bağla. Dirençlerin boş
   uçlarını breadboard'ın ortak GND hattına tak, o hattı TEK bir jumper ile Arduino
   GND'ye bağla (toplam 3 jumper).
3. Arduino Uno'yu USB kablosuyla bilgisayara bağla.

## 5. Kod açıklaması
| kod satırı | açıklama |
| --- | --- |
| `unsigned long oncekiA = 0;` | LED A'nın en son ne zaman değiştiğini saklar (milisaniye cinsinden). |
| `const unsigned long aralikA = 500;` | LED A'nın durumunu her 500 ms'de bir değiştirmesi gerektiğini söyler (500+500=1000 ms'de bir tam yanıp sönme = saniyede 1). |
| `unsigned long simdi = millis();` | Şu anki zamanı okur — bekletmez, sadece sorar. |
| `if (simdi - oncekiA >= aralikA)` | "Son değişimden bu yana yeterince zaman geçti mi?" sorusu. |
| `durumA = 1 - durumA;` | LED'in durumunu çevirir: 0 ise 1, 1 ise 0 olur (`!` ya da `else` kullanmadan). |
| `digitalWrite(ledA, durumA);` | `durumA` 1 ise `HIGH`, 0 ise `LOW` ile birebir aynı etkiyi yapar (Arduino'da `HIGH` = 1, `LOW` = 0). |

### İleri analiz [ileri]
`millis()` kart açıldığından beri geçen milisaniyeyi bir **sayaç** gibi hep artan bir
değer olarak tutar — tıpkı bir duvar saati gibi, sen zamanı okursun, saat seni
beklemez. `delay()` ise programın TAMAMINI durdurur; o sırada başka hiçbir LED'in
durumu değişemez. `if (simdi - oncekiA >= aralikA)` kalıbı, "son kontrolden bu yana
yeterince zaman geçti mi?" diye sorar ve HER `loop()` turunda bu soruyu tekrar sorar —
bekleme yoktur, sadece sorgu vardır. İki LED birbirinden habersiz, kendi ritminde ilerler.

`millis()`'in sonucu neden `int` değil `unsigned long`? ak0150'nin Merak Köşesi'nde
`int`'in 32767'de taştığını görmüştün. `millis()` kart açıldıktan yalnızca ~32 saniye
sonra bile bu sınırı geçer — bu yüzden çok daha büyük bir kutuya (`unsigned long`)
ihtiyaç var. `unsigned` kelimesinin tam ayrıntısı ileri düzeyde açılacak; şimdilik
"hep pozitif, çok büyük bir sayı kutusu" demek yeterli.

## 6. Çalıştır ve gözlemle
Devreyi kur, kodu karta yükle. Pin 3'teki LED saniyede bir, pin 9'daki LED saniyede
üç kez yanıp söner — ikisi de aynı anda, birbirini hiç beklemeden.

### Sorun giderme
- **Hiçbir LED yanmıyor** → Kod yüklenmemiş olabilir; doğru kartı ve portu seçip
  tekrar yükle.
- **Yalnız bir LED yanmıyor** → O LED ters takılmış olabilir; uzun bacağın pine, kısa
  bacağın kendi direncine gittiğini kontrol et.
- **LED'ler hiç yanıp sönmüyor, hep aynı durumda** → `durumA = 1 - durumA;` satırı
  silinmiş olabilir; bu satır olmadan `digitalWrite` hep aynı değeri yazar.
- **İki LED'in hızı birbirine karışmış gibi** → `aralikA` ve `aralikB` değerlerinin
  `oncekiA`/`oncekiB` ile doğru eşleştiğini kontrol et (A ile A, B ile B).

## 7. Mini sınav
1. [temel] `millis()` ne yapar?
   - A) Programı 1000 ms bekletir
   - B) Kart açıldığından beri geçen milisaniyeyi söyler, beklemez
   - C) Bir LED'i yakar
   - D) Seri Monitör'ü açar
   - ipucu: `delay()`'den farkını düşün.

2. [temel] `durumA = 1 - durumA;` satırı ne işe yarar?
   - A) durumA'yı hep 1 yapar
   - B) durumA'yı 0 ise 1'e, 1 ise 0'a çevirir
   - C) durumA'yı sıfırlar
   - D) Hiçbir şey yapmaz
   - ipucu: durumA yerine 0 ve 1 koyup elle hesapla.

3. [temel] `loop()` içinde kaç tane `delay()` var?
   - A) 2
   - B) 1
   - C) 0
   - D) 4
   - ipucu: Kodu tara.

4. [temel] Bu dersin devresi kaç LED kullanır?
   - A) 4
   - B) 2
   - C) 1
   - D) 3
   - ipucu: Malzeme listesine bak.

5. [ileri] `if (simdi - oncekiA >= aralikA)` satırı ne soruyor?
   - A) Kart daha yeni mi açıldı?
   - B) Son değişimden bu yana yeterince zaman geçti mi?
   - C) LED yanık mı?
   - D) Seri port açık mı?
   - ipucu: `simdi - oncekiA` geçen süreyi verir.

6. [ileri] `millis()` neden `int` değil `unsigned long` döndürür?
   - A) Rastgele seçilmiş
   - B) `int` çok kısa sürede taşar, `millis()`'in büyük değerlerini tutamaz
   - C) `unsigned long` daha hızlı çalışır
   - D) `int` negatif sayı tutamaz
   - ipucu: ak0150'deki int taşmasını hatırla.

## 8. AI Yoldaşı promptları

> **Not:** AI Yoldaşı sana devrenin nasıl kurulacağını, hangi pine bağlayacağını ya da
> hangi direnci kullanacağını söylemez — bunlar sadece derste yazar. **AI'ın dediği
> devrende çalışmıyorsa AI yanılmıştır, devren haklıdır.**

- [temel] **Eşleştirme** — "Sen sabırlı bir öğretmensin. Arduino Uno kartında 5V mantık
  gerilimiyle çalışan iki LED'li devremde LED'ler pin 3 ve 9'da, her birinin 220 ohm
  direnci var. `millis()` ile `delay()` arasındaki farkı anlamama yardım et. Pin veya
  bağlantı tarifi verme, cevabı söyleme; `delay()`'in programı nasıl durdurduğunu
  gözlemleten sorular sor."
- [temel] **Hata giderme** — "Sen bir hata ayıklama koçusun. Arduino Uno kartında 5V
  mantık gerilimiyle çalışan iki LED'li devremde LED'ler pin 3 ve 9'da. LED'ler hiç
  yanıp sönmüyor. Pin veya bağlantı tarifi verme; `durumA = 1 - durumA;` satırının kodda
  olup olmadığını kontrol etmemi sağlayan sorular sor."
- [ileri] **Kavram derinleştirme** — "Sen ileri seviye bir mentorsun. Arduino Uno
  kartımda `millis()` tabanlı bir zamanlama kodum var. `if (simdi - onceki >= aralik)`
  kalıbının neden `delay()`'den daha esnek olduğunu anlamama yardım et. Cevabı verme,
  iki LED'in birbirini bekleyip beklemediğini sorgulatan sorular sor."
- [temel] **Yanındaki Yetişkine** — "Cevabı söylemeyin. Şu üç şeyi sırayla sorun: İki
  LED aynı anda mı yanıp sönüyor, yoksa biri diğerini mi bekliyor? `loop()` içinde
  `delay()` var mı? `durumA` değişkeni hangi iki değeri alabiliyor?"

## 9. SEN YAP
1. Üçüncü bir LED ekle (pin 5, ak0185/ak0190 devresinde zaten var): kendi
   `oncekiC`/`aralikC`/`durumC` değişkenlerini tanımla, üçüncü bir ritimle yanıp
   söndür.
2. `aralikA` ve `aralikB` değerlerini değiştir, LED'lerin hızını ayarla.
3. `loop()` içinde hiç `delay()` OLMADIĞINI fark ettin mi? İki LED birbirini hiç
   beklemiyor. `delay()` ile bunu yapmaya çalışsaydın ne olurdu? (Dersin başındaki
   ACI denemesine geri dön.)

Şu soruyu defterine yaz, cevabını arama: `loop()` içinde `delay()` OLSAYDI ve bir yere
buton eklesen, butona basınca ne olurdu? Üç ünite sonra buton dersinde bu soruya geri
döneceğiz.
