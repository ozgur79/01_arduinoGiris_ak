# Meydan Okuma Kartları

Buradakiler **ders değil, kart.** Numaraları yok, sıraları yok, hiçbiri zorunlu değil.

## Bunlar ne işe yarar

Dersi erkenden bitirdin ve beklemek istemiyorsan buraya bak. Kartlar ana sıradaki
derslerden daha zordur ama **yeni bir şey öğretmezler** — zaten öğrendiğin bir aleti
daha zor bir işte kullandırırlar.

İşe yarar tarafı şu: bir aleti zor bir işte kullanmış olmak, o alette takılan bir
arkadaşına yardım edebilecek konuma getirir. Ana sırada bir ders önde olmak bunu vermez.

## Nasıl kullanılır

1. Kartın adında hangi dersten sonra çözülebileceği yazar.
2. O dersi bitirmediysen kartı açma — takılırsın, keyfi kaçar.
3. Kartlarda çözüm yoktur. Takılırsan aynı kartı çözmüş bir arkadaşına sor.

## Kart biçimi

Her kart tek bir `.md` dosyası, dört başlık:

```
# <kart adı>
**Ön koşul:** <hangi ders bitmiş olmalı>
## Görev
(ne yapılacak — kısa, net)
## Beklenen çıktı
(ekranda ya da devrede tam olarak ne görülecek)
## İpucu
(tek satır, cevabı vermeyen bir yön göstergesi)
```

## Şu an mevcut kartlar

- `yildizBaklava.md` — ak0182 (yıldız üçgenleri) sonrası. Düz + ters üçgeni üst
  üste koyup baklava (elmas) deseni çizme; boşluk döngüsü ister.
- `yildizIciBosUcgen.md` — ak0182 sonrası. Üçgenin sadece kenarlarını yıldız
  yapma; `else`/`||` henüz açılmadığı için onsuz bir yol aranması gerekir.

**Not (2026-09-28):** Eski `yildizUcgeni.md` kartı (düz üçgen) kaldırıldı — aynı
görev artık ana derste (`ak0182`) doğrudan öğretiliyor, kart olarak tekrar etmesine
gerek kalmadı. Kartlar artık ak0182'nin ÜSTÜNE, ana derste görülmeyen zor
desenlerle (boşluk döngüsü, kenar/köşe mantığı) devam ediyor.

**Sırada gelecekler** (ünite 1, seri port ve döngü dersleri üretildikçe):
1'den 50'ye beşerli satırlar · `while` sonrası — aynı desenler `while` ile ·
`if` ve `%` sonrası — TEK/ÇİFT yazdırma, 5'in katlarında "BOM" · rasgele sayı —
1-100 arası on sayı üret.
