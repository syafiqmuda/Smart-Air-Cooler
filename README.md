# SMART AIR COOLING USING ARTIFICIAL INTELLIGENT 

## A. PROJECT SUMMARY

**Smart Air Cooling:** Person/Moving/face Detection using Deep Learning

**Team Members:** 
- Mohammad Syafiq Bin Enchek Muda 	(B031910178)
- Abdillah Safwan Bin Yusop 		(B031910120)
- Muhammad Ridhwan Bin Razalee 		(B031910197)
- Farid Hazeeq Bin Burhanuddin 		(B031910427)


**Objectives:**
The objective for this project are mainly for
- Reduce amount of workload needed to adjust fan position
- Create a small portable cooling fan just like a mini air-conditioner
- The fan will automatically target person/moving object using a camera.
- Increase efficiency of the power and air-cold as normal fan will only blow in static or sometime it rotate when there is no person standing there.  


##  B. ABSTRACT 

  Currently the temperature in Malaysia now are soaring high as the weather in today world are increasing rapidly from time to time. This become major problem for Malaysia and also to those nation in the earth equator line (Khatulistiwa). Highest recorded temperature in malaysia are 36.4 degree celcius on February 2021, potentially making the coming weeks blistering hot. Moreover, based on the news taken from TheStar and BHarian, MetMalaysia director-general Jailan Simon said the country is currently in the last phase of the northeast monsoon season that will last until mid-March.

During this period, he said, rainfall is expected to be low in Peninsular Malaysia, particularly in the northern region. Those people who working on air-conditioner place will not have much trouble of ii but what happen to the people that dont have air-conditioner at the work place. As we know, heat place may reduce our energy to work efficently, especially during this MCO time due to Covid-19 happen on 2021 now, where most people work at home and which is most poeple dont have air-conditioner like their office.

Due to that, our team decide to make a Smart Air Cooling to solve this problem. Of course, we know that there a lot of product out there selling the air cooling fan. But this is not a normal type air cooler. It is a smart air cooler which user AI technology to automatically blow cool air toward the person. The Idea is to make a fan with servo to automatically targeting the nearest person posibble based on AI movement tracking or Person tracking depending on situation.

This is a small project that combining IoT and AI together to make a small scale air cooling which automatically blow the cold air toward the target user.   


![Coding](https://github.com/syafiqmuda/Smart-Air-Cooler/blob/main/src/static%20fan%20blow.webp)

Figure 1 shows the static fan blow only on straight where user need to stand in front of it.


## C.  DATASET

  For this dataset we will be using haarcascades which is an Object Detection using Haar feature-based cascade classifiers for the effective object detection method proposed by Paul Viola and Michael Jones based on their paper, "Rapid Object Detection using a Boosted Cascade of Simple Features" in 2001. It is a machine learning based approach where a cascade function is trained from a lot of positive and negative images. It is then used to detect objects in other images. Initially, the algorithm needs a lot of positive images (images of faces) and negative images (images without faces) to train the classifier. Then we need to extract features from it. For this, Haar features shown in the below image are used. They are just like our convolutional kernel. Each feature is a single value obtained by subtracting sum of pixels under the white rectangle from sum of pixels under the black rectangle.

![haarcascades](image)

 For this, we apply each and every feature on all the training images. For each feature, it finds the best threshold which will classify the faces to positive and negative. Obviously, there will be errors or misclassifications. We select the features with minimum error rate, which means they are the features that most accurately classify the face and non-face images. (The process is not as simple as this. Each image is given an equal weight in the beginning. After each classification, weights of misclassified images are increased. Then the same process is done. New error rates are calculated. Also new weights. The process is continued until the required accuracy or error rate is achieved or the required number of features are found).

![haarcascades](image)

The final classifier is a weighted sum of these weak classifiers. It is called weak because it alone can't classify the image, but together with others forms a strong classifier. The paper says even 200 features provide detection with 95% accuracy. Their final setup had around 6000 features. (Imagine a reduction from 160000+ features to 6000 features. That is a big gain).

So now you take an image. Take each 24x24 window. Apply 6000 features to it. Check if it is face or not. Wow.. Isn't it a little inefficient and time consuming? Yes, it is. The authors have a good solution for that. Here is the result of running the code above and using as input the video stream of a in webcam:

![haarcascades](image)


Additional Resources

    Paul Viola and Michael J. Jones. Robust real-time face detection. International Journal of Computer Vision, 57(2):137–154, 2004. [224]
    Rainer Lienhart and Jochen Maydt. An extended set of haar-like features for rapid object detection. In Image Processing. 2002. Proceedings. 2002 International Conference on, volume 1, pages I–900. IEEE, 2002. [132]
    Video Lecture on Face Detection and Tracking
    An interesting interview regarding Face Detection by Adam Harvey
    OpenCV Face Detection: Visualized on Vimeo by Adam Harvey



## D.   PROJECT STRUCTURE

The following directory is our structure of our project:
- $ tree --dirsfirst --filelimit 10
- .
- ├── dataset
- │   ├── with_mask [690 entries]
- │   └── without_mask [686 entries]
- ├── arduino_code
- │   └── arduino_code.ino
- ├── haarcascades
- │   ├── haarcascade_eye.xml
- │   ├── haarcascade_eye_tree_eyeglasses.xml
- │   ├── haarcascade_frontalcatface.xml
- │   ├── haarcascade_frontalcatface_extended.xml
- │   ├── haarcascade_frontalface_alt.xml
- │   ├── haarcascade_frontalface_alt_tree.xml
- │   ├── haarcascade_frontalface_alt2.xml
- │   ├── haarcascade_frontalface_default.xml
- │   ├── haarcascade_fullbody.xml
- │   ├── haarcascade_lefteye_2splits.xml
- │   ├── haarcascade_licence_plate_rus_16stages.xml
- │   ├── haarcascade_lowerbody.xml
- │   ├── haarcascade_profileface.xml
- │   ├── haarcascade_righteye_2splits.xml
- │   ├── haarcascade_smile.xml
- │   └── haarcascade_upperbody.xml
- ├── haarcascade_frontalface_default.xml
- └── Python.py

The dataset/ directory contains the data described in the “Smart Air-Cooler dataset” section.


## E.   TRAINING AND BUILDING THE SMART AIR-COOLER

In order to first to use this this project, we will mention on how the will device works. We will also explain on the part we used to implemented for this project. There will be a divided part that split into certain categories. The first part on how to make a cooler, the second is the electornic device (Servomachanism) and finally is the software used for coding in order to create an AI that control the device.

**Cooler Generator Part**

![Figure 2](image here)

The component used to build this part are :
- 2x 150mm Fan
- 1x 92mm Fan (with heatsink)
- 1x Radiator
- 1x Waterpump (with reservoir)
- 1x powersupply (12v 10A)

**Servomachanism**

![Figure 3](image here)

The component used to build this part are :
- 2x Servo MG90s
- 1x Servo Pan Tilt Platform
- 1x Arduino Mega
- 1x USB Webcam

**Software**

![Figure 4](image here)
IDE used
- Arduino IDE
- Pyhton (AI)


## F.  RESULT AND CONCLUSION

(will be update soon)



## G.   PROJECT PRESENTATION 

(will be update soon)



