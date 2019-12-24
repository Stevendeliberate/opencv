#include<opencv2\opencv.hpp>

using namespace cv;


//单通道处理
void main61()

{
	Mat J;
	Mat I = imread("1.jpg",CV_LOAD_IMAGE_GRAYSCALE);//灰度图像读取

	uchar lutdata[256];//创建表
	int divideWith = 10;

	for (int i = 0; i < 256; i++)
	{
		lutdata[i] = divideWith*(i / divideWith);//将计算好的值存入表中
	}

	Mat lut(1, 256, CV_8UC1,lutdata);//将表存入Mat容器中

	imshow("I", I);
	moveWindow("I", 0, 0);
	LUT(I, lut, J);//查表
	imshow("J", J);
	moveWindow("J", J.cols, 0);
	waitKey(0);
}

//三通道处理
void main62()
{
	Mat ImageTo;
	Mat ImageFrom = imread("1.jpg", CV_LOAD_IMAGE_ANYCOLOR);

	uchar lutdata[256 * 3];
	int divideWith = 10;

	for (int i = 0; i < 256 * 3; i += 3)
	{
		lutdata[i] = divideWith*(i / divideWith);
		lutdata[i+1] = divideWith*((i+1) / divideWith);
		lutdata[i+2] = divideWith*((i+2) / divideWith);
	}

	Mat lut(1, 256, CV_8UC3, lutdata);

	imshow("ImageFrom", ImageFrom);
	moveWindow("ImageFrom", 0, 0);
	LUT(ImageFrom, lut, ImageTo);//查表
	imshow("ImageTo", ImageTo);
	moveWindow("ImageTo", ImageTo.cols, 0);
	waitKey(0);
	
}

//图像二值化
void main63()
{
	double time = static_cast<double>(getTickCount());//开始计时
	Mat ImageTo;
	Mat ImageFrom = imread("1.jpg", CV_LOAD_IMAGE_GRAYSCALE);

	uchar lutdata[256];

	for (int i = 0; i < 256; i++)//二值化
	{
		if (i < (256) / 2)
		{
			lutdata[i] = 0;
		}
		else
		{
			lutdata[i] = 255;
		}
	}

	Mat lut(1, 256, CV_8U, lutdata);

	imshow("ImageFrom", ImageFrom);
	moveWindow("ImageFrom", 0, 0);
	LUT(ImageFrom, lut, ImageTo);//查表
	imshow("ImageTo", ImageTo);
	moveWindow("ImageTo", ImageTo.cols, 0);
	time = ((double)getTickCount() - time) / getTickFrequency();
	std::cout << time << std::endl;
	waitKey(0);

}