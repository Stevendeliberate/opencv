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

	namedWindow("ԭͼ");
	namedWindow("Ч��ͼ");

	imshow("ԭͼ", image);

	Mat outImage;

	blur(image, outImage, Size(5, 5));

	imshow("Ч��ͼ", outImage);

	waitKey(0);
	system("pause");
}