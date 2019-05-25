#include "led_handler.h"
#include "switch_handler.h"

 SW_STATUS_t sw = {RELEASED, RELEASED};
  
void setup() {
  
  LedInit();
  SwitchInit();
}

void loop() {
  
  static int EN = 0;
  
  
  sw = ReadSwitchStatus();

  if(sw.sw0 == PRESSED)
  {
    EN = 1;
  }

  if(sw.sw1 == PRESSED)
  {
    EN = 0;
  }

  if(EN)
  {
#ifdef AGOSDAHU
    
#elif VEZSBAHU

#elif KURDBOHU
    kurdbohu_loop(sw);
#elif DANIGEHU

#elif NAGYKAHU

#elif NAGYANHU

#elif KISSKAHU

#endif
  }
}
