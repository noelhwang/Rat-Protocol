#ifndef SYSTEM_CONFIG_H
#define SYSTEM_CONFIG_H


//define all pin assignments for peripherals

//
#define PIEZO_OUT

//beam break sensors. NEED TO BE ON PCINT or INT pins for interrupts!
#define BEAM_BREAK_START_IN
#define BEAM_BREAK_LEFT_IN
#define BEAM_BREAK_RIGHT_IN

//fans
#define SCENT_LEFT_FAN_PWM_OUT
#define SCENT_RIGHT_FAN_PWM_OUT 
#define SCENT_EXHAUST_FAN_PWM_OUT

//solenoids
#define SCENT_SOLENOID_A_OUT
#define SCENT_SOLENOID_B_OUT
#define SCENT_SOLENOID_C_OUT
#define SCENT_SOLENOID_D_OUT
#define SCENT_SOLENOID_E_OUT
#define SCENT_SOLENOID_W_OUT
#define SCENT_SOLENOID_X_OUT
#define SCENT_SOLENOID_Y_OUT
#define SCENT_SOLENOID_Z_OUT
#define SCENT_SOLENOID_EMPTY_OUT
#define SCENT_SOLENOID_LEFT_OUT
#define SCENT_SOLENOID_RIGHT_OUT



#endif
