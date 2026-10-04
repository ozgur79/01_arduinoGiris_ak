---
ak_no: ak0182
baslik: "Yıldız üçgenleri: düz ve ters"
duzey: 0-temel
unite: 1-LED-ve-Seri-Port
kazanimlar:
  - cpp.setup-loop
  - cpp.serial-begin
  - cpp.serial-println
  - cpp.for
  - cpp.arttirma
  - cpp.ic_ice_for
  - cpp.for_degisken_sinir
onkosul:
  - cpp.ic_ice_for (ak0180)
  - cpp.for / cpp.arttirma (ak0130, satir--)
kara_kutu: [void, "Serial ve noktalı yazım"]
merak_kosesi: "atlandı (yük freni — iki desen (düz + ters üçgen) bir arada zaten ağır)"
malzeme:
  - Arduino Uno kartı
  - USB kablosu
board:
  kart: Arduino Uno
  seri_port_pinleri: [0, 1]
  seri_hiz: 9600
kaynak:
  - "kaba müfredat madde 031 (iç içe for iskeleti, üçgen — ASIL hâli; ak0180'de kareye uyarlanmıştı)"
---

## 1. Hedef
İçteki `for`'un sınırını **sabit bir sayı yerine dıştaki döngünün o anki değerine**
bağlayarak ekrana önce düz, sonra ters bir yıldız üçgeni çizeceksin.

## 2. Malzemeler
- Arduino Uno kartı
- USB kablosu

Devre yok — ekran dersi.

## 3. Parça tanıtımı
Yeni parça yok. İç içe `for`'u ak0180'de gördün; burada içteki döngünün üst sınırı
artık sabit değil, dıştaki döngünün sayacına bağlı.

## 4. Devre kurulumu
Devre yok. Arduino Uno'yu USB kablosuyla bilgisayara bağlaman yeterli.

## 5. Kod açıklaması
| kod satırı | açıklama |
| --- | --- |
| `for (int satir = 1; satir <= 5; satir++)` | Düz üçgenin dıştaki döngüsü: 5 satır. |
| `for (int sutun = 1; sutun <= satir; sutun++)` | İçteki döngü: sınır artık **5 değil, `satir`** — satır büyüdükçe sınır da büyür. |
| `for (int satir = 5; satir >= 1; satir--)` | Ters üçgenin dıştaki döngüsü: 5'ten 1'e geri sayar (`satir--`, ak0130'dan tanıdık). |

**ak0180 ile fark:** Orada `sutun <= 5` hep aynı sayıydı — kare bu yüzden her
satırda eşit genişlikteydi. Burada `sutun <= satir` — sınır satıra göre değişiyor,
üçgen bu yüzden oluşuyor. Ters üçgende **içteki sınır değişmedi** (`sutun <= satir`
aynen kaldı), sadece dıştaki döngü yön değiştirdi (artıyor yerine azalıyor).

### İleri analiz [ileri]
Ters üçgeni kurmanın iki yolu var: (1) dıştaki döngüyü geri saydırmak (bu derste
seçilen yol) ya da (2) dıştaki döngüyü aynı bırakıp içteki sınırı `sutun <= 6 - satir`
yapmak (satir=1 iken sınır 5, satir=5 iken sınır 1). İkisi de aynı görüntüyü üretir —
biri "hangi satırdayım"ı geriye, öteki "sınırı" tersine çevirerek aynı sonuca ulaşır.
İkinci yol SEN YAP 2'de.

## 6. Çalıştır ve gözlemle
Kodu karta yükle. Seri Monitör'ü aç, hızı **9600** seç. Önce büyüyen bir üçgen
(1 yıldızdan 5 yıldıza), boş bir satır, sonra küçülen bir üçgen (5 yıldızdan 1
yıldıza) görünür.

### Sorun giderme
- **Hiçbir şey yazmıyor** → Kod yüklenmemiş olabilir; doğru kartı ve portu seçip
  tekrar yükle.
- **Üçgen yerine kare çıkıyor (her satır 5 yıldız)** → İçteki döngünün sınırı
  yanlışlıkla `sutun <= 5` bırakılmış olabilir; `sutun <= satir` olmalı.
- **Ters üçgen görünmüyor, düz üçgen iki kez tekrarlanıyor** → İkinci `for`
  bloğundaki `satir = 5; satir >= 1; satir--` satırı yanlışlıkla `satir = 1;
  satir <= 5; satir++` olarak kopyalanmış olabilir.
- **İki üçgen arasında boşluk yok, birbirine yapışık** → `Serial.println();`
  (parantezi boş) satırı silinmiş olabilir.
- **Ekrandaki yazılar anlamsız karakterlerden oluşuyor** → Seri Monitör hızı 9600
  değil.

## 7. Mini sınav
1. [temel] İçteki döngünün sınırı bu derste neye bağlı?
   - A) Her zaman 5'e
   - B) Dıştaki döngünün o anki değerine (`satir`)
   - C) Rastgele bir sayıya
   - D) Seri hızına
   - ipucu: `sutun <= satir` satırına bak.

2. [temel] Ters üçgende hangi döngü yön değiştirdi?
   - A) İçteki döngü
   - B) Dıştaki döngü
   - C) İkisi de
   - D) Hiçbiri
   - ipucu: `satir--` hangi `for`'un içinde?

3. [temel] Bu dersin devresi nedir?
   - A) Devre yok, sadece kart ve USB
   - B) 1 LED
   - C) 4 LED
   - D) Buton
   - ipucu: Başlıktaki "Devre" satırına bak.

4. [temel] `Serial.println();` (parantezi boş) iki üçgen arasında ne işe yarıyor?
   - A) Hiçbir şey
   - B) Alt satıra inip boş bir satır bırakıyor
   - C) Üçgeni siliyor
   - D) Seri portu kapatıyor
   - ipucu: Bu satır iki `for` bloğunun arasında, tek başına duruyor.

5. [ileri] `sutun <= 6 - satir` ile de aynı ters üçgen çıkar mı?
   - A) Hayır, farklı bir şekil çıkar
   - B) Evet — dıştaki döngü aynı yönde ilerlerken içteki sınır tersten hesaplanır
   - C) Sadece 5 satırda çalışır, başka sayıda çalışmaz
   - D) Kod derlenmez
   - ipucu: satir=1 iken 6-1=5, satir=5 iken 6-5=1 — sınır zaten tersten sayıyor.

6. [ileri] Düz üçgeni 7 satıra çıkarmak için kaç yerde `5` değiştirilmesi gerekir?
   - A) Hiçbiri, kendiliğinden büyür
   - B) Sadece dıştaki döngünün sınırı (`satir <= 5`) — içteki sınır zaten `satir`e bağlı
   - C) Her iki döngünün de sabit sınırı
   - D) `Serial.println()` satırı
   - ipucu: İçteki sınır zaten sabit bir sayı değil, `satir`e bağlı.

## 8. AI Yoldaşı promptları

> **Not:** AI Yoldaşı sana devrenin nasıl kurulacağını söylemez — bu derste zaten
> devre yok. **AI'ın dediği kartında çalışmıyorsa AI yanılmıştır, kartın haklıdır.**

- [temel] **Eşleştirme** — "Sen sabırlı bir öğretmensin. Arduino Uno kartımda seri
  hız 9600, devre yok; kodum iç içe `for` ile düz ve ters yıldız üçgeni çiziyor.
  İçteki döngünün sınırının neden sabit olmadığını anlamama yardım et. Cevabı
  söyleme; her satırda kaç yıldız olduğunu saydıran sorular sor."
- [temel] **Hata giderme** — "Sen bir hata ayıklama koçusun. Arduino Uno kartımda
  seri hız 9600; kodum üçgen yerine kare çiziyor. Cevabı verme; içteki döngünün üst
  sınırının hangi satırda olduğunu kontrol etmemi sağlayan sorular sor."
- [ileri] **Kavram derinleştirme** — "Sen ileri seviye bir mentorsun. Arduino Uno
  kartımda seri hız 9600; ters üçgeni iki farklı yoldan (dıştaki döngüyü geri
  saydırarak ya da içteki sınırı `6 - satir` yaparak) kurmanın neden aynı sonucu
  verdiğini anlamama yardım et. Cevabı söyleme, her iki yoldaki sınır değerlerini
  satır satır saydıran sorular sor."
- [temel] **Yanındaki Yetişkine** — "Cevabı söylemeyin. Şu üç şeyi sırayla sorun:
  Düz üçgende 3. satırda kaç yıldız var? Ters üçgende 3. satırda kaç yıldız var?
  İçteki döngünün üst sınırı hangi değişkene bağlı?"

## 9. SEN YAP
1. Düz üçgeni 7 satıra çıkar (iki for'daki 5'leri de 7 yap).
2. Ters üçgeni FARKLI bir yoldan üret: dıştaki döngüyü geri saydırma (satir 1'den
   5'e ARTSIN), bunun yerine içteki sınırı `sutun <= 6 - satir` yap. İki yol da aynı
   görüntüyü mü veriyor? [ileri]
3. Sayı üçgeni: yıldız yerine satır numarasını yazdır (her satırda "1 2 3..." o
   satırın numarasına kadar sayar).
4. Takılırsan üzülme — zor hâlleri (baklava, içi boş üçgen) `meydanOkuma/`
   klasöründe seni bekliyor, ama önce bu dersi bitir.
