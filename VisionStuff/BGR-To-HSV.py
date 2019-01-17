import libjevois as jevois
import cv2
import numpy as np
class FirstPython:
    def process(self, inframe, outframe):
      kernel = np.ones((5,5), np.float32)/25 #Average the pixels to make the blur kernel
      # Get the next camera frame as BGR:
      img = inframe.getCvBGR()

      _, img = cv2.threshold(img, 40, 255, cv2.THRESH_BINARY)
      
      img = cv2.dilate(img, kernel)
      
      # Convert to HSV
      hsv = cv2.cvtColor(img, cv2.COLOR_BGR2HSV)
      
      #HSV value arrays [H, S, V]
      lower = np.array([60,150,150])
      upper = np.array([100,255,255])

      #Apply the HSV stuff
      mask = cv2.inRange(hsv, lower, upper)

      # Send off the result:
      outframe.sendCv(mask)
      