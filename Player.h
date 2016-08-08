#ifndef PLAYER_H
#define PLAYER_H

#include <stdio.h>
#include <pthread.h>
#include "KeyQueue.h"
#include "WheelIO.h"

class Player{
 public:
  Player();
  double currentRate();
  void pushKeys(int pSet1, int pSet2);
  int queueSize();
  void frame1_run();
  void frame2_run();
  void stop();
 private:
  int mRunning;
  pthread_t mF1Thread;
  pthread_t mF2Thread;  
  KeyQueue *mQ1;
  KeyQueue *mQ2;
  WheelIO *mFrame1;
  WheelIO *mFrame2;  
};

#endif
