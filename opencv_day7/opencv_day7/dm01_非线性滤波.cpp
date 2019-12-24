/*
//头文件以及命名空间
#include<opencv2\imgproc\imgproc.hpp>
#include<opencv2\highgui\highgui.hpp>
#include<opencv2\core\core.hpp>
#include<iostream>
using namespace cv;
using namespace std;

//全局函数声明部分
static void g_medianBlur(int, void *);
static void g_bilateralFilter(int, void *);

//全局变量声明部分
Mat srcImage, dstImage4, dstImage5;
int g_nmedianBlurValue = 10;
int g_nbilateralFilterValue = 10;

void main11()
{
	system("color 9F");

	//读取原始图像
	srcImage = imread("1.jpg");
	if (!(srcImage.data))
	{
		cout << "读取图片错误，请检查图片是否存在"<<endl;
		return;
	}

	//创建窗口并显示
	namedWindow("【原始图像】");
	imshow("【原始图像】", srcImage);

	//中值滤波函数
	namedWindow("【中值滤波函数】");

	createTrackbar("参数值", "【中值滤波函数】", &g_nmedianBlurValue, 50, g_medianBlur);	//创建轨迹条
	g_medianBlur(g_nmedianBlurValue,0);

	//双边滤波
	namedWindow("【双边滤波函数】");

	createTrackbar("参数值", "【双边滤波函数】", &g_nbilateralFilterValue, 50, g_bilateralFilter);
	g_bilateralFilter(g_nbilateralFilterValue,0);

	waitKey(0);
}

//中值滤波
static void g_medianBlur(int, void *)
{
	dstImage4 = srcImage.clone();

	medianBlur(dstImage4, dstImage4, g_nmedianBlurValue*2+1);
	imshow("【中值滤波函数】", dstImage4);
}

//双边滤波
static void g_bilateralFilter(int, void *)
{
	bilateralFilter(srcImage, dstImage5, g_nbilateralFilterValue, g_nbilateralFilterValue * 2, g_nbilateralFilterValue / 2);
	imshow("【双边滤波函数】", dstImage5);
}
*/