#include "system.h"
#include "system_config.h"
#include "arduino.h"
#include "utilities.h"

APP_DATA appData;
//solenoid pin lookup table 
uint8_t solenoidPins[] = {
  SCENT_SOLENOID_NONE_LEFT_OUT, SCENT_SOLENOID_NONE_RIGHT_OUT,
  SCENT_SOLENOID_E_LEFT_OUT, SCENT_SOLENOID_E_RIGHT_OUT, SCENT_SOLENOID_D_LEFT_OUT, SCENT_SOLENOID_D_RIGHT_OUT, 
  SCENT_SOLENOID_C_LEFT_OUT, SCENT_SOLENOID_C_RIGHT_OUT, SCENT_SOLENOID_B_LEFT_OUT, SCENT_SOLENOID_B_RIGHT_OUT, 
  SCENT_SOLENOID_A_LEFT_OUT, SCENT_SOLENOID_A_RIGHT_OUT, SCENT_SOLENOID_X_LEFT_OUT, SCENT_SOLENOID_X_RIGHT_OUT,
  SCENT_SOLENOID_W_LEFT_OUT, SCENT_SOLENOID_W_RIGHT_OUT, SCENT_SOLENOID_Z_LEFT_OUT, SCENT_SOLENOID_Z_RIGHT_OUT,
  SCENT_SOLENOID_Y_LEFT_OUT, SCENT_SOLENOID_Y_RIGHT_OUT
};

void setSolenoidPin(uint8_t pin, uint8_t state){
  digitalWrite(pin, state);
}

void setSolenoid(uint8_t scent, uint8_t side, uint8_t state){
  
  //solenoid drivers are active low, so invert state
  Serial.print("Scent: ");
  Serial.print(scent);
  Serial.print(" Side: ");
  Serial.print(side);
  Serial.print(" State: ");
  Serial.print(state);
  
  uint8_t pinIdx = 2*scent + side;
  Serial.println("Pin index: " + String(pinIdx));
  
  Serial.print("Setting Solenoid on Pin ");
  Serial.print(solenoidPins[(2*(scent) + side)]);
  Serial.print(" to state:  ");
  Serial.println(!state);
  digitalWrite(solenoidPins[(2*(scent) + side)] ,!state);
}


void systemRunTasks(void){
  
  switch (appData.state) {
    case STATE_WAITING_FOR_TRIAL_PARAMS:
        //listen on serial port for trial parameters
      break;
    case STATE_WAITING_FOR_TRIAL_START:
        waitingForTrialStart();
      break;
    case STATE_WAITING_FOR_CHOICE:
      waitingForChoice();
      break;
    case STATE_TRIAL_COMPLETE:
      trialComplete();
    case STATE_WAITING_BETWEEN_TRIALS:
      waitingBetweenTrials();
    break;
    default:
      //you should never reach this state
      break;
  }
}

bool isValidParameters(){
  //checks if system tasks are valid
  return true; 
}


void waitingForTrialStart(void){
  #ifdef DEBUG
  Serial.println("Waiting for Trial to Start");
  #endif 
  attachInterrupt(digitalPinToInterrupt(BEAM_BREAK_START_IN), isrStartBeamBroken, CHANGE);
  digitalWrite(START_LED_OUT, HIGH); //turn on start LED
  while(!isBeamBreakBroken(appData.startBeamBreak)){
    
  }
  appData.state = STATE_WAITING_FOR_CHOICE;
}

void waitingForChoice(void){
  #ifdef DEBUG
  Serial.println("Waiting for choice.");
  #endif
  digitalWrite(START_LED_OUT, LOW); //turn off start LED
  digitalWrite(CORRIDOR_CHOICE_LED_OUT, HIGH); //turn on choose LED
  detachInterrupt(digitalPinToInterrupt(BEAM_BREAK_START_IN)); //disarm start beam break
  //arm beam breaks for smell corridors
  attachInterrupt(digitalPinToInterrupt(BEAM_BREAK_RIGHT_IN), isrLeftBeamBroken, CHANGE);
  attachInterrupt(digitalPinToInterrupt(BEAM_BREAK_LEFT_IN), isrRightBeamBroken, CHANGE);
  
  waitForChoiceTwoScent();  
 
}

void waitingBetweenTrials(){
  //un-arm beam breaks for corridors, turn off all the leds  
  detachInterrupt(digitalPinToInterrupt(BEAM_BREAK_LEFT_IN));
  detachInterrupt(digitalPinToInterrupt(BEAM_BREAK_RIGHT_IN));
  digitalWrite(CORRIDOR_CHOICE_LED_OUT, LOW);
  digitalWrite(START_LED_OUT, LOW);
}

void trialComplete(void){
  Serial.println("Trial Complete");
  logHeader();
  logResults();
  //done with trial, send back results
}

void waitForChoiceTwoScent(){
  //turn the fans on, open scent solenoids
  analogWrite(SCENT_RIGHT_FAN_PWM_OUT, appData.params.rightFanPWM);
  analogWrite(SCENT_LEFT_FAN_PWM_OUT, appData.params.leftFanPWM);
  setSolenoid(appData.params.scentLeft, LEFT_CORRIDOR, HIGH);
  setSolenoid(appData.params.scentRight, RIGHT_CORRIDOR, HIGH);
  
  while(!isBeamBreakBroken(appData.leftBeamBreak) || !isBeamBreakBroken(appData.leftBeamBreak)){
    //wait until either beambreak is broken. the broken beam flag will be set if either trips
  }
  if(isCorrectCorridor()){
    appData.bTrialSuccess = true;
    if(appData.params.type == TRAINING_SINGLE_SCENT){
      if(appData.params.bRewardCorrectScent){
            //dispense food         
      }
    }
    else{
      //dispense food
    }
  }
  else{
    appData.bTrialSuccess = false;
  }
  appData.state = STATE_WAITING_FOR_TRIAL_PARAMS; 
}

void systemReset(){
  //TODO set all the vars in appData to orignal state
  appData.state = STATE_WAITING_FOR_TRIAL_PARAMS;
  appData.bTrialSuccess = false;
  resetBeamBreak(appData.leftBeamBreak);
  resetBeamBreak(appData.rightBeamBreak);
  resetBeamBreak(appData.startBeamBreak);  
}

bool isBeamBreakBroken(BEAM_BREAK_DATA beamBreak){
  if(beamBreak.bSet){ 
    if(millis() - beamBreak.tStart > appData.params.tBeamBreak){
      beamBreak.bBroken = true;
      return true;
    }
    else{
      return false;
    }
  }
  return false;
}

bool isCorrectCorridor(){
  if(appData.params.scentLeft > appData.params.scentRight){
    //in the case that you assign a scent with higher priority on the left
    if(appData.leftBeamBreak.bBroken){
      return true;
    }
    else{
      return false;
    }
  }
  else if (appData.params.scentLeft < appData.params.scentRight){
    if(appData.rightBeamBreak.bBroken){
      return true;
    }
    else{
      return false;
    }
  }
  else{ //you should never end up here
    return false;
    }
  
}


void isrLeftBeamBroken(void){
  if(appData.leftBeamBreak.bSet){ //don't do anything unless the trial has started
    if(!digitalRead(BEAM_BREAK_LEFT_IN)){ //rat enters for first time. assumes the sensor is active high
      digitalWrite(13, HIGH);
      appData.leftBeamBreak.tStart = millis(); //record the start time
      appData.leftBeamBreak.bSet = true; //set flag saying rat has entered
      }
    else{
      digitalWrite(13, LOW);
      //rat leaves beam break after entering
      appData.leftBeamBreak.bSet = false;    
    }
  }
}

void isrRightBeamBroken(void){
  if(appData.startBeamBreak.bSet){ //don't do anything unless the trial has started
      if(!digitalRead(BEAM_BREAK_RIGHT_IN)){ //rat enters for first time. assumes the sensor is active high
        digitalWrite(13, HIGH);
        appData.rightBeamBreak.tStart = millis(); //record the start time
        appData.rightBeamBreak.bSet = true; //set flag saying rat has entered
        }
      else{
        digitalWrite(13, LOW);
        //rat leaves beam break after entering
        appData.rightBeamBreak.bSet = false;    
      }
  }
}

void isrStartBeamBroken(void){
  if(!digitalRead(BEAM_BREAK_START_IN)){ //rat enters for first time. assumes the sensor is active high
    digitalWrite(13, HIGH);
    appData.startBeamBreak.tStart = millis(); //record the start time
    appData.startBeamBreak.bSet = true; //set flag saying rat has entered
  }
  else{
    digitalWrite(13, LOW);
    //rat leaves beam break after entering
    appData.startBeamBreak.bSet = false;    
  }
}

