---
ak_no: ak0130
baslik: "for: sayma işini tek satıra topla"
duzey: 0-temel
unite: 1-LED-ve-Seri-Port
kazanimlar:
  - cpp.setup-loop
  - cpp.delay
  - cpp.serial-begin
  - cpp.serial-println
  - cpp.for
  - cpp.arttirma
onkosul:
  - cpp.degisken (ak0120)
  - cpp.atama (ak0120)
kara_kutu: [void, "Serial ve noktalı yazım"]
merak_kosesi: "Serial ve noktalı yazım (2. tur)"
malzeme:
  - Arduino Uno kartı
  - USB kablosu
board:
  kart: Arduino Uno
  seri_port_pinleri: [0, 1]
  seri_hiz: 9600
kaynak:
  - ..\arsiv\002for1den100e\002for1den100e.ino
---

## 1. Hedef
ak0120'de sayacın üç parçası (başlangıç, artış, hiç durmama) kodun üç ayrı yerinde
duruyordu. Bu derste `for` ile bu üç parçayı **tek satırda** toplayacaksın.

## 2. Malzemeler
- Arduino Uno kartı
- USB kablosu

Devre yok — üst üste ikinci ve son ekran dersi.

## 3. Parça tanıtımı
Yeni parça yok. `Serial.begin` ve `Serial.println`'i biliyorsun. Yeni olan `for` yapısı
ve `Serial.print` (yeni satıra geçmeyen yazdırma).

## 4. Devre kurulumu
Devre yok. Arduino Uno'yu USB kablosuyla bilgisayara bağlaman yeterli.

## 5. Kod açıklaması
| kod satırı | açıklama |
| --- | --- |
| `for (int sayac = 1; sayac <= 10; sayac++)` | Üç parça tek satırda: `sayac = 1` (başlangıç, bir kere), `sayac <= 10` (koşul, her turda kontrol edilir), `sayac++` (artış, her turun sonunda). |
| `Serial.print("Sayac: ");` | Yazıyı yazar ama imleci **aynı satırda** bırakır. |
| `Serial.println(sayac);` | `sayac`'ın değerini yazar ve **yeni satıra** geçer. |
| `delay(500);` | Her sayı arasında 500 milisaniye (yarım saniye) beklenir. |
| `sayac++` | `sayac = sayac + 1;`'in kısa yazılışı — ak0120'de öğrendiğin satırın kısaltması. |

### İleri analiz [ileri]
`for` döngüsünün üç bölmesi çalışma sırasına göre şöyledir: önce **başlangıç** bir kez
çalışır (`sayac = 1`), sonra her turun başında **koşul** kontrol edilir (`sayac <= 10`
doğru mu?), koşul doğruysa `{ }` içi çalışır, en son **artış** çalışır (`sayac++`) ve
döngü koşulu tekrar kontrol eder. Koşul yanlış olduğu an döngü biter. Bu döngü `setup()`
içinde olduğu için yalnızca kart açılınca bir kez, 1'den 10'a kadar çalışıp durur —
`loop()` boş kaldığı için bir daha tetiklenmez.

## 6. Çalıştır ve gözlemle
Kodu karta yükle. Seri Monitör'ü aç, hızı **9600** seç. "Sayac: 1"'den "Sayac: 10"'a
kadar yarım saniye arayla sayılar görünür, sonra durur (kart resetlenmeden bir daha
yazmaz).

### Sorun giderme
- **Hiçbir şey yazmıyor** → Kod yüklenmemiş olabilir; doğru kartı ve portu seçip tekrar
  yükle.
- **Sadece 10'dan sonraki bir sayı görünmüyor, hep tekrar ediyor** → `for` satırı
  `loop()`'a taşınmış olabilir; SEN YAP 1'i henüz yapmadıysan bu normal değildir, kodu
  KAVRAM'daki hâliyle karşılaştır.
- **Sayılar 1'den değil başka bir sayıdan başlıyor** → `for`'un başlangıç bölmesi
  (`sayac = 1`) değiştirilmiş olabilir.
- **10'a kadar değil daha ileri/geri sayıyor** → `for`'un koşul bölmesi (`sayac <= 10`)
  kontrol edilmeli.
- **Ekrandaki yazılar anlamsız karakterlerden oluşuyor** → Seri Monitör hızı 9600 değil;
  hem kodda hem monitörde 9600 olduğunu kontrol et.

## 7. Mini sınav
1. [temel] `for (int sayac = 1; sayac <= 10; sayac++)` satırındaki üçüncü bölme
   (`sayac++`) ne zaman çalışır?
   - A) Sadece bir kere, döngü başlarken
   - B) Her turun sonunda
   - C) Hiçbir zaman
   - D) Sadece koşul yanlış olduğunda
   - ipucu: Artış bölmesi her turu bir sonrakine taşır.

2. [temel] `Serial.print` ile `Serial.println` arasındaki fark nedir?
   - A) İkisi de aynı şeyi yapar
   - B) `print` yeni satıra geçmez, `println` geçer
   - C) `print` sayı yazamaz
   - D) `println` sadece bir kere kullanılabilir
   - ipucu: Kodda ikisi art arda duruyor, "Sayac: 3" gibi tek satır çıkıyor.

3. [temel] Bu dersteki `for` nerede duruyor?
   - A) `loop()` içinde
   - B) `setup()` içinde
   - C) İkisinin de dışında
   - D) `Serial.begin`'in içinde
   - ipucu: Koda bak, hangi süslü parantezlerin arasında.

4. [temel] `sayac++` ne anlama gelir?
   - A) `sayac = sayac - 1;`
   - B) `sayac = sayac + 1;`
   - C) `sayac = 0;`
   - D) `sayac`'ı ekrana yazdırır
   - ipucu: ak0120'de aynı işi uzun yazmıştın.

5. [ileri] `for` bu derste `loop()` yerine `setup()`'ta olduğu için ne olur?
   - A) Sayma bir kez olur ve durur
   - B) Sayma hiç durmadan tekrarlanır
   - C) Kod çalışmaz
   - D) `Serial.begin` çalışmaz
   - ipucu: `setup()` kart açılınca yalnızca bir kez çalışır.

6. [ileri] `for`'un üç bölmesi (başlangıç; koşul; artış), ak0120'nin hangi üç satırının
   yerini tutuyor?
   - A) `int sayac = 0;`, `sayac = sayac + 1;`, `delay(1000);`
   - B) `int sayac = 0;` (başlangıç), sayacın hiç durmaması (koşul yoktu), `sayac = sayac + 1;` (artış)
   - C) Yalnızca `Serial.println(sayac);`
   - D) `Serial.begin(9600);`
   - ipucu: ak0120'de sayaç hiç durmuyordu; burada bir koşulla durduruluyor.

## 8. AI Yoldaşı promptları

> **Not:** AI Yoldaşı sana devrenin nasıl kurulacağını söylemez — bu derste zaten devre
> yok. **AI'ın dediği kartında çalışmıyorsa AI yanılmıştır, kartın haklıdır.**

- [temel] **Eşleştirme** — "Sen sabırlı bir öğretmensin. Arduino Uno kartımda seri hız
  9600, devre yok; kodum `for (int sayac = 1; sayac <= 10; sayac++)` ile 1'den 10'a
  sayıyor. `for`'un üç bölmesinin (başlangıç, koşul, artış) hangi sırayla çalıştığını
  anlamama yardım et. Cevabı söyleme; bana bir turu adım adım gözlemleten sorular sor."
- [temel] **Hata giderme** — "Sen bir hata ayıklama koçusun. Arduino Uno kartımda seri
  hız 9600; `for` döngüm hiç durmuyor, sonsuza kadar sayıyor gibi görünüyor. Cevabı
  verme; `for`'un `setup()`'ta mı `loop()`'ta mı olduğunu kontrol etmemi sağlayan
  sorular sor."
- [ileri] **Kavram derinleştirme** — "Sen ileri seviye bir mentorsun. Arduino Uno
  kartımda seri hız 9600; ak0120'deki `sayac = sayac + 1;` satırı ile bu dersteki
  `for (...; ...; sayac++)` arasındaki ilişkiyi anlamama yardım et. Cevabı söyleme,
  üç bölmenin ak0120'nin hangi satırlarının yerini tuttuğunu bulmam için sorular sor."
- [temel] **Yanındaki Yetişkine** — "Cevabı söylemeyin. Şu üç şeyi sırayla sorun: Seri
  Monitör'de kaçtan kaça sayıyor? Kaç saniyede bir sayı değişiyor? `for` satırındaki üç
  bölmeden hangisi 'ne zaman duracağını' söylüyor?"

## 9. SEN YAP
1. `for` satırını `loop()` içine taşı (`setup()` boş kalsın). Ne değişti? Sayma neden
   hiç durmuyor?
2. 10'dan 1'e geriye say (artış yerine `sayac--`, koşulu buna göre çevir).
3. 0'dan 100'e beşer beşer say (artışı `sayac = sayac + 5` ya da `sayac += 5` yap).
