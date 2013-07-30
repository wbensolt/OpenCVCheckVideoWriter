/*
 * main.cpp
 *
 *  Created on: Feb 24, 2012
 *      Author: Ziobro Damian
 */

#include <opencv/cv.h>
#include <opencv/highgui.h>

int main(int argc, char* argv[]) {

    CvCapture* input = cvCaptureFromFile(argv[1]);
    IplImage* image = cvQueryFrame(input);

    if (!image) {
        printf("Unable to read input");
        return 0;
    }


    CvSize imgSize;
    imgSize.width = image->width;
    imgSize.height = image->height;
    double fps = cvGetCaptureProperty(input,CV_CAP_PROP_FPS);
    CvVideoWriter *writer = cvCreateVideoWriter("out.avi",CV_FOURCC('D','I','V','X'),fps,imgSize,true);

    IplImage* colourImage;
    cvNamedWindow("aaa");
    for (;;) {
        //Get a frame from the input video.
        colourImage = cvQueryFrame(input);
        cvWriteFrame(writer, colourImage);
        cvShowImage("aaa",colourImage);
        cvWaitKey(33);
    }

    cvDestroyAllWindows();
    cvReleaseVideoWriter(&writer);
    cvReleaseCapture(&input);

}
