#Credits
# CV_Bridge installed from guide: https://index.ros.org/p/cv_bridge/

import cv2
#from picamera.array import PiRGBArray
#from picamera import PiCamera
import time

def savePhoto(frame,location,framecount):
	cv2.imwrite(location,frame)
	print("Photo of frame:") 
	print(framecount)
	print("saved at: " + location)
	return


def visionProcessing(frame):
    #vision code goes here
	return frame

def findPort(port):
	for a in range(9):
		try: 
			test = cv2.VideoCapture(port,cv2.CAP_V4L2)
			print("Camera feed found at port:")
			print(a)
			port = a
			del test
			return port
		except:
			a = a
	raise exception("No valid port found")
	return port

#Add function to find port
port = 0
findPort(port)
framecount = 0
print("Connecting to camera")
cap = cv2.VideoCapture(port,cv2.CAP_V4L2) #Find port
#cap = cv2.VideoCapture(1,cv2.CAP_FFMPEG) #Find port
#cap = cv2.VideoCapture(-1) #Find port
cap.set(cv2.CAP_PROP_FOURCC, cv2.VideoWriter_fourcc('M', 'J', 'P', 'G'))
print("Video Capture has started")

# Check if the webcam is opened correctly

#this program feed will use the first avaliable 
if not cap.isOpened():
    raise IOError("Cannot open webcam")

while True:
    print("This has run")
    ret, frame = cap.read(cv2.CAP_V4L2)
    print("This has run 2")
    frame = cv2.resize(frame, None, fx=0.5, fy=0.5, interpolation=cv2.INTER_AREA)
    framecount = framecount + 1
    #opencv code goes here
    #frame = visionProcessing(frame)
    cv2.imshow('Input', frame)
    print("Frame Displayed")
    c = cv2.waitKey(1)
    if c == 27: #escape key will close imshow window
    	print("Number of frames taken are:")
    	print(framecount)
    	savePhoto(frame,"/home/teamvision/Desktop/Screenshots/capture.jpeg",framecount)
    	break
cap.release()
cv2.destroyAllWindows()
