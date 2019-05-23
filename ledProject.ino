int BASE = 2;  // the I/O pin for the first LED
int NUM = 6;   // number of LEDs
int inpinOn = 8;
int valOn;  // define val
int inpinOff = 9;
int valOff;  // define val
int noOfLed = 1;
int onWasPressed = 0;
int offWasPressed = 0;

void setup()
{
   for (int i = BASE; i < BASE + NUM; i ++) 
   {
     pinMode(i, OUTPUT);   // set I/O pins as output
   }
   pinMode(inpinOn,INPUT);  // set button pin as “input”
   pinMode(inpinOff,INPUT);
}

void loop()
{  

  valOn = digitalRead(inpinOn);
  valOff = digitalRead(inpinOff);

  if(valOn == HIGH)
  {
    onWasPressed = 1;
  }
  
  if(valOff == HIGH)
  {
    offWasPressed = 1;
    onWasPressed = 0;
  }
  
   if(onWasPressed==1)// check if the button is pressed, if yes, turn on the LEDs
   {
     for (int i = BASE; i < BASE + NUM; i ++) 
     {
      if(noOfLed ==1)
      {
        digitalWrite(i, HIGH);    // turn on LEDs one by one
        delay(200); 
        digitalWrite(i, LOW);
        delay(200);
      }
      else
      {
        digitalWrite(i, HIGH);
        if ( i != BASE + NUM - 1)
        {
          digitalWrite(i + 1, HIGH);
        }
        else
        {
          digitalWrite(BASE, HIGH);
        }     
        delay(200); 
     
        digitalWrite(i, LOW);
        if ( i != BASE + NUM - 1)
        {
          digitalWrite(i + 1, LOW);
        }
        else
        {
        digitalWrite(BASE, LOW);
        }  
         delay(200);
      }
     }
     
     if(noOfLed == 1)
     {
      noOfLed = 2;
     }
     else
     {
      noOfLed = 1;
     }
   }
   
   if(offWasPressed==1)// check if the button is pressed, if yes, turn off the LEDs
   {
     for (int i = BASE; i < BASE + NUM; i++) 
     {
       digitalWrite(i, LOW);
     }
   }
   
}
