---
ak_no: ak0260
baslik: "Refleks oyunu (Ünite 2 kapanış projesi)"
duzey: 0-temel
unite: 2-Buton
kazanimlar:
  - cpp.digitalread
  - cpp.while_bekleme
  - cpp.if-else
  - cpp.ve_operatoru
  - cpp.random
onkosul:
  - cpp.random (ak0165)
  - cpp.while_bekleme (ak0215)
  - cpp.if-else (ak0220)
  - cpp.ve_operatoru (ak0230)
  - cpp.delay_kor (ak0240)
kara_kutu: [void, "Serial ve noktalı yazım"]
merak_kosesi: "atlandı (yük freni — kapanış projesi, yeni kavram yok ama beş alet birlikte)"
malzeme:
  - Arduino Uno kartı
  - USB kablosu
  - Paket 5 devresi (4 LED, pin 3/5/6/9)
  - 2 buton (pin 2 ve pin 8)
  - 2 adet 10 kΩ direnç (pull-down)
board:
  kart: Arduino Uno
  led_pinleri: [3, 5, 6, 9]
  kullanilan_led: [3, 6, 9]
  buton_pinleri: [2, 8]
  pull_direnci: "10 kΩ, pull-down (her buton için ayrı)"
  basili_degeri: HIGH
  seri_port_pinleri: [0, 1]
  seri_hiz: 9600
kaynak:
  - "yok — ak tarafından yazıldı (Ünite 2 kapanış projesi)"
---

## 1. Hedef
İki oyunculu bir **refleks oyunu** kuracaksın: kart rastgele bir süre bekler, sonra
"BAS!" der; ilk basan kazanır.

## 2. Malzemeler
- Arduino Uno kartı, USB kablosu
- Paket 5 devresi (4 LED, pin 3/5/6/9)
- 2 buton, 2 adet 10 kΩ direnç (ak0230'daki gibi)

## 3. Parça tanıtımı
Yeni parça ve yeni komut yok. Bu ders Ünite 2'nin tüm aletlerini ve Ünite 1'den
`random()`'u bir araya getiriyor.

## 4. Devre kurulumu
ak0230'un devresi aynen. Pin 6 = sinyal LED'i ("BAS!"), pin 3 = Oyuncu 1'in LED'i
(Buton 1, pin 2), pin 9 = Oyuncu 2'nin LED'i (Buton 2, pin 8). Pin 5 bu derste yok.

## 5. Kod açıklaması
| kod satırı | açıklama |
| --- | --- |
| `delay(random(2000, 5001));` | 2 ile 5 saniye arası rastgele bekle (üst sınır gelmez, bu yüzden 5001). |
| `digitalWrite(sinyalLed, HIGH);` | "BAS!" sinyali. |
| `while (digitalRead(buton1Pin) == LOW && digitalRead(buton2Pin) == LOW) { }` | İkisi de basmadığı sürece bekle. |
| `if (digitalRead(buton1Pin) == HIGH) ... else ...` | Buton 1 basılıysa Oyuncu 1, değilse Oyuncu 2 kazandı. |

**Zincir:** çekirdek satır iki dersin birleşimi: ak0215'in "basılana kadar bekle"si ve
ak0230'un `&&`'ı. `&&` burada "ikisi de basmadığı sürece" diyor; döngüden çıkan kişi
ilk basan. `random` ak0165'ten, `if`/`else` ak0220'den geliyor.

**Dürüst bir sınır — beraberlik:** iki oyuncu aynı anda basarsa, kodda `if`'te Buton 1
önce kontrol edildiği için Oyuncu 1 kazanır. Oyun bu yüzden tam adil değil.
**Bir başka sınır:** bekleme süresi `delay` ile geçtiği için, kart o sürede butonları
okumuyor (ak0240).

### İleri analiz [ileri]
Erken basanı yakalamak için bekleme **sırasında** butonları okumak gerekir; `delay`
bunu engeller. `millis()` ile beklersen kart aynı anda hem zamanı hem butonları izler
(Ünite 3).

## 6. Çalıştır ve gözlemle
Yükle, Seri Monitör'ü aç (9600). "Hazir olun..." yazar, 2-5 saniye sonra pin 6'daki LED
yanar ve "BAS!" yazar. İlk basan oyuncunun LED'i yanar, kazanan ekrana yazılır. 3 saniye
sonra yeni tur.

### Sorun giderme
- **Hiçbir şey olmuyor** → Seri Monitör hızı 9600 mü? Kod yüklendi mi?
- **Sinyal yanar yanmaz kazanan çıkıyor** → Butonlardan biri hep `HIGH` okuyor olabilir
  (pull-down eksik ya da bacaklar karışık); `Serial.println(digitalRead(pin))` ile izle.
- **Hep Oyuncu 1 kazanıyor** → Buton 1 hep `HIGH` okuyor olabilir; ya da iki oyuncu aynı
  anda basıyordur (beraberlikte Oyuncu 1 kazanır).
- **Oyuncu 2 basıyor ama Oyuncu 1 kazanıyor** → Buton 2'nin pin 8'e ve kendi
  pull-down'ına bağlı olduğunu kontrol et.
- **Sinyal LED'i hiç yanmıyor** → LED pin 6'da mı, yönü doğru mu?

## 7. Mini sınav
1. [temel] "BAS!" öncesi bekleme neden rastgele?
   - A) Kart yavaş
   - B) Oyuncular sinyalin ne zaman geleceğini tahmin edemesin
   - C) LED ısınsın
   - D) Buton hazırlansın
   - ipucu: `random`.

2. [temel] `random(2000, 5001)` hangi sayıları verir?
   - A) 2000-5001
   - B) 2000-5000
   - C) 2001-5000
   - D) Yalnız 5001
   - ipucu: ak0165, üst sınır gelmez.

3. [temel] `while (buton1 LOW && buton2 LOW) { }` ne zaman biter?
   - A) İkisi de basılınca
   - B) Biri bile basılınca
   - C) Hiç bitmez
   - D) 1 saniye sonra
   - ipucu: `&&` ikisinin de doğru olmasını ister.

4. [temel] İki oyuncu tam aynı anda basarsa kim kazanır?
   - A) Oyuncu 2
   - B) Oyuncu 1
   - C) Kimse
   - D) Rastgele
   - ipucu: `if` önce hangisine bakıyor?

5. [ileri] Erken basanı yakalamak neden şu aletlerle zor?
   - A) `if` yetmez
   - B) `delay` sırasında kart butonları okumuyor
   - C) Buton çok hızlı
   - D) Seri port kapalı
   - ipucu: ak0240.

6. [ileri] Döngüden çıkınca neden sadece `if (buton1 HIGH) ... else ...` yetiyor?
   - A) Çünkü `else` hep Oyuncu 2
   - B) Döngü ancak biri basınca bittiği için, Buton 1 basılı değilse Buton 2 basılıdır
   - C) Başka seçenek yok
   - D) Kart rastgele seçer
   - ipucu: `&&` yerine düşün.

## 8. AI Yoldaşı promptları

> **Not:** AI Yoldaşı sana pin numarası, direnç değeri ya da bağlantı tarifi
> vermez — bunlar yalnız dersten gelir. **AI'ın dediği devrende çalışmıyorsa AI
> yanılmıştır, devren haklıdır.**

- [temel] **Eşleştirme** — "Sen sabırlı bir öğretmensin. Arduino Uno kartımda iki
  buton (pin 2 ve pin 8, 10 kΩ pull-down, basılı = HIGH) ve üç LED (pin 3, 6, 9) var.
  Kodum rastgele bekleyip sinyal LED'ini yakıyor, ilk basanı buluyor. `while` satırının
  neden `&&` kullandığını anlamama yardım et. Cevabı söyleme; hangi durumda döngünün
  bitebileceğini buldurcak sorular sor."
- [temel] **Hata giderme** — "Sen bir hata ayıklama koçusun. Arduino Uno kartımda iki
  pull-down'lı buton var; sinyal yanar yanmaz Oyuncu 1 kazanıyor, kimse basmıyor.
  Cevabı verme; her butonun pininin ne okuduğunu nasıl izleyeceğimi buldurcak sorular
  sor."
- [ileri] **Kavram derinleştirme** — "Sen ileri seviye bir mentorsun. Arduino Uno
  kartımda `delay` sırasında butonlar okunmuyor, bu yüzden erken basan yakalanamıyor.
  Bu sorunu nasıl çözebileceğimi düşünmeme yardım et. Cevabı söyleme, sorularla
  yönlendir."
- [temel] **Yanındaki Yetişkine** — "Cevabı söylemeyin. Şu üç şeyi sırayla sorun:
  Sinyal yandığında ekranda ne yazıyor? İlk basan oyuncunun LED'i yanıyor mu? Aynı
  anda basılınca ne oluyor?"

## 9. SEN YAP
1. Yanındaki biriyle (ya da iki elinle) oyna. "BAS!" yanmadan butonu basılı tutarsan ne
   olur? "BAS!" yanmadan KISA basıp bırakırsan kart bunu görür mü? Önce tahmin et,
   sonra dene.
2. Aynı anda basınca Oyuncu 1 kazanıyor — bu adil mi? Kodda adil yapmanın bir yolu var
   mı, düşün.
3. Erken basanı nasıl yakalarsın? Düşün, defterine yaz. (Ünite 3'te geri döneceğiz.)
4. Bekleme süresini 1-3 saniyeye indir.
