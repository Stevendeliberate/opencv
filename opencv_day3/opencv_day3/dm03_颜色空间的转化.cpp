#include<opencv2\opencv.hpp>
#include<opencv2\highgui\highgui.hpp>
#include<opencv2\imgproc\imgproc.hpp>

using namespace cv;

int main31()
{
	Mat a;
	a = imread("1.jpg");
	imshow("a",a);
	Mat b;
	cvtColor(a, b, COLOR_RGB2Lab);//ԭʼͼתΪ�Ҷ�ͼ
	imshow("b", b);
	waitKey(0);

	return 0;
}