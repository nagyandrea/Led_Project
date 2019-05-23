int ledPins[] = {7,6,5,4,3,2};
int buttonPinOn = 11;
int buttonPinOff = 9;

int buttonStateOn = 0;
int buttonStateOff = 0;

int counter = 0;
int working = 0;

void setup()
{
  for (int i =0;i<6;i++)
  {
    pinMode(ledPins[i], OUTPUT);
  }
  pinMode(buttonPinOn, INPUT);
  pinMode(buttonPinOff, INPUT);
}

void loop()
{
  buttonStateOn = digitalRead(buttonPinOn);
  buttonStateOff = digitalRead(buttonPinOff);

  if (buttonStateOn == HIGH)
  {
    working = 1;
  }

  if (buttonStateOff == HIGH)
  {
    working = 0;
  }
  
  if (working == 1 )
  {
       displayBinary(counter);
       delay(500); 
       counter++;
       
       if (counter > 30)
       {
         counter = 0;
       }
  }  
}


void displayBinary(byte numToShow)
{
  for (int i =0;i<5;i++)
  {
    if (bitRead(numToShow, i)==1)
    {
      digitalWrite(ledPins[i], HIGH); 
    }
    else
    {
      digitalWrite(ledPins[i], LOW); 
    }
  }
}
