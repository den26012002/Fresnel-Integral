import cv2
import math

img_path='pic1.png'
img=cv2.imread(img_path, 0).astype(float)
out_file=open("amplitudes.txt", 'w')
for line in img:
  for pix in line:
    print(f"{math.sqrt(pix):.{4}f}", end=' ', file=out_file)
  print(file=out_file)

out_file.close()
