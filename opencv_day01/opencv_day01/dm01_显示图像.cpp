#include <opencv2\opencv.hpp>
#include<opencv2\highgui\highgui.hpp>
using namespace cv;
using namespace std;

int main()
{
	Mat img1 = imread("C:/Users/steven_cha/Pictures/1.jpg");//Ĭ�϶�ȡΪ1,  CV_LOAD_IMAGE_COLOR
	imshow("[ԭͼ��]", img1);

	Mat img2 = imread("C:/Users/steven_cha/Pictures/1.jpg", 0);//imread��������ȡֵΪ0�����ػҶ�ͼ��  CV_LOAD_IMAGE_GRAYSCALE
	imshow("[�Ҷ�ͼ��]", img2);

	Mat img3 = imread("C:/Users/steven_cha/Pictures/1.jpg", 2);//ȡֵΪ2�����ض�Ӧ��ȵ�ͼ�񣬷���ת��Ϊ8λͼ�񷵻ء�  CV_LOAD_IMAGE_ANYDEPTH
	imshow("[���ͼ��]", img3);

	Mat img4 = imread("͸��Alphaֵͼ.png", 0);
	imshow("1", img4);
	waitKey(0);
	return 0;
}