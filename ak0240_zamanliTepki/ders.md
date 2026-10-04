---
ak_no: ak0240
baslik: "Zamanlı tepki: bas, 2 saniye yansın"
duzey: 0-temel
unite: 2-Buton
kazanimlar:
  - cpp.digitalread
  - cpp.delay
  - cpp.if
  - cpp.delay_kor
  - hw.buton-devre
onkosul:
  - cpp.if (ak0160)
  - cpp.digitalread / hw.pull-down (ak0210)
  - cpp.delay (ak0010)
kara_kutu: [void, "Serial ve noktalı yazım"]
merak_kosesi: "kara kutu değil — iş emri gereği acı tohumu: delay sırasında kart butonu duymuyor, çare Ünite 3'te millis() ile (ak0195 bağlantısı)"
malzeme:
  - Arduino Uno kartı
  - USB kablosu
  - Paket 5 devresi (4 LED, pin 3/5/6/9)
  - 1 buton (pin 2), 1 adet 10 kΩ direnç (pull-down)
board:
  kart: Arduino Uno
  led_pinleri: [3, 5, 6, 9]
  kullanilan_led: 6
  buton_pinleri: [2, 8]
  pull_direnci: "10 kΩ, pull-down"
  basili_degeri: HIGH
  seri_port_pinleri: [0, 1]
  seri_hiz: 9600
kaynak:
  - "..\\arsiv\\020GriButonLed\\020GriButonLed.ino"
  - "..\\arsiv\\021YesilButonLed\\021YesilButonLed.ino"
---

## 1. Hedef
Butona basınca LED **2 saniye** yansın, buton bırakılsa bile. Bunu yaparken kartın
o 2 saniye boyunca ne yaptığını (ya da yapmadığını) gözleyeceksin.

## 2. Malzemeler
- Arduino Uno kartı, USB kablosu
- Paket 5 devresi (4 LED, pin 3/5/6/9)
- Pin 2'deki buton ve 10 kΩ direnç (ak0210'daki gibi)

## 3. Parça tanıtımı
Yeni parça ya da komut yok; `delay` ak0010'dan, `digitalRead` ak0210'dan tanıdık.

## 4. Devre kurulumu
ak0210'un devresi aynen — dokunma.

## 5. Kod açıklaması
| kod satırı | açıklama |
| --- | --- |
| `if (digitalRead(butonPin) == HIGH)` | Butona basıldı mı? Basıldıysa bir olay başlar. |
| `digitalWrite(ledPin, HIGH); delay(2000); digitalWrite(ledPin, LOW);` | Yak, 2 saniye bekle, söndür. Olay butonu bırakınca bitmez, kendi süresi kadar sürer. |

**Zincir:** ak0220'de LED butonla birlikte yanıp sönüyordu (basılı = yanık). Burada
buton yalnız bir **başlangıç düğmesi**: bastığın an bir olay başlıyor ve olay butondan
bağımsız sürüyor. Ama `delay(2000)` sırasında kart başka hiçbir şey yapmıyor, butonu
da okumuyor — bu SEN YAP 1'de görünecek.

### İleri analiz [ileri]
`delay` bir "bekleme emri"dir: kartın işlemcisi o süre boyunca başka bir komuta geçmez.
Bu yüzden butonu aynı anda dinlemek mümkün değildir. ak0195'te `millis()` ile zamanı
beklemeden ölçmüştün; buton ile birleşmesi Ünite 3'ün konusu.

## 6. Çalıştır ve gözlemle
Yükle. Butona bas — LED 2 saniye yanar, söner. Yanıkken butona tekrar bas ve kartın
tepkisine bak (SEN YAP 1).

### Sorun giderme
- **LED hiç yanmıyor** → LED'in yönü, pin 6 bağlantısı, butonun 5V bacağı ve pull-down
  direnci sırayla kontrol et.
- **LED butona basmadan kendiliğinden yanıyor** → Pull-down direnç eksik; pin havada
  kalıp rastgele `HIGH` okuyor (ak0210 SEN YAP 1).
- **LED yanıyor ama 2 saniyeden çok kısa ya da uzun** → `delay(2000)` satırındaki sayı
  değişmiş olabilir; 1000 milisaniye = 1 saniye.
- **Buton basılı tutulunca beklediğin gibi olmuyor** → Bu hata değil, SEN YAP 2'nin
  sorusu; ne olduğunu kartta gör.
- **4 bacaklı buton** → Bacaklar karışmış olabilir; butonu 90° çevir ya da bacakları çapraz köşeden kullan (çapraz köşe her tip butonda çalışır).

## 7. Mini sınav
1. [temel] Butona basınca LED kaç saniye yanar?
   - A) 1
   - B) 2
   - C) Buton basılı kaldığı sürece
   - D) 10
   - ipucu: `delay(2000)`.

2. [temel] `delay(2000)` kaç saniyedir?
   - A) 20
   - B) 2
   - C) 0,2
   - D) 2000
   - ipucu: 1000 milisaniye = 1 saniye.

3. [temel] Buton bırakılırsa LED hemen söner mi?
   - A) Evet
   - B) Hayır, 2 saniye dolana kadar yanık kalır
   - C) Söner ve tekrar yanar
   - D) Kart resetlenir
   - ipucu: Olay kendi süresince sürüyor.

4. [temel] Bu derste hangi LED kullanılıyor?
   - A) Pin 3
   - B) Pin 5
   - C) Pin 6
   - D) Dahili LED
   - ipucu: `ledPin` sabitine bak.

5. [ileri] LED yanıkken butona basılırsa kart ne yapar?
   - A) Hemen cevap verir
   - B) `delay` bitene kadar butonu okumaz
   - C) LED'i söndürür
   - D) Seri porta yazar
   - ipucu: SEN YAP 1'de gördüğün.

6. [ileri] `delay`'in bu sorununa çare hangi araçla bulunacak?
   - A) `for` ile
   - B) `millis()` ile (Ünite 3)
   - C) `random()` ile
   - D) Çare yok
   - ipucu: Merak Köşesi.

## 8. AI Yoldaşı promptları

> **Not:** AI Yoldaşı sana pin numarası, direnç değeri ya da bağlantı tarifi
> vermez — bunlar yalnız dersten gelir. **AI'ın dediği devrende çalışmıyorsa AI
> yanılmıştır, devren haklıdır.**

- [temel] **Eşleştirme** — "Sen sabırlı bir öğretmensin. Arduino Uno kartımda pin
  2'de 10 kΩ pull-down'lı bir buton, pin 6'da bir LED var. Butona basınca LED
  `delay(2000)` ile 2 saniye yanıyor. Butonu bıraksam bile neden yanık kaldığını
  anlamama yardım et. Cevabı söyleme; kodun sırasını adım adım buldurcak sorular sor."
- [temel] **Hata giderme** — "Sen bir hata ayıklama koçusun. Arduino Uno kartımda
  buton pin 2'de, LED pin 6'da; LED yanıkken butona basınca hiçbir şey olmuyor. Cevabı
  verme; `delay` sırasında kartın ne yaptığını buldurcak sorular sor."
- [ileri] **Kavram derinleştirme** — "Sen ileri seviye bir mentorsun. Arduino Uno
  kartımda `delay` sırasında buton okunmuyor. Bu sorunu çözmek için hangi tür bir
  aracın gerektiğini düşünmeme yardım et. Cevabı söyleme, sorularla yönlendir."
- [temel] **Yanındaki Yetişkine** — "Cevabı söylemeyin. Şu üç şeyi sırayla sorun:
  Butona basınca LED kaç saniye yanıyor? LED yanıkken butona basınca ne oluyor? Butonu
  basılı tutunca ne oluyor?"

## 9. SEN YAP
1. LED yanıkken butona tekrar tekrar bas. Ne oluyor? Kart sana cevap veriyor mu?
2. Butona **basılı tut**. Önce tahminini yaz: 2 saniye sonra LED söner mi, hemen tekrar
   mı yanar? Sonra dene.
3. Ters hâli yap: program yüklenince LED yanık olsun; butona basınca 3 saniye sönsün,
   sonra tekrar yansın.
