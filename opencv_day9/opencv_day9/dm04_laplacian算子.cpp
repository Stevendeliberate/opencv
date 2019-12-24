#include<opencv2\imgproc\imgproc.hpp>
#include<opencv2\highgui\highgui.hpp>
#include<opencv2\core\core.hpp>
#include<iostream>
using namespace std;
using namespace cv;

void main41()
{
	Mat a = imread("1.jpg");
	Mat dst,ads_dst;

	imshow("1", a);
	GaussianBlur(a, a, Size(3, 3), 0, 0, BORDER_DEFAULT);

	cvtColor(a, a, COLOR_RGB2GRAY);

	Laplacian(a, dst, CV_16S, 3, 1, 0, BORDER_DEFAULT);
	convertScaleAbs(dst, ads_dst);
	imshow("ads_dst", ads_dst);
	waitKey(0);
}