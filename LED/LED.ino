#include<Keyboard.h>

int led = 13;
void setup() {
  Serial.begin(9600);
  Keyboard.begin();
  pinMode(13,OUTPUT);
}

void loop() {
  int inputchar;
  inputchar = Serial.read();
  if (inputchar == 'o') {
    digitalWrite(13, HIGH);
    delay(1000);
  } else {
    digitalWrite(13,LOW);
  }

}



