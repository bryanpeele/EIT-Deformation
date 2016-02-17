#include "Arduino.h"

void runSweepElectrodes() {

  
   // AB
   setMUX(0,0);
   setMUX(1,1);
   Serial.print("AB;");
   runSweepSingle();
   
   // AC
   setMUX(0,0);
   setMUX(1,2);
   Serial.print("AC;");
   runSweepSingle();
   
   // AD
   setMUX(0,0);
   setMUX(1,3);
   Serial.print("AD;");
   runSweepSingle();

   // AE
   setMUX(0,0);
   setMUX(1,4);
   Serial.print("AE;");
   runSweepSingle();

   // AF
   setMUX(0,0);
   setMUX(1,5);
   Serial.print("AF;");
   runSweepSingle();

   // AG
   setMUX(0,0);
   setMUX(1,6);
   Serial.print("AG;");
   runSweepSingle();

   // AH
   setMUX(0,0);
   setMUX(1,7);
   Serial.print("AH;");
   runSweepSingle();

   // BC
   setMUX(0,1);
   setMUX(1,2);
   Serial.print("BC;");
   runSweepSingle();

   // BD
   setMUX(0,1);
   setMUX(1,3);
   Serial.print("BD;");
   runSweepSingle();

   // BE
   setMUX(0,1);
   setMUX(1,4);
   Serial.print("BE;");
   runSweepSingle();

   // BF
   setMUX(0,1);
   setMUX(1,5);
   Serial.print("BF;");
   runSweepSingle();

   // BG
   setMUX(0,1);
   setMUX(1,6);
   Serial.print("BG;");
   runSweepSingle();

   // BH
   setMUX(0,1);
   setMUX(1,7);
   Serial.print("BH;");
   runSweepSingle();

   // CD
   setMUX(0,2);
   setMUX(1,3);
   Serial.print("CD;");
   runSweepSingle();

   // CE
   setMUX(0,2);
   setMUX(1,4);
   Serial.print("CE;");
   runSweepSingle();

   // CF
   setMUX(0,2);
   setMUX(1,5);
   Serial.print("CF;");
   runSweepSingle();

   // CG
   setMUX(0,2);
   setMUX(1,6);
   Serial.print("CG;");
   runSweepSingle();

   // CH
   setMUX(0,2);
   setMUX(1,7);
   Serial.print("CH;");
   runSweepSingle();

   // DE
   setMUX(0,3);
   setMUX(1,4);
   Serial.print("DE;");
   runSweepSingle();

   // DF
   setMUX(0,3);
   setMUX(1,5);
   Serial.print("DF;");
   runSweepSingle();

   // DG
   setMUX(0,3);
   setMUX(1,6);
   Serial.print("DG;");
   runSweepSingle();

   // DH
   setMUX(0,3);
   setMUX(1,7);
   Serial.print("DH;");
   runSweepSingle();

   // EF
   setMUX(0,4);
   setMUX(1,5);
   Serial.print("EF;");
   runSweepSingle();

   // EG
   setMUX(0,4);
   setMUX(1,6);
   Serial.print("EG;");
   runSweepSingle();

   // EH
   setMUX(0,4);
   setMUX(1,7);
   Serial.print("EH;");
   runSweepSingle();

   // FG
   setMUX(0,5);
   setMUX(1,6);
   Serial.print("FG;");
   runSweepSingle();

   // FH
   setMUX(0,5);
   setMUX(1,7);
   Serial.print("FH;");
   runSweepSingle();

   // GH
   setMUX(0,6);
   setMUX(1,7);
   Serial.print("GH;");
   runSweepSingle();


  
}

