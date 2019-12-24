#include<opencv2\imgproc\imgproc.hpp>
#include<opencv2\highgui\highgui.hpp>
#include<opencv2\core\core.hpp>
#include<iostream>
using namespace std;
using namespace cv;

int main11()//低阶Canny边缘算子
{
	Mat srcImage = imread("1.jpg");
	Mat dst;

	imshow("原图", srcImage);
	Canny(srcImage, dst, 9, 3,3);
	imshow("效果图", dst);
	waitKey(0);
	return 0;
}

//高阶Canny边缘算法
//先转成灰度图，降噪，用Canny，最后得到边缘作为掩码，拷贝原图到效果图上，得到彩色的边缘图
int main12()
{
	Mat srcImage = imread("1.jpg");
	Mat dst;

	imshow("原图", srcImage);
	Mat edge, gray;

	//创建一个与src同类型和大小的矩阵dst
	dst.create(srcImage.size(), srcImage.type());

	cvtColor(srcImage, gray, COLOR_RGB2GRAY);
	blur(gray, edge, Size(3, 3));

	Canny(edge, edge, 3, 9, 3);

	dst = Scalar::all(0);

	srcImage.copyTo(dst, edge);
	imshow("效果图2", dst);
	waitKey(0);
	return 0;
}

