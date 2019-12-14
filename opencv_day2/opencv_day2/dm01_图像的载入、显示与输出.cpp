//头文件
#include<opencv2\core\core.hpp>
#include<opencv2\highgui\highgui.hpp>

//命名空间 cv
using namespace cv;

int main11()
{
	//1.图像的载入和显示
	
	Mat girl = imread("girl.jpg");//载入图像到Mat类型下的girl
	namedWindow("[1]动漫图");//创建【1】动漫图的窗口
	imshow("[1]动漫图",girl);//显示名为【1】动漫图的窗口

	//------------------------------------------------------------------------------------------//
	//2.初级图像混合
	
	//载入两个图像
	Mat image = imread("dota.jpg",199);
	Mat logo = imread("dota_logo.jpg");

	//载入后显示
	namedWindow("[2]原画图");
	imshow("[2]原画图", image);

	namedWindow("[3]logo图");
	imshow("[3]logo图", logo);
	
	//定义一个Mat类型，用于存放，图像的ROI
	Mat imageROI;

	//方法一
	imageROI = image(Rect(800, 350, logo.cols, logo.rows));

	//方法二
	//imageROI = image(Range(350, 350 + logo.rows), Range(800, 800 + logo.cols));

	//将logo加到原图上
	addWeighted(imageROI, 0.5, logo, 0.3, 0., imageROI);

	//显示结果
	namedWindow("[4]原画+logo图");
	imshow("[4]原画+logo图", image);
	//----------------------------------------------------------------------------------------//

	//3.图像的输出
	imwrite("原图+logo图.jpg", image);
	waitKey(0);

	return 0;
}