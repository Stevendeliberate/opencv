#include<opencv2\core\core.hpp>
#include<opencv2\highgui\highgui.hpp>
#include<iostream>
#include<opencv2\opencv.hpp>

using namespace cv;
using namespace std;

bool  MultiChannelBlending()
{
	Mat srcImage = imread("1.jpg");
	Mat logoImage = imread("2.jpg",0);
	vector<Mat> channels;

	split(srcImage,channels);


	//彩色图像和灰度图像混合，灰度图像提供的是形状，彩色图像提供色彩
	//通道0是蓝色通道，将其与灰度图像logoImage混合后，logoImage为具有通道0的图像
	//改变logoImage的权值即可改变图形的深浅，从而颜色深浅也得以改变。
	addWeighted((channels.at(0))(Rect(0,250 , logoImage.cols, logoImage.rows)), 1.0,
		logoImage, 0.5, 0, (channels.at(0))(Rect(0, 250, logoImage.cols, logoImage.rows)));

	merge(channels, srcImage);

	imshow("混合蓝色通道图像", srcImage);

	//绿色通道
	//需要重新读取图片。
	srcImage = imread("1.jpg");
	logoImage = imread("2.jpg", 0);

	split(srcImage, channels);//重新分离通道
	
	addWeighted((channels.at(1))(Rect(0, 250, logoImage.cols, logoImage.rows)), 1.0,
		logoImage, 0.5, 0, (channels.at(1))(Rect(0, 250, logoImage.cols, logoImage.rows)));

	merge(channels, srcImage);

	imshow("混合绿色通道图像", srcImage);

	//红色通道
	srcImage = imread("1.jpg");
	logoImage = imread("2.jpg", 0);
	split(srcImage, channels);
	addWeighted((channels.at(2))(Rect(0, 250, logoImage.cols, logoImage.rows)), 1.0,
		logoImage, 0.5, 0, (channels.at(2))(Rect(0, 250, logoImage.cols, logoImage.rows)));

	merge(channels, srcImage);

	imshow("混合红色通道图像", srcImage);

	return true;
}


int main61()
{
	system("color 9F");

	MultiChannelBlending();
	if (MultiChannelBlending())
	{
		cout << "successed" << endl;
	}

	waitKey(0);
	return 0;
}