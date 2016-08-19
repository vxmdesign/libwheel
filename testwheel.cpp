#include<stdio.h>
#include<unistd.h>
#include"PlayerAPI.h"

int main(){
  startWheel();
  pushWheelKeys(0x7FFFFFFF,0x7FFFFFFF); 
 while(1000){
   sleep(1);
   pushWheelKeys(0x7FFFFFFF,0x7FFFFFFF);  
   printf("%f\n", getWheelRate());
 }


}
