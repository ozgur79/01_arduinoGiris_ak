---
ak_no: ak0060
baslik: Kara şimşek (elle)
duzey: 0-temel
unite: 0-LED
kazanimlar:
  - cpp.const-int
  - cpp.coklu-cikis
  - cpp.kod-tekrari
  - hw.coklu-led
kara_kutu: [void, OUTPUT]
merak_kosesi: atlandı (yük freni — ders uzun, kendi yeni fikri ağır)
malzeme:
  - Arduino Uno kartı
  - USB kablosu
  - 4 LED
  - 4 adet 220 ohm direnç
  - breadboard
  - 8 jumper kablo
board:
  kart: Arduino Uno
  led_pinleri: [8, 9, 10, 11]
  mantik_gerilimi: 5V
  direnc: 220 ohm
kaynak: D:\ArduinoProjeleri\002Arduino\004karaSimsek (pin 13/12/11/10 -> 8/9/10/11; desen 7 adımdan 6 adıma indirildi)
---

## 1. Hedef
Dört LED'i yan yana dizip aralarında gidip gelen bir ışık yapacaksın — eski dizilerdeki
"kara şimşek" efekti. Devre kolay, asıl olay kodda: her adımda dört LED'in de ne yapacağını
tek tek yazacaksın ve kod uzayacak. **Bu uzunluk bir kaza değil, dersin konusu.**

## 2. Malzemeler
- Arduino Uno kartı
- USB kablosu
- 4 LED
- 4 adet 220 ohm direnç
- breadboard
- 8 jumper kablo

## 3. Parça tanıtımı
Yeni parça yok — ak0020'de tanıdığın LED ve dirençten dörder tane. **Her LED'in kendi
direnci olmalı**; dördü tek dirence bağlanırsa hepsi sönük yanar ve desen zor görünür.
LED'leri breadboard'a soldan sağa, yan yana ve aralarında eşit boşluk olacak şekilde diz —
desenin gidip geldiğini görebilmen buna bağlı.

## 4. Devre kurulumu
1. Dört LED'i breadboard'a soldan sağa yan yana tak.
2. Soldaki LED'in uzun bacağından (+) pin 8'e bağlan.
3. Sıradakilerin uzun bacaklarını sırayla pin 9, pin 10 ve pin 11'e bağlan.
4. Her LED'in kısa bacağını (−) kendi 220 ohm direncine, her direncin diğer ucunu GND'ye bağlan.

Metin şeması:
- 1. LED (+) → pin 8, (−) → 220 ohm → GND
- 2. LED (+) → pin 9, (−) → 220 ohm → GND
- 3. LED (+) → pin 10, (−) → 220 ohm → GND
- 4. LED (+) → pin 11, (−) → 220 ohm → GND

## 5. Kod açıklaması
| kod satırı | açıklama |
| --- | --- |
| `// Dört LED'i dört ayrı pine bağlarsan dördünü de ayrı ayrı yönetebilirsin` | Dört LED dört ayrı pine bağlanırsa dördü de ayrı ayrı yönetilebilir. |
| `// Her adımda dört LED'in de ne yapacağını tek tek yazıyoruz: biri HIGH, üçü LOW` | Her adımda dört LED'in de durumu tek tek yazılır: biri `HIGH`, üçü `LOW`. |
| `// Desen gidip geliyor: 1-2-3-4-3-2, sonra baştan` | Desen gidip gelir: 1-2-3-4-3-2, sonra başa döner. |
| `const int led1 = 8;` (ve led2/led3/led4) | 8, 9, 10 ve 11 numaralı pinlere `led1`-`led4` adları verilir. |
| `pinMode(led1, OUTPUT);` (dört satır) | Dört pinin dördü de çıkış moduna alınır; her pinin kendi satırı vardır. |
| `digitalWrite(led1, HIGH);` | O adımda yanacak LED'in pini açılır. |
| `digitalWrite(led2, LOW);` | O adımda yanmayacak LED'lerin pinleri kapatılır. |
| `delay(300);` | O adımın görüntüsü 300 milisaniye ekranda kalır. |
| `}` (setup ve loop sonu) | `;` bir komutun bittiğini, `}` bloğun bittiğini gösterir. |

### İleri analiz [ileri]
`loop()` içinde **6 adım** var; her adım **4 satır `digitalWrite` + 1 satır `delay`** =
5 satır. Toplam **30 satır**, ve bunların 24'ü birbirinin neredeyse aynısı — sadece hangi
LED'in `HIGH` olduğu değişiyor.

Desen neden 6 adım, 8 değil? Çünkü gidip gelirken **uçlar tekrar edilmez**: 1-2-3-4-3-2
dizisinden sonra `loop()` başa döner ve 1 yanar. Eğer diziye sondan bir de 1 eklersen
(kaynak kodda böyleydi) 1. LED her turda iki kat uzun yanar ve desen aksar.

Beş LED'e çıkarsan adım sayısı 8 olur (1-2-3-4-5-4-3-2) ve her adım 5 `digitalWrite`
ister: 8 × 6 = **48 satır**. Yani bir LED eklemek koda 18 satır ekliyor. Bu büyüme,
ilerideki döngü konusunun neden var olduğunu anlatan asıl sebeptir.

## 6. Çalıştır ve gözlemle
Kod yüklendiğinde ışık soldan sağa yürür, sağ uca varınca geri döner ve bunu sürekli
tekrar eder. Her LED 300 milisaniye yanık kalır. Doğru çalışıyorsa uçlardaki LED'ler
diğerleriyle **aynı sürede** yanar — biri daha uzun yanıyorsa desende bir adım fazladır.

### Sorun giderme
- **Bir LED hiç yanmıyor, diğer üçü çalışıyor** → Sırayla üç şey: o LED'in `pinMode`
  satırı yazılmış mı, LED ters mi takılmış, kablo doğru pinde mi.
- **Işık soldan sağa gitmiyor, sırası karışık** → LED'lerin fiziksel dizilişi kodun sırasıyla
  uyuşmuyor. Breadboard'da soldan sağa pin 8-9-10-11 sırası korunmalı.
- **Uçtaki LED diğerlerinden uzun yanıyor** → Desende fazla bir adım var; gidiş-dönüşte
  uçlar tekrar edilmez.
- **Hepsi aynı anda yanıp sönüyor** → Bir adımda birden fazla `digitalWrite` `HIGH`
  bırakılmış olabilir; her adımda tam bir tane `HIGH` olmalı.
- **Hepsi çok sönük yanıyor** → Dört LED tek dirence bağlanmış olabilir; her LED'in kendi
  direnci olmalı.
- **Hiçbiri yanmıyor** → GND bağlantısı kopuk olabilir; dört direncin de GND'ye ulaştığını
  kontrol et.

## 7. Mini sınav
1. [temel] `loop()` içinde kaç adım var?
   - A) 4
   - B) 6 ✅
   - C) 8
   - D) 30
   - ipucu: Yorum satırlarındaki "1. adım", "2. adım" ifadelerini say.

2. [temel] Her adımda neden dört tane `digitalWrite` satırı var?
   - A) Dört LED'in de o adımdaki durumu tek tek yazılıyor ✅
   - B) Her LED dört kez yakılıyor
   - C) Dört farklı renk için
   - D) Arduino dört satır ister
   - ipucu: Bir LED yanarken diğer üçüne ne oluyor?

3. [temel] Işık sağ uca vardıktan sonra ne olur?
   - A) Söner ve program durur
   - B) Baştan sağ uca atlar
   - C) Geri döner, soldan devam eder ✅
   - D) Dördü birden yanar
   - ipucu: Desen 1-2-3-4-3-2.

4. [temel] `const int led3 = 10;` satırı ne yapar?
   - A) 10 numaralı pine `led3` adını verir ✅
   - B) 3 numaralı LED'i 10 kez yakar
   - C) 10 milisaniye bekler
   - D) Üçüncü LED'i açar
   - ipucu: ak0050'de öğrendiğin satır.

5. [ileri] Kaynak koddaki desen 1-2-3-4-3-2-1 idi, yani sonda bir kez daha 1 vardı.
   Bu ne soruna yol açar?
   - A) Hiçbir sorun olmaz
   - B) Program derlenmez
   - C) 1. LED her turda iki kat uzun yanar, desen aksar ✅
   - D) 4. LED hiç yanmaz
   - ipucu: `loop()` bittikten sonra hangi adım gelir?

6. [ileri] Beş LED'lik bir kara şimşekte `loop()` içinde kaç `digitalWrite` satırı olur?
   - A) 20
   - B) 24
   - C) 40 ✅
   - D) 48
   - ipucu: 8 adım × her adımda 5 LED'in durumu.

## 8. AI Yoldaşı promptları

> **Not:** AI Yoldaşı sana devrenin nasıl kurulacağını, hangi pine bağlayacağını ya da
> hangi direnci kullanacağını söylemez — bunlar sadece derste yazar. **AI'ın dediği
> devrende çalışmıyorsa AI yanılmıştır, devren haklıdır.**

- [temel] **Kavramsal** — "Sen sabırlı bir öğretmensin. Arduino Uno kartında, 8-9-10-11
  numaralı pinlere bağlı dört LED'le gidip gelen bir ışık deseni yazdım ve kodum çok
  uzadı. Bana daha kısa yazmanın yolunu **söyleme**; bunun yerine 'bu satırların hangileri
  gerçekten birbirinden farklı?' diye sorarak farkı kendim görmemi sağla."
- [temel] **Hata giderme** — "Sen bir hata ayıklama koçusun. Arduino Uno kartında pin
  8-9-10-11'e 220 ohm dirençlerle bağlı dört LED'im var; üçü çalışıyor, biri hiç yanmıyor.
  **Bana pin numarası ya da bağlantı tarifi verme.** Bunun yerine hangi üç şeyi sırayla
  kontrol etmem gerektiğini soru sorarak buldur."
- [ileri] **Pekiştirme** — "Sen ileri seviye bir mentorsun. Arduino Uno'da dört LED'lik
  bir desenim var; her adım 4 satır, 6 adım = 30 satır. Beşinci LED eklersem kaç satır
  olacağını **sen hesaplama**; 'adım sayısı nasıl değişir, her adımda kaç satır olur'
  diye sorarak bana hesaplattır."
- [temel] **Yanındaki Yetişkine** — "Yardım etmek isterseniz: cevabı söylemeyin. Şu üç
  şeyi sırayla sorun — çalışmayan LED'in uzun bacağı doğru yönde mi duruyor? Koddaki pin
  numarası ile kablonun takılı olduğu pin aynı mı? O LED'in direncinin iki ucu da tam
  oturmuş mu? Üçü de doğruysa bize yazın."

## 9. SEN YAP
1) Deseni ters yönde başlat: ışık soldan değil sağdan başlasın (led4'ten led1'e gidip
   geri dönsün). Kaç satırın yerini değiştirmen gerekti?
2) Beşinci bir LED eklesen (pin 12), `loop()` içine kaç satır eklemen gerekirdi? Önce
   tahmin et, defterine yaz; sonra tek tek sayarak kontrol et. (Devreyi kurmana gerek
   yok, bu bir sayma görevi.)
3) Bekleme süresini 300'den 100'e düşür. Kaç satıra dokunman gerekti? Şimdi ak0050'de
   öğrendiğin şeyi hatırla: bunu tek satırdan değiştirilebilir hâle getirebilir misin?

**Not:** Bu dersin kodu uzun ve satırların çoğu birbirinin neredeyse aynısı. Yazarken
hissettiğin o rahatsızlık haklı — aynı deseni çok daha kısa yazmanın bir yolu var. Onu
seri port ünitesinde öğreneceğiz ve bu devreye geri dönüp aynı işi birkaç satırda yapacağız.
