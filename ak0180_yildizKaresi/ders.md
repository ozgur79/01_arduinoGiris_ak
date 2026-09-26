---
ak_no: ak0180
baslik: "İç içe for: yıldız karesi"
duzey: 0-temel
unite: 1-LED-ve-Seri-Port
kazanimlar:
  - cpp.setup-loop
  - cpp.serial-begin
  - cpp.serial-println
  - cpp.for
  - cpp.ic_ice_for
onkosul:
  - cpp.for (ak0130)
kara_kutu: [void, "Serial ve noktalı yazım"]
merak_kosesi: "atlandı (yük freni — iç içe for + print/println bilinçli istisnası zaten ağır)"
malzeme:
  - Arduino Uno kartı
  - USB kablosu
board:
  kart: Arduino Uno
  seri_port_pinleri: [0, 1]
  seri_hiz: 9600
kaynak:
  - "kaba müfredat madde 029 (5x5 yıldız, kodu yok, fikir kaynağı)"
  - "kaba müfredat madde 031 (iç içe for iskeleti, üçgen — kareye uyarlandı)"
---

## 1. Hedef
Bir `for`'un **içine** başka bir `for` koyarak ekrana 5x5'lik bir yıldız karesi
çizeceksin. Dıştaki döngü satırları, içteki döngü her satırdaki yıldızları sayar.

## 2. Malzemeler
- Arduino Uno kartı
- USB kablosu

Devre yok — ekran dersi.

## 3. Parça tanıtımı
Yeni parça yok. `for`'u ak0130'dan biliyorsun; burada bir `for`'un içine ikinci bir
`for` koyuyoruz.

## 4. Devre kurulumu
Devre yok. Arduino Uno'yu USB kablosuyla bilgisayara bağlaman yeterli.

## 5. Kod açıklaması
| kod satırı | açıklama |
| --- | --- |
| `for (int satir = 1; satir <= 5; satir++)` | Dıştaki döngü: 5 satır say. |
| `for (int sutun = 1; sutun <= 5; sutun++)` | İçteki döngü: her satırda 5 yıldız say. |
| `Serial.print("* ");` | Yıldızı yazar, **aynı satırda kalır** (satır sonuna geçmez). |
| `Serial.println();` | İçteki döngü bitince (5 yıldız yazılınca) alt satıra iner. |

**Bilinçli istisna — `Serial.println` kuralı burada bilerek bozuluyor:** Paket 1'den
beri hep `Serial.println` kullanıyorduk çünkü her yazının kendi satırında durmasını
istiyorduk. Bu derste tam tersini istiyoruz: 5 yıldızın **aynı satırda** yan yana
durmasını. Bu yüzden yıldızlar için `Serial.print` (satır sonuna geçmeyen), satır
bitince tek bir kez `Serial.println()` (parantezi boş — sadece alt satıra iner)
kullanılıyor. `print`/`println` farkını ak0130'da öğrenmiştin; burada ilk kez gerçek
bir işe yarıyor.

### İleri analiz [ileri]
Dıştaki `for` bir kez ilerlediğinde (bir satır), içteki `for` **baştan sona** çalışır
(5 kez döner). Yani içteki döngü toplamda 5 (dış) × 5 (iç) = 25 kez çalışır — 25 yıldız
yazılır. Dıştaki sayaç (`satir`) kaç satır olduğunu, içteki sayaç (`sutun`) her satırda
kaç yıldız olduğunu sayar; ikisi birbirinden bağımsız iki ayrı kutudur.

## 6. Çalıştır ve gözlemle
Kodu karta yükle. Seri Monitör'ü aç, hızı **9600** seç. Ekranda 5 satır, her satırda
5 yıldız olan bir kare görünür.

### Sorun giderme
- **Hiçbir şey yazmıyor** → Kod yüklenmemiş olabilir; doğru kartı ve portu seçip
  tekrar yükle.
- **Tüm yıldızlar tek satırda, hiç alt satıra geçmiyor** → `Serial.println();` satırı
  yanlışlıkla içteki döngünün İÇİNE yazılmış olabilir; dıştaki döngünün içinde ama
  içteki döngünün DIŞINDA olmalı.
- **Her yıldız kendi satırında, kare yerine tek sütun görünüyor** → `Serial.print`
  yerine yanlışlıkla `Serial.println` kullanılmış olabilir.
- **5x5 yerine farklı boyutta bir kare çıkıyor** → İki `for`'un da üst sınırını (`<= 5`)
  kontrol et.
- **Ekrandaki yazılar anlamsız karakterlerden oluşuyor** → Seri Monitör hızı 9600
  değil.

## 7. Mini sınav
1. [temel] Dıştaki `for` ne sayar?
   - A) Her satırdaki yıldız sayısını
   - B) Kaç satır olacağını
   - C) Hiçbir şey
   - D) Seri hızını
   - ipucu: `satir` değişkeninin adına bak.

2. [temel] `Serial.print("* ")` neden `Serial.println("* ")` değil?
   - A) Yıldızların aynı satırda yan yana durması gerekiyor
   - B) print daha hızlı çalışır
   - C) println sayı yazamaz
   - D) Fark etmez
   - ipucu: Bir satırda 5 yıldız istiyoruz.

3. [temel] `Serial.println();` (parantez boş) satırı ne zaman çalışır?
   - A) Her yıldızdan sonra
   - B) Her satırdaki 5 yıldız bitince
   - C) Hiçbir zaman
   - D) Program başında bir kere
   - ipucu: Hangi döngünün içinde, hangi döngünün dışında olduğuna bak.

4. [temel] Bu dersin devresi nedir?
   - A) Devre yok, sadece kart ve USB
   - B) 1 LED
   - C) 4 LED
   - D) Buton
   - ipucu: Başlıktaki "Devre" satırına bak.

5. [ileri] İçteki `for` toplamda kaç kez çalışır?
   - A) 5 kez
   - B) 10 kez
   - C) 25 kez (5 satır x 5 sütun)
   - D) 1 kez
   - ipucu: Dıştaki döngü bir kez ilerlediğinde içteki baştan sona çalışıyor.

6. [ileri] `Serial.println();` satırı yanlışlıkla içteki döngünün içine taşınsaydı ne
   olurdu?
   - A) Hiçbir şey değişmezdi
   - B) Her yıldızdan sonra alt satıra inilirdi, kare yerine tek sütun yıldız çıkardı
   - C) Kod derlenmezdi
   - D) Kare 2 katı büyük çıkardı
   - ipucu: `println` her çağrıldığında alt satıra iner.

## 8. AI Yoldaşı promptları

> **Not:** AI Yoldaşı sana devrenin nasıl kurulacağını söylemez — bu derste zaten
> devre yok. **AI'ın dediği kartında çalışmıyorsa AI yanılmıştır, kartın haklıdır.**

- [temel] **Eşleştirme** — "Sen sabırlı bir öğretmensin. Arduino Uno kartımda seri hız
  9600, devre yok; kodum iç içe `for` ile 5x5 yıldız karesi çiziyor. Dıştaki ve içteki
  döngünün ne saydığını anlamama yardım et. Cevabı söyleme; her döngünün kaç kez
  çalıştığını saydıran sorular sor."
- [temel] **Hata giderme** — "Sen bir hata ayıklama koçusun. Arduino Uno kartımda seri
  hız 9600; kodum kare yerine tek bir sütun yıldız yazdırıyor. Cevabı verme;
  `Serial.print` ile `Serial.println` satırlarının nerede olduğunu kontrol etmemi
  sağlayan sorular sor."
- [ileri] **Kavram derinleştirme** — "Sen ileri seviye bir mentorsun. Arduino Uno
  kartımda seri hız 9600; iç içe iki `for`'un toplam kaç kez çalıştığını (5x5=25)
  anlamama yardım et. Cevabı söyleme, dıştaki döngünün her turunda içtekinin baştan
  sona kaç kez döndüğünü saydıran sorular sor."
- [temel] **Yanındaki Yetişkine** — "Cevabı söylemeyin. Şu üç şeyi sırayla sorun: Ekranda
  kaç satır var? Her satırda kaç yıldız var? `Serial.print` ile `Serial.println`
  satırları koda nerede duruyor?"

## 9. SEN YAP
1. 5x5 yerine 3x7 bir dikdörtgen çiz (3 satır, 7 sütun).
2. Yıldız yerine sayı yazdır: her satırda "1 2 3 4 5" görünsün.
3. Bir üçgen dene: her satırda bir önceki satırdan bir fazla yıldız olsun. Takılırsan
   üzülme — üçgenlerin devamı `meydanOkuma/` klasöründe, ders değil kart olarak seni
   bekliyor.
4. 5x5 karede TAM OLARAK 3. satır, 4. sütundaki yıldızı "+" yap, geri kalan her yer
   yıldız kalsın. İpucu: iç içe `for`'u nasıl yazdığını hatırla — aynı mantıkla bir
   `if`'in içine başka bir `if` de koyabilirsin. `&&` ya da `else` kullanmadan,
   yalnızca tek koşullu `if`'lerle çöz.
