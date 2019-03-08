#ifndef UTILITIES_H
#define UTILITIES_H

#include "system.h"

void logEvent(uint32_t EVENT_ID, uint32_t parameter); 
void logHeader(EXPERIMENT_PARAMS params);
bool isSuccess(uint8_t probability); 


#endif
