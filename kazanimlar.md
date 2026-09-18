# Kazanımlar

Her `ders.md` frontmatter'ındaki `kazanimlar:` listesi buradaki id'leri kullanır. Var
olan bir kavram tekrar kullanılıyorsa yeni id uydurulmaz, buradaki kayıt kullanılır.

**Bu dosya tek kaynaktır.** Deneyap tarafı (`dk`, `D:\Atolye\Deneyap\01_deneyapGiris_dk`)
buradan **okur**, kendi kopyasını açmaz. dk'nin ihtiyaç duyduğu ama burada olmayan bir
kazanım çıkarsa dk yeni id **önerir**, Özgür üzerinden buraya eklenir.

**`hw.` öneki neden algısal bir kazanımı da taşıyor (2026-09-06):** `hw.gorme-esigi`
donanıma değil göze ait bir gerçek. Yine de yeni bir önek (`fiz.`, `algi.`) açılmadı —
ak'de `hw.` fiilen "kod dışındaki fiziksel dünya" anlamında kullanılıyor (`hw.harici-led-devre`
de devre bilgisidir, board bilgisi değil). Tek kullanım için önek çoğaltmak takip yükü olurdu.
Bu kazanım board'a bağlı değildir, her kartta aynıdır — port sırasında dk'ye olduğu gibi geçer.

**İki id'nin ayrılma gerekçesi (2026-09-03):** `cpp.pinmode` ve `cpp.digitalwrite` önce
tek id'ydi (`cpp.pinmode-digitalwrite`), çünkü Arduino Uno'da ikisi hep birlikte geliyor.
Deneyap Mini v2'de gelmiyor: dahili RGB LED dersi `pinMode` kullanıyor ama eylem
`neopixelWrite`, yani `digitalWrite` ilk kez harici LED dersinde geçiyor. Tek id kalsaydı
bu fark port sırasında görünmezdi.

| id | tanım | ilk öğretildiği ders |
|----|-------|------------------------|
| cpp.setup-loop | `setup()` kart açılınca bir kez, `loop()` setup bitince sürekli baştan tekrar çalışır | ak0010 |
| cpp.delay | `delay()` ile parantez içindeki milisaniye kadar bekleme yapılır | ak0010 |
| cpp.pinmode | `pinMode()` ile bir pinin çıkış (`OUTPUT`) ya da giriş (`INPUT`) modu ayarlanır | ak0010 |
| cpp.digitalwrite | `digitalWrite()` ile bir çıkış pini `HIGH` (açık) ya da `LOW` (kapalı) yapılır | ak0010 |
| hw.dahili-led | Kartın üzerinde hazır bağlı, harici devre gerektirmeyen LED | ak0010 |
| cpp.blok-noktalivirgul | `{ }` bir kod bloğunun başlangıcını/bitişini gösterir, `;` bir komutun bittiğini gösterir | ak0020 |
| hw.harici-led-devre | LED'i breadboard üzerinde harici bir pime bağlama; LED'in yönü (uzun bacak +, kısa bacak −) ve direncin LED'i aşırı akımdan koruma görevi | ak0020 |
| hw.gorme-esigi | Yanıp sönme yeterince hızlanınca göz sönmeyi ayırt edemez, ışık sürekli yanıyormuş gibi görünür; sınırı koyan ışık kaynağı değil gözdür, eşik kişiden kişiye değişir | ak0030 |
| cpp.coklu-cikis | Aynı programda birden fazla çıkış pini, `pinMode` ve `digitalWrite` satırları ayrı ayrı yazılarak birbirinden bağımsız yönetilir | ak0040 |
| hw.coklu-led | Birden fazla LED'i aynı devrede, her birinin kendi pini ve kendi direnci olacak şekilde bağlama | ak0040 |
| cpp.const-int | `const int isim = sayi;` ile bir sayıya isim verilir; `const` o ismin değerinin bir daha değişmeyeceğini söyler. İsim, kodu okuyan insan içindir — derleme sırasında sayıyla değiştirilir | ak0050 |
| cpp.kod-tekrari | Birbirinin neredeyse aynısı olan satırlar çoğalıyorsa kodun kısaltılabileceğini fark etme; tekrarın kendisini bir problem olarak görme | ak0060 |
| cpp.serial-begin | `Serial.begin(9600)` ile kartın bilgisayara yazı göndereceği seri bağlantı başlatılır; kart ve Seri Monitör aynı hızı kullanır | ak0110 |
| cpp.serial-println | `Serial.println(...)` ile tırnak içindeki yazı Seri Monitör'e gönderilir ve sonraki yazı için yeni satıra geçilir | ak0110 |
| hw.seri-port | Arduino Uno'da seri port bilgisayarla yazı alışverişi yapar; pin 0 ve 1 bu iş için ayrılmıştır | ak0110 |
| cpp.digitalread | `digitalRead()` ile bir giriş pininin `HIGH` mi `LOW` mu olduğu okunur | dk0050 *(Deneyap — Ünite 2/`ak02xx` bu id'yi ak tarafında henüz üretmedi, dilim stratejisi gereği dk önce vardı)* |
| cpp.if-else | `if (...) { }` koşul doğruysa çalışır, `else { }` yanlışsa çalışır — karar dallanması | dk0050 *(Deneyap — bkz. yukarıdaki not)* |
| hw.buton-devre | Butonu breadboard üzerinde giriş pinine bağlama; basılı/basılı değil iki durumu `digitalRead` ile ayırt etme | dk0050 *(Deneyap — bkz. yukarıdaki not)* |
