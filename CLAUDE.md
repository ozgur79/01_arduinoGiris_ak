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
- **Kara kutu kuralı:** Öğretilmeyen her yapı açıkça "kara kutu" olarak işaretlenir, hangi
  derste açılacağı yazılır **ve taksitle ödenir** — ders başına tek kutu, `.ino`'nun
  sonundaki `MERAK KÖŞESİ`nde. Sessizce geçilen hiçbir şey kalmaz, sonsuza kadar
  ertelenen de kalmaz. Ayrıntı: "Merak Köşesi doktrini".
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
- `README.md` — **öğrenciye dönük** giriş: nasıl kullanılır + numaralı ders sırası +
  durum sütunu. Öğrencinin repo'yu klonlayıp kendi hızında sırayla ilerlemesi buna
  bağlı; her yeni onaylanan derste güncellenir. (ck'den alındı, 2026-09-06.)
- `meydanOkuma/` — **ders değil, kart.** LED karşılığı olmayan programlama alıştırmaları
  (yıldız desenleri, rasgele sayı, TEK/ÇİFT...) ana sıraya girmez, buraya kart olarak
  düşer. Numarası yok, sırası yok, zorunlu değil. İşlevi: dersi erken bitiren öğrencinin
  ana hattan koşup gitmesi yerine **derinleşmesi** — ve aynı aleti daha zor bir işte
  kullanmış olarak takılan arkadaşına yardım edebilecek konuma gelmesi.
  Gerekçe: Tasarim.md Karar 14.

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

**Temel düzey kapsamı:** sadece LED → LED+Seri Port → Buton → Buton+Seri Port, bu sırayla.
Malzeme gerektiren dersler (motor, 7 segment, mesafe sensörü, buzzer...) müfredata girmez,
`mufredat.md` sonundaki "malzeme gerekiyor" listesine düşer. Gerekçe: zihinEv Tasarim.md
Karar 1, Karar 7.

**Ünite 0 (LED) yedi ders, döngüsüz.** `ak0010` dahili LED · `ak0020` harici LED ·
`ak0030` hız merdiveni (eşik) · `ak0040` iki LED sırayla · `ak0050` LED'e isim ver
(`const int`) · `ak0060` kara şimşek elle · `ak0070` trafik lambası (kapanış).
Ünite 0'ın kimliği tek cümle: **dijital çıkış, açık ya da kapalı.** `for` yok, PWM yok,
seri port yok. Gerekçe: Tasarim.md Karar 14.

`ak0060` (kara şimşek elle) rahatlama sözünü **açıkça vermek zorunda** — 28 satır
`digitalWrite` yazan öğrenci bunun normal olduğunu sanmamalı: "bu kodun çok kısa bir
hâli var, seri port ünitesinde öğreneceğiz."

**Ünite 1 (seri port + döngü): öğren / harca ritmi.** Blok konuya göre değil **alete
göre** kurulur. Her yeni dil aleti art arda iki derste yaşar: önce **ekranda öğrenilir**
(ekran aletin röntgenidir — `for`'u LED'de öğretirsen öğrenci sadece yanıp sönme görür,
`i`'yi göremez), hemen ardından **LED'de harcanır** (`for` → kara şimşek, `if`/`%` →
binary sayıcı, `analogWrite` → nefes alan LED).

**Sert kural: üst üste en fazla iki ekran dersi.** Üçüncüden önce mutlaka fiziksel bir
sonuç gelir. Bu Karar 1'i bozmaz: "LED bitmeden seri porta geçilmez" kuralı ünite 0
içindir; ünite 1'e girildikten sonra LED'e dönmek serbesttir.

**Pin kuralı:** pin **0 ve 1 seri port (RX/TX) için rezerve**, pin **13 dahili LED için**.
Harici LED'ler ünite 0 boyunca **8-12** arasında. Arşivdeki pin numaraları (13, 12, 6, 2)
körü körüne alınmaz — bu aralığa taşınır. PWM gereken dersler yalnız `~` işaretli
pinleri kullanır (Uno: 3, 5, 6, 9, 10, 11); `A0` PWM pini **değildir**.

**Seri hız board'a özgüdür (Özgür, 2026-09-06):** Arduino Uno'da **9600**, Deneyap
Kart'ta **115200**. Bu bir tercih değil board gerçeği — Karar 9 gereği `ders.md`'nin
`board:` bloğuna girer, KAVRAM'da genel doğruymuş gibi yazılmaz. `ak` derslerinde daima
9600 kullanılır (Arduino IDE'nin varsayılanı; öğrenci hiçbir ayar değiştirmeden çalışır,
sürtünme az). `dk` portunda 115200'e çevrilir ve `Donanim-Referans-DYMv2.md`'ye işlenir.
Bir müfredat içinde değer değişmez — öğrenci monitördeki hızı koddakiyle eşleştiremezse
anlamsız karakter görür ve sebebini bulamaz.

**Kara kutu disiplini:** Kullanılan ama o derste açıklanmayan her yapı, script başlığında
hangi derste açılacağıyla listelenir — sessiz sızma yok. Fonksiyonel açıklanabilecek bir
komut ("bu satır pini açar") kara kutu listesine girmez, KAVRAM'da anlatılır; kara kutu
listesi o düzeyde ders içinde anlatılamayacak sözdizimi içindir (örn. `void`, `{ }`, `;`,
`OUTPUT`). Ayrı bir "Kara Kutu Takip Tablosu" `mufredat.md`'de tutulur.

**Board sızması:** Board'a özel bir gerçek (pin no, gerilim, dahili LED API'si) genel
doğruymuş gibi yazılmaz — "bu kartta" diye çerçevelenir ya da malzeme/devre/kod bölümüne
taşınır. Gerekçe: zihinEv Tasarim.md Karar 9.

**Script şablonu (istisnasız), dört parça:** başlık yorumu (ak no, ne öğreneceğiz, malzeme,
devre, kara kutu listesi + sabit kapanış satırı, varsa `kaynak:`) + `--- KAVRAM ---` (kısa
satır yorumları) + `--- SEN YAP ---` (fiziksel görev, cevapsız — cevap
`cozumler/<ak no>_<isim>/` altında) + `--- MERAK KÖŞESİ ---` (aşağıdaki doktrin; ders
yüklüyse bu parça atlanır).

Kara kutu listesinin sonunda **sabit** bir kapanış satırı durur, dersten derse değişmez,
uzamaz: `Bunlara şimdilik dokunma, sırası gelince tek tek açacağız.` İşlevi, öğrencinin
"bunlar ne, ben mi eksik anladım?" diye takılmaması.

## Merak Köşesi doktrini (ck'den alındı, 2026-09-06)

Gerekçe: zihinEv Tasarim.md Karar 13. Karar 2 iptal değil, tamamlanıyor.

Kara kutuyu **işaretlemek yetmiyor, ödemek gerekiyor.** Söz verilip hiç açılmayan kutu
üç ders sonra okunmaz hâle geliyor. Kutu iki yere bölünür: dosyanın **başında** sabit
çerçeve notu (yukarıdaki kapanış satırı), **sonunda** tek kutuluk gerçek açıklama
(`// --- MERAK KÖŞESİ ---`). Bölünme bilerek: dersin kendi yeni fikri öğrencinin ilk
karşılaştığı şey olsun, kara kutu açıklaması onu ezmesin.

**Yeri:** dosyanın en sonu, `SEN YAP`'tan **sonra**. Öğrenci kodu çalıştırıp fiziksel
görevini yaptıktan sonra okur. `ders.md`'ye tekrar yazılmaz — `.ino` yorumu tek yerdir;
`ders.md` frontmatter'ına sadece `merak_kosesi:` alanı (hangi kutu, kaçıncı tur) girer.

- **Ders başına tek kutu.** Bir derste iki kutu birden açıklanmaz.
- **Üç adım:** (1) soru satırı — kutunun adını soruya çevir; (2) *şimdilik geçerli*
  cevap — kutunun gerçekte ne olduğu değil, **öğrencinin kendi kodunda ne yaptığı**;
  (3) açılış yeri.
- **Ölçü:** 3-6 satır. Aşarsan fazlası açılış dersine aittir, kes. Tek satıra da
  sıkıştırma — sıkıştırılmış isim listesi ck'de üç kez denendi, üçünde de kapalı bulundu.
- **Yeni terim getirmez.** Açıklamak için henüz öğretilmemiş bir terime ihtiyaç varsa
  o kutu bu derste anlatılamaz — sıradaki kutuya geç, `mufredat.md`'ye sebebini yaz.
- **Zincir kurar, izole tanım vermez.** Mümkünse bir önceki köşeye bağla.
- **Tekrar değil, yeni açı.** Aynı kutuya ikinci kez gelindiğinde günlüğe bakılır,
  üstüne yeni bir katman eklenir.
- **Rotasyon freni — üç tur, sonra emekli.** Bir kutu üç kez köşeye konu olduysa
  "yeterince tanıtıldı" sayılır, rotasyondan çıkar (tabloda `emekli`) ve açılış dersine
  kadar bir daha yazılmaz.
- **Yük freni — atlanabilir.** Dersin kendi yeni fikri ağırsa köşe atlanır; rotasyon
  kaymaz, tabloya "atlandı (ders yüklü)" yazılır. Öğrencinin zihni scriptin kendi
  içeriğiyle zaten doluysa kutu beklemeye alınır — kural budur, istisna değil.
  (ak0010 ve ak0020 bu yüzden köşesiz; rotasyon ak0030'da başladı.)
- **Sınanabilir, ama sadece yazıldığı düzeyde.** Kara kutu `ders.md` §7 mini sınavında
  çıkabilir; soru, köşede yazan cümlenin düzeyini aşmaz. `SEN YAP` kara kutuya dokunmaz.
- **Sahte numara yasak.** `akXXXX` yazılmaz — öğrenciye anlamsız, takibi imkânsız.
  Yerine konu/ünite adı: `"fonksiyon" konusunda`, `buton dersinde (ünite 2)`. Açılış
  dersi üretildiğinde tablo gerçek numarayla güncellenir **ve** o kutuya değinen eski
  dosyalar geriye dönük düzeltilir.
- **5. sınıf ölçüsü ck'nin lise ölçüsünü geçmez.** Kutunun cevabı somut ve fiziksel
  olsun; benzetme serbest, soyut tanım değil.

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

## AI Yoldaşı doktrini (2026-09-06 — Deneyap Atölyem kararları)

Evde öğretmen yok. Destek **üç katmanlıdır**, biri ötekinin yerine geçmez:

1. **`ders.md` §6 Sorun giderme** — birinci ve en önemli ağ. Hesap, yaş sınırı, internet
   istemez; takılan öğrencinin ilk gittiği yer burasıdır ve vakaların çoğunu burası
   kapatmalıdır. Öğretmenin yerine geçen asıl şey budur.
2. **Yanındaki yetişkin** — §8'e "Yanındaki Yetişkine" kartı yazılır. Çocuğa değil
   **yetişkine** hitap eder: "cevabı söylemeyin, şu üç şeyi sırayla sorun...".
3. **AI Yoldaşı** — erişimi olan için bonus. **Asla zorunlu değil.**

- **Hiçbir ders AI erişimi gerektirmez.** AI adımı ilerlemenin şartı olamaz: AI
  araçlarının çoğu 13 yaş altını kabul etmiyor, hedef kitle daha küçük. Ama erişimi olan
  çocuk **istediği anda** sorabilmeli — AI dersin sonuna kilitlenmez.
- **Prompt dört parçalıdır:** rol + **bağlam** + görev + "cevabı verme" kısıtı. Bağlam
  `ders.md` frontmatter'ındaki `board:` bloğundan gelir (kart adı, pin, mantık gerilimi,
  direnç) ve prompta açıkça yazılır. AI'ın hangi kartta olduğunu **tahmin etmesine izin
  verilmez** — tahmin ederse genel Arduino bilgisi board'a sızar (5V/3.3V, pin eşlemesi).
- **AI Yoldaşı asla pin numarası, direnç değeri ya da bağlantı tarifi vermez.** Bunlar
  yalnız dersten gelir. Prompt "nasıl bağlayacağımı söyle" demez, "düşünmeme yardım et"
  der. Sokratik kısıt bir üslup tercihi değil, **yanlış olgu iddiasına karşı korumadır**.
- **Sabit not, her derste:** *"AI'ın dediği devrende çalışmıyorsa AI yanılmıştır, devren
  haklıdır."* Son hakem fizikseldir — donanım müfredatının ekran müfredatına üstünlüğü
  tam olarak budur, gerçeklik AI'ı denetler.
- **§6 tek semptomlu olamaz.** En az 3-5 ayrı semptom, her biri **farklı sebeple**.
  "LED yanmıyor" tek başına yetmez; ters bağlama, yanlış pin, eksik GND, ortak direnç,
  yüklenmemiş kod ayrı maddelerdir.

Gerekçe ve tam tartışma: zihinEv `🏰 300-Projects/deneyapAtolyem/AI-Yoldasi-Kararlari.md`.

**Geriye dönük uygulanmaz (Özgür, 2026-09-06).** Bu doktrin ak0060'ta yürürlüğe girdi.
ak0010-ak0050 onaylanmış ve commit edilmiş derslerdir; §8'leri eski hâliyle kalır. Eksik
parçalar (board bağlamlı prompt, "Yanındaki Yetişkine" kartı, sabit not) o dersler
**dk'ya porte edilirken** dk tarafında eklenir — dk'nin kendi doktrini bunu zaten
zorunlu kılıyor.

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
- ak0020 (Harici LED) onaylandı, commit+push edildi (2026-09-03).
- **Merak Köşesi doktrini yürürlüğe girdi (2026-09-06)** — ck'nin (`D:\Atolye\cSharp`)
  dört turda çözdüğü format ak'ye taşındı. Özgür `.ino` sonunu seçti (`ders.md`'de
  ayrı bölüm ve iki yerde birden seçenekleri elendi). Beraberinde: rotasyon freni,
  yük freni, sabit çerçeve kapanış satırı, `README.md`. ck'nin `degerlendirme.md`'si
  **alınmadı** — `ders.md` §7 mini sınavı zaten o işi görüyor (Özgür kararı).
  `cozumler/` görünürlüğüne dokunulmadı (Özgür kararı).
- ak0030 (LED'i hızlandır — eşik) üretildi, onay bekliyor (2026-09-06). SEN YAP
  Özgür'ün kendi hız merdivenine çevrildi ("saniyede 1/5/10/25/50 kez").
- **Ünite yapısı revize edildi (2026-09-06, Karar 14)** — Özgür'ün `kabaMüfredat.docx`'i
  okundu, üç sorusu cevaplandı: `for` seri portla birlikte · `const int` iki LED'den
  sonra · kara şimşek önce elle sonra `for` ile. Sonuç: `for` ve PWM ünite 0'dan çıktı,
  ünite 0 yedi derse indi (kapanış: trafik lambası), ünite 1 "öğren/harca" ritmiyle
  kuruldu, `meydanOkuma/` açıldı. Kaynak dosyalarda altı kod hatası tespit edildi
  (Karar 14'te listeli), ders üretilirken düzeltilecek.
- **Açık:** öğrenci→öğretmen geri bildirim kanalı. Özgür sınıf içinde dolaşarak
  çözmeyi planlıyor; Deneyap Atölyem tarafının geri bildirimi ayrı bir turda
  konuşulacak.

## Tuzaklar
(boş — bir şey patladıkça Kural/Neden/Nasıl şablonuyla eklenir)
