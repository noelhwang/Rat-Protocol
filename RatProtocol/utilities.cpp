#include "utilities.h"
#include "events.h"


void logEvent(uint32_t EVENT_ID, uint32_t parameter){

  Serial.print(EVENT_ID);
  Serial.print(" ");
  Serial.println(parameter);
  
}
