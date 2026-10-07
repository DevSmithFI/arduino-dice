/*
   Dice
*/


int result = 0;
int resultDisplayed = 1;
int anim = 0;
int cycles = 0;
int direction = 1;
int switchStatePrev = 0;
int switchState = 0;

//turn off leds
void turnOffLEDs()
{
  int i;
  for(i=2;i<=7;i++)
  {
     digitalWrite(i, LOW);
  }

}

void setup() {
  // declare the LED pins as outputs
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);

  // declare the switch pin as an input
  pinMode(8, INPUT);

 //turn off leds
  turnOffLEDs();

}






void loop() {

  // read the value of the switch
  // digitalRead() checks to see if there is voltage on the pin or not
  switchState = digitalRead(8);

  // button is pressed
  if ((switchState == HIGH) && (switchStatePrev == LOW))
  {
    anim = 0;
    cycles = 4;
    direction = 1;
    resultDisplayed = 0;
    delay(100);
    switchStatePrev = 1;
  }

  if (cycles > 0)
  {
     turnOffLEDs();
     digitalWrite(anim+2,HIGH);
     anim += direction;
     delay(100);

     if(anim == 5)
     {
        cycles--;
        direction = -1;
     }

     if(anim == 0)
     {
        cycles--;
        direction = +1;
     }
  }  

  if(cycles == 0)
  {
     if(resultDisplayed == 0)
     {
        //show dice
        result = (millis() % 6) + 2;
        turnOffLEDs();
        digitalWrite(result,HIGH);
        resultDisplayed = 1;
    }
  }
  switchStatePrev = switchState;
}
