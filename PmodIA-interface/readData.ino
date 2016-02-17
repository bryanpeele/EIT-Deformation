#include "Arduino.h"

int readData(int addr){
  int data;

  Wire.beginTransmission(SLAVE_ADDR);
  Wire.write(ADDR_PTR);
  Wire.write(addr);
  Wire.endTransmission();

  delay(1);

  Wire.requestFrom(SLAVE_ADDR,1);

  if (Wire.available() >= 1){
    data = Wire.read();
  }
  else {
    data = -1;
  }

  delay(1);
  return data;  
}
