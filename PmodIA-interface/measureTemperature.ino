
#include "Arduino.h"

boolean measureTemperature() {
  
  // Measure temperature '10010000'
  writeData(CTRL_REG, 0x90);
  //TODO: necessary to write to second control register?

  delay(10); // wait for 10 ms



  //Check status reg for temp measurement available
  int flag = readData(STATUS_REG)& 1;

  if (flag == 1) {


    // Temperature is available
    int temperatureData = readData(TEMP_R1) << 8;
    temperatureData |= readData(TEMP_R2);
    temperatureData &= 0x3FFF; // remove first two bits
    
    if (temperatureData & 0x2000 == 1) { // negative temperature
      
      temperatureData -= 0x4000;
    }
    
    double val = double(temperatureData) / 32;
    temperatureData /= 32;
    
    Serial.print("Temperature: ");
    Serial.print(val);
    //Serial.write(176);  //degree sign
    Serial.println("C.");
    

    // Power Down '10100000'
    writeData(CTRL_REG,0xA0);

    
    return true;

  } else {
    return false;
  }
}

