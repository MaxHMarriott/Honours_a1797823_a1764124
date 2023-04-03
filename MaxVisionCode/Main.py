
#Credits
#https://subscription.packtpub.com/book/application-development/9781785283932/3/ch03lvl1sec28/accessing-the-webcam
# CV_Bridge installed from guide: https://index.ros.org/p/cv_bridge/

import cv2

cap = cv2.VideoCapture(0)

# Check if the webcam is opened correctly

#this program feed will use the first avaliable 
if not cap.isOpened():
    raise IOError("Cannot open webcam")

while True:
    ret, frame = cap.read()
    frame = cv2.resize(frame, None, fx=0.5, fy=0.5, interpolation=cv2.INTER_AREA)
    #opencv code goes here
    frame = visionProcessing(frame)
    cv2.imshow('Input', frame)

    c = cv2.waitKey(1)
    if c == 27: #escape key will close imshow window
        break

cap.release()
cv2.destroyAllWindows()

def visionProcessing(frame):
    #
    return frame