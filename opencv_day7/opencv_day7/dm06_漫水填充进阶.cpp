#include<opencv2\imgproc\imgproc.hpp>
#include<opencv2\highgui\highgui.hpp>
#include<opencv2\core\core.hpp>
#include<iostream>

using namespace std;
using namespace cv;

Mat g_srcImage, g_dstImage, g_grayImage, g_maskImage;//����ԭͼ��Ŀ��ͼ���Ҷ�ͼ����Ĥͼ
int g_nFillMode = 1;//��ˮ����ģʽ
int g_nLowDifference = 20, g_nUpDifference = 20;//����������ֵ
int g_nConnectivity = 4;//��ʾfloodFill������ʶ���Ͱ�λ����ֵͨ
bool g_bIsColor = true;//�Ƿ�Ϊ��ɫͼ�ı�ʶ������ֵ
bool g_bUseMask = false;//�Ƿ���ʾ��Ĥ���ڵĲ���ֵ
int g_nNewMaskVal = 255;//�µ����»��Ƶ�����ֵ

//�����ϢonMouse�����ص�����
static void onMouse(int event, int x, int y, int, void *)//x,yΪ����������ص�
{
	//��������û�а��£��㷵��
	if (event != EVENT_LBUTTONDOWN)
	{
		return;
	}

	//����floodfill����֮ǰ�Ĳ���׼������
	Point seed = Point(x, y);
	int LowDifference = g_nFillMode == 0 ? 0 : g_nLowDifference;//�շ�Χ����ˮ��䣬��ֵ��Ϊ0��������Ϊȫ�ֱ�����g_nLowDifference
	int UpDifference = g_nFillMode == 0 ? 0 : g_nUpDifference;//�շ�Χ����ˮ��䣬��ֵ��Ϊ0��������Ϊȫ�ֱ�����g_nUpDifference

	//��ʶ���ĵͰ�λΪg_nConnectivity��8-15λΪg_nNewMaskVal����8λ��ֵ��16-23λ��ֵΪCV_FLOODFILL_FIXED_RANGE����0
	int flags = g_nConnectivity + (g_nNewMaskVal << 8) + (g_nFillMode == 1 ? CV_FLOODFILL_FIXED_RANGE : CV_FLOODFILL_MASK_ONLY);

	//�������bgrֵ
	RNG bgr;
	int b = bgr.uniform(0, 255);
	int g = bgr.uniform(0, 255);
	int r = bgr.uniform(0, 255);
	Rect ccomp;//�����ػ��������С�߽��������

	Scalar newVal = g_bIsColor ? Scalar(b, g, r) : Scalar(r*0.299, g*0.587, b*0.114);//���ػ��������ص���ֵ�����ǲ�ɫģʽ��ȡScalar(b,g,r);���ǻҶ�ģʽ,ȡScalar(r*0.299, g*0.587, b*0.114)

	Mat dst = g_bIsColor ? g_dstImage : g_grayImage;//Ŀ��ͼ��ֵ
	int area;

	//��ʽ����floodFill����
	if (g_bUseMask)
	{
		threshold(g_maskImage, g_maskImage, 1, 128, THRESH_BINARY);
		area = floodFill(dst, g_maskImage, seed, newVal, &ccomp, Scalar(LowDifference, LowDifference, LowDifference), Scalar(UpDifference, UpDifference, UpDifference), flags);
		imshow("mask", g_maskImage);
	}
	else
	{
		area = floodFill(dst, seed, newVal, &ccomp, Scalar(LowDifference, LowDifference, LowDifference), Scalar(UpDifference, UpDifference, UpDifference), flags);
	}

	imshow("Ч��ͼ", dst);
	cout << area << "�����ر��ػ�" << endl;

}

int main(int argc,char** argv)
{
	g_srcImage = imread("1.jpg",1);

	if (!g_srcImage.data)
	{
		cout << "��ȡͼƬ����" << endl;
		return false;
	}

	g_srcImage.copyTo(g_dstImage);//���Ƶ�Ŀ��ͼ

	cvtColor(g_dstImage, g_grayImage, COLOR_RGB2GRAY);
	g_maskImage.create(g_srcImage.rows + 2, g_srcImage.cols + 2, CV_8UC1);//����image0�ĳߴ�����ʼ����Ĥmask

	namedWindow("Ч��ͼ", WINDOW_AUTOSIZE);

	//����Trackbar
	createTrackbar("�������ֵ", "Ч��ͼ", &g_nLowDifference, 255, 0);
	createTrackbar("�������ֵ", "Ч��ͼ", &g_nUpDifference, 255, 0);

	//���ص�����
	setMouseCallback("Ч��ͼ", onMouse, 0);

	//ѭ����ѯ����
	while (1)
	{
		//��ʾЧ��ͼ
		imshow("Ч��ͼ", g_bIsColor ? g_dstImage : g_grayImage);

		//��ȡ���̰���
		int c = waitKey(0);
		//�ж�ESC�Ƿ��£����±��˳�
		if ((c & 255) == 27)
		{
			cout << "�����˳�������" << endl;
			break;
		}
		switch ((char)c)
		{
		case'1':
			if (g_bIsColor)
			{
				cout << "����1�����£��л���ɫ/�Ҷ�ģʽ����ǰ����Ϊ������ɫģʽ���л�Ϊ���Ҷ�ģʽ��" << endl;
				cvtColor(g_srcImage, g_grayImage, COLOR_RGB2GRAY);
				g_maskImage = Scalar::all(0);
				g_bIsColor = false;
			}
			else
			{
				cout << "����1�����£��л���ɫ/�Ҷ�ģʽ����ǰ����Ϊ�����Ҷ�ģʽ���л�Ϊ����ɫģʽ��" << endl;
				g_srcImage.copyTo(g_dstImage);
				g_maskImage = Scalar::all(0);
				g_bIsColor = true;
			}
			break;
			//����2���£���ʾ/������Ĥ����
		case'2':
			if (g_bUseMask)
			{
				destroyWindow("mask");
				g_bUseMask = false;
			}
			else
			{
				namedWindow("mask", 0);
				g_maskImage = Scalar::all(0);
				imshow("mask", g_maskImage);
				g_bUseMask = true;
			}
			break;
		case '3':
			cout << "������3�������£��ָ�ԭʼͼ��\n";
			g_srcImage.copyTo(g_dstImage);
			cvtColor(g_dstImage, g_grayImage, COLOR_BGR2GRAY);
			g_maskImage = Scalar::all(0);
			break;
			//������̰�����4�������£�ʹ�ÿշ�Χ����ˮ���
		case '4':
			cout << "������4�������£�ʹ�ÿշ�Χ����ˮ���\n";
			g_nFillMode = 0;
			break;
			//������̰�����5�������£�ʹ�ý��䡢�̶���Χ����ˮ���
		case '5':
			cout << "������5�������£�ʹ�ý��䡢�̶���Χ����ˮ���\n";
			g_nFillMode = 1;
			break;
			//������̰�����6�������£�ʹ�ý��䡢������Χ����ˮ���
		case '6':
			cout << "������6�������£�ʹ�ý��䡢������Χ����ˮ���\n";
			g_nFillMode = 2;
			break;
			//������̰�����7�������£�������־���ĵͰ�λʹ��4λ������ģʽ
		case '7':
			cout << "������7�������£�������־���ĵͰ�λʹ��4λ������ģʽ\n";
			g_nConnectivity = 4;
			break;
			//������̰�����8�������£�������־���ĵͰ�λʹ��8λ������ģʽ
		case '8':
			cout << "������8�������£�������־���ĵͰ�λʹ��8λ������ģʽ\n";
			g_nConnectivity = 8;
			break;
		}
	}
	return 0;
}
