// Motor A
 
int enA = 9;
int in1 = 8;
int in2 = 7;
 
// Motor B
 
int enB = 3;
int in3 = 5;
int in4 = 4;
 
void setup()
 
{
 
  // Set all the motor control pins to outputs
 
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
 
}
 
void dcRun()
 
{
 
  // the motors in  the same direction at a fixed speed for 3 secondes
 
  // Turn on motor A
 
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
 
  // Set speed to 200 out of possible range 0~255
 
  analogWrite(enA, 200);
 
  // Turn on motor B
 
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
 
  // Set speed to 200 out of possible range 0~255
 
  analogWrite(enB, 200);
 
  delay(3000);

   // Now change motor directions
 
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);  
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH); 
 
  delay(3000);

  // Run the motors in opposite directions at a fixed speed
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
    
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  
  
  delay(3000);
 
 
  // Now turn off motors
 
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);  
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
 
}
 
void dcSpeed()
 
{
 
  // run the motors across the range of possible speeds
  // Note that maximum speed is determined by the motor itself and the operating voltage
 
  // Turn on motors
 
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);  
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH); 
 
  // Accelerate from zero to maximum speed
 
  for (int i = 0; i < 256; i++)
 
  {
 
    analogWrite(enA, i);
    analogWrite(enB, i);
 
    delay(20);
 
  } 
 
  // Decelerate from maximum speed to zero
 
  for (int i = 255; i >= 0; --i)
 
  {
 
    analogWrite(enA, i);
    analogWrite(enB, i);
 
    delay(20);
 
  } 
 
  // Now turn off motors
 
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);  
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);  
 
}
 
void loop()
 
{
 
  dcRun();
 
  delay(1000);
 
  dcSpeed();
 
  delay(1000);
 
}
