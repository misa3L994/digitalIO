
#include "digitalIO.h"


//FUNCIONES 
digitalIO::digitalIO(){
     
}
digitalIO digitalIO::operator+(digitalIO sw){
digitalIO r;
r.num = num + sw.num;
return r;
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
