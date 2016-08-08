#include "Player.h"

void *priv_f1_call(void *arg){
  Player *p;
  p = (Player*)arg;
  p->frame1_run();
  return NULL;
}

void *priv_f2_call(void *arg){
  Player *p;
  p = (Player*)arg;
  p->frame2_run();
  return NULL;
}

Player::Player(){
  mFrame1 = new WheelIO(0);
  mFrame2 = new WheelIO(1);
  mQ1 = new KeyQueue();
  mQ2 = new KeyQueue();
  mRunning = 1;
  pthread_create(&mF1Thread, NULL, priv_f1_call, this);
  pthread_create(&mF1Thread, NULL, priv_f2_call, this);
  
}

double Player::currentRate(){
  return mFrame1->rate();
}

int Player::queueSize(){
  return mQ1->size();
}

void Player::frame1_run(){
  int nxt;
  while(mRunning == 1){
    nxt = mQ1->pop_key();
    mFrame1->sendInt(nxt);
  }
}

void Player::frame2_run(){
  int nxt;
  while(mRunning == 1){
    nxt = mQ2->pop_key();
    mFrame2->sendInt(nxt);
  }
}

void Player::pushKeys(int pSet1, int pSet2){
  mQ1->push_key(pSet1);
  mQ2->push_key(pSet2);
}

void Player::stop(){
  mRunning = 0;
}
