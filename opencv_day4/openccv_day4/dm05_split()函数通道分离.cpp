#include<opencv2\opencv.hpp>

using namespace cv;
using namespace std;

void fenli()
{
	Mat srcImage;
	Mat imageROI;
	vector<Mat> channels;
	srcImage = imread("1.jpg");

	//��һ����ͨ��ͼ��ת����3����ͨ����ͼ��
	split(srcImage, channels);//����ɫ��ͨ��
	imageROI = channels.at(0);//��������ɫͨ��

	Mat imageROI2;
	imageROI2 = channels.at(1);//������ɫͨ��

	Mat imageROI3;
	imageROI3 = channels.at(2);//�����ɫͨ��

	imshow("origial", srcImage);
	imshow("blue", imageROI);
	imshow("green", imageROI2);
	imshow("red", imageROI3);

	Mat dstImage;
	merge(channels, dstImage);
	imshow("after merge", dstImage);
	waitKey(0);
	return;
}

void main51()
{
	fenli();
}
