#include<opencv2\opencv.hpp>
using namespace cv;

int main05()
{
	//������Ƶ
	VideoCapture capture("C:/Users/steven_cha/Pictures/1.avi");

	//ѭ����ʾÿһ֡
	while(1)
	{
		Mat frame;//����һ��Mat���������ڴ洢ÿһ֡��ͼ��
		capture >> frame;//��ȡ��ǰ֡
		if (frame.empty())
		{
			break;
		}
		imshow("��ȡ��Ƶ", frame);
		waitKey(30);

	}
	return 0;
}