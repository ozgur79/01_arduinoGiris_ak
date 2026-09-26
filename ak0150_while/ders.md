---
ak_no: ak0150
baslik: "while: olduğu sürece say"
duzey: 0-temel
unite: 1-LED-ve-Seri-Port
kazanimlar:
  - cpp.setup-loop
  - cpp.delay
  - cpp.serial-begin
  - cpp.serial-println
  - cpp.while
onkosul:
  - cpp.for (ak0130)
  - cpp.arttirma (ak0130)
  - cpp.degisken (ak0120)
kara_kutu: [void, "Serial ve noktalı yazım"]
merak_kosesi: "int taşması (ek kutu, Özgür'ün isteği — rotasyon dışı)"
malzeme:
  - Arduino Uno kartı
  - USB kablosu
board:
  kart: Arduino Uno
  seri_port_pinleri: [0, 1]
  seri_hiz: 9600
kaynak:
  - ..\arsiv\kabaMüfredat.docx, madde 023
---

## 1. Hedef
ak0130'da `for` ile bir satırda topladığın sayma işini bu sefer `while` ile
yazacaksın — aynı sonuç, üç parça bu kez ayrı ayrı duruyor.

## 2. Malzemeler
- Arduino Uno kartı
- USB kablosu

Devre yok — ekran dersi.

## 3. Parça tanıtımı
Yeni parça yok. `Serial.begin`, `Serial.println`, değişken ve `sayac++`'ı biliyorsun.
Yeni olan `while` yapısı.

## 4. Devre kurulumu
Devre yok. Arduino Uno'yu USB kablosuyla bilgisayara bağlaman yeterli.

## 5. Kod açıklaması
| kod satırı | açıklama |
| --- | --- |
| `int sayac = 1;` | Başlangıç — `while`'dan önce, ayrı bir satır. |
| `while (sayac <= 10)` | Koşul — `sayac` 10'dan küçük ya da eşit **olduğu sürece** blok çalışır. |
| `Serial.println(sayac);` | Bloğun içindeki asıl iş: `sayac`'ı yazdırır. |
| `delay(500);` | ak0130 ile aynı ritim: her sayı arasında yarım saniye beklenir. |
| `sayac++;` | Artış — blok bitmeden hemen önce, en son satır. |

### İleri analiz [ileri]
`for (int sayac = 1; sayac <= 10; sayac++)` tek satırda üç bölme taşıyordu. `while`
aynı üç parçayı üç ayrı yere dağıtır: başlangıç `while`'dan önce bir kez, koşul
`while(...)` parantezinde her turun başında kontrol edilir, artış blok içinde en son
çalışır. Artış satırı unutulursa (SEN YAP 1) koşul hiçbir zaman yanlış olmaz — bu,
`for`'da da olabilecek ama `while`'da unutmanın daha kolay olduğu bir hatadır, çünkü
üç parça artık göz önünde tek satırda değil.

## 6. Çalıştır ve gözlemle
Kodu karta yükle. Seri Monitör'ü aç, hızı **9600** seç. 1'den 10'a kadar sayılar
yarım saniye arayla görünür, sonra durur.

### Sorun giderme
- **Hiçbir şey yazmıyor** → Kod yüklenmemiş olabilir; doğru kartı ve portu seçip
  tekrar yükle.
- **Sayma hiç durmuyor, aynı sayı tekrar tekrar yazılıyor** → `sayac++;` satırı
  silinmiş olabilir (SEN YAP 1'i deniyorsan bu normaldir — kazara kurulmuş bir sonsuz
  döngü).
- **Sayılar 1'den değil başka bir sayıdan başlıyor** → `int sayac = 1;` satırındaki
  başlangıç değeri değiştirilmiş olabilir.
- **Ekrandaki yazılar anlamsız karakterlerden oluşuyor** → Seri Monitör hızı 9600
  değil; hem kodda hem monitörde 9600 olduğunu kontrol et.

## 7. Mini sınav
1. [temel] `while (sayac <= 10)` satırı ne anlama gelir?
   - A) sayac 10'dan büyük olduğu sürece
   - B) sayac 10'dan küçük ya da eşit olduğu sürece
   - C) sayac tam olarak 10 olunca
   - D) Hiçbir zaman
   - ipucu: `<=` "küçük ya da eşit" demek.

2. [temel] `sayac++;` satırı bu derste nerede duruyor?
   - A) `while`'dan önce
   - B) `while(...)` parantezinin içinde
   - C) `{ }` bloğunun en son satırı
   - D) `Serial.begin`'in içinde
   - ipucu: Koda bak.

3. [temel] `sayac++;` satırı silinirse ne olur?
   - A) Kod derlenmez
   - B) Koşul hiç yanlış olmaz, sayma hiç durmaz
   - C) Sayma tersine döner
   - D) Ekranda hiçbir şey görünmez
   - ipucu: sayac hep aynı değerde kalır.

4. [temel] Bu dersin devresi nedir?
   - A) 1 LED
   - B) Devre yok, sadece kart ve USB
   - C) 4 LED
   - D) Buton
   - ipucu: Başlıktaki "Devre" satırına bak.

5. [ileri] `for`'un tek satırdaki üç bölmesi (başlangıç; koşul; artış) `while`'da
   nereye dağılır?
   - A) Üçü de aynı satırda kalır
   - B) Başlangıç öncesine, koşul parantezine, artış blok sonuna
   - C) Üçü de blok içine
   - D) Üçü de silinir
   - ipucu: KAVRAM tablosuna bak.

6. [ileri] Aşağıdaki deneyde (Merak Köşesi) `int sayac` neden sonunda -32768 olur?
   - A) Programda bir hata var
   - B) `int` kutusunun bir üst sınırı var (32767); aşılınca en küçük değere döner
   - C) Kart resetlenir
   - D) `Serial.println` sayıyı ters çevirir
   - ipucu: Her kutunun bir sınırı var.

## 8. AI Yoldaşı promptları

> **Not:** AI Yoldaşı sana devrenin nasıl kurulacağını söylemez — bu derste zaten
> devre yok. **AI'ın dediği kartında çalışmıyorsa AI yanılmıştır, kartın haklıdır.**

- [temel] **Eşleştirme** — "Sen sabırlı bir öğretmensin. Arduino Uno kartımda seri hız
  9600, devre yok; kodum `while (sayac <= 10)` ile 1'den 10'a sayıyor.
  `while`'ın `for`'dan farkını anlamama yardım et. Cevabı söyleme; başlangıç, koşul ve
  artışın kodda nerede durduğunu bulduran sorular sor."
- [temel] **Hata giderme** — "Sen bir hata ayıklama koçusun. Arduino Uno kartımda seri
  hız 9600; `while` döngüm hiç durmuyor. Cevabı verme; `{ }` bloğunun içinde artış
  satırının olup olmadığını kontrol etmemi sağlayan sorular sor."
- [ileri] **Kavram derinleştirme** — "Sen ileri seviye bir mentorsun. Arduino Uno
  kartımda seri hız 9600; `int` değişkenin neden sonsuza kadar büyüyemeyeceğini
  anlamama yardım et. Cevabı söyleme, kutunun bir sınırı olduğunu kendim keşfetmem
  için sorular sor."
- [temel] **Yanındaki Yetişkine** — "Cevabı söylemeyin. Şu üç şeyi sırayla sorun:
  Sayma kaçtan kaça gidiyor? Sayma nerede duruyor? `while (sayac <= 10)` satırı
  hangi soruya cevap veriyor: 'ne zaman devam edilir' mi, 'ne zaman durulur' mu?"

## 9. SEN YAP
1. `sayac++;` satırını sil. Kodu yükle, Seri Monitör'ü aç. Ne oldu?
2. 10'dan 1'e geriye say (başlangıcı, koşulu ve artışı buna göre çevir: `sayac--`).
3. Aşağıdaki tabloyu kendi kodunla doldur: `for`'un üç parçası `while`'da nereye gitti?
