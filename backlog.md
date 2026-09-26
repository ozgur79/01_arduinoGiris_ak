# Backlog

- **Karar 14 güncellendi (Özgür + Ortak, 2026-09-26): `ak0182` "yıldız üçgenleri"
  müfredata giriyor.** Düz üçgen ve ters üçgen ayrı ders değil, **tek** numaralı ders
  (`ak0182`) — iki ayrı ders olsaydı ak0180 ile birlikte art arda üç ekran dersi
  gelirdi. Ekran dersi, tek yeni fikir: içteki döngünün sınırı dıştaki döngüye bağlı
  (`sutun <= satir`). Tasarım ve Yol Haritası (Ev tarafında) güncellendi. `meydanOkuma/
  yildizUcgeni.md` şimdilik yerinde kalıyor — ak0182 üretilirken zor desenlere
  (baklava, içi boş üçgen) dönüştürülecek. **ak0182'nin iş emri Paket 5 kapandıktan
  sonra gelecek, şimdi üretilmiyor.**
- **ak0165/ak0170/ak0180 kartta test edildi, onaylandı (2026-09-26).** Ortak'ın iş emri
  (`zihinEv/🏰 300-Projects/arduinoMufredat/is-emri-ak-unite1-paket4.md`) üzerine
  üretildi: `random()` (ak0165, yeni ders, ak0140 devresi), nefes alan LED / `analogWrite`
  (ak0170, kaynaktaki 3 hata düzeltildi), iç içe `for` / yıldız karesi (ak0180,
  `Serial.print`/`println`'in bilinçli istisnası). `randomSeed`/`analogRead` ek kutu
  olarak ak0165'e girdi (analog giriş ünitesinde açılacak). Kart testinde ak0165'te
  iki sorun çıktı, düzeltildi: (1) zar atışları Seri Monitör açılmadan önce yazılıp
  kayboluyordu → `Serial.begin`'den sonra `delay(2500);` eklendi; (2) pin 8-11 geçişleri
  takip edilemiyordu → LED yanık süresi `delay(1500)`'e çıkarıldı, `delay(200)` karanlık
  ara eklendi; ayrıca ekrana "Zar: "/"LED: " etiketleri ve "neden hep aynı sıra geliyor"
  sorusu SEN YAP'a eklendi. ak0180'e SEN YAP 4 eklendi (5x5 karede tek hücreyi `&&`/`else`
  olmadan iç içe `if` ile değiştirme). meydanOkuma/'ya `yildizUcgeni.md` kartı eklendi.
  Ünite 1 Paket 4 kapandı.
- **ak0150/ak0155/ak0160 kartta test edildi, onaylandı (2026-09-26).** Ortak'ın iş emri
  (`zihinEv/🏰 300-Projects/arduinoMufredat/is-emri-ak-unite1-paket3.md`) üzerine
  üretildi: `while`, sonsuz döngü (`while(true)`, yeni ders), `if` + `%`. Kaynaklar
  `.ino` değil `arsiv\kabaMüfredat.docx` madde 023/024. Test sonrası ak0150'nin
  while bloğuna `Serial.println`'den sonra `delay(500);` eklendi (ak0130 ile aynı
  ritim, Özgür istedi) — `.ino`, `cozumler/` ve `ders.md` §5'te. ak0150'nin Merak
  Köşesi'ndeki `int` taşması denemesinin süresi **henüz ölçülmedi**; "kartta
  doğrulanacak" ifadesi olduğu gibi bırakıldı. Ünite 1 Paket 3 kapandı.
- **ak0120/ak0130/ak0140 kartta test edildi, onaylandı (2026-09-26).** Ortak'ın iş emri
  (`zihinEv/🏰 300-Projects/arduinoMufredat/is-emri-ak-unite1-paket2.md`) üzerine
  üretildi: Sayaç (değişken/atama), `for`, Kara şimşek-`for`. Kaynaklar arşive
  kopyalandı (`002for1den100e`, `004karaSimsekIleri`; `009ak120ham` zaten arşivdeydi).
  ak0140'ta kaynağın desen hatası (uç LED'lerin art arda iki kez yanması) kod okunarak
  tespit edilip düzeltildi, kartta doğrulandı — gerekçe `ders.md` §5'te. Ünite 1
  Paket 2 kapandı.
- **ak0110/ak0115 kartta test edildi, onaylandı (2026-09-18).** Ünite 1 Paket 1 kapandı.
- **Karar verildi (Özgür, 2026-09-06): ak geriye dönük güncellenmeyecek.** AI Yoldaşı
  doktrini ak0060'tan itibaren geçerli; ak0010-ak0050'nin §8'leri eski hâliyle kalıyor.
  Eksik parçalar o dersler **dk'ya porte edilirken dk tarafında** eklenecek.
- **dk portunda uyarlanacak — "arkadaşınla karşılaştır" ifadesi** (ak0030 SEN YAP 3,
  ak0040 AI promptları). Evde arkadaş yok.
- **dk portunda değişecek — seri hız.** ak'de 9600, dk'de 115200 (Özgür teyit etti).
- **Açık (ayrı tur):** Deneyap Atölyem'de öğretmenin yokluğu — kararlar alındı
  (`zihinEv/🏰 300-Projects/deneyapAtolyem/AI-Yoldasi-Kararlari.md`), Alfred'e gidecek
  metin hazır (`Alfred-Mesaji-2026-09-06.md`), **kanal kapalı**. Arda'yla buluşmada
  açılacak; kanal açılınca önce güncel portal çekilecek (Kurallar.md).
- **`meydanOkuma/` boş.** Kartlar ünite 1 dersleri üretildikçe eklenecek.
