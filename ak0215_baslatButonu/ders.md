---
ak_no: ak0215
baslik: "Başlat butonu: butona basılana kadar bekle"
duzey: 0-temel
unite: 2-Buton
kazanimlar:
  - cpp.while
  - cpp.while_bekleme
  - cpp.digitalread
  - hw.buton-devre
onkosul:
  - cpp.while (ak0150)
  - cpp.dizi (ak0185)
  - cpp.digitalread / hw.pull-down (ak0210)
kara_kutu: [void, "Serial ve noktalı yazım"]
merak_kosesi: "atlandı (yük freni — while+buton yeni fikri + kara şimşek köprüsü zaten ağır)"
malzeme:
  - Arduino Uno kartı
  - USB kablosu
  - Paket 5 devresi (4 LED, pin 3/5/6/9)
  - 1 buton (pin 2), 1 adet 10 kΩ direnç (pull-down)
board:
  kart: Arduino Uno
  buton_pinleri: [2, 8]
  pull_direnci: "10 kΩ, pull-down"
  basili_degeri: HIGH
  seri_port_pinleri: [0, 1]
  seri_hiz: 9600
kaynak:
  - "yok (Yol Haritası 'sonsuz döngü 3a') + kendi ak0150 (while) + ak0185 (kara şimşek, dizi)"
---

## 1. Hedef
Kart açıldığında hiçbir şey yapmadan **butona basılana kadar bekleyecek**, sonra
ak0185'teki kara şimşek deseni başlayacak.

## 2. Malzemeler
- Arduino Uno kartı
- USB kablosu
- Paket 5 devresi (4 LED, pin 3/5/6/9)
- ak0210'daki buton (pin 2) ve 10 kΩ direnç

## 3. Parça tanıtımı
Yeni komut yok. `while`'ı ak0150'den, `digitalRead`'i ak0210'dan biliyorsun; burada
ilk kez bir `while`'ın koşulunu bir **buton** kırıyor.

## 4. Devre kurulumu
ak0210'un devresi aynen (Paket 5'in 4 LED'i + pin 2'deki buton, pull-down) — dokunma.

## 5. Kod açıklaması
| kod satırı | açıklama |
| --- | --- |
| `Serial.println("Butona bas...");` | Beklemeden ÖNCE, tek sefer yazılır. |
| `while (digitalRead(butonPin) == LOW)` | "Buton basılı DEĞİLKEN" — koşul doğru olduğu sürece döngü sürer. |
| `{ }` (boş gövde) | "Hiçbir şey yapma, sadece koşulu tekrar tekrar kontrol et." |
| (kara şimşek, `loop()` içinde) | ak0185'ten değişmeden — bekleme bitince bu başlar. |

**ak0155 köprüsü:** `loop()`'un kendisi de hiç bitmeyen bir döngüydü (`while(true)`
gibi). Buradaki `while` FARKLI: koşulu bir gün (buton basılınca) YANLIŞ olur, döngü
biter — "hiç bitmeyen" değil, "biri bitirene kadar süren" bir döngü.

### İleri analiz [ileri]
Boş gövdeli bir `while` (`while (koşul) { }`) tuhaf görünebilir ama geçerlidir:
döngünün TEK işi koşulu tekrar tekrar sormaktır, gövdede yapılacak başka bir iş
yoktur. Kart, buton basılana kadar `setup()`'ın içinde "sıkışmış" gibi durur —
`loop()`'a hiç geçemez, çünkü `setup()` bitmeden `loop()` başlamaz.

## 6. Çalıştır ve gözlemle
Kodu karta yükle. Seri Monitör'ü aç, hızı **9600** seç. "Butona bas..." yazısını
gör, LED'ler hiç hareket etmiyor. Butona bas — kara şimşek başlar ve artık hiç
durmaz (bir sonraki `while` yok, `loop()` sonsuza kadar tekrar eder).

### Sorun giderme
- **"Butona bas..." hiç görünmüyor** → Seri Monitör hızı 9600 değil, ya da kod
  yüklenmemiş.
- **Butona basmadan kara şimşek hemen başlıyor** → Pull-down direnç eksik olabilir,
  pin havada kalıp rastgele `HIGH` okuyor olabilir (ak0210'daki sorunla aynı).
- **Butona bassan da hiçbir şey olmuyor** → `while` koşulu `== LOW` yerine
  yanlışlıkla `== HIGH` yazılmış olabilir (o zaman program başlangıçta hiç
  beklemeden geçer, ya da tam tersi hiç geçmez — hangisi olduğuna bak).
- **Kart açılışında LED'ler bir anlığına yanıp kara şimşek başlamadan duruyor** →
  Normal olabilir, `pinMode` ayarlanırken pinler kısa bir an belirsiz durabilir;
  eğer devam ediyorsa `pinMode` satırlarının `while`'dan ÖNCE olduğundan emin ol.

## 7. Mini sınav
1. [temel] `while (digitalRead(butonPin) == LOW) { }` ne zaman biter?
   - A) 10 saniye sonra
   - B) Buton basılınca (koşul yanlış olunca)
   - C) Hiçbir zaman
   - D) Kart resetlenince
   - ipucu: Koşul "basılı DEĞİLKEN" diyor.

2. [temel] "Butona bas..." yazısı neden `while`'ın İÇİNDE değil, ÖNCESİNDE?
   - A) Fark etmez, ikisi de olur
   - B) İçinde olsa ekranı aynı yazıyla anında doldururdu
   - C) İçinde olsaydı kod derlenmezdi
   - D) Serial.println while içinde çalışmaz
   - ipucu: while saniyede çok kez döner.

3. [temel] Bu dersin devresi nedir?
   - A) Devre yok
   - B) Paket 5 devresi + ak0210'daki buton (pin 2)
   - C) Sadece 1 LED
   - D) 2 buton
   - ipucu: ak0210'un devresi aynen kullanılıyor.

4. [temel] Boş gövdeli `while (koşul) { }` ne yapar?
   - A) Hiçbir şey, kod hatası verir
   - B) Koşulu tekrar tekrar kontrol eder, koşul doğruysa bekler
   - C) Koşulu bir kez kontrol eder
   - D) LED'i yakar
   - ipucu: `{ }` boş bir blok, içinde komut yok.

5. [ileri] `loop()`'un sonsuz döngüsü ile buradaki `while` arasındaki fark ne?
   - A) Hiç fark yok
   - B) loop() hiç bitmez, buradaki while bir gün (buton basılınca) biter
   - C) while daha hızlıdır
   - D) loop() sadece bir kez çalışır
   - ipucu: ak0155'teki "sonsuz döngü" ile karşılaştır.

6. [ileri] Butona basılı tutunca kara şimşeğin başlaması, bırakınca değil — neden
   şu anki aletlerle (while + digitalRead) tam olarak yapılamıyor?
   - A) Yapılabilir, sadece == HIGH yazmak yeter
   - B) Kartın "önce basıldı, sonra bırakıldı" diye bir SIRAYI hatırlaması gerekir; digitalRead sadece o anki durumu okur, geçmişi hatırlamaz
   - C) Pull-down direnç buna izin vermiyor
   - D) while bunu hiç yapamaz
   - ipucu: SEN YAP 2'yi dene, ne olduğunu gözlemle.

## 8. AI Yoldaşı promptları

> **Not:** AI Yoldaşı sana devrenin nasıl kurulacağını söylemez — bu ders ak0210'un
> devresini aynen kullanır. **AI'ın dediği kartında çalışmıyorsa AI yanılmıştır,
> kartın haklıdır.**

- [temel] **Eşleştirme** — "Sen sabırlı bir öğretmensin. Arduino Uno kartımda pin
  2'de pull-down dirençli bir buton, pin 3/5/6/9'da 4 LED var. Kodum setup()
  içinde butona basılana kadar bekliyor, sonra loop()'ta kara şimşek başlıyor.
  while'ın koşulunun nasıl 'bir gün biteceğini' anlamama yardım et. Cevabı
  söyleme; koşulun ne zaman yanlış olacağını buldurcak sorular sor."
- [temel] **Hata giderme** — "Sen bir hata ayıklama koçusun. Arduino Uno kartımda
  pull-down dirençli bir buton var; kartı açtığımda kara şimşek butona basmadan
  hemen başlıyor. Cevabı verme; pull-down direncin bağlı olup olmadığını ve
  while koşulunu kontrol ettirecek sorular sor."
- [ileri] **Kavram derinleştirme** — "Sen ileri seviye bir mentorsun. Arduino Uno
  kartımda digitalRead sadece o anki pin durumunu okuyor. Butona 'basılı tutunca
  başla, bırakınca değil' davranışının neden basit bir == HIGH/== LOW
  değişikliğiyle yapılamadığını anlamama yardım et. Cevabı söyleme, kartın
  'önceki durumu' hatırlaması gerekip gerekmediğini buldurcak sorular sor."
- [temel] **Yanındaki Yetişkine** — "Cevabı söylemeyin. Şu üç şeyi sırayla sorun:
  Kart açılınca ne yazıyor? Butona basmadan kara şimşek başlıyor mu? while'ın
  içinde hangi komutlar var, hangileri yok?"

## 9. SEN YAP
1. "Butona bas..." satırını `while`'ın İÇİNE taşı, tekrar yükle. Seri Monitör'de
   ne oluyor? (Dikkat: ekran çok hızlı dolar — bu yüzden yazı `while`'ın DIŞINDA,
   önce, tek sefer duruyordu.)
2. Dene ve gözlemle: butona BASILI TUTUNCA kara şimşek başlasın, BIRAKINCA değil —
   koşulu (`== LOW` yerine `== HIGH`) değiştirerek bunu yapabilir misin? Kodu
   yükle, karta dokunmadan gözlemle: kara şimşek beklediğin gibi mi başlıyor,
   yoksa AÇILIŞTA hemen mi başlıyor? Neden böyle olduğunu defterine yaz (ipucu:
   kart açılışında buton zaten basılı değil, koşul o an ne diyor?). Bu soruya
   Ünite 3'te (kenar tetikleme) geri döneceğiz.
