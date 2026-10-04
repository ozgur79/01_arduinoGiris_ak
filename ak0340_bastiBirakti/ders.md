---
ak_no: ak0340
baslik: "Bastı mı, bıraktı mı: else if"
duzey: 0-temel
unite: 3-Buton-ve-Seri-Port
kazanimlar:
  - cpp.else_if
  - cpp.kenar_tetikleme
  - cpp.if-else
onkosul:
  - cpp.kenar_tetikleme (ak0320)
  - cpp.if-else (ak0220)
  - cpp.ve_operatoru (ak0230)
kara_kutu: [void, "Serial ve noktalı yazım"]
merak_kosesi: "atlandı (rotasyonda aktif kutu yok; ders else if + iki kenar taşıyor)"
malzeme:
  - Arduino Uno kartı
  - USB kablosu
  - Paket 5 devresi (4 LED, pin 3/5/6/9)
  - 1 buton (pin 2), 1 adet 10 kΩ direnç (pull-down)
board:
  kart: Arduino Uno
  led_pinleri: [3, 5, 6, 9]
  kullanilan_led: [3, 9]
  buton_pinleri: [2, 8]
  pull_direnci: "10 kΩ, pull-down"
  basili_degeri: HIGH
  seri_port_pinleri: [0, 1]
  seri_hiz: 9600
kaynak:
  - "..\\arsiv\\030butonBastiBirakti\\030butonBastiBirakti.ino (bayraksız, bool ve ! taşınmadı)"
---

## 1. Hedef
Kartın butonun **basıldığını** ve **bırakıldığını** ayrı ayrı yakalamasını, ekrana ve
LED'lere yazdırmasını sağlayacaksın.

## 2. Malzemeler
- Arduino Uno kartı, USB kablosu
- Paket 5 devresi, pin 2'deki buton ve pull-down direnç

## 3. Parça tanıtımı
Yeni parça yok. Yeni komut: **`else if`**.

## 4. Devre kurulumu
ak0320'nin devresi aynen — dokunma. Basışta pin 3, bırakışta pin 9'daki LED yanacak.

## 5. Kod açıklaması
| kod satırı | açıklama |
| --- | --- |
| `if (durum == HIGH && sonDurum == LOW)` | Yeni basıldı → "BASTI", pin 3 kısa yanar. |
| `else if (durum == LOW && sonDurum == HIGH)` | İlk koşul yanlışsa ve yeni bırakıldıysa → "BIRAKTI", pin 9 kısa yanar. |
| `sonDurum = durum;` | Turun sonunda geçmişi güncelle (ak0320). |

**Zincir:** ak0220'de `else` "başka ne olursa" diyordu. Burada iki kenar var ve ikisi de
özel bir durum: basış ve bırakış. `else` ikisini birden kapsardı, oysa "hiçbiri de
olmayan" turlar (buton olduğu gibi duruyorsa) çoğunluk. `else if` ikinci bir koşul
sorar: ilk koşul yanlışsa ve **şu koşul doğruysa**. İkisi aynı turda birlikte doğru
olamaz; `else if` bunu söylemenin yolu. Kaynak kodda (`030butonBastiBirakti`)
`basildi`/`birakildi` bayrakları vardı; `sonDurum` zaten basış ile bırakışı sıraya
koyduğu için gerekmediğini düşünüp çıkardık (kod okunarak; kartta karşılaştırılacak).

### İleri analiz [ileri]
`else if` zinciri yukarıdan aşağı bakar ve ilk doğru olanda durur. İki ayrı `if`
ise ikisini de sorar. Burada ikisi birlikte doğru olamadığı için sonuç aynıdır; bu
ayrım koşullar örtüştüğünde önem kazanır.

## 6. Çalıştır ve gözlemle
Yükle, Seri Monitör'ü 9600'de aç. Bas: "BASTI" yazar, pin 3 kısa yanar. Bırak: "BIRAKTI"
yazar, pin 9 kısa yanar.

### Sorun giderme
- **Hiçbir şey yazmıyor** → Seri Monitör hızı 9600 mü, kod yüklendi mi?
- **BIRAKTI hiç yazmıyor** → İkinci koşulda `durum == LOW && sonDurum == HIGH` yerine yanlışlıkla `sonDurum == LOW` yazılmış olabilir.
- **Hep BASTI yazıyor, BIRAKTI hiç yok** → İkinci koşuldaki `LOW`/`HIGH` ters
  yazılmış olabilir.
- **LED'ler yanmıyor ama ekranda yazı çıkıyor** → LED bacakları / pin 3 ve pin 9 bağlantısı.
- **Butona basmadan yazılar çıkıyor** → Pull-down eksik, pin havada (ak0210).
- **Bir basışta arka arkaya BASTI/BIRAKTI çıkıyor** → Sıçrama olabilir; ak0330'daki gibi
  `delay`'in eksikliği; çaresi ak0330'da.

## 7. Mini sınav
1. [temel] `else if` ne zaman çalışır?
   - A) Her zaman
   - B) İlk koşul yanlışsa ve kendi koşulu doğruysa
   - C) İlk koşul doğruysa
   - D) Hiç
   - ipucu: "değilse eğer".

2. [temel] Bırakma anında ekranda ne yazar?
   - A) BASTI
   - B) BIRAKTI
   - C) Hiçbir şey
   - D) Sayaç
   - ipucu: Şimdi LOW, az önce HIGH.

3. [temel] Bu derste basışta hangi LED yanar?
   - A) Pin 3
   - B) Pin 5
   - C) Pin 6
   - D) Pin 9
   - ipucu: `basisLed`.

4. [temel] Buton hiç değişmezse (basılı tutulur) ne yazar?
   - A) Sürekli BASTI
   - B) Hiçbir şey
   - C) BIRAKTI
   - D) Sayaç artar
   - ipucu: İki koşul da yanlış.

5. [ileri] `else` ile `else if` arasındaki fark nedir?
   - A) Fark yok
   - B) `else` koşulsuz "başka her şey"; `else if` ikinci bir koşul da ister
   - C) `else if` daha hızlı
   - D) `else` yalnız LED'de çalışır
   - ipucu: KAVRAM.

6. [ileri] İki ayrı `if` ile `else if` burada aynı sonucu verir mi?
   - A) Hayır, hiç vermez
   - B) Evet, çünkü iki koşul aynı turda birlikte doğru olamaz
   - C) Yalnız basılıyken
   - D) Yalnız bırakılırken
   - ipucu: İleri analiz.

## 8. AI Yoldaşı promptları

> **Not:** AI Yoldaşı sana pin numarası, direnç değeri ya da bağlantı tarifi
> vermez — bunlar yalnız dersten gelir. **AI'ın dediği devrende çalışmıyorsa AI
> yanılmıştır, devren haklıdır.**

- [temel] **Eşleştirme** — "Sen sabırlı bir öğretmensin. Arduino Uno kartımda pin 2'de
  10 kΩ pull-down'lı bir buton, pin 3 ve 9'da LED var, seri hız 9600. Kodum butonun
  basıldığını ve bırakıldığını `else if` ile ayırıyor. `else if`'in `else`'ten farkını
  anlamama yardım et. Cevabı söyleme; hangi turlarda hangi bloğun çalıştığını buldurcak
  sorular sor."
- [temel] **Hata giderme** — "Sen bir hata ayıklama koçusun. Arduino Uno kartımda
  butonu bırakınca BIRAKTI yazmıyor. Cevabı verme; ikinci koşuldaki `LOW`/`HIGH`
  değerlerini ve `sonDurum`'un güncellendiği yeri kontrol ettirecek sorular sor."
- [ileri] **Kavram derinleştirme** — "Sen ileri seviye bir mentorsun. Arduino Uno
  kartımda iki kenarı `else if` ile ayırıyorum. İki ayrı `if` ile `else if`'in hangi
  durumda farklı sonuç vereceğini düşünmeme yardım et. Cevabı söyleme, örnek durumlar
  sor."
- [temel] **Yanındaki Yetişkine** — "Cevabı söylemeyin. Şu üç şeyi sırayla sorun:
  Bastığında ne yazıyor? Bıraktığında? Basılı tuttuğunda ne yazıyor?"

## 9. SEN YAP
1. Kısa bas-bırak, sonra basılı tut ve bırak. Ekranda ve LED'lerde sıra ne? Arka arkaya
   iki BASTI gördün mü?
2. `else if` yerine iki ayrı `if` yaz. Sonuç değişti mi? Neden?
3. Basışları ve bırakışları ayrı sayaçlarla say. Hep eşit mi, biri bir fazla olabilir
   mi? Ne zaman?
4. [ileri] "Hiçbir şey olmadı" turunda ne oluyor? Kodda bunu yapan satır var mı?
