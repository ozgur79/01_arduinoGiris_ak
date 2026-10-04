| ders | tarih | derlendi mi | devrede çalıştı mı | sorun | çözüm |
|------|-------|--------------|---------------------|-------|-------|
| ak0010 | 2026-09-02 | ✓ | ✓ | — | Özgür onayladı, sorun çıkmadı (kayıt 2026-09-06'da geriye dönük girildi) |
| ak0020 | 2026-09-03 | ✓ | ✓ | — | Özgür onayladı, sorun çıkmadı (kayıt 2026-09-06'da geriye dönük girildi) |
| ak0030 | 2026-09-06 | ✓ | ✓ | — | Özgür onayladı, sorun çıkmadı |
| ak0040 | 2026-09-06 | ✓ | ✓ | — | Özgür onayladı, sorun çıkmadı |
| ak0050 | 2026-09-06 | ✓ | ✓ | — | Özgür onayladı, sorun çıkmadı |
| ak0060 | 2026-09-06 | ✓ | ✓ | — | Özgür onayladı, sorun çıkmadı |
| ak0070 | 2026-09-11 | ✓ | ✓ | — | Özgür kartta test etti |
| ak0110 | 2026-09-18 | ✓ | ✓ | — | Özgür kartta test etti |
| ak0115 | 2026-09-18 | ✓ | ✓ | — | Özgür kartta test etti |
| ak0120 | 2026-09-26 | ✓ | ✓ | — | Özgür kartta test etti |
| ak0130 | 2026-09-26 | ✓ | ✓ | — | Özgür kartta test etti |
| ak0140 | 2026-09-26 | ✓ | ✓ | — | Özgür kartta test etti |
| ak0150 | 2026-09-26 | ✓ | ✓ | — | Özgür kartta test etti |
| ak0155 | 2026-09-26 | ✓ | ✓ | — | Özgür kartta test etti |
| ak0160 | 2026-09-26 | ✓ | ✓ | — | Özgür kartta test etti |
| ak0165 | 2026-09-26 | ✓ | ✓ | — | Özgür kartta test etti (düzeltmeler sonrası) |
| ak0170 | 2026-09-26 | ✓ | ✓ | — | Özgür kartta test etti |
| ak0180 | 2026-09-26 | ✓ | ✓ | — | Özgür kartta test etti |
| ak0185 | 2026-09-28 | ✓ | ✓ | — | Özgür kartta test etti |
| ak0190 | 2026-09-28 | ✓ | ✓ | — | Özgür kartta test etti |
| ak0195 | 2026-09-28 | ✓ | ✓ | — | Özgür kartta test etti |
| ak0182 | — | — | — | — | teste hazır (2026-09-28) |
| ak0197 | — | — | — | — | teste hazır (2026-09-28) — ayrıca doğrulanacak: Seri Monitör "Yeni satır" modunda gönderilen \n karakteri iki if yapısında zararsız mı (hiçbir if'e uymuyor iddiası, henüz test edilmedi) |
| ak0199 | — | — | — | — | teste hazır (2026-09-28) — üç ayrı bozuk kod, üçü de ayrı ayrı test edilecek |
| ak0210 | — | — | — | — | teste hazır (2026-09-30) — malzeme: 2 × 10 kΩ direnç (bu derste 1, ak0230'dan itibaren 2 gerekir; kitte var mı Özgür kurarken doğrular). Kartta bakılacak: SEN YAP 1'de 10 kΩ sökülünce `Serial.println(digitalRead(butonPin))` ne gösteriyor (ders "zıplayabilir" diyor, kesin söylemiyor) |
| ak0215 | — | — | — | — | teste hazır (2026-09-30) — kartta bakılacak: "Butona bas..." yazısı çıkıyor mu, butona basınca kara şimşek başlıyor mu; SEN YAP 2'de `== HIGH` ile açılışta hemen başlıyor mu |
| ak0220 | — | — | — | — | teste hazır (2026-09-30) — kartta bakılacak: basınca yanıp bırakınca sönüyor mu; SEN YAP 2'de (pin 6 / pin 9 zıt LED) |
| ak0230 | — | — | — | — | teste hazır (2026-09-30) — malzeme: 2 × 10 kΩ direnç + 2 buton. Kartta bakılacak: tek butonla LED yanmıyor, ikisiyle yanıyor mu; SEN YAP 3'te direnç sökülünce ne oluyor |
| ak0240 | — | — | — | — | teste hazır (2026-09-30) — kartta bakılacak: LED 2 sn yanıyor mu; yanıkken basınca kart cevap veriyor mu; butonu BASILI TUTUNCA ne oluyor (ders tahmin yazmıyor, Özgür'ün gözlemi çıktı olarak buraya yazılacak) |
| ak0250 | — | — | — | — | teste hazır (2026-09-30) — kartta bakılacak: LED basınca mı bırakınca mı yanıyor (kod okunarak "bırakınca" çıkarıldı, doğrulanmadı); `delay(100)` silinince sıçrama görünüyor mu (görünmeyebilir); iki butona birden basınca LED'in son durumu |
| ak0260 | — | — | — | — | teste hazır (2026-09-30) — kartta bakılacak: "BAS!" sonrası ilk basan kazanıyor mu, Seri Monitör'de doğru oyuncu yazıyor mu; "BAS!" yanmadan butonu basılı tutunca/kısa basınca ne oluyor (kod okunarak kestirildi, doğrulanmadı) |
| ak0299 | — | — | — | — | teste hazır (2026-09-30) — üç bozuk kod ayrı ayrı test edilecek. Kartta bakılacak: bozuk1'de LED sürekli yanıp sönüyor mu; bozuk2'de LED hep yanık mı; bozuk3'te LED tamamen mi yoksa soluk mu yanıyor (INPUT modunda `digitalWrite(HIGH)` soluk yanma bırakabilir — kartta doğrulanmadı); çözüm kodları derleniyor mu |
| ak0310 | — | — | — | — | teste hazır (2026-09-30) — kartta bakılacak: 046 hâlinde bir basışta sayaç kaça fırlıyor (ders sayı vaat etmiyor, Özgür'ün gözlemi buraya); `while` + `delay(20)` çaresiyle bir basış = 1 mi; iki butonlu sayaçta Buton 1 basılıyken Buton 2 sayılıyor mu |
| ak0320 | — | — | — | — | teste hazır (2026-09-30) — kartta bakılacak: bir basış = 1 sayı mı; basılı tutunca artmıyor mu; Buton 1 basılıyken Buton 2 sayılıyor mu; `delay` olmadan bir basışta bazen 2 artış görülüyor mu (görülmeyebilir) |
| ak0330 | — | — | — | — | teste hazır (2026-09-30) — kartta bakılacak: LED'ler 0→15→0 doğru ilerliyor mu; sıçrama kaynaklı atlama görülüyor mu (görülmeyebilir, "kesin atlar" denmedi); `delay(0)`/`delay(50)`/`delay(500)` farkı; bit sırası ak0190 ile aynı mı (pin 9 = 1'ler) |
| ak0340 | — | — | — | — | teste hazır (2026-09-30) — kartta bakılacak: bas → BASTI + pin 3, bırak → BIRAKTI + pin 9; arka arkaya iki BASTI görülüyor mu; **iddia (kod okunarak): 030'un bayraklarını silince çıktı aynı** — kartta 030 orijinali ile bu sürümün çıktısı karşılaştırılacak, henüz doğrulanmadı |
| düzeltme | 2026-09-30 | — | — | — | Ortak araştırma notuna göre test edilmemiş derslerde düzeltme: (1) ak0210/0220/0230/0240/0250 4 bacaklı buton maddesi "1-2 ve 3-4 çapraz kısa devre" yerine "aynı kenardaki bacak çifti içeride bağlı olabilir, emin değilsen 90° çevir ya da çapraz köşeyi kullan" dilinde; (2) ak0230 İleri analiz'den "kısa devre" kelimesi çıkarıldı; (3) ak0299 Sorun giderme'ye "IDE varsayılan ayarda uyarı vermeyebilir" eklendi (ak0220'ye de `if (...);` maddesi); (4) ak0310 "yüzlerce" ifadesi kaldırıldı (sayı Özgür'ün ölçümüne bırakıldı); ak0320 Sorun giderme'ye `sonDurum` if içine konursa ne olur eklendi; ak0330'a Ganssle atfı, ak0340'a "BIRAKTI yazmıyor" maddesi eklendi. Kartta bakılacak (yeni): `if (x);` ve `if (x = HIGH)` için bu IDE sürümü uyarı veriyor mu |
