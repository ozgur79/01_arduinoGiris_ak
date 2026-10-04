---
ak_no: ak0310
baslik: "Buton sayacı: sayaç neden kaçıyor?"
duzey: 0-temel
unite: 3-Buton-ve-Seri-Port
kazanimlar:
  - cpp.digitalread
  - cpp.while_bekleme
  - cpp.serial-println
  - cpp.loop_hizi
onkosul:
  - cpp.while_bekleme (ak0215, ak0250)
  - cpp.serial-println (ak0110)
  - cpp.degisken / cpp.arttirma (ak0120, ak0130)
  - hw.buton_sicrama (ak0250)
kara_kutu: [void, "Serial ve noktalı yazım"]
merak_kosesi: "atlandı (rotasyonda aktif kutu yok; ders acı + çare + iki buton sorusu taşıyor)"
malzeme:
  - Arduino Uno kartı
  - USB kablosu
  - Paket 5 devresi (4 LED, pin 3/5/6/9)
  - 2 buton (pin 2 ve pin 8), 2 adet 10 kΩ direnç (pull-down)
board:
  kart: Arduino Uno
  led_pinleri: [3, 5, 6, 9]
  buton_pinleri: [2, 8]
  pull_direnci: "10 kΩ, pull-down (her buton için ayrı)"
  basili_degeri: HIGH
  seri_port_pinleri: [0, 1]
  seri_hiz: 9600
kaynak:
  - "..\\arsiv\\046butonSayac_amator\\046butonSayac_amator.ino"
  - "..\\arsiv\\047butonSayac_pro\\047butonSayac_pro.ino"
---

## 1. Hedef
Bir butona **bir kez** bastığında sayacın neden **bir**, değil çok daha fazla arttığını
görecek ve çaresini kuracaksın.

## 2. Malzemeler
- Arduino Uno kartı, USB kablosu
- Paket 5 devresi ve ak0230'daki iki buton (pin 2 ve pin 8), iki pull-down direnç

## 3. Parça tanıtımı
Yeni parça ve yeni komut yok. Yeni fikir: `loop()`'un hızı.

## 4. Devre kurulumu
ak0230'un devresi aynen — dokunma.

## 5. Kod açıklaması
| kod satırı | açıklama |
| --- | --- |
| `if (digitalRead(butonPin) == HIGH) { sayac++; ... }` | Buton HIGH ise sayacı artır ve ekrana yaz. |
| `Serial.println(sayac);` | Sayacın değerini Seri Monitör'e yazar (ak0110). |

**Zincir:** ak0250'de bir basışı "bırakılana kadar bekle" ile tek bir olaya çevirmiştik,
ama orada LED yakmak bir kez yazılsa da çok kez yazılsa da aynı sonucu veriyordu.
Sayaçta fark büyük: `sayac++` her yazılışta sayıyı değiştirir. Kart butonun basılı
olduğunu her turda görür, `loop()` saniyede çok kez döner, bu yüzden bir basış
çok sayıda tur sürer (kaç tur olduğu kartta ölçülür, ders bir sayı vaat etmez). Çaresi, ak0250'deki gibi, `while`'la butonun bırakılmasını
beklemek.

### İleri analiz [ileri]
Kaç kez sayacağı parmağının basış süresine ve `loop()`'un ne kadar sürede döndüğüne
(`Serial.println` yavaşlatır) bağlıdır; bu yüzden sayı her denemede farklı çıkar.
Ders bir sayı vaat etmiyor.

## 6. Çalıştır ve gözlemle
Kodu yükle, Seri Monitör'ü 9600'de aç, butona bir kez kısa bas. Sayının tek değil çok
arttığını göreceksin. Sonra SEN YAP 2'deki çareyi ekle.

### Sorun giderme
- **Ekranda hiçbir şey yok** → Seri Monitör hızı 9600 mü, kod yüklendi mi?
- **Butona basmadan sayaç kendiliğinden artıyor** → Pull-down direnç eksik, pin havada
  kalıp `HIGH` okuyor (ak0210).
- **Anlamsız karakterler** → Seri Monitör hızı 9600 değil.
- **Çareyi ekledim ama sayaç hâlâ fazla artıyor** → `while` satırı `sayac++`'dan sonra
  mı? Noktalı virgül ile kapatılıp `{ }` unutulmuş olabilir.
- **Bir basışta sayaç bazen 2 artıyor** → Buton sekiyor olabilir (sıçrama, ak0250);
  `delay(20)` eksik ya da kısa olabilir. Ayrıntısı ak0330'da.

## 7. Mini sınav
1. [temel] Bir basışta sayaç neden çok artar?
   - A) Buton bozuk
   - B) `loop()` çok hızlı döner, basış sürdükçe her turda artar
   - C) `Serial` yüzünden
   - D) Sayaç hatalı
   - ipucu: Saniyede kaç tur döndüğünü düşün.

2. [temel] Çare nedir?
   - A) `delay`'i silmek
   - B) Butonun bırakılmasını `while` ile beklemek
   - C) Sayacı silmek
   - D) LED eklemek
   - ipucu: ak0250.

3. [temel] `while (digitalRead(butonPin) == HIGH) { }` ne zaman biter?
   - A) Buton basılınca
   - B) Buton bırakılınca
   - C) 20 ms sonra
   - D) Hiç bitmez
   - ipucu: Koşul "basılıyken" diyor.

4. [temel] Buton 1 `while`'da bekliyorken Buton 2'ye basılırsa?
   - A) Sayılır
   - B) Kart Buton 2'yi okumaz, sayılmaz
   - C) LED yanar
   - D) Kart resetlenir
   - ipucu: Kart `while`'ın içinde.

5. [ileri] Sayaç neden her denemede farklı bir sayıya çıkar?
   - A) Rastgele
   - B) Basış süresi ve `loop()` hızı değişir
   - C) Buton her seferinde farklı
   - D) Bilgisayar yüzünden
   - ipucu: İleri analiz.

6. [ileri] `while` ile beklemek bir sorunu çözüp başka bir sorun çıkarıyor. Hangisi?
   - A) Hiçbiri
   - B) Bekleme sırasında kart başka butonu okuyamaz
   - C) Sayaç taşar
   - D) LED söner
   - ipucu: SEN YAP 3.

## 8. AI Yoldaşı promptları

> **Not:** AI Yoldaşı sana pin numarası, direnç değeri ya da bağlantı tarifi
> vermez — bunlar yalnız dersten gelir. **AI'ın dediği devrende çalışmıyorsa AI
> yanılmıştır, devren haklıdır.**

- [temel] **Eşleştirme** — "Sen sabırlı bir öğretmensin. Arduino Uno kartımda pin
  2'de 10 kΩ pull-down'lı bir buton var, seri hız 9600. Butona bir kez basınca sayaç
  çok fazla artıyor. Nedenini anlamama yardım et. Cevabı söyleme; `loop()`'un bir
  saniyede kaç kez döndüğünü ve butonun o sürede ne yaptığını buldurcak sorular sor."
- [temel] **Hata giderme** — "Sen bir hata ayıklama koçusun. Arduino Uno kartımda iki
  buton (pin 2 ve 8), her biri pull-down'lı. Buton 1'e basılıyken Buton 2 sayılmıyor.
  Cevabı verme; kartın o sırada hangi satırda beklediğini buldurcak sorular sor."
- [ileri] **Kavram derinleştirme** — "Sen ileri seviye bir mentorsun. Arduino Uno
  kartımda `while` ile buton bırakılana kadar bekliyorum. Bu bekleyişin kartı neden
  başka işler için kör yaptığını ve bunun nasıl aşılabileceğini düşünmeme yardım et.
  Cevabı söyleme, sorularla yönlendir."
- [temel] **Yanındaki Yetişkine** — "Cevabı söylemeyin. Şu üç şeyi sırayla sorun:
  Bir kez basınca ekranda ne görüyorsun? `while` eklenince ne değişti? Buton 1
  basılıyken Buton 2'ye basınca ne oluyor?"

## 9. SEN YAP
1. Kodu olduğu gibi yükle, butona bir kez kısa bas. Sayaç kaça çıktı? Neden 1 değil?
2. Çareyi kendin yaz: `sayac++`'dan sonra butonun bırakılmasını `while { }` ile bekle,
   `loop()`'un sonuna `delay(20);` koy. Bir basış artık kaç sayıyor?
3. Pin 8'deki ikinci butona ikinci bir sayaç ekle. Buton 1'i basılı tut, Buton 2'ye
   bas: sayılıyor mu? Neden? (Bir sonraki dersin sorusu.)
4. Sayaç 2 olunca pin 6'daki LED yansın. Üçüncü basışta ne oluyor? Sayacı ve LED'i
   baştan başlatmak için ne gerekir?
