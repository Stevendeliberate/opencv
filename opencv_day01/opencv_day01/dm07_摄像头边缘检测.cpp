#include<opencv2\opencv.hpp>
using namespace cv;

int main07()
{
	Mat frame;//定义一个Mat变量，用于存储每一帧的图像
	Mat edge;
	//读入视频
	VideoCapture capture(0);

	//循环显示每一帧
	while (1)
	{
		capture >> frame;//读取当前帧

		//将原图像转化为灰度图像
		cvtColor(frame, edge, CV_BGR2GRAY);

		//使用3*3内核来降噪
		blur(edge, edge, Size(7,7));

		//进行canny边缘检测并显示
		Canny(edge, edge, 0, 30, 3);
		imshow("被Canny检测后的视频", edge);
		if (waitKey(30) >= 0)
		{
			break;
		}
	}
	return 0;
}