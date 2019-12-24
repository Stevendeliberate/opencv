//ȫ�ֱ����������ռ�
#include<opencv2\core\core.hpp>
#include<opencv2\highgui\highgui.hpp>
#include<opencv2\imgproc\imgproc.hpp>
#include<iostream>

using namespace cv;
using namespace std;

//ȫ�ֺ���������
Mat srcImage, dstImage;
int g_nTrackbarNumer = 0;
int g_nStructElement = 10;

//ȫ�ֺ���������
static void Proess();
static void on_TrackbarNumer(int, void*);
static void on_StructElement(int, void*);

int main41()
{
	srcImage = imread("1.jpg");
	if (!srcImage.data)
	{
		cout << "ͼ����ش�������ͼ��" << endl;
		return false;
	}

	namedWindow("��ԭͼ��");
	imshow("��ԭͼ��", srcImage);

	//����������
	namedWindow("��Ч��ͼ��");
	createTrackbar("ģʽ","��Ч��ͼ��",&g_nTrackbarNumer,7,on_TrackbarNumer);
	createTrackbar("�ں˳ߴ�","��Ч��ͼ��",&g_nStructElement,50,on_StructElement);

	waitKey(0);
	return 0;
}

static void Proess()
{
	Mat element = getStructuringElement(MORPH_RECT, Size(2 * g_nStructElement + 1, 2 * g_nStructElement + 1), Point(g_nStructElement, g_nStructElement));

	if (g_nTrackbarNumer == 0)
	{
		dstImage = srcImage.clone();
		imshow("��Ч��ͼ��", dstImage);
	}
	else if (g_nTrackbarNumer == 1)//������
	{
		morphologyEx(srcImage, dstImage, MORPH_OPEN, element);
		imshow("��Ч��ͼ��", dstImage);
	}
	else if (g_nTrackbarNumer == 2)//������
	{
		morphologyEx(srcImage, dstImage, MORPH_CLOSE, element);
		imshow("��Ч��ͼ��", dstImage);
	}
	else if (g_nTrackbarNumer == 3)//������
	{
		morphologyEx(srcImage, dstImage, MORPH_GRADIENT, element);
		imshow("��Ч��ͼ��", dstImage);
	}
	else if (g_nTrackbarNumer == 4)//������
	{
		morphologyEx(srcImage, dstImage, MORPH_TOPHAT, element);
		imshow("��Ч��ͼ��", dstImage);
	}
	else if (g_nTrackbarNumer == 5)//������
	{
		morphologyEx(srcImage, dstImage, MORPH_BLACKHAT, element);
		imshow("��Ч��ͼ��", dstImage);
	}
	else if (g_nTrackbarNumer == 6)//������
	{
		morphologyEx(srcImage, dstImage, MORPH_ERODE, element);
		imshow("��Ч��ͼ��", dstImage);
	}
	else if (g_nTrackbarNumer == 7)//������
	{
		morphologyEx(srcImage, dstImage,MORPH_DILATE, element);
		imshow("��Ч��ͼ��", dstImage);
	}
}

static void on_TrackbarNumer(int, void*)
{
	Proess();
}
static void on_StructElement(int, void*)
{
	Proess();
}
