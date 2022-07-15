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
  digitalWrite(trigger, LOW);            // trigger off
  delayMicroseconds(2);                  // delay before sending pulse, in MICROseconds not MILLIseconds
  digitalWrite(trigger, HIGH);           // trigger on
  delayMicroseconds(10);                 // send sounds pulse for 10 microseconds
  digitalWrite(trigger, LOW);            // turn the trigger back off

  // Now we need to read the sounds pulse sent by the trigger using the echo, and store it in a variable
  long duration = pulseIn(echo, HIGH);    

  /* This time, rather than printing out the time it took for the sound pulse we're going to convert 
  it to distance. First, we have to divide the duration variable by 2, because the sound travelled out 
  and back. Then, since distance is just speed * time, we can just multiply the halved duration variable 
  by the known speed of sound, ~343 m/s at sea level. Finally, because we're going to print out the 
  distance in cm rather than meters, we'll just do the unit conversion in the same step in order to make 
  our code more efficient */
  
  long distance = (duration/2)*0.0344;    //convert time to distance and create variable
  Serial.print(distance);                 // print the distance variable
  Serial.print(" ");                      // print a space
  Serial.println("cm");                   // print the units
  delay(1000);                            // delay 1 second
}
