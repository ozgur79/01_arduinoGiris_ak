---
ak_no: ak0155
baslik: "Sonsuz döngü: loop() aslında ne?"
duzey: 0-temel
unite: 1-LED-ve-Seri-Port
kazanimlar:
  - cpp.setup-loop
  - cpp.delay
  - cpp.pinmode
  - cpp.digitalwrite
  - cpp.sonsuz_dongu
  - hw.dahili-led
onkosul:
  - cpp.while (ak0150)
kara_kutu: [void, OUTPUT]
merak_kosesi: "while(1) vs while(true) köprü notu (rotasyon dışı, ak0020'deki { }/; gibi hemen açıklandı)"
malzeme:
  - Arduino Uno kartı
  - USB kablosu
board:
  kart: Arduino Uno
  dahili_led_pin: 13
  mantik_gerilimi: 5V
kaynak: kendi ak0010_dahiliLed kodun
---

## 1. Hedef
`loop()`'un aslında kartın senin yerine yazdığı bir **sonsuz döngü** olduğunu
göreceksin. ak0010'daki yanıp sönen LED kodunu, bu kez kendi yazdığın bir sonsuz
döngünün (`while (true)`) içine taşıyacaksın. Yeni fikir yok, bilerek — LED aynı
davranışı gösterecek.

## 2. Malzemeler
- Arduino Uno kartı
- USB kablosu

Devre yok — ak0010'daki dahili LED (pin 13), yeni malzeme yok.

## 3. Parça tanıtımı
Yeni parça yok. ak0010'daki dahili LED aynen kullanılıyor.

## 4. Devre kurulumu
Devre yok — dahili LED zaten pin 13'e bağlı, hazır.

## 5. Kod açıklaması
| kod satırı | açıklama |
| --- | --- |
| `pinMode(13, OUTPUT);` | ak0010'daki gibi, 13. pin çıkış yapılır. |
| `while (true) {` | Koşulu hiç yanlış olmayan bir döngü başlar — `true` (doğru) hep doğru olduğu için asla durmaz. |
| `digitalWrite(13, HIGH); delay(1000); digitalWrite(13, LOW); delay(1000);` | ak0010'daki `loop()` içeriğiyle birebir aynı dört satır. |
| `}` | `while (true)` bloğu burada biter — ama hiçbir zaman gerçekten "biter"e ulaşılmaz, döngü hep başa döner. |
| `void loop() { }` | Boş. Sonsuz döngü artık `setup()` içinde, `loop()`'a hiç sıra gelmiyor. |

### İleri analiz [ileri]
ak0010'da LED'i yakıp söndüren dört satır `loop()` içindeydi; kart bu satırları kendi
sonsuz döngüsüyle (`loop()`'un kendisiyle) tekrarlıyordu. Burada aynı dört satır
`setup()` içine, kendi yazdığımız `while (true)` bloğunun içine taşındı. Kartın
davranışı **birebir aynı** çünkü aslında hep aynı şeyi yapıyorduk: `loop()` da bir
sonsuz döngüdür, biz sadece onu bu kez kendi ellerimizle, farklı bir yerde yazdık.

## 6. Çalıştır ve gözlemle
Kodu karta yükle. Kartın üzerindeki "L" yazılı LED saniyede bir yanıp söner — ak0010
ile birebir aynı görüntü.

### Sorun giderme
- **LED hiç yanmıyor** → Kod yüklenmemiş olabilir; "Done uploading" mesajını kontrol
  et.
- **LED sürekli yanık/sönük, yanıp sönmüyor** → İki `delay()` satırının da silinmediğinden
  emin ol.
- **"BITTI" yazısını eklemene rağmen hiç görünmüyor (SEN YAP 2)** → Bu beklenen
  sonuçtur, hata değil; §5'teki "İleri analiz"i tekrar oku.

## 7. Mini sınav
1. [temel] `while (true)` ne zaman durur?
   - A) 10 tur sonra
   - B) Hiçbir zaman
   - C) LED söndüğünde
   - D) `delay` bittiğinde
   - ipucu: `true` hiç yanlış olmaz.

2. [temel] Bu derste `loop()` içinde ne var?
   - A) LED kodu
   - B) Hiçbir şey, boş
   - C) `while (true)`
   - D) `Serial.println`
   - ipucu: Koda bak.

3. [temel] ak0010 ile bu dersin LED davranışı arasındaki fark nedir?
   - A) Bu derste LED daha hızlı yanıp söner
   - B) Fark yok, ikisi de aynı davranışı gösterir
   - C) Bu derste LED hiç yanmaz
   - D) Bu derste iki LED var
   - ipucu: "Yeni fikir yok, bilerek" başlıkta yazıyor.

4. [temel] Bu dersin devresi nedir?
   - A) Devre yok, dahili LED
   - B) 1 harici LED
   - C) 4 LED
   - D) Buton
   - ipucu: Başlıktaki "Devre" satırına bak.

5. [ileri] `while (true)` satırından SONRAKİ bir satır (örn. `Serial.println("BITTI")`)
   neden hiç çalışmaz?
   - A) Yazım hatası olduğu için
   - B) `while (true)` hiçbir zaman bitmediği için o satıra sıra gelmez
   - C) `Serial.begin` çağrılmadığı için
   - D) `loop()` boş olduğu için
   - ipucu: Döngü hiç durmuyorsa, döngüden sonraki satıra ne zaman sıra gelir?

6. [ileri] `while (true)` yerine `while (false)` yazılsaydı ne olurdu?
   - A) LED sürekli yanardı
   - B) `{ }` bloğunun içine hiç girilmezdi, LED hiç yanmazdı
   - C) Kod derlenmezdi
   - D) LED bir kere yanıp sönerdi
   - ipucu: Koşul hiçbir zaman doğru değilse blok hiç çalışmaz.

## 8. AI Yoldaşı promptları

> **Not:** AI Yoldaşı sana devrenin nasıl kurulacağını söylemez — bu derste zaten
> devre yok, dahili LED kullanılıyor. **AI'ın dediği kartında çalışmıyorsa AI
> yanılmıştır, kartın haklıdır.**

- [temel] **Eşleştirme** — "Sen sabırlı bir öğretmensin. Arduino Uno kartımda dahili
  LED (pin 13) kullanıyorum, devre yok. Kodum `while (true)` içinde LED'i yakıp
  söndürüyor. `loop()` ile `while (true)` arasındaki ilişkiyi anlamama yardım et.
  Cevabı söyleme; ikisinin neden aynı davranışı ürettiğini buldurmak için sorular sor."
- [temel] **Hata giderme** — "Sen bir hata ayıklama koçusun. Arduino Uno kartımda
  dahili LED kullanıyorum. `while (true)` bloğundan sonra eklediğim bir yazı satırı
  hiç görünmüyor. Cevabı verme; döngünün ne zaman bittiğini sorgulatan sorular sor."
- [ileri] **Kavram derinleştirme** — "Sen ileri seviye bir mentorsun. Arduino Uno
  kartımda dahili LED kullanıyorum. `while (true)`'dan çıkmanın mümkün olup
  olmadığını merak ediyorum. Cevabı söyleme (henüz `break` öğrenmedim), sadece
  'bu döngüden çıkmak için dışarıdan bir sinyal gerekir mi?' fikrini
  düşündürecek sorular sor."
- [temel] **Yanındaki Yetişkine** — "Cevabı söylemeyin. Şu üç şeyi sırayla sorun:
  LED nasıl davranıyor, ak0010'dakiyle aynı mı? `loop()` içinde ne var? `while (true)`
  hiç durur mu, çocuk bunu nasıl anladı?"

## 9. SEN YAP
1. Bu kodu ak0010'daki koduyla yan yana koy. İkisi de kartta aynı şeyi mi yapıyor?
   Hangi satırlar `loop()`'tan `setup()`'a taşındı?
2. `setup()` içine en başa `Serial.begin(9600);` ekle. `while (true)` bloğunun ALTINA
   (hâlâ `setup()` içinde, döngüden SONRA) `Serial.println("BITTI");` ekle. Kartta
   yükle, Seri Monitör'ü aç. "BITTI" hiç görünmüyor — neden?
3. `while (true)` satırını `while (false)` yap. Ne oluyor?

Şu soruyu defterine yaz, cevabını arama: Bu döngüden nasıl çıkılır? Cevabı iki ünite
sonra (butonla) göreceğiz.
