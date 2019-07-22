/*
 Fading

 This example shows how to fade an LED using the analogWrite() function.

 The circuit:
 * LED attached from digital pin 9 to ground.

 Created 1 Nov 2008
 By David A. Mellis
 modified 30 Aug 2011
 By Tom Igoe

 http://www.arduino.cc/en/Tutorial/Fading

 This example code is in the public domain.

 */
int sensorPin = A0;
int ledPin = 13;    // LED connected to digital pin 9
int sensorValue = 0;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() 
{
  sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue);

  analogWrite(ledPin, sensorValue);
}


