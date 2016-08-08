#include "PlayerAPI.h"


Player *local_player=NULL;

void startWheel(){
  wiringPiSetup();  
  local_player = new Player(); 
}

double getWheelRate(){
  if(local_player == NULL){
    return 0.0;   
  }
  return local_player->currentRate();
}

int getWheelQueueSize(){
  if(local_player == NULL){
    return -1;   
  }
  return local_player->queueSize();
}

void pushWheelKeys(int pKey1, int pKey2){
  if(local_player == NULL){
    return;   
  }
  return local_player->pushKeys(pKey1, pKey2);
}
