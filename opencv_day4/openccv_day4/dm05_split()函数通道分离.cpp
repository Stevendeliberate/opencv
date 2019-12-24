#include<opencv2\opencv.hpp>

using namespace cv;
using namespace std;

void fenli()
{
	Mat srcImage;
	Mat imageROI;
	vector<Mat> channels;
	srcImage = imread("1.jpg");

	//把一个三通道图像转换成3个单通道的图像
	split(srcImage, channels);//分离色彩通道
	imageROI = channels.at(0);//分离了蓝色通道

	Mat imageROI2;
	imageROI2 = channels.at(1);//分离绿色通道

	Mat imageROI3;
	imageROI3 = channels.at(2);//分离红色通道

	imshow("origial", srcImage);
	imshow("blue", imageROI);
	imshow("green", imageROI2);
	imshow("red", imageROI3);

	Mat dstImage;
	merge(channels, dstImage);
	imshow("after merge", dstImage);
	waitKey(0);
	return;
}

void main51()
{
	fenli();
}
