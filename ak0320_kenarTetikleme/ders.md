---
ak_no: ak0320
baslik: "Kenar tetikleme: az önce nasıldı?"
duzey: 0-temel
unite: 3-Buton-ve-Seri-Port
kazanimlar:
  - cpp.kenar_tetikleme
  - cpp.digitalread
  - cpp.ve_operatoru
  - cpp.karsilastirma
onkosul:
  - cpp.loop_hizi (ak0310)
  - cpp.ve_operatoru (ak0230)
  - cpp.degisken (ak0120)
kara_kutu: [void, "Serial ve noktalı yazım"]
merak_kosesi: "atlandı (rotasyonda aktif kutu yok; ders hafıza fikri + iki sayaç taşıyor)"
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
  - "..\\arsiv\\045butonSayac\\045butonSayac.ino"
  - "..\\arsiv\\023SariButon\\023SariButon.ino (aynı fikir)"
---

## 1. Hedef
Kartın butonun **yeni basıldığı anı** beklemeden yakalamasını sağlayacak, iki butonu
aynı anda sayacaksın.

## 2. Malzemeler
- Arduino Uno kartı, USB kablosu
- Paket 5 devresi ve iki buton (pin 2 ve 8), iki pull-down direnç

## 3. Parça tanıtımı
Yeni parça yok. Yeni fikir: bir değişkende **bir önceki durumu saklamak**.

## 4. Devre kurulumu
ak0230'un devresi aynen — dokunma.

## 5. Kod açıklaması
| kod satırı | açıklama |
| --- | --- |
| `durum1 = digitalRead(buton1Pin);` | Butonun şu anki durumunu oku. |
| `durum1 == HIGH && sonDurum1 == LOW` | Şimdi basılı VE az önce basılı değildi: yeni basıldı. |
| `sonDurum1 = durum1;` | Turun sonunda şimdiki durumu sakla; bir sonraki tur "az önceki" olarak kullanacak. |

**Zincir:** ak0310'da bir basışı bir kez saymak için kartı `while` ile bekletiyorduk;
bekleyen kart öbür butonu göremiyordu. Burada kart hiç beklemiyor: geçmişi bir
değişkene yazıyor, her turda "şimdi" ile "az önce"yi karşılaştırıyor. Basılı tutulan
butonda ikisi de `HIGH`, koşul yanlış, sayılmıyor — bu yüzden bir basış tek sayı.
ak0230'un `&&`'ı burada yeni bir işte: "şimdi" VE "az önce" koşulu.

**Sıçrama notu:** bu derste `delay` yok. Bazı butonlarda bir basış bazen tek yerine
iki sayılabilir; buna sıçrama diyoruz (ak0250'de adını duydun), ak0330'da çaresi var.

### İleri analiz [ileri]
Buna **yükselen kenar** denir (LOW → HIGH). Tersi **düşen kenar**dır (HIGH → LOW). Kart
yalnız o anki değeri okur; geçmişi kendimiz saklarız.

## 6. Çalıştır ve gözlemle
Yükle, Seri Monitör'ü 9600'de aç. Butona bas: sayaç bir artar. Basılı tut: artmaz.

### Sorun giderme
- **Hiçbir şey yazmıyor** → Seri Monitör hızı 9600 mü, kod yüklendi mi?
- **Butona basmadan sayaç artıyor** → Pull-down eksik, pin havada kalıyor (ak0210).
- **Buton 2 hiç sayılmıyor** → Pin 8'e ve kendi pull-down'ına bağlı mı?
- **Bir basışta bazen 2 artıyor** → Sıçrama olabilir, hata değil; ak0330'da çözülüyor.
- **`sonDurum = durum;` satırını `if`'in İÇİNE koydum, sayaç tuhaf davranıyor** → O zaman
  geçmiş yalnızca basış anında güncellenir, bırakılınca güncellenmez; sıradaki basış
  kaçabilir ya da sayı kayar. Satır `loop()`'un SONUNDA, `if`'lerin dışında durmalı.
- **Basılı tutunca sayaç artıyor** → `sonDurum` satırı `loop()`'un SONUNDA mı? Başta
  ya da yanlış yerdeyse geçmiş hiç güncellenmez.

## 7. Mini sınav
1. [temel] `sonDurum` ne tutar?
   - A) Sayacı
   - B) Butonun bir önceki turdaki durumunu
   - C) LED'in pinini
   - D) Seri hızı
   - ipucu: "son" = az önceki.

2. [temel] Butona basılı tutulunca neden sayılmaz?
   - A) Kart basılıyken uyur
   - B) Şimdi de az önce de HIGH, "yeni basıldı" koşulu yanlış
   - C) Seri port kapanır
   - D) `delay` yüzünden
   - ipucu: Koşul `sonDurum == LOW` ister.

3. [temel] `sonDurum1 = durum1;` satırı nerede olmalı?
   - A) `loop()`'un başında
   - B) `loop()`'un sonunda
   - C) `setup()`'ta
   - D) Hiçbir yerde
   - ipucu: Önce karşılaştır, sonra sakla.

4. [temel] Bu derste kart butonu beklerken donuyor mu?
   - A) Evet, `while` ile
   - B) Hayır, beklemeden her turda okuyor
   - C) Evet, `delay` ile
   - D) Bazen
   - ipucu: ak0310 ile karşılaştır.

5. [ileri] Düşen kenar koşulu nedir?
   - A) Şimdi HIGH, az önce LOW
   - B) Şimdi LOW, az önce HIGH
   - C) İkisi de HIGH
   - D) İkisi de LOW
   - ipucu: Bırakıldı = HIGH'dan LOW'a.

6. [ileri] `durum1 != sonDurum1` hangi anları yakalar?
   - A) Yalnız basılmayı
   - B) Yalnız bırakılmayı
   - C) Hem basılmayı hem bırakılmayı
   - D) Hiçbirini
   - ipucu: "eşit değil" = değişti.

## 8. AI Yoldaşı promptları

> **Not:** AI Yoldaşı sana pin numarası, direnç değeri ya da bağlantı tarifi
> vermez — bunlar yalnız dersten gelir. **AI'ın dediği devrende çalışmıyorsa AI
> yanılmıştır, devren haklıdır.**

- [temel] **Eşleştirme** — "Sen sabırlı bir öğretmensin. Arduino Uno kartımda pin 2
  ve 8'de iki buton (10 kΩ pull-down, basılı = HIGH) var. Kodum her turda butonu okuyup
  bir önceki turla karşılaştırıyor. Bu yöntemin neden basılı tutulan butonu tekrar
  saymadığını anlamama yardım et. Cevabı söyleme; iki durumu (şimdi/az önce) tablo
  yapmam için sorular sor."
- [temel] **Hata giderme** — "Sen bir hata ayıklama koçusun. Arduino Uno kartımda
  kenar tetikleme kodum var; butonu basılı tutunca sayaç artıyor. Cevabı verme;
  `sonDurum` güncellemesinin yerini kontrol ettirecek sorular sor."
- [ileri] **Kavram derinleştirme** — "Sen ileri seviye bir mentorsun. Arduino Uno
  kartımda yükselen ve düşen kenarı yakalıyorum. Hangisinin hangi durumda işe
  yaradığını düşünmeme yardım et. Cevabı söyleme, örnek durumlar sor."
- [temel] **Yanındaki Yetişkine** — "Cevabı söylemeyin. Şu üç şeyi sırayla sorun:
  Butona basınca sayaç kaç artıyor? Basılı tutunca? Bir buton basılıyken öbürüne
  basınca sayılıyor mu?"

## 9. SEN YAP
1. Buton 1'i BASILI TUT, Buton 2'ye art arda bas. Sayılıyor mu? ak0310'la karşılaştır.
2. Bir basışta sayaç bazen 2 artıyor mu? Çok kez bas, say. (Artıyorsa bir sonraki dersin
   konusu.)
3. Buton 1 BIRAKILDIĞINDA ekrana "birakildi" yazdır (şimdi LOW, az önce HIGH).
4. `&&`'li koşul yerine `durum1 != sonDurum1` ile dene. Ne fark var?
