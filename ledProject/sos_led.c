#include "sos_led.h"
#include <Arduino.h>

#define SHORT 250u
#define LONG  500u
#define PAUSE 15000u

const int led0  = 2;
const int led1  = 3;
const int led2  = 4;
const int led3  = 5;
const int led4  = 6;
const int led5  = 7;

static FSM_t FSM_SOS        = S;

static int repetition_cnt   = 0;
static int S_cnt            = 0;
static int P_cnt            = 0;
static int iteration_cnt    = 3;
static int delay_cnt        = 0;

void sos_ledBlink(void)
{
    static int delayLimit = 0;

    switch(FSM_SOS){
      case S:
        MorseBlink(SHORT);
        iteration_cnt--;
        if(iteration_cnt == 0)
        {
          S_cnt++;
          S_cnt %= 3;   //S_cnt either 0, 1 or 2
          if(S_cnt >= 2)
          {
              FSM_SOS = P;
              S_cnt = 0;
          }
          else
          {
              FSM_SOS = O;
          }

          iteration_cnt = 3;
        }
      break;

      case O:
        MorseBlink(LONG);
        iteration_cnt--;
        if(iteration_cnt == 0)
        {
          FSM_SOS = S;
          iteration_cnt = 3;
        }
      break;

      case P:
        delay(1);
        delay_cnt++;

        if(!P_cnt)
            delayLimit = 299;
        else // P_cnt = 1
            delayLimit = 14999;

        if(delay_cnt >= delayLimit)
        {
            P_cnt++;
            P_cnt %= 2; // P_cnt either 0 or 1
            FSM_SOS = S;
            delay_cnt = 0;
        }
      break;
    }
}

void MorseBlink(int time)
{
  digitalWrite(led0, HIGH);
  digitalWrite(led1, HIGH);
  digitalWrite(led4, HIGH);
  digitalWrite(led5, HIGH);
  delay(time);
  digitalWrite(led0, LOW);
  digitalWrite(led1, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
  delay(SHORT);
}