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
- **Ortak'tan iki kural düzeltmesi (ak'nin hatası değil):** Karar 11'in §5 kuralı fazla
  katıydı, "birebir aynı" yerine "her kod satırını kapsayan, `.ino` yorumuyla
  çelişmeyen" oldu — ak'nin uygulaması doğruydu, dosyalar değişmedi. Karar 12'de
  ak0030'un tek yeni fikri "hız" yerine **"eşik"** olarak yeniden tanımlandı.
