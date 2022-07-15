#include <Q2HX711.h>    //Include the library for the hx711
Q2HX711 hx711(A2, A3);  //Assigning the load cell to analog pins 2 and 3

void setup()
{
  Serial.begin(9600);   //Set the serial communication to 9600 baud
}
void loop()
{
  float rdg = hx711.read();   //read the data from the hx711
  float rdgTare = 0000000.0;  //Assign the tare value to a variable
  float rdg550 = 0000000.0;   //Assign the 550g value to a variable
  float mass = 550*((rdg-rdgTare)/(rdg550-rdgTare));   //calculate the mass

  /* In the previous sketch we caclulated and printed the mass of an unknown weight
     using our Arduino. Since we now know the mass, and we know the formula to 
     calculate the force due to gravity, F=mg, we can use our Arduino to do this 
     calculation and print the force in Newtons to our serial monitor. To do this we'll 
     write the code for calculation and assign it to the variable "force". Remember
     that it's important to calibrate the hx711 before every use as the tare value
     will change due to many factors, and your tare value from earlier in the lab 
     may not be the same as the tare value your load cell reports now */
  float force = mass*9.83;
  Serial.print(force);    //Print the calculated force to the serial monitor 
  Serial.println(" N");   //Print the units for force
  delay(250);             //Delay 250 milliseconds
}
