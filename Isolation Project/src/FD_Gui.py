import tkinter as tk
from PIL import ImageTk, Image
import cv2
import numpy as np
import time
import sys


face_cascade = cv2.CascadeClassifier('C:/Users/Lenovo/Anaconda3/pkgs/libopencv-3.4.2-h20b85fd_0/Library/etc/haarcascades/haarcascade_frontalface_default.xml') 

cam = cv2.VideoCapture(0)
time.sleep(2)
gStop=False


window = tk.Tk()

def stop(event):
    global gStop
    gStop=True
    print(gStop)
    window.after_cancel(h) 

def takePic():
    global gStop
    global h
    if(not gStop):
                
        #test(event)        
        ret,img = cam.read()

        if ret is True:
            gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
        else:
            pass
        faces = face_cascade.detectMultiScale(gray, 1.3, 5)
        close = False
        for (x,y,w,h) in faces: 

            cv2.rectangle(img,(x,y),(x+w,y+h),(255,255,0),2)  
            oi_gray = gray[y:y+h, x:x+w] 
            roi_color = img[y:y+h, x:x+w]
            crop_img = img[y: y + h, x: x + w]
            crop_img = cv2.resize(crop_img, (100, 104)) 
            cv2.imwrite("Images/pf%s.png" % (sys.argv[1]), crop_img)
            close = True
            
        cv2.imshow('webcam', img)
        #cv2.waitKey(200)
        #if close:
       #     break
    
    
        if cv2.waitKey(1)&0xFF == ord('q'):
            pass
        h = window.after(1,takePic)
    return gStop
           
    
    
#This creates the main window of an application
h = window.after(1,takePic)
window.title("Join")
window.geometry("300x300")
window.configure(background='grey')
window.bind("<space>", stop)

path = "face.jpg"

#Creates a Tkinter-compatible photo image, which can be used everywhere Tkinter expects an image object.
try:
    img = ImageTk.PhotoImage(Image.open(path))
except:
    pass

#The Label widget is a standard Tkinter widget used to display a text or image on the screen.
panel = tk.Label(window, image = None)

#The Pack geometry manager packs widgets in rows or columns.
panel.pack(side = "bottom", fill = "both", expand = "yes")

capButton = tk.Button(window, text="Take Picture",command = lambda:takePic())
capButton.pack()

confirmButton = tk.Button(window, text="Confirm Picture",command = lambda:window.destroy())
confirmButton.pack()
#Start the GUI
window.mainloop()
cam.release()
cv2.destroyAllWindows() 