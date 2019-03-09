#ifndef SYSTEM_CONFIG_H
#define SYSTEM_CONFIG_H


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
#define SCENT_SOLENOID_A_OUT  1
#define SCENT_SOLENOID_B_OUT  1
#define SCENT_SOLENOID_C_OUT  1 
#define SCENT_SOLENOID_D_OUT  1
#define SCENT_SOLENOID_E_OUT  1 
#define SCENT_SOLENOID_W_OUT  1
#define SCENT_SOLENOID_X_OUT  1
#define SCENT_SOLENOID_Y_OUT  1
#define SCENT_SOLENOID_Z_OUT  1
#define SCENT_SOLENOID_EMPTY_OUT  1 
#define SCENT_SOLENOID_LEFT_OUT 1
#define SCENT_SOLENOID_RIGHT_OUT  1




#endif
