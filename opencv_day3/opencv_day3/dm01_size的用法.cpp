#include<opencv2\opencv.hpp>

using namespace cv;

void main01()
{
	Mat a(Size(5, 5), CV_8UC3);//8λ3ͨ��ͼ��
	randu(a, Scalar::all(0), Scalar::all(255));//�����0--255

	std::cout << format(a,"numpy") << std::endl;//numpy��ʾ
}