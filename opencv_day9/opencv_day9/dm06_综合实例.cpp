#include<opencv2\imgproc\imgproc.hpp>
#include<opencv2\highgui\highgui.hpp>
#include<iostream>
using namespace std;
using namespace cv;

//ȫ�ֱ�������
//ԭͼ Ŀ��ͼ �Ҷ�ͼ
Mat src_Image, dst_Image, gray_Image;

//Canny��Ե������ر���
Mat g_cannyEdge;
int g_cannyLowThreshold = 1;

//sobel��Ե�����ر���
Mat g_sobelx, g_sobely;
Mat g_sobelabsx, g_sobelabsy;
int g_soblekernlsize = 1;

//scharr�˲�����ر���
Mat g_scharrx, g_scharry;
Mat g_scharrabsx, g_scharrabsy;


//ȫ�ֺ�������
static void on_canny(int, void *);
static void on_sobel(int, void *);
void scharr();

void main61()
{
	system("color 2F");

	src_Image = imread("1.jpg");
	if (!src_Image.data)
	{
		cout << "����ͼƬ�����������������" << endl;
	}

	//��ʾԭʼͼ
	imshow("��ԭʼͼ��", src_Image);

	//������src_Image�ߴ��������ͬ�ľ���dst
	dst_Image.create(src_Image.size(), src_Image.type());

	//��ԭͼ��ת��Ϊ�Ҷ�ͼ��
	cvtColor(src_Image, gray_Image, COLOR_RGB2GRAY);

	//��������
	namedWindow("��Ч��ͼ��Canny��Ե���", WINDOW_AUTOSIZE);
	namedWindow("��Ч��ͼ��Sobel��Ե���", WINDOW_AUTOSIZE);

	//����trackar
	createTrackbar("����ֵ", "��Ч��ͼ��Canny��Ե���", &g_cannyLowThreshold, 120, on_canny);
	createTrackbar("����ֵ", "��Ч��ͼ��Sobel��Ե���", &g_soblekernlsize, 3, on_sobel);

	//���ûص�����
	on_canny(0,0);
	on_sobel(0,0);

	//���÷�װ��scharr()��Ե����㷨��scharr��������
	scharr();

	while (char(waitKey(1) != 'q'))
	{
	}

	return ;
}

void on_canny(int, void *)
{
	//��ʹ��3*3�ں�ȥ��
	blur(gray_Image, g_cannyEdge, Size(3, 3));

	Canny(g_cannyEdge, g_cannyEdge, g_cannyLowThreshold, g_cannyLowThreshold * 3, 3);

	dst_Image = Scalar::all(0);
	
	src_Image.copyTo(dst_Image, g_cannyEdge);
	imshow("��Ч��ͼ��Canny��Ե���", dst_Image);
}

void on_sobel(int, void *)
{
	//x������ݶ�
	Sobel(src_Image, g_sobelx, CV_16S, 1, 0, (2 * g_soblekernlsize + 1), 1, 1, BORDER_DEFAULT);
	convertScaleAbs(g_sobelx, g_sobelabsx);//ʹ�����Ա任ת����������Ԫ�س�8λ�޷�������

	//y������ݶ�
	Sobel(src_Image, g_sobely, CV_16S, 0, 1, (2 * g_soblekernlsize + 1), 1, 1, BORDER_DEFAULT);
	convertScaleAbs(g_sobely, g_sobelabsy);//ʹ�����Ա任ת����������Ԫ�س�8λ�޷�������

	//�ϲ��ݶȣ����ƣ�
	addWeighted(g_sobelabsx, 0.5, g_sobelabsy, 0.5, 0, dst_Image);
	imshow("��Ч��ͼ��Sobel��Ե���", dst_Image);
}

void scharr()
{
	Scharr(src_Image, g_scharrx, CV_16S, 1, 0, 1, 0, BORDER_DEFAULT);
	convertScaleAbs(g_scharrx, g_scharrabsx);

	Scharr(src_Image,g_scharry, CV_16S, 0, 1, 1, 0, BORDER_DEFAULT);
	convertScaleAbs(g_scharry, g_scharrabsy);

	addWeighted(g_scharrabsx, 0.5, g_scharrabsy, 0.5, 0, dst_Image);
	imshow("��Ч��ͼ��Scharr��Ե���", dst_Image);
}