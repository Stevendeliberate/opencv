#include<opencv2\opencv.hpp>
using namespace cv;

int main06()
{
	Mat frame;//����һ��Mat���������ڴ洢ÿһ֡��ͼ��
	//������Ƶ
	VideoCapture capture(0);

	//ѭ����ʾÿһ֡
	while (1)
	{
		capture >> frame;//��ȡ��ǰ֡
		imshow("��ȡ��Ƶ", frame);
		waitKey(30);

	}
	return 0;
}