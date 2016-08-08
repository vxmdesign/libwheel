#include "KeyQueue.h"

KeyQueue::KeyQueue(){
  mStart = 0;
  mEnd = 0;
  mCount = 0;
  sem_init(&mLock, 0, 1);
}

void KeyQueue::push_key(int pKey){
  int nxt;
  nxt = (mEnd + 1) % QUEUE_SIZE;
  if(nxt == mStart){
    return;
  }
  mQueue[mEnd] = pKey;
  sem_wait(&mLock);
  mEnd = nxt;
  mCount++;
  sem_post(&mLock);  
}

int KeyQueue::pop_key(){
  int ret;
  if(mStart == mEnd){
    return 0;
  }
  ret = mQueue[mStart];
  sem_wait(&mLock);
  mStart = (mStart + 1) % QUEUE_SIZE;
  mCount = mCount - 1;
  sem_post(&mLock);
  return ret;  
}


int KeyQueue::size(){
  return mCount;
}
