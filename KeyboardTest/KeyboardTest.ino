#include<Keyboard.h>

int key_enable = 1;
void setup() {
  pinMode( 2, INPUT_PULLUP);
  Keyboard.begin();
}
 
void loop() {
  if (digitalRead(2) == LOW) {
    key_enable = 0;
  } else {
    if (key_enable == 0) {
      Keyboard.print("TEST");
      key_enable = 1;
    }
  }
}


