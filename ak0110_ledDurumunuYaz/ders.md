---
ak_no: ak0110
baslik: LED durumunu yaz
duzey: 0-temel
unite: 1-LED-ve-Seri-Port
kazanimlar:
  - cpp.setup-loop
  - cpp.delay
  - cpp.pinmode
  - cpp.digitalwrite
  - cpp.serial-begin
  - cpp.serial-println
  - hw.harici-led-devre
  - hw.seri-port
kara_kutu: [void, OUTPUT, "Serial ve noktalı yazım"]
merak_kosesi: atlandı (yük freni — yeni araç ve yeni noktalı yazım birlikte geliyor)
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
  seri_port_pinleri: [0, 1]
  seri_hiz: 9600
  mantik_gerilimi: 5V
  direnc: 220 ohm
kaynak: ..\arsiv\000seri06ledYandiSondu\000seri06ledYandiSondu.ino (pin 6 -> 8; Serial.print -> Serial.println)
---

## 1. Hedef
LED'in yalnızca yanıp sönmeyecek; ne yaptığını bilgisayara da yazacak. LED yanınca Seri
Monitör'de `YANDI`, sönünce `SONDU` göreceksin. Bu dersin tek yeni fikri, kartın çalışırken
bilgisayara yazı gönderebilmesidir.

## 2. Malzemeler
- Arduino Uno kartı
- USB kablosu
- 1 LED
- 1 adet 220 ohm direnç
- breadboard
- 2 jumper kablo

## 3. Parça tanıtımı
Yeni elektronik parça yok. ak0020'deki LED, direnç ve breadboard devresini yeniden
kullanacaksın. **Seri Monitör**, Arduino IDE içinde karttan gelen yazıları gösteren
penceredir; devreye eklenen bir parça değildir.

## 4. Devre kurulumu
1. LED'i breadboard'a tak.
2. LED'in uzun bacağını (+) bir jumper kabloyla Arduino Uno'nun 8 numaralı pinine bağla.
3. LED'in kısa bacağını (−) 220 ohm dirence bağla.
4. Direncin diğer ucunu bir jumper kabloyla Arduino Uno'nun GND pinine bağla.
5. Arduino Uno'yu USB kablosuyla bilgisayara bağla.

Metin şeması: LED uzun bacak (+) → pin 8, kısa bacak (−) → 220 ohm direnç → GND

Bu kartta pin 0 ve pin 1 seri port için ayrılmıştır. LED bu yüzden bu pinlere değil,
pin 8'e bağlanır.

## 5. Kod açıklaması
| kod satırı | açıklama |
| --- | --- |
| `// Kart çalışırken bilgisayara yazı gönderebilir; yazıları Seri Monitör'de görürüz` | Seri Monitör, kartın gönderdiği yazıların görüldüğü penceredir. |
| `// 9600, kart ile Seri Monitör'ün aynı konuşma hızıdır; monitörde de 9600 seçilir` | Kartın ve monitörün hızı aynı olmazsa yazı doğru okunmaz. Bu derste ikisi de 9600'dür. |
| `// Serial.println, tırnak içindeki yazıyı gönderir ve sonraki yazı için yeni satıra geçer` | `println` sayesinde `YANDI` ve `SONDU` ayrı satırlarda görünür. |
| `// Bu kartta seri port pin 0 ve 1'i kullanır; LED'leri bu yüzden pin 8'den yukarı bağlarız` | Arduino Uno'da pin 0 ve 1 seri haberleşmeye ayrılır. |
| `pinMode(8, OUTPUT);` | Pin 8, LED'i açıp kapatacak çıkış olur. |
| `Serial.begin(9600);` | Kartın bilgisayara 9600 hızında yazı göndermesini başlatır. |
| `digitalWrite(8, HIGH);` | Pin 8 açılır; LED yanar. |
| `Serial.println("YANDI");` | Seri Monitör'e `YANDI` yazar ve yeni satıra geçer. |
| `digitalWrite(8, LOW);` | Pin 8 kapanır; LED söner. |
| `Serial.println("SONDU");` | Seri Monitör'e `SONDU` yazar ve yeni satıra geçer. |

`SONDU` özellikle Türkçe karakter kullanmadan yazıldı. Bazı bilgisayarlarda `SÖNDÜ`
yazısındaki `Ö` ve `Ü` bozuk görünebilir; bu, LED kodunun bozuk olduğu anlamına gelmez.

### İleri analiz [ileri]
`Serial.begin(9600)` yalnızca `setup()` içinde çalışır çünkü seri bağlantıyı bir kez
başlatmak yeterlidir. `Serial.println(...)` ise `loop()` içindedir; LED'in her yeni
durumunda yeniden mesaj gönderir.

Kaynak kod `Serial.print` kullandığı için mesajları aynı satıra ekleyip
`YANDISONDUYANDISONDU` biçiminde uzatıyordu. `Serial.println` her mesajdan sonra yeni
satıra geçtiği için LED'in adımları ayrı ayrı okunur.

## 6. Çalıştır ve gözlemle
Kodu karta yükle. Arduino IDE'de Seri Monitör'ü aç ve hızı **9600** seç. LED bir saniye
yanarken ekranda `YANDI`, bir saniye sönerken `SONDU` görünür. Işık ve yazı aynı anda
değişir.

### Sorun giderme
- **LED hiç yanmıyor** → LED ters takılmış olabilir. Uzun bacağın pin 8'e, kısa bacağın
  direnç tarafına baktığını kontrol et.
- **LED yanıyor ama Seri Monitör boş kalıyor** → Kod karta yüklenmemiş ya da yanlış port
  seçilmiş olabilir. Doğru Arduino Uno ve portu seçip kodu yeniden yükle.
- **Seri Monitör'de anlamsız karakterler görünüyor** → Monitör hızı kodla eşleşmiyordur.
  Kodda ve monitörde 9600 seçili olduğunu kontrol et.
- **`YANDISONDU` yazıları aynı satırda birleşiyor** → Kodda `Serial.println` yerine
  `Serial.print` yazılmış olabilir; iki satırı da karşılaştır.
- **`SÖNDÜ` yazınca `S?ND?` gibi bir görüntü çıkıyor** → Türkçe karakter gösterimi
  uyuşmamış olabilir. Mesajı bu dersteki gibi `SONDU` yaz.
- **LED ile yazı aynı anda değişmiyor** → `Serial.println` satırının ilgili
  `digitalWrite` satırının hemen altında olduğunu kontrol et.

## 7. Mini sınav
1. [temel] Kartın gönderdiği `YANDI` ve `SONDU` yazıları nerede görülür?
   - A) Breadboard üzerinde
   - B) Seri Monitör'de
   - C) LED'in içinde
   - D) Direncin üzerinde
   - ipucu: Arduino IDE'de açtığın pencerenin adını düşün.

2. [temel] `Serial.println("YANDI");` satırı ne yapar?
   - A) LED'i yakar
   - B) Bir saniye bekler
   - C) `YANDI` yazıp yeni satıra geçer
   - D) Pin 8'i kapatır
   - ipucu: LED'i yakan satır `digitalWrite` ile başlar.

3. [temel] Seri Monitör'de hangi hız seçilmelidir?
   - A) 8
   - B) 220
   - C) 9600
   - D) 1000
   - ipucu: `Serial.begin(...)` parantezinin içindeki sayıya bak.

4. [temel] Arduino Uno'da LED neden pin 0 veya 1'e bağlanmadı?
   - A) Bu pinler seri port için ayrılmıştır
   - B) Bu pinler yalnız direnç içindir
   - C) Pin 8 daha parlaktır
   - D) Pin 0 ve 1 yoktur
   - ipucu: KAVRAM'daki son yorum satırına bak.

5. [ileri] `Serial.begin(9600)` neden `setup()` içindedir?
   - A) LED'i sürekli yakmak için
   - B) Seri bağlantıyı bir kez başlatmak yeterli olduğu için
   - C) Her saniye hızı değiştirmek için
   - D) Direnci korumak için
   - ipucu: `setup()` kaç kez çalışır?

6. [ileri] Kaynak koddaki `Serial.print` yerine neden `Serial.println` kullanıldı?
   - A) LED daha parlak yansın diye
   - B) Mesajlar ayrı satırlarda kolay okunsun diye
   - C) Seri hız artsın diye
   - D) Pin numarası değişsin diye
   - ipucu: `ln`, yazıdan sonra yeni satıra geçilmesini sağlar.

## 8. AI Yoldaşı promptları

> **Not:** AI Yoldaşı sana devrenin nasıl kurulacağını, hangi pine bağlayacağını ya da
> hangi direnci kullanacağını söylemez — bunlar sadece derste yazar. **AI'ın dediği
> devrende çalışmıyorsa AI yanılmıştır, devren haklıdır.**

- [temel] **Kavramsal** — "Sen sabırlı bir öğretmensin. Arduino Uno kartında 5V mantık
  gerilimiyle çalışan, pin 8'e bağlı ve 220 ohm direnç kullanan bir LED'im var; seri hız
  9600. Kartın LED'in durumunu bilgisayara yazmasının ne işe yaradığını düşünmeme yardım
  et. Cevabı verme; LED'e bakamadığım bir anı hayal ettiren sorular sor."
- [temel] **Hata giderme** — "Sen bir hata ayıklama koçusun. Arduino Uno kartında 5V
  mantık gerilimiyle çalışan, pin 8'e bağlı ve 220 ohm direnç kullanan LED yanıp sönüyor;
  seri hız 9600 olmasına rağmen Seri Monitör boş. Pin numarası, direnç değeri veya bağlantı
  tarifi verme. Cevabı söylemeden, yükleme ve monitör seçimlerini sırayla kontrol ettiren
  sorular sor."
- [ileri] **Kod okuma** — "Sen ileri seviye bir mentorsun. Arduino Uno kartında 5V mantık
  gerilimiyle çalışan, pin 8'e bağlı ve 220 ohm direnç kullanan LED kodumda seri hız 9600;
  pin 0 ve 1 seri porta ayrılmış. `Serial.print` ile `Serial.println` arasındaki görünür
  farkı kendim bulmamı sağla. Cevabı verme, iki olası ekran çıktısını karşılaştırmam için
  sorular sor."
- [temel] **Yanındaki Yetişkine** — "Cevabı söylemeyin. Şu üç şeyi sırayla sorun: LED ile
  yazı aynı anda mı değişiyor? Seri Monitör'de 9600 seçili mi? `println` satırı ilgili
  `digitalWrite` satırının hemen altında mı? Üçü de doğruysa çocukla birlikte bir tam
  yanma-sönme turunu gözlemleyin."

## 9. SEN YAP
1. LED'in 2 saniye yanık, yarım saniye sönük kalmasını sağla.
2. Seri Monitör'de `YANDI` yerine `ISIK ACIK`, `SONDU` yerine `ISIK KAPALI` yazdır.
3. LED ile ekrandaki yazının aynı anda değiştiğini gözlemle.
