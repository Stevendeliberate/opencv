#include<opencv2\imgproc\imgproc.hpp>
#include<opencv2\highgui\highgui.hpp>
#include<opencv2\core\core.hpp>
#include<iostream>
using namespace std;
using namespace cv;

void lowCanny(Mat &inputImage)
{
	Mat dstImage;
	Canny(inputImage, dstImage, 9, 3, 3);
	imshow("效果图1", dstImage);
}

void highCanny(Mat &inputImage)
{
	Mat dstImage, edge, gray;
	
	dstImage.create(inputImage.size(), inputImage.type());

	cvtColor(inputImage, gray, COLOR_RGB2GRAY);

	blur(gray, edge, Size(3, 3));

	Canny(edge, edge, 3, 9, 3);

	dstImage = Scalar::all(0);

	inputImage.copyTo(dstImage, edge);

	imshow("效果图2", dstImage);
}


void main21()
{
	Mat srcImage = imread("1.jpg");

	lowCanny(srcImage);

	highCanny(srcImage);

	waitKey(0);

}