#include "system_init.h"
#include "system_config.h"
#include "system.h"

extern APP_DATA appData;

void initTimers(){
  //TODO
}
void initIOs(void){
  //TODO
}
void initSteppers(void){
  //TODO
}

void systemInit(void){

  appData.state = STATE_WAITING_FOR_TRIAL_PARAMS;
}
