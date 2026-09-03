# Müfredat

Numaralandırma şeması: `ak<binler><yüzler><onlar+birler>` — binler = düzey (0 = temel),
yüzler = ünite/blok (0 = LED), onlar+birler = ders sırası.

## Ders Tablosu

| ak no | konu | kazanım | C++ önkoşulu | donanım önkoşulu | malzeme | öncelik | kaynak |
|-------|------|---------|----------------|---------------------|---------|---------|--------|
| ak0010 | Dahili LED'i yakıp söndür | setup bir kez, loop sürekli çalışır; dahili LED'i yakıp söndürebilme | yok | yok | Arduino Uno kartı | çekirdek | arsiv/001dahiliLed/001dahiliLed.ino |
| ak0020 | Harici LED'i yakıp söndür | LED'i breadboard üzerinde harici bir pime bağlayıp yakıp söndürebilme; LED'in yönü olduğunu (uzun bacak +, kısa bacak −) ve direncin LED'i koruma görevini açıklayabilme | setup/loop, pinMode/digitalWrite, delay (ak0010) | dahili LED (ak0010) | Arduino Uno kartı, USB kablosu, 1 LED, 1 adet 220 ohm direnç, breadboard, 2 jumper kablo | çekirdek | arsiv/002ledYak/002ledYak.ino |

## Kara Kutu Takip Tablosu

| kara kutu | ilk göründüğü ders | açıldığı ders |
|-----------|---------------------|----------------|
| void | ak0010 | belirlenmedi — "fonksiyon" konusunda açılacak, temel düzeyin ilerisinde |
| { } | ak0010 | ak0020 |
| ; | ak0010 | ak0020 |
| OUTPUT | ak0010 | buton dersinde (ünite 2), INPUT ile birlikte — numarası o tur belirlenecek |

## Malzeme Gerekiyor (temel düzeye girmeyecek)
(boş — motor/servo, 7 segment, mesafe sensörü, buzzer gibi dersler envanter geldikçe buraya
düşülecek, temel düzeye eklenmeyecek)
