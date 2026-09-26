---
ak_no: ak0165
baslik: "Rastgele kara şimşek: random()"
duzey: 0-temel
unite: 1-LED-ve-Seri-Port
kazanimlar:
  - cpp.setup-loop
  - cpp.delay
  - cpp.pinmode
  - cpp.digitalwrite
  - cpp.serial-begin
  - cpp.serial-println
  - cpp.const-int
  - cpp.for
  - cpp.random
onkosul:
  - cpp.for (ak0130), const int/çoklu çıkış (ak0060/ak0140)
kara_kutu: [void, OUTPUT, "Serial ve noktalı yazım"]
merak_kosesi: "randomSeed / analogRead (ek kutu — analog giriş dersine kadar açılmaz)"
malzeme:
  - Arduino Uno kartı
  - USB kablosu
  - 4 LED
  - 4 adet 220 ohm direnç
  - breadboard
  - 8 jumper kablo
board:
  kart: Arduino Uno
  led_pinleri: [8, 9, 10, 11]
  seri_port_pinleri: [0, 1]
  seri_hiz: 9600
  mantik_gerilimi: 5V
  direnc: 220 ohm
kaynak:
  - "kaba müfredat madde 025 (kodu yok, fikir kaynağı: 1-100 arası rastgele 10 sayı)"
  - ak0140_karaSimsekFor/ak0140_karaSimsekFor.ino (devre)
---

## 1. Hedef
Kartın senin yerine bir sayı "seçmesini" sağlayacaksın — önce ekranda zar atarak, sonra
aynı yeteneği kullanıp ak0140'ın dört LED'inden rastgele birini yakarak.

## 2. Malzemeler
- Arduino Uno kartı
- USB kablosu
- 4 LED
- 4 adet 220 ohm direnç
- Breadboard
- 8 jumper kablo

## 3. Parça tanıtımı
Yeni parça yok. ak0140'taki 4 LED'lik devre aynen kullanılır.

## 4. Devre kurulumu
ak0140 ile birebir aynı:
1. 4 LED'i breadboard'a soldan sağa, yan yana tak.
2. 1. LED'in uzun bacağını (+) pin 8'e, 2.'yi pin 9'a, 3.'yü pin 10'a, 4.'yü pin 11'e
   bağla.
3. Her LED'in kısa bacağını (−) kendi 220 ohm direncine bağla, direncin boş ucunu
   GND'ye bağla.
4. Arduino Uno'yu USB kablosuyla bilgisayara bağla.

## 5. Kod açıklaması
| kod satırı | açıklama |
| --- | --- |
| `delay(2500);` | Kod yüklenir yüklenmez çalışmaya başlar; bu bekleme sana Seri Monitör'ü açman için birkaç saniye tanır. Açmadan önce yazılan satırlar kaybolur. |
| `random(1, 7)` | 1'den 6'ya rastgele bir sayı üretir. **7 hiç gelmez** — üst sınır dahil değildir. |
| `for (int atis = 1; atis <= 5; atis++)` | Zarı 5 kez atmak için. |
| `random(ilkLed, sonLed + 1)` | 8'den 11'e rastgele bir pin seçer (`sonLed + 1` = 12, o da hiç gelmez). |
| `digitalWrite(secilenPin, HIGH); delay(1500); digitalWrite(secilenPin, LOW); delay(200);` | Seçilen pindeki LED'i yakar, 1500 ms yanık bırakır (göz hangi pin olduğunu rahatça seçebilsin), söndürür, sonra 200 ms karanlık bırakır (bir sonraki LED'den ayrı görünsün). |
| `Serial.print("Zar: ");` / `Serial.print("LED: ");` | Yazının önüne hangi bölümde olduğumuzu söyleyen bir etiket koyar — öğrenci "5" yazısının zar mı, LED pini mi olduğunu karıştırmasın. |
| `Serial.println(secilenPin);` | Hangi pinin seçildiğini ekrana yazar (etiketten hemen sonra, aynı satırda). |

### İleri analiz [ileri]
`random(alt, ust)` matematikteki kapalı-açık aralığa benzer: `[alt, ust)`. Bu yüzden
zar için `random(1, 7)` yazılır (1..6 gelsin istiyoruz), pin için
`random(ilkLed, sonLed + 1)` yazılır (`sonLed`'in kendisi de gelsin istiyoruz, bu
yüzden üst sınıra 1 eklenir). Bu, ak0130'daki `for (sayac <= 10)` ile `for (sayac < 10)`
farkına benzer bir dikkat noktasıdır — sınırın dahil olup olmadığını her zaman kontrol
et.

## 6. Çalıştır ve gözlemle
Devreyi kur, kodu karta yükle, **hemen ardından Seri Monitör'ü aç** (hızı **9600**
seç) — kod yüklenir yüklenmez çalışmaya başlar, sana birkaç saniyelik bir pay
bırakılmıştır. Önce "Zar: " etiketiyle 5 zar atışı (1-6 arası sayılar) görünür, sonra
dört LED'den rastgele biri sırayla yanıp söner (yanık 1500 ms, arada kısa bir karanlık
an); her seferinde "LED: " etiketiyle hangi pinin seçildiği ekrana yazılır.

### Sorun giderme
- **Hiçbir LED yanmıyor** → Kod yüklenmemiş olabilir; doğru kartı ve portu seçip
  tekrar yükle.
- **Yalnız bir LED yanmıyor** → O LED ters takılmış olabilir; uzun bacağın pine, kısa
  bacağın kendi direncine gittiğini kontrol et.
- **Zar atışları hiç görünmüyor, doğrudan LED yanıp sönmeye geçiyor** → Seri
  Monitör'ü kodu yükledikten hemen sonra açmadıysan zar atışları (yalnızca birkaç
  saniye sürer) sen açmadan önce yazılıp geçmiş olabilir. Kartı resetle (üzerindeki
  reset düğmesi) ve Seri Monitör açıkken bekle.
- **LED'lerin hangisinin yandığını seçemiyorum, değişimler çok hızlı** → `delay(1500)`
  ve `delay(200)` satırlarının silinmediğinden emin ol; SEN YAP 1'i henüz yapmadıysan
  bu normal değildir.
- **Zar atışlarında 7 görünüyor** → `random(1, 7)` satırı değiştirilmiş olabilir; üst
  sınırın hiç gelmemesi gerekir.
- **Ekrandaki sayılar Seri Monitör'de anlamsız karakterlerden oluşuyor** → Seri
  Monitör hızı 9600 değil.
- **Kartı resetleyince zarlar hep aynı sırayla geliyor** → Bu bir hata değil, beklenen
  davranış — Merak Köşesi'nde sebebi anlatılıyor.

## 7. Mini sınav
1. [temel] `random(1, 7)` hangi sayıları üretebilir?
   - A) 1, 2, 3, 4, 5, 6, 7
   - B) 1, 2, 3, 4, 5, 6
   - C) 0, 1, 2, 3, 4, 5, 6
   - D) Sadece 7
   - ipucu: Üst sınır dahil değildir.

2. [temel] Bu derste hangi LED yanar?
   - A) Her zaman pin 8
   - B) Sırayla hepsi
   - C) Rastgele seçilen biri
   - D) Hiçbiri
   - ipucu: `random(ilkLed, sonLed + 1)` satırına bak.

3. [temel] Aynı LED art arda iki kez seçilirse bu ne anlama gelir?
   - A) Kod hatalı
   - B) Rastgelelik zaten böyle çalışır, hata değil
   - C) Devre bozuk
   - D) LED yanmaz
   - ipucu: KAVRAM'daki notu hatırla.

4. [temel] Bu dersin devresi hangi eski dersle aynıdır?
   - A) Trafik lambası
   - B) Kara şimşek, for ile (ak0140)
   - C) İki LED
   - D) Harici LED
   - ipucu: 4 LED, pin 8-11.

5. [ileri] `random(ilkLed, sonLed + 1)` satırında neden `sonLed`'e 1 eklenir?
   - A) Yazım hatası
   - B) Üst sınır dahil olmadığı için, 11'in de gelmesini sağlamak için
   - C) Pin sayısını ikiye katlamak için
   - D) LED'leri daha hızlı yakmak için
   - ipucu: `random` üst sınırı hiç üretmez.

6. [ileri] Kartı resetleyip zarları tekrar okuyunca neden hep aynı sıra gelir?
   - A) Kart bozuk
   - B) Kart aslında önceden hazırlanmış bir listeden sırayla okuyor, liste her zaman
     aynı yerden başlıyor
   - C) `random` fonksiyonu yalnız bir kere çalışır
   - D) Seri Monitör hızı yanlış
   - ipucu: Merak Köşesi'ni oku.

## 8. AI Yoldaşı promptları

> **Not:** AI Yoldaşı sana devrenin nasıl kurulacağını, hangi pine bağlayacağını ya da
> hangi direnci kullanacağını söylemez — bunlar sadece derste yazar. **AI'ın dediği
> devrende çalışmıyorsa AI yanılmıştır, devren haklıdır.**

- [temel] **Eşleştirme** — "Sen sabırlı bir öğretmensin. Arduino Uno kartında 5V mantık
  gerilimiyle çalışan rastgele kara şimşek devremde 4 LED pin 8-11'de, seri hız 9600.
  `random(1, 7)` neden hiçbir zaman 7 üretmez, anlamama yardım et. Pin veya bağlantı
  tarifi verme, cevabı söyleme; birkaç atışın sonucunu sayıp sınırı bulduran sorular
  sor."
- [temel] **Hata giderme** — "Sen bir hata ayıklama koçusun. Arduino Uno kartında 5V
  mantık gerilimiyle çalışan rastgele kara şimşek devremde 4 LED pin 8-11'de. Bazen
  hiçbir LED yanmıyor gibi görünüyor. Pin veya bağlantı tarifi verme; `random`'ın
  ürettiği sayı ile `digitalWrite`'a giden pin numarasının eşleşip eşleşmediğini
  kontrol etmemi sağlayan sorular sor."
- [ileri] **Kavram derinleştirme** — "Sen ileri seviye bir mentorsun. Arduino Uno
  kartımda seri hız 9600; kartın rastgele sayı üretirken neden her resette aynı
  sırayı verdiğini anlamama yardım et. Cevabı söyleme (henüz analogRead öğrenmedim),
  sadece 'kart bu sayıları nereden alıyor olabilir?' sorusunu düşündürecek sorular sor."
- [temel] **Yanındaki Yetişkine** — "Cevabı söylemeyin. Şu üç şeyi sırayla sorun: Zar
  atışlarında 7 hiç geldi mi? Hangi LED'in yanacağını önceden tahmin edebiliyor mu?
  Kartı resetleyince sıra değişti mi, değişmedi mi?"

## 9. SEN YAP
1. `loop()` içindeki `delay(1500)` yerine `random(100, 500)` kullan — her seferinde
   farklı bir bekleme süresi olsun.
2. `setup()` içindeki zar atma döngüsünü değiştir: 1'den 100'e kadar rastgele 10 sayı
   yazdır (`random(1, 101)`).
3. Kartı yükledikten sonra RESETLE ve zarları tekrar oku. Aynı sırayla mı geldiler?
   Not al.
4. **Soru:** Zarlar neden her resette AYNI sırayla geliyor? Kartın "rastgele" bir sayı
   seçtiğini düşünüyorsan bu şaşırtıcı olmalı. Önce kendi tahminini yaz, sonra Merak
   Köşesi'ni oku ve tahminini karşılaştır.
