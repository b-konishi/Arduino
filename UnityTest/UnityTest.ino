volatile int angle;
void setup() {
  angle = 3;
  pinMode(2, INPUT_PULLUP);
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(2), launch, CHANGE);
}

void loop() {
}
void launch() {
  Serial.print(angle);
  Serial.print("\t");
  Serial.println("");
}

