#include <opencv2\opencv.hpp>
#include<opencv2\highgui\highgui.hpp>

using namespace std;
using namespace cv;

void main21()//Rect�Ĳ���
{
	Point point;
	point.x = 10;
	point.y = 610;
	Rect a(3, 3, 5, 5);
	Rect b(4, 4, 2, 2);

	cout << "area:" << a.area() << endl;
	cout << a.contains(point) << endl;//���ص�boolֵ 1�ھ����� 0���ھ�����
	cout << a.tl() << endl;
	cout << a.br() << endl;

}

void main22()//����Ľ����Ͳ���
{
	Rect a(3, 3, 5, 5);
	Rect b(4, 4, 6, 6);


	Rect rect1 = a | b;//����
	Rect rect2 = a & b;//����
	cout << "rect1:" << rect1 << endl;
	cout << "rect2:" << rect2 << endl;
}

void main23()//���ε�ƽ�ƺ�����
{
	Rect a(3, 3, 5, 5);
	Rect b(4, 4, 6, 6);
	Point point(3, 3);

	Rect rectshift = a - point;//ƽ�����
	Rect rectScale = b + Size(2, 2);//ֻ��+

	cout << rectshift << endl;
	cout << rectScale << endl;
}