import cv2 as cv
import sys
import os.path
from datetime import datetime

def replace_all(text: str, dic: dict) -> str:
    for i, j in enumerate(dic):
        text = text.replace(i, j)
    return text

d = {
    "-": "_",
    " ": "_",
    ":": "_",
    ".": "_"
}

cv.namedWindow("Preview")
vc = cv.VideoCapture(0)

if vc.isOpened():
    rval, frame = vc.read()
else:
    rval = False

while rval:
    cv.imshow("Preview", frame)
    rval, frame = vc.read()
    key = cv.waitKey(20)
    if key == 32:
        break

cv.destroyWindow("Preview")
vc.release()

now = datetime.now()
file_name = now.strftime("%m_%d_%Y_%H_%M_%S_camera.pgm")

if sys.platform == "win32":
    file_name = "\\" + file_name
else:
    file_name = "/" + file_name

img_path = os.getcwd() + file_name
img_gray = cv.cvtColor(frame, cv.COLOR_BGR2GRAY)
cv.imwrite(img_path, img_gray)
