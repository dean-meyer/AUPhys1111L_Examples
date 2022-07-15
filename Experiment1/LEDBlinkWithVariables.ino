int ledPin = 8;       //Use pin 8 for the LED
int delayTime = 500;  //Set the delay time to be 500 milliseconds

void setup()
{
  /*We set pin 8 as an output again, but this time we use the variable we made
    above rather than using the pin number */
  pinMode(ledPin, OUTPUT); 
}

void loop()
{
  digitalWrite(ledPin, HIGH);   //Set pin 8 to High, this time using our variable
  delay(delayTime);             //Delay for 500 milliseconds, using our variable
  digitalWrite(ledPin, LOW);    //Set pin 8 to Low, again using our variable
  delay(delayTime);             //Delay for 500 milliseconds, again using our variable
}
