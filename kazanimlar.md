# Kazanımlar

Her `ders.md` frontmatter'ındaki `kazanimlar:` listesi buradaki id'leri kullanır. Var
olan bir kavram tekrar kullanılıyorsa yeni id uydurulmaz, buradaki kayıt kullanılır.

**Bu dosya tek kaynaktır.** Deneyap tarafı (`dk`, `D:\Atolye\Deneyap\01_deneyapGiris_dk`)
buradan **okur**, kendi kopyasını açmaz. dk'nin ihtiyaç duyduğu ama burada olmayan bir
kazanım çıkarsa dk yeni id **önerir**, Özgür üzerinden buraya eklenir.

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
