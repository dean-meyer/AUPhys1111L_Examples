#include <Q2HX711.h>    //Include the library for the hx711
Q2HX711 hx711(A2, A3);  //Assigning the load cell to analog pins 2 and 3

void setup()
{
  Serial.begin(9600);   //Set the serial communication to 9600 baud
}
void loop()
{
  float rdg = hx711.read();   //read the data from the hx711

  /*In the next two lines we're going to assign variables using our known values from 
   the previous step in the experiment. We found a tare value and the value for 500g
   with the load cell. We are going to assign each to a variable, rdgTare for the tare
   value and rdg550 for the value with 550g. The numbers in this example just 0 for 
   convenience, you will need to change them to match your experimentally determined
   values. Remember that it is important to check your tare value every time you use
   the hx711 load cell as it may change due to many different factors */
  float rdgTare = 0000000.0;
  float rdg550 = 0000000.0;
  
  /*In this next line we're going to use our Arduino to do our calculations for us again,
   like we did in Experiment 2 with the sonic ranger. In this case, we know the value
   for our Tare reading and the value for our reading with 550g in our load cell. To 
   calculate the mass we can multiply 550 with the current reading minus the Tare
   reading divided by the 550g reading minus the Tare reading. This value will give 
   us the mass of the unknown weight in our load cell which we will assign to the 
   variable "mass" */
  float mass = 550*((rdg-rdgTare)/(rdg550-rdgTare));
  Serial.println(mass);   //Print the calculated mass to the serial monitor 
  delay(250);             //Delay 250 milliseconds
}
