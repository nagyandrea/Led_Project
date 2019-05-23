int whiteled_1 = 3;
int whiteled_2 = 4;
int whiteled_3 = 5;
int whiteled_4 = 6;
int redled_1 = 2;
int redled_2 = 7;
bool whiteBlink = true;
int counter;
int buttonOnPin = 8;
int buttonOffPin = 9;
int buttonOnState = 0;
bool isOnPressed = false;
int buttonOffState = 0;

void setup()
{
  pinMode(whiteled_1, OUTPUT);     
  pinMode(whiteled_2, OUTPUT);     
  pinMode(whiteled_3, OUTPUT);    
  pinMode(whiteled_4, OUTPUT);     
  pinMode(redled_1, OUTPUT);     
  pinMode(redled_2, OUTPUT);      
  pinMode(buttonOnPin, INPUT);
}
void loop()
{
  //Read button ON state (pressed or not pressed?)
  buttonOnState = digitalRead(buttonOnPin);
  buttonOffState = digitalRead(buttonOffPin);

  //If button pressed...
  if (buttonOnState == HIGH) { 
    isOnPressed = true;
  }
  if (buttonOffState == HIGH) { 
    isOnPressed = false;
    digitalWrite(whiteled_1, LOW);    
    digitalWrite(whiteled_2, LOW); 
    digitalWrite(whiteled_3, LOW); 
    digitalWrite(whiteled_4, LOW); 
    digitalWrite(redled_1, LOW);    
    digitalWrite(redled_2, LOW);
    counter = 0;
    whiteBlink = true;
  }
     //...ones, turn led on!
      if(whiteBlink && isOnPressed)
      {
         digitalWrite(whiteled_1, LOW);    
         digitalWrite(whiteled_2, LOW); 
         digitalWrite(whiteled_3, LOW); 
         digitalWrite(whiteled_4, LOW); 
         delay(500);        // delay
         digitalWrite(whiteled_1, HIGH);    
         digitalWrite(whiteled_2, HIGH); 
         digitalWrite(whiteled_3, HIGH); 
         digitalWrite(whiteled_4, HIGH); 
         delay(500);        // delay  
         counter++;
         
         if(counter == 10)
         {
          whiteBlink = false;
          counter = 0;
         }
         
         digitalWrite(whiteled_1, LOW);    
         digitalWrite(whiteled_2, LOW); 
         digitalWrite(whiteled_3, LOW); 
         digitalWrite(whiteled_4, LOW); 
      }
      else if (isOnPressed)
      {
         digitalWrite(redled_1, LOW);    
         digitalWrite(redled_2, LOW); 
         delay(500);        // delay
         digitalWrite(redled_1, HIGH);    
         digitalWrite(redled_2, HIGH); 
         delay(500);        // delay  
         counter++;
         
         if(counter == 15)
         {
          whiteBlink = true;
          counter = 0;
         }
         
         digitalWrite(redled_1, LOW);    
         digitalWrite(redled_2, LOW); 
      }
}
