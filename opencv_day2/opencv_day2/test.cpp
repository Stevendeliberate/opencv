#include<opencv2\opencv.hpp>

using namespace cv;

void main11()
{
	Mat image1;
	image1 = imread("1.jpg");
	namedWindow("123");
	imshow("123", image1);
	Mat rusult;
	int i;
	for (i = -3; i < 3; i++)
	{
		char name[10];
		sprintf(name, "第%d个图", i);
		flip(image1, rusult, i);
		imshow(&(name[i]), rusult);
	}

	waitKey(0);
}

void main12()
{
	Mat A, C;
	A = imread("1.jpg", CV_LOAD_IMAGE_COLOR);
	Mat B(A);
	C = A;
	Mat D(A, Rect(100, 100, 50, 50));//Rect(x,y,width,height)在矩阵A中，以点（x，y）为矩阵左上点，圈出width*heigh的矩阵
	Mat E = A(Range::all(), Range(1, 3));
	imshow("A", A);
	imshow("B", B);
	imshow("C", C);//A,B,C所指的是同一个矩阵，改变其一，会改变所有。
	imshow("D", D);
	imshow("E", E);
	Mat F = A.clone();
	Mat G;
	A.copyTo(G);
	imshow("F", F);
	imshow("G", G);
	waitKey(0);
}