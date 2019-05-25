#include "led_handler.h"

static LED_STATUS_t ledStates[] =
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

static int GetLed(int ledPin)
{
    int led = -1;
    int i, n;
    
    for(i=0, n=sizeof(ledStates); i<n; i++)
    {
        if (ledStates[i].pin == ledPin)
        {
            led = i;
            break;
        }
    }

    return(led);
}

int GetLedValue(int ledPin)
{
    int ledValue = -1;
    int led      = -1;
    int i, n;
    
    led = GetLed(ledPin);
    if (led != -1)
    {
        ledValue = ledStates[led].value;
    }
    
    return(ledValue);
}

void WriteLed(int ledPin, int newState)
{
    int led = -1;

    led = GetLed(ledPin);
    if (led != -1)
    {
        ledStates[led].value = newState;
        digitalWrite(ledPin, newState);
    }
}

void SwitchLedState(int ledPin)
{
    int led         = -1;
    int newLedState = -1;

    led = GetLed(ledPin);
    if (led != -1)
    {
        newLedState          = (ledStates[led].value == LOW) ? HIGH : LOW;
        ledStates[led].value = newLedState;
        digitalWrite(ledPin, newLedState);
    }
}
