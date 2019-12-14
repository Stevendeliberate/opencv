#include<opencv2\opencv.hpp>
using namespace cv;

int main05()
{
	//读入视频
	VideoCapture capture("C:/Users/steven_cha/Pictures/1.avi");

	//循环显示每一帧
	while(1)
	{
		Mat frame;//定义一个Mat变量，用于存储每一帧的图像
		capture >> frame;//读取当前帧
		if (frame.empty())
		{
			break;
		}
		imshow("读取视频", frame);
		waitKey(30);

	}
	return 0;
}