---
ak_no: ak0330
baslik: "Butonla binary sayıcı: sıçrama (debounce)"
duzey: 0-temel
unite: 3-Buton-ve-Seri-Port
kazanimlar:
  - cpp.debounce
  - hw.buton_sicrama
  - cpp.kenar_tetikleme
  - cpp.dizi
  - cpp.kalan
onkosul:
  - cpp.kenar_tetikleme (ak0320)
  - cpp.dizi (ak0185)
  - cpp.kalan (ak0160, ak0190)
  - hw.buton_sicrama (ak0250)
kara_kutu: [void, "Serial ve noktalı yazım"]
merak_kosesi: "atlandı (yük freni — harcama dersi: binary + kenar tetikleme + sıçrama bir arada)"
malzeme:
  - Arduino Uno kartı
  - USB kablosu
  - Paket 5 devresi (4 LED, pin 3/5/6/9)
  - 1 buton (pin 2), 1 adet 10 kΩ direnç (pull-down)
board:
  kart: Arduino Uno
  led_pinleri: [3, 5, 6, 9]
  bit_sirasi: "pin 9 = 1'ler (en sağ), pin 6 = 2'ler, pin 5 = 4'ler, pin 3 = 8'ler (en sol)"
  buton_pinleri: [2, 8]
  pull_direnci: "10 kΩ, pull-down"
  basili_degeri: HIGH
  seri_port_pinleri: [0, 1]
  seri_hiz: 9600
kaynak:
  - "kendi ak0190 (binary sayıcı) + ak0320 (kenar tetikleme); 024kirmiziButon yalnız fikir"
---

## 1. Hedef
Her butona basışta 4 LED'in ikilik olarak 1 artan bir sayıyı göstermesini sağlayacak
ve butonun "titremesini" (sıçrama) tanıyacaksın.

## 2. Malzemeler
- Arduino Uno kartı, USB kablosu
- Paket 5 devresi (4 LED, pin 3/5/6/9), pin 2'deki buton ve pull-down direnç

## 3. Parça tanıtımı
Yeni parça yok. Yeni fikir: **sıçrama** ve çaresi (kısa `delay`).

## 4. Devre kurulumu
ak0190'ın LED devresi + ak0320'deki Buton 1 (pin 2) aynen — dokunma.

## 5. Kod açıklaması
| kod satırı | açıklama |
| --- | --- |
| `if (durum == HIGH && sonDurum == LOW)` | Yeni basıldı (ak0320). |
| `sayi++; if (sayi == 16) { sayi = 0; }` | Sayıyı artır, 15'ten sonra baştan. |
| `(sayi % 2) > 0` ... `(sayi % 16) > 7` | Her basamağın açık mı kapalı mı olduğu (ak0190). |
| `delay(50);` | Sıçrama geçsin diye kenar yakalandıktan sonra kısa bekleme. |

**Zincir:** ak0190'da sayıyı kart kendi kendine artırıyordu; burada sen butonla
artırıyorsun. Kenar tetikleme (ak0320) bir basışı tek sayıya çevirdi ama tek bir
şeyi çözemedi: buton fiziksel bir parça, kontakları birleşirken çok kısa süre
açılıp kapanabilir. Kart bunu birkaç basış gibi görürse LED'ler bir sayı **atlayabilir**.
Bu her butonda ve her basışta olmaz; atladığını gördüysen sebebi sıçramadır.
Çare: kenar yakalanınca kısa bir `delay` — titreme bitene kadar kart bir sonraki
basışa bakmaz. ak0250'deki `delay(100)` de aynı işi yapıyordu, orada adı "sıçrama"
diye geçmişti; şimdi nedenini biliyorsun.

### İleri analiz [ileri]
`delay` ile bekleme basit ama kartı o süre için kör eder: çok hızlı basışlar kaçabilir.
Kaç milisaniye yeterli olduğu butondan butona çok değişir (kaynak: Ganssle, "A Guide to Debouncing" — milisaniye mertebesi; ders kesin bir süre iddia etmez). Kartı kör etmeden debounce
yapmak `millis()` ister (ak0195'in konusu, bu derste yok).

## 6. Çalıştır ve gözlemle
Yükle. Her basışta LED'ler 0000, 0001, 0010, 0011 ... 1111 diye ilerler ve 16. basışta
0'a döner. Seri Monitör'de aynı sayı yazar.

### Sorun giderme
- **LED'ler hiç ilerlemiyor** → Buton pin 2'de mi, pull-down var mı? Seri Monitör'de
  "Sayi:" çıkıyor mu, çıkıyorsa sorun LED devresinde.
- **Bazen iki sayı birden atlıyor** → Sıçrama olabilir; `delay(50)` yerinde mi?
- **Sayı ekranda doğru ama LED'ler yanlış** → LED bacakları / pin sırası ak0190'la aynı
  mı (en sağ pin 9 = 1'ler)?
- **LED'ler hep yanık / rastgele** → Buton pull-down'ı eksik, pin havada.
- **Hızlı basışlar sayılmıyor** → `delay` çok uzun olabilir (SEN YAP 2).

## 7. Mini sınav
1. [temel] Buton sıçraması nedir?
   - A) Butonun eğilmesi
   - B) Basılırken kontakların çok kısa süre açılıp kapanması
   - C) LED titremesi
   - D) Seri port hatası
   - ipucu: Kavram bölümü.

2. [temel] Sıçrama her zaman mı görünür?
   - A) Evet, hep
   - B) Hayır, butondan butona değişir, hiç görünmeyebilir
   - C) Yalnız LED'de
   - D) Yalnız seri portta
   - ipucu: "atlayabilir" deniyor.

3. [temel] `delay(50)` burada ne işe yarar?
   - A) LED'i yavaşlatır
   - B) Titreme geçsin diye kartı kısa bir süre bekletir
   - C) Sayacı sıfırlar
   - D) Seri hızı değiştirir
   - ipucu: Kenar yakalandıktan sonra.

4. [temel] 16. basıştan sonra sayı kaç olur?
   - A) 16
   - B) 0
   - C) 15
   - D) 1
   - ipucu: `sayi == 16`.

5. [ileri] `delay`'i çok uzun yapınca (ör. 500) ne olabilir?
   - A) Hiçbir şey
   - B) Çok hızlı art arda basışlar okunamayabilir
   - C) Sayaç geri sayar
   - D) LED söner
   - ipucu: Bekleme sırasında kart butonu okumaz.

6. [ileri] 4 LED ile en fazla kaç farklı sayı gösterilebilir?
   - A) 4
   - B) 8
   - C) 16
   - D) 32
   - ipucu: 2×2×2×2.

## 8. AI Yoldaşı promptları

> **Not:** AI Yoldaşı sana pin numarası, direnç değeri ya da bağlantı tarifi
> vermez — bunlar yalnız dersten gelir. **AI'ın dediği devrende çalışmıyorsa AI
> yanılmıştır, devren haklıdır.**

- [temel] **Eşleştirme** — "Sen sabırlı bir öğretmensin. Arduino Uno kartımda pin
  3/5/6/9'da 4 LED (pin 9 = 1'ler basamağı) ve pin 2'de 10 kΩ pull-down'lı bir buton
  var, seri hız 9600. Her basışta sayı 1 artıyor ve LED'lerde ikilik gösteriliyor.
  Bazen bir sayı atlıyor. Nedenini anlamama yardım et. Cevabı söyleme; butonun fiziksel
  olarak basılırken ne yaptığını buldurcak sorular sor."
- [temel] **Hata giderme** — "Sen bir hata ayıklama koçusun. Arduino Uno kartımda
  butonla ilerleyen 4 LED'li ikilik sayıcım var. Seri Monitör doğru sayıyı yazıyor ama
  LED'ler yanlış. Cevabı verme; hangi katmanın (buton, kod, LED devresi) doğru
  çalıştığını ayırmamı sağlayacak sorular sor."
- [ileri] **Kavram derinleştirme** — "Sen ileri seviye bir mentorsun. Arduino Uno
  kartımda sıçramayı `delay` ile geçiştiriyorum. Bu yöntemin artısını ve eksisini
  düşünmeme yardım et. Cevabı söyleme, sorularla yönlendir."
- [temel] **Yanındaki Yetişkine** — "Cevabı söylemeyin. Şu üç şeyi sırayla sorun:
  Bir basışta sayı kaç artıyor? Hiç sayı atladı mı? `delay` süresini değiştirince ne
  fark etti?"

## 9. SEN YAP
1. Butona yavaş yavaş, tek tek bas. LED'ler 0'dan 15'e tek tek mi ilerliyor, yoksa
   atlama var mı? (Atlamayabilir; görmediysen "bu denemede görmedim" yaz.)
2. `delay(50)` yerine `delay(0)` yaz, yükle, tek tek bas. Fark var mı? Sonra
   `delay(500)` yap ve hızlı art arda bas. Ne oluyor? Tahmin yazma, dene.
3. Kaç basışta 15'ten 0'a dönüyor? Bunu yapan satır hangisi?
4. 8 LED olsaydı en büyük sayı kaç olurdu?
