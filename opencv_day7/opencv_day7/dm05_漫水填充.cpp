/*
//ȫ�ֱ����������ռ�
#include<opencv2\core\core.hpp>
#include<opencv2\highgui\highgui.hpp>
#include<opencv2\imgproc\imgproc.hpp>
#include<iostream>

using namespace cv;
using namespace std;

void main()
{
	Mat Image = imread("1.jpg");

	imshow("ԭͼ", Image);
	Rect ccomp;

	floodFill(Image,Point(50,300),Scalar(155,255,55),&ccomp,Scalar(20,20,20),Scalar(20,20,20));
	imshow("Ч��ͼ", Image);

	waitKey(0);
}
*/