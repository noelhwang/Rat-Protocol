#include "SerialCommand.h"
#include "system.h"
#include "system_config.h"
#include "serial_config.h"
#include "utilities.h"

extern APP_DATA appData;

bool bBeamBreakTest = false;

SerialCommand matlab;

void nak(){
  Serial.println("NAK");
}

void ack(){
  Serial.println("ACK");
}

void loadParams(void){
  char *arg; 
  for(int iParam = 0; iParam < NUM_PARAMS; iParam++){
    arg=matlab.next();  
    if (arg != NULL){
       switch(iParam){
        case TYPE:
          appData.params.type = atoi(arg);
          #ifdef DEBUG
          Serial.print("Experiment Type: ");
          Serial.println(atoi(arg));
          #endif
          break;
        case SCENT_LEFT:
          appData.params.scentLeft = atoi(arg);
          break;
        case SCENT_RIGHT:
          appData.params.scentRight = atoi(arg);
          break;
        case LEFT_FAN_PWM:
          appData.params.leftFanPWM = atoi(arg);
          break;
        case RIGHT_FAN_PWM:
          appData.params.rightFanPWM = atoi(arg);
          break;
        case MAIN_FAN_PWM:
          appData.params.mainFanPWM = atoi(arg);
          break;
        case B_REWARD_CORRECT_SCENT:
          appData.params.bRewardCorrectScent = atoi(arg);
          break;
        case SCENT_REWARD_PROBABILITY:
          appData.params.scentRewardProbability = atoi(arg);
          break;
        case T_BEAM_BREAK:
          appData.params.tBeamBreak = atoi(arg);
        break;
        case T_WAIT_TIME:
          appData.params.tWaitTime = atoi(arg);
          break;
        default:
          Serial.println("PARAMETER OUT OF INDEX");
          break;
      }  
    }
  }
  logHeader();
}

void startExperiment(void){
  ack();
}

void stopExperiment(void){
  ack();  
}

void testSolenoidPin(void){

  char *arg;
   uint8_t params[2];
   for(int iParam = 0; iParam < 2; iParam++){
    arg=matlab.next();  
    if (arg != NULL){
      params[iParam] = atoi(arg);
    }
   }
  Serial.println("Testing Solenoid");
 setSolenoidPin(params[0], params[1]);
 

}

void testSolenoid(void){

   char *arg;
   uint8_t params[3];
   for(int iParam = 0; iParam < NUM_SOLENOID_PARAMS; iParam++){
    arg=matlab.next();  
    if (arg != NULL){
      params[iParam] = atoi(arg);
    }
   }
  Serial.println("Testing Solenoid");
  setSolenoid(params[0], params[1], params[2]);
}

void testFan(void){
  ack();
}

void testFood(void){
  ack();
}

void dumpState(void){
  ack();
  logHeader();
}

void testBeamBreak(){
  bBeamBreakTest = true;
  appData.params.tBeamBreak = 500; //default 500ms bem break time 
  Serial.println("Starting Beam Break Test");
  
  attachInterrupt(digitalPinToInterrupt(BEAM_BREAK_START_IN), isrStartBeamBroken, CHANGE);
  attachInterrupt(digitalPinToInterrupt(BEAM_BREAK_LEFT_IN), isrLeftBeamBroken, CHANGE);
  attachInterrupt(digitalPinToInterrupt(BEAM_BREAK_RIGHT_IN), isrRightBeamBroken, CHANGE);  
  
  
  while(bBeamBreakTest){
    matlab.readSerial(); //wait for end command
    if(appData.startBeamBreak.bSet){
      Serial.println("Start beam break broken");
    }
    if(appData.rightBeamBreak.bSet){
      Serial.println("Right csorridor beam break broken");
    }
    if(appData.leftBeamBreak.bSet){
      Serial.println("Left corridor beam break broken");
    }
  }
  detachInterrupt(digitalPinToInterrupt(BEAM_BREAK_START_IN));
  detachInterrupt(digitalPinToInterrupt(BEAM_BREAK_LEFT_IN));
  detachInterrupt(digitalPinToInterrupt(BEAM_BREAK_RIGHT_IN));
  Serial.println("Test Terminated");
}

void stopBeamBreakTest(){
  
  bBeamBreakTest = false;
}

void initCommands(void){
  matlab.addCommand("PRM", loadParams); //to start experiment and load commands
  matlab.addCommand("BGN", startExperiment);
  matlab.addCommand("END", stopExperiment); //to stop trial   
  //test functions for hardware testing
  matlab.addCommand("SOL", testSolenoid);//
  matlab.addCommand("FAN", testFan);
  matlab.addCommand("RWD", testFood);
  matlab.addCommand("BRK", testBeamBreak);
  matlab.addCommand("ENDTEST", stopBeamBreakTest);// stop beam break test
  matlab.addCommand("MEM", dumpState); //dumps appData states
  matlab.addCommand("SLT", testSolenoidPin);
  
  matlab.addDefaultHandler(nak); //not 
}

