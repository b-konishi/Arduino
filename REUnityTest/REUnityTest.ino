const float STEP_ANGLE = 11.25;
volatile bool pin2, pin3;
volatile float degree;
void setup() {
  degree = 0;
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(3), launch, CHANGE);
}

void loop() {

}

void launch() {
  pin2 = digitalRead(2);
  pin3 = digitalRead(3);
  if (pin2^pin3) {
    while (digitalRead(2)^digitalRead(3)) {}
    if (!(pin2^digitalRead(2))&(pin3^digitalRead(3))==1) {
      degree += STEP_ANGLE;
    } else {
      degree -= STEP_ANGLE;
    }
  } else {
    while (!(digitalRead(2)^digitalRead(3))) {}
    if ((pin2^digitalRead(2))&!(pin3^digitalRead(3))==1) {
      degree += STEP_ANGLE;
    } else {
      degree -= STEP_ANGLE;
    }
  }
  Serial.print(degree,4);
  Serial.print("\t");
  Serial.println("");
}

