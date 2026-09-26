# Müfredat

Numaralandırma şeması: `ak<binler><yüzler><onlar+birler>` — binler = düzey (0 = temel),
yüzler = ünite/blok (0 = LED), onlar+birler = ders sırası.

## Ders Tablosu

| ak no | konu | kazanım | C++ önkoşulu | donanım önkoşulu | malzeme | öncelik | kaynak |
|-------|------|---------|----------------|---------------------|---------|---------|--------|
| ak0010 | Dahili LED'i yakıp söndür | setup bir kez, loop sürekli çalışır; dahili LED'i yakıp söndürebilme | yok | yok | Arduino Uno kartı | çekirdek | ..\arsiv\001dahiliLed\001dahiliLed.ino |
| ak0020 | Harici LED'i yakıp söndür | LED'i breadboard üzerinde harici bir pime bağlayıp yakıp söndürebilme; LED'in yönü olduğunu (uzun bacak +, kısa bacak −) ve direncin LED'i koruma görevini açıklayabilme | setup/loop, pinMode/digitalWrite, delay (ak0010) | dahili LED (ak0010) | Arduino Uno kartı, USB kablosu, 1 LED, 1 adet 220 ohm direnç, breadboard, 2 jumper kablo | çekirdek | ..\arsiv\002ledYak\002ledYak.ino |
| ak0030 | LED'i hızlandır | Yanıp sönmeyi hızlandırmanın bir sınırı olduğunu, o sınırdan sonra gözün sönmeyi ayırt edemediğini gözlemle bulabilme; delay değerinin sıklığı belirlediğini açıklayabilme | setup/loop, delay, pinMode/digitalWrite (ak0010) | harici LED devresi (ak0020) | ak0020'nin devresi aynen (yeni malzeme yok) | çekirdek | ..\arsiv\002ledYak\002ledYak.ino (bekleme süresi merdiveni) |
| ak0040 | İki LED sırayla | Aynı programda iki çıkış pinini bağımsız yönetebilme; bir LED yanarken diğerini sönük tutabilme (zıt durum); her LED'in kendi direnci olması gerektiğini açıklayabilme | setup/loop, pinMode/digitalWrite, delay (ak0010) | harici LED devresi (ak0020) | Arduino Uno kartı, USB kablosu, 2 LED, 2 adet 220 ohm direnç, breadboard, 4 jumper kablo | çekirdek | ..\arsiv\006ikiLed\006ikiLed.ino (pin 13/12 -> 8/9 düzeltildi) |
| ak0050 | LED'e isim ver | Pin numarası yerine `const int` ile verilen bir isim kullanabilme; pin değiştiğinde tek satır düzeltmenin yettiğini gösterebilme; ismin Arduino için değil kodu okuyan insan için olduğunu açıklayabilme | setup/loop, pinMode/digitalWrite, çoklu çıkış (ak0040) | iki LED devresi (ak0040) | ak0040'ın devresi aynen (yeni malzeme yok) | çekirdek | yok — ak0040'ın varyasyonu |
| ak0060 | Kara şimşek (elle) | Dört LED'i ayrı ayrı yöneterek gidip gelen bir desen kurabilme; her adımda tüm çıkışların durumunun yazılması gerektiğini açıklayabilme; tekrar eden satırların çoğalmasını bir problem olarak fark etme | const int (ak0050), çoklu çıkış (ak0040) | dört LED devresi | Arduino Uno kartı, USB kablosu, 4 LED, 4 adet 220 ohm direnç, breadboard, 8 jumper kablo | çekirdek | ..\arsiv\004karaSimsek\004karaSimsek.ino (pin ve desen düzeltmeli) |
| ak0070 | Trafik lambası | Üç LED'i `const int` adlarıyla trafik lambası sırasına göre yönetebilme; her adımda tüm çıkışların durumunu yazabilme; `delay` sayısının projenin anlamını değiştirdiğini gözlemleyebilme | const int (ak0050), çoklu çıkış (ak0040), delay (ak0010) | çoklu LED devresi (ak0040) | Arduino Uno kartı, USB kablosu, kırmızı+sarı+yeşil LED, 3 adet 220 ohm direnç, breadboard, 6 jumper kablo | çekirdek — ünite 0 kapanış projesi | ..\arsiv\008trafikLambasi\008trafikLambasi.ino (pin 2/3/4 -> 8/9/10; isimlendirildi) |
| ak0110 | LED durumunu yaz | Kartın çalışırken bilgisayara yazı gönderebildiğini gözlemleyebilme; seri bağlantıyı 9600 hızında başlatabilme; `Serial.println` ile LED'in durumunu ayrı satırlarda yazdırabilme | setup/loop, pinMode/digitalWrite, delay (ak0010) | harici LED devresi (ak0020) | ak0020'nin devresi aynen (yeni malzeme yok) | çekirdek — seri port derslerinin önkoşulu | ..\arsiv\000seri06ledYandiSondu\000seri06ledYandiSondu.ino (pin 6 -> 8; Serial.print -> Serial.println) |
| ak0115 | Trafik lambası rengini yazsın | Trafik lambasında yanan rengin adını `Serial.println` ile aynı anda yazdırabilme; bilinen bir projeye seri çıktı katmanı ekleyebilme | Serial.begin/println (ak0110), const int/çoklu çıkış/delay (ak0070) | trafik lambası devresi (ak0070) | ak0070'in devresi aynen (yeni malzeme yok) | genişletme adayı — `Serial.println` pekiştirmesi | ak0070_trafikLambasi/ak0070_trafikLambasi.ino; ..\arsiv\kabaMüfredat.docx (030. madde) |
| ak0120 | Sayaç: kart saysın, ekrana yazsın | Program çalışırken değeri değişebilen bir isim (değişken) tanımlayabilme; `sayac = sayac + 1;` satırının eşitliğin sağının önce hesaplanıp sola atandığını açıklayabilme | Serial.begin/println (ak0110) | yok | Arduino Uno kartı, USB kablosu (devre yok) | çekirdek — `for`'un önkoşulu | ..\arsiv\009ak120ham\009ak120ham.ino (Özgür yazdı; 115200→9600, sayac++→sayac=sayac+1, Serial.print(" ")→Serial.println) |
| ak0130 | `for`: sayma işini tek satıra topla | `for` döngüsünün üç bölmesini (başlangıç, koşul, artış) tanıyıp kullanabilme; `sayac++`'ın `sayac = sayac + 1;`'in kısa yazılışı olduğunu açıklayabilme | değişken/atama (ak0120) | yok | Arduino Uno kartı, USB kablosu (devre yok) | çekirdek — döngülerin ilk dersi | ..\arsiv\002for1den100e\002for1den100e.ino (0-255→1-10, 1000ms→500ms, "Sayaç Değeri: "→"Sayac: ", kullanılmayan `int degisken;` silindi) |
| ak0140 | Kara şimşek, `for` ile (harcama dersi) | `for` ile ardışık pinleri tek döngüde yönetebilme; elle yazılmış kodla `for` ile yazılmış kodu satır sayısı üzerinden karşılaştırabilme | `for`/`sayac++` (ak0130), const int/çoklu çıkış (ak0060) | dört LED devresi (ak0060, aynen) | ak0060'ın devresi aynen (yeni malzeme yok) | genişletme — `for` pekiştirmesi, yeni kazanım yok | ..\arsiv\004karaSimsekIleri\004karaSimsekIleri.ino (dizi kaldırıldı, desen hatası düzeltildi) + ak0060_karaSimsek/ak0060_karaSimsek.ino |

## Kara Kutu Takip Tablosu

Kara kutu sadece işaretlenmez, **taksitle ödenir**: ders başına tek kutu, o dersin
`.ino` dosyasının sonundaki `MERAK KÖŞESİ`nde 3-6 satırla gerçekten açıklanır. Doktrin
`CLAUDE.md`'de.

**Rotasyon sırası:** `void` → `OUTPUT` → (başa dön). `void` ak0115'te 3. turla emekli
oldu; sıradaki kutu `OUTPUT` (3. tur), ak0140'ta karşılandı ve o da emekli oldu. `{ }` ve
`;` rotasyona girmez, ak0020'de KAVRAM içinde kapandı.

**İkinci, bağımsız rotasyon (2026-09-26):** `Serial ve noktalı yazım` kendi başına bir
rotasyona girdi — `void`/`OUTPUT` rotasyonuyla karışmaz, çünkü ak0120/ak0130'da (seri
port dersleri, `pinMode`/`OUTPUT` hiç kullanılmıyor) `OUTPUT`'u o derste yazılan koda
bağlamak mümkün değildi (doktrin: "zincir kurar, kendi kodunda ne yaptığını" anlatır).
`Serial ve noktalı yazım` ise tam o derslerde kullanıldığı için doğal aday oldu. Aynı
3 tur / emekli kuralı bu rotasyon için de geçerli.

**Rotasyon freni:** bir kutu 3 tur köşeye konu olduysa `emekli` sayılır, açılış dersine
kadar bir daha yazılmaz.

**Yük freni:** dersin kendi yeni fikri ağırsa köşe atlanır, rotasyon kaymaz — atlanan
ders aşağıdaki günlükte görünür. ak0010 (ilk ders, aynı anda 11 yeni şey) ve ak0020
(ilk devre kurulumu: LED yönü, direnç, breadboard, GND) bu yüzden köşesiz. Rotasyon
ak0030'da başladı. ak0040 = `OUTPUT` (1. tur), ak0050 = `void` (2. tur). ak0060 yük
freniyle atlandı (30 satırlık desen dersi); rotasyon kaymadı. ak0070 = `OUTPUT` (2. tur).
ak0110 yeni seri port aracıyla noktalı yazımı birlikte getirdiği için yük freniyle
atlandı; sıradaki `void` 3. tur kaymadı. ak0115 = `void` (3. tur); kutu emekli oldu.
ak0120 = `Serial ve noktalı yazım` (1. tur, yeni rotasyon başladı). ak0130 =
`Serial ve noktalı yazım` (2. tur, yeni açı: `Serial.print` vs `Serial.println`).
ak0140 = `OUTPUT` (3. tur, yeni açı: `for` ile tek satırda dört pine birden yazılması);
kutu emekli oldu.

| kara kutu | ilk göründüğü ders | açılacağı yer | tur / emekli | Merak Köşesi günlüğü | not |
|-----------|---------------------|----------------|----------------|----------------------|-----|
| `void` | ak0010 | "fonksiyon" konusu — temel düzeyin ilerisinde, numarası o tur belirlenecek | 3 tur / emekli | ak0030: setup ve loop birer "iş listesi", void listenin adının önünde "geriye bir sonuç vermeyecek" der; ak0050: `const int` ile aynı yerde durur — int "bu bir sayı" derken void "geriye bir şey gelmez" der (2. tur, yeni açı); ak0115: setup seri bağlantıyı hazırlar, loop renkleri çalıştırır; void iki listenin işini yapıp geriye sonuç vermeyeceğini söyler (3. tur, yeni açı) | emekli — açılış dersine kadar rotasyondan çıktı |
| `OUTPUT` | ak0010 | buton dersi (ünite 2), INPUT ile birlikte | 3 tur / emekli | ak0040: pinMode satırında pine ne iş yapacağını söylersin; OUTPUT = bu pin dışarı elektrik verecek. Görev bir kez seçildiği için satır setup'ta durur; ak0070: üç rengin her birini açıp kapatabilmek için üç pine de OUTPUT yazılır (2. tur, yeni açı); ak0140: dört pin için OUTPUT artık elle değil `for` ile tek satırda tekrarlanıyor, OUTPUT'un kendisi değişmedi (3. tur, yeni açı) | emekli — açılış dersine (buton, ünite 2) kadar rotasyondan çıktı |
| `{ }` | ak0010 | ak0020 (açıldı) | rotasyon dışı | — | ak0020'de KAVRAM'da açıldı, kapandı |
| `;` | ak0010 | ak0020 (açıldı) | rotasyon dışı | — | ak0020'de KAVRAM'da açıldı, kapandı |
| `Serial ve noktalı yazım` | ak0110 | "fonksiyon" konusu — temel düzeyin ilerisinde, numarası o tur belirlenecek | 2 tur | ak0110: atlandı (yük freni — yeni seri port aracıyla yeni noktalı yazım birlikte geliyor); ak0120: Serial.begin ve Serial.println'deki nokta, "bu yeteneğe şunu yap demenin yolu" olarak tanıtıldı (1. tur); ak0130: Serial.print ile Serial.println farkı — print aynı satırda kalır, println yeni satıra geçer (2. tur, yeni açı) | rotasyonda — `void`/`OUTPUT` rotasyonundan bağımsız, kendi 3 turluk döngüsünde |

**Atlanan dersler (yük freni):** ak0010, ak0020, ak0060, ak0110.

## Ünite 0 — Set Başına Minimum Malzeme

Özgür onayladı (2026-09-06): sınıfta her set için bu miktarlar mevcut.

**Set başına minimum:** 1 Arduino Uno + USB kablosu · 1 breadboard · **4 LED** (en az biri
kırmızı, biri sarı, biri yeşil — trafik lambası için; dördüncünün rengi serbest) ·
**4 adet 220 ohm direnç** · **8 jumper kablo**.

| ders | LED | direnç | jumper | not |
|------|-----|--------|--------|-----|
| ak0010 | 0 | 0 | 0 | dahili LED, devre yok |
| ak0020 | 1 | 1 | 2 | ilk devre |
| ak0030 | 1 | 1 | 2 | ak0020'nin devresi aynen |
| ak0040 | 2 | 2 | 4 | ak0030'un üstüne ikinci LED |
| ak0050 | 2 | 2 | 4 | ak0040'ın devresi aynen |
| ak0060 | 4 | 4 | 8 | kara şimşek — ünitenin en çok malzeme isteyen dersi |
| ak0070 | 3 | 3 | 6 | trafik lambası: kırmızı + sarı + yeşil |

Her LED'in **kendi direnci** olmalı; iki LED tek dirence bağlanırsa ikisi de sönük yanar.

## Malzeme Gerekiyor (temel düzeye girmeyecek)
(boş — motor/servo, 7 segment, mesafe sensörü, buzzer gibi dersler envanter geldikçe buraya
düşülecek, temel düzeye eklenmeyecek)
