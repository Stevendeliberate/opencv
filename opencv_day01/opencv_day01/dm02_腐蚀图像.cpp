#include<opencv2\highgui\highgui.hpp>
#include<opencv2\imgproc\imgproc.hpp>

using namespace cv;

int main02()
{
	//����ԭͼ
	Mat StrImage = imread("C:/Users/steven_cha/Pictures/1.jpg");
	//��ʾԭͼ
	imshow("ԭʼͼ", StrImage);

	//����ͼ��ʴ����
	Mat element = getStructuringElement(MORPH_RECT, Size(15, 15));
	Mat desImage;
	erode(StrImage, desImage, element);
	//��ʾЧ��ͼ
	imshow("[Ч��ͼ]��ʴ����", desImage);
	waitKey(0);

	return 0;
}