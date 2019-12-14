#include <opencv2\opencv.hpp>
#include<opencv2\highgui\highgui.hpp>
using namespace cv;
using namespace std;

int main()
{
	Mat img1 = imread("C:/Users/steven_cha/Pictures/1.jpg");//默认读取为1,  CV_LOAD_IMAGE_COLOR
	imshow("[原图像]", img1);

	Mat img2 = imread("C:/Users/steven_cha/Pictures/1.jpg", 0);//imread（）函数取值为0，返回灰度图像，  CV_LOAD_IMAGE_GRAYSCALE
	imshow("[灰度图像]", img2);

	Mat img3 = imread("C:/Users/steven_cha/Pictures/1.jpg", 2);//取值为2，返回对应深度的图像，否则转换为8位图像返回。  CV_LOAD_IMAGE_ANYDEPTH
	imshow("[深度图像]", img3);

	Mat img4 = imread("透明Alpha值图.png", 0);
	imshow("1", img4);
	waitKey(0);
	return 0;
}