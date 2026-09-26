---
ak_no: ak0120
baslik: Sayaç — kart saysın, ekrana yazsın
duzey: 0-temel
unite: 1-LED-ve-Seri-Port
kazanimlar:
  - cpp.setup-loop
  - cpp.delay
  - cpp.serial-begin
  - cpp.serial-println
  - cpp.degisken
  - cpp.atama
kara_kutu: [void, "Serial ve noktalı yazım"]
merak_kosesi: "Serial ve noktalı yazım (1. tur)"
malzeme:
  - Arduino Uno kartı
  - USB kablosu
board:
  kart: Arduino Uno
  seri_port_pinleri: [0, 1]
  seri_hiz: 9600
kaynak:
  - ..\arsiv\009ak120ham\009ak120ham.ino (Özgür yazdı)
---

## 1. Hedef
Kartın kendi kendine sayı saymasını ve her sayıyı Seri Monitör'e yazmasını sağlayacaksın.
Yeni fikir: **değişken** — değeri program çalışırken değişebilen bir isim. ak0050'de
öğrendiğin `const int` bunun tam tersiydi: değeri hiç değişmiyordu.

## 2. Malzemeler
- Arduino Uno kartı
- USB kablosu

Devre yok — bu bir ekran dersi.

## 3. Parça tanıtımı
Yeni parça yok. `Serial.begin` ve `Serial.println`'i ak0110'da öğrendin, burada aynı
komutları kullanıyorsun. Yeni olan tek şey `int sayac = 0;` satırı.

## 4. Devre kurulumu
Devre yok. Arduino Uno'yu USB kablosuyla bilgisayara bağlaman yeterli.

## 5. Kod açıklaması
| kod satırı | açıklama |
| --- | --- |
| `int sayac = 0;` | `sayac` adında bir **değişken** oluşturulur, başlangıç değeri 0'dır. `const` yok, yani bu isim değişebilir. |
| `Serial.begin(9600);` | Kartın bilgisayara 9600 hızında yazı göndermesi başlatılır. |
| `sayac = sayac + 1;` | Eşittirin **sağı önce hesaplanır** (sayac'ın şu anki değerine 1 eklenir), sonra sonuç yeniden `sayac`'ın içine konur. Bu matematikteki eşitlik değildir. |
| `Serial.println(sayac);` | `sayac`'ın o anki değeri Seri Monitör'e yazılır, sonra yeni satıra geçilir. |
| `delay(1000);` | Bir sonraki sayıya geçmeden önce 1000 milisaniye (1 saniye) beklenir. |

### İleri analiz [ileri]
`sayac = sayac + 1;` satırı çalıştığında `sayac` değişkeninin eski değeri okunur, 1
eklenir, sonuç tekrar aynı kutuya (`sayac`) yazılır. Eğer bu satır olmasaydı `sayac`
sonsuza kadar 0 kalırdı — `loop()` her turda sıfırdan başlamaz, `sayac` bir önceki
turdaki değerini korur. Bu, `const int`'in davranışından temelden farklıdır: `const int`
her turda aynı değeri verir çünkü zaten hiç değişmez; `sayac` her turda değişir çünkü
biz onu değiştiriyoruz.

## 6. Çalıştır ve gözlemle
Kodu karta yükle. Seri Monitör'ü aç, hızı **9600** seç. Ekranda saniyede bir 1, 2, 3, 4...
şeklinde artan sayılar görünür.

### Sorun giderme
- **Hiçbir şey yazmıyor** → Kod yüklenmemiş olabilir. Doğru kartı ve portu seçip tekrar
  yükle.
- **Seri Monitör boş** → Monitör kapalı ya da yanlış port seçili. Monitörü açıp kodu
  yüklediğin portu seç.
- **Ekrandaki yazılar anlamsız karakterlerden oluşuyor** → Seri Monitör hızı 9600 değil.
  Hem kodda hem monitörde 9600 olduğunu kontrol et.
- **Sayı hiç artmıyor, hep aynı sayı yazıyor** → `sayac = sayac + 1;` satırı silinmiş ya
  da yanlış yazılmış olabilir; satırı KAVRAM'daki hâliyle karşılaştır.
- **Sayılar 0'dan değil başka bir sayıdan başlıyor** → `int sayac = 0;` satırındaki
  başlangıç değeri değiştirilmiş olabilir.

## 7. Mini sınav
1. [temel] `int sayac = 0;` satırındaki `sayac` ne olur?
   - A) Hiç değişmeyen bir isim
   - B) Değeri program çalışırken değişebilen bir isim
   - C) Bir pin numarası
   - D) Bir LED'in adı
   - ipucu: `const` yazılmamış.

2. [temel] `sayac = sayac + 1;` satırı çalıştığında hangisi doğrudur?
   - A) Önce sağdaki hesaplanır, sonra sonuç sayac'ın içine konur
   - B) sayac ve sayac+1 eşit olduğu için hiçbir şey değişmez
   - C) sayac her zaman 1 olur
   - D) Bu satır bir hata verir
   - ipucu: Bu matematiksel eşitlik değil.

3. [temel] Ekranda sayılar ne sıklıkla artar?
   - A) delay(1000) yüzünden saniyede bir
   - B) Anında, hiç beklemeden
   - C) Dakikada bir
   - D) Kart her yeniden başladığında
   - ipucu: `delay`'in parantez içindeki sayıya bak, birim milisaniye.

4. [temel] Bu dersin devresi nedir?
   - A) 1 LED
   - B) 4 LED
   - C) Devre yok, sadece kart ve USB
   - D) Buton
   - ipucu: Başlıktaki "Devre" satırına bak.

5. [ileri] `int sayac = 0;` satırı `int sayac = 100;` olsa ekranda ilk sayı ne olur?
   - A) 0
   - B) 1
   - C) 100
   - D) 101
   - ipucu: `loop()` çalışmadan önce bir kez `+1` yapılmış olur.

6. [ileri] `sayac = sayac + 1;` ile `const int` arasındaki temel fark nedir?
   - A) İkisi de aynı şeyi yapar
   - B) `const int` bir kere yazılır ve hiç değişmez; `sayac` her turda güncellenir
   - C) `const int` sadece LED'lerde kullanılır
   - D) `sayac` yalnızca bir kere kullanılabilir
   - ipucu: ak0050'deki `const int`'i hatırla.

## 8. AI Yoldaşı promptları

> **Not:** AI Yoldaşı sana devrenin nasıl kurulacağını söylemez — bu derste zaten devre
> yok. **AI'ın dediği kartında çalışmıyorsa AI yanılmıştır, kartın haklıdır.**

- [temel] **Eşleştirme** — "Sen sabırlı bir öğretmensin. Arduino Uno kartımda seri hız
  9600, devre yok, sadece kart ve USB var; kodum saniyede bir artan bir sayı yazdırıyor.
  `sayac = sayac + 1;` satırının ne yaptığını anlamama yardım et. Cevabı söyleme; bana
  bir turun (bir `loop()` çalışmasının) baştan sona ne yaptığını adım adım
  gözlemleten sorular sor."
- [temel] **Hata giderme** — "Sen bir hata ayıklama koçusun. Arduino Uno kartımda seri
  hız 9600, devre yok; sayaç kodum hep aynı sayıyı yazıyor, hiç artmıyor. Cevabı verme;
  `sayac = sayac + 1;` satırının kodda olup olmadığını ve doğru yazılıp yazılmadığını
  kontrol etmemi sağlayan sorular sor."
- [ileri] **Kavram derinleştirme** — "Sen ileri seviye bir mentorsun. Arduino Uno
  kartımda seri hız 9600; `int sayac = 0;` ile `const int isim = sayi;` arasındaki farkı
  anlamama yardım et. Cevabı söyleme, ikisinin ne zaman değiştiğini ve ne zaman hiç
  değişmediğini karşılaştırmam için sorular sor."
- [temel] **Yanındaki Yetişkine** — "Cevabı söylemeyin. Şu üç şeyi sırayla sorun: Seri
  Monitör'de sayı artıyor mu? Kaçta bir artıyor (kaç saniyede bir)? `sayac = sayac + 1;`
  satırını okuyunca eşittirin hangi tarafının önce hesaplandığını söyleyebiliyor mu?"

## 9. SEN YAP
1. `sayac = sayac + 1;` satırını `sayac = sayac + 2;` yap. Seri Monitör'de ne değişti?
2. `int sayac = 0;` satırını `int sayac = 100;` yap. Sayma nereden başladı?
3. `delay(1000);` değerini değiştir. Sayıların ekrana çıkma hızı nasıl değişti?
