#include "utilities.h"
#include "events.h"

/*
 * struct EXPERIMENT_PARAMS {  
  uint16_t type; //experiment type  
  
  //scent assigned to left and right
  uint16_t scentLeft; 
  uint16_t scentRight;

  uint16_t leftFanPWM;
  uint16_t rightFanPWM;
  uint16_t mainFanPWM;
  
  //probability that scent will yield success
  uint16_t successProbability; //probability of current reward scent
  //only relevant in single scent trials

  //time required to break the respective beam breaks in milliseconds
  uint32_t tBeamBreak;
  uint32_t tWaitTime; //time between trials
  uint8_t scentRewardProbability; //scents probabilities 
  
};
 * 
 */

extern APP_DATA appData;

void logEvent(uint32_t EVENT_ID, uint32_t parameter){
  Serial.print(EVENT_ID);
  Serial.print(" ");
  Serial.println(parameter);
}

void logHeader(void){
  
  String outputString;
  Serial.println("Experiment Parameters");
  outputString = ("Experiment: " + String(appData.params.type) +  " Left: " + String(appData.params.scentLeft) + " Right: " + String(appData.params.scentRight) + " BreakTime(ms): " 
                  + String(appData.params.tBeamBreak) + " Reward: " + String(appData.params.bRewardCorrectScent) 
                  +  " Probability: " + String(appData.params.scentRewardProbability)); 
  Serial.println(outputString);
}

void logResults(void){
  Serial.println("Trial Result: " + String(appData.bTrialSuccess));
}

