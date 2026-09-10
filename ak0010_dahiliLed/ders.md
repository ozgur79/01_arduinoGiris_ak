---
ak_no: ak0010
baslik: Dahili LED'i yakıp söndür
duzey: 0-temel
unite: 0-LED
kazanimlar:
  - cpp.setup-loop
  - cpp.delay
  - cpp.pinmode
  - cpp.digitalwrite
  - hw.dahili-led
kara_kutu: [void, "{ }", ";", OUTPUT]
malzeme:
  - Arduino Uno kartı
  - USB kablosu
board:
  kart: Arduino Uno
  dahili_led_pin: 13
  dahili_led_api: digitalWrite
  mantik_gerilimi: 5V
  direnc: yok
kaynak: arsiv/001dahiliLed/001dahiliLed.ino
---

## 1. Hedef
Bugün kod yazarak gerçek bir ışığı sen kontrol edeceksin. Arduino kartının üzerindeki
küçük bir LED'i yakıp söndüreceksin — bilgisayarına yazdığın birkaç satır kodun, gerçek
dünyada bir şeyi nasıl hareket ettirdiğini ilk kez göreceksin.

## 2. Malzemeler
- Arduino Uno kartı
- USB kablosu

## 3. Parça tanıtımı
- **Arduino Uno kartı** — kodunu çalıştıran, üzerine yüklediğin programı hatırlayan kart.
- **USB kablosu** — kartı bilgisayara bağlar; hem güç verir hem kodu karta taşır.
- **Dahili LED** — kartın üzerinde "L" yazısının yanında duran küçük ışık, bu derste
  yakıp söndüreceğin LED.

## 4. Devre kurulumu
Devre yok — bu kartta dahili LED zaten pin 13'e bağlı, hazır.

## 5. Kod açıklaması
| kod satırı | açıklama |
| --- | --- |
| `void setup() {` | setup() içindeki satırlar kart açılınca sadece 1 kez çalışır. |
| `pinMode(13, OUTPUT);` | 13. pini, açıp kapatabileceğimiz bir pin yap. |
| `}` | setup() burada biter. |
| `void loop() {` | loop() içindeki satırlar setup bitince sürekli baştan tekrar eder. |
| `digitalWrite(13, HIGH);` | 13. pini aç -> LED yanar. |
| `delay(1000);` | 1000 milisaniye (1 saniye) bekle. |
| `digitalWrite(13, LOW);` | 13. pini kapat -> LED söner. |
| `delay(1000);` | 1 saniye bekle. |
| `}` | loop() burada biter. |

### İleri analiz [ileri]
yok

## 6. Çalıştır ve gözlemle
Kod karta yüklendikten sonra, kartın üzerindeki "L" yazılı LED saniyede bir yanıp
söner: 1 saniye yanık, 1 saniye sönük, sürekli tekrar.

### Sorun giderme
- **LED hiç yanmıyor** → USB kablosu tam takılı mı, IDE'de yükleme "Done uploading"
  diyerek bitti mi kontrol et.
- **LED sürekli yanık ya da sürekli sönük, yanıp sönmüyor** → kodu yeniden yükle,
  iki `delay()` satırının da silinmediğinden emin ol.

## 7. Mini sınav
1. [temel] `pinMode(13, OUTPUT);` satırı ne işe yarar?
   - A) 13. pini bir giriş (buton gibi) pini yapar
   - B) 13. pini bir çıkış (LED gibi) pini yapar
   - C) LED'i doğrudan yakar
   - D) 1 saniye bekletir
   - ipucu: OUTPUT kelimesinin İngilizce anlamını düşün.

2. [temel] `delay(1000);` kaç saniye bekletir?
   - A) 1 saniye
   - B) 10 saniye
   - C) 100 saniye
   - D) 1000 saniye
   - ipucu: 1000 milisaniye kaç saniyeye eşittir?

3. [temel] `loop()` fonksiyonu kart açıkken kaç kez çalışır?
   - A) Sadece 1 kez
   - B) Kart kapanana kadar sürekli baştan
   - C) Tam olarak 2 kez
   - D) Hiç çalışmaz
   - ipucu: setup() ile loop() arasındaki fark neydi?

4. [ileri] `delay(1000)` yerine `delay(1000000)` yazılsaydı, LED yaklaşık kaç saniyede
   bir durum değiştirirdi?
   - A) 1 saniye
   - B) 100 saniye
   - C) 1000 saniye
   - D) 10000 saniye
   - ipucu: 1 saniye = 1000 milisaniye. 1.000.000 milisaniye kaç saniye eder?

5. [ileri] `digitalWrite(13, HIGH);` satırı yanlışlıkla `loop()` yerine `setup()`
   içine yazılsaydı ne olurdu?
   - A) LED hiç yanmazdı
   - B) LED kart açılırken bir kez yanar, bir daha hiç sönmezdi
   - C) Program derlenmezdi
   - D) Kart açılmazdı
   - ipucu: setup() ne zaman, kaç kez çalışıyordu?

## 8. AI Yoldaşı promptları
- [temel] **Kavramsal** — "Sen sabırlı bir öğretmensin. Bir öğrenciye setup() ve
  loop()'un farkını, gerçek hayattan bir benzetmeyle (örneğin sabah rutini ile her gün
  tekrar eden işler) buldurmaya çalış. Cevabı söyleme, önce bir soru sor."
- [temel] **Hata giderme** — "Sen bir hata ayıklama koçusun. Öğrenci delay() değerini
  değiştirdiğinde LED'in hızının değişmediğini söylüyor. Kodun hangi satırına
  bakması gerektiğini sorular sorarak buldur, cevabı doğrudan verme."
- [ileri] **Pekiştirme** — "Sen ileri seviye bir mentorsun. Öğrenciye milisaniye ile
  saniye arasındaki dönüşümü, farklı delay() değerleriyle (1000, 500, 2000) kendi
  kendine keşfettir. Formülü doğrudan söyleme, sorularla ilerlet."

## 9. SEN YAP
1) `delay(1000)` yazan iki satırdaki 1000 sayısını değiştir; LED'i daha hızlı ya da
   daha yavaş yakıp söndür.
2) İki `delay()` değerini birbirinden farklı yap (ör. yanma kısa, sönme uzun).
