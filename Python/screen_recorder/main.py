# first install these packages
# pip install numpy
# pip install opencv-python
# pip install PyAutoGUI

import cv2
import numpy as np
import pyautogui

SCREEN_SIZE = (1920, 1080)
fourcc = cv2.VideoWriter_fourcc(*'MP4V')
out = cv2.VideoWriter("output.mp4", fourcc, 20.0,(SCREEN_SIZE))

while True:
    img = pyautogui.screenshot()
    frame = np.array(img)
    frame = cv2.cvtColor(frame,cv2.COLOR_BGR2RGB)
    out.write(frame)

    # if user press q exit
    if cv2.waitKey(1) == ord("q"):
        break

cv2.destroyAllWindows()
out.release()
