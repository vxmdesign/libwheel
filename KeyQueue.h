#ifndef KEY_QUEUE_H
#define KEY_QUEUE_H

#include<stdio.h>
#include<semaphore.h>

#define QUEUE_SIZE 2048

class KeyQueue{
 public:
  KeyQueue();
  void push_key(int pKey);
  int pop_key();  
  int size();
 private:
  sem_t mLock;
  int mStart;
  int mEnd;
  int mCount;
  int mQueue[2048];
};


#endif
