#Created by syafiqmuda
#BITI 1113 - Artificial Intelligent
#Final Assesment  (2021)

import numpy as np
import cv2

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

    #detect the face (make a triangle)
    for (x,y,w,h) in faces:
        cv2.rectangle(frame,(x,y),(x+w,y+h),(0,255,0),2) # (top,left)(right,bottom)(color)(border)
        break # break to select only near face

    #Show Cam Windows
    cv2.imshow("Frame", frame)

# Escape Key To Close
    k = cv2.waitKey(1)
    if k == 27:
        break
    
cap.release()
cv2.destroyAllWindows()
