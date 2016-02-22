//https://ez.analog.com/thread/42057?start=15&tstart=0

// this is a test of the new branch

#include "Wire.h"
#define button 2
#define SLAVE_ADDR 0x0D
#define ADDR_PTR 0xB0

#define START_FREQ_R1 0x82
#define START_FREQ_R2 0x83
#define START_FREQ_R3 0x84

#define FREG_INCRE_R1 0x85
#define FREG_INCRE_R2 0x86
#define FREG_INCRE_R3 0x87

#define NUM_INCRE_R1 0x88
#define NUM_INCRE_R2 0x89

#define NUM_SCYCLES_R1 0x8A 
#define NUM_SCYCLES_R2 0x8B 

#define RE_DATA_R1 0x94
#define RE_DATA_R2 0x95

#define IMG_DATA_R1 0x96
#define IMG_DATA_R2 0x97

#define TEMP_R1 0x92
#define TEMP_R2 0x93

#define CTRL_REG 0x80
#define CTRL_REG2 0x81

#define STATUS_REG 0x8F


const float MCLK = 16.776*pow(10,6); // AD5933 Internal Clock Speed 16.776 MHz
const float start_freq = 30*pow(10,3); // Set start freq, < 100Khz
const float incre_freq = 1*pow(10,3); // Set freq increment
const int incre_num = 1; // Set number of increments; < 511
const int samples = 20;

char state; 

boolean RUN_STATE = LOW;

int readData(int addr);
void writeData(int addr, int data);
void runSweepSingle();
void sweepElectrodes();
void setMUX(int MUX, int output);
byte getFrequency(float freq, int n);
boolean measureTemperature();
void programReg();
void runSweep();


void setup() {

  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);

  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);


  
  Wire.begin();
  Serial.begin(115200);
  pinMode(button, INPUT);   

  //nop - clear ctrl-reg
  writeData(CTRL_REG,0x0);


  //reset ctrl register
  writeData(CTRL_REG2,0x10);  

  programReg();
}


void loop(){

  //Read state and enter FSM
    if(Serial.available()>0) {
      state = Serial.read();

      //FSM
      switch(state) {
        case 'A':  //Program Registers
          programReg();
          break;

        case 'B':  //Measure Temperature
          measureTemperature();
          break;

        case 'C':
          runSweepElectrodes("Empty");
          delay(10);
          break;

      
        case 'D':
          RUN_STATE = HIGH;
          break;

      
        case 'E':
          RUN_STATE = LOW;
          break;


        case 'F':
          for (int i=0; i<samples; i++) {
            runSweepElectrodes("Empty");
            delay(10);
          }
          break;

        case 'G':
          for (int i=0; i<samples; i++) {
            runSweepElectrodes("Center");
            delay(10);
          }
          break;

         case 'H':
          for (int i=0; i<samples; i++) {
            runSweepElectrodes("East");
            delay(10);
          }
          break;

         case 'I':
          for (int i=0; i<samples; i++) {
            runSweepElectrodes("North");
            delay(10);
          }
          break;

        case 'J':
          for (int i=0; i<samples; i++) {
            runSweepElectrodes("West");
            delay(10);
          }
          break;

         case 'K':
          for (int i=0; i<samples; i++) {
            runSweepElectrodes("South");
            delay(10);
          }
          break;
      
      }

      

      Serial.flush();
    }

    if (RUN_STATE == HIGH) {
       runSweepElectrodes("None");

    }

}






