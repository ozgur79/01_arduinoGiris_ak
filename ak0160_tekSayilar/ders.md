---
ak_no: ak0160
baslik: "Tek sayılar: if + %"
duzey: 0-temel
unite: 1-LED-ve-Seri-Port
kazanimlar:
  - cpp.setup-loop
  - cpp.delay
  - cpp.serial-begin
  - cpp.serial-println
  - cpp.if
  - cpp.kalan
  - cpp.karsilastirma
onkosul:
  - cpp.sonsuz_dongu (ak0155)
  - cpp.degisken/cpp.atama (ak0120)
  - cpp.for/cpp.arttirma — <= karşılaştırması (ak0130)
kara_kutu: [void, OUTPUT]
merak_kosesi: "Serial ve noktalı yazım (3. tur, bundan sonra emekli)"
malzeme:
  - Arduino Uno kartı
  - USB kablosu
board:
  kart: Arduino Uno
  seri_port_pinleri: [0, 1]
  seri_hiz: 9600
kaynak:
  - ..\arsiv\kabaMüfredat.docx, madde 024
---

## 1. Hedef
Kartın 1'den başlayarak sayarken yalnızca **tek sayıları** ekrana yazmasını
sağlayacaksın. İki yeni fikir birlikte gelir: `if` (koşul doğruysa çalış) ve `%`
(kalan) — `%` burada `if`'in koşulunu kurmak için bir alet.

## 2. Malzemeler
- Arduino Uno kartı
- USB kablosu

Devre yok — ekran dersi.

## 3. Parça tanıtımı
Yeni parça yok. `Serial.begin`/`Serial.println`, değişken ve sonsuz döngü fikrini
(ak0155) biliyorsun.

## 4. Devre kurulumu
Devre yok. Arduino Uno'yu USB kablosuyla bilgisayara bağlaman yeterli.

## 5. Kod açıklaması
| kod satırı | açıklama |
| --- | --- |
| `int sayac = 1;` | `loop()`'un dışında, global — her turda sıfırlanmasın diye. |
| `if (sayac % 2 != 0)` | `sayac`'ın 2'ye bölümünden kalan sıfıra **eşit değilse** (yani tek sayıysa) blok çalışır. |
| `Serial.println(sayac);` | Yalnızca koşul doğruyken çalışır — `if`'in `{ }` bloğunun içinde. |
| `sayac++;` | `if`'in dışında, her turda çalışır — sayaç `if` doğru olsun olmasın ilerler. |
| `delay(200);` | Her tur arasında kısa bir bekleme. |

### İleri analiz [ileri]
`%` (kalan) bir bölmenin kalanını verir: `7 % 2` = 1 (7'yi 2'ye böl, kalan 1),
`8 % 2` = 0 (8'i 2'ye böl, kalan 0). Kalan hep 0 ise sayı **çift**, değilse **tek**tir.
`sayac % 2 != 0` ile `sayac % 2 == 1` tam olarak aynı koşuldur — ikisini de görebilirsin.
`!=` ve `==` birer **karşılaştırma operatörü**dür; ak0130'da `<=` ile (for'un koşulunda)
tanışmıştın, burada aynı ailenin iki yeni üyesini adlandırıyoruz: `==` "tam olarak eşit
mi?", `!=` "eşit değil mi?" diye sorar.

Kaynak koddaki `while (1)` burada kullanılmadı: `loop()` zaten kendi başına sonsuz bir
döngü (ak0155), ikinci bir `while (true)` eklemek aynı fikri gereksiz yere tekrarlardı.
Bunun yerine sayaç `loop()`'un dışında, **global** tanımlandı — `loop()`'un içinde
olsaydı her turda yeniden `1`'e sıfırlanırdı.

## 6. Çalıştır ve gözlemle
Kodu karta yükle. Seri Monitör'ü aç, hızı **9600** seç. Ekranda 1, 3, 5, 7, 9...
şeklinde yalnızca tek sayılar görünür.

### Sorun giderme
- **Hiçbir şey yazmıyor** → Kod yüklenmemiş olabilir; doğru kartı ve portu seçip
  tekrar yükle.
- **Hem tek hem çift sayılar yazılıyor** → `if` satırı ya da `%` işlemi yanlış
  yazılmış olabilir; KAVRAM'daki hâliyle karşılaştır.
- **Hiçbir sayı yazılmıyor, sadece bekliyor gibi** → `sayac++;` satırı `if`'in İÇİNE
  yanlışlıkla girmiş olabilir; o zaman `sayac` bazı turlarda hiç artmaz.
- **Sayı hiç ilerlemiyor, hep aynı sayı** → `int sayac = 1;` satırı `loop()`'un İÇİNE
  taşınmış olabilir — bu durumda her turda yeniden 1'e sıfırlanır.
- **Ekrandaki yazılar anlamsız karakterlerden oluşuyor** → Seri Monitör hızı 9600
  değil; hem kodda hem monitörde 9600 olduğunu kontrol et.

## 7. Mini sınav
1. [temel] `7 % 2` işleminin sonucu nedir?
   - A) 3
   - B) 1
   - C) 0
   - D) 14
   - ipucu: 7'yi 2'ye böl, kalanı bul.

2. [temel] `if (sayac % 2 != 0)` satırı ne zaman çalışır?
   - A) sayac çift olduğunda
   - B) sayac tek olduğunda
   - C) Her zaman
   - D) Hiçbir zaman
   - ipucu: `!=` "eşit değil" demek; kalan sıfıra eşit değilse sayı tektir.

3. [temel] `sayac++;` satırı neden `if`'in DIŞINDA duruyor?
   - A) Yanlışlıkla öyle yazılmış
   - B) sayac'ın if doğru olsun olmasın her turda ilerlemesi gerekiyor
   - C) if'in içinde olsa kod derlenmez
   - D) Fark etmez, ikisi de aynı sonucu verir
   - ipucu: sayac if'in içine girseydi, tek sayı yazılmayan turlarda ne olurdu?

4. [temel] Bu dersin devresi nedir?
   - A) Devre yok, sadece kart ve USB
   - B) 1 LED
   - C) 4 LED
   - D) Buton
   - ipucu: Başlıktaki "Devre" satırına bak.

5. [ileri] `int sayac = 1;` satırı `loop()`'un içine taşınsaydı ne olurdu?
   - A) Hiçbir şey değişmezdi
   - B) sayac her turda yeniden 1'e sıfırlanır, hep "1" yazılırdı
   - C) Kod derlenmezdi
   - D) Sayma tersine dönerdi
   - ipucu: `loop()` her turda baştan çalışır.

6. [ileri] `sayac % 2 != 0` ile aynı işi yapan başka bir yazım hangisidir?
   - A) `sayac % 2 == 1`
   - B) `sayac % 2 == 0`
   - C) `sayac <= 2`
   - D) `sayac / 2`
   - ipucu: Kalan 0 değilse, 2'ye bölümde kalan ne olabilir?

## 8. AI Yoldaşı promptları

> **Not:** AI Yoldaşı sana devrenin nasıl kurulacağını söylemez — bu derste zaten
> devre yok. **AI'ın dediği kartında çalışmıyorsa AI yanılmıştır, kartın haklıdır.**

- [temel] **Eşleştirme** — "Sen sabırlı bir öğretmensin. Arduino Uno kartımda seri hız
  9600, devre yok; kodum `%` ve `if` ile yalnız tek sayıları yazdırıyor. `%`
  işleminin ne yaptığını anlamama yardım et. Cevabı söyleme; birkaç sayıyı elle 2'ye
  bölüp kalanı bulduran sorular sor."
- [temel] **Hata giderme** — "Sen bir hata ayıklama koçusun. Arduino Uno kartımda seri
  hız 9600; kodum hem tek hem çift sayıları yazdırıyor, sadece tek sayıları yazması
  gerekiyordu. Cevabı verme; `if` satırındaki koşulu ve `%` işlemini kontrol etmemi
  sağlayan sorular sor."
- [ileri] **Kavram derinleştirme** — "Sen ileri seviye bir mentorsun. Arduino Uno
  kartımda seri hız 9600; `sayac % 2 != 0` ile `sayac % 2 == 1` satırlarının neden aynı
  sonucu verdiğini anlamama yardım et. Cevabı söyleme, `%`'nin çıkarabileceği tüm
  değerleri (0 ve 1) listeletecek sorular sor."
- [temel] **Yanındaki Yetişkine** — "Cevabı söylemeyin. Şu üç şeyi sırayla sorun:
  Ekranda hangi sayılar görünüyor, tek mi çift mi? `if` satırındaki koşul ne diyor?
  `sayac++;` satırı neden `if`'in dışında duruyor?"

## 9. SEN YAP
1. Yalnız çift sayıları yazdır (koşulu değiştir, `else` ekleme).
2. Yalnız 3'e tam bölünen sayıları yazdır (`sayac % 3 == 0`).
3. 5'e tam bölünen sayılarda "BOM" yazdır, diğer sayılarda hiçbir şey yazma (yine
   `else` kullanmadan, tek bir `if` ile).
