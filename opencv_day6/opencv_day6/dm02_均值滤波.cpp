#include<opencv2\imgproc\imgproc.hpp>
#include<opencv2\core\core.hpp>
#include<opencv2\highgui\highgui.hpp>
#include<iostream>


using namespace std;
using namespace cv;

void main21()
{
	system("color 9F");
	Mat image = imread("1.jpg");

	namedWindow("原图");
	namedWindow("效果图");

	imshow("原图", image);

	Mat outImage;

	blur(image, outImage, Size(5, 5));

	imshow("效果图", outImage);

	waitKey(0);
	system("pause");
}