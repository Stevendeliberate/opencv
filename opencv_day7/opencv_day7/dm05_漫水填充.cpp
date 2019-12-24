/*
//全局变量及命名空间
#include<opencv2\core\core.hpp>
#include<opencv2\highgui\highgui.hpp>
#include<opencv2\imgproc\imgproc.hpp>
#include<iostream>

using namespace cv;
using namespace std;

void main()
{
	Mat Image = imread("1.jpg");

	imshow("原图", Image);
	Rect ccomp;

	floodFill(Image,Point(50,300),Scalar(155,255,55),&ccomp,Scalar(20,20,20),Scalar(20,20,20));
	imshow("效果图", Image);

	waitKey(0);
}
*/