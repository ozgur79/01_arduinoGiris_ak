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
Deneyap Mini v2'de gelmiyor sanılıyordu: dahili RGB LED dersinin (dk0010) `pinMode`
kullandığı, eylemin ise `neopixelWrite` olduğu düşünülmüştü — yani `digitalWrite`'ın
ilk kez harici LED dersinde (dk0020) geçeceği varsayılmıştı.

**Düzeltme (2026-09-20):** Bu öncül yanlış çıktı — dk0010 kartta test edildi,
`pinMode(LED_BUILTIN, OUTPUT)` satırının LED üzerinde hiçbir etkisi olmadığı görüldü
(`neopixelWrite` pimi RMT üzerinden kendi ayarlıyor). Satır dk0010'dan tamamen
kaldırıldı (`01_deneyapGiris_dk@7051dcc`) — dk0010 artık `cpp.pinmode` kazanımını hiç
içermiyor. Deneyap tarafında `cpp.pinmode` ile `cpp.digitalwrite` aslında dk0020'de
**birlikte, ilk kez orada** öğretiliyor — tıpkı Arduino Uno'daki gibi. Bölünmüş id'ler
yine de korundu: geri birleştirmek zaten teslim edilmiş çok sayıda dersi (ak0010–ak0115,
dk0010–dk0040) etkiler, kazanım takibinin ayrı ayrı olması bir zarar getirmiyor. Bu,
bilinçli bir "değiştirme" kararı — id yapısı aynı kalıyor, yalnız üstteki tarihsel
gerekçenin dayandığı örnek artık geçersiz, güncel durum bu paragrafta.

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
| cpp.degisken | Değeri program çalışırken değişebilen bir isim (`int sayac = 0;`); `const int`'in tam tersi | ak0120 |
| cpp.atama | `sayac = sayac + 1;` matematiksel eşitlik değildir: eşittirin sağı önce hesaplanır, sonuç soldaki isme atanır | ak0120 |
| cpp.for | `for (başlangıç; koşul; artış) { }` ile sayma işinin üç parçası tek satırda toplanır; koşul doğru olduğu sürece blok tekrar çalışır | ak0130 |
| cpp.arttirma | `sayac++` / `sayac--`, `sayac = sayac + 1;` / `sayac = sayac - 1;`'in kısa yazılışıdır | ak0130 |
| cpp.while | `while (koşul) { }` ile `for`'un tek satırda topladığı üç parça (başlangıç, koşul, artış) yeniden ayrı ayrı yazılır; koşul doğru olduğu sürece blok tekrar çalışır | ak0150 |
| cpp.sonsuz_dongu | `while (true)` (ya da `while (1)`), koşulu hiç yanlış olmayan, kendiliğinden bitmeyen bir döngü kurar; `loop()`'un kendisi de böyle bir döngüdür | ak0155 |
| cpp.if | `if (koşul) { }` koşul doğruysa içindeki blok çalışır, yanlışsa atlanır (bu düzeyde `else` yok) | ak0160 |
| cpp.kalan | `%` (kalan) operatörü bir bölmenin kalanını verir; `sayac % 2` çift sayılarda 0, tek sayılarda 1 verir | ak0160 |
| cpp.karsilastirma | `==`, `!=` gibi karşılaştırma operatörleri iki değeri kıyaslayıp doğru/yanlış üretir; `<=` ak0130'da `for`'un koşulunda dolaylı kullanılmıştı, ak0160'ta `==`/`!=` ile adlandırılıp genişletildi | ak0130 (dolaylı, `<=`) / ak0160 (adlandırıldı) |
| cpp.random | `random(alt, ust)` kartın alt (dahil) ile ust (hariç) arasında rastgele bir sayı seçmesini sağlar; üst sınır asla gelmez | ak0165 |
| cpp.analogwrite | `analogWrite(pin, deger)` yalnız ~ işaretli pinlerde 0-255 arası bir değerle "arada" bir çıkış verir (PWM); `digitalWrite`'ın yalnız HIGH/LOW verebilmesinden farklıdır | ak0170 |
| cpp.ic_ice_for | Bir `for` döngüsünün gövdesine ikinci bir `for` döngüsü konabilir; dıştaki bir kez ilerlerken içteki baştan sona çalışır | ak0180 |
| cpp.digitalread | `digitalRead()` ile bir giriş pininin `HIGH` mi `LOW` mu olduğu okunur | dk0050 *(Deneyap — Ünite 2/`ak02xx` bu id'yi ak tarafında henüz üretmedi, dilim stratejisi gereği dk önce vardı)* |
| cpp.if-else | `if (...) { }` koşul doğruysa çalışır, `else { }` yanlışsa çalışır — karar dallanması | dk0050 *(Deneyap — bkz. yukarıdaki not)* |
| hw.buton-devre | Butonu breadboard üzerinde giriş pinine bağlama; basılı/basılı değil iki durumu `digitalRead` ile ayırt etme | dk0050 *(Deneyap — bkz. yukarıdaki not)* |
