#include "config.h"
#include "blinkingLEDs.c";
int LED1 = 7;
int LED2 = 8;
int StartButton = 12;
int StopButton = 13;
int IsOperate = 0;
void setup() {
  Serial.begin(9600);
  pinMode(LED1, OUTPUT);   // set I/O pins as output
  pinMode(LED2, OUTPUT);   // set I/O pins as output
  pinMode(StartButton,INPUT);// set button pin as “input”
  pinMode(StopButton,INPUT);// set button pin as “input”
}

void loop() {
  if(digitalRead(StartButton)==HIGH)
  {
    Serial.println("Start button pushed");
    IsOperate = 1;
  }
  if(digitalRead(StopButton)==HIGH)
  {
    Serial.println("Stop button pushed");
    IsOperate = 0;
  }
  if (IsOperate)
  {
    Serial.println("Next turn");
    OneBlink();
  }
}
