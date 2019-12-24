#include<opencv2\core\core.hpp>
#include<opencv2\highgui\highgui.hpp>
#include<imgproc\imgproc.hpp>


#define WINDOW_WIDTH 600
#define WINDOW_NAME1 "image 1"
#define WINDOW_NAME2 "image 2"
using namespace cv;

void DrawEllipse(Mat img, double angle)//画椭圆
{
	int thickness = 2;//定义线宽
	int lineType = 8;//定义线性

	ellipse(img,
		Point(WINDOW_WIDTH / 2, WINDOW_WIDTH / 2),//椭圆中心点
		Size(WINDOW_WIDTH / 4, WINDOW_WIDTH / 16),//大小位于矩形(WINDOW_WIDTH / 4, WINDOW_WIDTH / 16)内
		angle,//椭圆的旋转角度为angle
		0,360,//扩展的弧度从0到360度
		Scalar(255, 0, 0),//改变椭圆颜色，代表蓝色
		thickness,//线宽
		lineType);//线型（8联通线性）
}

void DrawFilledCricle(Mat img, Point center)
{
	int thickness = 10;//定义线宽
	int lineType = 8;//定义线型

	circle(img,
		center,//圆心
		WINDOW_WIDTH/32,//半径
		Scalar(0,0,255),//颜色BGR的红色
		thickness,lineType);
}

void DrawPolygon(Mat img)//绘制多边形
{
	int lineType = 8;

	//创建一些点
	Point rookPoints[1][20];
	rookPoints[0][0] = Point(WINDOW_WIDTH / 4, 7 * WINDOW_WIDTH / 8);
	rookPoints[0][1] = Point(3 * WINDOW_WIDTH / 4, 7 * WINDOW_WIDTH / 8);
	rookPoints[0][2] = Point(3 * WINDOW_WIDTH / 4, 13 * WINDOW_WIDTH / 16);
	rookPoints[0][3] = Point(11 * WINDOW_WIDTH / 16, 13 * WINDOW_WIDTH / 16);
	rookPoints[0][4] = Point(19 * WINDOW_WIDTH / 32, 3 * WINDOW_WIDTH / 8);
	rookPoints[0][5] = Point(3 * WINDOW_WIDTH / 4, 3 * WINDOW_WIDTH / 8);
	rookPoints[0][6] = Point(3 * WINDOW_WIDTH / 4, WINDOW_WIDTH / 8);
	rookPoints[0][7] = Point(26 * WINDOW_WIDTH / 40, WINDOW_WIDTH / 8);
	rookPoints[0][8] = Point(26 * WINDOW_WIDTH / 40, WINDOW_WIDTH / 4);
	rookPoints[0][9] = Point(22 * WINDOW_WIDTH / 40, WINDOW_WIDTH / 4);
	rookPoints[0][10] = Point(22 * WINDOW_WIDTH / 40, WINDOW_WIDTH / 8);
	rookPoints[0][11] = Point(18 * WINDOW_WIDTH / 40, WINDOW_WIDTH / 8);
	rookPoints[0][12] = Point(18 * WINDOW_WIDTH / 40, WINDOW_WIDTH / 4);
	rookPoints[0][13] = Point(14 * WINDOW_WIDTH / 40, WINDOW_WIDTH / 4);
	rookPoints[0][14] = Point(14 * WINDOW_WIDTH / 40, WINDOW_WIDTH / 8);
	rookPoints[0][15] = Point(WINDOW_WIDTH / 4, WINDOW_WIDTH / 8);
	rookPoints[0][16] = Point(WINDOW_WIDTH / 4, 3 * WINDOW_WIDTH / 8);
	rookPoints[0][17] = Point(13 * WINDOW_WIDTH / 32, 3 * WINDOW_WIDTH / 8);
	rookPoints[0][18] = Point(5 * WINDOW_WIDTH / 16, 13 * WINDOW_WIDTH / 16);
	rookPoints[0][19] = Point(WINDOW_WIDTH / 4, 13 * WINDOW_WIDTH / 16);

	const Point* ppt[1] = { rookPoints[0] };//定义多边形的顶点集
	int npt[] = { 20 };//定义多边形顶点数目为20个

	fillPoly(img,
		ppt,
		npt,
		1,//要绘制的多边形数量仅为1
		Scalar(255, 255, 255),//白色
		lineType);
}

void DrawLine(Mat img, Point start, Point end)//绘制线
{
	int thickness = 2;
	int lineType = 8;
	line(img,
		start,
		end,
		thickness,
		lineType
		);
}

int main51()
{
	//创建空白图像
	Mat atomImage = Mat::zeros(WINDOW_WIDTH, WINDOW_WIDTH, CV_8UC3);
	Mat rookImage = Mat::zeros(WINDOW_WIDTH, WINDOW_WIDTH, CV_8UC3);

	//先绘制椭圆
	DrawEllipse(atomImage, 90);
	DrawEllipse(atomImage, 0);
	DrawEllipse(atomImage, 45);
	DrawEllipse(atomImage, -45);

	//绘制中心圆
	DrawFilledCricle(atomImage,Point(WINDOW_WIDTH/2,WINDOW_WIDTH/2));

	//绘制多边形
	DrawPolygon(rookImage);

	//绘制矩形
	rectangle(rookImage,
		Point(0, 7 * WINDOW_WIDTH/8),//矩阵左上角的点
		Point(WINDOW_WIDTH, WINDOW_WIDTH),//矩阵右下角的点
		Scalar(0, 255, 255),//颜色
		-1,
		8);
	
	//绘制一些线段
	DrawLine(rookImage, Point(0, 15 * WINDOW_WIDTH / 16), Point(WINDOW_WIDTH, 15 * WINDOW_WIDTH / 16));
	DrawLine(rookImage, Point(WINDOW_WIDTH / 4, 7 * WINDOW_WIDTH / 8), Point(WINDOW_WIDTH / 4, WINDOW_WIDTH));
	DrawLine(rookImage, Point(WINDOW_WIDTH / 2, 7 * WINDOW_WIDTH / 8), Point(WINDOW_WIDTH / 2, WINDOW_WIDTH));
	DrawLine(rookImage, Point(3 * WINDOW_WIDTH / 4, 7 * WINDOW_WIDTH / 8), Point(3 * WINDOW_WIDTH / 4, WINDOW_WIDTH));

	//显示图像
	imshow(WINDOW_NAME1, atomImage);
	moveWindow(WINDOW_NAME1, 0, 200);
	imshow(WINDOW_NAME2, rookImage);
	moveWindow(WINDOW_NAME2, WINDOW_WIDTH, 300);

	waitKey(0);
	return 0;
}
