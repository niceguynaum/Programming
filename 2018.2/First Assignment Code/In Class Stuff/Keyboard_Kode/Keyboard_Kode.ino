#include <Keyboard.h>

int buttonPin = 7;
int buttonState = 0;
int lastButton = 0;

void setup() 
{
  pinMode (buttonPin, INPUT);
  Keyboard.begin();
  //Serial.begin(9600);
}

void loop() 
{
  lastButton = buttonState;
  buttonState = digitalRead(buttonPin);

  if (buttonState == 1 && lastButton == 0)
  {
    //Serial.println("Butts McButtz");
    Keyboard.println("Butts McButtz \n");
  }
}
