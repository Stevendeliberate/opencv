/*
//头文件以及命名空间声明
#include<opencv2\imgproc\imgproc.hpp>
#include<opencv2\core\core.hpp>
#include<opencv2\highgui\highgui.hpp>
#include<iostream>
using namespace cv;
using namespace std;

//全局变量声明
Mat g_srcImage, g_dstImage1, g_dstImage2, g_dstImage3;
int g_nBoxFilterValue = 3;
int g_nblurValue = 3;
int g_nGaussianBlurValue = 3;
Mat dstImage4, dstImage5;
int g_nmedianBlurValue = 10;
int g_nbilateralFilterValue = 10;

static void on_BoxFilter(int, void *);//方框滤波
static void on_blur(int, void *);//均值滤波
static void on_GaussianBlur(int, void *);//高斯滤波
static void g_medianBlur(int, void *);//中值滤波
static void g_bilateralFilter(int, void *);//双边滤波

int main21()
{
	system("color 5E");

	//载入原图
	g_srcImage = imread("1.jpg");
	if (!g_srcImage.data)
	{
		cout << "载入图像失败，请检查图像是否存在" << endl;
	}

//	cvtColor(g_srcImage,g_srcImage,COLOR_BGR2GRAY);
// 	imshow("1", g_srcImage);

	//显示原图
	namedWindow("[0]原图窗口", 1);
	imshow("[0]原图窗口", g_srcImage);

	//创建方框滤波窗口
	namedWindow("【1】方框滤波", 1);
	createTrackbar("内核值", "【1】方框滤波", &g_nBoxFilterValue, 100, on_BoxFilter);
	on_BoxFilter(g_nBoxFilterValue, 0);

	//创建均值滤波窗口
	namedWindow("【2】均值滤波", 1);
	createTrackbar("内核值", "【2】均值滤波", &g_nblurValue, 100, on_blur);
	on_blur(g_nblurValue, 0);

	//创建高斯滤波窗口
	namedWindow("【3】高斯滤波", 1);
	createTrackbar("内核值", "【3】高斯滤波", &g_nGaussianBlurValue, 100, on_GaussianBlur);
	on_GaussianBlur(g_nGaussianBlurValue, 0);

	//中值滤波函数
	namedWindow("【中值滤波函数】");

	createTrackbar("参数值", "【中值滤波函数】", &g_nmedianBlurValue, 50, g_medianBlur);	//创建轨迹条
	g_medianBlur(g_nmedianBlurValue, 0);

	//双边滤波
	namedWindow("【双边滤波函数】");

	createTrackbar("参数值", "【双边滤波函数】", &g_nbilateralFilterValue, 50, g_bilateralFilter);
	g_bilateralFilter(g_nbilateralFilterValue, 0);


	cout << "按下q键时程序退出" << endl;

	while (char(waitKey(1) != 'q'))
	{
	}
	return 0;
}

static void on_BoxFilter(int, void *)//方框滤波
{
	//复制原图到Mat中
	g_dstImage1 = g_srcImage.clone();
	boxFilter(g_dstImage1, g_dstImage1, -1, Size(g_nBoxFilterValue + 1, g_nBoxFilterValue + 1));
	imshow("【1】方框滤波", g_dstImage1);
}
static void on_blur(int, void *)//均值滤波
{
	//复制原图到Mat中
	g_dstImage2 = g_srcImage.clone();
	blur(g_dstImage2, g_dstImage2, Size(g_nblurValue + 1, g_nblurValue + 1));
	imshow("【2】均值滤波", g_dstImage2);
}
static void on_GaussianBlur(int, void *)//高斯滤波
{
	//复制原图到Mat中
	g_dstImage3 = g_srcImage.clone();
	GaussianBlur(g_dstImage3, g_dstImage3, Size(g_nGaussianBlurValue * 2 + 1, g_nGaussianBlurValue * 2 + 1), 0, 0);//size必须为单数
	imshow("【3】高斯滤波", g_dstImage3);
}
//中值滤波
static void g_medianBlur(int, void *)
{
	dstImage4 = g_srcImage.clone();

	medianBlur(dstImage4, dstImage4, g_nmedianBlurValue * 2 + 1);
	imshow("【中值滤波函数】", dstImage4);
}
//双边滤波
static void g_bilateralFilter(int, void *)
{
	bilateralFilter(g_srcImage, dstImage5, g_nbilateralFilterValue, g_nbilateralFilterValue * 2, g_nbilateralFilterValue / 2);
	imshow("【双边滤波函数】", dstImage5);
}
*/