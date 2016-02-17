#include "Arduino.h"

byte getFrequency(float freq, int n){
  long val = long((freq/(MCLK/4)) * pow(2,27));
  byte code;

    switch (n) {
      case 1:
        code = (val & 0xFF0000) >> 0x10; 
        break;
      
      case 2:
        code = (val & 0x00FF00) >> 0x08;
        break;

      case 3:
        code = (val & 0x0000FF);
        break;

      default: 
        code = 0;
    }

  return code;  
}
