/*
//ͷ�ļ��Լ������ռ�
#include<opencv2\imgproc\imgproc.hpp>
#include<opencv2\highgui\highgui.hpp>
#include<opencv2\core\core.hpp>
#include<iostream>

using namespace std;
using namespace cv;

//ȫ�ֺ���������
static void Proess();//���ʹ�����
static void on_TrackbarNumChange(int, void *);
static void on_ElementSizeChange(int, void *);

//ȫ�ֱ�������
Mat g_srcImage, g_dstImage;
int g_nTrackbarNumer = 0;//0��ʾ��ʴerode��1��ʾ����dilate
int g_nStructElement = 3;//�ں˳ߴ�

int main()
{
	g_srcImage = imread("1.jpg");
	if (!g_srcImage.data)
	{
		cout << "����ͼ�񲻴��ڣ�����ͼ��" << endl;
	}

	namedWindow("ԭͼ��");
	imshow("ԭͼ��", g_srcImage);

	namedWindow("Ч��ͼ");

	createTrackbar("��ʴ/����", "Ч��ͼ", &g_nTrackbarNumer, 1, on_TrackbarNumChange);
	createTrackbar("�ں˳ߴ�", "Ч��ͼ", &g_nStructElement, 21,on_ElementSizeChange);

	waitKey(0);

}

static void process()
{
	Mat element = getStructuringElement(MORPH_RECT, Size(2 * g_nStructElement + 1, 2 * g_nStructElement + 1), Point(g_nStructElement, g_nStructElement));

	if (g_nTrackbarNumer == 0)
	{
		erode(g_srcImage, g_dstImage, element);
	}
	else
	{
		dilate(g_srcImage, g_dstImage, element);

	}
	imshow("Ч��ͼ", g_dstImage);
}

static void on_TrackbarNumChange(int, void *)
{
	process();
}

static void on_ElementSizeChange(int, void *)
{
	process();
}
*/