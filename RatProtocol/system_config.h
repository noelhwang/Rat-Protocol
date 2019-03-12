#ifndef SYSTEM_CONFIG_H
#define SYSTEM_CONFIG_H

#include "system.h"
//define all pin assignments for peripherals

//
#define PIEZO_OUT       1
//LEDs
#define CORRIDOR_CHOICE_LED_OUT    1
#define START_LED_OUT   1



//beam break sensors. NEED TO BE ON PCINT or INT pins for interrupts!
#define BEAM_BREAK_START_IN 2 //for debug
#define BEAM_BREAK_LEFT_IN  11  
#define BEAM_BREAK_RIGHT_IN 12

//fans
#define SCENT_LEFT_FAN_PWM_OUT  1
#define SCENT_RIGHT_FAN_PWM_OUT 1 
#define SCENT_EXHAUST_FAN_PWM_OUT 1

//solenoids
#define SCENT_SOLENOID_A_LEFT_OUT     4
#define SCENT_SOLENOID_A_RIGHT_OUT    5

#define SCENT_SOLENOID_B_LEFT_OUT     6
#define SCENT_SOLENOID_B_RIGHT_OUT    7

#define SCENT_SOLENOID_C_LEFT_OUT  8
#define SCENT_SOLENOID_C_RIGHT_OUT  9 

#define SCENT_SOLENOID_D_LEFT_OUT  10
#define SCENT_SOLENOID_D_RIGHT_OUT  11

#define SCENT_SOLENOID_E_LEFT_OUT  22 
#define SCENT_SOLENOID_E_RIGHT_OUT  23 

#define SCENT_SOLENOID_W_LEFT_OUT  24
#define SCENT_SOLENOID_W_RIGHT_OUT  25

#define SCENT_SOLENOID_X_LEFT_OUT  26
#define SCENT_SOLENOID_X_RIGHT_OUT  27

#define SCENT_SOLENOID_Y_LEFT_OUT  28
#define SCENT_SOLENOID_Y_RIGHT_OUT  29

#define SCENT_SOLENOID_Z_LEFT_OUT  30
#define SCENT_SOLENOID_Z_RIGHT_OUT  31

#define SCENT_SOLENOID_NONE_LEFT_OUT  32
#define SCENT_SOLENOID_NONE_RIGHT_OUT 33

enum{

  
  
};


#endif
