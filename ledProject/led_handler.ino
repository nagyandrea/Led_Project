#include "led_handler.h"

static LED_STATUS_t ledState[] =
{
   {LED0, LOW},
   {LED1, LOW}, 
   {LED2, LOW},
   {LED3, LOW},
   {LED4, LOW},
   {LED5, LOW},
};

void LedInit(void)
{
    pinMode(LED0, OUTPUT);
    pinMode(LED1, OUTPUT);
    pinMode(LED2, OUTPUT);
    pinMode(LED3, OUTPUT);
    pinMode(LED4, OUTPUT);
    pinMode(LED5, OUTPUT);

    digitalWrite(LED0, LOW);
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
    digitalWrite(LED5, LOW);
}

int readtLedValue(int ledNumber)
{
    return(ledState[ledNumber].value);
}

void WriteLed(int ledNumber, int newState)
{
    if (ledNumber >= 0 && 
        ledNumber < sizeof(ledState))
    {
        digitalWrite(ledState[ledNumber].pin, newState);
        ledState[ledNumber].value = newState;
        
    }
}
