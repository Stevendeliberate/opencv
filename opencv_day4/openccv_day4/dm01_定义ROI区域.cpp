#include<opencv2\opencv.hpp>

using namespace cv;

//����һ
void main11()
{
	Mat image;
	image = imread("1.jpg", CV_LOAD_IMAGE_ANYCOLOR);//��ȡԭͼͼ��
	Mat imageROI;//����һ��MAT����� 
	imageROI = image(Rect(50, 50, image.rows-100,image.cols-200));//ָ��ԭͼ���е�ROI����
	imshow("origial", image);
	imshow("ROI", imageROI);
	waitKey(0);
}

//������
void main12()
{
	Mat image;
	image = imread("1.jpg", CV_LOAD_IMAGE_ANYCOLOR);
	Mat imageROI;
	
	imageROI = image(Range(250, 400),Range(0,image.cols));//Range(a,b)�Ƿ�Χ����a����b������
	//image��Range��a��b����range��c��d������image���еķ�Χ���еķ�Χ����
	imshow("origial", image);
	imshow("ROI", imageROI);
	waitKey(0);
}