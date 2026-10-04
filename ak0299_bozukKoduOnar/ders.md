---
ak_no: ak0299
baslik: "Bozuk kodu onar (Ünite 2 kapanışı)"
duzey: 0-temel
unite: 2-Buton
kazanimlar:
  - cpp.hata_ayiklama_seri
  - cpp.esit_esit_atama
onkosul:
  - cpp.hata_ayiklama_seri (ak0199)
  - cpp.digitalread / hw.pull-down (ak0210)
  - cpp.if-else (ak0220)
kara_kutu: [void, "Serial ve noktalı yazım"]
merak_kosesi: "atlandı (yük freni — ünite kapanışı, üç ayrı hata + yöntem zaten ağır)"
malzeme:
  - Arduino Uno kartı
  - USB kablosu
  - ak0210'un devresi (pin 2'de buton + 10 kΩ pull-down, pin 6'da LED)
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
  - "yok — bu ders ak tarafından baştan yazıldı (kasıtlı hatalı kod)"
klasor_notu: "Arduino IDE tek klasörde tek .ino ister ve dosya adı klasör adıyla eşleşmek zorunda. Üç bozuk kod aynı anda ayrı ayrı açılabilsin diye her biri kendi alt klasöründe, kendi adını taşıyan bir .ino olarak duruyor (bozuk1_noktaliVirgul/, bozuk2_esitEsit/, bozuk3_yanlisMod/) — tek ortak ders.md üçünü de anlatıyor."
secim_notu: "İş emrinin aday listesinden 1 (if sonunda ;), 2 (= ile == karışması) ve 3 (LED pini INPUT) seçildi; üçünün teşhis yolu birbirinden farklı. Aday 4 (pull-down eksik, hata devrede) bu derse alınmadı: ak0210 SEN YAP 1 bunu zaten öğretiyor ve Özgür'ün devreyi bilerek bozmasını gerektiriyor."
---

## 1. Hedef
Üç ayrı kod **derleniyor** ama **yanlış çalışıyor**. Görevin, tahmin etmeden,
`Serial.println` ile kontrol ederek hatayı bulmak ve düzeltmek. Bu sefer üç hata
**birbirine benzemiyor**: her birinin kendi teşhis yolu var.

## 2. Malzemeler
- Arduino Uno kartı, USB kablosu
- ak0210'un devresi (pin 2'de buton + 10 kΩ pull-down, pin 6'da LED) — üç kod da bu
  devreyi aynen kullanır, hiçbir şey sökülmez.

## 3. Parça tanıtımı
Yeni komut yok. Bu ders Ünite 2'nin aletlerini (`digitalRead`, `if`/`else`, `pinMode`)
**hata bulmak için** kullanıyor.

**Klasör düzeni notu:** Arduino IDE bir klasörde tek `.ino` ister ve dosya adı klasör
adıyla eşleşmek zorunda. Üç bozuk kod ayrı ayrı açılabilsin diye alt klasörlerde:
- `bozuk1_noktaliVirgul/bozuk1_noktaliVirgul.ino`
- `bozuk2_esitEsit/bozuk2_esitEsit.ino`
- `bozuk3_yanlisMod/bozuk3_yanlisMod.ino`

Üçünde de `Serial.begin(9600);` zaten `setup()`'ta var; `Serial.println` satırlarını sen
ekleyeceksin.

## 4. Devre kurulumu
ak0210'un devresi (pin 2'de buton + pull-down, pin 6'da LED) kuruluysa dokunma.

## 5. Kod açıklaması

**Yöntem ak0199'daki gibi, ama üç ayrı teşhis yoluyla:**
1. Kodun **beklendiği gibi çalışmadığı** yeri gözlemle.
2. Bir yere `Serial.println(...)` koy.
3. Ekrandakini **beklediğinle** karşılaştır — fark hatanın yeridir.

| dosya | ne bekleniyor | ne oluyor | teşhis yolu |
| --- | --- | --- | --- |
| `bozuk1_noktaliVirgul` | butona basınca LED 2 saniye yansın | buton fark etmeksizin LED yanıp sönüyor | `digitalRead`'i yazdır: buton doğru okunuyor, demek ki karar satırı yanlış |
| `bozuk2_esitEsit` | basılıyken LED yansın | LED hep yanık | `digitalRead` ile değişkeni yan yana yazdır: ikisi aynı değil |
| `bozuk3_yanlisMod` | basılıyken LED yansın | LED yanmıyor (ya da çok soluk) | `if`'in içine bir mesaj yazdır: mesaj çıkıyor ama LED yanmıyor, sorun kararda değil, pinin görevinde |

### İleri analiz [ileri]
Üçü de Arduino IDE'nin derleme hatası vermediği hatalar. `;` boş bir komuttur, `=`
geçerli bir atama ifadesidir, `INPUT` geçerli bir pin modudur — söz dizimi açısından
hepsi doğru. Hata **anlamda**: senin yazdığın ile kartın anladığı farklı.

## 6. Çalıştır ve gözlemle
Üç klasörü sırayla Arduino IDE ile aç, karta yükle, gözlemle, hatayı bul.

### Sorun giderme
- **Hangi satıra `Serial.println` koyacağımı bilmiyorum** → "Ne oluyor" sütunundaki
  gözlemden başla: LED neden hep yanık/yanmıyor? Önce butonun ne okuduğuna bak.
- **`Serial.println` ekledim ama hiçbir şey görünmüyor** → Seri Monitör hızı 9600 mü?
  Kod yüklendi mi?
- **Ekranda hep 0 (ya da hep 1) görüyorum, buton fark etmiyor** → Bozuk kodu değil
  devreni kontrol et: pull-down direnç ve buton bacakları (ak0210'un Sorun giderme'si).
- **Onardım ama LED hâlâ yanlış** → Yalnız bir satırı değiştirdin mi? Bu üç hatanın her
  biri tek bir karakter ya da tek bir kelimedir.
- **Kod derleniyor mu?** → Üçü de derlenir. "Derlendi" = "doğru" demek değil. `if (...);`
  ve `=`/`==` karışması için Arduino IDE varsayılan ayarda uyarı vermeyebilir; uyarı
  görmemek kodun doğru olduğunu göstermez. (Preferences'ta derleyici uyarıları açılırsa
  bazı kurulumlarda görünebilir; hangi ayarla göründüğü bu atölyede henüz denenmedi.)

## 7. Mini sınav
1. [temel] `if (x == HIGH);` satırındaki `;` ne yapar?
   - A) Hiçbir şey
   - B) if'in gövdesini boş yapar, altındaki blok her zaman çalışır
   - C) if'i hızlandırır
   - D) Derleme hatası verir
   - ipucu: bozuk1.

2. [temel] `=` ile `==` arasındaki fark nedir?
   - A) Fark yok
   - B) `=` atama yapar, `==` karşılaştırır
   - C) `==` atama yapar
   - D) İkisi de karşılaştırır
   - ipucu: bozuk2.

3. [temel] `pinMode(ledPin, INPUT)` ile LED neden yanmaz?
   - A) LED bozuk
   - B) Pin çıkış değil, giriş olarak ayarlanmış
   - C) Direnç yok
   - D) Seri port açık
   - ipucu: bozuk3.

4. [temel] Hatayı bulma yönteminin ilk adımı nedir?
   - A) Kodu baştan yazmak
   - B) Ne olduğunu gözlemlemek
   - C) Kartı resetlemek
   - D) Butonu değiştirmek
   - ipucu: ak0199'daki üç adım.

5. [ileri] Bu üç hata neden Arduino IDE'de derleme hatası olarak görünmez?
   - A) IDE eski
   - B) Üçü de söz dizimi olarak geçerli, hata anlamda
   - C) IDE hepsini düzeltir
   - D) Bunlar hata değil
   - ipucu: İleri analiz.

6. [ileri] `if (butonDurum = HIGH)` yazınca `butonDurum`'a ne olur?
   - A) Hiçbir şey
   - B) Butonun gerçek değeri ne olursa olsun `HIGH` olur
   - C) `LOW` olur
   - D) Kart hata verir
   - ipucu: bozuk2 teşhis paragrafı.

## 8. AI Yoldaşı promptları

> **Not:** AI Yoldaşı sana hatanın nerede olduğunu SÖYLEMEZ; pin numarası, direnç
> değeri ya da bağlantı tarifi de vermez. **AI'ın dediği devrende çalışmıyorsa AI
> yanılmıştır, devren haklıdır.**

- [temel] **Eşleştirme** — "Sen sabırlı bir öğretmensin. Arduino Uno kartımda pin
  2'de 10 kΩ pull-down'lı bir buton, pin 6'da bir LED var; seri hız 9600. Kodum
  derleniyor ama LED beklediğim gibi davranmıyor. Hatayı `Serial.println` ile nasıl
  bulacağımı anlamama yardım et. Cevabı söyleme; neyi yazdıracağımı ve ekrandakini
  neyle karşılaştıracağımı buldurcak sorular sor."
- [temel] **Hata giderme** — "Sen bir hata ayıklama koçusun. Arduino Uno kartımda pin
  2'de pull-down'lı buton, pin 6'da LED var. LED hep yanık / yanıp sönüyor / hiç
  yanmıyor (hangisi olduğunu söyle). Cevabı verme; butonun ne okuduğunu ve kararın
  nerede verildiğini ayrı ayrı sınamamı sağlayacak sorular sor."
- [ileri] **Kavram derinleştirme** — "Sen ileri seviye bir mentorsun. Arduino Uno
  kartımda üç bozuk kod var (if sonunda noktalı virgül, `=` ile `==` karışması, LED pini
  `INPUT`). Üçünün neden derleme hatası vermediğini anlamama yardım et. Cevabı
  söyleme, her birinin söz diziminde neden geçerli olduğunu buldurcak sorular sor."
- [temel] **Yanındaki Yetişkine** — "Cevabı söylemeyin. Şu üç şeyi sırayla sorun:
  LED ne yapıyor, ne yapması gerekiyordu? Buton basılıyken `digitalRead` ne yazıyor?
  Ekrandaki bu sayı ile LED'in davranışı birbirine uyuyor mu?"

## 9. SEN YAP
1. `bozuk1_noktaliVirgul`'u aç, `loop()`'un başına `Serial.println(digitalRead(butonPin));`
   koy. Buton basılı değilken ekranda ne yazıyor, LED ne yapıyor? Bu ikisi neden
   çelişiyor? Hatayı bul, düzelt.
2. `bozuk2_esitEsit`'te `if`'in hemen önüne ve hemen sonrasına
   `Serial.println(digitalRead(butonPin));` ve `Serial.println(butonDurum);` koy.
   İkisi ne zaman farklı? Hatayı bul, düzelt.
3. `bozuk3_yanlisMod`'da `if`'in içine `Serial.println("yakiyorum");` koy. Mesaj
   çıkıyor mu? LED yanıyor mu? Bu ikisinin birlikte anlamı ne? Hatayı bul, düzelt.
4. Çözümler `cozumler/ak0299_bozukKoduOnar/` altında — önce kendin dene.
