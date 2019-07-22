/*
  Fading

  This example shows how to fade an LED using the analogWrite() function.

  The circuit:
  - LED attached from digital pin 9 to ground.

  created 1 Nov 2008
  by David A. Mellis
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Fading
*/

int buttonPin = 2;
int buttonPin2 = 4;
int buttonState = 0;
int buttonState2 = 0;

int sensorPin = A0;
int ledPin = 13;    // LED connected to digital pin 9
int sensorValue = 0;
int sensorDelay = 0;


void setup() 
{
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  pinMode(buttonPin2, INPUT);
  Serial.begin(9600);
}

void loop()
{
  buttonState = digitalRead(buttonPin);
  buttonState2 = digitalRead(buttonPin2);

  
  
  sensorValue = analogRead(sensorPin);
  sensorDelay = sensorValue*2;

  if (buttonState == 1 && buttonState2 == 1) 
  {
    analogWrite (ledPin, sensorValue);
    delay(sensorDelay);
    analogWrite (ledPin, 0);
    delay(sensorDelay);
    Serial.println(sensorValue);                                                 
  }
   
  else if (buttonState == 1 && buttonState2 == 0)
  {
    analogWrite (ledPin, 175);
    delay(sensorDelay);
    analogWrite (ledPin, 0);
    delay(sensorDelay);
  }
  else
  {
    analogWrite(ledPin, sensorValue);
    Serial.println(sensorValue);
  }
}
