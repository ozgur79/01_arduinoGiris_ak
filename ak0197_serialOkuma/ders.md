---
ak_no: ak0197
baslik: "Serial.read: klavyeden komutla LED"
duzey: 0-temel
unite: 1-LED-ve-Seri-Port
kazanimlar:
  - cpp.setup-loop
  - cpp.pinmode
  - cpp.digitalwrite
  - cpp.serial-begin
  - cpp.serial_read
  - cpp.char
onkosul:
  - cpp.if (ak0160)
  - hw.coklu-led / Paket 5 devresi (ak0185)
kara_kutu: [void, OUTPUT]
merak_kosesi: "atlandı (yük freni — iki yönlü seri port + char + tek tırnak + iç içe if zaten ağır)"
malzeme:
  - Arduino Uno kartı
  - USB kablosu
  - Paket 5 devresindeki 4 LED'den biri (pin 9)
board:
  kart: Arduino Uno
  seri_port_pinleri: [0, 1]
  seri_hiz: 9600
kaynak:
  - "D:\\ArduinoProjeleri\\002Arduino\\080bluetoothArd\\080bluetoothArd.ino (kopyalandı: ..\\arsiv\\080bluetoothArd\\)"
test_notu: "Seri Monitör 'Yeni satır' modunda gönderilen \\n karakterinin iki if yapısında zararsız olduğu (hiçbir if'e uymuyor) iddiası KARTTA HENÜZ DOĞRULANMADI — Test-Gunlugu.md'de ayrıca işaretli."
---

## 1. Hedef
Seri Monitör'ün üstündeki kutuya bir harf yazıp göndereceksin; kart bu harfi
`Serial.read()` ile okuyup pin 9'daki LED'i yakacak ya da söndürecek.

## 2. Malzemeler
- Arduino Uno kartı
- USB kablosu
- Paket 5 devresindeki 4 LED'den biri (pin 9) — yeni jumper gerekmez

## 3. Parça tanıtımı
`Serial.available()` ve `Serial.read()` yeni: ikisi de seri portun **okuma**
tarafı. Şimdiye kadar kart hep `Serial.println` ile yazıyordu (kartdan
bilgisayara); burada ilk kez bilgisayardan karta bir şey gönderiyoruz.

## 4. Devre kurulumu
ak0185/ak0190/ak0195'in devresi (4 LED, pin 3/5/6/9, ortak GND hattı) kuruluysa
dokunma. Sıfırdan kuruyorsan: 1 LED (+) → pin 9, kısa bacak (−) → 220 ohm direnç →
breadboard'ın ortak GND hattı → TEK jumper ile Arduino GND.

## 5. Kod açıklaması
| kod satırı | açıklama |
| --- | --- |
| `char gelenKarakter;` | Tek bir harf/karakter saklayan bir kutu tanımlar. |
| `if (Serial.available() > 0)` | "Okunmayı bekleyen bir harf var mı?" sorusu — varsa içeri girilir. |
| `gelenKarakter = Serial.read();` | Bekleyen harfi okur, `gelenKarakter`e koyar. |
| `if (gelenKarakter == '1')` | Okunan harf **tam olarak** `'1'` karakteriyse (tek tırnak!) LED'i yak. |
| `if (gelenKarakter == '0')` | Okunan harf `'0'` ise LED'i söndür. |

**Tek tırnak neden önemli:** `'1'` bir `char` — tek bir karakter. `"1"` (çift
tırnaklı) bir **yazı** (String) olurdu; `char` bir yazıyla asla eşit çıkmaz, kod
derlenir ama koşul hep yanlış olur.

**İç içe `if`:** Dıştaki `if (Serial.available() > 0)` önce "okunacak bir şey var
mı" diye sorar. VARSA, içindeki iki `if` hangi harf geldiğine bakar. Bunu ak0180'de
bir `for`'un içine `for` koyarak öğrenmiştin — burada aynı fikir `if` ile: bir
`if`'in gövdesine başka bir `if` konabilir.

### İleri analiz [ileri]
Kaynak kod (`080bluetoothArd.ino`) `while (Serial.available() > 0)` kullanıyordu —
bu, kutuda birden fazla harf varsa hepsini AYNI `loop()` turunda okurdu. Burada
`if` kullanıldı: her `loop()` turunda **en fazla bir** harf okunur, kalanlar
sıradaki turlarda okunur. Sonuç aynı görünür (LED aynı şekilde tepki verir) ama
`while` burada gereksiz bir yeni şey (döngü içinde döngü değil ama "hepsini bir
turda bitir" fikri) taşırdı.

## 6. Çalıştır ve gözlemle
Kodu karta yükle. Seri Monitör'ü aç, hızı **9600** seç. Üstteki kutuya `1` yaz,
Enter'a bas (ya da "Gönder" tuşu) — pin 9'daki LED yanmalı. `0` yaz, gönder —
sönmeli.

### Sorun giderme
- **Hiçbir şey olmuyor** → Seri Monitör'ün alt köşesindeki hızı kontrol et, **9600**
  seçili olmalı.
- **LED hiç tepki vermiyor, ama kod yüklendi** → Kutuya `1` yazdıktan sonra Enter'a
  ya da "Gönder" tuşuna basmayı unutmuş olabilirsin — yazı kutuda kalır, karta
  gönderilmez.
- **`"1"` yazınca çalışmıyor ama `1` yazınca çalışıyor** → Seri Monitör'e sen zaten
  tırnak yazmıyorsun (kutuya sadece `1` yazıyorsun); koddaki `'1'` tek tırnaklı
  `char` karşılaştırmasıdır, bunu değiştirme.
- **LED yanıyor ama sönmüyor (ya da tersi)** → `if (gelenKarakter == '1')` ile
  `if (gelenKarakter == '0')` satırlarının içindeki `HIGH`/`LOW` karışmış olabilir.
- **Kod derlenmiyor, `char` ile ilgili bir hata veriyor** → `'1'` yerine yanlışlıkla
  `"1"` (çift tırnak) yazılmış olabilir.
- **Seri Monitör'ün "Yeni satır" ayarı açıkken bir şey bozuluyor mu?** → Bu KARTTA
  HENÜZ DOĞRULANMADI. Teoride "Yeni satır" gönderilen ekstra `\n` karakteri
  hiçbir `if`'e uymadığı için zararsız olmalı — ama bu iddia test edilene kadar
  "doğrulandı" denmiyor (bkz. `Test-Gunlugu.md`).

## 7. Mini sınav
1. [temel] `Serial.available()` ne sorar?
   - A) LED yanık mı diye
   - B) Okunmayı bekleyen bir harf var mı diye
   - C) Kart açık mı diye
   - D) Seri hızı ne diye
   - ipucu: "available" kelimesinin anlamına bak — "mevcut, hazır".

2. [temel] `'1'` ile `"1"` arasındaki fark nedir?
   - A) Hiç fark yok
   - B) `'1'` tek karakter (char), `"1"` bir yazı (String) — char ile hiç eşleşmez
   - C) `"1"` daha hızlı çalışır
   - D) `'1'` sayı, `"1"` harf
   - ipucu: Tırnak sayısına bak — bir tek, bir çift.

3. [temel] Bu dersin devresi nedir?
   - A) Devre yok
   - B) Paket 5 devresindeki 4 LED'den biri (pin 9)
   - C) Buton
   - D) 8 LED
   - ipucu: Başlıktaki "Devre" satırına bak.

4. [temel] İçteki iki `if` ('1' ve '0' için) hangi `if`'in İÇİNDE duruyor?
   - A) Hiçbirinin, hepsi aynı seviyede
   - B) `if (Serial.available() > 0)`'ın içinde
   - C) `setup()`'ın içinde
   - D) `pinMode`'un içinde
   - ipucu: Süslü parantezlerin nerede açılıp nerede kapandığına bak.

5. [ileri] Kaynak kod `while (Serial.available() > 0)` kullanıyordu, burada
   `if` kullanıldı. Fark ne olurdu?
   - A) Hiç fark olmazdı
   - B) `while` kutudaki tüm harfleri aynı turda okurdu, `if` her turda en fazla bir harf okur
   - C) `while` kodu derlemezdi
   - D) `if` daha hızlı çalışırdı
   - ipucu: `while` "olduğu sürece" tekrar eder, `if` sadece bir kez bakar.

6. [ileri] Kaynakta `'0'` LED'i yakıyor, `'1'` söndürüyordu. Burada neden
   değiştirildi?
   - A) Kaynaktaki kod derlenmiyordu
   - B) İsimle (1 = "aç" sezgisi) uyuşması için, davranışın kendisi değişmedi
   - C) Pin numarası değiştiği için zorunluydu
   - D) `char` böyle gerektiriyor
   - ipucu: "1 yaz, LED yansın" mı daha mantıklı, "1 yaz, LED sönsün" mü?

## 8. AI Yoldaşı promptları

> **Not:** AI Yoldaşı sana devrenin nasıl kurulacağını söylemez — bu ders Paket 5
> devresini (4 LED, pin 3/5/6/9, ortak GND) aynen kullanır. **AI'ın dediği kartında
> çalışmıyorsa AI yanılmıştır, kartın haklıdır.**

- [temel] **Eşleştirme** — "Sen sabırlı bir öğretmensin. Arduino Uno kartımda seri
  hız 9600; devrede pin 9'a bağlı 1 LED var. Kodum Seri Monitör'den okuduğum bir
  harfe göre LED'i yakıp söndürüyor. `Serial.available()` ile `Serial.read()`
  arasındaki farkı anlamama yardım et. Cevabı söyleme; hangisinin 'var mı' diye
  sorduğunu, hangisinin gerçekten okuduğunu buldurcak sorular sor."
- [temel] **Hata giderme** — "Sen bir hata ayıklama koçusun. Arduino Uno kartımda
  seri hız 9600, pin 9'da 1 LED var; `1` gönderdiğimde LED yanmıyor. Cevabı verme;
  Seri Monitör'ün hız ayarını ve 'Gönder' tuşuna basıp basmadığımı kontrol
  ettirecek sorular sor."
- [ileri] **Kavram derinleştirme** — "Sen ileri seviye bir mentorsun. Arduino Uno
  kartımda seri hız 9600; kodum `char` tipinde tek karakter okuyor ve tek tırnaklı
  `'1'` ile karşılaştırıyor. `char` ile `String` arasındaki farkı ve neden
  `"1"` yazsam koşulun hiç doğru olmayacağını anlamama yardım et. Cevabı söyleme,
  tırnak sayısını saydıran sorular sor."
- [temel] **Yanındaki Yetişkine** — "Cevabı söylemeyin. Şu üç şeyi sırayla sorun:
  Seri Monitör'ün hızı kaç? Kutuya `1` yazınca ne oluyor, `0` yazınca ne oluyor?
  Kod içinde `'1'` tek mi çift mi tırnaklı?"

## 9. SEN YAP
1. Seri Monitör'ü aç, hızı 9600 seç. Üstteki kutuya `1` yaz, gönder — pin 9'daki
   LED yanmalı. `0` yaz, gönder — sönmeli.
2. Üçüncü bir `if` ekle: `'2'` gönderilince pin 3'teki LED de yansın (`pinMode`'u
   `setup()`'a eklemeyi unutma).
3. ak0185'teki `ledler` dizisini buraya taşı (`{3, 5, 6, 9}`); `'a'` gönderilince
   dizideki dört LED'in HEPSİ birden yansın (`for` ile, ak0185'teki gibi).

**dk uyarlama notu:** Bu ders Bluetooth donanımı olmadan `Serial.read()`'in kendisini
öğretiyor; dk portunda gerçek bir Bluetooth modülüyle (HC-05 vb.) aynı okuma kalıbı
üzerine kurulabilir — porlama bu turda yapılmıyor, sadece not düşülüyor.
