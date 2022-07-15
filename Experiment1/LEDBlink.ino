void setup()
/* Because this code is in the setup portion of the sketch it will only run one time when
   the sketch is uploaded to the Arduino board. */
{
  pinMode(8, OUTPUT);   //Sets pin 8 as an output
}

void loop()
/* Because this code is in the loop portion of the sketch it will run repeatedly, or  
   in a loop, until something happens to cause it to stop like disconnecting the Arduino 
   from your computer */
{
  digitalWrite(8, HIGH);  //Set pin 8 to High, this will turn the LED on
  delay(1000);            //Delay for 1000 milliseconds, or 1 second
  digitalWrite(8, LOW);   //Set pin 8 to Low, this will turn the LED off
  delay(1000);            //Delay for 1000 milliseconds again
}
