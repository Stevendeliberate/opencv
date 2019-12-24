#include<opencv2\opencv.hpp>

using namespace cv;

//方法一
void main11()
{
	Mat image;
	image = imread("1.jpg", CV_LOAD_IMAGE_ANYCOLOR);//读取原图图像
	Mat imageROI;//定义一个MAT类变量 
	imageROI = image(Rect(50, 50, image.rows-100,image.cols-200));//指定原图像中的ROI区域
	imshow("origial", image);
	imshow("ROI", imageROI);
	waitKey(0);
}

//方法二
void main12()
{
	Mat image;
	image = imread("1.jpg", CV_LOAD_IMAGE_ANYCOLOR);
	Mat imageROI;
	
	imageROI = image(Range(250, 400),Range(0,image.cols));//Range(a,b)是范围，即a——b的区域
	//image（Range（a，b），range（c，d））即image（行的范围，列的范围）。
	imshow("origial", image);
	imshow("ROI", imageROI);
	waitKey(0);
}