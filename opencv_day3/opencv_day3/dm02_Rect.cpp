#include <opencv2\opencv.hpp>
#include<opencv2\highgui\highgui.hpp>

using namespace std;
using namespace cv;

void main21()//Rect的操作
{
	Point point;
	point.x = 10;
	point.y = 610;
	Rect a(3, 3, 5, 5);
	Rect b(4, 4, 2, 2);

	cout << "area:" << a.area() << endl;
	cout << a.contains(point) << endl;//返回的bool值 1在矩阵内 0不在矩阵内
	cout << a.tl() << endl;
	cout << a.br() << endl;

}

void main22()//矩阵的交集和并集
{
	Rect a(3, 3, 5, 5);
	Rect b(4, 4, 6, 6);


	Rect rect1 = a | b;//并集
	Rect rect2 = a & b;//交集
	cout << "rect1:" << rect1 << endl;
	cout << "rect2:" << rect2 << endl;
}

void main23()//矩形的平移和缩放
{
	Rect a(3, 3, 5, 5);
	Rect b(4, 4, 6, 6);
	Point point(3, 3);

	Rect rectshift = a - point;//平移起点
	Rect rectScale = b + Size(2, 2);//只能+

	cout << rectshift << endl;
	cout << rectScale << endl;
}