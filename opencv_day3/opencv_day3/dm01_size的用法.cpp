#include<opencv2\opencv.hpp>

using namespace cv;

void main01()
{
	Mat a(Size(5, 5), CV_8UC3);//8位3通道图像
	randu(a, Scalar::all(0), Scalar::all(255));//随机数0--255

	std::cout << format(a,"numpy") << std::endl;//numpy显示
}