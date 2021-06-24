#Created by syafiqmuda
#BITI 1113 - Artificial Intelligent
#Final Assesment (2021)

import numpy as np
import cv2
import serial, time, sys

#Connection to arduino
arduino = serial.Serial('COM5', 9600)
time.sleep(1)
print("Connection to arduino...")

# Dataset
face_cascade = cv2.CascadeClassifier('haarcascade_frontalface_default.xml')

# Camera Connection
cap = cv2.VideoCapture(0)

while True:

    #Create Camera Windows
    cam, frame = cap.read()

    #mirror the image
    frame = cv2.flip(frame,1)

    #print(frame.shape) #change color
    gray = cv2.cvtColor(frame,cv2.COLOR_BGR2GRAY)
    faces = face_cascade.detectMultiScale(gray,1.3)
    

#detect the face (make a rectangle) -------------------------------------------------------
    for (x,y,w,h) in faces:
        
        # (top,left)(bottom,right)(color)(border)
        cv2.rectangle(frame,(x,y),(x+w,y+h),(0,255,0),2) 

        #take middle point of the rectangle(face)
        xx = int(x+(x+h))//2
        yy = int(y+(y+w))//2

        #plot the center of the face
        cv2.circle(frame,(x+w//2,y+h//2),2,(0,255,0),2)

        #create line X
        cv2.line (frame, (xx, 0),(xx, 480), (0, 255, 0), 2)
        
        #create line Y
        cv2.line (frame, (0, yy),(640, yy), (0, 255, 0), 2)

        #console
        print("Center Point of Rectangle is :")
        print("X is :", xx)
        print("Y is :", yy)

        #send to arduino
        data = "X{0:.0f}Y{1:.0f}".format(xx, yy)
        print("data send :", data)
        arduino.write(data.encode())
        
        break
        
# break to select only near face --------------------------------------------------------

    
    #Show Cam Windows
    cv2.imshow("Frame", frame)

    

# Escape Key To Close
    k = cv2.waitKey(1)
    if k == 27:
        break
    
cap.release()
cv2.destroyAllWindows()
