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
uint16_t delayTime;
long lastChangeTime = 0;
bool state1 = LOW;
bool flag1 = false;
const long delayT = 2000;  // Tiempo de histéresis (ajustable) 

public:
bool state;
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
void blinkOutput(uint16_t);
void blinkOutput(uint8_t,uint8_t);
void setOutput(boolean);
//bool readWithHysteresis(uint8_t pin, long &lastChangeTime, bool &state, bool &flag);
bool readWithHysteresis(long Time);

};

#endif