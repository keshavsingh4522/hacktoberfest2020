import cv2
import time
import numpy as np

##reading from the webcam
cap = cv2.VideoCapture(0)

## Allow the system to sleep for 3 seconds before the webcam starts
time.sleep(3)
count = 0
background = 0

## Capture the background in range of 60
for i in range(60):
    ret, background = cap.read()
background = np.flip(background, axis=1)

## Read every frame from the webcam, until the camera is open
while (cap.isOpened()):
    ret, img = cap.read()
    if not ret:
        break
    count += 1
    img = np.flip(img, axis=1)

    ## Convert the color space from BGR to HSV
    hsv = cv2.cvtColor(img, cv2.COLOR_BGR2HSV)

    ## Generat masks to detect red color
    
    ##YOU CAN CHANGE THE COLOR VALUE BELOW ACCORDING TO YOUR CLOTH COLOR
    lower_red = np.array([0, 120, 50])
    upper_red = np.array([10, 255,255])
    mask1 = cv2.inRange(hsv, lower_red, upper_red)

    lower_red = np.array([100, 40, 40])        
    upper_red = np.array([100, 255, 255]) 
    mask1 = cv2.inRange(hsv, lower_red, upper_red) 
    # setting the lower and upper range for mask2  
    lower_red = np.array([155, 40, 40]) 
    upper_red = np.array([180, 255, 255]) 
    mask2 = cv2.inRange(hsv, lower_red, upper_red) 
    #----------------------------------------------------------------------# 
  
    # the above block of code could be replaced with 
    # some other code depending upon the color of your cloth  
    mask1 = mask1 + mask2 
  
    # Refining the mask corresponding to the detected red color 
    mask1 = cv2.morphologyEx(mask1, cv2.MORPH_OPEN, np.ones((3, 3), 
                                         np.uint8), iterations = 2) 
    mask1 = cv2.dilate(mask1, np.ones((3, 3), np.uint8), iterations = 1) 
    mask2 = cv2.bitwise_not(mask1) 
  
    # Generating the final output 
    res1 = cv2.bitwise_and(background, background, mask = mask1) 
    res2 = cv2.bitwise_and(img, img, mask = mask2) 
    final_output = cv2.addWeighted(res1, 1, res2, 1, 0) 
  
    cv2.imshow("INVISIBLE MAN", final_output) 
    k = cv2.waitKey(1) 
    if k == 27: 
        break


cap.release()
cv2.destroyAllWindows()