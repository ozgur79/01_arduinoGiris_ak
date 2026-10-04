---
ak_no: ak0199
baslik: "Bozuk kodu onar (Ünite 1 kapanışı)"
duzey: 0-temel
unite: 1-LED-ve-Seri-Port
kazanimlar:
  - cpp.hata_ayiklama_seri
onkosul:
  - cpp.for (ak0130)
  - cpp.while (ak0150)
  - cpp.if / cpp.kalan (ak0160)
  - cpp.dizi (ak0185)
kara_kutu: [void, OUTPUT]
merak_kosesi: "atlandı (yük freni — ünite kapanışı, üç ayrı hata + yöntem zaten ağır)"
malzeme:
  - Arduino Uno kartı
  - USB kablosu
  - Paket 5 devresindeki 4 LED (pin 3/5/6/9)
board:
  kart: Arduino Uno
  seri_port_pinleri: [0, 1]
  seri_hiz: 9600
kaynak:
  - "yok — bu ders ak tarafından baştan yazıldı (kasıtlı hatalı kod)"
klasor_notu: "Arduino IDE tek klasörde tek .ino ister ve dosya adı klasör adıyla eşleşmek zorunda. Üç bozuk kod aynı anda ayrı ayrı açılabilsin diye her biri kendi alt klasöründe, kendi adını taşıyan bir .ino olarak duruyor (bozuk1_yanlisSinir/, bozuk2_artmayanSayac/, bozuk3_tersIf/) — tek ortak ders.md üçünü de anlatıyor."
---

## 1. Hedef
Üç ayrı kod parçası da **derleniyor** ama **yanlış çalışıyor**. Görevin, tahmin
etmeden, `Serial.println` ile şüpheli değişkenlerin değerini ekrana yazdırarak
hatayı bulmak ve düzeltmek.

## 2. Malzemeler
- Arduino Uno kartı
- USB kablosu
- Paket 5 devresindeki 4 LED (pin 3/5/6/9, ortak GND hattı) — üç kod da bu devreyi
  aynen kullanır, hiçbir şey sökülmez.

## 3. Parça tanıtımı
Yeni bir komut yok. Bu ders `for`, `while`, `if`, `%` ve dizi'yi (Ünite 1'in tüm
aletleri) **hata bulmak için** kullanıyor — seri port artık sadece sonucu
göstermiyor, **hata bulma aletine** dönüşüyor.

**Klasör düzeni notu:** Arduino IDE bir klasörde tek `.ino` ister ve o dosyanın adı
klasörün adıyla eşleşmek zorunda. Üç bozuk kodun hepsi ayrı ayrı çalıştırılabilsin
diye her biri kendi alt klasöründe duruyor:
- `bozuk1_yanlisSinir/bozuk1_yanlisSinir.ino`
- `bozuk2_artmayanSayac/bozuk2_artmayanSayac.ino`
- `bozuk3_tersIf/bozuk3_tersIf.ino`

## 4. Devre kurulumu
Paket 5 devresi (ak0185'te kurulan 4 LED, pin 3/5/6/9, ortak GND hattı) kuruluysa
dokunma. Üç bozuk kod da bu devreyi değiştirmeden kullanır.

## 5. Kod açıklaması

**Yöntem, üçünde de aynı üç adım:**
1. Kodun **beklendiği gibi çalışmadığı** yeri gözlemle (hangi LED yanmıyor, hangi
   desen donuyor, hangi basamak ters).
2. Şüphelendiğin değişkenin yanına `Serial.println(degisken);` koy (setup()'a
   `Serial.begin(9600);` eklemen gerekebilir, bozuk kodlarda henüz yok).
3. Seri Monitör'deki sayıyla **beklediğin** sayıyı karşılaştır — farkın olduğu yer
   hatanın olduğu yerdir.

| dosya | ne bekleniyor | ne oluyor |
| --- | --- | --- |
| `bozuk1_yanlisSinir` | 4 LED sırayla yanıp söner | pin 9 (ledler[3]) hiç yanmıyor |
| `bozuk2_artmayanSayac` | 4 LED sırayla yanıp söner | sadece pin 3 sonsuza kadar yanıp sönüyor, öbürleri hiç sıra bulamıyor |
| `bozuk3_tersIf` | binary sayıcı (ak0190 gibi) 0'dan 15'e sayar | 2'ler basamağının LED'i (pin 6) her sayıda TAM TERS davranıyor |

### İleri analiz [ileri]
Üçü de "kod çalışıyor görünüyor ama yanlış" kategorisinde — Arduino IDE hiçbirinde
hata vermez (derleme hatası yok), çünkü üçü de **söz dizimi olarak** doğru. Hata
**mantıkta**: yanlış sınır, unutulan bir satır, ters bir karşılaştırma. Bu tür
hatalar en zor bulunanlardır çünkü kart sana "burada bir hata var" demez —
`Serial.println` bu yüzden bir hata ayıklama ALETİDİR, sadece sonuç gösteren bir
ekran değil.

## 6. Çalıştır ve gözlemle
Her üç klasörü de sırayla Arduino IDE ile aç, karta yükle, gözlemle.

### Sorun giderme
- **Hangi satıra `Serial.println` koyacağımı bilmiyorum** → "Ne oluyor" sütunundaki
  gözlemden başla: hangi LED/basamak yanlış davranıyorsa, o LED'i kontrol eden
  değişkenin (döngü sayacı, `sayi % 4` gibi) yanına koy.
- **`Serial.println` ekledim ama hiçbir şey görünmüyor** → `setup()`'a
  `Serial.begin(9600);` eklemeyi unutmuş olabilirsin; Seri Monitör'ün hızını da
  9600 yap.
- **Ekranda sayılar akıyor ama hangisinin "yanlış" olduğunu anlayamıyorum** →
  Kodun BEKLEDİĞİN hâlini (elle, kafanda ya da kağıda) önce yaz, sonra ekrandaki
  sayıyla karşılaştır — fark ettiğin an hata orada.
- **Onardım ama LED hâlâ yanlış davranıyor** → Değiştirdiğin satırın gerçekten
  hatalı satır olduğundan emin ol; bazen birden fazla satır şüpheli görünür ama
  tek biri gerçek hatadır.

**dk uyarlama notu:** Bu ders evde öğretmensiz öğrenmenin en işe yarar becerisini
(kendi kodunu şüpheyle okuyup ölçerek hata bulma) öğretiyor — Deneyap Atölyem'in
öğretmensiz ortamına doğrudan uyar. Portlama bu turda yapılmıyor, sadece not
düşülüyor.

**Not:** Bu tarz "bozuk kodu onar" kapanış dersi Ünite 2 ve Ünite 3 sonunda da
tekrar gelecek — her seferinde o ünitenin kendi aletleriyle.

## 7. Mini sınav
1. [temel] Bu üç bozuk kod, Arduino IDE'de yüklenirken hata veriyor mu?
   - A) Evet, üçü de derleme hatası veriyor
   - B) Hayır, üçü de derleniyor ama yanlış çalışıyor
   - C) Sadece biri derleniyor
   - D) Hiçbiri karta yüklenemiyor
   - ipucu: Başlıktaki "Hedef" satırına bak.

2. [temel] Hatayı bulma yöntemi nedir?
   - A) Tahmin etmek
   - B) Şüpheli değişkenin yanına Serial.println koyup beklenenle karşılaştırmak
   - C) Kodu baştan yazmak
   - D) Kartı resetlemek
   - ipucu: "3 adımlı yöntem" başlığına bak.

3. [temel] `bozuk1_yanlisSinir`'de hangi LED yanmıyor?
   - A) pin 3
   - B) pin 5
   - C) pin 6
   - D) pin 9
   - ipucu: Dizinin son elemanı, indeks 3.

4. [temel] `bozuk2_artmayanSayac`'ta neden sadece bir LED sonsuza kadar yanıp
   sönüyor?
   - A) LED bozuk
   - B) Sayaç bir satır eksik yüzünden hiç artmıyor
   - C) delay() çok uzun
   - D) Pin numarası yanlış
   - ipucu: while'ın koşulunu hiç yanlış yapamayan bir şey eksik.

5. [ileri] `bozuk3_tersIf`'te hata neden bulunması en zor olanı?
   - A) Kod derlenmiyor
   - B) Yanlış satır söz dizimi olarak tamamen doğru, sadece mantığı ters (< yerine >)
   - C) LED bağlı değil
   - D) Seri hız yanlış
   - ipucu: Arduino IDE'nin görebileceği bir hata değil, mantık hatası.

6. [ileri] Üç bozuk kodun ortak noktası nedir?
   - A) Üçü de derleme hatası veriyor
   - B) Üçü de "çalışıyor görünüyor ama yanlış" — hata mantıkta, söz diziminde değil
   - C) Üçü de aynı pini kullanıyor
   - D) Üçü de while kullanıyor
   - ipucu: "İleri analiz" bölümüne bak.

## 8. AI Yoldaşı promptları

> **Not:** AI Yoldaşı sana hatanın nerede olduğunu SÖYLEMEZ. **AI'ın dediği
> kartında çalışmıyorsa AI yanılmıştır, kartın haklıdır.**

- [temel] **Eşleştirme** — "Sen sabırlı bir öğretmensin. Arduino Uno kartımda seri
  hız 9600; 4 LED'im (pin 3/5/6/9) beklediğim gibi çalışmıyor. Hatayı
  `Serial.println` ile nasıl bulacağımı anlamama yardım et. Cevabı söyleme; hangi
  değişkenin şüpheli olduğunu ve beklediğim değerle ekrandakini nasıl
  karşılaştıracağımı buldurcak sorular sor."
- [temel] **Hata giderme** — "Sen bir hata ayıklama koçusun. Arduino Uno kartımda
  seri hız 9600; kodum derleniyor ama bir LED hiç yanmıyor / bir LED donuk kalıyor
  / bir basamak ters davranıyor (hangisi olduğunu söyle). Cevabı verme; şüpheli
  satırın yanına ne koyacağımı ve ekrandaki sayıyı neyle karşılaştıracağımı
  sorularla buldur."
- [ileri] **Kavram derinleştirme** — "Sen ileri seviye bir mentorsun. Arduino Uno
  kartımda üç farklı bozuk kod var (yanlış sınır, artmayan sayaç, ters if). Bu üç
  hatanın neden Arduino IDE tarafında bir derleme hatası olarak görünmediğini,
  neden hepsinin 'mantık hatası' sayıldığını anlamama yardım et. Cevabı söyleme,
  her birinin söz dizimi olarak neden geçerli olduğunu buldurcak sorular sor."
- [temel] **Yanındaki Yetişkine** — "Cevabı söylemeyin. Şu üç şeyi sırayla sorun:
  Hangi LED/basamak yanlış davranıyor? Şüpheli satırın yanına hangi değişkeni
  yazdırdın? Ekrandaki sayı, senin beklediğin sayıyla aynı mı?"

## 9. SEN YAP
1. `bozuk1_yanlisSinir`'i aç, `Serial.begin(9600);` ekle, döngü sayacının (`i`)
   yanına `Serial.println(i);` koy, karta yükle. En büyük hangi sayıyı görüyorsun?
   Beklediğin sayı (dizinin son indeksi) ile aynı mı?
2. `bozuk2_artmayanSayac`'ı aynı yöntemle incele — sayaç değişip değişmediğini
   gözlemle.
3. `bozuk3_tersIf`'i incele — `sayi % 4` değerini ekrana yazdır, `Serial.println("Sayi: ")`
   ile yazdırılan onluk sayıyla karşılaştır. 2'ler basamağının LED'i (pin 6) hangi
   sayılarda YANMASI gerekiyor, hangilerinde gerçekten yanıyor?
4. Üçünü de düzelt. Çözüm `cozumler/ak0199_bozukKoduOnar/` altında — önce kendin
   dene, sonra karşılaştır.
