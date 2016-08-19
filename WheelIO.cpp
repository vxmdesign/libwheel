#include "WheelIO.h"

wpins iomap[] = {
  {11,10,5,6},
  {5,1,16,15}
};

WheelIO *local_map[sizeof(iomap)/sizeof(wpins)];

void map1_trig(){
  local_map[0]->interrupt();
  printf("trig spi 1\n");
}

void map2_trig(){
  local_map[1]->interrupt();
  printf("trig spi 2\n");
 
}

WheelIO::WheelIO(int pSelect){
  struct timeval tv;
  mPins = &iomap[pSelect];
  mSelect = pSelect;
  sem_init(&mLock, 0, 1);
  mDelta = 0;
  gettimeofday(&tv, NULL);
  mLastStamp = tv.tv_sec;
  mLastStamp = mLastStamp * 1000000;
  mLastStamp += tv.tv_usec;
  
  configAll();
}

void WheelIO::interrupt(){
  long long st;
  struct timeval tv;
  if(digitalRead(mPins->intr) == 0){
    gettimeofday(&tv, NULL);
    st = tv.tv_sec;
    st = st * 1000000;
    st += tv.tv_usec;
    mDelta = st - mLastStamp;    
    sem_post(&mLock);
  }
}

void WheelIO::sendInt(int pVal){
  int c;
  //sem_wait(&mLock);
  printf("sending %x\n",pVal);
  for(c = 0; c < 18; c++){
    digitalWrite(mPins->sclk, 0);
    if(pVal & 0x1){
      digitalWrite(mPins->dout, 1);
    }else{
      digitalWrite(mPins->dout, 0);
    }
    usleep(1);
    digitalWrite(mPins->sclk, 1);
    usleep(1);
    pVal = pVal>>1;
  }
}

void WheelIO::configAll(){
  pinMode(mPins->sclk, OUTPUT);
  pinMode(mPins->dout, OUTPUT);
  pinMode(mPins->intr, INPUT);
  pinMode(mPins->trig, OUTPUT);
  digitalWrite(mPins->sclk, 1);
  digitalWrite(mPins->trig, 0);
  if(mSelect == 0){
    wiringPiISR(mPins->intr, INT_EDGE_FALLING, &map1_trig);

  }else if(mSelect == 1){
    wiringPiISR(mPins->intr, INT_EDGE_FALLING, &map2_trig);
  }
  local_map[mSelect] = this;
}

double WheelIO::rate(){
  double ret;
  ret = mDelta;
  ret = ret / 1000000.0;
  ret = 1 / ret;
  return ret;  
}
