---
ak_no: ak0185
baslik: "Dizi: pinler ardışık olmayınca kara şimşek"
duzey: 0-temel
unite: 1-LED-ve-Seri-Port
kazanimlar:
  - cpp.setup-loop
  - cpp.delay
  - cpp.pinmode
  - cpp.digitalwrite
  - cpp.const-int
  - cpp.for
  - cpp.dizi
  - cpp.dizi_indeks
onkosul:
  - cpp.for (ak0130), const int/çoklu çıkış (ak0060/ak0140)
kara_kutu: [void, OUTPUT]
merak_kosesi: "atlandı (yük freni — dizi + acı açılışı zaten ağır)"
malzeme:
  - Arduino Uno kartı
  - USB kablosu
  - 4 LED
  - 4 adet 220 ohm direnç
  - breadboard
  - 5 jumper kablo
board:
  kart: Arduino Uno
  led_pinleri: [3, 5, 6, 9]
  mantik_gerilimi: 5V
  direnc: 220 ohm
kaynak:
  - ..\arsiv\004karaSimsekIleri\004karaSimsekIleri.ino (dizi kullanan hâli)
  - ak0140_karaSimsekFor/ak0140_karaSimsekFor.ino
---

## 1. Hedef
ak0140'ta bir soru bırakmıştık: "pinler ardışık olmasaydı ne yapardık?" Bu derste
cevabı **dizi**: birden fazla değeri tek bir isimde, sıra numarasıyla saklayan bir
kutu. **Devreyi kurduktan hemen sonra, bu dersin kodunu yüklemeden önce SEN YAP 1'i
yap** — acıyı önce kendin yaşa, çözümü sonra oku.

## 2. Malzemeler
- Arduino Uno kartı
- USB kablosu
- 4 LED
- 4 adet 220 ohm direnç
- Breadboard
- 5 jumper kablo

## 3. Parça tanıtımı
Yeni parça yok. Dört LED, dört direnç — ak0140 ile aynı sayıda malzeme, farklı pinlerde.

## 4. Devre kurulumu
1. 4 LED'i breadboard'a soldan sağa, yan yana tak.
2. 1. LED'in uzun bacağını (+) pin **3**'e, 2.'yi pin **5**'e, 3.'yü pin **6**'ya,
   4.'yü pin **9**'a bağla (dört sinyal jumper'ı).
3. Her LED'in kısa bacağını (−) kendi 220 ohm direncine bağla. Dirençlerin boş
   uçlarının hepsini breadboard'ın **ortak GND hattına** tak (aynı hat).
4. O GND hattını **TEK bir jumper** ile Arduino'nun GND pinine bağla — LED başına
   ayrı bir GND jumper'ı gerekmez.
5. Arduino Uno'yu USB kablosuyla bilgisayara bağla.

Metin şeması:
- 1. LED (+) → pin 3, (−) → 220 ohm direnç → ortak GND hattı
- 2. LED (+) → pin 5, (−) → 220 ohm direnç → ortak GND hattı
- 3. LED (+) → pin 6, (−) → 220 ohm direnç → ortak GND hattı
- 4. LED (+) → pin 9, (−) → 220 ohm direnç → ortak GND hattı
- Ortak GND hattı → 1 jumper → Arduino GND

Toplam jumper: 4 (sinyal) + 1 (GND hattı) = **5**.

**Pinler ardışık değil** (3, 5, 6, 9) — ak0140'taki gibi 8,9,10,11 değil. Bu dersin
başlangıç noktası tam olarak bu — SEN YAP 1'de bunu kendin göreceksin.

## 5. Kod açıklaması
| kod satırı | açıklama |
| --- | --- |
| `const int ledler[4] = {3, 5, 6, 9};` | Dört pini TEK bir isimde, sırayla saklar. |
| `ledler[0]` | Dizinin **birinci** elemanı — pin 3. Dizi SIFIRDAN sayılır. |
| `ledler[3]` | Dizinin **dördüncü** elemanı — pin 9 (`ledSayisi - 1` = 3). |
| `for (int i = 0; i < ledSayisi; i++)` | `i`, 0'dan `ledSayisi - 1`'e (yani 3'e) kadar gider — dizinin tüm elemanlarını dolaşır. |
| `pinMode(ledler[i], OUTPUT);` | `i`. sıradaki pini çıkış yapar. |

### İleri analiz [ileri]
**Neden `i < 4` yazıyoruz, `i <= 4` değil?** Dizi 4 elemanlıdır ama SIFIRDAN sayıldığı
için geçerli indeksler 0, 1, 2, 3'tür — `ledler[4]` diye bir eleman **yoktur**. Eğer
yanlışlıkla `i <= 4` yazılırsa, `i` 4 olduğunda `ledler[4]`'e erişilmeye çalışılır: kart
bunun için bir HATA vermez, dizinin hemen arkasındaki hafıza bölgesini "pin numarası"
sanıp oraya rastgele bir değer yazar — beklenmedik bir pin yanabilir ya da hiçbir şey
olmayabilir. Bu, C++'ın **sessizce yanlış davranan** bir tarafıdır; kontrol her zaman
sana düşer.

**ak0140'la karşılaştırma:** ak0140'ta döngü değişkeni (`pin`) doğrudan pin numarasıydı
(`pin = 8, 9, 10, 11`), çünkü pinler ardışıktı. Burada döngü değişkeni (`i`) bir **sıra
numarası**dır (0, 1, 2, 3), gerçek pin `ledler[i]`'den okunur. Pinler ardışık olduğunda
dizi gerekmez; ardışık olmadığında dizi tek çözümdür.

## 6. Çalıştır ve gözlemle
Devreyi kur, kodu karta yükle. LED'ler pin 3-5-6-9-6-5 sırasıyla yanıp söner, sonra
baştan başlar — ak0140'taki 1-2-3-4-3-2 deseninin birebir aynısı, sadece farklı
pinlerde.

### Sorun giderme
- **Hiçbir LED yanmıyor** → Kod yüklenmemiş olabilir; doğru kartı ve portu seçip
  tekrar yükle.
- **Yalnız bir LED yanmıyor** → O LED ters takılmış olabilir; uzun bacağın pine, kısa
  bacağın kendi direncine gittiğini kontrol et.
- **Beklenmedik bir pin yanıyor ya da davranış tuhaf** → `for` satırlarındaki `< ledSayisi`
  yerine yanlışlıkla `<= ledSayisi` yazılmış olabilir — dizinin sınırını aşan bir
  indekse erişiliyor olabilir. Sınırları KAVRAM'daki hâliyle karşılaştır.
- **Desen ak0140'takinden farklı** → `ledler` dizisinin `{3, 5, 6, 9}` olduğunu
  kontrol et.

## 7. Mini sınav
1. [temel] `ledler[0]` hangi pini verir?
   - A) 0
   - B) 3
   - C) 5
   - D) 9
   - ipucu: Dizi sıfırdan sayılır, ilk eleman indeks 0'dadır.

2. [temel] `ledler` dizisinde kaç eleman var?
   - A) 3
   - B) 4
   - C) 5
   - D) 9
   - ipucu: `{3, 5, 6, 9}` — virgülle ayrılmış sayıları say.

3. [temel] `for (int i = 0; i < ledSayisi; i++)` satırında `i` en son hangi değeri alır?
   - A) 4
   - B) 3
   - C) 0
   - D) 9
   - ipucu: Koşul `i < 4` olduğu için `i` 4 olunca döngü durur, içeri girmeden.

4. [temel] Bu dersin devresi hangi eski dersle aynı sayıda LED kullanır?
   - A) ak0060 / ak0140 (4 LED)
   - B) ak0070 (3 LED)
   - C) ak0040 (2 LED)
   - D) ak0020 (1 LED)
   - ipucu: Malzeme listesine bak.

5. [ileri] `for (int i = 0; i <= ledSayisi; i++)` yazılsaydı ne olurdu?
   - A) Hiçbir şey değişmezdi
   - B) `ledler[4]` gibi var olmayan bir elemana erişilir, kart hata vermeden rastgele
     davranabilirdi
   - C) Kod derlenmezdi
   - D) Desen tersine dönerdi
   - ipucu: Dizinin geçerli indeksleri 0, 1, 2, 3'tür.

6. [ileri] ak0140 ile ak0185 arasındaki temel fark nedir?
   - A) ak0185'te LED sayısı farklı
   - B) ak0140'ta döngü değişkeni doğrudan pin numarasıydı, ak0185'te bir dizi
     indeksidir
   - C) ak0185'te `for` kullanılmıyor
   - D) Fark yok
   - ipucu: Pinlerin ardışık olup olmaması.

## 8. AI Yoldaşı promptları

> **Not:** AI Yoldaşı sana devrenin nasıl kurulacağını, hangi pine bağlayacağını ya da
> hangi direnci kullanacağını söylemez — bunlar sadece derste yazar. **AI'ın dediği
> devrende çalışmıyorsa AI yanılmıştır, devren haklıdır.**

- [temel] **Eşleştirme** — "Sen sabırlı bir öğretmensin. Arduino Uno kartında 5V mantık
  gerilimiyle çalışan kara şimşek devremde 4 LED pin 3, 5, 6, 9'da (ardışık değil), her
  LED'in 220 ohm direnci var. `ledler[0]`'ın hangi pin olduğunu anlamama yardım et. Pin
  veya bağlantı tarifi verme, cevabı söyleme; dizinin sıfırdan başladığını fark ettiren
  sorular sor."
- [temel] **Hata giderme** — "Sen bir hata ayıklama koçusun. Arduino Uno kartında 5V
  mantık gerilimiyle çalışan kara şimşek devremde 4 LED pin 3, 5, 6, 9'da. Beklenmedik
  bir davranış görüyorum. Pin veya bağlantı tarifi verme; `for` döngüsünün sınırının
  (`< ledSayisi`) doğru yazılıp yazılmadığını kontrol etmemi sağlayan sorular sor."
- [ileri] **Kavram derinleştirme** — "Sen ileri seviye bir mentorsun. Arduino Uno
  kartımda dizi kullanan bir kara şimşek kodum var. `ledler[4]`'e erişmenin neden
  tehlikeli olduğunu anlamama yardım et. Cevabı söyleme, dizinin geçerli indekslerini
  saydıran sorular sor."
- [temel] **Yanındaki Yetişkine** — "Cevabı söylemeyin. Şu üç şeyi sırayla sorun: Dizide
  kaç eleman var? İlk eleman hangi sayıyla adlandırılıyor (0 mu 1 mi)? `for` döngüsü
  kaç kez çalışıyor?"

## 9. SEN YAP
1. **ÖNCE BUNU DENE** (bu dersin kodunu yüklemeden önce): `ak0140_karaSimsekFor`
   klasöründeki kodu aç, `ilkLed = 3` ve `sonLed = 9` yap, bu devreye (pin 3,5,6,9)
   yükle. Ne oluyor? Desen 4, 7 ve 8'de "boşta bekliyor" gibi davranır, ritim bozulur
   — çünkü orada LED yok. Bu ACI'yı gördükten sonra bu dersin koduna geç.
2. `ledler` dizisinin sırasını değiştir: `{9, 3, 6, 5}`. Kodun geri kalanına HİÇ
   dokunmadan desen nasıl değişti?
3. ak0170'le birleştir: her LED `digitalWrite` yerine `analogWrite` ile yavaşça
   parlayıp sönsün (nefes alan kara şimşek).
