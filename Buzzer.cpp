/*
*/
#include "Buzzer.h"

//Sound sound;

Buzzer :: Buzzer(void){}
void Buzzer :: buzzerBegin(uint8_t b)
{
  _buzz = b;
}
void Buzzer :: bip(void)
{
  tone(_buzz, NOTE_A5);
  delay(200);
  noTone(_buzz); 
}	
void Buzzer :: playSound(void)
{
  tone(_buzz,2000,100);
}
void Buzzer :: playSound(Sounds s)
{
  switch(s)
  {
  	default:
  	
  	break;
  	case BIP:
  	tone(_buzz,1000,50);
  	break;
  	case WRONG:
  	tone(_buzz,200,500);
  	break;
  	case RIGHT:
  	tone(_buzz, 2000, 100);
    delay(150);
    tone(_buzz, 2000, 100);
  	break;
  	case WINS:
  	for(int i=0; i<3; i++) { tone(_buzz, 2000, 50); delay(100); }
  	break;
  	case LOSE:
  	break;
    case BIP2:
    tone(_buzz, 800, 50);
    delay(500);
    break;
  }
}
void Buzzer :: playMelody(int *m, int *t)
{
   int size = sizeof(m) / sizeof(int);
   for (int thisNote = 0; thisNote < size; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / t[thisNote];
    tone(_buzz, m[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(_buzz);
  }
}
void Buzzer :: melody(Sounds s)
{
  switch(s)
  {
    //default:
   
    //break;
    case WRONG:
    for (int thisNote = 0; thisNote < 3; thisNote++) {
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(_buzz, wrong[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(_buzz);
  }
    break;
    case WINS:
	int size = sizeof(wins) / sizeof(int);
    for (int thisNote = 0; thisNote < size; thisNote++) {
    int noteDuration = 1000 / tempoW[thisNote];
    tone(_buzz, wins[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(_buzz);
  }
    break;
    case LEVEL_UP:
	for (int thisNote = 0; thisNote < 4; thisNote++) {
    int noteDuration = 1000 / metric[thisNote];
    tone(_buzz, level_up[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(_buzz);
  }
    break;
  }
}
void Buzzer :: melody(void)
{
   
   int size = sizeof(mario) / sizeof(int);
   for (int thisNote = 0; thisNote < size; thisNote++) {
    int noteDuration = 1000 / tempo[thisNote];
    tone(_buzz, mario[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(_buzz);
  }
}
void Buzzer :: alarm(void)
{
int freq = 0;
  while(freq < 2000)
    {
      tone(_buzz, freq++);             // reproduce tono de alarma
    }
    delay(300);
    noTone(_buzz);                   // apaga el buzzer
    delay(500);
    freq = 100; 
}
