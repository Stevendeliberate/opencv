//ͷ�ļ��Լ������ռ������
#include<opencv2\highgui\highgui.hpp>
#include<opencv2\core\core.hpp>
#include<iostream>

using namespace std;
using namespace cv;

//ȫ�ֱ���������

int g_nContrastValue;//�Աȶ�ֵ
int g_nBrightValue;//����ֵ
Mat g_srcImage, g_dstImage;//����ͼ�� ���ͼ��

static void on_ContrastAndBright(int, void *)
{
	namedWindow("ԭʼͼ�񴰿�", 1);
	
	for (int y = 0; y < g_srcImage.rows;y++)
	{
		for (int x = 0; x < g_srcImage.cols;x++)
		{
			for (int c = 0; c < 3;c++)
			{
				g_dstImage.at<Vec3b>(y, x)[c] = saturate_cast<uchar>((g_nContrastValue*0.01)*(g_srcImage.at<Vec3b>(y, x)[c]) + g_nBrightValue);//����
			}
		}
	}
	//��ʾͼ��
	imshow("ԭʼͼ�񴰿�", g_srcImage);
	imshow("Ч��ͼ����", g_dstImage);
}

int main71()
{
	g_srcImage = imread("1.jpg");
	if (!g_srcImage.data)
	{
		cout << "��ȡͼƬ����" << endl;
		return false;
	}
	g_dstImage = Mat::zeros(g_srcImage.size(), g_srcImage.type());//����һ��������ͼƬ��С�͸�ʽ��ͬ�ľ���

	//��ʼ���ԱȶȺ�����ֵ
	g_nBrightValue = 80;
	g_nContrastValue = 80;

	//��������
	namedWindow("Ч��ͼ����", 1);

	//�����켣��
	createTrackbar("�Աȶȣ�", "Ч��ͼ����", &g_nContrastValue, 300, on_ContrastAndBright);
	createTrackbar("���ȣ�", "Ч��ͼ����", &g_nBrightValue, 200, on_ContrastAndBright);

	//�ص�������ʼ��
	on_ContrastAndBright(g_nContrastValue, 0);
	on_ContrastAndBright(g_nBrightValue, 0);

	while (char(waitKey(1)) != 'q')
	{
	}
	return 0;
}
