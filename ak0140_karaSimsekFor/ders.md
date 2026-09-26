---
ak_no: ak0140
baslik: "Kara şimşek, for ile (harcama dersi)"
duzey: 0-temel
unite: 1-LED-ve-Seri-Port
kazanimlar:
  - cpp.setup-loop
  - cpp.delay
  - cpp.pinmode
  - cpp.digitalwrite
  - cpp.const-int
  - cpp.coklu-cikis
  - hw.coklu-led
onkosul:
  - cpp.for (ak0130)
  - cpp.arttirma (ak0130)
kara_kutu: [void, OUTPUT]
merak_kosesi: "OUTPUT (3. tur, sonrasında emekli)"
malzeme:
  - Arduino Uno kartı
  - USB kablosu
  - 4 LED
  - 4 adet 220 ohm direnç
  - breadboard
  - 8 jumper kablo
board:
  kart: Arduino Uno
  led_pinleri: [8, 9, 10, 11]
  mantik_gerilimi: 5V
  direnc: 220 ohm
kaynak:
  - ..\arsiv\004karaSimsekIleri\004karaSimsekIleri.ino
  - ak0060_karaSimsek/ak0060_karaSimsek.ino
---

## 1. Hedef
Yeni fikir yok, bilerek: ak0060'ta elle yazdığın kara şimşek desenini `for` ile çok
daha kısa yazacaksın. Aynı ışık deseni, çok daha az satır. Dersin değeri bu
karşılaştırmada.

## 2. Malzemeler
- Arduino Uno kartı
- USB kablosu
- 4 LED
- 4 adet 220 ohm direnç
- Breadboard
- 8 jumper kablo

## 3. Parça tanıtımı
Yeni parça yok. ak0060'taki devre aynen kullanılır.

## 4. Devre kurulumu
1. 4 LED'i breadboard'a soldan sağa, yan yana tak.
2. 1. LED'in uzun bacağını (+) pin 8'e bağla.
3. 2. LED'in uzun bacağını (+) pin 9'a bağla.
4. 3. LED'in uzun bacağını (+) pin 10'a bağla.
5. 4. LED'in uzun bacağını (+) pin 11'e bağla.
6. Her LED'in kısa bacağını (−) kendi 220 ohm direncine bağla.
7. Her direncin boş ucunu GND'ye bağla.
8. Arduino Uno'yu USB kablosuyla bilgisayara bağla.

Metin şeması (ak0060 ile birebir aynı):
- 1. LED (+) → pin 8, (−) → 220 ohm direnç → GND
- 2. LED (+) → pin 9, (−) → 220 ohm direnç → GND
- 3. LED (+) → pin 10, (−) → 220 ohm direnç → GND
- 4. LED (+) → pin 11, (−) → 220 ohm direnç → GND

## 5. Kod açıklaması
| kod satırı | açıklama |
| --- | --- |
| `const int ilkLed = 8; const int sonLed = 11;` | Pinler ardışık olduğu için yalnızca ilk ve son pine isim veriliyor. |
| `for (int pin = ilkLed; pin <= sonLed; pin++) { pinMode(pin, OUTPUT); }` | Dört ayrı `pinMode` satırı yerine tek döngü; `pin` değişkeni doğrudan pin numarası. |
| İleri `for` (`pin = ilkLed` → `sonLed`) | 8, 9, 10, 11 sırasıyla yanıp söner. |
| Geri `for` (`pin = sonLed - 1` → `ilkLed + 1`) | 10, 9 sırasıyla yanıp söner — uç LED'lere (8 ve 11) tekrar dokunulmaz, çünkü onlar zaten bir kez yandı. |

### İleri analiz [ileri]
Kaynak kodda (`004karaSimsekIleri.ino`) bir dizi (`int all_pins[4]`) kullanılıyordu.
Dizi bu düzeyde henüz öğretilmedi (Modül 2'de gelecek), bu yüzden burada kullanılmadı:
pinler ardışık olduğu için döngü değişkeninin kendisi doğrudan pin numarası olarak
kullanıldı (`pin = 8, 9, 10, 11`). Kaynakta ayrıca bir desen hatası vardı — ileri döngü
`i < 3` ile (8, 9, 10'u kapsıyor, 11'i atlıyor), geri döngü `i = 3`'ten (11, 10, 9, 8)
başlıyordu. Bu, turlar arasında pin 8'in art arda iki kez yanmasına yol açıyordu. Kod
okunarak tespit edildi; ak0060'taki 1-2-3-4-3-2 deseniyle birebir aynı olacak şekilde
düzeltildi: ileri döngü tüm pinleri (8'den 11'e) kapsar, geri döngü uç pinlere (8 ve 11)
tekrar dokunmadan yalnızca aradakileri (10, 9) kapsar. Düzeltilmiş desen Özgür'ün kart
testiyle doğrulandı (2026-09-26).

**Karşılaştırma (ak0060 ↔ ak0140):**

| ders | digitalWrite+delay satırı | pinMode satırı |
|------|----------------------------|-----------------|
| ak0060 (elle) | 30 | 4 |
| ak0140 (for)  | 6  | 1 (for içinde) |

Aynı ışık deseni, aynı 6 adım (8-9-10-11-10-9), çok daha az yazılan satır.

## 6. Çalıştır ve gözlemle
Devreyi kur, kodu karta yükle. LED'ler sırayla 8-9-10-11-10-9 şeklinde yanıp söner,
sonra baştan başlar — ak0060 ile birebir aynı görüntü.

### Sorun giderme
- **Hiçbir LED yanmıyor** → Kod yüklenmemiş olabilir. Doğru kartı ve portu seçip
  yüklemeyi yeniden dene.
- **Yalnız bir LED yanmıyor** → O LED ters takılmış olabilir. Uzun bacağın pine, kısa
  bacağın kendi direncine gittiğini kontrol et.
- **Uç LED'lerden biri (8 ya da 11) art arda iki kez yanıyor gibi görünüyor** → Geri
  döngünün sınırları (`sonLed - 1` ve `ilkLed + 1`) değiştirilmiş olabilir; KAVRAM'daki
  hâliyle karşılaştır.
- **LED'ler sönük yanıyor** → LED'ler aynı direnci paylaşıyor olabilir. Her LED'in kendi
  220 ohm direnci olmalı.
- **Desen ak0060'takinden farklı** → `ilkLed` ve `sonLed` değerlerinin 8 ve 11 olduğunu
  kontrol et.

## 7. Mini sınav
1. [temel] Bu derste kaç `pinMode` satırı **elle** yazılıyor?
   - A) 4
   - B) 1 (for içinde tekrarlanıyor)
   - C) 0
   - D) 8
   - ipucu: `for` döngüsünün içine tek satır yazılıyor.

2. [temel] LED'ler hangi sırayla yanıp söner?
   - A) 8-9-10-11, sonra baştan
   - B) 8-9-10-11-10-9, sonra baştan
   - C) 11-10-9-8, sonra baştan
   - D) Rastgele
   - ipucu: İleri döngü tüm pinleri, geri döngü aradaki pinleri kapsar.

3. [temel] Bu dersin devresi hangi eski dersle aynıdır?
   - A) Trafik lambası
   - B) Kara şimşek (ak0060)
   - C) İki LED
   - D) Harici LED
   - ipucu: 4 LED, pin 8-11.

4. [temel] `pin` değişkeni bu derste neyi temsil ediyor?
   - A) Bir sayacı
   - B) Doğrudan pin numarasını
   - C) Bir LED rengini
   - D) Bekleme süresini
   - ipucu: Pinler ardışık olduğu için dizi gerekmiyor.

5. [ileri] Beşinci bir LED (pin 12) eklemek için kaç satır değiştirmen gerekir?
   - A) 1 (`sonLed = 12`)
   - B) 4
   - C) 10'dan fazla
   - D) Hiç, otomatik eklenir
   - ipucu: `for` sınırları `ilkLed` ve `sonLed`'e bağlı.

6. [ileri] Kaynak koddaki desen hatası neydi?
   - A) Hiç hata yoktu
   - B) İleri döngü bir pini atlıyor, geri döngü bir pini iki kez yakıyordu
   - C) LED'ler hiç yanmıyordu
   - D) `delay` eksikti
   - ipucu: İleri döngü `i < 3`, geri döngü `i = 3`'ten başlıyordu.

## 8. AI Yoldaşı promptları

> **Not:** AI Yoldaşı sana devrenin nasıl kurulacağını, hangi pine bağlayacağını ya da
> hangi direnci kullanacağını söylemez — bunlar sadece derste yazar. **AI'ın dediği
> devrende çalışmıyorsa AI yanılmıştır, devren haklıdır.**

- [temel] **Eşleştirme** — "Sen sabırlı bir öğretmensin. Arduino Uno kartında 5V mantık
  gerilimiyle çalışan kara şimşek devremde 4 LED pin 8, 9, 10, 11'de; her LED'in 220 ohm
  direnci var, devre yok seri port. Kodum `for` ile pinleri döngüyle tarıyor. Işıkların
  hangi sırayla yanması gerektiğini anlamama yardım et. Pin veya bağlantı tarifi verme,
  cevabı söyleme; bir tam turu adım adım gözlemleten sorular sor."
- [temel] **Hata giderme** — "Sen bir hata ayıklama koçusun. Arduino Uno kartında 5V
  mantık gerilimiyle çalışan kara şimşek devremde 4 LED pin 8-11'de. Bir uç LED art arda
  iki kez yanıyor gibi görünüyor. Pin veya bağlantı tarifi verme; geri döngünün başlangıç
  ve bitiş sınırlarını kontrol etmemi sağlayan sorular sor."
- [ileri] **Kod karşılaştırma** — "Sen ileri seviye bir mentorsun. Arduino Uno kartında
  5V mantık gerilimiyle çalışan kara şimşek devremde 4 LED pin 8-11'de. Elle yazılmış eski
  koduma (30 satır) karşı bu `for` versiyonunun (birkaç satır) nasıl aynı işi yaptığını
  anlamama yardım et. Cevabı verme; iki kodun hangi bölümlerinin birbirine karşılık
  geldiğini bulmam için sorular sor."
- [temel] **Yanındaki Yetişkine** — "Cevabı söylemeyin. Şu üç şeyi sırayla sorun: Işıklar
  hangi sırayla yanıyor? Uç LED'lerden biri (8 ya da 11) art arda iki kez yanıyor mu?
  `for` satırındaki `ilkLed` ve `sonLed` değerleri hangi pinler?"

## 9. SEN YAP
1. Kartta çalıştır, ak0060 ile aynı deseni gördüğünü doğrula: 8-9-10-11-10-9, sonra
   baştan.
2. Beşinci bir LED eklesen (pin 12), tek satırı (`sonLed = 11` → `12`) değiştirmen
   yeterli mi? ak0060'ta kaç satır değiştirmen gerekiyordu? Karşılaştır.
3. Aşağıdaki tabloyu kendi kodunla doldur: iki dersin `digitalWrite`+`delay` satır
   sayısını say.
