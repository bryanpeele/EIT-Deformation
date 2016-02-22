#include "Arduino.h"


void runSweepElectrodes(String type) {

  
   // AB
   setMUX(0,0);
   setMUX(1,1);
   delay(10);
   runSweepSingle2(type+";AB");
   
   // AC
   setMUX(0,0);
   setMUX(1,2);
   
   delay(10);
   runSweepSingle2(type+";AC");
   
   // AD
   setMUX(0,0);
   setMUX(1,3);
   //Serial.print("AD;");
   delay(10);
   runSweepSingle2(type+";AD");

   // AE
   setMUX(0,0);
   setMUX(1,4);
   //Serial.print("AE;");
   delay(10);
   runSweepSingle2(type+";AE");

   // AF
   setMUX(0,0);
   setMUX(1,5);
   //Serial.print("AF;");
   delay(10);
   runSweepSingle2(type+";AF");

   // AG
   setMUX(0,0);
   setMUX(1,6);
   //Serial.print("AG;");
   delay(10);
   runSweepSingle2(type+";AG");

   // AH
   setMUX(0,0);
   setMUX(1,7);
   //Serial.print("AH;");
   delay(10);
   runSweepSingle2(type+";AH");

   // BC
   setMUX(0,1);
   setMUX(1,2);
   //Serial.print("BC;");
   delay(10);
   runSweepSingle2(type+";BC");

   // BD
   setMUX(0,1);
   setMUX(1,3);
   //Serial.print("BD;");
   delay(10);
   runSweepSingle2(type+";BD");

   // BE
   setMUX(0,1);
   setMUX(1,4);
   //Serial.print("BE;");
   delay(10);
   runSweepSingle2(type+";BE");

   // BF
   setMUX(0,1);
   setMUX(1,5);
  // Serial.print("BF;");
   delay(10);
   runSweepSingle2(type+";BF");

   // BG
   setMUX(0,1);
   setMUX(1,6);
  // Serial.print("BG;");
   delay(10);
   runSweepSingle2(type+";BG");

   // BH
   setMUX(0,1);
   setMUX(1,7);
   //Serial.print("BH;");
   delay(10);
   runSweepSingle2(type+";BH");

   // CD
   setMUX(0,2);
   setMUX(1,3);
   //Serial.print("CD;");
   delay(10);
   runSweepSingle2(type+";CD");

   // CE
   setMUX(0,2);
   setMUX(1,4);
  // Serial.print("CE;");
   delay(10);
   runSweepSingle2(type+";CE");

   // CF
   setMUX(0,2);
   setMUX(1,5);
   //Serial.print("CF;");
   delay(10);
   runSweepSingle2(type+";CF");

   // CG
   setMUX(0,2);
   setMUX(1,6);
   //Serial.print("CG;");
   delay(10);
   runSweepSingle2(type+";CG");

   // CH
   setMUX(0,2);
   setMUX(1,7);
   //Serial.print("CH;");
   delay(10);
   runSweepSingle2(type+";CH");

   // DE
   setMUX(0,3);
   setMUX(1,4);
  // Serial.print("DE;");
   delay(10);
   runSweepSingle2(type+";DE");

   // DF
   setMUX(0,3);
   setMUX(1,5);
  // Serial.print("DF;");
   delay(10);
   runSweepSingle2(type+";DF");

   // DG
   setMUX(0,3);
   setMUX(1,6);
  // Serial.print("DG;");
   delay(10);
   runSweepSingle2(type+";DG");

   // DH
   setMUX(0,3);
   setMUX(1,7);
  // Serial.print("DH;");
   delay(10);
   runSweepSingle2(type+";DH");

   // EF
   setMUX(0,4);
   setMUX(1,5);
  // Serial.print("EF;");
   delay(10);
   runSweepSingle2(type+";EF");

   // EG
   setMUX(0,4);
   setMUX(1,6);
  // Serial.print("EG;");
   delay(10);
   runSweepSingle2(type+";EG");

   // EH
   setMUX(0,4);
   setMUX(1,7);
  // Serial.print("EH;");
   delay(10);
   runSweepSingle2(type+";EH");

   // FG
   setMUX(0,5);
   setMUX(1,6);
  // Serial.print("FG;");
   delay(10);
   runSweepSingle2(type+";FG");

   // FH
   setMUX(0,5);
   setMUX(1,7);
  // Serial.print("FH;");
   delay(10);
   runSweepSingle2(type+";FH");

   // GH
   setMUX(0,6);
   setMUX(1,7);
  // Serial.print("GH;");
   delay(10);
   runSweepSingle2(type+";GH");


  
}

