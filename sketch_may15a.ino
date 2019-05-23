  const int led0  = 2;
  const int led1  = 3;
  const int led2  = 4;
  const int led3  = 5;
  const int led4  = 6;
  const int led5  = 7;

  const int sw0   = 8;
  const int sw1   = 9;

  typedef enum FSM{
    S1,
    O1,
    S_1,
    P1,
    S2,
    O2,
    S_2,
    P2
  } FSM_t;


#define SHORT 250u
#define LONG  500u
#define PAUSE 15000u

void MorseBlink(int);

void setup() {
  // put your setup code here, to run once:
  pinMode(led0, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);

  pinMode(sw0, INPUT_PULLUP);
  pinMode(sw1, INPUT_PULLUP);

  digitalWrite(led0, LOW);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);

}

void loop() {
  // put your main code here, to run repeatedly:
  int i, j;
  static int EN = 0;
  static int sw0State = 1;
  static int sw0_old = 1;
  static int sw1State = 1;
  static int sw1_old = 1;

  static FSM_t FSM_SOS = S1;
  static int iteration_cnt = 3;
  volatile static int delay_cnt = 0;

  sw0_old = sw0State;
  sw1_old = sw1State;

  delay(1);
  sw0State = digitalRead(sw0);
  sw1State = digitalRead(sw1);

  if(sw0_old && !sw0State)
    EN = 1;

  if(sw1_old && !sw1State)
    EN = 0;

  // Test
  digitalWrite(led3, EN);
  if(EN){
    switch(FSM_SOS){
      case S1:
        MorseBlink(SHORT);
        iteration_cnt--;
        if(iteration_cnt == 0)
        {
          FSM_SOS = O1;
          iteration_cnt = 3;
        }
      break;

      case O1:
        MorseBlink(LONG);
        iteration_cnt--;
        if(iteration_cnt == 0)
        {
          FSM_SOS = S_1;
          iteration_cnt = 3;
        }
      break;

      case S_1:
        MorseBlink(SHORT);
        iteration_cnt--;
        if(iteration_cnt == 0)
        {
          FSM_SOS = P1;
          iteration_cnt = 3;
        }
      break;

      case P1:
        delay(1);
        delay_cnt++;
        if(delay_cnt >= 299) //300ms
        {
          FSM_SOS = S2;
          delay_cnt = 0;
        }
      break;

      case S2:
        MorseBlink(SHORT);
        iteration_cnt--;
        if(iteration_cnt == 0)
        {
          FSM_SOS = O2;
          iteration_cnt = 3;
        }
      break;

      case O2:
        MorseBlink(LONG);
        iteration_cnt--;
        if(iteration_cnt == 0)
        {
          FSM_SOS = S_2;
          iteration_cnt = 3;
        }
      break;

      case S_2:
        MorseBlink(SHORT);
        iteration_cnt--;
        if(iteration_cnt == 0)
        {
          FSM_SOS = P2;
          iteration_cnt = 3;
        }
      break;

      case P2:
        delay(1);
        delay_cnt++;
        if(delay_cnt >= 14999) //15000ms
        {
          FSM_SOS = S1;
          delay_cnt = 0;
        }
      break;
    }
  }

  if(0)
  {
    for(j = 0; j<2; j++){
      for(i = 0; i<3; i++)
        MorseBlink(SHORT);
      for(i = 0; i<3; i++)
        MorseBlink(LONG);
      for(i = 0; i<3; i++)
        MorseBlink(SHORT);
      delay(250);
    }
    delay(PAUSE);
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
  delay(200);
}
