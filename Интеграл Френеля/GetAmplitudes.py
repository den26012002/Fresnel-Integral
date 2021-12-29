import cv2
import math

img_path='pic1.png'
img=cv2.imread(img_path, 0).astype(float)
for line in img:
  for pix in line:
    print(f"{math.sqrt(pix):.{4}f}", end=' ')
  print()
