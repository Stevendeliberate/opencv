#include<opencv2\imgproc\imgproc.hpp>
#include<opencv2\core\core.hpp>
#include<opencv2\highgui\highgui.hpp>
#include<iostream>

using namespace std;
using namespace cv;

void main11()
{
	system("color 9F");
	Mat image = imread("1.jpg");

	namedWindow("ԭͼ");
	namedWindow("Ч��ͼ");

	imshow("ԭͼ", image);

	Mat outImage;

	boxFilter(image, outImage, -1, Size(5, 5));

	imshow("Ч��ͼ", outImage);

	waitKey(0);
	system("pause");
}