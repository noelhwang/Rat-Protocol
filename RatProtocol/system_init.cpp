#include "system_init.h"
#include "system_config.h"
#include "system.h"

extern APP_DATA appData;

//solenoid pin lookup table 
extern uint8_t solenoidPins[] = {
  SCENT_SOLENOID_E_LEFT_OUT, SCENT_SOLENOID_E_RIGHT_OUT, SCENT_SOLENOID_D_LEFT_OUT, SCENT_SOLENOID_D_RIGHT_OUT, 
  SCENT_SOLENOID_C_LEFT_OUT, SCENT_SOLENOID_C_RIGHT_OUT, SCENT_SOLENOID_B_LEFT_OUT, SCENT_SOLENOID_B_RIGHT_OUT, 
  SCENT_SOLENOID_A_LEFT_OUT, SCENT_SOLENOID_A_RIGHT_OUT, SCENT_SOLENOID_X_LEFT_OUT, SCENT_SOLENOID_X_RIGHT_OUT,
  SCENT_SOLENOID_W_LEFT_OUT, SCENT_SOLENOID_W_RIGHT_OUT, SCENT_SOLENOID_Z_LEFT_OUT, SCENT_SOLENOID_Z_RIGHT_OUT,
  SCENT_SOLENOID_Y_LEFT_OUT, SCENT_SOLENOID_Y_RIGHT_OUT
};



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
