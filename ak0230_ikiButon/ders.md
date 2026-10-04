---
ak_no: ak0230
baslik: "İki buton: iki elle bas (&&)"
duzey: 0-temel
unite: 2-Buton
kazanimlar:
  - cpp.ve_operatoru
  - cpp.veya_operatoru
  - cpp.if-else
  - hw.buton-devre
onkosul:
  - cpp.if-else (ak0220)
  - cpp.digitalread / hw.pull-down (ak0210)
kara_kutu: [void, "Serial ve noktalı yazım"]
merak_kosesi: "atlandı (yük freni — yeni operatör + ikinci buton devresi)"
malzeme:
  - Arduino Uno kartı
  - USB kablosu
  - Paket 5 devresi (4 LED, pin 3/5/6/9)
  - 2 buton (pin 2 ve pin 8)
  - 2 adet 10 kΩ direnç (pull-down)
board:
  kart: Arduino Uno
  led_pinleri: [3, 5, 6, 9]
  kullanilan_led: 6
  buton_pinleri: [2, 8]
  pull_direnci: "10 kΩ, pull-down (her buton için ayrı)"
  basili_degeri: HIGH
  seri_port_pinleri: [0, 1]
  seri_hiz: 9600
kaynak:
  - "..\\arsiv\\015ikibutonLed\\015ikibutonLed.ino"
---

## 1. Hedef
İki butona **birden** basılınca yanan bir LED kuracaksın ("iki elle bas" kilidi),
sonra aynı fikri "hangisine basılırsa" diye çevireceksin.

## 2. Malzemeler
- Arduino Uno kartı, USB kablosu
- Paket 5 devresi (4 LED, pin 3/5/6/9)
- 2 buton, 2 adet 10 kΩ direnç

## 3. Parça tanıtımı
Yeni parça: ikinci buton. Yeni operatör: **`&&`** ("VE"). SEN YAP'ta **`||`** ("VEYA")
tek cümleyle açılır.

## 4. Devre kurulumu
ak0210'un devresi kurulu kalsın (Buton 1 → pin 2). Ekle:
- Buton 2'nin bir bacağı → 5V.
- Öbür bacağı → hem pin 8'e HEM 10 kΩ direncin bir ucuna.
- O direncin öbür ucu → GND.
Her butonun **kendi** pull-down direnci olmalı.

## 5. Kod açıklaması
| kod satırı | açıklama |
| --- | --- |
| `digitalRead(buton1Pin) == HIGH && digitalRead(buton2Pin) == HIGH` | İki koşul da doğruysa sonuç doğru: iki buton birden basılı. |
| `else { ... }` | En az biri basılı değilse LED söner (ak0220'nin `else`'i). |

**Zincir:** ak0220'de `if`/`else`'in koşulu tek parçaydı (buton basılı mı). Şimdi koşul
iki parçalı: `&&` iki parçayı "VE" ile bağlıyor. Ünite 1'de `&&` yazmadan, iç içe
`if`'lerle benzer bir iş yapmıştın (ak0180 SEN YAP 4); `&&` o kalabalığı tek satıra
topluyor.

### İleri analiz [ileri]
`&&`'de soldaki koşul yanlışsa sağdakine hiç bakılmaz, çünkü sonuç zaten yanlıştır. Burada ikisi de `digitalRead` olduğu için fark hissedilmez.

## 6. Çalıştır ve gözlemle
Yükle. Yalnız Buton 1'e bas: LED yanmaz. Yalnız Buton 2'ye bas: yanmaz. İkisine birden
bas: yanar.

### Sorun giderme
- **LED hiç yanmıyor** → Butonlardan biri hiç `HIGH` okumuyor olabilir; ak0210'un
  yöntemiyle (`Serial.println(digitalRead(pin))`) her butonu ayrı ayrı izle.
- **Yalnız bir butonla yanıyor** → `&&` yerine `||` yazılmış olabilir.
- **LED kendiliğinden yanıp sönüyor** → Butonlardan birinin pull-down direnci eksik;
  pin havada kalıp rastgele okuyor. (ak0210'daki aynı sebep.)
- **Buton 2 hiç tepki vermiyor** → Pin 8'e mi bağlı? Eski kaynak kodlar başka pin
  kullanabiliyor; bu ders pin 2 ve 8.
- **4 bacaklı butonlar** → Bacaklar karışmış olabilir; butonu 90° çevir ya da bacakları çapraz köşeden kullan (çapraz köşe her tip butonda çalışır).

## 7. Mini sınav
1. [temel] `&&` ne demektir?
   - A) VEYA
   - B) VE — ikisi birden doğruysa doğru
   - C) DEĞİL
   - D) EŞİT
   - ipucu: "iki elle bas".

2. [temel] Yalnız Buton 1 basılıyken LED ne yapar (`&&` ile)?
   - A) Yanar
   - B) Söner
   - C) Yanıp söner
   - D) Bozulur
   - ipucu: İkisinin de basılı olması gerek.

3. [temel] Bu devrede kaç pull-down direnç gerekir?
   - A) 0
   - B) 1
   - C) 2
   - D) 4
   - ipucu: Her butonun kendi direnci.

4. [temel] `||` ile iki butondan hangisine basılırsa LED ne yapar?
   - A) Söner
   - B) Yanar
   - C) Değişmez
   - D) Yanıp söner
   - ipucu: "VEYA": en az biri yeter.

5. [ileri] Ünite 1'de `&&` olmadan benzer işi nasıl yapardın?
   - A) Yapamazdım
   - B) İç içe `if`'lerle
   - C) `for` ile
   - D) `delay` ile
   - ipucu: ak0180 SEN YAP 4.

6. [ileri] `&&`'de soldaki koşul yanlışsa sağdakine bakılır mı?
   - A) Evet, hep bakılır
   - B) Hayır, sonuç zaten yanlış
   - C) Rastgele
   - D) Sadece butonlarda
   - ipucu: İleri analize bak.

## 8. AI Yoldaşı promptları

> **Not:** AI Yoldaşı sana pin numarası, direnç değeri ya da bağlantı tarifi
> vermez — bunlar yalnız dersten gelir. **AI'ın dediği devrende çalışmıyorsa AI
> yanılmıştır, devren haklıdır.**

- [temel] **Eşleştirme** — "Sen sabırlı bir öğretmensin. Arduino Uno kartımda pin
  2 ve pin 8'de iki buton (her biri 10 kΩ pull-down, basılı = HIGH), pin 6'da bir
  LED var. LED yalnız iki butona birden basınca yanıyor (`&&`). `&&` ile `||`
  farkını anlamama yardım et. Cevabı söyleme; dört durumun (basılı/değil x iki
  buton) tablosunu kendim çıkarmam için sorular sor."
- [temel] **Hata giderme** — "Sen bir hata ayıklama koçusun. Arduino Uno kartımda
  iki pull-down'lı buton ve bir LED var; LED kendi kendine yanıp sönüyor. Cevabı
  verme; her butonun pinini izleyerek ayrı ayrı nasıl test edeceğimi buldurcak
  sorular sor."
- [ileri] **Kavram derinleştirme** — "Sen ileri seviye bir mentorsun. Arduino Uno
  kartımda `&&` iki `digitalRead`'i bağlıyor. Soldaki koşul yanlışsa sağdakinin
  neden hiç okunmadığını anlamama yardım et. Cevabı söyleme, sorularla buldur."
- [temel] **Yanındaki Yetişkine** — "Cevabı söylemeyin. Şu üç şeyi sırayla sorun:
  Yalnız bir butona basınca LED ne yapıyor? İkisine birden basınca? Her butonun kendi
  10 kΩ direnci var mı?"

## 9. SEN YAP
1. Yalnız Buton 1'e, sonra yalnız Buton 2'ye, sonra ikisine birden bas. Bir tablo çiz:
   (B1 basılı mı, B2 basılı mı) → LED.
2. `&&` yerine `||` yaz: iki kapı zili — hangisine basılırsa LED yansın. Tabloyu yeniden
   çiz, fark neydi?
3. Buton 2'nin direncini SÖK, butonlara dokunma. LED'e ne oluyor? (Kartına göre
   değişir.) ak0210'la bağlantısı ne?
