/* Created by syafiqmuda
 *  BITI 1113 - Artificial Intelligent
 *  Final Assesment (2021)
 *  
 *  Special thankyou to Liz Miller from LearnRobotic.com
 *  https://www.learnrobotics.org/blog/face-tracking-opencv/?utm_source=youtube&utm_medium=description&utm_campaign=face_tracking_video
*/

#include<Servo.h>

Servo x, y;
int width = 640, height = 480;  // total resolution of the video
int xpos = 70, ypos = 70;  // initial positions of both Servos
void setup() {

  Serial.begin(9600);
  x.attach(6);
  y.attach(5);
  x.write(xpos);
  y.write(ypos);
}

void loop() {
  if (Serial.available() > 0)
  {
    int x_mid, y_mid;
    if (Serial.read() == 'X')
    {
      x_mid = Serial.parseInt();  // read center x-coordinate   
      
      if (Serial.read() == 'Y'){
        y_mid = Serial.parseInt(); // read center y-coordinate
      }
    }

    
    
    /* adjust the servo within the squared region if the coordinates
        is outside it
    */
    if (x_mid > width / 2 + 55){
      xpos += 1;
    }
      
    if (x_mid < width / 2 - 55){
      xpos -= 1;
    }
      
    if (y_mid < height / 2 + 55){
      ypos -= 1;
    }
      
    if (y_mid > height / 2 - 55){
      ypos += 1;
    }
      
    // if the servo degree is outside its range
    if (xpos >= 160)
      xpos = 170;
    else if (xpos <= 0)
      xpos = 0;
    if (ypos >= 160)
      ypos = 170;
    else if (ypos <= 0)
      ypos = 0;

    delay(15);
    
    x.write(xpos);
    y.write(ypos);
  }
}
