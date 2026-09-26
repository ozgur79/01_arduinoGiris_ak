---
ak_no: ak0170
baslik: "Nefes alan LED: analogWrite (PWM)"
duzey: 0-temel
unite: 1-LED-ve-Seri-Port
kazanimlar:
  - cpp.setup-loop
  - cpp.delay
  - cpp.pinmode
  - cpp.const-int
  - cpp.for
  - cpp.analogwrite
onkosul:
  - hw.gorme-esigi (ak0030)
  - cpp.for (ak0130)
kara_kutu: [void, OUTPUT]
merak_kosesi: "atlandı (yük freni — PWM + frekans illüzyonu köprüsü + 3 kaynak hatası düzeltmesi zaten ağır)"
malzeme:
  - Arduino Uno kartı
  - USB kablosu
  - 1 LED
  - 1 adet 220 ohm direnç
  - breadboard
  - 2 jumper kablo
board:
  kart: Arduino Uno
  led_pini: 11
  pwm_pinleri: [3, 5, 6, 9, 10, 11]
  mantik_gerilimi: 5V
  direnc: 220 ohm
kaynak:
  - ..\arsiv\002ledParlaklik\002ledParlaklik.ino
---

## 1. Hedef
Şimdiye kadar LED'i yalnızca açık ya da kapalı yaptın. Bu derste LED'in **arada** da
durabileceğini göreceksin — yavaşça parlayıp yavaşça sönen, "nefes alan" bir LED
yapacaksın.

## 2. Malzemeler
- Arduino Uno kartı
- USB kablosu
- 1 LED
- 1 adet 220 ohm direnç
- Breadboard
- 2 jumper kablo

## 3. Parça tanıtımı
Yeni parça yok. Tek fark: LED'in bağlı olduğu pinin (~) işaretli olması gerekiyor.

## 4. Devre kurulumu
1. LED'i breadboard'a tak.
2. LED'in uzun bacağını (+) pin **11**'e bağla (pin numarasının yanında ~ işareti var).
3. LED'in kısa bacağını (−) 220 ohm direnç ile GND'ye bağla.
4. Arduino Uno'yu USB kablosuyla bilgisayara bağla.

Metin şeması: LED (+) → pin 11 (~), (−) → 220 ohm direnç → GND

**Pin 8'de bu ders çalışmaz** — Uno'da yalnız ~ işaretli pinler (3, 5, 6, 9, 10, 11)
`analogWrite` yapabilir, diğerleri yapamaz.

## 5. Kod açıklaması
| kod satırı | açıklama |
| --- | --- |
| `const int led = 11;` | Pine isim veriyoruz (ak0050 kuralı). |
| `analogWrite(led, parlaklik);` | LED'e 0 (tamamen sönük) ile 255 (tamamen parlak) arası bir değer verir. |
| `for (int parlaklik = 0; parlaklik <= 255; parlaklik++)` | Parlaklığı yavaş yavaş artırır — "nefes alma". |
| `for (int parlaklik = 255; parlaklik >= 0; parlaklik--)` | Parlaklığı yavaş yavaş azaltır — "nefes verme". |
| `delay(10);` | Her adımda kısa bir bekleme; bu satır olmasa göz artışı hiç fark etmez. |

### İleri analiz [ileri]
`analogWrite` aslında LED'i yine sadece açık/kapalı yapıyor — ama bunu gözün fark
edemeyeceği kadar **hızlı** yapıyor (buna PWM denir: pin çok hızlı açılıp kapanıyor).
Bunu ak0030'da gördüğün "frekans illüzyonu"ndan hatırlarsın: yanıp sönme yeterince
hızlanınca göz sönmeyi ayırt edemez, ışık sürekli yanıyormuş gibi görünür. `analogWrite`
değeri ne kadar büyükse, pin o kadar büyük bir bölümünde "açık" kalıyor — göz bunu
"daha parlak" olarak algılıyor. Bu ayrıntının tam adı ve nasıl çalıştığı ileride
elektronik derslerinde açılacak; şimdilik "çok hızlı yanıp sönme = arada bir parlaklık
hissi" yeterli.

Kaynak koddaki üç düzeltme: (1) `analogWrite(11, ...)` çıplak pin yerine
`analogWrite(led, ...)` yazıldı, (2) aralık 0-200 yerine tam aralık 0-255 yapıldı,
(3) iniş ve çıkışın farklı hızları (10/20 ms, üstelik yorum satırı yanlış "10
milisaniye" diyordu) eşitlenip ikisi de `delay(10)` yapıldı — nefes alma ve verme aynı
hızda.

## 6. Çalıştır ve gözlemle
Devreyi kur, kodu karta yükle. LED yavaşça parlayıp yavaşça söner, sürekli tekrar eder
— gerçek bir nefes alıp verme gibi.

### Sorun giderme
- **LED hiç yanmıyor** → Kod yüklenmemiş olabilir; "Done uploading" mesajını kontrol
  et.
- **LED yanıyor ama nefes almıyor, sadece açık/kapalı gibi** → LED'in ~ işaretli bir
  pine (3, 5, 6, 9, 10, 11) bağlı olduğunu kontrol et; pin 8 gibi ~ işaretsiz bir
  pinde `analogWrite` çalışmaz.
- **LED ters takılmış** → Uzun bacağın pine, kısa bacağın dirence gittiğini kontrol
  et.
- **Nefes çok hızlı/yavaş** → `delay(10)` değerlerini değiştir.

## 7. Mini sınav
1. [temel] `analogWrite` LED'e hangi değerleri verebilir?
   - A) Sadece HIGH ve LOW
   - B) 0 ile 255 arası herhangi bir sayı
   - C) Sadece 1 ve 0
   - D) Sadece 255
   - ipucu: "Arada" değerler de var.

2. [temel] Bu derste LED hangi pine bağlı?
   - A) Pin 8
   - B) Pin 11
   - C) Pin 13
   - D) Pin 0
   - ipucu: Devre kurulumuna bak.

3. [temel] `analogWrite` hangi pinlerde çalışır?
   - A) Tüm pinlerde
   - B) Yalnız ~ işaretli pinlerde
   - C) Yalnız pin 8'de
   - D) Yalnız dahili LED'de
   - ipucu: Uno'da 3, 5, 6, 9, 10, 11.

4. [temel] Bu dersin devresi kaç LED kullanır?
   - A) 4
   - B) 1
   - C) 3
   - D) 0
   - ipucu: Malzeme listesine bak.

5. [ileri] PWM aslında ne yapar?
   - A) LED'e gerçekten ara bir gerilim verir
   - B) Pini gözün fark edemeyeceği kadar hızlı açıp kapatır
   - C) LED'in rengini değiştirir
   - D) LED'in direncini değiştirir
   - ipucu: ak0030'daki frekans illüzyonunu hatırla.

6. [ileri] Kaynak kodda iniş ve çıkış neden farklı hızlardaydı, bu derste ne yapıldı?
   - A) Kasıtlı bırakıldı, açıklandı
   - B) İkisi de delay(10) yapılıp eşitlendi, çünkü yorum satırı da yanlıştı
   - C) İkisi de delay(20) yapıldı
   - D) Hiçbir şey değiştirilmedi
   - ipucu: §5'teki "Kaynak koddaki üç düzeltme" paragrafına bak.

## 8. AI Yoldaşı promptları

> **Not:** AI Yoldaşı sana devrenin nasıl kurulacağını, hangi pine bağlayacağını ya da
> hangi direnci kullanacağını söylemez — bunlar sadece derste yazar. **AI'ın dediği
> devrende çalışmıyorsa AI yanılmıştır, devren haklıdır.**

- [temel] **Eşleştirme** — "Sen sabırlı bir öğretmensin. Arduino Uno kartında 5V mantık
  gerilimiyle çalışan nefes alan LED devremde LED pin 11'de (~), 220 ohm direnci var.
  `analogWrite`'ın `digitalWrite`'tan farkını anlamama yardım et. Pin veya bağlantı
  tarifi verme, cevabı söyleme; LED'in parlaklığının nasıl değiştiğini gözlemleten
  sorular sor."
- [temel] **Hata giderme** — "Sen bir hata ayıklama koçusun. Arduino Uno kartında 5V
  mantık gerilimiyle çalışan nefes alan LED devremde LED pin 8'de. LED sadece açık/kapalı
  gibi davranıyor, nefes almıyor. Pin veya bağlantı tarifi verme; pinin ~ işaretli olup
  olmadığını kontrol etmemi sağlayan sorular sor."
- [ileri] **Kavram derinleştirme** — "Sen ileri seviye bir mentorsun. Arduino Uno
  kartımda 5V mantık gerilimiyle çalışan LED pin 11'de (~). PWM'in gözü nasıl kandırdığını
  anlamama yardım et. Cevabı verme, ak0030'daki frekans illüzyonuyla bağlantı kurduran
  sorular sor."
- [temel] **Yanındaki Yetişkine** — "Cevabı söylemeyin. Şu üç şeyi sırayla sorun: LED
  gerçekten sönük bir ışıkla mı yanıyor, yoksa hızlı yanıp sönüyor mu (elle sallayarak
  fotoğraf çekmeyi deneyebilirler)? Nefes alma ve verme aynı hızda mı? LED hangi pine
  bağlı?"

## 9. SEN YAP
1. LED %50 parlaklığa (analogWrite değeri 127) çıksın, sonra birden ve tamamen sönsün.
2. İkinci bir LED (başka bir ~ pinine, ör. pin 10) ekleyip ters nefes aldır: biri
   parlarken öteki sönsün.
3. `delay(10)` değerlerini değiştir. Nefes alma/verme ne kadar hızlandı ya da yavaşladı?
