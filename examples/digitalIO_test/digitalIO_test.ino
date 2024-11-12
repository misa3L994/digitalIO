/*
   Biblioteca digitalIO by Proyectil Mx

   Ejemplo de uso para entradas y salidas digitales


   shield Proyectil

*/
#include <digitalIO.h>

digitalIO input;
digitalIO btn(43);
digitalIO led1(9);
digitalIO led2;
digitalIO rele(A0);

int number;
void setup() {
  Serial.begin(115200);

  input.begin(41, INPUT_PULLUP);
  btn.begin(INPUT_PULLUP);
  led1.begin(OUTPUT);
  led2.begin(31, OUTPUT);
  rele.begin(OUTPUT);

 
  Serial.println("Inicia digitalIo test..");
}

void loop()
{
Serial.print(input.readWithHysteresis(3000));
Serial.print(" -- ");
Serial.println(btn.readWithHysteresis(1000));
}
void loop1() {

  led1.setOutput(btn.getState());

  if (btn.getTimeOn() > 2000)
  {
    led2.blinkOutput(1, 100);
  }

  if (input.getTimeOn() > 5000)
  {
    rele.setOutput(!rele.state);
    while(!input.getState());
  }

  number = input.getNumber(); 
  if (number != 0)
  {
    Serial.println(number);
    led1.blinkOutput(number, 500);
    
   
  }

}
