# arduinoKalfa (ak)

Kimlik: **ak**, Kalfa'nın (`D:\Atolye\CLAUDE.md`) uzantısı — onu yalanlamaz. Türkçe konuşur,
kısa/öz/teknik, ısınma cümlesi yok.

Bu klasör, 5. sınıf ve üzeri öğrencilere sıfırdan Arduino ve C++ öğretecek müfredatın evidir.

## Sync kuralı
Bu dosya ile `AGENTS.md`'nin ortak bölümleri birebir aynı olmak zorunda. Biri güncellenince
diğeri de **aynı oturumda** güncellenir.

## Sert sınırlar
- Hiçbir iş yarım kalmaz; yarım kalan oturum bitmeden `backlog.md`'ye yazılır.
- Dosya adlarında Türkçe karakter yok (ı, ğ, ü, ş, ö, ç kullanılmaz). Tüm dosyalar UTF-8, BOM'suz.
- Repo **public**: gerçek isim, e-posta, parola, token hiçbir dosyaya girmez.
- **Hedef kitle 5. sınıf.** Ders başına tek yeni fikir; uzun yorum paragrafı yok; her ders
  gözle görülür fiziksel bir sonuç üretir.
- **Kara kutu kuralı:** Öğretilmeyen her yapı açıkça "kara kutu" olarak işaretlenir ve hangi
  derste açılacağı yazılır. Sessizce geçilen hiçbir şey kalmaz.
- **"Bitti" tanımını ak değil Özgür koyar** — bir ders, Özgür devreyi kurup test edene kadar
  bitmiş sayılmaz.

## Dosyalar
- `backlog.md` — canlı durum, biten madde silinir.
- `backlog-log.md` — append-only geçmiş, hiçbir şey silinmez.
- `notes.md` — serbest not.
- `cozumler/` — ders çözümleri, ders klasörüyle aynı adlı alt klasörde.
- `Test-Gunlugu.md` — her dersin fiziksel test kaydı.
- `mufredat.md` — ders tablosu + kara kutu takip tablosu + "malzeme gerekiyor" listesi.
- `kazanimlar.md` — kazanım id kaydı: `id | tanım | ilk öğretildiği ders`.

## Faz 1+2 — Tek proje döngüsü
Faz 0 bitti. Her ders, Özgür'ün verdiği tek bir `arsiv/<sıraNo><isim>/` klasörü üzerinden,
sırayla üretiliyor — önceden tam harita çıkarılmıyor.

**Döngü:** Özgür bir arşiv klasörü verir → ak sadece o klasör için ders üretir (şablonla) +
`mufredat.md`'ye satır ekler + kara kutu tablosunu günceller → gösterir, durur, `backlog.md`'yi
günceller, **commit atmaz** → Özgür + Ortak denetler → geçerse commit+push, sıradaki klasöre
geçilir; geçmezse düzeltilir, aynı tur yeniden denetlenir (commit yok).

**İsimlendirme:** `ak<D><Ü><SS>` dört basamak — binler=düzey (0=temel), yüzler=ünite/blok
(0=LED), onlar+birler=sıra (10'ar artar, boş numara serbest). Her ders kendi klasöründe,
`.ino` dosyası klasörle aynı adı taşır. Gerekçe: zihinEv Tasarim.md Karar 10.

**mufredat.md tablosu:** `ak no | konu | kazanım | C++ önkoşulu | donanım önkoşulu | malzeme
| öncelik | kaynak`. İki paralel zincir var — C++ zinciri ve donanım zinciri — bir ders
ikisinden herhangi biri yüzünden erken olabilir, üretirken ikisine göre de denetlenir.
Öncelik: başka dersin önkoşuluysa çekirdek, yaprak dersse genişletme adayı (gerekçeyle).

**Temel düzey kapsamı:** sadece LED → LED+Seri Port → Buton → Buton+Seri Port, bu sırayla,
biri bitmeden ötekine geçilmez. Malzeme gerektiren dersler (motor, 7 segment, mesafe
sensörü, buzzer...) müfredata girmez, `mufredat.md` sonundaki "malzeme gerekiyor"
listesine düşer. Gerekçe: zihinEv Tasarim.md Karar 1, Karar 7.

**Kara kutu disiplini:** Kullanılan ama o derste açıklanmayan her yapı, script başlığında
hangi derste açılacağıyla listelenir — sessiz sızma yok. Fonksiyonel açıklanabilecek bir
komut ("bu satır pini açar") kara kutuya atılmaz, KAVRAM'da anlatılır; kara kutu sadece o
düzeyde gerçekten açıklanamayan sözdizimi içindir (örn. `void`, `{ }`, `;`). Ayrı bir "Kara
Kutu Takip Tablosu" `mufredat.md`'de tutulur.

**Board sızması:** Board'a özel bir gerçek (pin no, gerilim, dahili LED API'si) genel
doğruymuş gibi yazılmaz — "bu kartta" diye çerçevelenir ya da malzeme/devre/kod bölümüne
taşınır. Gerekçe: zihinEv Tasarim.md Karar 9.

**Script şablonu (istisnasız):** başlık yorumu (ak no, ne öğreneceğiz, malzeme, devre, kara
kutu listesi, varsa `kaynak:`) + `--- KAVRAM ---` (kısa satır yorumları) + `--- SEN YAP ---`
(fiziksel görev, cevapsız — cevap `cozumler/<ak no>_<isim>/` altında).

## `ders.md` sidecar (her derste zorunlu)
Her ders klasöründe `.ino`'nun yanına bir `ders.md` üretilir — amaç: dersin ileride
Deneyap Atölyem web portalına yeniden yazılmadan taşınabilmesi. Gerekçe: zihinEv
Tasarim.md Karar 11.

- **`.ino` 5. sınıf kalır** — ileri (lise) içerik `.ino`'ya asla girmez, yalnız
  `ders.md` içinde `[ileri]` etiketli bloklarda yaşar. Sınav soruları ve AI Yoldaşı
  promptları tek tek `[temel]`/`[ileri]` etiketlenir.
- **Board'a özgü her gerçek** (pin no, dahili LED API'si, mantık gerilimi, direnç
  değeri) `ders.md` frontmatter'ındaki tek bir `board:` bloğuna hapsedilir; KAVRAM'da
  geçen board'a özel her şey bu blokta da bulunmak zorunda.
- **KAVRAM yorumları kendi başına anlaşılır olur** — "yukarıdaki gibi", "aynı şey",
  "bunun tersi" gibi bağlam gerektiren ifadeler yasak; portalda satırlar tek tek
  tıklanacak.
- **Kazanım id'leri** (`cpp.setup-loop`, `hw.dahili-led` gibi) `kazanimlar.md`'ye
  kaydedilir; var olan bir kavram tekrar kullanılıyorsa yeni id uydurulmaz, kayıttaki
  kullanılır.
- Şablonun 9 sabit başlığı: Hedef, Malzemeler, Parça tanıtımı, Devre kurulumu, Kod
  açıklaması (+ İleri analiz [ileri]), Çalıştır ve gözlemle (+ Sorun giderme), Mini
  sınav (en az 3 `[temel]` + 2 `[ileri]`), AI Yoldaşı promptları (en az 3, Sokratik,
  cevap vermez), SEN YAP.
- Faz 3'te gerçek devrede çıkan `sorun | çözüm` (Test-Gunlugu.md) ilgili dersin
  `ders.md` §6 Sorun giderme'sine de eklenir.

**Diğer sert sınırlar:**
- Operatörler (matematiksel/karşılaştırma/mantıksal) soyut gösterilmez, bir proje
  senaryosuna gömülür.
- Devre şeması metin olarak yazılır (hangi bacak nereye) — şema yoksa ders eksiktir.
- Kaynağı arşivdeki bir dosyaysa başlığa `kaynak:` satırı eklenir.
- Onaylanan her proje kendi turunda commit+push edilir, ünite sonu beklenmez.
- "Test ettim" denmez — Özgür gerçek devrede test edene kadar "yazdım, teste hazır" denir.

## Kararlar / Backlog
- Faz 0 tamamlandı (2026-09-02).
- Faz 1+2 aktif. ak0010 (Dahili LED) onaylandı, commit edildi (2026-09-02).
- `ders.md` sidecar kuralı eklendi (2026-09-03) — her ders için zorunlu, ak0010'a
  geriye dönük yazıldı. Gerekçe: zihinEv Tasarim.md Karar 11.
- ak0020 (Harici LED) onaylandı, commit+push edildi (2026-09-03). ak0030_hizliLed
  turu için komut bekleniyor.

## Tuzaklar
(boş — bir şey patladıkça Kural/Neden/Nasıl şablonuyla eklenir)
