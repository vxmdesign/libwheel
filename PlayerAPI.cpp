#include "PlayerAPI.h"


Player *local_player=NULL;

int val2;

void startWheel(){
  wiringPiSetup();  
  printf("starting wheel from c \n");
  local_player = new Player(); 
  val2 = 0;
}

double getWheelRate(){
  if(local_player == NULL){
    return 0.0;   
  } 
  return local_player->currentRate();
}

int getWheelQueueSize(){
  if(local_player == NULL){
    printf("getWheelQueue - player is null \n");
    return -1;   
  }
  printf("getWheelQueueSize - returning queue size \n");
  return local_player->queueSize();
}

void pushWheelKeys(int pKey1, int pKey2){
  printf("inside pushWheelKeys \n");
  if(local_player == NULL){
    printf("pushWheelKeys - player is null \n");
    return;   
  }
  printf("pushing %d and %d \n", pKey1, pKey2);
  return local_player->pushKeys(pKey1, pKey2);
}

int getNumber(){
  return val2;
}

void setNumber(int val){
  val2 = val;
}
