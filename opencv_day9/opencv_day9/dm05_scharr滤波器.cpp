#include<opencv2\imgproc\imgproc.hpp>
#include<opencv2\highgui\highgui.hpp>
#include<opencv2\core\core.hpp>
#include<iostream>
using namespace std;
using namespace cv;

void main51()
{
	Mat a = imread("1.jpg");
	Mat dst, ads_dst;
	Mat abs_grad_x, abs_grad_y;

	imshow("1", a);

	Scharr(a, abs_grad_x, CV_16S, 1, 0, 1, 0, BORDER_DEFAULT);
	convertScaleAbs(abs_grad_x, abs_grad_x);
	imshow("x", abs_grad_x);

	Scharr(a, abs_grad_y, CV_16S, 0, 1, 1, 0, BORDER_DEFAULT);
	convertScaleAbs(abs_grad_y, abs_grad_y);
	imshow("y", abs_grad_y);

	addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, ads_dst);
	imshow("xy", ads_dst);
	waitKey(0);
}