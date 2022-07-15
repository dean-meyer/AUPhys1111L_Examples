void setup()
{
  Serial.begin(9600);   //Set the serial communication to 9600 baud
  Serial.println("Enter a number between 0 and 255 to change the motor speed!"); //Take user input for the motor speed
}

void loop()
{
  /* Here we are going to use an "if" statement for the first time in lab. All that an
     if statement does is check to see if a condition is met, and if it is then it executes
     code that comes after it. You'll often see "if" statements paired with "else" or "else if"
     statements, but in this case we only need the if. Note that there is NOT a semicolon at 
     the end of the line with the "if", if you put on there you're code will not work. Instead
     you enclose the code to be run if the conditions are met in curly braces. In this case, 
     we are checking to see if the Serial Monitor is avaliable, and if it is then we'll 
     execute the code after to adjust the motor speed */
  if (Serial.available() > 0)
  {
    /* The Serial.parseInt() function looks for the number the user entered in the serial monitor
       above when we took the user input */
    int motorSpeed = Serial.parseInt();
    int junk = Serial.read();     //This line allows for error handling with data from the serial monitr
    analogWrite(3, motorSpeed);   //Set the motor speed to the user input value on analog pin 3
  }
}
