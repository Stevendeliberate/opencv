//头文件以及命名空间的声明
#include<opencv2\highgui\highgui.hpp>
#include<opencv2\core\core.hpp>
#include<iostream>

using namespace std;
using namespace cv;

//全局变量的声明

int g_nContrastValue;//对比度值
int g_nBrightValue;//亮度值
Mat g_srcImage, g_dstImage;//输入图像 输出图像

static void on_ContrastAndBright(int, void *)
{
	namedWindow("原始图像窗口", 1);
	
	for (int y = 0; y < g_srcImage.rows;y++)
	{
		for (int x = 0; x < g_srcImage.cols;x++)
		{
			for (int c = 0; c < 3;c++)
			{
				g_dstImage.at<Vec3b>(y, x)[c] = saturate_cast<uchar>((g_nContrastValue*0.01)*(g_srcImage.at<Vec3b>(y, x)[c]) + g_nBrightValue);//算子
			}
		}
	}
	//显示图像
	imshow("原始图像窗口", g_srcImage);
	imshow("效果图窗口", g_dstImage);
}

int main71()
{
	g_srcImage = imread("1.jpg");
	if (!g_srcImage.data)
	{
		cout << "读取图片出错" << endl;
		return false;
	}
	g_dstImage = Mat::zeros(g_srcImage.size(), g_srcImage.type());//创建一个和输入图片大小和格式相同的矩阵

	//初始化对比度和亮度值
	g_nBrightValue = 80;
	g_nContrastValue = 80;

	//创建窗口
	namedWindow("效果图窗口", 1);

	//创建轨迹条
	createTrackbar("对比度：", "效果图窗口", &g_nContrastValue, 300, on_ContrastAndBright);
	createTrackbar("亮度：", "效果图窗口", &g_nBrightValue, 200, on_ContrastAndBright);

	//回调函数初始化
	on_ContrastAndBright(g_nContrastValue, 0);
	on_ContrastAndBright(g_nBrightValue, 0);

	while (char(waitKey(1)) != 'q')
	{
	}
	return 0;
}
