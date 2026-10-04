# İçi boş üçgen

**Ön koşul:** ak0182 (Yıldız üçgenleri: düz ve ters)

## Görev
ak0182'deki düz üçgende yıldızlar içi doluydu (her hücre yıldız). Bu kartta
sadece KENARLAR yıldız olsun, ortası boşluk olsun:
```
*
* *
*   *
*     *
*********
```
(Sadece ilk sütun, son sütun ve en alttaki satır yıldız; aradaki her şey boşluk.)

## Beklenen çıktı
Yukarıdaki gibi, kenarları yıldız, ortası boş bir üçgen — 5 satır.

## İpucu
Bir hücrenin "kenar" olup olmadığını sormak için normalde `||` ("veya") kullanılır,
ama `||` henüz açılmadı (Ünite 2'de gelecek) — onsuz dene: her kenar koşulunu AYRI
bir `if` yapabilir misin (ak0197'deki iki ayrı `if` gibi)? Alt köşedeki tam satır
ayrı bir durum, onu da düşün. Takılırsan bu kart seni bekletebilir, zorunlu değil.
