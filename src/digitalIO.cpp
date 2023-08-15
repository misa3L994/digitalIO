
#include "digitalIO.h"


//FUNCIONES 
digitalIO::digitalIO(){}
digitalIO::digitalIO(uint8_t pin){
  _pin = pin;
}
digitalIO digitalIO::operator+(digitalIO sw){
digitalIO r;
r.num = num + sw.num;
return r;
}
void digitalIO::begin(uint8_t mode){
  num =_pin;
  
  pinMode(_pin,mode);

  if(mode == INPUT or mode == INPUT_PULLUP){
  if(mode != 0)state = false;
  else state = true;
 }
 else state = false;

}
void digitalIO::begin(uint8_t pin, uint8_t input){
  num =_pin = pin;
  
  pinMode(_pin,input);
  if(input != 0)state = false;
  else state = true;
}
void digitalIO::setNumber(uint8_t n){
    num = n;
}
long digitalIO::getTimeOn(){
  if(!getState()){
       
    if(flagTime == false){
          flagTime = true;
          getTime1 = millis();
       }
       getTime2 = millis() - getTime1;
       return getTime2;
    }else {
        getTime2 = 0;
        flagTime = false;
        return NULL;
    }    
}

bool digitalIO::getState(){
   bool buttonState;
   
   buttonState = digitalRead(_pin);
   delay(10);
   return(buttonState);
}
uint8_t digitalIO::getNumber(){
   int buttonPressed = 0;
   
   newPush = digitalRead(_pin);
  
   if(newPush == state && oldPush == !state){
        buttonPressed = num;
         delay(200);
   }
    
   oldPush = newPush;
   return(buttonPressed);
}

void digitalIO :: blinkOutput(uint16_t waitTime)
{
  delayTime = waitTime;
  setOutput(!state);
   delay(delayTime);
}
void digitalIO :: blinkOutput(uint8_t times,uint8_t speed)
{
  uint8_t _times = times*2;
  for(int i = 0;i < _times;i++)
  {
    blinkOutput(speed);
  }
}
void digitalIO :: setOutput(boolean s)
{
  digitalWrite(_pin,s);
  if(s == HIGH)state = true;
  else state = false;
}
