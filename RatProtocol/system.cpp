#include "system.h"
#include "system_config.h"
#include "arduino.h"

APP_DATA appData;

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
}


void waitingForTrialStart(void){
  #ifdef DEBUG
  Serial.println("Waiting for Trial to Start");
  
  #endif 
  attachInterrupt(digitalPinToInterrupt(BEAM_BREAK_START_IN), isrStartBeamBroken, CHANGE);
  digitalWrite(START_LED_OUT, HIGH); //turn on start LED
  
  unsigned long currentTime;  
  if(appData.startBeamBreak.bSet){ //if the rat's entered
    //if the beam's been broken, check the time difference between start time and now
    currentTime = millis();
    if(currentTime - appData.startBeamBreak.tStart > appData.params.tBeamBreakStart){
      appData.state = STATE_WAITING_FOR_CHOICE; //success
      Serial.println("RAT HAS STARTED TRIAL");
    }
  }

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
  
  switch  (appData.params.type){
    case TRAINING_SINGLE_SCENT:

    uint8_t corridor; 
    corridor = NULL_CORRIDOR;
      //check to see which corridor the scent is assigned to
      if(appData.params.scentLeft == NO_SCENT){
        //scent is on the right corridor
        corridor = RIGHT_CORRIDOR;
      }
      else{
        //scent is on the left corridor
        corridor = LEFT_CORRIDOR;
      }
      
      if(corridor == LEFT_CORRIDOR){
        //TODO open scent specific left corridor solenoid  
        analogWrite(SCENT_LEFT_FAN_PWM_OUT, appData.params.leftFanPWM);
      }
      else{
        analogWrite(SCENT_RIGHT_FAN_PWM_OUT, appData.params.rightFanPWM);

        //TODO open scent specific right corridor solenoid
      }            
      break;
    case TRAINING_COMPARISON_SCENTS:
      
      break;
    case EXPERIMENT_COMPARISONS:
      
      break;
    case EXPERIMENT_NOVEL_SCENTS:
    
      break;
    default:
      //never end up here
      break;
  }
}

void waitingBetweenTrials(){
  detachInterrupt(digitalPinToInterrupt(BEAM_BREAK_LEFT_IN));
  detachInterrupt(digitalPinToInterrupt(BEAM_BREAK_RIGHT_IN));
  digitalWrite(CORRIDOR_CHOICE_LED_OUT, LOW);
  digitalWrite(START_LED_OUT, LOW);
  switch(appData.params.type){
    case TRAINING_SINGLE_SCENT:
          
      break;
    case TRAINING_COMPARISON_SCENTS:
    
      break;
    case EXPERIMENT_NOVEL_SCENTS:
    
      break;
    default:
      //never end up here
      break;
  }
}
void systemReset(){
  appData.state = STATE_WAITING_FOR_TRIAL_PARAMS;
}

//Interrupt Service Routines
void generic_trigger_isr(uint8_t pin, BEAM_BREAK_DATA beamBreak){
  if(digitalRead(pin)){ //rat enters for first time. assumes the sensor is active high
    beamBreak.tStart = millis(); //record the start time
    beamBreak.bSet = true; //set flag saying rat has entered
  }
  else{
    //rat leaves beam break after entering
    beamBreak.bSet = false;    
  }
}

void isrLeftBeamBroken(void){
  if(appData.startBeamBreak.bSet){ //don't do anything unless the trial has started
    generic_trigger_isr(BEAM_BREAK_LEFT_IN, appData.leftBeamBreak);  
  }
}
void isrRightBeamBroken(void){
  if(appData.startBeamBreak.bSet){ //don't do anything unless the trial has started
    generic_trigger_isr(BEAM_BREAK_RIGHT_IN, appData.rightBeamBreak);
  }
}
void isrStartBeamBroken(void){
  generic_trigger_isr(BEAM_BREAK_START_IN, appData.startBeamBreak);  
}


