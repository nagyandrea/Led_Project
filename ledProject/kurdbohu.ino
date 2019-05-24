#include "globdefs.h"
#include "kurdbohu.h"

// Static variables:
static int state        = LOW;
static int button_state = LOW;    		      // variable for reading the pushbutton status

// Global functions:
void kurdbohu_setup(void)
{
    Serial.begin(9600);
    pinMode(LED0, OUTPUT);   // initialize the LED pin as an output:
    pinMode(SWITCH0, INPUT);    // initialize the pushbutton pin as an input:
}

void kurdbohu_loop(void)
{
    button_state = digitalRead(SWITCH0);   // read the state of the pushbutton value
    
    // check if the pushbutton is pressed. If it is, switch LED on/off:
    if (button_state == HIGH)
    {
        if(state == HIGH) state = LOW;
        else state = HIGH;
        digitalWrite(LED0, state);
        delay(500);
    } 
    Serial.println(state);
}
