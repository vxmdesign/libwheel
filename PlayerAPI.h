#ifndef PLAYER_API_H
#define PLAYER_API_H

#include <wiringPi.h>
#include "Player.h"


extern "C"{
  
  void startWheel();
  double getWheelRate();
  int getWheelQueueSize();
  void pushWheelKeys(int pKey1, int pKey2);

}

#endif
