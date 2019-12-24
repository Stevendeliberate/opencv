#include<opencv2\core\core.hpp>
#include<opencv2\highgui\highgui.hpp>
#include<imgproc\imgproc.hpp>


#define WINDOW_WIDTH 600
#define WINDOW_NAME1 "image 1"
#define WINDOW_NAME2 "image 2"
using namespace cv;

void DrawEllipse(Mat img, double angle)//����Բ
{
	int thickness = 2;//�����߿�
	int lineType = 8;//��������

	ellipse(img,
		Point(WINDOW_WIDTH / 2, WINDOW_WIDTH / 2),//��Բ���ĵ�
		Size(WINDOW_WIDTH / 4, WINDOW_WIDTH / 16),//��Сλ�ھ���(WINDOW_WIDTH / 4, WINDOW_WIDTH / 16)��
		angle,//��Բ����ת�Ƕ�Ϊangle
		0,360,//��չ�Ļ��ȴ�0��360��
		Scalar(255, 0, 0),//�ı���Բ��ɫ��������ɫ
		thickness,//�߿�
		lineType);//���ͣ�8��ͨ���ԣ�
}

void DrawFilledCricle(Mat img, Point center)
{
	int thickness = 10;//�����߿�
	int lineType = 8;//��������

	circle(img,
		center,//Բ��
		WINDOW_WIDTH/32,//�뾶
		Scalar(0,0,255),//��ɫBGR�ĺ�ɫ
		thickness,lineType);
}

void DrawPolygon(Mat img)//���ƶ����
{
	int lineType = 8;

	//����һЩ��
	Point rookPoints[1][20];
	rookPoints[0][0] = Point(WINDOW_WIDTH / 4, 7 * WINDOW_WIDTH / 8);
	rookPoints[0][1] = Point(3 * WINDOW_WIDTH / 4, 7 * WINDOW_WIDTH / 8);
	rookPoints[0][2] = Point(3 * WINDOW_WIDTH / 4, 13 * WINDOW_WIDTH / 16);
	rookPoints[0][3] = Point(11 * WINDOW_WIDTH / 16, 13 * WINDOW_WIDTH / 16);
	rookPoints[0][4] = Point(19 * WINDOW_WIDTH / 32, 3 * WINDOW_WIDTH / 8);
	rookPoints[0][5] = Point(3 * WINDOW_WIDTH / 4, 3 * WINDOW_WIDTH / 8);
	rookPoints[0][6] = Point(3 * WINDOW_WIDTH / 4, WINDOW_WIDTH / 8);
	rookPoints[0][7] = Point(26 * WINDOW_WIDTH / 40, WINDOW_WIDTH / 8);
	rookPoints[0][8] = Point(26 * WINDOW_WIDTH / 40, WINDOW_WIDTH / 4);
	rookPoints[0][9] = Point(22 * WINDOW_WIDTH / 40, WINDOW_WIDTH / 4);
	rookPoints[0][10] = Point(22 * WINDOW_WIDTH / 40, WINDOW_WIDTH / 8);
	rookPoints[0][11] = Point(18 * WINDOW_WIDTH / 40, WINDOW_WIDTH / 8);
	rookPoints[0][12] = Point(18 * WINDOW_WIDTH / 40, WINDOW_WIDTH / 4);
	rookPoints[0][13] = Point(14 * WINDOW_WIDTH / 40, WINDOW_WIDTH / 4);
	rookPoints[0][14] = Point(14 * WINDOW_WIDTH / 40, WINDOW_WIDTH / 8);
	rookPoints[0][15] = Point(WINDOW_WIDTH / 4, WINDOW_WIDTH / 8);
	rookPoints[0][16] = Point(WINDOW_WIDTH / 4, 3 * WINDOW_WIDTH / 8);
	rookPoints[0][17] = Point(13 * WINDOW_WIDTH / 32, 3 * WINDOW_WIDTH / 8);
	rookPoints[0][18] = Point(5 * WINDOW_WIDTH / 16, 13 * WINDOW_WIDTH / 16);
	rookPoints[0][19] = Point(WINDOW_WIDTH / 4, 13 * WINDOW_WIDTH / 16);

	const Point* ppt[1] = { rookPoints[0] };//�������εĶ��㼯
	int npt[] = { 20 };//�������ζ�����ĿΪ20��

	fillPoly(img,
		ppt,
		npt,
		1,//Ҫ���ƵĶ����������Ϊ1
		Scalar(255, 255, 255),//��ɫ
		lineType);
}

void DrawLine(Mat img, Point start, Point end)//������
{
	int thickness = 2;
	int lineType = 8;
	line(img,
		start,
		end,
		thickness,
		lineType
		);
}

int main51()
{
	//�����հ�ͼ��
	Mat atomImage = Mat::zeros(WINDOW_WIDTH, WINDOW_WIDTH, CV_8UC3);
	Mat rookImage = Mat::zeros(WINDOW_WIDTH, WINDOW_WIDTH, CV_8UC3);

	//�Ȼ�����Բ
	DrawEllipse(atomImage, 90);
	DrawEllipse(atomImage, 0);
	DrawEllipse(atomImage, 45);
	DrawEllipse(atomImage, -45);

	//��������Բ
	DrawFilledCricle(atomImage,Point(WINDOW_WIDTH/2,WINDOW_WIDTH/2));

	//���ƶ����
	DrawPolygon(rookImage);

	//���ƾ���
	rectangle(rookImage,
		Point(0, 7 * WINDOW_WIDTH/8),//�������Ͻǵĵ�
		Point(WINDOW_WIDTH, WINDOW_WIDTH),//�������½ǵĵ�
		Scalar(0, 255, 255),//��ɫ
		-1,
		8);
	
	//����һЩ�߶�
	DrawLine(rookImage, Point(0, 15 * WINDOW_WIDTH / 16), Point(WINDOW_WIDTH, 15 * WINDOW_WIDTH / 16));
	DrawLine(rookImage, Point(WINDOW_WIDTH / 4, 7 * WINDOW_WIDTH / 8), Point(WINDOW_WIDTH / 4, WINDOW_WIDTH));
	DrawLine(rookImage, Point(WINDOW_WIDTH / 2, 7 * WINDOW_WIDTH / 8), Point(WINDOW_WIDTH / 2, WINDOW_WIDTH));
	DrawLine(rookImage, Point(3 * WINDOW_WIDTH / 4, 7 * WINDOW_WIDTH / 8), Point(3 * WINDOW_WIDTH / 4, WINDOW_WIDTH));

	//��ʾͼ��
	imshow(WINDOW_NAME1, atomImage);
	moveWindow(WINDOW_NAME1, 0, 200);
	imshow(WINDOW_NAME2, rookImage);
	moveWindow(WINDOW_NAME2, WINDOW_WIDTH, 300);

	waitKey(0);
	return 0;
}
