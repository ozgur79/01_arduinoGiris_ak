const int kirmizi = 8;
const int sari = 9;
const int yesil = 10;

void setup() {
  pinMode(kirmizi, OUTPUT);
  pinMode(sari, OUTPUT);
  pinMode(yesil, OUTPUT);
}

void loop() {
  digitalWrite(kirmizi, HIGH);
  digitalWrite(sari, LOW);
  digitalWrite(yesil, LOW);
  delay(4000);

  digitalWrite(kirmizi, HIGH);
  digitalWrite(sari, HIGH);
  digitalWrite(yesil, LOW);
  delay(1000);

  digitalWrite(kirmizi, LOW);
  digitalWrite(sari, LOW);
  digitalWrite(yesil, HIGH);
  delay(3000);

  digitalWrite(kirmizi, LOW);
  digitalWrite(sari, HIGH);
  digitalWrite(yesil, LOW);
  delay(1000);
}
