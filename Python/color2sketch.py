import cv2
img_location = ""
filename = '.jpg'
img = cv2.imread("#image location")
gray_image = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY) 
inverted_gray_image = 255 - gray_image
inverted_blurred_img = 255 - blurred_img
pencil_sketch_IMG = cv2.divide(gray_image, inverted_blurred_img, scale = 256.0)
#Show the original image
cv2.imshow('Original Image', img)
#Show the new image pencil sketch
cv2.imshow('Pencil Sketch', pencil_sketch_IMG)
#Display the window infinitely until any keypress
cv2.waitKey(0)
