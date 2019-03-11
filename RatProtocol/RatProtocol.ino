#include "system_init.h"
#include "system.h"
#include "Serial_Config.h"
#include "SerialCommand.h"

extern SerialCommand matlab;

void setup() {
  initCommands();
  Serial.begin(9600);
  Serial.println("Starting Serial");
  
  systemInit();
  
}

void loop() {
  matlab.readSerial();
  //systemRunTasks();
}
