#ifndef  proyectil_DIGITALIO_H_
#define  proyectil_DIGITALIO_H_

#include <Arduino.h>
#include "Buzzer.h"

class digitalIO : public Buzzer{

private:
uint8_t _pin;
bool flagTime = false;
long getTime1 = 0;
long getTime2 = 0;  
bool newPush = false;
bool oldPush = false;
bool state;

public:
digitalIO();
digitalIO(uint8_t);
void begin(uint8_t,uint8_t);
void begin(uint8_t);
bool getState();
void setNumber(uint8_t);
uint8_t getNumber();
long getTimeOn();
digitalIO operator+(digitalIO);
uint8_t num; 
};

#endif