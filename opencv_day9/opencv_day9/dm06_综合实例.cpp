#include<opencv2\imgproc\imgproc.hpp>
#include<opencv2\highgui\highgui.hpp>
#include<iostream>
using namespace std;
using namespace cv;

//全局变量申明
//原图 目标图 灰度图
Mat src_Image, dst_Image, gray_Image;

//Canny边缘检测的相关变量
Mat g_cannyEdge;
int g_cannyLowThreshold = 1;

//sobel边缘检测相关变量
Mat g_sobelx, g_sobely;
Mat g_sobelabsx, g_sobelabsy;
int g_soblekernlsize = 1;

//scharr滤波器相关变量
Mat g_scharrx, g_scharry;
Mat g_scharrabsx, g_scharrabsy;


//全局函数申明
static void on_canny(int, void *);
static void on_sobel(int, void *);
void scharr();

void main61()
{
	system("color 2F");

	src_Image = imread("1.jpg");
	if (!src_Image.data)
	{
		cout << "载入图片错误，请检查后重新载入" << endl;
	}

	//显示原始图
	imshow("【原始图】", src_Image);

	//创建与src_Image尺寸和类型相同的矩阵dst
	dst_Image.create(src_Image.size(), src_Image.type());

	//将原图像转化为灰度图像
	cvtColor(src_Image, gray_Image, COLOR_RGB2GRAY);

	//创建窗口
	namedWindow("【效果图】Canny边缘检测", WINDOW_AUTOSIZE);
	namedWindow("【效果图】Sobel边缘检测", WINDOW_AUTOSIZE);

	//创建trackar
	createTrackbar("参数值", "【效果图】Canny边缘检测", &g_cannyLowThreshold, 120, on_canny);
	createTrackbar("参数值", "【效果图】Sobel边缘检测", &g_soblekernlsize, 3, on_sobel);

	//调用回调函数
	on_canny(0,0);
	on_sobel(0,0);

	//调用封装了scharr()边缘检测算法的scharr（）函数
	scharr();

	while (char(waitKey(1) != 'q'))
	{
	}

	return ;
}

void on_canny(int, void *)
{
	//先使用3*3内核去噪
	blur(gray_Image, g_cannyEdge, Size(3, 3));

	Canny(g_cannyEdge, g_cannyEdge, g_cannyLowThreshold, g_cannyLowThreshold * 3, 3);

	dst_Image = Scalar::all(0);
	
	src_Image.copyTo(dst_Image, g_cannyEdge);
	imshow("【效果图】Canny边缘检测", dst_Image);
}

void on_sobel(int, void *)
{
	//x方向的梯度
	Sobel(src_Image, g_sobelx, CV_16S, 1, 0, (2 * g_soblekernlsize + 1), 1, 1, BORDER_DEFAULT);
	convertScaleAbs(g_sobelx, g_sobelabsx);//使用线性变换转换输入数组元素成8位无符号整型

	//y方向的梯度
	Sobel(src_Image, g_sobely, CV_16S, 0, 1, (2 * g_soblekernlsize + 1), 1, 1, BORDER_DEFAULT);
	convertScaleAbs(g_sobely, g_sobelabsy);//使用线性变换转换输入数组元素成8位无符号整型

	//合并梯度（近似）
	addWeighted(g_sobelabsx, 0.5, g_sobelabsy, 0.5, 0, dst_Image);
	imshow("【效果图】Sobel边缘检测", dst_Image);
}

void scharr()
{
	Scharr(src_Image, g_scharrx, CV_16S, 1, 0, 1, 0, BORDER_DEFAULT);
	convertScaleAbs(g_scharrx, g_scharrabsx);

	Scharr(src_Image,g_scharry, CV_16S, 0, 1, 1, 0, BORDER_DEFAULT);
	convertScaleAbs(g_scharry, g_scharrabsy);

	addWeighted(g_scharrabsx, 0.5, g_scharrabsy, 0.5, 0, dst_Image);
	imshow("【效果图】Scharr边缘检测", dst_Image);
}