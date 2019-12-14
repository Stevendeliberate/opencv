#include<opencv2\opencv.hpp>

using namespace cv;
using namespace std;

int main51()
{
	system("color 5F");

	Mat r = Mat(10, 3, CV_8UC3);
	randu(r, Scalar::all(0), Scalar::all(255));//randu()函数，随机值填充矩阵 矩阵元素为Scalar类型 拥有上下限
	
	cout << "opencv风格：" << endl;
	cout << "r = " << endl << " " << r << endl << endl;

	cout << "python风格：" << endl;
	cout << format(r, "python") << endl;

	cout << "CSV分隔：" << endl;
	cout << format(r, "csv") << endl;

	cout << "NUMPY风格：" << endl;
	cout << format(r, "numpy") << endl;

	cout << "C语言风格：" << endl;
	cout << format(r, "C") << endl;

	return 0;
}