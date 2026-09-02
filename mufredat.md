# Müfredat

Numaralandırma şeması: `ak<binler><yüzler><onlar+birler>` — binler = düzey (0 = temel),
yüzler = ünite/blok (0 = LED), onlar+birler = ders sırası.

## Ders Tablosu

| ak no | konu | kazanım | C++ önkoşulu | donanım önkoşulu | malzeme | öncelik | kaynak |
|-------|------|---------|----------------|---------------------|---------|---------|--------|
| ak0010 | Dahili LED'i yakıp söndür | setup bir kez, loop sürekli çalışır; dahili LED'i yakıp söndürebilme | yok | yok | Arduino Uno kartı | çekirdek | arsiv/001dahiliLed/001dahiliLed.ino |

## Kara Kutu Takip Tablosu

| kara kutu | ilk göründüğü ders | açıldığı ders |
|-----------|---------------------|----------------|
| void | ak0010 | belirlenmedi — "fonksiyon" konusunda açılacak, temel düzeyin ilerisinde |
| { } | ak0010 | ak0020 |
| ; | ak0010 | ak0020 |
| OUTPUT | ak0010 | ak0030 |

## Malzeme Gerekiyor (temel düzeye girmeyecek)
(boş — motor/servo, 7 segment, mesafe sensörü, buzzer gibi dersler envanter geldikçe buraya
düşülecek, temel düzeye eklenmeyecek)
