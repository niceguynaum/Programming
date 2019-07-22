#include <Mouse.h>

int buttonPin = 7;
int buttonState = 0;
int lastButton = 0;
int choiceVar = 0;

int sensorPin = A0;
int sensorValue = 0;
int SensorValue = 0;

void setup() 
{
  pinMode (buttonPin, INPUT);
  Mouse.begin();
  //Serial.begin(9600);
}

void loop() 
{
  int val;
  val = digitalRead(buttonPin);

  if(val==HIGH)
  {
    choiceVar = choiceVar + 1;
    }

    while (val == HIGH){
      delay(100);
      val = digitalRead(buttonPin);
    }
  sensorValue = analogRead(sensorPin);
  SensorValue = sensorValue*100;
  
  if (choiceVar == 2)
  {
    choiceVar = 0;
  }
  if (choiceVar ==1)
  {
    //Serial.println("Butts McButtz");
    Mouse.move(SensorValue, SensorValue, 0);
  }
  if (choiceVar == 0)
  {
    
  }
}
