# Yıldız baklavası

**Ön koşul:** ak0182 (Yıldız üçgenleri: düz ve ters)

## Görev
Düz ve ters üçgeni üst üste koyarsan bir baklava (elmas) deseni çıkar. 5 satırlık
bir baklava çiz: önce büyüyen, sonra küçülen bir üçgen — ama bu kez her satırın
SOLUNDA doğru sayıda boşluk olmalı ki yıldızlar ortalanmış görünsün (ak0182'de
boşluk yoktu, üçgenler sola yaslıydı).

## Beklenen çıktı
Seri Monitör'de şöyle bir görüntü (yıldızlar ortalı):
```
    *
   ***
  *****
 *******
*********
 *******
  *****
   ***
    *
```

## İpucu
Her satırda İKİ şey saymalısın: kaç boşluk, kaç yıldız. Boşluk sayısı da satıra
göre değişir (üçgenin tersi gibi davranır) — üçüncü bir `for` (boşluk için)
gerekebilir, ana derste (ak0182) bu yoktu.
