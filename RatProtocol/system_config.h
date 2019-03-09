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
#define BEAM_BREAK_START_IN 1
#define BEAM_BREAK_LEFT_IN  1  
#define BEAM_BREAK_RIGHT_IN 1

//fans
#define SCENT_LEFT_FAN_PWM_OUT  1
#define SCENT_RIGHT_FAN_PWM_OUT 1 
#define SCENT_EXHAUST_FAN_PWM_OUT 1

//solenoids
#define SCENT_SOLENOID_A_LEFT_OUT  1
#define SCENT_SOLENOID_B_LEFT_OUT  1
#define SCENT_SOLENOID_C_LEFT_OUT  1 
#define SCENT_SOLENOID_D_LEFT_OUT  1
#define SCENT_SOLENOID_E_LEFT_OUT  1 
#define SCENT_SOLENOID_W_LEFT_OUT  1
#define SCENT_SOLENOID_X_LEFT_OUT  1
#define SCENT_SOLENOID_Y_LEFT_OUT  1
#define SCENT_SOLENOID_Z_LEFT_OUT  1

#define SCENT_SOLENOID_A_RIGHT_OUT  1
#define SCENT_SOLENOID_B_RIGHT_OUT  1
#define SCENT_SOLENOID_C_RIGHT_OUT  1 
#define SCENT_SOLENOID_D_RIGHT_OUT  1
#define SCENT_SOLENOID_E_RIGHT_OUT  1 
#define SCENT_SOLENOID_W_RIGHT_OUT  1
#define SCENT_SOLENOID_X_RIGHT_OUT  1
#define SCENT_SOLENOID_Y_RIGHT_OUT  1
#define SCENT_SOLENOID_Z_RIGHT_OUT  1

enum{

  
  
};


#endif
