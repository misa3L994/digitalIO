/*
Ejemplo del Uso de Histeresis 


12/11/2024
*/

#include <digitalIO.h>

digitalIO input1;
digitalIO input2(43);
digitalIO input3(45);
digitalIO input4;
digitalIO output(31);


void setup() {
  Serial.begin(115200);
  // put your setup code here, to run once:
  input1.begin(41,INPUT_PULLUP);
  input2.begin(INPUT_PULLUP);
  input3.begin(INPUT_PULLUP);
  input4.begin(11,INPUT_PULLUP);
  output.begin(OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
bool stableState1 = input1.readWithHysteresis(2000);
bool stableState2 = input2.readWithHysteresis(3000);
bool stableState3 = input3.readWithHysteresis(1000);
bool stableState4 = input4.readWithHysteresis(200);

Serial.print(stableState1);
Serial.print(" --- ");
Serial.print(stableState2);
Serial.print(" --- ");
Serial.print(stableState3);
Serial.print(" --- ");
Serial.println(stableState4);

output.setOutput(!(stableState1 | stableState2 | stableState3 | stableState4));



}
