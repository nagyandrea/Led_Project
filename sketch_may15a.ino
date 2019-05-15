  int led0 = 1;
  int led1 = 2;
  int led2 = 3;
  int led3 = 4;
  int led4 = 5;
  int led5 = 6;  

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
