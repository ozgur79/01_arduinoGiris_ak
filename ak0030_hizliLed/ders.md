---
ak_no: ak0030
baslik: LED'i hızlandır
duzey: 0-temel
unite: 0-LED
kazanimlar:
  - cpp.delay
  - hw.gorme-esigi
kara_kutu: [void, OUTPUT]
merak_kosesi: void (1. tur)
malzeme:
  - Arduino Uno kartı
  - USB kablosu
  - 1 LED
  - 1 adet 220 ohm direnç
  - breadboard
  - 2 jumper kablo
board:
  kart: Arduino Uno
  harici_led_pin: 8
  mantik_gerilimi: 5V
  direnc: 220 ohm
kaynak: arsiv/002ledYak/002ledYak.ino (bekleme süresi 500 ms) + arsiv/kabaMüfredat.docx (hız merdiveni)
---

## 1. Hedef
Bir önceki derste kurduğun devre aynen duruyor. Bu sefer devreye değil, koddaki bekleme
süresine dokunacaksın: LED'i **saniyede 1 → 5 → 10 → 25 → 50 kez** yakıp söndürüp
**artık söndüğünü göremediğin hızı** kendin bulacaksın. O hızı ders sana vermeyecek,
sen bulacaksın.

## 2. Malzemeler
- Arduino Uno kartı
- USB kablosu
- 1 LED
- 1 adet 220 ohm direnç
- breadboard
- 2 jumper kablo

## 3. Parça tanıtımı
Bu derste yeni parça yok — ak0020'de tanıdığın LED, direnç, breadboard ve jumper kablo
kullanılıyor. Devre kuruluysa hiç sökme.

## 4. Devre kurulumu
ak0020'nin devresi aynen kullanılır. Devren sökülmüşse yeniden kur:
1. LED'i breadboard'a tak.
2. LED'in uzun bacağından (+) bir jumper kabloyla Arduino'nun 8 numaralı pinine bağlan.
3. LED'in kısa bacağını (−) 220 ohm dirence bağla.
4. Direncin diğer ucundan bir jumper kabloyla Arduino'nun GND pinine bağlan.

Metin şeması: LED uzun bacak (+) → pin 8, kısa bacak (−) → 220 ohm direnç → GND

## 5. Kod açıklaması
| kod satırı | açıklama |
| --- | --- |
| `// delay() içindeki sayı milisaniye cinsindendir: 1000 bir saniye, 500 yarım saniyedir` | `delay()` içindeki sayı milisaniye cinsindendir: 1000 bir saniye, 500 yarım saniyedir. |
| `// delay() içindeki sayı küçüldükçe LED daha sık yanıp söner` | `delay()` içindeki sayı küçüldükçe LED daha sık yanıp söner. |
| `// Bir tam tur (bir yanma + bir sönme) iki delay() sürer: 500 + 500 = bir saniye,` | Bir tam tur (bir yanma + bir sönme) iki `delay()` sürer: 500 + 500 = bir saniye. |
| `// yani LED saniyede 1 kez yanıp sönüyor` | Yani LED saniyede 1 kez yanıp sönüyor. |
| `void setup() {` | `{` ve `}` arasındaki satırlar o fonksiyona ait koddur; bu blok "başlangıç" bloğudur. |
| `pinMode(8, OUTPUT);` | 8. pini, açıp kapatabileceğimiz bir pin yap. |
| `void loop() {` | loop() içindeki satırlar setup bitince sürekli baştan tekrar eder. |
| `digitalWrite(8, HIGH);` | 8. pini aç -> LED yanar. |
| `delay(500);` (birinci) | Yarım saniye boyunca hiçbir şey yapma, LED yanık kalsın. |
| `digitalWrite(8, LOW);` | 8. pini kapat -> LED söner. |
| `delay(500);` (ikinci) | Yarım saniye boyunca hiçbir şey yapma, LED sönük kalsın. |
| `}` (setup ve loop sonu) | `;` işareti bir komutun bittiğini, `}` bloğun bittiğini gösterir. |

### İleri analiz [ileri]
Bir tam tur (yan + sön) iki `delay()` sürer, yani `2 × delay` milisaniye. Saniyede kaç
tur olduğu buradan çıkar: `frekans = 1000 / (2 × delay)`, birimi hertz (Hz).

| delay | bir tur | frekans |
| --- | --- | --- |
| 500 ms | 1000 ms | 1 Hz |
| 250 ms | 500 ms | 2 Hz |
| 100 ms | 200 ms | 5 Hz |
| 50 ms | 100 ms | 10 Hz |
| 20 ms | 40 ms | 25 Hz |
| 10 ms | 20 ms | 50 Hz |

Ters yönde de kullanılır: hedef hızdan `delay` değerini bulmak için
`delay = 1000 / (2 × hedef hız)`. Saniyede 25 kez istiyorsan `1000 / 50 = 20` ms.

Gözün bu turları tek tek ayırt edemez hâle geldiği sınıra **görme eşiği** (kaynaşma
frekansı) denir. LED gerçekte hâlâ sönüyor — değişen LED değil, gözün. Bu yüzden eşik
kişiden kişiye, hatta aynı kişide gündüz/gece farklı çıkabilir; tek bir "doğru sayı"
yoktur.

## 6. Çalıştır ve gözlemle
Kod ilk hâliyle yüklendiğinde LED yarım saniye yanık, yarım saniye sönük kalır —
ak0020'deki ritmin iki katı hızında. SEN YAP'taki sayıları küçülttükçe yanıp sönme
hızlanır; bir yerden sonra göz sönmeyi seçemez ve LED sürekli yanıyormuş gibi görünür.
Çok hızlandırınca LED biraz **daha sönük** görünür, çünkü zamanın yarısında kapalıdır.

### Sorun giderme
- **LED hiç yanmıyor** → LED'in uzun bacağı pin 8'e, kısa bacağı dirence bakıyor mu
  kontrol et; LED yönlü bir parçadır, ters takılırsa yanmaz.
- **LED hızlanmıyor** → İki `delay()` satırından yalnız birini değiştirmiş olabilirsin;
  ikisi de aynı sayı olmalı.
- **Kodu değiştirdin ama LED aynı davranıyor** → Değişikliği karta yeniden yüklemen
  gerekir; dosyayı kaydetmek yetmez.
- **"Sürekli yanıyor" mu, "hâlâ sönüyor" mu emin olamıyorsan** → Gözünü LED'den ayırıp
  başını yavaşça sağa sola sallayarak bak; sönme varsa ışık kesik kesik bir iz bırakır.

## 7. Mini sınav
1. [temel] `delay(250)` kaç saniyelik bekleme yapar?
   - A) 250 saniye
   - B) 25 saniye
   - C) Çeyrek saniye
   - D) 2,5 saniye
   - ipucu: 1000 milisaniye 1 saniyeye eşit.

2. [temel] Bu derste devrede ne değişti?
   - A) LED'in pini değişti
   - B) Direncin değeri değişti
   - C) Devrede hiçbir şey değişmedi, sadece koddaki sayı değişti
   - D) LED'in yönü değişti
   - ipucu: §4'te "ak0020'nin devresi aynen kullanılır" yazıyor.

3. [temel] `delay()` sayısını küçültürsen LED ne yapar?
   - A) Daha sık yanıp söner
   - B) Daha seyrek yanıp söner
   - C) Hiç yanmaz
   - D) Rengi değişir
   - ipucu: KAVRAM'daki ikinci yorum satırına bak.

4. [temel] LED çok hızlandığında sürekli yanıyormuş gibi görünüyor. Gerçekte ne oluyor?
   - A) LED artık sönmüyor
   - B) LED hâlâ sönüyor ama göz bunu ayırt edemiyor
   - C) Arduino komutları atlıyor
   - D) Direnç ısınıp LED'i açık tutuyor
   - ipucu: Değişen LED mi, gözün mü?

5. [ileri] `delay` 20 ms iken LED saniyede kaç kez yanıp söner?
   - A) 20
   - B) 25
   - C) 50
   - D) 100
   - ipucu: Bir tur iki `delay()` sürer; `1000 / (2 × 20)`.

6. [ileri] LED'in saniyede 5 kez yanıp sönmesini istiyorsun. `delay` kaç olmalı?
   - A) 5
   - B) 100
   - C) 200
   - D) 500
   - ipucu: `delay = 1000 / (2 × hedef hız)`.

7. [ileri] İki arkadaş aynı devrede farklı eşik değerleri buldu. Bu neyi gösterir?
   - A) Biri kodu yanlış yazmıştır
   - B) Arduino kartlarından biri bozuktur
   - C) Görme eşiği kişiden kişiye değişir, tek doğru sayı yoktur
   - D) Direnç değerleri farklıdır
   - ipucu: Sınırı koyan LED değil, göz.

## 8. AI Yoldaşı promptları
- [temel] **Kavramsal** — "Sen sabırlı bir öğretmensin. Öğrenci bir LED'i çok
  hızlandırdı ve LED sürekli yanıyor gibi görünüyor. Ona 'LED mi değişti, gözün mü?'
  diye sor ve sinema/çizgi film karelerinin nasıl hareket gibi göründüğünü hatırlatarak
  cevabı kendisi bulsun. Cevabı sen söyleme."
- [temel] **Hata giderme** — "Sen bir hata ayıklama koçusun. Öğrenci `delay` sayısını
  küçülttü ama LED'in hızı değişmedi. Ona iki soru sor: koddaki kaç tane `delay()`
  satırı var, hepsini değiştirdi mi; ve değişikliği karta yeniden yükledi mi. Cevabı
  doğrudan verme."
- [ileri] **Pekiştirme** — "Sen ileri seviye bir mentorsun. Öğrenciye bir tam turun
  neden iki `delay()` sürdüğünü sorarak frekans formülünü (`1000 / (2 × delay)`) kendi
  cümleleriyle kurdur. Formülü sen yazma, önce 'bir tur ne kadar sürüyor' diye sor."
- [ileri] **Tartışma** — "Sen meraklı bir tartışma arkadaşısın. Öğrenciye şunu sor:
  eşiği geçtikten sonra LED biraz daha sönük görünüyor, neden? Cevabı verme; 'zamanın
  ne kadarında açık, ne kadarında kapalı' diye düşündür."

## 9. SEN YAP
1) LED'i sırayla şu hızlarda yakıp söndür. Her hız için iki `delay()` satırındaki sayıyı
   İKİSİNİ BİRDEN değiştir, karta yükle ve LED'e bak:

   | hedef hız | delay değeri |
   | --- | --- |
   | saniyede 1 kez | `delay(500)` |
   | saniyede 5 kez | `delay(100)` |
   | saniyede 10 kez | `delay(50)` |
   | saniyede 25 kez | `delay(20)` |
   | saniyede 50 kez | `delay(10)` |

2) Hangi hızdan sonra LED'in söndüğünü artık göremiyorsun, sürekli yanıyor gibi
   görünüyor? O hızı defterine yaz.
3) Bulduğun hızı bir arkadaşınınkiyle karşılaştır. Aynı hızı mı buldunuz?
