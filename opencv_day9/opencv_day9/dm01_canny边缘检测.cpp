#include<opencv2\imgproc\imgproc.hpp>
#include<opencv2\highgui\highgui.hpp>
#include<opencv2\core\core.hpp>
#include<iostream>
using namespace std;
using namespace cv;

int main11()//�ͽ�Canny��Ե����
{
	Mat srcImage = imread("1.jpg");
	Mat dst;

	imshow("ԭͼ", srcImage);
	Canny(srcImage, dst, 9, 3,3);
	imshow("Ч��ͼ", dst);
	waitKey(0);
	return 0;
}

//�߽�Canny��Ե�㷨
//��ת�ɻҶ�ͼ�����룬��Canny�����õ���Ե��Ϊ���룬����ԭͼ��Ч��ͼ�ϣ��õ���ɫ�ı�Եͼ
int main12()
{
	Mat srcImage = imread("1.jpg");
	Mat dst;

	imshow("ԭͼ", srcImage);
	Mat edge, gray;

	//����һ����srcͬ���ͺʹ�С�ľ���dst
	dst.create(srcImage.size(), srcImage.type());

	cvtColor(srcImage, gray, COLOR_RGB2GRAY);
	blur(gray, edge, Size(3, 3));

	Canny(edge, edge, 3, 9, 3);

	dst = Scalar::all(0);

	srcImage.copyTo(dst, edge);
	imshow("Ч��ͼ2", dst);
	waitKey(0);
	return 0;
}

