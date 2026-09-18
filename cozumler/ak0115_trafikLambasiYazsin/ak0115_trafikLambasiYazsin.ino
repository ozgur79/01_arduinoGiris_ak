const int kirmizi = 8;
const int sari = 9;
const int yesil = 10;

void setup() {
  pinMode(kirmizi, OUTPUT);
  pinMode(sari, OUTPUT);
  pinMode(yesil, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(kirmizi, HIGH);
  digitalWrite(sari, LOW);
  digitalWrite(yesil, LOW);
  Serial.println("KIRMIZI");
  delay(4000);

  digitalWrite(kirmizi, LOW);
  digitalWrite(sari, LOW);
  digitalWrite(yesil, HIGH);
  Serial.println("YESIL");
  delay(3000);

  digitalWrite(kirmizi, LOW);
  digitalWrite(sari, HIGH);
  digitalWrite(yesil, LOW);
  Serial.println("SARI");
  delay(2000);
}
