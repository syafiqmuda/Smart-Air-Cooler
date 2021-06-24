/* Created by syafiqmuda
 *  BITI 1113 - Artificial Intelligent
 *  Final Assesment (2021)
 *  
 *  Special thankyou to Liz Miller from LearnRobotic.com
 *  https://www.learnrobotics.org/blog/face-tracking-opencv/?utm_source=youtube&utm_medium=description&utm_campaign=face_tracking_video
*/

#include<Servo.h>

Servo servoVer; //Vertical Servo
Servo servoHor; //Horizontal Servo

// Declaration
int x;
int y;
int servoX, servoY;

// Set Range (Camera Resolution / degree)(Camera Range)
int width = 640;
int height = 480;
int range = 2;

void setup()
{
  Serial.begin(9600);
  servoVer.attach(5); //Attach Vertical Servo to Pin 5
  servoHor.attach(6); //Attach Horizontal Servo to Pin 6
  servoVer.write(90-20);
  servoHor.write(90-15);
}

void Pos()
{
  servoX = map(x, 0, width, 0, 180);
  servoY = map(y, 0, height, 0, 180);
    
  servoX = min(servoX, 160);
  servoX = max(servoX, 30);
  
  servoY = min(servoY, 160);
  servoY = max(servoY, 30);

  runX();
  runY();
}

void loop()
{
  if(Serial.available() > 0)
  {
    if(Serial.read() == 'X')
    {
      x = Serial.parseInt();
      if(Serial.read() == 'Y')
      {
        y = Serial.parseInt();
        Pos();
      }
    }
    
    while(Serial.available() > 0)
    {
      Serial.read();
    }
  }
}

void runX(){
  // Range Finder
  if (servoX < 45){
    servoX += 20;
  }

  else if(servoX > 135 ){
    servoX -= 20;
  }
  servoHor.write(servoX-20);
}

void runY(){
  // Range Finder
  if (servoY < 45){
    servoY += 10;
  }

  else if(servoY > 135 ){
    servoY -= 10;
  }
  servoVer.write(servoY-15);
}
