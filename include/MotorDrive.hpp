#pragma once

#include <Arduino.h>

struct Motordrive{
 int motornumber1;
 int motornumber2;
 int motorpwm;
 int pwmch;

 void setup(){
  pinMode(motornumber1,OUTPUT);
  pinMode(motornumber2,OUTPUT);
  ledcAttachPin(motorpwm, pwmch);
  ledcSetup(pwmch,12800,8);
 }

 void DRIVE(int pwmvalue){
    if (pwmvalue > 0){
      digitalWrite(motornumber1,1);
      digitalWrite(motornumber2,0);
      ledcWrite(pwmch,pwmvalue);
  }else if (pwmvalue < 0){
      digitalWrite(motornumber1,0);
      digitalWrite(motornumber2,1);
      ledcWrite(pwmch,-pwmvalue);
  }else {
      digitalWrite(motornumber1,1);
      digitalWrite(motornumber2,1);
  }
 }
};