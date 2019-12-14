//ͷ�ļ�
#include<opencv2\core\core.hpp>
#include<opencv2\highgui\highgui.hpp>

//�����ռ� cv
using namespace cv;

int main11()
{
	//1.ͼ����������ʾ
	
	Mat girl = imread("girl.jpg");//����ͼ��Mat�����µ�girl
	namedWindow("[1]����ͼ");//������1������ͼ�Ĵ���
	imshow("[1]����ͼ",girl);//��ʾ��Ϊ��1������ͼ�Ĵ���

	//------------------------------------------------------------------------------------------//
	//2.����ͼ����
	
	//��������ͼ��
	Mat image = imread("dota.jpg",199);
	Mat logo = imread("dota_logo.jpg");

	//�������ʾ
	namedWindow("[2]ԭ��ͼ");
	imshow("[2]ԭ��ͼ", image);

	namedWindow("[3]logoͼ");
	imshow("[3]logoͼ", logo);
	
	//����һ��Mat���ͣ����ڴ�ţ�ͼ���ROI
	Mat imageROI;

	//����һ
	imageROI = image(Rect(800, 350, logo.cols, logo.rows));

	//������
	//imageROI = image(Range(350, 350 + logo.rows), Range(800, 800 + logo.cols));

	//��logo�ӵ�ԭͼ��
	addWeighted(imageROI, 0.5, logo, 0.3, 0., imageROI);

	//��ʾ���
	namedWindow("[4]ԭ��+logoͼ");
	imshow("[4]ԭ��+logoͼ", image);
	//----------------------------------------------------------------------------------------//

	//3.ͼ������
	imwrite("ԭͼ+logoͼ.jpg", image);
	waitKey(0);

	return 0;
}