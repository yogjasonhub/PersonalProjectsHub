#include<iostream>
#include<stdlib.h>
#include<opencv2\objdetect\objdetect.hpp>
#include<opencv2\highgui\highgui.hpp>
#include<opencv2\imgproc\imgproc.hpp>

using namespace std;
using namespace cv;

int main()
{
	// This program implements the Viola-Jones algorithm where it detects faces in an image
	CascadeClassifier facialRecognition;
	if (!facialRecognition.load("C:\\Users\\jason\\Downloads\\opencv\\sources\\data\\haarcascades\\haarcascade_frontalface_default.xml")) {
		cout << "\n File isn't loaded properly";
		exit(0); //stdlib.h
	}
	char path[100];

	cout << "\n Enter path of first image : ";
	cin.getline(path, 100);   // first image

	Mat img = imread(path, IMREAD_UNCHANGED);

	if (img.empty()) {
		cout << "\n image is not loaded! - ";
	}
	else
	{
		vector<Rect> faces;

		facialRecognition.detectMultiScale(img, faces);

		for (int i = 0; i < faces.size(); i++) {
			Point pt1(faces[i].x, faces[i].y);
			Point pt2((faces[i].x + faces[i].height), (faces[i].y + faces[i].width));

			rectangle(img, pt1, pt2, Scalar(0, 255, 0), 2, 8, 0);
		}

		imwrite("C:\\Users\\jason\\Documents\\Coding\\FacialRecognitionProject\\facialOutPutRecognition.jpg", img);
		cout << "\n Image was detected!! Check path for new output image";
	}

	return 0;
}
