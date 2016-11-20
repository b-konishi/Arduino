#include <Keyboard.h>

#define STEP_ANGLE 1.8
bool pin2, pin3;
volatile float degree;
volatile bool keyboardFlag;
void setup() {
  degree = 0;
  keyboardFlag = false;
  pinMode(0, INPUT_PULLUP);
  pinMode(1, INPUT_PULLUP);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  attachInterrupt(digitalPinToInterrupt(0), zero, CHANGE);
  attachInterrupt(digitalPinToInterrupt(1), item, FALLING);
}

void loop() {
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

void zero() {
  degree = 0.000;
  Serial.print(degree);
  Serial.print("\t");
  Serial.println("");
}

void item() {
  Keyboard.print("A");
  // Serial.println("item"); 
}




