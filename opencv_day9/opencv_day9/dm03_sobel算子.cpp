#include<opencv2\imgproc\imgproc.hpp>
#include<opencv2\highgui\highgui.hpp>
#include<opencv2\core\core.hpp>
#include<iostream>
using namespace std;
using namespace cv;

void main31()
{
	Mat grad_x, gard_y;
	Mat abs_grad_x, abs_grad_y;
	Mat dst;
	Mat src = imread("1.jpg");

	imshow("ԭͼ", src);

	//x������ݶ�
	Sobel(src, grad_x, CV_8U, 1, 0, 3, 0.4, 128, BORDER_DEFAULT);
	convertScaleAbs(grad_x, abs_grad_x);//ʹ�����Ա任ת����������Ԫ�س�8λ�޷�������
	imshow("abs_grad_x", abs_grad_x);

	//y������ݶ�
	Sobel(src, gard_y, CV_16S, 0, 1, 3, 1, 1, BORDER_DEFAULT);
	convertScaleAbs(gard_y, abs_grad_y);
	imshow("abs_grad_y", abs_grad_y);


	Sobel(src, gard_y, CV_16S, 1, 1, 3, 1, 1, BORDER_DEFAULT);
	convertScaleAbs(gard_y, abs_grad_y);
	imshow("abs_grad_xy", abs_grad_y);

	//�ϲ��ݶȣ����ƣ�
	addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, dst);
	imshow("�ϲ�ͼ", dst);
	waitKey(0);
}