---
ak_no: ak0250
baslik: "İki buton: biri yakar, biri söndürür"
duzey: 0-temel
unite: 2-Buton
kazanimlar:
  - cpp.while_bekleme
  - cpp.digitalread
  - hw.buton-devre
  - hw.buton_sicrama
onkosul:
  - cpp.while_bekleme (ak0215)
  - cpp.ve_operatoru (ak0230, SEN YAP 3 bağlantısı)
  - cpp.digitalread / hw.pull-down (ak0210)
kara_kutu: [void, "Serial ve noktalı yazım"]
merak_kosesi: "atlandı (yük freni — hafıza fikri + bırakılana kadar bekleme + sıçrama birlikte)"
malzeme:
  - Arduino Uno kartı
  - USB kablosu
  - Paket 5 devresi (4 LED, pin 3/5/6/9)
  - 2 buton (pin 2 = YAK, pin 8 = SÖNDÜR)
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
  - "..\\arsiv\\022MaviButonKolay\\022MaviButonKolay.ino"
  - "..\\arsiv\\022MaviButonZor\\022MaviButonZor.ino (yalnız karşılaştırma, #define taşınmadı)"
---

## 1. Hedef
Biri LED'i yakan, biri söndüren **iki buton** kuracaksın. LED bir kez yanınca butonu
bıraksan da yanık kalacak.

## 2. Malzemeler
- Arduino Uno kartı, USB kablosu
- Paket 5 devresi (4 LED, pin 3/5/6/9)
- 2 buton (pin 2 = YAK, pin 8 = SÖNDÜR), 2 adet 10 kΩ direnç (ak0230'daki gibi)

## 3. Parça tanıtımı
Yeni parça yok. Yeni fikir: LED'in durumunu **butonun kendisi değil, LED tutuyor**.

## 4. Devre kurulumu
ak0230'un devresi aynen — dokunma. Buton 1 (pin 2) YAK, Buton 2 (pin 8) SÖNDÜR.

## 5. Kod açıklaması
| kod satırı | açıklama |
| --- | --- |
| `while (digitalRead(yakPin) == HIGH) { }` | Buton BIRAKILANA kadar bekle. |
| `delay(100);` | Buton basılıp bırakılırken kontaklar bir anlığına sekebilir ("sıçrama"); kısa bekleme bu sekmenin geçmesini bekler. |
| `digitalWrite(ledPin, HIGH);` | LED bir kez yakılır; sen `LOW` yazana kadar yanık kalır. |

**Zincir:** ak0215'te `while` butona BASILANA kadar bekletiyordu. Burada tersi:
butona basıldıktan sonra BIRAKILANA kadar bekletiyor. ak0240'ta buton bir olayı
başlatıyordu, olay süresi dolunca bitiyordu; burada LED yakıldıktan sonra süresi yok,
ikinci bir butona basılana kadar yanık kalıyor. Bu, değişkensiz bir "hafıza": durumu
LED'in kendisi tutuyor.

`022MaviButonZor` aynı işi yapan ama `#define` ile yazılmış bir kardeş koddur; o kalıp
`digitalRead`'i bir isme saklıyor, bu derste taşınmadı.

### İleri analiz [ileri]
Sıçrama (bounce): mekanik bir butonun kontakları basıldığı/bırakıldığı anda çok kısa
süre açılıp kapanabilir; kart bunu birkaç ayrı basış sanabilir. `delay(100)` bunu
basitçe aşmanın bir yoludur; daha düzgün yolu Ünite 3'te açılacak.

## 6. Çalıştır ve gözlemle
Yükle. YAK'a bas, bırak: LED yanmalı ve yanık kalmalı. SÖNDÜR'e bas, bırak: sönmeli.

### Sorun giderme
- **LED hiç yanmıyor** → YAK butonunun pin 2'ye, LED'in pin 6'ya bağlı olduğunu kontrol
  et; `digitalRead` değerini `Serial.println` ile izleyebilirsin.
- **LED yanıyor ama hiç sönmüyor** → SÖNDÜR butonu pin 8'de mi? Pull-down direnci var mı?
  Yoksa bu buton hiç `HIGH` okumuyor olabilir.
- **LED kendiliğinden yanıp sönüyor** → Butonlardan birinin pull-down direnci eksik,
  pin havada kalıp rastgele okuyor (ak0210).
- **LED butona basınca değil bırakınca yanıyor** → Bu hata değil: kodda LED `while`'dan
  sonra yakılıyor.
- **Tek basışta LED birkaç kez açılıp kapanıyor gibi** → Sıçrama olabilir; `delay(100)`
  satırı silinmiş mi bak.

## 7. Mini sınav
1. [temel] LED bir kez yanınca neden yanık kalır?
   - A) Buton basılı kaldığı için
   - B) `HIGH` yazıldı, sen `LOW` yazana kadar öyle kalır
   - C) `delay` yüzünden
   - D) Pull-down direnç yüzünden
   - ipucu: Durumu LED tutuyor.

2. [temel] `while (digitalRead(yakPin) == HIGH) { }` ne zaman biter?
   - A) Buton basılınca
   - B) Buton bırakılınca
   - C) 100 ms sonra
   - D) Hiç bitmez
   - ipucu: Koşul "basılıyken" diyor.

3. [temel] SÖNDÜR butonu hangi pinde?
   - A) 2
   - B) 3
   - C) 8
   - D) 6
   - ipucu: `sondurPin` sabiti.

4. [temel] LED butona basınca mı, bırakınca mı yanar?
   - A) Basınca
   - B) Bırakınca
   - C) Rastgele
   - D) Hiçbir zaman
   - ipucu: LED'i yakan satır `while`'dan sonra.

5. [ileri] `delay(100)` ne için konmuş?
   - A) LED'i yavaşlatmak
   - B) Butonun sıçramasının geçmesini beklemek
   - C) Seri portu açmak
   - D) Pili korumak
   - ipucu: İleri analize bak.

6. [ileri] ak0215'teki `while` ile buradaki `while` arasındaki fark nedir?
   - A) Fark yok
   - B) Orada BASILANA kadar, burada BIRAKILANA kadar bekliyor
   - C) Orada LED, burada buton
   - D) Burada `if` yok
   - ipucu: Zincir paragrafı.

## 8. AI Yoldaşı promptları

> **Not:** AI Yoldaşı sana pin numarası, direnç değeri ya da bağlantı tarifi
> vermez — bunlar yalnız dersten gelir. **AI'ın dediği devrende çalışmıyorsa AI
> yanılmıştır, devren haklıdır.**

- [temel] **Eşleştirme** — "Sen sabırlı bir öğretmensin. Arduino Uno kartımda pin
  2 ve pin 8'de iki buton (10 kΩ pull-down, basılı = HIGH), pin 6'da bir LED var.
  YAK butonu LED'i yakıyor ve LED bırakınca da yanık kalıyor. Bunun nedenini anlamama
  yardım et. Cevabı söyleme; LED'in durumunu kimin tuttuğunu buldurcak sorular sor."
- [temel] **Hata giderme** — "Sen bir hata ayıklama koçusun. Arduino Uno kartımda iki
  buton, bir LED var; LED yanıyor ama SÖNDÜR butonu sönmüyor. Cevabı verme; hangi
  butonun hangi pinde olduğunu ve her pinin ne okuduğunu nasıl izleyeceğimi buldurcak
  sorular sor."
- [ileri] **Kavram derinleştirme** — "Sen ileri seviye bir mentorsun. Arduino Uno
  kartımda mekanik bir butonla çalışıyorum. `delay(100)`'ün neden gerekebileceğini
  anlamama yardım et. Cevabı söyleme, bir butonun basılıp bırakılırken fiziksel olarak
  ne yaptığını buldurcak sorular sor."
- [temel] **Yanındaki Yetişkine** — "Cevabı söylemeyin. Şu üç şeyi sırayla sorun:
  YAK'a basınca LED ne zaman yanıyor, basınca mı bırakınca mı? SÖNDÜR'e basınca ne
  oluyor? İki butona birden basınca ne oluyor?"

## 9. SEN YAP
1. YAK'a bas ve bırak: LED bastığın anda mı, bıraktığın anda mı yanıyor? Önce kodu
   okuyup tahmin et, sonra dene.
2. `delay(100)` satırlarını sil, tekrar yükle, butonlara çok hızlı bas-bırak yap. Fark
   görüyor musun? (Görmeyebilirsin — "bu denemede görmedim" diye yaz.)
3. İki butona BİRDEN bas (ak0230'daki gibi). LED ne yapıyor? Kodda hangisi önce
   kontrol ediliyor?
