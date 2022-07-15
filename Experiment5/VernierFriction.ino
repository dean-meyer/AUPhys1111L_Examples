#include <VernierLib.h> //include the Vernier library
VernierLib Vernier;     //rename the Vernier library to just Vernier
float sensorReading;    //create a float-type variable for the sensor reading
long currentTime;       //create a long-type variable for time

void setup()
{
  Serial.begin(9600);  //Set the serial communication to 9600 baud
  Vernier.autoID();    //Reads information about the sensor, including calibration info
}

void loop()
{
  currentTime = millis();                //set the start time of the experiement, counting up in milliseconds
  sensorReading = Vernier.readSensor();  //get the value from the sensor and assign it to the sensorReading variable

  /* In this next line we're doing something new again. We assigned a variable
     for current time above as the start time of the sketch in milliseconds. 
     Rather than printint out the milliseconds value though, it's much easier
     to read time printed in seconds. To get our Arduino to print in seconds
     we'll just divide our currentTime variable by 1000, or 1e3 in scientific
     notation, and then print that value */
  Serial.print(currentTime/1e3);  
  Serial.print(" s, ");   //print the units for our time
  
  /* We're going to do another new thing here in the next line. At the start of
     the sketch we assigned the sensorReading variable to a float-type variable.
     Float data types in Arduino have 6-7 digit precision, meaning it will print 
     out 6 or 7 decimal places precisely when you tell it to print. We don't need
     that many decimals for this, so we can use tell our Arduino to only print 
     out the first 3 numbers after the decimal with the ", 3" portion of the line.
     You can use this to print out more or less numbers after the decimal, but 
     if you do remember that the float data type only has 6-7 digits of precision
     so anything after that cannot be trusted. 
     
     One other note for those of you in this course that are Computer and Cyber
     Science majors or familiar with other C-family languages and may be thinking
     "well yeah, that's why you use double." With the Arduino we use in lab, an 
     Arduino Uno, double still only occupies 4 bytes, not 8, which is the same as 
     float, so you cannot gain increased precision by using double. Some other 
     modesl of Arduino do support the double data type though */
  Serial.print(sensorReading, 3);
  Serial.print(" ");                      //print a space
  Serial.println(Vernier.sensorUnits());  //print the units from the Vernier
  delay(250);
}
