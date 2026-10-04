---
ak_no: ak0220
baslik: "if / else: basınca yan, bırakınca sön"
duzey: 0-temel
unite: 2-Buton
kazanimlar:
  - cpp.if-else
  - cpp.digitalread
  - hw.buton-devre
onkosul:
  - cpp.if (ak0160)
  - cpp.digitalread / hw.pull-down (ak0210)
kara_kutu: [void, "Serial ve noktalı yazım"]
merak_kosesi: "atlandı (rotasyonda aktif kutu yok — void/OUTPUT/Serial emekli; OUTPUT ak0210'da açıldı)"
malzeme:
  - Arduino Uno kartı
  - USB kablosu
  - Paket 5 devresi (4 LED, pin 3/5/6/9)
  - 1 buton (pin 2), 1 adet 10 kΩ direnç (pull-down)
board:
  kart: Arduino Uno
  led_pinleri: [3, 5, 6, 9]
  kullanilan_led: 6
  buton_pinleri: [2, 8]
  pull_direnci: "10 kΩ, pull-down"
  basili_degeri: HIGH
  seri_port_pinleri: [0, 1]
  seri_hiz: 9600
kaynak:
  - "..\arsiv\012butonLed\012butonLed.ino"
---

## 1. Hedef
`else` ile "basılıysa yak, DEĞİLSE söndür" kararını tek yerde vereceksin.

## 2. Malzemeler
- Arduino Uno kartı, USB kablosu
- Paket 5 devresi (4 LED, pin 3/5/6/9) — ak0210'daki gibi
- Pin 2'deki buton ve 10 kΩ direnç (pull-down)

## 3. Parça tanıtımı
Yeni parça yok. Yeni komut: **`else`** ("değilse").

## 4. Devre kurulumu
ak0210'un devresi aynen — dokunma.

## 5. Kod açıklaması
| kod satırı | açıklama |
| --- | --- |
| `if (digitalRead(butonPin) == HIGH) { ... }` | Buton basılıysa bu blok çalışır. |
| `else { ... }` | Koşul doğru DEĞİLSE bu blok çalışır. Kart iki bloktan yalnız birini çalıştırır. |

**Zincir:** ak0160'ta `if` yalnız "doğruysa" yolunu biliyordu. ak0210'da LED için bu
yüzden iki ayrı iş yazdık: önce her turda söndür, sonra basılıysa yak. O kod
çalışıyordu ama LED basılıyken de her turda bir anlığına söndürülüyordu — gözle
görünmese bile gerçek. `else` ile "iki ayrı iş" yerine "tek karar" oluyor.

**Ünite 1 boyunca `else`'siz kurduğumuz her şey** (ak0160 tek/çift, ak0190, ak0197)
artık daha kısa ve daha net yazılabilir. `else`'siz yazılmış kod yanlış değildi —
sadece `else`'in ne işe yaradığını görmen için o ana kadar beklettik.

### İleri analiz [ileri]
`else` yalnız en yakın `if`'e aittir. Süslü parantezler (`{ }`) sayesinde hangi bloğun
hangi yola ait olduğu açıktır; parantezsiz yazımda bu açık olmaz, hatalara kapı açar.
Bu yüzden müfredatta `if` ve `else` hep `{ }` ile yazılır.

## 6. Çalıştır ve gözlemle
Kodu yükle. Butona bas — pin 6'daki LED yanar. Bırak — söner. Davranış ak0210 ile
aynı görünür; fark, kararın tek yerde verilmesi. (Titremeyi gözle görebilmen
gerekmiyor; görmüyorsan sorun yok.)

### Sorun giderme
- **LED hiç yanmıyor** → LED'in uzun bacağı pin 6 tarafında mı, direnç takılı mı bak;
  ak0210'da çalışıyorsa kod yüklenmemiş olabilir.
- **LED hep yanıyor** → Pull-down direnç eksik ya da yanlış bacakta; pin havada kalıp
  `HIGH` okuyor olabilir (ak0210 SEN YAP 1).
- **Tam ters: basınca sönüyor, bırakınca yanıyor** → `== HIGH` yerine `== LOW`
  yazılmış olabilir; ya da iki blok yer değiştirmiş.
- **`if` satırının sonuna `;` koydum, LED hep aynı** → `if (...);` if'in gövdesini boş yapar
  (ak0299'un konusu); IDE varsayılan ayarda uyarı vermeyebilir.
- **Kod derlenmiyor, `else` hakkında hata** → `else` yalnız `if`'in kapanış `}`
  parantezinden hemen sonra gelebilir; arada başka bir komut varsa hata verir.
- **Buton hiç tepki vermiyor** → 4 bacaklı butonda bacaklar karışmış olabilir; butonu 90°
  çevir ya da bacakları çapraz köşeden kullan (çapraz köşe her tip butonda çalışır).

## 7. Mini sınav
1. [temel] `else` bloğu ne zaman çalışır?
   - A) Her zaman
   - B) `if`'in koşulu doğru olmadığında
   - C) Koşul doğru olduğunda
   - D) Hiçbir zaman
   - ipucu: "else" = "değilse".

2. [temel] `if`/`else`'de kaç blok çalışır?
   - A) İkisi de
   - B) Hiçbiri
   - C) Yalnız biri
   - D) Rastgele
   - ipucu: "Ya o ya bu."

3. [temel] Buton basılı değilken bizim devremizde hangi blok çalışır?
   - A) `if` bloğu
   - B) `else` bloğu
   - C) İkisi de
   - D) Hiçbiri
   - ipucu: Basılı değilken pin `LOW` okur.

4. [temel] ak0210'un else'siz hâli ile bu dersin hâli arasındaki fark nedir?
   - A) Devre değişti
   - B) İki ayrı iş (söndür, sonra şartlı yak) yerine tek karar var
   - C) Seri port eklendi
   - D) Fark yok, kod aynı
   - ipucu: KAVRAM'daki "eski hâl" yorumuna bak.

5. [ileri] `else` hangi `if`'e aittir?
   - A) En yakın önceki `if`'e
   - B) Dosyadaki ilk `if`'e
   - C) Herhangi birine
   - D) `if` gerekmez
   - ipucu: İleri analize bak.

6. [ileri] Neden `if`/`else`'i hep `{ }` ile yazıyoruz?
   - A) Zorunlu, yoksa derlenmez
   - B) Hangi komutun hangi yola ait olduğu açık kalsın, hata çıkmasın
   - C) Daha hızlı çalışır
   - D) Süslü olsun diye
   - ipucu: Parantezsiz yazımda tek komut dahil olur.

## 8. AI Yoldaşı promptları

> **Not:** AI Yoldaşı sana pin numarası, direnç değeri ya da bağlantı tarifi
> vermez — bunlar yalnız dersten gelir. **AI'ın dediği devrende çalışmıyorsa AI
> yanılmıştır, devren haklıdır.**

- [temel] **Eşleştirme** — "Sen sabırlı bir öğretmensin. Arduino Uno kartımda pin
  6'da 1 LED, pin 2'de 10 kΩ pull-down dirençli 1 buton var; basılı = HIGH
  okunuyor. Kodum `if (digitalRead(butonPin) == HIGH) { LED yak } else { LED söndür }`.
  `else`'in ne zaman çalıştığını anlamama yardım et. Cevabı söyleme; butonun
  basılı ve basılı değil durumlarında hangi bloğun çalıştığını buldurcak sorular sor."
- [temel] **Hata giderme** — "Sen bir hata ayıklama koçusun. Arduino Uno kartımda pin
  2'de pull-down dirençli buton, pin 6'da LED var. LED butona basınca sönüyor,
  bırakınca yanıyor. Cevabı verme; `== HIGH` ve blokların yerini kontrol ettirecek
  sorular sor."
- [ileri] **Kavram derinleştirme** — "Sen ileri seviye bir mentorsun. Arduino Uno
  kartımda `if`/`else` kullanıyorum. Neden bir kararı tek yerde (`else` ile) vermenin
  iki ayrı iş yazmaktan daha sağlam olduğunu anlamama yardım et. Cevabı söyleme,
  iki yazımın farkını buldurcak sorular sor."
- [temel] **Yanındaki Yetişkine** — "Cevabı söylemeyin. Şu üç şeyi sırayla sorun:
  Buton basılıyken hangi blok çalışıyor? Basılı değilken hangisi? `else`'in yazıldığı
  yer `if`'in neresinden sonra?"

## 9. SEN YAP
1. Ünite 1'de `else`'siz kurduğun ak0160'ı (tek sayıları yazdır) `else` ile yeniden
   yaz: tek sayıda "TEK", değilse "CIFT" yazsın. `else` ile kod kısaldı mı, uzadı mı?
2. İki LED kullan (pin 6 ve pin 9): butona basılıyken biri, basılı değilken ötekisi
   yansın. Hangi LED hangi blokta?
3. [ileri] `else`'in içine ikinci bir `if` koyabilir misin? Ne işe yarardı, düşün.
