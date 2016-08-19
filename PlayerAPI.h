#ifndef PLAYER_API_H
#define PLAYER_API_H

#include <wiringPi.h>
#include "Player.h"
#include<stdio.h>


extern "C"{
  
  void startWheel();
  double getWheelRate();
  int getWheelQueueSize();
  void pushWheelKeys(int pKey1, int pKey2);
  int getNumber();
  void setNumber(int val);

}

#endif
  