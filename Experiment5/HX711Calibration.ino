/* This is the first time we've used #include in a sketch. With Arduinos, external
 *  libraries are sometimes required when using different components. These 
 *  libraries provide functions for use with the component to take advantage of 
 *  their features and help you avoid having to write a lot of extra code to use
 *  the component. In this experiment we will be using an hx711 Load Cell Amplifier,
 *  and a library named Q2HX711 to interact with it. */

#include <Q2HX711.h>    
Q2HX711 hx711(A2, A3);  //Assigning the load cell to analog pins 2 and 3

void setup()
{
  Serial.begin(9600);   //Set the serial communication to 9600 baud
}
void loop()
{
  /* In this first line we're assigning a variable to read in the data from the 
     hx711 load cell amplifier using the built in .read function from the library */
  long int rdg = hx711.read();
  Serial.println(rdg);   //Print the reading from the load cell to the serial monitor 
  delay(250);           //Delay 250 milliseconds
}
