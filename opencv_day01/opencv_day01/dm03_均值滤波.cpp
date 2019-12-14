#include<opencv2\highgui\highgui.hpp>
#include<opencv2\imgproc\imgproc.hpp>

using namespace cv;

int main03()
{
	//读取图像
	Mat srcImage = imread("C:/Users/steven_cha/Pictures/1.jpg");

	//显示原始图
	imshow("均值滤波【原图】", srcImage);

	//进行均值滤波操作
	Mat dstimage;
	blur(srcImage, dstimage, Size(7, 7));//均值滤波函数blur(原图像，目标图像，size（）)；

	//显示效果图
	imshow("均值滤波【效果图】", dstimage);
	
	waitKey(0);
	return 0;

}