/* Here we're using another library in our sketch, VernierLib.h. Immediately after
   including the library though, we're renaming it to just "Vernier" with the second
   line. There are many reasons why you might want to rename an installed library in
   your sketch such as having to type fewer characters, avoiding typos, ease of use, 
   or to be in line with common practices */
   
#include <VernierLib.h> 
VernierLib Vernier;     
float sensorReading;      //Create a float-type variable for the sensor reading

void setup()
{
  Serial.begin(9600); //Set the serial communication to 9600 baud
  Vernier.autoID();   //Reads information about the sensor, including calibration info
}
void loop()
{
  sensorReading = Vernier.readSensor();   //get the value from the sensor and assign it to the sensorReading variable
  Serial.print(sensorReading);            //print the value read in the previous line
  Serial.print(" ");                      //print a space on the same line
  Serial.println(Vernier.sensorUnits());  //print the units from the sensor and create a new line
  delay(100);                             //delay 100 milliseconds
}
