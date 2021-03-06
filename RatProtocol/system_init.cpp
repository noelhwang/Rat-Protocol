#include "system_init.h"
#include "system_config.h"
#include "system.h"

extern APP_DATA appData;





void initTimers(){
  //TODO
}
void initIOs(void){
  //TODO initialize output pins 
  pinMode(SCENT_SOLENOID_A_LEFT_OUT, OUTPUT);
  pinMode(SCENT_SOLENOID_A_RIGHT_OUT, OUTPUT);
  pinMode(SCENT_SOLENOID_B_LEFT_OUT, OUTPUT);
  pinMode(SCENT_SOLENOID_B_RIGHT_OUT, OUTPUT);
  pinMode(SCENT_SOLENOID_C_LEFT_OUT, OUTPUT);
  pinMode(SCENT_SOLENOID_C_RIGHT_OUT, OUTPUT);
  pinMode(SCENT_SOLENOID_D_LEFT_OUT, OUTPUT);
  pinMode(SCENT_SOLENOID_D_RIGHT_OUT, OUTPUT);
  pinMode(SCENT_SOLENOID_E_LEFT_OUT, OUTPUT);
  pinMode(SCENT_SOLENOID_E_RIGHT_OUT, OUTPUT);
  
  pinMode(SCENT_SOLENOID_W_LEFT_OUT, OUTPUT);
  pinMode(SCENT_SOLENOID_W_RIGHT_OUT, OUTPUT);
  pinMode(SCENT_SOLENOID_X_LEFT_OUT, OUTPUT);
  pinMode(SCENT_SOLENOID_X_RIGHT_OUT, OUTPUT);
  pinMode(SCENT_SOLENOID_Y_LEFT_OUT, OUTPUT);
  pinMode(SCENT_SOLENOID_Y_RIGHT_OUT, OUTPUT);
  pinMode(SCENT_SOLENOID_Z_LEFT_OUT, OUTPUT);
  pinMode(SCENT_SOLENOID_Z_RIGHT_OUT, OUTPUT);
  
  

  digitalWrite(SCENT_SOLENOID_A_LEFT_OUT, HIGH);
  digitalWrite(SCENT_SOLENOID_A_RIGHT_OUT, HIGH);
  digitalWrite(SCENT_SOLENOID_B_LEFT_OUT, HIGH);
  digitalWrite(SCENT_SOLENOID_B_RIGHT_OUT, HIGH);
  digitalWrite(SCENT_SOLENOID_C_LEFT_OUT, HIGH);
  digitalWrite(SCENT_SOLENOID_C_RIGHT_OUT, HIGH);
  digitalWrite(SCENT_SOLENOID_D_LEFT_OUT, HIGH);
  digitalWrite(SCENT_SOLENOID_D_RIGHT_OUT, HIGH);
  
  digitalWrite(SCENT_SOLENOID_E_LEFT_OUT, HIGH);
  digitalWrite(SCENT_SOLENOID_E_RIGHT_OUT, HIGH);
  digitalWrite(SCENT_SOLENOID_W_LEFT_OUT, HIGH);
  digitalWrite(SCENT_SOLENOID_W_RIGHT_OUT, HIGH);
  digitalWrite(SCENT_SOLENOID_X_LEFT_OUT, HIGH);
  digitalWrite(SCENT_SOLENOID_X_RIGHT_OUT, HIGH);
  digitalWrite(SCENT_SOLENOID_Y_LEFT_OUT, HIGH);
  digitalWrite(SCENT_SOLENOID_Y_RIGHT_OUT, HIGH);
  digitalWrite(SCENT_SOLENOID_Z_LEFT_OUT, HIGH);
  digitalWrite(SCENT_SOLENOID_Z_RIGHT_OUT, HIGH);
  

  
  pinMode(BEAM_BREAK_START_IN, INPUT);
  pinMode(BEAM_BREAK_LEFT_IN, INPUT);
  pinMode(BEAM_BREAK_RIGHT_IN, INPUT);

  pinMode(13, OUTPUT);//debug led
  digitalWrite(13, LOW);
  
}
void initSteppers(void){
  //TODO
}

void initInterrupts(void){
  //initialize interrupts
}

void systemInit(void){

  appData.state = STATE_WAITING_FOR_TRIAL_PARAMS;
  initIOs();
}
