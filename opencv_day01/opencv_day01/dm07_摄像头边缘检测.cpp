#include<opencv2\opencv.hpp>
using namespace cv;

int main07()
{
	Mat frame;//����һ��Mat���������ڴ洢ÿһ֡��ͼ��
	Mat edge;
	//������Ƶ
	VideoCapture capture(0);

	//ѭ����ʾÿһ֡
	while (1)
	{
		capture >> frame;//��ȡ��ǰ֡

		//��ԭͼ��ת��Ϊ�Ҷ�ͼ��
		cvtColor(frame, edge, CV_BGR2GRAY);

		//ʹ��3*3�ں�������
		blur(edge, edge, Size(7,7));

		//����canny��Ե��Ⲣ��ʾ
		Canny(edge, edge, 0, 30, 3);
		imshow("��Canny�������Ƶ", edge);
		if (waitKey(30) >= 0)
		{
			break;
		}
	}
	return 0;
}