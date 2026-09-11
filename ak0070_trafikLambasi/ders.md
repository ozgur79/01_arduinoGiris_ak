---
ak_no: ak0070
baslik: Trafik lambası
duzey: 0-temel
unite: 0-LED
kazanimlar:
  - cpp.const-int
  - cpp.coklu-cikis
  - cpp.delay
  - hw.coklu-led
kara_kutu: [void, OUTPUT]
merak_kosesi: OUTPUT (2. tur)
malzeme:
  - Arduino Uno kartı
  - USB kablosu
  - 3 LED (kırmızı, sarı, yeşil)
  - 3 adet 220 ohm direnç
  - breadboard
  - 6 jumper kablo
board:
  kart: Arduino Uno
  kirmizi_led_pin: 8
  sari_led_pin: 9
  yesil_led_pin: 10
  mantik_gerilimi: 5V
  direnc: 220 ohm
kaynak: D:\ArduinoProjeleri\002Arduino\008trafikLambasi\008trafikLambasi.ino (pin 2/3/4 -> 8/9/10; pinler isimlendirildi)
---

## 1. Hedef
Üç LED'i kırmızı, sarı ve yeşil renkleriyle bir trafik lambasına dönüştüreceksin. Yeni bir
kod komutu öğrenmeyeceksin; önceki derslerde öğrendiklerini tek bir işe koyacaksın. Kırmızı
4 saniye, yeşil 3 saniye, sarı 1 saniye yanar. Sayılar değişince kod bozulmaz, lambanın
anlamı değişir.

## 2. Malzemeler
- Arduino Uno kartı
- USB kablosu
- Kırmızı, sarı ve yeşil LED
- 3 adet 220 ohm direnç
- Breadboard
- 6 jumper kablo

## 3. Parça tanıtımı
Yeni parça yok. Her renk için bir LED ve **kendi 220 ohm direnci** var. Kırmızı LED durmayı,
yeşil LED geçmeyi, sarı LED hazırlanmayı gösterecek.

## 4. Devre kurulumu
1. Kırmızı, sarı ve yeşil LED'i breadboard'a üstten alta sırasıyla tak.
2. Kırmızı LED'in uzun bacağını (+) pin 8'e bağla.
3. Sarı LED'in uzun bacağını (+) pin 9'a bağla.
4. Yeşil LED'in uzun bacağını (+) pin 10'a bağla.
5. Her LED'in kısa bacağını (-) kendi 220 ohm direncine bağla. Her direncin boş ucunu GND'ye bağla.

Metin şeması:
- Kırmızı LED (+) → pin 8, (-) → 220 ohm direnç → GND
- Sarı LED (+) → pin 9, (-) → 220 ohm direnç → GND
- Yeşil LED (+) → pin 10, (-) → 220 ohm direnç → GND

## 5. Kod açıklaması
| kod satırı | açıklama |
| --- | --- |
| `const int kirmizi = 8;` | Bu kartta 8 numaralı pine `kirmizi` adı verilir. |
| `const int sari = 9;` | Bu kartta 9 numaralı pine `sari` adı verilir. |
| `const int yesil = 10;` | Bu kartta 10 numaralı pine `yesil` adı verilir. |
| `pinMode(kirmizi, OUTPUT);` | Kırmızı LED'in bağlı olduğu pin, açılıp kapatılacak çıkış olur. |
| `digitalWrite(kirmizi, HIGH);` | Kırmızı LED'in pini açılır; kırmızı LED yanar. |
| `digitalWrite(sari, LOW);` | Sarı LED'in pini kapanır; sarı LED söner. |
| `digitalWrite(yesil, LOW);` | Yeşil LED'in pini kapanır; yeşil LED söner. |
| `delay(4000);` | Kırmızı ışığın durumu 4000 milisaniye, yani 4 saniye sürer. |
| `delay(3000);` | Yeşil ışığın durumu 3000 milisaniye, yani 3 saniye sürer. |
| `delay(1000);` | Sarı ışığın durumu 1000 milisaniye, yani 1 saniye sürer. |

### İleri analiz [ileri]
Bir adımda yalnız bir LED yanıyor olsa bile üç `digitalWrite` satırı vardır. Bu satırlar
önceki adımdan kalan durumları temizler: yeni adımın resmini baştan çizer.

Başlangıç kodunda kırmızı, yeşil ve sarı için süreler sırasıyla 4000, 3000 ve 1000'dir.
Bu sayılar elektronik bir zorunluluk değildir; projenin kararıdır. Aynı kodda süreleri
değiştirerek daha aceleci ya da daha sakin görünen bir trafik lambası yapabilirsin.

## 6. Çalıştır ve gözlemle
Kodu yüklediğinde kırmızı 4 saniye yanar, sonra yeşil 3 saniye yanar, sonra sarı 1 saniye
yanar. `loop()` başa dönünce tekrar kırmızı yanar. Gözünle üç sürenin eşit olmadığını fark et.

### Sorun giderme
- **Hiçbir LED yanmıyor** → Kod karta yüklenmemiş olabilir. Arduino IDE'de doğru kartı ve portu seçip yüklemeyi tekrar dene.
- **Yalnız bir renk hiç yanmıyor** → O LED ters takılmış olabilir. Uzun bacağın pine, kısa bacağın dirence gittiğini kontrol et.
- **Renkler yanlış sırada yanıyor** → Kabloların pin 8, 9 ve 10 sırasını kodla karşılaştır. Kırmızı 8, sarı 9, yeşil 10'dadır.
- **LED'ler çok sönük yanıyor** → LED'ler aynı direnci paylaşıyor olabilir. Her LED'in kendi 220 ohm direnci olmalı.
- **Bir renk diğerlerinden çok kısa ya da uzun yanıyor** → O rengin hemen altındaki `delay` sayısını kontrol et.

## 7. Mini sınav
1. [temel] `const int sari = 9;` satırı ne yapar?
   - A) Sarı LED'i 9 saniye yakar
   - B) 9 numaralı pine `sari` adını verir
   - C) 9 LED'i aynı anda yakar
   - D) Sarı LED'i kapatır
   - ipucu: Bu satırdaki sayı bir süre değil, pin numarasıdır.

2. [temel] Kırmızı ışık yanarken sarı ve yeşil LED'e ne yazılır?
   - A) İkisine de `LOW`
   - B) İkisine de `HIGH`
   - C) Birine `HIGH`, birine `LOW`
   - D) Hiçbir şey yazılmaz
   - ipucu: Her adımda üç LED'in de durumu yazılır.

3. [temel] `delay(1000);` kaç saniye bekletir?
   - A) 10 saniye
   - B) 100 saniye
   - C) 1 saniye
   - D) Hiç bekletmez
   - ipucu: 1000 milisaniye 1 saniyedir.

4. [ileri] Kırmızı ışığın 4 saniye yerine 6 saniye yanması için hangi satırı değiştirmelisin?
   - A) `delay(4000);` satırını `delay(6000);` yapmalısın
   - B) `pinMode(kirmizi, OUTPUT);` satırını silmelisin
   - C) `digitalWrite(sari, LOW);` satırını `HIGH` yapmalısın
   - D) `const int kirmizi = 8;` satırını 6 yapmalısın
   - ipucu: Süreyi belirleyen satır `delay` ile başlar.

5. [ileri] Kırmızı+sarı adımından sonra yeşile geçerken kaç `digitalWrite` satırının değeri değişir?
   - A) 1
   - B) 2
   - C) 3
   - D) Hiçbiri
   - ipucu: Her adımda üç LED'in de durumu yazılır; hangilerinin durumu gerçekten farklı?

## 8. AI Yoldaşı promptları

> **Not:** AI Yoldaşı sana devrenin nasıl kurulacağını, hangi pine bağlayacağını ya da hangi direnci kullanacağını söylemez — bunlar sadece derste yazar. **AI'ın dediği devrende çalışmıyorsa AI yanılmıştır, devren haklıdır.**

- [temel] **Süreler** — "Sen sabırlı bir öğretmensin. Arduino Uno kartında pin 8'de kırmızı, pin 9'da sarı, pin 10'da yeşil LED ve her LED için 220 ohm direnç kullanan bir trafik lambası yaptım. Süreleri değiştirmek istiyorum. Bana sayı verme; kırmızının uzun, sarının kısa kalması için hangi `delay` satırlarını karşılaştırmam gerektiğini sorularla buldur."
- [temel] **Kod okuma** — "Sen bir kod okuma koçusun. Arduino Uno kartında pin 8, 9 ve 10'a bağlı üç LED'im var; kodumda her adımda üç `digitalWrite` satırı yazıyorum. Bana çözümü söyleme. Önceki adımdan kalan bir LED durumunun sonraki adımı neden etkileyebileceğini sorularla fark ettir."
- [ileri] **Birlikte yanma** — "Sen ileri seviye bir mentorsun. Arduino Uno'da kırmızı, sarı ve yeşil LED'li trafik lambama kırmızı+sarı adımını eklemek istiyorum. Pin numarası, direnç değeri veya bağlantı tarifi verme. Her LED'in o adımdaki durumunu kendim bulmam için 'hangileri yanacak, hangisi sönecek' diye sorular sor."
- [temel] **Yanındaki Yetişkine** — "Yardım etmek isterseniz cevabı söylemeyin. Şu üç şeyi sırayla sorun: LED'in uzun bacağı doğru yöne mi bakıyor? Koddaki renk adıyla kablonun bağlı olduğu pin uyuşuyor mu? Her LED'in kendi direnci var mı? Üçü de doğruysa birlikte gözlem yapın."

## 9. SEN YAP
1. Süreleri değiştir. Kırmızı daha uzun, sarı daha kısa, yeşil ortada kalacak başka üç sayı seç. Trafik lambasının davranışı nasıl değişti?
2. Türkiye'deki sırayı kur: kırmızı → kırmızı+sarı → yeşil → sarı → kırmızı. Kırmızı+sarı adımında iki LED'i aynı anda `HIGH` yap. Her adımda üç LED'in de durumunu yaz.
