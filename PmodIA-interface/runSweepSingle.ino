#include "Arduino.h"

void runSweepSingle() {
  short re;
  short img;
  double freq;
  double mag;
  double phase;
  double gain;
  double impedance;
  int i=0;

  programReg();

  // 1. Standby '10110000' Mask D8-10 of avoid tampering with gains
  writeData(CTRL_REG,(readData(CTRL_REG) & 0x07) | 0xB0);

  // 2. Initialize sweep
  writeData(CTRL_REG,(readData(CTRL_REG) & 0x07) | 0x10);

  // 3. Start sweep
  writeData(CTRL_REG,(readData(CTRL_REG) & 0x07) | 0x20); 

      byte R1 = readData(RE_DATA_R1);
      byte R2 = readData(RE_DATA_R2);
      re = (R1 << 8) | R2;


      R1  = readData(IMG_DATA_R1);
      R2  = readData(IMG_DATA_R2);
      img = (R1 << 8) | R2;

      freq = start_freq + i*incre_freq;

      //Serial.print("F");
      Serial.print(freq/1000);
      Serial.print(";");

      //Serial.print("R");
      Serial.print(re);
      Serial.print(";");

      //Serial.print("I");
      Serial.print(img);
      Serial.println(";");

  //Power down
  writeData(CTRL_REG,(readData(CTRL_REG) & 0x07) | 0xA0);
}


