#include "config.h"
#include "Arduino.h"

void OneBlink(){
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, LOW);
  delay(300);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, HIGH);
  delay(300);
     
}
