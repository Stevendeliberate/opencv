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
		sprintf(name, "��%d��ͼ", i);
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
	Mat D(A, Rect(100, 100, 50, 50));//Rect(x,y,width,height)�ھ���A�У��Ե㣨x��y��Ϊ�������ϵ㣬Ȧ��width*heigh�ľ���
	Mat E = A(Range::all(), Range(1, 3));
	imshow("A", A);
	imshow("B", B);
	imshow("C", C);//A,B,C��ָ����ͬһ�����󣬸ı���һ����ı����С�
	imshow("D", D);
	imshow("E", E);
	Mat F = A.clone();
	Mat G;
	A.copyTo(G);
	imshow("F", F);
	imshow("G", G);
	waitKey(0);
}