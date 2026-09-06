# Backlog Log

Append-only. Hiçbir şey silinmez.

## 2026-09-02
- Kurulum (Faz 0) tamamlandı: CLAUDE.md, AGENTS.md, backlog.md, backlog-log.md, notes.md,
  cozumler/, Test-Gunlugu.md, .gitignore, git init, GitHub public repo.
- ak0010 (Dahili LED) onaylandı ve commit edildi: `ak0010_dahiliLed/`, çözüm
  `cozumler/ak0010_dahiliLed/`, mufredat.md ders + kara kutu tablosu. Ortak'ın
  düzeltmesiyle dört basamaklı numaralandırmaya geçildi ve kara kutu listesi
  `void`/`{ }`/`;`/`OUTPUT`'a daraltıldı.

## 2026-09-03
- `ders.md` sidecar kuralı (Karar 11) yürürlüğe girdi: CLAUDE.md/AGENTS.md güncellendi,
  `kazanimlar.md` açıldı, ak0010'un `ders.md`'si geriye dönük yazıldı.
- ak0020 (Harici LED) üretildi ve commit edildi (564c6f9).
- **Ortak'ın denetimi — üç düzeltme.** Cross-session mesaj kanalı tıkalı olduğu için
  (mesajlar alıcı tarafta onay kuyruğunda takıldı, iki kez) düzeltmeleri Özgür'ün
  izniyle Ortak doğrudan uyguladı:
  1. `OUTPUT` kara kutusunun açılacağı ders `ak0030` değil, **buton dersi (ünite 2)** —
     OUTPUT'un içeriği ancak INPUT'la karşılaştırılınca anlaşılır, ak0030 ise tek
     fikirli bir keşif dersi. (ak0010.ino, ak0020.ino, mufredat.md)
  2. ak0020 SEN YAP 2. maddesi değişti: "delay sürelerini değiştir" hem ak0010'un SEN
     YAP 1'inin kopyasıydı hem ak0030'un konusuna giriyordu. Yerine "LED'i pin 8'den
     pin 9'a taşı, kodda neyi değiştirmen gerekiyor" — kod ile devrenin birlikte
     tutması gerektiğini öğretiyor. (.ino, ders.md §9, cozumler/)
  3. ders.md §6'da `delay(500)` yazıyordu, derste `delay(1000)` var — düzeltildi.
- **Kazanım id bölünmesi yapıldı:** `cpp.pinmode-digitalwrite` → `cpp.pinmode` +
  `cpp.digitalwrite`. Uno'da ikisi hep birlikte geldiği için tek id yazılmıştı; Deneyap
  Mini v2'de dahili RGB LED dersi `pinMode` kullanıyor ama eylem `neopixelWrite`, yani
  `digitalWrite` ilk kez harici LED dersinde geçiyor. Tek id kalsaydı bu fark port
  sırasında hiç görünmezdi. Dokunulan yerler: `kazanimlar.md` (bir satır iki oldu,
  gerekçe dosyaya yazıldı), `ak0010_dahiliLed/ders.md` ve `ak0020_hariciLed/ders.md`
  frontmatter'ları. Ortak uyguladı, Özgür'ün isteğiyle.
- **Ortak'tan iki kural düzeltmesi (ak'nin hatası değil):** Karar 11'in §5 kuralı fazla
  katıydı, "birebir aynı" yerine "her kod satırını kapsayan, `.ino` yorumuyla
  çelişmeyen" oldu — ak'nin uygulaması doğruydu, dosyalar değişmedi. Karar 12'de
  ak0030'un tek yeni fikri "hız" yerine **"eşik"** olarak yeniden tanımlandı.

## 2026-09-06
- **ck'nin Merak Köşesi doktrini ak'ye taşındı.** Ortak iki müfredatı karşılaştırdı;
  ak'nin kara kutuları sadece *listeleniyordu*, hiç açılmıyordu (`void` ve `OUTPUT`
  iki derstir başlıkta "sonra açacağız" diye duruyordu, hiçbir yerde tek kelime
  açıklanmamıştı). ck bu sorunu dört turda çözmüştü.
  - Özgür AskUserQuestion ile üç somut format arasından **`.ino` sonu**nu seçti
    (`ders.md`'de ayrı bölüm ve iki yerde birden seçenekleri elendi).
  - Beraberinde gelenler: ders başına tek kutu / 3-6 satır ölçüsü, üç adım (soru +
    şimdilik geçerli işlevsel cevap + açılış yeri), rotasyon freni (3 tur → emekli),
    yük freni (ders yüklüyse atla, rotasyon kaymaz), sabit çerçeve kapanış satırı.
  - **Doktrin çatışması çözüldü:** ak'nin eski kuralı "kara kutu, o düzeyde gerçekten
    açıklanamayan sözdizimi içindir" diyordu; ck'nin bulgusu ise kutuya *şimdilik
    geçerli işlevsel* cevap verilebileceği. Kural yeniden yazıldı: kara kutu **listesi**
    ders içinde anlatılamayacak sözdizimi içindir, ama listedeki kutu Merak Köşesi'nde
    ödenir. (CLAUDE.md + AGENTS.md)
  - Geriye dönük: ak0010 ve ak0020'ye sabit çerçeve kapanış satırı eklendi. İkisi de
    **yük freniyle köşesiz** bırakıldı — ak0010 aynı anda 11 yeni şey taşıyor, ak0020
    ilk devre kurulumu (LED yönü, direnç, breadboard, GND). Rotasyon ak0030'da başladı.
- **`README.md` açıldı (ck'den alındı).** Öğrenciye dönük: nasıl kullanılır, kod
  içindeki dört bölüm, kara kutunun ne demek olduğu, numaralı ders sırası + durum.
  Öğrencinin repo'yu klonlayıp kendi hızında ilerlemesinin altyapısı.
- **ck'nin `degerlendirme.md`'si alınmadı** (Özgür kararı): `ders.md` §7 mini sınavı
  (çoktan seçmeli, ipuçlu, `[temel]`/`[ileri]` etiketli) zaten o işi görüyor, ikinci
  soru seti bakım yükü olurdu.
- **`cozumler/` görünürlüğüne dokunulmadı** (Özgür kararı). Ortak repo public olduğu
  için SEN YAP'ın cevabının bir klasör ötede durduğunu tespit etti; mevcut hâl korundu.
- **ak0030 (LED'i hızlandır) üretildi, onay bekliyor.** Kaynak `arsiv/002ledYak`.
  **Klasör kendi belgeleriyle çelişiyor:** `.ino` tek LED (pin 6, `delay(500)`), yanındaki
  `Kavramlar.md`/`ScriptAciklamasi.md`/`OgrenciGorevi.md` ise iki LED (13 ve 6, zıt
  durumda) anlatıyor. ck'nin Karar 1'i uygulandı — konu koddan çıkarıldı: ak0020'ye
  göre tek gerçek fark bekleme süresinin yarıya inmesi. İki LED anlatan `.md`'ler
  `006ikiLed`'in, yani ak0040'ın işi. Arşivdeki pin 6 alınmadı, Karar 12 gereği pin 8'de
  kalındı.
  - Tek yeni fikir **eşik** (Karar 12): ne kadar hızlandırırsan hızlandır gözün sönmeyi
    seçemediği bir sınır var. Eşik değeri derste yazmıyor, öğrenci buluyor.
  - `cozumler/` dosyasına sayısal eşik **bilerek yazılmadı** — tek doğru sayı yok,
    eşik kişiden kişiye değişir. Çözüm dosyası yöntemi ve beklenen aralığı (10-25 ms)
    veriyor, "cevap"ı değil.
  - Yeni kazanım id: `hw.gorme-esigi`. `hw.` öneki altında tutuldu, gerekçe
    `kazanimlar.md`'de. Board'a bağlı değil, dk'ye olduğu gibi geçer.
- **Merak Köşesi 1. tur:** ak0030 = `void`. Sıradaki kutu `OUTPUT`.

## 2026-09-06 (ikinci tur)
- **Özgür'ün kaba müfredatı okundu** (`arsiv/kabaMüfredat.docx`, 510 satır) ve üç sorusu
  cevaplandı: `for` seri portla birlikte · `const int` iki LED'den sonra · kara şimşek
  önce elle sonra `for` ile. Üçü de Karar 12'yi değiştirdi → **Karar 14** yazıldı,
  Karar 12'ye revizyon notu düşüldü.
- **Ünite 0 yedi derse indi.** `for` ve PWM ünite 1'e taşındı (Özgür'ün kendi PWM kodu
  zaten `for` kullanıyor), binary sayıcı ünite 1'e (`if` + `%` gerekiyor). Ünite 0'ın
  kimliği tek cümle oldu: dijital çıkış, açık ya da kapalı. Kapanış: trafik lambası.
- **Ünite 1 "öğren/harca" ritmiyle kuruldu.** Tespit edilen risk: Özgür'ün dokümanında
  seri port bölümü 020-031 arası **on bir ders üst üste ekrana yazı yazdırıyor**;
  robotik atölyesine gelen 5. sınıf için motivasyon kaybı riski. Özgür riske katıldı.
  Çözüm: blok konuya göre değil alete göre kurulur — her yeni dil aleti önce ekranda
  öğrenilir (ekran aletin röntgeni: `for`'u LED'de öğretirsen `i` görünmez), hemen
  ardından LED'de harcanır. **Sert kural: üst üste en fazla iki ekran dersi.**
- **`meydanOkuma/` açıldı.** LED karşılığı olmayan alıştırmalar (yıldız desenleri,
  rasgele sayı, TEK/ÇİFT) ders değil kart oluyor; ana sıranın dışında, zorunlu değil.
  Asıl işlevi: dersi erken bitiren öğrencinin ana hattan koşup gitmesi yerine
  derinleşmesi — ve aynı aleti daha zor bir işte kullanmış olarak takılan arkadaşına
  yardım edebilecek konuma gelmesi. Kart yok, biçim ve ön koşul kuralı hazır.
- **Yeni pin kuralı:** pin 0/1 seri port (RX/TX) için, pin 13 dahili LED için rezerve;
  ünite 0 boyunca harici LED'ler 8-12. Bu kural hiçbir yerde yazmıyordu — ünite 1 seri
  port olduğu için ünite 0'da alt pinlere alışan öğrenci sebebi anlaşılmaz bir hatayla
  karşılaşırdı. Ayrıca: PWM yalnız `~` pinlerinde (Uno: 3,5,6,9,10,11), `A0` PWM değil.
- **Kaynak dosyalarda altı kod hatası tespit edildi** (Karar 14'te listeli): iki tanesi
  derlenmiyor (41 ve 42. Buton-Led), dördü derlenip yanlış çalışıyor (PWM'de `A0`,
  `#define YAK` ile `pinMode`, 51'de `millis()` ölçümü, `005binarySayici`'de `pinMode`/
  `digitalWrite` karışması, `004karaSimsekIleri`'de `i < 3`). Ders üretilirken düzeltilecek.
- **ak0030 Özgür'ün diline çevrildi.** SEN YAP "delay sayısını küçült" yerine Özgür'ün
  kendi hız merdiveni oldu: saniyede 1/5/10/25 kez (dokümandan) + 50 kez (eklendi).
  Dokümandaki "Hesaplama bana anlatılacak" notunun cevabı `[ileri]` bloğuna girdi:
  bir tam tur iki `delay()` sürer, `frekans = 1000 / (2 × delay)`, tersi
  `delay = 1000 / (2 × hedef hız)`. Mini sınava ters yön sorusu eklendi.
- **ak0040 (İki LED sırayla) üretildi, onay bekliyor.** Kaynak `arsiv/006ikiLed`; pin
  13/12 → 8/9 taşındı (pin 13 dahili LED çakışması). Yeni kazanımlar `cpp.coklu-cikis`
  ve `hw.coklu-led`. Merak Köşesi 1. tur `OUTPUT`. SEN YAP üç madde: birlikte yanma ·
  farklı süreler (300/900) · iki LED'i sürekli yanık bırakma. Üçüncüsünün gizli hedefi
  "loop boşsa LED neden sönmüyor?" sorusunu doğurmak — cevabı `[ileri]` bloğunda:
  `digitalWrite` bir çakma değil anahtardır. `[ileri]` ayrıca `delay()`'in bedelini
  gösterip `millis()`'e köprü kuruyor.
- **ak0030 ve ak0040 Özgür tarafından onaylandı (2026-09-06), commit+push edildi.**
  Test-Gunlugu.md'ye iki satır girdi; sorun bildirilmedi. Sıradaki ders ak0050
  (`const int`), Merak Köşesi sırası `void` (2. tur).
- **`meydanOkuma` isim kararı:** tüm müfredatlarda tek kelime. 5. sınıf için ayrı bir
  kelime (`bulmaca`) kullanma önerisi Özgür tarafından reddedildi.
- **Özgür'ün amaç beyanı (2026-09-06):** "Sürtünmeyi olabildiğince azaltarak öğrencilerin
  Deneyap Atölyem ile kendi kendine öğrenme süreçlerini desteklemek." Bundan sonra
  beraberlik bozucu ölçüt: iki tasarım pedagojik olarak eşitse, **evde tek başına
  çalışan çocuğun geçebileceği** seçilir. Bu ölçüt uygulanınca bugünkü işte bir çelişki
  bulundu (yukarıdaki "arkadaşınla karşılaştır" maddesi).

