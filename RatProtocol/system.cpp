#include "system.h"


APP_DATA appData;

void systemRunTasks(void){
  switch (appData.state) {
    case STATE_WAITING_FOR_TRIAL_PARAMS:
        //TODO
      break;
    case STATE_WAITING_FOR_TRIAL_START:
        //TODO
      break;
    case STATE_WAITING_FOR_CHOICE:
        //TODO
      break;
    case STATE_WRONG_SCENT_CHOSEN:
        //TODO
      break;
    case STATE_CORRECT_SCENT_CHOSEN:
        //TODO
      break;
    default:
      //you should never reach this state
      break;
  }
}
void systemReset(){
  appData.state = STATE_WAITING_FOR_TRIAL_PARAMS;
  appData.numTries = 0;
  
  
}
//reinitialize state variables

void isrLeftBeamBroken{
  //read the pin to see if it's a rising or falling edge
}

void isrRightBeamBroken{
  //read the pin to see if it's a rising or falling edge
}

void ISR_START_BEAM_BROKEN{
  //read the pin to see if it's a rising or falling edge
}
