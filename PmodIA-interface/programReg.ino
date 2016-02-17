#include "Arduino.h"

void programReg(){

  // Set Range 1, PGA gain 1
  writeData(CTRL_REG,0x01);

  // Set settling cycles
  writeData(NUM_SCYCLES_R1, 0x07);
  writeData(NUM_SCYCLES_R2, 0xFF);

  // Start frequency of 1kHz
  writeData(START_FREQ_R1, getFrequency(start_freq,1));
  writeData(START_FREQ_R2, getFrequency(start_freq,2));
  writeData(START_FREQ_R3, getFrequency(start_freq,3));

  // Increment by 1 kHz
  writeData(FREG_INCRE_R1, getFrequency(incre_freq,1)); 
  writeData(FREG_INCRE_R2, getFrequency(incre_freq,2)); 
  writeData(FREG_INCRE_R3, getFrequency(incre_freq,3));

  // Points in frequency sweep (100), max 511
  //writeData(NUM_INCRE_R1, (incre_num & 0x001F00)>>0x08 );
  writeData(NUM_INCRE_R1, 0x00);
  writeData(NUM_INCRE_R2, incre_num);

  //Serial.println("Register set");

}
