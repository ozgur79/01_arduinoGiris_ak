---
ak_no: ak0040
baslik: İki LED sırayla
duzey: 0-temel
unite: 0-LED
kazanimlar:
  - cpp.pinmode
  - cpp.digitalwrite
  - cpp.delay
  - cpp.coklu-cikis
  - hw.coklu-led
kara_kutu: [void, OUTPUT]
merak_kosesi: OUTPUT (1. tur)
malzeme:
  - Arduino Uno kartı
  - USB kablosu
  - 2 LED (mümkünse farklı renkte)
  - 2 adet 220 ohm direnç
  - breadboard
  - 4 jumper kablo
board:
  kart: Arduino Uno
  harici_led_pin_1: 8
  harici_led_pin_2: 9
  mantik_gerilimi: 5V
  direnc: 220 ohm
kaynak: arsiv/006ikiLed/006ikiLed.ino (pin 13/12 yerine 8/9)
---

## 1. Hedef
Şimdiye kadar tek bir LED'i yönettin. Bu derste devrene ikinci bir LED ekleyip **ikisini
birlikte** yöneteceksin: biri yanarken diğeri sönük olacak, sonra sıra değişecek. İki
lambanın sırayla yanması, ilerideki trafik lambasının ve kara şimşeğin temelidir.

## 2. Malzemeler
- Arduino Uno kartı
- USB kablosu
- 2 LED (mümkünse farklı renkte — hangisinin yandığını ayırt etmek kolaylaşır)
- 2 adet 220 ohm direnç
- breadboard
- 4 jumper kablo

## 3. Parça tanıtımı
Bu derste yeni parça yok, sadece **sayı** değişiyor: ak0020'de tanıdığın LED ve dirençten
ikişer tane kullanıyorsun. Her LED'in kendi direnci olmalı — iki LED tek dirençle
beslenirse ikisi de sönük yanar.

## 4. Devre kurulumu
ak0030'un devresi duruyorsa sökme, üstüne ikinci LED'i ekle:
1. İkinci LED'i breadboard'a, birincinin yanına tak.
2. İkinci LED'in uzun bacağından (+) bir jumper kabloyla Arduino'nun 9 numaralı pinine bağlan.
3. İkinci LED'in kısa bacağını (−) ikinci 220 ohm dirence bağla.
4. Bu direncin diğer ucundan bir jumper kabloyla Arduino'nun GND pinine bağlan.

Metin şeması:
- 1. LED uzun bacak (+) → pin 8, kısa bacak (−) → 220 ohm direnç → GND
- 2. LED uzun bacak (+) → pin 9, kısa bacak (−) → 220 ohm direnç → GND

## 5. Kod açıklaması
| kod satırı | açıklama |
| --- | --- |
| `// Her pinin kendi pinMode satırı olur: iki LED kullanıyorsan iki satır yazarsın` | Her pinin kendi `pinMode` satırı olur: iki LED kullanıyorsan iki satır yazarsın. |
| `// Aynı loop() içinde iki pin birbirinden bağımsız olarak açılıp kapatılabilir` | Aynı `loop()` içinde iki pin birbirinden bağımsız olarak açılıp kapatılabilir. |
| `// Bir LED yanarken diğerinin sönük olmasına "zıt durum" denir` | Bir LED yanarken diğerinin sönük olmasına "zıt durum" denir. |
| `pinMode(8, OUTPUT);` | 8. pini, açıp kapatabileceğimiz bir pin yap. |
| `pinMode(9, OUTPUT);` | 9. pini, açıp kapatabileceğimiz bir pin yap. |
| `digitalWrite(8, HIGH);` | 8. pini aç -> 1. LED yanar. |
| `digitalWrite(9, LOW);` | 9. pini kapat -> 2. LED söner. |
| `delay(300);` (birinci) | Bu durumu 300 milisaniye koru. |
| `digitalWrite(8, LOW);` | 8. pini kapat -> 1. LED söner. |
| `digitalWrite(9, HIGH);` | 9. pini aç -> 2. LED yanar. |
| `delay(300);` (ikinci) | Bu durumu da 300 milisaniye koru. |
| `}` (setup ve loop sonu) | `;` bir komutun bittiğini, `}` bloğun bittiğini gösterir. |

### İleri analiz [ileri]
`digitalWrite()` bir "çakma" değil, bir **anahtar**: pini o duruma getirir ve sen
değiştirene kadar orada tutar. Bu yüzden `delay(300)` satırı boyunca 8. pin açık, 9. pin
kapalı kalır — Arduino o sırada başka bir iş yapmasa bile pinlerin durumu bozulmaz.

`delay()`'in bir bedeli de burada görünüyor: `delay(300)` çalışırken program **başka
hiçbir şey yapamaz.** Bu yüzden SEN YAP 2'deki 300/900 gibi birbirinin katı olan süreler
kolayca kurulur, ama "biri 300, diğeri 400 milisaniyede yanıp sönsün" gibi bağımsız
ritimler `delay()` ile kurulamaz. Bunun çözümünü (`millis()`) seri port ünitesinde
göreceğiz.

Bir tam tur (1. LED yanık + 2. LED yanık) 300 + 300 = 600 milisaniye sürüyor, yani her
LED saniyede yaklaşık 1,7 kez yanıp sönüyor (`1000 / 600`).

## 6. Çalıştır ve gözlemle
Kod karta yüklendiğinde iki LED sırayla yanar: 8'e bağlı LED yanarken 9'a bağlı LED
sönük, 300 milisaniye sonra tersi. İkisi hiçbir zaman aynı anda yanmaz ve hiçbir zaman
aynı anda sönük kalmaz — devrede sürekli bir ışık vardır, sadece yeri değişir.

### Sorun giderme
- **İki LED de aynı anda yanıyor** → Aynı `delay()`'den önceki iki `digitalWrite`
  satırının ikisi birden `HIGH` olmamalı; zıt durum için biri `HIGH`, biri `LOW` olur.
- **Sadece bir LED çalışıyor, diğeri hiç yanmıyor** → Üç şeyi sırayla kontrol et: o
  LED'in `pinMode` satırı yazılmış mı, LED ters takılmış mı, kablo doğru pinde mi.
- **İkisi de hiç yanmıyor** → GND bağlantısını kontrol et; iki LED'in direnci de GND'ye
  ulaşmalı.
- **İkisi de çok sönük yanıyor** → İki LED tek dirence bağlanmış olabilir; her LED'in
  kendi direnci olmalı.
- **LED'ler yanıyor ama sırayı takip edemiyorsun** → İki LED'i farklı renk seç; aynı
  renkte iki LED'de sıra izlemek zordur.

## 7. Mini sınav
1. [temel] Bu derste kaç tane `pinMode` satırı var, neden?
   - A) 1 tane — bir kart var
   - B) 2 tane — iki ayrı pin kullanılıyor ✅
   - C) 4 tane — her LED'in iki bacağı var
   - D) Hiç yok — `digitalWrite` yeterli
   - ipucu: KAVRAM'ın ilk yorum satırına bak.

2. [temel] "Zıt durum" ne demek?
   - A) İki LED aynı anda yanar
   - B) İki LED aynı anda söner
   - C) Biri yanarken diğeri sönüktür ✅
   - D) LED'ler ters takılmıştır
   - ipucu: KAVRAM'ın üçüncü yorum satırına bak.

3. [temel] Her LED'in neden kendi direnci olmalı?
   - A) İki LED tek dirençle beslenirse ikisi de sönük yanar ✅
   - B) Arduino iki direnç ister
   - C) Direnç LED'in rengini belirler
   - D) Gerekli değil, tek direnç yeter
   - ipucu: §3 Parça tanıtımı.

4. [temel] 9'a bağlı LED hiç yanmıyor, 8'e bağlı çalışıyor. İlk bakacağın üç şey nedir?
   - A) USB kablosu, bilgisayar, Arduino IDE
   - B) `pinMode(9, OUTPUT)` satırı, LED'in yönü, kablonun pini ✅
   - C) Direncin rengi, breadboard'un markası, LED'in boyu
   - D) `delay()` süresi, kartın modeli, GND
   - ipucu: §6 Sorun giderme.

5. [ileri] `digitalWrite(8, HIGH);` yazdıktan sonra `delay(300);` çalışırken 8. pin ne
   durumdadır?
   - A) 300 milisaniye boyunca açık kalır ✅
   - B) Bir an açılıp hemen kapanır
   - C) Sürekli açılıp kapanır
   - D) `delay()` bitene kadar kapalıdır
   - ipucu: `digitalWrite` bir çakma değil, bir anahtar.

6. [ileri] "8'e bağlı LED 300 ms'de, 9'a bağlı LED 400 ms'de yanıp sönsün" isteseydin,
   bunu bu derste öğrendiklerinle kurabilir miydin?
   - A) Evet, iki `delay()` yazmak yeterli
   - B) Hayır — `delay()` çalışırken program başka hiçbir şey yapamaz ✅
   - C) Evet, ama LED'leri ters takmak gerekir
   - D) Hayır, çünkü Arduino'da iki LED aynı anda kullanılamaz
   - ipucu: `delay()` beklerken program duruyor mu, çalışıyor mu?

## 8. AI Yoldaşı promptları
- [temel] **Kavramsal** — "Sen sabırlı bir öğretmensin. Öğrenciye iki LED'in 'zıt
  durumda' çalışmasını bir tahterevalliye benzeterek buldurmaya çalış: biri yukarıdayken
  diğeri aşağıdadır. Cevabı söyleme, önce 'ikisi birden yukarıda olabilir mi' diye sor."
- [temel] **Hata giderme** — "Sen bir hata ayıklama koçusun. Öğrencinin iki LED'inden
  biri hiç yanmıyor. Ona sırayla üç soru sor: o pin için `pinMode` satırı yazılmış mı,
  LED'in uzun bacağı pine mi bakıyor, kablo doğru pinde mi. Cevabı sen verme, sorularla
  yürüt."
- [ileri] **Pekiştirme** — "Sen ileri seviye bir mentorsun. Öğrenciye `digitalWrite`'ın
  bir 'çakma' mı yoksa bir 'anahtar' mı olduğunu sor. `delay(300)` sırasında pinin ne
  durumda olduğunu düşündürerek kendi cevabını kurmasını sağla. Terimi sen söyleme."
- [ileri] **Tartışma** — "Sen meraklı bir tartışma arkadaşısın. Öğrenciye şu görevi ver:
  bir LED 300 ms'de, diğeri 400 ms'de yanıp sönsün. Kâğıt üzerinde denemesini iste ve
  neden `delay()` ile kurulamadığını kendisi fark etsin. Çözümü (`millis()`) sakın verme,
  sadece 'delay beklerken program ne yapıyor' diye sor."

## 9. SEN YAP
1) İki LED'i zıt değil, BİRLİKTE çalıştır: ikisi aynı anda yansın, aynı anda sönsün.
   Hangi satırları değiştirmen gerekiyor?
2) İlk hâline dön. Şimdi süreleri farklılaştır: 8'e bağlı LED 300 milisaniye yanık
   kalsın, 9'a bağlı LED 900 milisaniye yanık kalsın.
3) İki LED'i de sürekli yanık bırakan bir kod yazabilir misin? Dene ve gördüğünü yaz.
