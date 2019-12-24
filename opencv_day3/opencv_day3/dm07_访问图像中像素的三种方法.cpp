#include<opencv2\opencv.hpp>
#include<opencv2\highgui\highgui.hpp>
#include<iostream>

using namespace std;
using namespace cv;

//指针访问：C操作符[ ]方法版的颜色空间缩减函数
void colorReduce1(Mat& inputImage,Mat& outputImage,int div)
{
	//参数准备
	outputImage = inputImage.clone();//复制实参到临时变量
	int rowNumber = outputImage.rows;//行数
	int colNumber = outputImage.cols*outputImage.channels();//列数*通道数 = 每一行元素的个数

	//双重循环，遍历所有的像素值
	for (int i = 0; i < rowNumber; i++)//行循环
	{
		uchar* data = outputImage.ptr<uchar>(i);//获取第i行的首地址
		for (int j = 0; j < colNumber; j++)//列循环
		{
			data[j] = data[j] / div*div + div / 2;//开始处理每个像素
		}
	}
}

//用迭代器操作像素
void colorReduce2(Mat &inputImage, Mat &outputImage, int div)
{
	//参数准备
	outputImage = inputImage.clone();

	//获取迭代器
	Mat_<Vec3b>::iterator it = outputImage.begin<Vec3b>();//初始位置的迭代器
	Mat_<Vec3b>::iterator itend = outputImage.end<Vec3b>();//终止位置的迭代器

	//存取彩色图像像素
	for (; it != itend; ++it)
	{
		//开始处理每个像素
		(*it)[0] = (*it)[0] / div*div + div / 2;
		(*it)[1] = (*it)[1] / div*div + div / 2;
		(*it)[2] = (*it)[2] / div*div + div / 2;
	}
}

//动态地址计算
void colorReduce3(Mat &inputImage, Mat &outputImage, int div)
{
	//参数准备
	outputImage = inputImage.clone();
	int rowNumber = outputImage.rows;
	int colNumber = outputImage.cols;

	//存取彩色图像像素
	for (int i = 0; i < rowNumber; i++)
	{
		for (int j = 0; j < colNumber; j++)
		{
			//开始处理每个像素
			outputImage.at<Vec3b>(i, j)[0] =
				outputImage.at<Vec3b>(i, j)[0] / div*div + div / 2;//蓝色通道B
			outputImage.at<Vec3b>(i, j)[1] =
				outputImage.at<Vec3b>(i, j)[1] / div*div + div / 2;//绿色通道G
			outputImage.at<Vec3b>(i, j)[2] =
				outputImage.at<Vec3b>(i, j)[2] / div*div + div / 2;//红色通道R
		}
	}
}


void main71()
{
	//创建图像并显示
	Mat srcImage = imread("1.jpg");
	imshow("原始图像：", srcImage);

	//按原始图的参数规格来创建效果图
	Mat dstImage;
	dstImage.create(srcImage.rows, srcImage.cols, srcImage.type());//效果图大小、类型与原图片相同

	double time = static_cast<double>(getTickCount());//开始计时

	colorReduce1(srcImage, dstImage, 32);//调用颜色空间缩减函数

	time = ((double)getTickCount() - time) / getTickFrequency();//计算时间并输出
	std::cout << "time1:"<<time << std::endl;

	//显示效果图
	imshow("效果图",dstImage);



	waitKey(0);
}

void main72()
{
	//创建图像并显示
	Mat srcImage = imread("1.jpg");
	imshow("原始图像：", srcImage);

	//按原始图的参数规格来创建效果图
	Mat dstImage;
	dstImage.create(srcImage.rows, srcImage.cols, srcImage.type());//效果图大小、类型与原图片相同

	double time = static_cast<double>(getTickCount());//开始计时

	colorReduce2(srcImage, dstImage, 32);//调用颜色空间缩减函数

	time = ((double)getTickCount() - time) / getTickFrequency();//计算时间并输出
	std::cout << "time1:" << time << std::endl;

	//显示效果图
	imshow("效果图", dstImage);

	waitKey(0);
}

void main()
{
	//创建图像并显示
	Mat srcImage = imread("1.jpg");
	imshow("原始图像：", srcImage);

	//按原始图的参数规格来创建效果图
	Mat dstImage;
	dstImage.create(srcImage.rows, srcImage.cols, srcImage.type());//效果图大小、类型与原图片相同

	double time = static_cast<double>(getTickCount());//开始计时

	colorReduce3(srcImage, dstImage, 32);//调用颜色空间缩减函数

	time = ((double)getTickCount() - time) / getTickFrequency();//计算时间并输出
	std::cout << "time1:" << time << std::endl;

	//显示效果图
	imshow("效果图", dstImage);

	waitKey(0);
}