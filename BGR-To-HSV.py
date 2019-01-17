import libjevois as jevois
import cv2
import numpy as np
class CompoTest:
    def process(self, inframe, outframe):
      # Get the next camera frame as BGR:
      img = inframe.getCvBGR()

      # Convert to HSV
      hsv = cv2.cvtColor(img, cv2.COLOR_BGR2HSV)

      #HSV value arrays [H, S, V]
      lower = np.array([110,50,50])
      upper = np.array([130,255,255])

      #Apply the HSV stuff
      mask = cv2.inRange(hsv, lower, upper)


      # Send off the result:
      outframe.sendCv(mask)