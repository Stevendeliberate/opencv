/*
//ͷ�ļ��Լ������ռ�
#include<opencv2\imgproc\imgproc.hpp>
#include<opencv2\highgui\highgui.hpp>
#include<opencv2\core\core.hpp>
#include<iostream>
using namespace cv;
using namespace std;

//ȫ�ֺ�����������
static void g_medianBlur(int, void *);
static void g_bilateralFilter(int, void *);

//ȫ�ֱ�����������
Mat srcImage, dstImage4, dstImage5;
int g_nmedianBlurValue = 10;
int g_nbilateralFilterValue = 10;

void main11()
{
	system("color 9F");

	//��ȡԭʼͼ��
	srcImage = imread("1.jpg");
	if (!(srcImage.data))
	{
		cout << "��ȡͼƬ��������ͼƬ�Ƿ����"<<endl;
		return;
	}

	//�������ڲ���ʾ
	namedWindow("��ԭʼͼ��");
	imshow("��ԭʼͼ��", srcImage);

	//��ֵ�˲�����
	namedWindow("����ֵ�˲�������");

	createTrackbar("����ֵ", "����ֵ�˲�������", &g_nmedianBlurValue, 50, g_medianBlur);	//�����켣��
	g_medianBlur(g_nmedianBlurValue,0);

	//˫���˲�
	namedWindow("��˫���˲�������");

	createTrackbar("����ֵ", "��˫���˲�������", &g_nbilateralFilterValue, 50, g_bilateralFilter);
	g_bilateralFilter(g_nbilateralFilterValue,0);

	waitKey(0);
}

//��ֵ�˲�
static void g_medianBlur(int, void *)
{
	dstImage4 = srcImage.clone();

	medianBlur(dstImage4, dstImage4, g_nmedianBlurValue*2+1);
	imshow("����ֵ�˲�������", dstImage4);
}

//˫���˲�
static void g_bilateralFilter(int, void *)
{
	bilateralFilter(srcImage, dstImage5, g_nbilateralFilterValue, g_nbilateralFilterValue * 2, g_nbilateralFilterValue / 2);
	imshow("��˫���˲�������", dstImage5);
}
*/