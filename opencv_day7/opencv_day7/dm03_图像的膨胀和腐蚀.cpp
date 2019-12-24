/*
//头文件以及命名空间
#include<opencv2\imgproc\imgproc.hpp>
#include<opencv2\highgui\highgui.hpp>
#include<opencv2\core\core.hpp>
#include<iostream>

using namespace std;
using namespace cv;

//全局函数的声明
static void Proess();//膨胀处理函数
static void on_TrackbarNumChange(int, void *);
static void on_ElementSizeChange(int, void *);

//全局变量声明
Mat g_srcImage, g_dstImage;
int g_nTrackbarNumer = 0;//0表示腐蚀erode，1表示膨胀dilate
int g_nStructElement = 3;//内核尺寸

int main()
{
	g_srcImage = imread("1.jpg");
	if (!g_srcImage.data)
	{
		cout << "输入图像不存在，请检查图像" << endl;
	}

	namedWindow("原图像");
	imshow("原图像", g_srcImage);

	namedWindow("效果图");

	createTrackbar("腐蚀/膨胀", "效果图", &g_nTrackbarNumer, 1, on_TrackbarNumChange);
	createTrackbar("内核尺寸", "效果图", &g_nStructElement, 21,on_ElementSizeChange);

	waitKey(0);

}

static void process()
{
	Mat element = getStructuringElement(MORPH_RECT, Size(2 * g_nStructElement + 1, 2 * g_nStructElement + 1), Point(g_nStructElement, g_nStructElement));

	if (g_nTrackbarNumer == 0)
	{
		erode(g_srcImage, g_dstImage, element);
	}
	else
	{
		dilate(g_srcImage, g_dstImage, element);

	}
	imshow("效果图", g_dstImage);
}

static void on_TrackbarNumChange(int, void *)
{
	process();
}

static void on_ElementSizeChange(int, void *)
{
	process();
}
*/