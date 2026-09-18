void setup() {
  pinMode(8, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(8, HIGH);
  Serial.println("ISIK ACIK");
  delay(2000);

  digitalWrite(8, LOW);
  Serial.println("ISIK KAPALI");
  delay(500);
}
