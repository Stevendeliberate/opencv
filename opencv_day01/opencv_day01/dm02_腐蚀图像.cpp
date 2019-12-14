#include<opencv2\highgui\highgui.hpp>
#include<opencv2\imgproc\imgproc.hpp>

using namespace cv;

int main02()
{
	//载入原图
	Mat StrImage = imread("C:/Users/steven_cha/Pictures/1.jpg");
	//显示原图
	imshow("原始图", StrImage);

	//进行图像腐蚀操作
	Mat element = getStructuringElement(MORPH_RECT, Size(15, 15));
	Mat desImage;
	erode(StrImage, desImage, element);
	//显示效果图
	imshow("[效果图]腐蚀操作", desImage);
	waitKey(0);

	return 0;
}