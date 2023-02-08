#include "digitalIO.h"

digitalIO :: Buzzer b;
#define BUZZER 6
void setup() {
  // put your setup code here, to run once:

  b.buzzerBegin(BUZZER);// inicializa el pin para el zumbador


  b.playSound(RIGHT);
  delay(2000);
  b.playSound(WINS);
  delay(2000);
  b.playSound(WRONG);
  delay(2000);
  b.playSound(BIP);
  delay(2000);
  b.playSound(BIP2);
  delay(2000);

  b.melody();
  delay(2000);
  b.melody(WINS);
  delay(1000);
  b.melody(WRONG);
  delay(1000);
  b.bip();
  delay(1000);

}

void loop() {
  // put your main code here, to run repeatedly:

}
