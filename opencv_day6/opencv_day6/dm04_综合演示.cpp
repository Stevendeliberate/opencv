/*
//ͷ�ļ��Լ������ռ�����
#include<opencv2\imgproc\imgproc.hpp>
#include<opencv2\core\core.hpp>
#include<opencv2\highgui\highgui.hpp>
#include<iostream>
using namespace cv;
using namespace std;

//ȫ�ֱ�������
Mat g_srcImage, g_dstImage1, g_dstImage2, g_dstImage3;
int g_nBoxFilterValue = 3;
int g_nblurValue = 3;
int g_nGaussianBlurValue = 3;

static void on_BoxFilter(int, void *);//�����˲�
static void on_blur(int, void *);//��ֵ�˲�
static void on_GaussianBlur(int, void *);//��˹�˲�

int main()
{
	system("color 5E");

	//����ԭͼ
	g_srcImage = imread("1.jpg");
	if (!g_srcImage.data)
	{
		cout << "����ͼ��ʧ�ܣ�����ͼ���Ƿ����" << endl;
	}

	//����ԭͼ������Mat��
	g_dstImage1 = g_srcImage.clone();
	g_dstImage2 = g_srcImage.clone();
	g_dstImage3 = g_srcImage.clone();

	//��ʾԭͼ
	namedWindow("[0]ԭͼ����", 1);
	imshow("[0]ԭͼ����", g_srcImage);

	//���������˲�����
	namedWindow("��1�������˲�",1);
	createTrackbar("�ں�ֵ", "��1�������˲�", &g_nBoxFilterValue, 40, on_BoxFilter);
	on_BoxFilter(g_nBoxFilterValue, 0);

	//������ֵ�˲�����
	namedWindow("��2����ֵ�˲�", 1);
	createTrackbar("�ں�ֵ", "��2����ֵ�˲�", &g_nblurValue, 40, on_blur);
	on_blur(g_nblurValue, 0);

	//������˹�˲�����
	namedWindow("��3����˹�˲�", 1);
	createTrackbar("�ں�ֵ", "��3����˹�˲�", &g_nGaussianBlurValue, 40, on_GaussianBlur);
	on_GaussianBlur(g_nGaussianBlurValue, 0);

	cout << "����q��ʱ�����˳�" << endl;

	while (char(waitKey(1) != 'q'))
	{	}
	return 0;
}

static void on_BoxFilter(int, void *)//�����˲�
{
	boxFilter(g_dstImage1, g_dstImage1, -1, Size(g_nBoxFilterValue + 1, g_nBoxFilterValue + 1));
	imshow("��1�������˲�", g_dstImage1);
}
static void on_blur(int, void *)//��ֵ�˲�
{
	blur(g_dstImage2, g_dstImage2, Size(g_nblurValue + 1, g_nblurValue + 1));
	imshow("��2����ֵ�˲�", g_dstImage2);
}
static void on_GaussianBlur(int, void *)//��˹�˲�
{
	GaussianBlur(g_dstImage3, g_dstImage3, Size(g_nGaussianBlurValue*2 + 1, g_nGaussianBlurValue*2 + 1), 0, 0);//size����Ϊ����
	imshow("��3����˹�˲�", g_dstImage3);
}
*/