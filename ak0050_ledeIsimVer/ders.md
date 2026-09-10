---
ak_no: ak0050
baslik: LED'e isim ver
duzey: 0-temel
unite: 0-LED
kazanimlar:
  - cpp.const-int
  - cpp.pinmode
  - cpp.digitalwrite
  - cpp.coklu-cikis
kara_kutu: [void, OUTPUT]
merak_kosesi: void (2. tur)
malzeme:
  - Arduino Uno kartı
  - USB kablosu
  - 2 LED (biri kırmızı, biri yeşil)
  - 2 adet 220 ohm direnç
  - breadboard
  - 4 jumper kablo
board:
  kart: Arduino Uno
  kirmizi_led_pin: 8
  yesil_led_pin: 9
  mantik_gerilimi: 5V
  direnc: 220 ohm
kaynak: yok — ak0040'ın devresi aynen kullanılır
---

## 1. Hedef
Şimdiye kadar kodda hep pin numarası yazdın: `8`, `9`. Bu derste o numaralara **isim**
vereceksin ve bundan sonra numarayı değil ismi kullanacaksın. Küçük bir değişiklik gibi
duruyor ama bir şeyi kökten değiştiriyor: LED'in kablosunu başka bir pine taşıdığında
kodda **tek bir satırı** düzeltmen yetecek.

## 2. Malzemeler
- Arduino Uno kartı
- USB kablosu
- 2 LED (biri kırmızı, biri yeşil)
- 2 adet 220 ohm direnç
- breadboard
- 4 jumper kablo

## 3. Parça tanıtımı
Bu derste yeni parça yok. ak0040'ın devresi aynen kullanılıyor; tek fark, LED'lerin
renklerini artık kodda da adlandırıyor olman.

## 4. Devre kurulumu
ak0040'ın devresi duruyorsa hiç dokunma. Sökülmüşse yeniden kur:
1. Kırmızı LED'in uzun bacağından (+) pin 8'e, kısa bacağından (−) 220 ohm dirence,
   direncin diğer ucundan GND'ye bağlan.
2. Yeşil LED'in uzun bacağından (+) pin 9'a, kısa bacağından (−) ikinci 220 ohm dirence,
   direncin diğer ucundan GND'ye bağlan.

Metin şeması:
- Kırmızı LED (+) → pin 8, (−) → 220 ohm direnç → GND
- Yeşil LED (+) → pin 9, (−) → 220 ohm direnç → GND

## 5. Kod açıklaması
| kod satırı | açıklama |
| --- | --- |
| `// Aşağıdaki satır 8 sayısına "kirmizi" adını verir; bundan sonra 8 yerine kirmizi yazabilirsin` | Bu satır 8 sayısına "kirmizi" adını verir; bundan sonra 8 yerine `kirmizi` yazılabilir. |
| `// const, "bu isme verilen sayı bir daha değişmeyecek" demektir` | `const`, "bu isme verilen sayı bir daha değişmeyecek" demektir. |
| `const int kirmizi = 8;` | 8 numaralı pine `kirmizi` adı verilir. |
| `const int yesil = 9;` | 9 numaralı pine `yesil` adı verilir. |
| `// İsim satırları setup ve loop'un dışında, en üstte durur; böylece hem setup hem loop bu isimleri kullanabilir` | İsim satırları `setup` ve `loop`'un dışında, en üstte durur; böylece iki blok da bu isimleri kullanabilir. |
| `pinMode(kirmizi, OUTPUT);` | `kirmizi` adını verdiğimiz pini, açıp kapatabileceğimiz bir pin yap. |
| `pinMode(yesil, OUTPUT);` | `yesil` adını verdiğimiz pini, açıp kapatabileceğimiz bir pin yap. |
| `digitalWrite(kirmizi, HIGH);` | `kirmizi` pini aç -> kırmızı LED yanar. |
| `digitalWrite(yesil, LOW);` | `yesil` pini kapat -> yeşil LED söner. |
| `delay(300);` (birinci) | Bu durumu 300 milisaniye koru. |
| `digitalWrite(kirmizi, LOW);` | `kirmizi` pini kapat -> kırmızı LED söner. |
| `digitalWrite(yesil, HIGH);` | `yesil` pini aç -> yeşil LED yanar. |
| `delay(300);` (ikinci) | Bu durumu da 300 milisaniye koru. |
| `}` (setup ve loop sonu) | `;` bir komutun bittiğini, `}` bloğun bittiğini gösterir. |

### İleri analiz [ileri]
`const` yazmadan da olurdu: `int kirmizi = 8;` aynı işi görürdü. `const`'un getirdiği şey
bir **koruma**: sonradan yanlışlıkla `kirmizi = 9;` yazarsan program derlenmez, hata
verir. `const` olmasaydı bu hata sessizce geçer, LED'in neden yanmadığını saatlerce
ararsın. Yani `const` bilgisayara değil, **gelecekteki sana** yazılmış bir not.

İkinci nokta: verdiğin isim derlenmiş programda **yok**. Arduino'ya gönderilen kodda
`kirmizi` diye bir şey bulunmaz, onun yerine 8 yazar — isimler derleme sırasında
sayılarla değiştirilir. Bu yüzden isim vermenin **hiçbir bedeli yoktur**: programı ne
yavaşlatır ne büyütür. İstediğin kadar anlamlı isim kullanabilirsin.

## 6. Çalıştır ve gözlemle
Devrede hiçbir şey değişmez: kırmızı ve yeşil LED sırayla, 300'er milisaniye yanıp söner
— ak0040'ın tıpatıp aynısı. **Bu dersin bütün farkı kodda.** Aynı işi yapan iki kod
yazdın; ikincisi değiştirmesi kolay olan.

### Sorun giderme
- **`kirmizi was not declared in this scope` hatası** → İsim satırını `setup`'ın içine
  yazmış olabilirsin; isim satırları `setup`'ın **dışında**, en üstte durmalı.
- **`expected initializer` ya da benzeri hata** → `const int kirmizi = 8;` satırının
  sonunda `;` var mı kontrol et.
- **Kod derlenmiyor, isim bulunamıyor diyor** → Büyük/küçük harf farkı olabilir:
  `Kirmizi` ile `kirmizi` Arduino için iki ayrı isimdir.
- **LED'ler ters yanıyor (kırmızı olması gereken yeşil)** → İsimlere verdiğin pin
  numaraları devredeki bağlantıyla ters olabilir; `const int` satırlarını kontrol et.
- **Hiçbir şey değişmedi diye endişeleniyorsan** → Doğrusu bu. Devrenin davranışı
  aynı kalmalı, değişen tek şey kodun okunabilirliği.

## 7. Mini sınav
1. [temel] `const int kirmizi = 8;` satırı ne yapar?
   - A) 8 numaralı pini açar
   - B) 8 sayısına `kirmizi` adını verir
   - C) Kırmızı LED'i yakar
   - D) LED'in rengini değiştirir
   - ipucu: KAVRAM'ın ilk yorum satırına bak.

2. [temel] `const` ne demek?
   - A) Bu isme verilen sayı bir daha değişmeyecek
   - B) Bu satır bir kez çalışacak
   - C) Bu bir LED'dir
   - D) Bu satır yorumdur
   - ipucu: KAVRAM'ın ikinci yorum satırına bak.

3. [temel] İsim satırları kodun neresinde durur?
   - A) `setup`'ın içinde
   - B) `loop`'un içinde
   - C) İkisinin de dışında, en üstte
   - D) Dosyanın en sonunda
   - ipucu: İki blok da o isimleri kullanabilmeli.

4. [temel] Kırmızı LED'in kablosunu pin 8'den pin 10'a taşıdın. Kodda kaç satır
   değiştirmen gerekir?
   - A) 1 satır
   - B) 2 satır
   - C) 3 satır
   - D) Hiç gerekmez
   - ipucu: 8 sayısı artık kaç yerde yazıyor?

5. [ileri] `const` yerine sadece `int` yazsaydın ne olurdu?
   - A) Kod hiç çalışmazdı
   - B) Aynı çalışırdı, ama yanlışlıkla değeri değiştirirsen hata alamazdın
   - C) LED daha parlak yanardı
   - D) İsim kullanılamazdı
   - ipucu: `const` bilgisayarı değil, gelecekteki seni koruyor.

6. [ileri] Verdiğin isim Arduino'ya gönderilen programda var mıdır?
   - A) Evet, program isimleri de taşır
   - B) Hayır, derleme sırasında isimler sayılarla değiştirilir
   - C) Sadece `const` yazarsan taşır
   - D) LED yanarken taşır, sönerken taşımaz
   - ipucu: İsim vermenin programa bir bedeli var mı?

## 8. AI Yoldaşı promptları
- [temel] **Kavramsal** — "Sen sabırlı bir öğretmensin. Öğrenciye telefon rehberi
  benzetmesiyle sor: numarayı ezberlemek mi kolay, kişinin adını görmek mi? Kodda pin
  numarası yerine isim kullanmanın neye benzediğini kendisi bulsun. Cevabı söyleme."
- [temel] **Hata giderme** — "Sen bir hata ayıklama koçusun. Öğrenci `kirmizi was not
  declared in this scope` hatası alıyor. Ona iki soru sor: isim satırını nereye yazdı,
  ve yazdığı isimle kullandığı isim harfi harfine aynı mı. Cevabı doğrudan verme."
- [ileri] **Pekiştirme** — "Sen ileri seviye bir mentorsun. Öğrenciye şunu sordur:
  kodda dört yerde geçen bir pin numarasını değiştirmek ile tek yerde geçen bir ismi
  değiştirmek arasında ne fark var? Dört LED'lik bir devre hayal ettirerek büyüt.
  Sonucu sen söyleme."
- [ileri] **Tartışma** — "Sen meraklı bir tartışma arkadaşısın. Öğrenciye sor: isimleri
  `a` ve `b` yapsa kod çalışır mı? Çalışıyorsa isim vermek kime yarıyor? 'Bilgisayar mı
  okuyor bu kodu, insan mı' diye düşündür. Cevabı verme."

## 9. SEN YAP
1) İki LED'i de taşı: kabloları pin 8 ve 9'dan pin 10 ve 11'e al, kodu da düzelt.
   Kodda kaç satır değiştirdin? Şimdi ak0040'ın koduna bak: aynı taşımayı orada
   yapsaydın kaç satır değişecekti? İki sayıyı yan yana yaz.
2) `kirmizi` ve `yesil` isimlerini kendi LED'lerinin gerçek renklerine göre değiştir.
   Kaç yerde değiştirmen gerekti?
3) İsimleri `kirmizi` ve `yesil` yerine `a` ve `b` yap. Kod yine çalışıyor mu?
   Çalışıyorsa isim vermek kime yarıyor — Arduino'ya mı, sana mı? İki satırda yaz.
