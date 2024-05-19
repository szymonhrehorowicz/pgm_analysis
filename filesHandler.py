import cv2
import numpy as np
import sys
import os.path

def main():
    imgPath = ""

    # Handle command arguments
    for idx, arg in enumerate(sys.argv):
        if(arg == "-tif"):
            imgPath = sys.argv[idx + 1]
            break
        elif(arg == "-png"):
            imgPath = sys.argv[idx + 1]
            break

    # Read img
    if os.path.isfile(imgPath):
        # extract the file name
        (head, tail) = os.path.split(imgPath)
        pathArr = os.path.splitext(tail)

        # read img
        img = cv2.imread(imgPath, cv2.IMREAD_UNCHANGED)

        # turn img to grayscale
        grayImg = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

        # save grayscale img as png
        grayImgPath = imgPath.replace(pathArr[-1], ".pgm")
        cv2.imwrite(grayImgPath, grayImg)
    else:
        print("There is no such img file!")

if __name__ == '__main__':
    main()
