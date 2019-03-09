#ifndef SYSTEM_H
#define SYSTEM_H

#include "arduino.h"




//comparisons are (A>B, B>C, C>D, D>E)
#define NUM_TRAINING_COMPARISONS   4
#define NUM_SCENTS  10


enum{
  NULL_CORRIDOR,
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
  STATE_WAITING_BETWEEN_TRIALS
};


struct SCENT_SCORE_BOARD{
  uint16_t numTrials; //how many total sequences have been run
  uint16_t numSuccesses[NUM_TRAINING_COMPARISONS];
};

//beam break struct 
struct BEAM_BREAK_DATA  {
  unsigned long tStart;
  bool bSet;
};

struct EXPERIMENT_PARAMS {  
  uint16_t type; //experiment type  
  
  //scent assigned to left and right
  uint16_t scentLeft; 
  uint16_t scentRight;

  uint16_t leftFanPWM;
  uint16_t rightFanPWM;
  uint16_t mainFanPWM;
  
  //probability that scent will yield success
  uint16_t successProbability; //probability of current reward scent

  //time required to break the respective beam breaks in milliseconds
  uint32_t tBeamBreakStart;
  uint32_t tBeamBreakReward;
  uint32_t tBeamBreakPunishment;
  float scentRewardProbability[NUM_SCENTS]; //scents probabilities 
  
};

//system state variables
struct APP_DATA {
  uint16_t state;//system state as defined in enumeration
  SCENT_SCORE_BOARD scoreBoard; //trial successes
  BEAM_BREAK_DATA leftBeamBreak, rightBeamBreak, startBeamBreak;
  EXPERIMENT_PARAMS params; //experiment params passed to micro from matlab
};

void systemRunTasks();
bool isValidParameters();
void waitingForTrialStart(void);
void waitingForChoice(void);
void waitingBetweenTrials(void);
void isrLeftBeamBroken(void);
void isrRightBeamBroken(void);
void isrStartBeamBroken(void);
void systemReset(); //reinitialize state variables

#endif
