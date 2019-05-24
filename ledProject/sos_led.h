#ifndef SOS_LED_H
#define SOS_LED_H

typedef enum FSM{
    S,
    O,
    P
  } FSM_t;

void sos_ledBlink( void );

#endif