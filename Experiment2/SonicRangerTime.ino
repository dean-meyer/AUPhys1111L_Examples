int trigger = 13;                       // assigns trigger to pin 13
int echo = 12;                          // assigns echo to pin 12

void setup() 
{
  Serial.begin(9600);                   // starts serial communication
  pinMode(trigger, OUTPUT);             // assigns trigger pin as an output
  pinMode(echo, INPUT);                 // assigns echo pin as an input
}

void loop() 
{
  // We need to send the sound pulse using the HC-SR04 Sonic Ranger trigger
  digitalWrite(trigger, LOW);             // trigger off
  delayMicroseconds(2);                   // delay before sending pulse, in MICROseconds not MILLIseconds
  digitalWrite(trigger, HIGH);            // trigger on
  delayMicroseconds(10);                  // send sounds pulse for 10 microseconds
  digitalWrite(trigger, LOW);             // turn the trigger back off

  // Now we need to read the sounds pulse sent by the trigger using the echo 
  long duration = pulseIn(echo, HIGH);    //create a long integer variable for the sound pulse reading

  // And finally, we need to print out the reading from the Sonic Ranger's echo
  Serial.print(duration);                 // print out the duration variable we created
  Serial.print(" ");                      // print a space
  Serial.println("microseconds");         // print the units
  delay(1000);                            // delay 1 second, units are in MILLIseconds
}
