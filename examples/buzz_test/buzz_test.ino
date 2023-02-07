#include "digitalIO.h"

digitalIO :: Buzzer b;
void setup() {
  // put your setup code here, to run once:
 
 b.buzzerBegin(A2);
 b.playSound(RIGHT);
 delay(1000);
 b.melody(MELODY);
 delay(1000);
 b.bip();
}

void loop() {
  // put your main code here, to run repeatedly:

}
