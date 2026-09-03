---
ak_no: ak0020
baslik: Harici LED'i yakıp söndür
duzey: 0-temel
unite: 0-LED
kazanimlar:
  - cpp.setup-loop
  - cpp.delay
  - cpp.pinmode-digitalwrite
  - cpp.blok-noktalivirgul
  - hw.harici-led-devre
kara_kutu: [void, OUTPUT]
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
kaynak: arsiv/002ledYak/002ledYak.ino
---

## 1. Hedef
Bu sefer LED kartın üzerinde değil, senin kurduğun bir devrenin üzerinde. Bir LED'i,
bir direnci ve birkaç kabloyu doğru sırayla bağlayıp aynı yakıp-söndürme işini kendi
devrende çalıştıracaksın.

## 2. Malzemeler
- Arduino Uno kartı
- USB kablosu
- 1 LED
- 1 adet 220 ohm direnç
- breadboard
- 2 jumper kablo

## 3. Parça tanıtımı
- **LED** — iki bacaklı küçük ışık kaynağı; bacaklarından biri uzun, biri kısa.
- **Direnç** — LED'e giden akımı sınırlayan, üzerinde renkli çizgiler olan parça.
- **Breadboard** — kabloları lehim yapmadan birbirine bağlamana yarayan delikli tahta.
- **Jumper kablo** — breadboard, LED, direnç ve Arduino arasında bağlantı kuran kablo.

## 4. Devre kurulumu
1. LED'i breadboard'a tak.
2. LED'in uzun bacağından (+) bir jumper kabloyla Arduino'nun 8 numaralı pinine bağlan.
3. LED'in kısa bacağını (−) 220 ohm dirence bağla.
4. Direncin diğer ucundan bir jumper kabloyla Arduino'nun GND pinine bağlan.

Metin şeması: LED uzun bacak (+) → pin 8, kısa bacak (−) → 220 ohm direnç → GND

## 5. Kod açıklaması
| kod satırı | açıklama |
| --- | --- |
| `// LED'in iki bacağı var: uzun bacak (+) ve kısa bacak (-) - yönü önemlidir, ters takarsan LED yanmaz` | LED'in iki bacağı var: uzun bacak (+) ve kısa bacak (−) — yönü önemlidir, ters takarsan LED yanmaz. |
| `// Direnç, LED'e çok fazla akım gitmesini engeller ve LED'i korur` | Direnç, LED'e çok fazla akım gitmesini engeller ve LED'i korur. |
| `void setup() {` | `{` ve `}` arasındaki satırlar o fonksiyona ait koddur; bu blok "başlangıç" bloğudur. |
| `pinMode(8, OUTPUT);` | 8. pini, açıp kapatabileceğimiz bir pin yap. |
| `}` (setup sonu) | `;` işareti bir komutun bittiğini gösterir; `}` bloğun bittiğini gösterir. |
| `void loop() {` | loop() içindeki satırlar setup bitince sürekli baştan tekrar eder. |
| `digitalWrite(8, HIGH);` | 8. pini aç -> LED yanar. |
| `delay(1000);` | 1000 milisaniye (1 saniye) bekle. |
| `digitalWrite(8, LOW);` | 8. pini kapat -> LED söner. |
| `delay(1000);` | 1 saniye bekle. |

### İleri analiz [ileri]
Direncin değeri Ohm Kanunu'yla (V = I × R) hesaplanır. Bu devrede kart 5V verir
(bkz. `board.mantik_gerilimi`), direnç 220 ohm'dur (bkz. `board.direnc`) — bu ikisi
LED'den geçen akımı güvenli bir seviyede tutacak şekilde seçilmiştir. Farklı bir
board'da mantık gerilimi farklıysa (örn. 3.3V), aynı akımı elde etmek için farklı bir
direnç değeri gerekir — bu yüzden gerilim ve direnç değeri board'a özgüdür, dersten
derse değişebilir.

## 6. Çalıştır ve gözlemle
Kod karta yüklendikten sonra, breadboard üzerindeki LED saniyede bir yanıp söner:
1 saniye yanık, 1 saniye sönük, sürekli tekrar — ak0010'daki dahili LED ile aynı ritim,
ama ışık artık kartın üzerinde değil, senin kurduğun devrede.

### Sorun giderme
- **LED hiç yanmıyor, ters bağlanmış olabilir** → LED'in iki bacağını yer değiştirip
  tekrar dene; LED yönlü bir parçadır, ters takılırsa yanmaz.
- **LED yanmıyor** → pin numarasının kodda (`8`) ve devrede (breadboard'daki bağlantı)
  aynı olduğundan emin ol.
- **`delay(1000)` bir saniye mi, bin saniye mi diye şüphe ediyorsan** → `delay()`
  değeri her zaman milisaniye cinsindendir, 1000 milisaniye 1 saniyeye eşittir.

## 7. Mini sınav
1. [temel] LED'in hangi bacağı Arduino pinine, hangisi dirence bağlanır?
   - A) Uzun bacak pine, kısa bacak dirence ✅
   - B) Kısa bacak pine, uzun bacak dirence
   - C) İkisi de pine bağlanır
   - D) İkisi de dirence bağlanır
   - ipucu: KAVRAM yorumundaki "+" ve "−" işaretlerine bak.

2. [temel] Bu derste direncin görevi nedir?
   - A) LED'i daha parlak yapmak
   - B) LED'e giden akımı sınırlayıp LED'i korumak ✅
   - C) Pin numarasını değiştirmek
   - D) delay() süresini kısaltmak
   - ipucu: Direnç kelimesinin "engellemek" anlamıyla ilişkisini düşün.

3. [temel] Bu derste LED hangi pine bağlıdır?
   - A) Pin 13
   - B) Pin 6
   - C) Pin 8 ✅
   - D) Pin 0
   - ipucu: `pinMode()` satırındaki sayıya bak.

4. [ileri] LED'i ters taksaydın (bacakları yer değiştirseydin) ne olurdu?
   - A) LED daha parlak yanardı
   - B) LED hiç yanmazdı ✅
   - C) Direnç yanardı
   - D) Arduino kartı bozulurdu
   - ipucu: LED yönlü bir parçadır — akım sadece tek yönde geçer.

5. [ileri] Bu devrede mantık gerilimi 5V, direnç 220 ohm. Farklı bir kartta mantık
   gerilimi 3.3V olsaydı, aynı LED için genelde ne beklenir?
   - A) Aynı direnç değeri her board'da kullanılır
   - B) Direnç değeri board'un gerilimine göre yeniden hesaplanır ✅
   - C) Direnç hiç gerekmez
   - D) LED'in bacak yönü değişir
   - ipucu: Ohm Kanunu'nda gerilim değişirse ne değişir?

## 8. AI Yoldaşı promptları
- [temel] **Kavramsal** — "Sen sabırlı bir öğretmensin. Öğrenciye LED'in neden yönlü
  bir parça olduğunu, su borusundaki tek yönlü bir vana benzetmesiyle buldurmaya
  çalış. Cevabı söyleme, önce bir soru sor."
- [temel] **Hata giderme** — "Sen bir hata ayıklama koçusun. Öğrenci LED'i taktı ama
  yanmıyor. Önce hangi iki şeyi kontrol etmesi gerektiğini (yön ve pin numarası)
  sorular sorarak buldur, cevabı doğrudan verme."
- [ileri] **Pekiştirme** — "Sen ileri seviye bir mentorsun. Öğrenciye direncin neden
  gerekli olduğunu, Ohm Kanunu'nu (V = I × R) hiç adını vermeden, 'gerilim sabitken
  direnç artarsa akıma ne olur' sorusuyla düşündür. Formülü sen söyleme, öğrenci
  kendi cümlesiyle ifade etsin."

## 9. SEN YAP
1) LED'in bacaklarını yer değiştirerek tak (ters bağla). Ne oluyor, gözlemle.
2) LED'in kablosunu pin 8'den pin 9'a taşı. Kodda da neyi değiştirmen gerekiyor?
   Değiştir ve çalıştır.
