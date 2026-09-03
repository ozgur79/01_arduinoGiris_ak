# Backlog

- **Kazanım id bölünmesi (Özgür elle yapacak, küçük):** `cpp.pinmode-digitalwrite`
  ikiye ayrılacak → `cpp.pinmode` + `cpp.digitalwrite`. Sebep: Deneyap Mini v2'de
  dahili LED dersi `pinMode` kullanıyor ama `digitalWrite` kullanmıyor
  (`neopixelWrite`), yani ikisi ayrı derslerde ilk kez geçiyor. Uno'da hep birlikte
  geldikleri için tek id yazılmıştı. Dokunulacak yerler: `kazanimlar.md` (bir satır
  iki olur), `ak0010_dahiliLed/ders.md` ve `ak0020_hariciLed/ders.md` frontmatter'
  larındaki `kazanimlar:` listeleri. Şu an iki ders var, maliyeti sıfır; ders
  sayısı arttıkça büyür.

- ak0030_hizliLed turu için Özgür/Ortak'tan komut bekleniyor — arşiv klasörü yok,
  ak0020'nin devresi aynen kullanılacak. **Tek yeni fikir EŞİK, hız değil:** "delay
  değiştirilebilir" ak0010'un SEN YAP'ında zaten öğretiliyor, ders o hâliyle boş kalır.
  Yeni fikir sınırın kendisi — ne kadar hızlandırırsan hızlandır gözün ayırt edemediği
  bir yer var. Eşik değerini ak yazmaz, öğrenci bulur.
