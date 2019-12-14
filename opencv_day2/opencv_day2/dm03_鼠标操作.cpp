#include<opencv2\opencv.hpp>
using namespace cv;

#define WINDOW_NAME "程序窗口"

//全局函数声明
void on_MouseHandle(int event, int x, int y, int flags, void* param);
void DrawRectangle(cv::Mat& img, cv::Rect box);
void ShowHelpText();

//全局变量声明
Rect g_rectangle;
bool g_bDrawingBox = false;//是否进行绘制
RNG g_rng(12345);

int main31(int argc,char** argv)
{
	system("color 5F");
	ShowHelpText();

	//1.准备参数
	g_rectangle = Rect(-1, -1, 0, 0);
	Mat srcImage(600, 800, CV_8UC3), tempImage;
	srcImage.copyTo(tempImage);
	g_rectangle = Rect(-1, -1, 0, 0);
	srcImage = Scalar::all(0);

	//2.设置鼠标操作回调函数
	namedWindow(WINDOW_NAME);
	setMouseCallback(WINDOW_NAME, on_MouseHandle, (void *)&srcImage);

	//3.程序主循环，当进行绘制的标识符为真时，进行绘制
	while (1)
	{
		srcImage.copyTo(tempImage);
		if (g_bDrawingBox)
		{
			DrawRectangle(tempImage, g_rectangle);
			imshow(WINDOW_NAME, tempImage);
		}
		if (waitKey(10) == 27)
		{
			break;
		}
	}
	return 0;
}

void on_MouseHandle(int event, int x, int y, int flags, void *param)
{
	Mat& image = *(cv::Mat*) param;
	switch (event)
	{
		//鼠标移动消息
	case EVENT_MOUSEMOVE:
	{
							if (g_bDrawingBox)
							{
								g_rectangle.width = x - g_rectangle.x;
								g_rectangle.height = y - g_rectangle.y;
							}
	}
		break;

		//左键按下消息
	case EVENT_LBUTTONDOWN:
		{
							  g_bDrawingBox = true;
							  g_rectangle = Rect(x, y, 0, 0);
		}
		break;

		//左键抬起消息
	case EVENT_LBUTTONUP:
	{
							g_bDrawingBox = false;
							//对宽和高小于0的处理
							if (g_rectangle.width < 0)
							{
								g_rectangle.x += g_rectangle.width;
								g_rectangle.width *= -1;
							}

							if (g_rectangle.height < 0)
							{
								g_rectangle.y += g_rectangle.height;
								g_rectangle.height *= -1;
							}

							//调用函数进行绘制
							DrawRectangle(image, g_rectangle);
	}
		break;
	}

}

void DrawRectangle(cv::Mat& img, cv::Rect box)
{
	rectangle(img, box.tl(), box.br(), Scalar(g_rng.uniform(0, 255), g_rng.uniform(0, 255), g_rng.uniform(0, 255)));
}

void ShowHelpText()
{
	//输出欢迎信息和OpenCV版本
	printf("\n\n\t\t\t   当前使用的OpenCV版本为：" CV_VERSION);
	printf("\n\n  ----------------------------------------------------------------------------\n");
	//输出一些帮助信息
	printf("\n\n\n\t欢迎来到【鼠标交互演示】示例程序\n");
	printf("\n\n\t请在窗口中点击鼠标左键并拖动以绘制矩形\n");
	printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t by steven cha");
}