#include "Arduino.h"

void setMUX(int MUX, int output){

  int offset = 2 + (MUX*4);



  if (output == 0) {
    digitalWrite(offset,LOW);
    digitalWrite(offset+1,LOW);
    digitalWrite(offset+2,LOW);
  }

  if (output == 1) {
    digitalWrite(offset,HIGH);
    digitalWrite(offset+1,LOW);
    digitalWrite(offset+2,LOW);
  }

  if (output == 2) {
    digitalWrite(offset,LOW);
    digitalWrite(offset+1,HIGH);
    digitalWrite(offset+2,LOW);
  }

  if (output == 3) {
    digitalWrite(offset,HIGH);
    digitalWrite(offset+1,HIGH);
    digitalWrite(offset+2,LOW);
  }

  if (output == 4) {
    digitalWrite(offset,LOW);
    digitalWrite(offset+1,LOW);
    digitalWrite(offset+2,HIGH);
  }

  if (output == 5) {
    digitalWrite(offset,HIGH);
    digitalWrite(offset+1,LOW);
    digitalWrite(offset+2,HIGH);
  }

  if (output == 6) {
    digitalWrite(offset,LOW);
    digitalWrite(offset+1,HIGH);
    digitalWrite(offset+2,HIGH);
  }

  if (output == 7) {
    digitalWrite(offset,HIGH);
    digitalWrite(offset+1,HIGH);
    digitalWrite(offset+2,HIGH);
  }


}
