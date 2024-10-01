import cv2
imgloc='C:/Users/91981/Documents/others/WIE/task1/picture.jpg'

img= cv2.imread(imgloc)
gryimg=cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
invtgrayimg=255-gryimg
blurimg=cv2.GaussianBlur(invtgrayimg,(21,21),0)
invtblurimg=255-blurimg
pencile=cv2.divide(gryimg,invtgrayimg,scale=256.0)

cv2.imshow('original Image',img)
cv2.imshow('Gray Image',gryimg)
cv2.imshow('Inverted Gray Image',invtgrayimg)
cv2.imshow('Blurr Image',blurimg)
cv2.imshow('Inverted Blurr Image',invtblurimg)
cv2.imshow('Pencil Sketch Image',pencile)
cv2.waitKey(0)




