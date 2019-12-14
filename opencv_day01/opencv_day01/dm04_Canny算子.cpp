#include<opencv2\opencv.hpp>
#include<opencv2\imgproc\imgproc.hpp>

using namespace cv;

int main04()
{
	//载入原图像
	Mat srcImage = imread("C:/Users/steven_cha/Pictures/1.jpg");
	imshow("【原始图】Canny边缘检测", srcImage);
	Mat dstImage, edge, grayImage;
	
	//创建与src同类型和大小的矩阵(dst)
	dstImage.create(srcImage.size(), srcImage.type());

	//将原始图像转化为灰度图像
	cvtColor(srcImage, grayImage, COLOR_BGR2GRAY);

	//先使用3*3内核来降噪
	blur(grayImage, edge, Size(3, 3));

	//运行Canny算子
	Canny(edge, edge, 3, 9, 3);

	//显示效果图
	imshow("【效果图】Canny边缘检测",edge);

	waitKey(0);
	return 0;
}