---
ak_no: ak0210
baslik: "Buton: INPUT, digitalRead, pull-down"
duzey: 0-temel
unite: 2-Buton
kazanimlar:
  - cpp.pinmode
  - cpp.digitalread
  - hw.buton-devre
  - hw.pull-down
onkosul:
  - cpp.pinmode/cpp.digitalwrite (ak0010)
  - cpp.if (ak0160)
kara_kutu: [void]
merak_kosesi: "atlandı (rotasyon boş — OUTPUT bu derste kara kutu tanıtımı olarak değil, INPUT ile birlikte GERÇEK açılışını yapıyor)"
malzeme:
  - Arduino Uno kartı
  - USB kablosu
  - Paket 5 devresi (4 LED, 4x220 ohm, pin 3/5/6/9)
  - 1 buton
  - 1 adet 10 kΩ direnç (pull-down)
board:
  kart: Arduino Uno
  buton_pinleri: [2, 8]
  pull_direnci: "10 kΩ, pull-down"
  basili_degeri: HIGH
  seri_port_pinleri: [0, 1]
  seri_hiz: 9600
kaynak:
  - "..\\arsiv\\010butonLedKolay\\010butonLedKolay.ino"
---

## 1. Hedef
Bir butonu devrene ekleyip `digitalRead()` ile "basılı mı, değil mi" diye
okuyacaksın; LED'i sadece basılıyken yakacaksın.

## 2. Malzemeler
- Arduino Uno kartı
- USB kablosu
- Paket 5 devresi (4 LED, 4×220 ohm, pin 3/5/6/9) — sökülmez
- 1 buton
- 1 adet 10 kΩ direnç

## 3. Parça tanıtımı
**Buton:** basılınca iki bacağını birbirine bağlayan bir anahtar.
**Pull-down direnç (10 kΩ):** buton basılı DEĞİLKEN pinin ne okuyacağı belirsizdir
("havada kalır"); bu direnç pini GND'ye "çekerek" basılı değilken kesin `LOW`
okunmasını garanti eder. Buton basılınca pin doğrudan 5V'a bağlanır, `HIGH` okunur.

## 4. Devre kurulumu
Paket 5 devresi (4 LED, pin 3/5/6/9, ortak GND hattı) kuruluysa dokunma. Yeni:
- Buton bir bacağı → 5V.
- Butonun aynı sıradaki öbür bacağı → hem pin 2'ye HEM 10 kΩ direncin bir ucuna.
- 10 kΩ direncin öbür ucu → GND.

Sonuç: buton basılı iken pin 2 doğrudan 5V'a bağlı (`HIGH`); bırakılmışken direnç
pini GND'ye çeker (`LOW`).

## 5. Kod açıklaması
| kod satırı | açıklama |
| --- | --- |
| `pinMode(butonPin, INPUT);` | Bu pin artık İÇERİYİ okuyacak (dışarı yazmayacak). |
| `digitalRead(butonPin)` | Pinin şu an `HIGH` mi `LOW` mu olduğunu okur. |
| `digitalWrite(ledPin, LOW);` | Her turun başında LED önce söndürülür (`else` henüz yok). |
| `if (digitalRead(butonPin) == HIGH)` | Basılıysa (`HIGH`) LED'i yak. |

**`OUTPUT`/`INPUT` — söz verilen açılış:** Ünite 0'dan beri `pinMode`'a hep `OUTPUT`
yazıyorduk, "bu pin dışarı yazacak" demek için. Burada `INPUT` yazıyoruz, "bu pin
içeriyi okuyacak" demek için — ikisi birbirinin tam karşılığı, `pinMode`'un
kendisi hiç değişmedi, sadece hangi görevi verdiğimiz değişti.

### İleri analiz [ileri]
`digitalRead()`, `digitalWrite()`'ın tam tersidir: `digitalWrite` bizim karar
verdiğimiz bir değeri pine YAZAR (kart bilmez, biz söyleriz); `digitalRead` pinin
GERÇEKTE ne olduğunu OKUR (kart ölçer, bize söyler). Bir pin aynı anda hem OUTPUT
hem INPUT olamaz — `pinMode` hangisini seçtiğini kaydeder.

## 6. Çalıştır ve gözlemle
Kodu karta yükle. Butona bas — pin 6'daki LED yanmalı. Bırak — sönmeli.

### Sorun giderme
- **LED hiç yanmıyor** → Butonun 5V bacağı gerçekten 5V'a mı bağlı, kontrol et.
- **LED hep yanıyor, buton fark etmiyor** → Pull-down direnç eksik olabilir ya da
  yanlış bacaklara takılmış olabilir; pin havada kalıp rastgele HIGH okuyor olabilir.
- **Buton basıldığında LED YANMASI gerekirken SÖNÜYOR (ya da tam tersi)** →
  `== HIGH` yerine yanlışlıkla `== LOW` yazılmış olabilir (bu, pull-up devresinin
  mantığıdır, bizim devremiz pull-down).
- **4 bacaklı buton hiç tepki vermiyor** → Butonun 4 bacağı iki çift hâlindedir:
  aynı kenardaki iki bacak çoğu butonda içeriden birbirine bağlıdır (hangi numaranın hangisi olduğu üreticiye göre değişir). Emin değilsen butonu 90° çevir ya da bacakları ÇAPRAZ köşeden kullan; çapraz köşe her tip butonda çalışır. İki kabloyu aynı çifte taktıysan
  buton ya hiç tepki vermez ya da hep basılı görünür.
- **Buton "hep basılı" görünüyor** → İki bacağı zaten breadboard'ın aynı hattında
  olabilir (buton devreye kısa devre yapıyor); bacakları farklı hatlara ayır.

## 7. Mini sınav
1. [temel] `INPUT` ile `OUTPUT` arasındaki fark nedir?
   - A) Hiç fark yok
   - B) INPUT pin okur (içeri), OUTPUT pin yazar (dışarı)
   - C) INPUT daha hızlıdır
   - D) OUTPUT sadece LED için kullanılır
   - ipucu: "in" = içeri, "out" = dışarı.

2. [temel] Bizim devremizde (pull-down) buton basılıyken pin ne okur?
   - A) LOW
   - B) HIGH
   - C) Rastgele
   - D) 0.5V
   - ipucu: Basılı olduğunda pin doğrudan 5V'a bağlanıyor.

3. [temel] Pull-down direnç ne işe yarar?
   - A) LED'i korur
   - B) Buton basılı değilken pinin kesin LOW okumasını sağlar
   - C) Butonu hızlandırır
   - D) Seri portu açar
   - ipucu: "Havada kalan pin" sorununu çözüyor.

4. [temel] Bu dersin devresinde kaç LED, kaç buton var?
   - A) 4 LED, 1 buton (Paket 5 devresi + 1 buton)
   - B) 1 LED, 1 buton
   - C) 4 LED, 2 buton
   - D) Devre yok
   - ipucu: Paket 5 devresi sökülmedi, üstüne 1 buton eklendi.

5. [ileri] `digitalRead()` ile `digitalWrite()` birbirinin tersi mi, aynısı mı?
   - A) Aynısı
   - B) Tam tersi — biri okur (kart söyler), biri yazar (biz söyleriz)
   - C) İkisi de yazar
   - D) İkisi de okur
   - ipucu: "read" = oku, "write" = yaz.

6. [ileri] Bir pin aynı anda hem INPUT hem OUTPUT olabilir mi?
   - A) Evet, ikisi birlikte kullanılabilir
   - B) Hayır — pinMode hangisini seçtiğini kaydeder, ikisi aynı anda olamaz
   - C) Sadece dijital pinlerde olabilir
   - D) Sadece analog pinlerde olabilir
   - ipucu: pinMode bir GÖREV atar, iki görev birden verilmez.

## 8. AI Yoldaşı promptları

> **Not:** AI Yoldaşı sana devrenin nasıl kurulacağını söylemez — pull-down
> direncin bacak sırasını sen deneyerek bulursun. **AI'ın dediği kartında
> çalışmıyorsa AI yanılmıştır, kartın haklıdır.**

- [temel] **Eşleştirme** — "Sen sabırlı bir öğretmensin. Arduino Uno kartımda pin 6'da
  1 LED, pin 2'de pull-down dirençli 1 buton var; basılı = HIGH okunuyor. INPUT ile
  OUTPUT'un farkını anlamama yardım et. Cevabı söyleme; hangi pinin okuduğunu,
  hangisinin yazdığını buldurcak sorular sor."
- [temel] **Hata giderme** — "Sen bir hata ayıklama koçusun. Arduino Uno kartımda pin
  2'de pull-down dirençli bir buton var; LED butona basılı değilken de yanıyor.
  Cevabı verme; pull-down direncin bağlantısını ve == HIGH/== LOW karşılaştırmasını
  kontrol ettirecek sorular sor."
- [ileri] **Kavram derinleştirme** — "Sen ileri seviye bir mentorsun. Arduino Uno
  kartımda pull-down dirençli bir buton var; direnç sökülünce pinin neden
  'havada kalıp' kararsız bir değer okuduğunu anlamama yardım et. Cevabı söyleme,
  pinin bağlı olmadığı durumda neden belirli bir değere 'çekilmesi' gerektiğini
  buldurcak sorular sor."
- [temel] **Yanındaki Yetişkine** — "Cevabı söylemeyin. Şu üç şeyi sırayla sorun:
  Buton basılıyken pin ne okuyor? Pull-down direnç hangi iki noktayı birbirine
  bağlıyor? INPUT ile OUTPUT arasındaki fark ne?"

## 9. SEN YAP
1. 10 kΩ direnci SÖK (pin 2'yi "havada" bırak). `setup()`'a `Serial.begin(9600);`
   ekle, `loop()`'a `Serial.println(digitalRead(butonPin));` koy (ak0199'daki
   "değeri yazdırıp bak" yöntemi). Butona hiç dokunmadan Seri Monitör'de ne
   görüyorsun? (Kartına göre değişebilir — havada kalan bir pin dokunulmadığında
   zıplayabilir, "kesin şu olur" diye bir kural yok.) Sonra direnci geri tak, fark
   neydi?
2. Devredeki başka bir LED'i (pin 3, 5 ya da 9) de aynı butonla yak.
3. [ileri] `if (digitalRead(butonPin) == HIGH)` yerine `if (digitalRead(butonPin))`
   yazılsa ne olurdu? (İpucu: `HIGH` aslında `1`'dir, `if` sıfır olmayan bir sayıyı
   "doğru" sayar.)
