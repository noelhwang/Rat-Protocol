#ifndef SYSTEM_H
#define SYSTEM_H

#define DEBUG
#include "arduino.h"

//comparisons are (A>B, B>C, C>D, D>E)
#define NUM_TRAINING_COMPARISONS   4
#define NUM_SCENTS  10


//9 scents, 2 solenoids per scent, no scent is scent 10
#define NUM_SOLENOIDS 20

#define NUM_PARAMS  10
#define NUM_SOLENOID_PARAMS 3
enum{
  
};

enum{
  LEFT_CORRIDOR,
  RIGHT_CORRIDOR
};

//training comparison tests
enum{
  COMPARE_A_B,
  COMPARE_B_C,
  COMPARE_C_D, 
  COMPARE_D_E
};

//scent hierarchy and indices
//VERY IMPORTANT THAT ORDER IS NOT CHANGED
//listed from lowest to highest
enum{
  NO_SCENT,
  SCENT_E,
  SCENT_D,
  SCENT_C,
  SCENT_B,
  SCENT_A,
  SCENT_X,
  SCENT_W, 
  SCENT_Z,
  SCENT_Y
};

enum{
  SCENT_NONE_LEFT,
  SCENT_NONE_RIGHT,
  SCENT_E_LEFT,
  SCENT_E_RIGHT,
  SCENT_D_LEFT, 
  SCENT_D_RIGHT,
  SCENT_C_LEFT,
  SCENT_C_RIGHT,
  SCENT_B_LEFT,
  SCENT_B_RIGHT,
  SCENT_A_LEFT, 
  SCENT_A_RIGHT, 
  SCENT_X_LEFT, 
  SCENT_X_RIGHT, 
  SCENT_W_LEFT, 
  SCENT_W_RIGHT, 
  SCENT_Z_LEFT, 
  SCENT_Z_RIGHT, 
  SCENT_Y_RIGHT, 
  SCENT_Y_LEFT
};

//experiment types
enum{
  TRAINING_SINGLE_SCENT,
  TRAINING_COMPARISON_SCENTS,
  EXPERIMENT_COMPARISONS,
  EXPERIMENT_NOVEL_SCENTS
};

//arduino states
enum{
  STATE_WAITING_FOR_TRIAL_PARAMS,
  STATE_WAITING_FOR_TRIAL_START,
  STATE_WAITING_FOR_CHOICE,
  STATE_WAITING_BETWEEN_TRIALS,
  STATE_TRIAL_COMPLETE
};

//beam break struct 
struct BEAM_BREAK_DATA  {
  unsigned long tStart;
  bool bSet; //true if waiting for rat to exceed time limit
  bool bBroken; //true if rat has exceeded time limit
};

enum{
  TYPE, 
  SCENT_LEFT, 
  SCENT_RIGHT,
  LEFT_FAN_PWM,
  RIGHT_FAN_PWM,
  MAIN_FAN_PWM,
  B_REWARD_CORRECT_SCENT,
  SCENT_REWARD_PROBABILITY,
  T_BEAM_BREAK,
  T_WAIT_TIME
};

struct EXPERIMENT_PARAMS {  
  uint32_t type; //experiment type  
  
  //scent assigned to left and right
  uint32_t scentLeft; 
  uint32_t scentRight;

  uint32_t leftFanPWM;
  uint32_t rightFanPWM;
  uint32_t mainFanPWM;
  
  bool bRewardCorrectScent; //true if dispensing reward with correct scent choice
  uint8_t scentRewardProbability; //scents probabilities 

  //only relevant in single scent trials

  //time required to break the respective beam breaks in milliseconds
  uint32_t tBeamBreak;
  uint32_t tWaitTime; //time between trials
  
};

//system state variables
struct APP_DATA {
  bool bTrialSuccess;
  uint16_t state;//system state as defined in enumeration
  BEAM_BREAK_DATA leftBeamBreak, rightBeamBreak, startBeamBreak;
  EXPERIMENT_PARAMS params; //experiment params passed to micro from matlab
};
void setSolenoid(uint8_t scent, uint8_t side, uint8_t state);
void systemRunTasks();
bool isValidParameters();
void waitingForTrialStart(void);
void waitingForChoice(void);
void waitingBetweenTrials(void);
void isrLeftBeamBroken(void);
void isrRightBeamBroken(void);
void isrStartBeamBroken(void);
bool isBeamBreakBroken(BEAM_BREAK_DATA beamBreak);
void systemReset(); //reinitialize state variables
void waitForChoiceSingleScent(void);
void waitForChoiceTwoScent(void);
bool isCorrectCorridor(void);
void trialComplete(void);

void resetBeamBreak(BEAM_BREAK_DATA beamBreak);
void resetParams(EXPERIMENT_PARAMS params);

#endif
