#ifndef WHEEL_IO_H
#define WHEEL_IO_H

#include<stdio.h>
#include<wiringPi.h>
#include<unistd.h>
#include<semaphore.h>
#include<sys/time.h>

typedef struct{
  int sclk;
  int dout;
  int trig;
  int intr;
}wpins;

class WheelIO{
 public:
  WheelIO(int pSelect);
  void sendInt(int pVal);  
  void interrupt();
  double rate();
 private:
  void configAll();
  int mSelect;
  sem_t mLock;
  wpins *mPins;
  long long mLastStamp;
  long long mDelta;
};

#endif
