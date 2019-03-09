#include "system_init.h"
#include "system_config.h"
#include "system.h"

extern APP_DATA appData;

void initTimers(){
  //TODO
}
void initIOs(void){
  //TODO initialize output pins 
}
void initSteppers(void){
  //TODO
}

void initInterrupts(void){
  //initialize interrupts
}

void systemInit(void){

  appData.state = STATE_WAITING_FOR_TRIAL_PARAMS;
}
