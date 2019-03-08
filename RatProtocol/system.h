#ifndef SYSTEM_H
#define SYSTEM_H

#include "arduino.h"

enum{
  NO_SCENT,
  SCENT_A,
  SCENT_B,
  SCENT_C,
  SCENT_D,
  SCENT_E,
  SCENT_F, 
  SCENT_G,
  SCENT_H,
  SCENT_I,
  SCENT_J,
  SCENT_K
};

enum{
  STATE_WAITING_FOR_TRIAL_PARAMS,
  STATE_WAITING_FOR_TRIAL_START,
  STATE_WAITING_FOR_CHOICE,
  STATE_WRONG_SCENT_CHOSEN,
  STATE_CORRECT_SCENT_CHOSEN
};

struct EXPERIMENT_PARAMS {

  uint16_t scentLeft;
  uint16_t scentRight;
  uint16_t successProbability;
  uint32_t startDelayTime;
  uint32_t rewardDelayTime;
  uint32_t punishmentDelayTime;
  bool bSingleScent;
};

//system state variables
struct APP_DATA {
  
  uint16_t state;//system state
  uint16_t numTries; //number of experiment tries recorded
  EXPERIMENT_PARAMS params;
};

void systemRunTasks();
void systemReset(); //reinitialize state variables

#endif
