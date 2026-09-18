---
ak_no: ak0115
baslik: Trafik lambası rengini yazsın
duzey: 0-temel
unite: 1-LED-ve-Seri-Port
kazanimlar:
  - cpp.setup-loop
  - cpp.delay
  - cpp.pinmode
  - cpp.digitalwrite
  - cpp.const-int
  - cpp.coklu-cikis
  - cpp.serial-begin
  - cpp.serial-println
  - hw.coklu-led
  - hw.seri-port
kara_kutu: [void, OUTPUT, "Serial ve noktalı yazım"]
merak_kosesi: void (3. tur, emekli)
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
  seri_port_pinleri: [0, 1]
  seri_hiz: 9600
  mantik_gerilimi: 5V
  direnc: 220 ohm
kaynak:
  - ak0070_trafikLambasi/ak0070_trafikLambasi.ino
  - ..\arsiv\kabaMüfredat.docx, 030. madde
---

## 1. Hedef
ak0070'te kurduğun trafik lambasını değiştirmeden ona bir katman ekleyeceksin. Kırmızı
LED yanarken Seri Monitör `KIRMIZI`, yeşil yanarken `YESIL`, sarı yanarken `SARI`
yazacak. Yeni komut öğrenmeyeceksin; ak0110'da öğrendiğin seri yazıyı tanıdığın bir
devrede kullanacaksın.

## 2. Malzemeler
- Arduino Uno kartı
- USB kablosu
- Kırmızı, sarı ve yeşil LED
- 3 adet 220 ohm direnç
- Breadboard
- 6 jumper kablo

## 3. Parça tanıtımı
Yeni parça yok. ak0070'teki üç LED'li trafik lambası devresi aynen kullanılır. Her LED'in
kendi direnci vardır. Seri Monitör de ak0110'da kullandığın Arduino IDE penceresidir.

## 4. Devre kurulumu
1. Kırmızı, sarı ve yeşil LED'i breadboard'a üstten alta sırasıyla tak.
2. Kırmızı LED'in uzun bacağını (+) pin 8'e bağla.
3. Sarı LED'in uzun bacağını (+) pin 9'a bağla.
4. Yeşil LED'in uzun bacağını (+) pin 10'a bağla.
5. Her LED'in kısa bacağını (−) kendi 220 ohm direncine bağla.
6. Her direncin boş ucunu GND'ye bağla.
7. Arduino Uno'yu USB kablosuyla bilgisayara bağla.

Metin şeması:
- Kırmızı LED (+) → pin 8, (−) → 220 ohm direnç → GND
- Sarı LED (+) → pin 9, (−) → 220 ohm direnç → GND
- Yeşil LED (+) → pin 10, (−) → 220 ohm direnç → GND

Arduino Uno'da pin 0 ve pin 1 seri port için ayrılmıştır; üç LED pin 8, 9 ve 10'da kalır.

## 5. Kod açıklaması
| kod satırı | açıklama |
| --- | --- |
| `// Trafik lambasının bildiğimiz koduna, yanan rengi yazan Serial.println satırları ekliyoruz` | ak0070 kodu korunur; her renk adımına bir yazı satırı eklenir. |
| `// Her renk yazısı, o rengin LED durumları ayarlandıktan hemen sonra gönderilir` | Ekrandaki ad ile fiziksel olarak yanan LED aynı rengi gösterir. |
| `const int kirmizi = 8;` | Arduino Uno'da pin 8'e `kirmizi` adı verilir. |
| `const int sari = 9;` | Arduino Uno'da pin 9'a `sari` adı verilir. |
| `const int yesil = 10;` | Arduino Uno'da pin 10'a `yesil` adı verilir. |
| `Serial.begin(9600);` | Kartın bilgisayara 9600 hızında yazı göndermesini başlatır. |
| `Serial.println("KIRMIZI");` | Kırmızı LED ayarlandıktan sonra ekrana `KIRMIZI` yazar. |
| `Serial.println("YESIL");` | Yeşil LED ayarlandıktan sonra ekrana `YESIL` yazar. |
| `Serial.println("SARI");` | Sarı LED ayarlandıktan sonra ekrana `SARI` yazar. |

`YESIL` Türkçe karakter kullanmadan yazıldı. Bazı bilgisayarlarda `YEŞİL` içindeki `Ş`
bozuk görünebilir; bu, LED'in veya kodun bozuk olduğu anlamına gelmez.

### İleri analiz [ileri]
ak0070'teki `const int`, `pinMode`, `digitalWrite` ve `delay` satırları aynı sırada
duruyor. Yeni katman yalnızca bir `Serial.begin` ve üç `Serial.println` satırıdır. Bu
sayede değişikliğin hangi davranışı eklediği kolayca görülebilir.

`Serial.println` satırı üç LED'in durumu ayarlandıktan sonra gelir. Satır daha erken
yazılırsa ekranda yeni renk görünürken devrede önceki renk çok kısa süre daha kalabilir.

## 6. Çalıştır ve gözlemle
Kodu karta yükle. Arduino IDE'de Seri Monitör'ü aç ve hızı **9600** seç. Kırmızı LED
4 saniye yanarken `KIRMIZI`, yeşil LED 3 saniye yanarken `YESIL`, sarı LED 1 saniye
yanarken `SARI` görünür. Sonra sıra baştan başlar.

### Sorun giderme
- **Hiçbir LED yanmıyor** → Kod karta yüklenmemiş olabilir. Doğru Arduino Uno ve portu
  seçip yüklemeyi yeniden dene.
- **Yalnız bir renk yanmıyor** → O LED ters takılmış olabilir. Uzun bacağın pine, kısa
  bacağın kendi direncine gittiğini kontrol et.
- **Yanan renk ile ekrandaki ad farklı** → `Serial.println` satırı yanlış renk adımına
  konmuş olabilir. Yazı satırını hemen üstündeki üç `digitalWrite` ile karşılaştır.
- **Seri Monitör boş** → Seri Monitör kapalı ya da yanlış port seçili olabilir. Monitörü
  açıp kodu yüklediğin portu seç.
- **Ekrandaki yazılar anlamsız karakterlerden oluşuyor** → Seri Monitör hızı kodla
  eşleşmiyordur. Kodda ve monitörde 9600 seçili olduğunu kontrol et.
- **LED'ler sönük yanıyor** → Üç LED aynı direnci paylaşıyor olabilir. Her LED'in kendi
  220 ohm direnci olmalı.

## 7. Mini sınav
1. [temel] Kırmızı LED yanarken Seri Monitör'de ne yazmalıdır?
   - A) SARI
   - B) YESIL
   - C) KIRMIZI
   - D) SONDU
   - ipucu: Yazı, yanan LED'in renk adıdır.

2. [temel] `Serial.println("SARI");` satırı kodda nereye yerleştirilir?
   - A) Sarı LED'in durumları ayarlandıktan hemen sonra
   - B) `const int` satırlarının arasına
   - C) Kırmızı adımının başına
   - D) Kodun dışına
   - ipucu: Ekrandaki ad ile yanan LED aynı anda değişmeli.

3. [temel] Seri Monitör hangi hızda açılmalıdır?
   - A) 220
   - B) 1000
   - C) 9600
   - D) 10
   - ipucu: `Serial.begin(...)` satırındaki sayıya bak.

4. [temel] Bu dersin devresi hangi eski dersle aynıdır?
   - A) Dahili LED
   - B) Trafik lambası
   - C) Hız merdiveni
   - D) Kara şimşek
   - ipucu: Üç renkli devreyi daha önce nerede kurdun?

5. [ileri] Bu derste ak0070 koduna eklenen satırlar hangileridir?
   - A) Bir `Serial.begin` ve üç `Serial.println`
   - B) Üç yeni `const int`
   - C) Altı yeni `digitalWrite`
   - D) Üç yeni `pinMode`
   - ipucu: Eski kod ile yeni kodu yan yana karşılaştır.

6. [ileri] `Serial.println("YESIL");` satırı LED durumlarından önce yazılırsa hangi
   uyumsuzluk görülebilir?
   - A) Yazı yeni rengi gösterirken devre çok kısa süre önceki renkte kalabilir
   - B) Direnç değeri değişir
   - C) Seri hız kendiliğinden artar
   - D) Pin 10 kaybolur
   - ipucu: Kod satırları yukarıdan aşağıya çalışır.

## 8. AI Yoldaşı promptları

> **Not:** AI Yoldaşı sana devrenin nasıl kurulacağını, hangi pine bağlayacağını ya da
> hangi direnci kullanacağını söylemez — bunlar sadece derste yazar. **AI'ın dediği
> devrende çalışmıyorsa AI yanılmıştır, devren haklıdır.**

- [temel] **Eşleştirme** — "Sen sabırlı bir öğretmensin. Arduino Uno kartında 5V mantık
  gerilimiyle çalışan trafik lambamda kırmızı pin 8, sarı pin 9, yeşil pin 10'da; her
  LED'in 220 ohm direnci var ve seri hız 9600. Yanan LED ile Seri Monitör'deki renk
  adını eşleştirmeme yardım et. Pin veya bağlantı tarifi verme, cevabı söyleme; bir tam
  turu adım adım gözlemleten sorular sor."
- [temel] **Hata giderme** — "Sen bir hata ayıklama koçusun. Arduino Uno kartında 5V
  mantık gerilimiyle çalışan trafik lambamda kırmızı pin 8, sarı pin 9, yeşil pin 10'da;
  her LED'in 220 ohm direnci var ve seri hız 9600. LED renkleri doğru ama ekrandaki adlar
  yanlış sırada. Pin, direnç veya bağlantı tarifi verme; cevabı söylemeden her
  `Serial.println` satırının çevresindeki kodu karşılaştırmamı sağlayan sorular sor."
- [ileri] **Kod karşılaştırma** — "Sen ileri seviye bir mentorsun. Arduino Uno kartında
  5V mantık gerilimiyle çalışan trafik lambamda kırmızı pin 8, sarı pin 9, yeşil pin
  10'da; her LED'in 220 ohm direnci var, pin 0 ve 1 seri porta ayrılmış ve seri hız
  9600. Eski trafik lambası koduyla yeni kod arasındaki tek katmanı bulmama yardım et.
  Cevabı verme; aynı kalan ve eklenen satırları kendim ayırmam için sorular sor."
- [temel] **Yanındaki Yetişkine** — "Cevabı söylemeyin. Şu üç şeyi sırayla sorun:
  Fiziksel olarak hangi renk yanıyor? Seri Monitör'de hangi ad görünüyor? O yazı satırının
  hemen üstünde hangi LED durumları ayarlanmış? Üç cevabı çocukla birlikte karşılaştırın."

## 9. SEN YAP
1. Sarı LED'in 1 saniye yerine 2 saniye yanmasını sağla.
2. Seri Monitör'deki `SARI` yazısının da LED ile aynı anda göründüğünü gözlemle.
