float value;
void setup() {
  Serial.begin(9800);
}

void loop() {
  value = analogRead(0);
  Serial.println(value);
  //delay(50);
}
