#ifndef LED_HANDLER_H
#define LED_HANDLER_H

    #include "Arduino.h"
    #include "globdefs.h"
    
    // constant definitions
    #define LED0        2u
    #define LED1        3u
    #define LED2        4u
    #define LED3        5u
    #define LED4        6u
    #define LED5        7u
    
    // structured types
    typedef struct led_status{
       int pin;
       int value;
    }LED_STATUS_t;
    
    // global functions
    void LedInit(void);
    int  GetLedValue(int ledPin);
    void WriteLed(int ledNumber, int newState);
    void SwitchLedState(int ledPin);

#endif //LED_HANDLER_H
