#include<opencv2\highgui\highgui.hpp>
#include<opencv2\imgproc\imgproc.hpp>

using namespace cv;

int main03()
{
	//��ȡͼ��
	Mat srcImage = imread("C:/Users/steven_cha/Pictures/1.jpg");

	//��ʾԭʼͼ
	imshow("��ֵ�˲���ԭͼ��", srcImage);

	//���о�ֵ�˲�����
	Mat dstimage;
	blur(srcImage, dstimage, Size(7, 7));//��ֵ�˲�����blur(ԭͼ��Ŀ��ͼ��size����)��

	//��ʾЧ��ͼ
	imshow("��ֵ�˲���Ч��ͼ��", dstimage);
	
	waitKey(0);
	return 0;

}