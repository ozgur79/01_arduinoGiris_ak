# Backlog

- **Ünite 3 Paket 1 üretildi, teste hazır, COMMİT YOK (2026-09-30).** Ortak'ın iş emri
  (`zihinEv/🏰 300-Projects/arduinoMufredat/is-emri-ak-unite3-paket1.md`): ak0310 (sayaç
  kaçıyor, 046→047), ak0320 (kenar tetikleme), ak0330 (butonla binary sayıcı, debounce),
  ak0340 (bastı/bıraktı, `else if`). Devre aynı. Sekiz sketch `arduino-cli compile
  --fqbn arduino:avr:uno` ile derlendi (kartta çalıştırılmadı).
  - Arşive kopyalandı: 029, 031, 045, 046, 047, 048, 023, 024 (030 zaten vardı).
    **031 kaynak olarak kullanılmadı** (mantık bozuk + `#define` pin 0/1 hatası); 029, 048 ve
    023/024 de doğrudan taşınmadı (048 yalnız ak0310 SEN YAP 4'e fikir oldu).
  - Kararlar: ak0310'un ana kodu acı veren 046 hâli, çare (`while { }` + `delay(20)`) SEN YAP 2
    ve çözümde. ak0320 ana kodu `&&`'li hâl (`!=` ak0160'ta zaten tanıtılmıştı, SEN YAP 4'te ikinci
    yol) ve **`delay` yok** — sıçrama ak0330'da; ders.md bir basışta bazen 2 artış olabileceğini
    hata değil diye söylüyor. ak0330'da LED yalnız kenar anında güncelleniyor (ak0220'deki
    "her tur söndür-yak" tuzağından kaçınmak için). ak0340 bayraksız (`bool`/`!` açılmadı);
    `switch` adı bile geçmedi.
  - **Doğrulanmamış iddialar:** ak0340'ta 030'un bayraklarının gereksiz olduğu (kod okunarak);
    sıçramanın ak0320/ak0330'da görünüp görünmeyeceği; ak0310'da sayacın kaça çıkacağı (bilerek
    yazılmadı).
  - Kayıtlar: `mufredat.md` (4 satır + Ünite 3 Paket 1 notu), `kazanimlar.md` (`cpp.loop_hizi`,
    `cpp.kenar_tetikleme`, `cpp.debounce`, `cpp.else_if`), `Test-Gunlugu.md`, `README.md`.
  - **Paket 2'ye:** `bool`, `!`, toggle, uzun basma, `millis()` 2. tur, `break`/`continue`,
    Ünite 3 kapanışı (`switch` sonrası).
- **Ünite 2 (Paket 1 kalanı + Paket 2) üretildi, teste hazır, COMMİT YOK (2026-09-30).**
  Ortak'ın iş emri (`zihinEv/🏰 300-Projects/arduinoMufredat/is-emri-ak-unite2-paket2.md`,
  Paket 1 iş emriyle birlikte) üzerine, Özgür'ün kararıyla toplu üretim: ak0182/0197/0199/
  0210/0215 test edilmeden devam edildi, hepsi topluca test edilecek. Commit'ler Özgür test
  edince **paket paket, ayrı** atılacak (Ünite 1 Paket 6 / Ünite 2 Paket 1 / Ünite 2 Paket 2).
  - İş emrindeki tespit eskimişti: `cozumler/ak0210_butonOku/` zaten vardı; ak0220/ak0230
    gerçekten yoktu. Üretilenler: ak0220 (`if`/`else`), ak0230 (`&&`), ak0240 (zamanlı tepki),
    ak0250 (yak/söndür), ak0260 (refleks oyunu, Ünite 2 kapanışı), ak0299 (bozuk kodu onar,
    Ünite 2). Hepsi `.ino` + `ders.md` + `cozumler/` ile; 16 sketch (ana + çözüm) `arduino-cli
    compile --fqbn arduino:avr:uno` ile **derlendi** (yalnız derleme — kartta çalıştırılmadı).
  - Arşive kopyalandı: `020GriButonLed`, `021YesilButonLed`, `022MaviButonKolay`.
  - Kaynak hataları taşınmadı: 022Kolay SÖNDÜR pin 3 → pin 8; `while(...);` noktalı virgül →
    `{ }`; 022Zor `#define`+`pinMode(YAK, INPUT)` (pin 0/1) — 022Zor yalnız karşılaştırma;
    sihirli sayılar → `const int`; "ark" yorumu → "sıçrama" (asıl konu Ünite 3 debounce).
  - **ak0299 seçimi:** aday listeden 1 (`if (...);`), 2 (`=`/`==`) ve 3 (LED pini `INPUT`)
    alındı; üçünün teşhis yolu farklı (butonu okuyup kıyasla / değişken ile okumayı kıyasla /
    `if` içine mesaj yaz). Aday 4 (pull-down eksik) alınmadı: ak0210 SEN YAP 1 zaten öğretiyor
    ve Özgür'ün devreyi bilerek bozmasını gerektiriyor. Gerekçe `ders.md` frontmatter'ında.
  - **Doğrulanmamış iddialar** (kod okunarak yazıldı, Test-Gunlugu'nda işaretli): ak0250'de LED
    bırakınca yanar; ak0260'da erken basma davranışı; ak0299 bozuk3'te INPUT modunda LED'in
    soluk yanıp yanmadığı. ak0240'ta basılı tutma davranışı ders.md'de bilerek tahmin
    edilmedi, soru olarak bırakıldı.
  - ak0240'ın Merak Köşesi kara kutu değil "acı tohumu" (iş emri gereği, tek cümle:
    `millis()` ile Ünite 3'te çare). Diğer Ünite 2 dersleri köşesiz: rotasyonda aktif kutu yok.
  - `OUTPUT` kara kutusu ak0210'da gerçek açılışını yaptı, `mufredat.md` tablosunda kapandı.
  - `mufredat.md` (ak0210–ak0299 satırları — 0210/0215 önceden eksikti), `kazanimlar.md` (7 yeni
    id, 3 dk-notlu id güncellendi), `Test-Gunlugu.md`, `README.md` güncellendi.
- **Ünite 3'e devir:** `bool` · `!` · `else if` · kenar tetikleme · debounce · `millis()` 2. tur ·
  toggle. **`030butonBastiBirakti` Ünite 3 Paket 8'in kaynağı** (kenar tetikleme + `bool` + `!`
  + `else if`); arşivde duruyor, Ünite 2'ye alınmadı. Alınmayan diğer kaynaklar: `023SariButon`,
  `024kirmiziButon`, `029`, `031`, `045–048`.
- **Ünite 1 Paket 6 (kapanış) üretildi, teste hazır (2026-09-28).** Ortak'ın iş emri
  (`zihinEv/🏰 300-Projects/arduinoMufredat/is-emri-ak-unite1-paket6.md`) üzerine
  ak0182 (yıldız üçgenleri, düz+ters), ak0197 (`Serial.read`, klavyeden komut), ak0199
  (bozuk kodu onar, ünite kapanışı) üretildi. Bu paket kapanınca Ünite 1 biter.
  - ak0182: kaba müfredat §031'in ASIL hâli (üçgen) — ak0180'de kareye uyarlanmıştı,
    burada geri döndü. Ters üçgen `satir--` (dış döngü geri sayar) ile kuruldu; `6 -
    satir` iç sınırlı alternatif SEN YAP/[ileri]'de. Yeni kazanım id: `cpp.for_degisken_sinir`.
  - ak0197: kaynak `D:\ArduinoProjeleri\002Arduino\080bluetoothArd\080bluetoothArd.ino`
    → `arsiv\080bluetoothArd\` kopyalandı (Bluetooth taşınmadı). Kaynakta '0' yakıyor
    '1' söndürüyordu (isimle ters) → burada '1' yak/'0' söndür yapıldı. `while` →
    `if (Serial.available() > 0)` (daha az yeni şey). Yeni kazanım id: `cpp.serial_read`,
    `cpp.char`. **Doğrulanacak:** Seri Monitör "Yeni satır" modunda gönderilen `\n`'in
    iki `if` yapısında zararsız olduğu iddiası kartta test edilmedi (Test-Gunlugu.md'de
    işaretli).
  - ak0199: kaynak yok, ak kendi yazdı — üç kasıtlı hatalı kod (yanlış sınırlı `for`,
    artmayan `while`, ters `if`), yöntem `Serial.println` ile değişken izleme. Arduino
    IDE'nin klasör=isim kuralı yüzünden üç alt klasöre bölündü
    (`bozuk1_yanlisSinir/`, `bozuk2_artmayanSayac/`, `bozuk3_tersIf/`), gerekçe
    `ders.md`'de. Yeni kazanım id: `cpp.hata_ayiklama_seri`.
  - `meydanOkuma/yildizUcgeni.md` kaldırıldı (görevi ak0182'ye taşındı); yerine
    `yildizBaklava.md` (boşluk döngüsü) ve `yildizIciBosUcgen.md` (`else`/`||` henüz
    yok, onsuz aranacak) eklendi.
  - Ünite 1 kapanışında hâlâ kara kutu olan her şey `mufredat.md`'ye Ünite 2'ye devir
    listesi olarak işlendi (`void`, `OUTPUT`, `Serial ve noktalı yazım`, üç ek kutu).
  - Üçü de Merak Köşesi'nden yük freniyle muaf (üçü de zaten ağır dersler).
  - `.ino`/`ders.md` + `cozumler/` + `mufredat.md` + `kazanimlar.md` + Kara Kutu
    tablosu + `Test-Gunlugu.md` ("teste hazır") + `README.md` ("teste hazır")
    güncellendi. **Commit atılmadı** — Özgür kartta test edecek, Ortak denetleyecek.
- **ak0185/ak0190/ak0195 kartta test edildi, onaylandı (2026-09-28).** Ünite 1 Paket 5
  kapandı. Test-Gunlugu.md ve README.md "teste hazır" → "yayında" güncellendi.
- **Ortak denetimi sonrası iki düzeltme, ak0185/ak0190 (2026-09-26).**
  (1) ak0190'da basamak yönü tersti — en soldaki LED (pin 3) 1'ler basamağıydı,
  öğrenci soldan sağa okuyunca ikilik sayıyı ters görürdü. Eşleme çevrildi: pin 9
  (en sağ) = 1'ler, pin 6 = 2'ler, pin 5 = 4'ler, pin 3 (en sol) = 8'ler — onluk
  sayılardaki gibi birler basamağı sağda. `.ino`, `cozumler/`, `ders.md` (board.bit_sirasi,
  §4, §7 mini sınav) güncellendi. (2) ak0185'te acı yalnız anlatılmıştı, Karar 12
  gereği (acı çekilmeden öğretilmez) SEN YAP 1'e taşındı: öğrenci ak0140 kodunu
  ilkLed=3/sonLed=9 ile bu devreye kendisi yükleyip ritmin 4/7/8'de bozulduğunu
  görüyor, bozuk kod ayrıca şevkedilmedi (ak0140 zaten elinde). Ayrıca Özgür'ün kart
  testinde fark ettiği bir üçüncü şey düzeltildi: **jumper sayısı** — dirençler ortak
  GND hattına alınırsa LED başına ayrı GND jumper'ı gerekmez (4 LED = 5 jumper, 8
  değil). ak0185/ak0190'da 8→5, ak0195'te 4→3 (sıfırdan kuruluyorsa) yapıldı, devre
  kurulumu adımları "ortak GND hattı, tek jumper" diye netleştirildi. ak0195'e
  dokunulmadı (zaten temizdi, sadece jumper sayısı düzeltildi).
- **Ünite 1 Paket 5 üretildi, teste hazır (2026-09-26).** Ortak'ın iş emri
  (`zihinEv/🏰 300-Projects/arduinoMufredat/is-emri-ak-unite1-paket5.md`) üzerine
  ak0185 (dizi), ak0190 (binary sayıcı, harcama), ak0195 (`millis()` 1. tur) üretildi.
  Üçü de aynı devrede: 4 LED, pin 3/5/6/9 (ardışık değil — dizinin gerekçesi bu).
  Kaynaklar arşive kopyalandı (`005binarySayici`, `003ikiLed_saniyede1saniyede2`;
  `004karaSimsekIleri` zaten arşivdeydi). ak0190'da kaynağın üç hatası (pinMode ile
  LED söndürme, gölgelenen `i`, `else` kullanımı) düzeltildi, gerekçe `ders.md` §5'te.
  ak0195'te `unsigned long` ak0150'nin `int taşması`na bağlanarak tek cümleyle
  tanıtıldı (ek kutu, rotasyon dışı); LED durumu `!`/`else` olmadan `1 - durum` ile
  çevrildi; "butona basınca ne olur" sorusu Ünite 3'e köprü olarak bırakıldı.
  ak0185/ak0190/ak0195 Merak Köşesi'nden yük freniyle muaf (üçü de zaten ağır dersler).
  `.ino`/`ders.md` + `cozumler/` + `mufredat.md` + `kazanimlar.md` (cpp.dizi,
  cpp.dizi_indeks, cpp.millis, cpp.unsigned_long) + Kara Kutu tablosu güncellendi.
  **Commit atılmadı** (Paket 4'ten ayrı tutuldu) — Özgür kartta test edecek, Ortak
  denetleyecek. Test-Gunlugu.md'ye üçü için "teste hazır" satırı eklendi.
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
