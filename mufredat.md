# Müfredat

Numaralandırma şeması: `ak<binler><yüzler><onlar+birler>` — binler = düzey (0 = temel),
yüzler = ünite/blok (0 = LED), onlar+birler = ders sırası.

## Ders Tablosu

| ak no | konu | kazanım | C++ önkoşulu | donanım önkoşulu | malzeme | öncelik | kaynak |
|-------|------|---------|----------------|---------------------|---------|---------|--------|
| ak0010 | Dahili LED'i yakıp söndür | setup bir kez, loop sürekli çalışır; dahili LED'i yakıp söndürebilme | yok | yok | Arduino Uno kartı | çekirdek | arsiv/001dahiliLed/001dahiliLed.ino |
| ak0020 | Harici LED'i yakıp söndür | LED'i breadboard üzerinde harici bir pime bağlayıp yakıp söndürebilme; LED'in yönü olduğunu (uzun bacak +, kısa bacak −) ve direncin LED'i koruma görevini açıklayabilme | setup/loop, pinMode/digitalWrite, delay (ak0010) | dahili LED (ak0010) | Arduino Uno kartı, USB kablosu, 1 LED, 1 adet 220 ohm direnç, breadboard, 2 jumper kablo | çekirdek | arsiv/002ledYak/002ledYak.ino |
| ak0030 | LED'i hızlandır | Yanıp sönmeyi hızlandırmanın bir sınırı olduğunu, o sınırdan sonra gözün sönmeyi ayırt edemediğini gözlemle bulabilme; delay değerinin sıklığı belirlediğini açıklayabilme | setup/loop, delay, pinMode/digitalWrite (ak0010) | harici LED devresi (ak0020) | ak0020'nin devresi aynen (yeni malzeme yok) | çekirdek | arsiv/002ledYak/002ledYak.ino (bekleme süresi 500 ms) |
| ak0040 | İki LED sırayla | Aynı programda iki çıkış pinini bağımsız yönetebilme; bir LED yanarken diğerini sönük tutabilme (zıt durum); her LED'in kendi direnci olması gerektiğini açıklayabilme | setup/loop, pinMode/digitalWrite, delay (ak0010) | harici LED devresi (ak0020) | Arduino Uno kartı, USB kablosu, 2 LED, 2 adet 220 ohm direnç, breadboard, 4 jumper kablo | çekirdek | arsiv/006ikiLed/006ikiLed.ino (pin 13/12 -> 8/9 düzeltildi) |
| ak0050 | LED'e isim ver | Pin numarası yerine `const int` ile verilen bir isim kullanabilme; pin değiştiğinde tek satır düzeltmenin yettiğini gösterebilme; ismin Arduino için değil kodu okuyan insan için olduğunu açıklayabilme | setup/loop, pinMode/digitalWrite, çoklu çıkış (ak0040) | iki LED devresi (ak0040) | ak0040'ın devresi aynen (yeni malzeme yok) | çekirdek | yok — ak0040'ın varyasyonu |
| ak0060 | Kara şimşek (elle) | Dört LED'i ayrı ayrı yöneterek gidip gelen bir desen kurabilme; her adımda tüm çıkışların durumunun yazılması gerektiğini açıklayabilme; tekrar eden satırların çoğalmasını bir problem olarak fark etme | const int (ak0050), çoklu çıkış (ak0040) | dört LED devresi | Arduino Uno kartı, USB kablosu, 4 LED, 4 adet 220 ohm direnç, breadboard, 8 jumper kablo | çekirdek | D:\ArduinoProjeleri\002Arduino\004karaSimsek (pin ve desen düzeltmeli) |

## Kara Kutu Takip Tablosu

Kara kutu sadece işaretlenmez, **taksitle ödenir**: ders başına tek kutu, o dersin
`.ino` dosyasının sonundaki `MERAK KÖŞESİ`nde 3-6 satırla gerçekten açıklanır. Doktrin
`CLAUDE.md`'de.

**Rotasyon sırası:** `void` → `OUTPUT` → (başa dön). `{ }` ve `;` rotasyona girmez,
ak0020'de KAVRAM içinde kapandı.

**Rotasyon freni:** bir kutu 3 tur köşeye konu olduysa `emekli` sayılır, açılış dersine
kadar bir daha yazılmaz.

**Yük freni:** dersin kendi yeni fikri ağırsa köşe atlanır, rotasyon kaymaz — atlanan
ders aşağıdaki günlükte görünür. ak0010 (ilk ders, aynı anda 11 yeni şey) ve ak0020
(ilk devre kurulumu: LED yönü, direnç, breadboard, GND) bu yüzden köşesiz. Rotasyon
ak0030'da başladı. ak0040 = `OUTPUT` (1. tur), ak0050 = `void` (2. tur). ak0060 yük freniyle atlandı (30 satırlık desen dersi); rotasyon kaymadı, sıradaki kutu `OUTPUT` (2. tur) ak0070'te kullanılacak.

| kara kutu | ilk göründüğü ders | açılacağı yer | tur / emekli | Merak Köşesi günlüğü | not |
|-----------|---------------------|----------------|----------------|----------------------|-----|
| `void` | ak0010 | "fonksiyon" konusu — temel düzeyin ilerisinde, numarası o tur belirlenecek | 2 tur | ak0030: setup ve loop birer "iş listesi", void listenin adının önünde "geriye bir sonuç vermeyecek" der; ak0050: `const int` ile aynı yerde durur — int "bu bir sayı" derken void "geriye bir şey gelmez" der (2. tur, yeni açı) | rotasyonda |
| `OUTPUT` | ak0010 | buton dersi (ünite 2), INPUT ile birlikte | 1 tur | ak0040: pinMode satırında pine ne iş yapacağını söylersin; OUTPUT = bu pin dışarı elektrik verecek. Görev bir kez seçildiği için satır setup'ta durur | rotasyonda |
| `{ }` | ak0010 | ak0020 (açıldı) | rotasyon dışı | — | ak0020'de KAVRAM'da açıldı, kapandı |
| `;` | ak0010 | ak0020 (açıldı) | rotasyon dışı | — | ak0020'de KAVRAM'da açıldı, kapandı |

**Atlanan dersler (yük freni):** ak0010, ak0020, ak0060.

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
