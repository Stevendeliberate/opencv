//全局变量及命名空间
#include<opencv2\core\core.hpp>
#include<opencv2\highgui\highgui.hpp>
#include<opencv2\imgproc\imgproc.hpp>
#include<iostream>

using namespace cv;
using namespace std;

//全局函数的声明
Mat srcImage, dstImage;
int g_nTrackbarNumer = 0;
int g_nStructElement = 10;

//全局函数的声明
static void Proess();
static void on_TrackbarNumer(int, void*);
static void on_StructElement(int, void*);

int main41()
{
	srcImage = imread("1.jpg");
	if (!srcImage.data)
	{
		cout << "图像加载错误，请检查图像" << endl;
		return false;
	}

	namedWindow("【原图像】");
	imshow("【原图像】", srcImage);

	//创建滑动条
	namedWindow("【效果图】");
	createTrackbar("模式","【效果图】",&g_nTrackbarNumer,7,on_TrackbarNumer);
	createTrackbar("内核尺寸","【效果图】",&g_nStructElement,50,on_StructElement);

	waitKey(0);
	return 0;
}

static void Proess()
{
	Mat element = getStructuringElement(MORPH_RECT, Size(2 * g_nStructElement + 1, 2 * g_nStructElement + 1), Point(g_nStructElement, g_nStructElement));

	if (g_nTrackbarNumer == 0)
	{
		dstImage = srcImage.clone();
		imshow("【效果图】", dstImage);
	}
	else if (g_nTrackbarNumer == 1)//开运算
	{
		morphologyEx(srcImage, dstImage, MORPH_OPEN, element);
		imshow("【效果图】", dstImage);
	}
	else if (g_nTrackbarNumer == 2)//开运算
	{
		morphologyEx(srcImage, dstImage, MORPH_CLOSE, element);
		imshow("【效果图】", dstImage);
	}
	else if (g_nTrackbarNumer == 3)//开运算
	{
		morphologyEx(srcImage, dstImage, MORPH_GRADIENT, element);
		imshow("【效果图】", dstImage);
	}
	else if (g_nTrackbarNumer == 4)//开运算
	{
		morphologyEx(srcImage, dstImage, MORPH_TOPHAT, element);
		imshow("【效果图】", dstImage);
	}
	else if (g_nTrackbarNumer == 5)//开运算
	{
		morphologyEx(srcImage, dstImage, MORPH_BLACKHAT, element);
		imshow("【效果图】", dstImage);
	}
	else if (g_nTrackbarNumer == 6)//开运算
	{
		morphologyEx(srcImage, dstImage, MORPH_ERODE, element);
		imshow("【效果图】", dstImage);
	}
	else if (g_nTrackbarNumer == 7)//开运算
	{
		morphologyEx(srcImage, dstImage,MORPH_DILATE, element);
		imshow("【效果图】", dstImage);
	}
}

static void on_TrackbarNumer(int, void*)
{
	Proess();
}
static void on_StructElement(int, void*)
{
	Proess();
}
