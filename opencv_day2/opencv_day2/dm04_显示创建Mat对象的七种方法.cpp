#include<opencv2\opencv.hpp>

using namespace cv;
using namespace std;

int main41()//方法一
{
	Mat M(2, 2, CV_8UC3, Scalar(0, 0, 255));//构造一个两行两列的8位3通道的的矩阵，元素为scalar型
	cout << "M = " << endl << " " << M << endl << endl;
	return 0;
}

int main42()
{
	Mat m;
	m.create(4, 4, CV_8UC(2)); //利用Mat类中的Creat（）函数进行初始化
	cout << "m = " << endl << " " << m << endl << endl;//此法不能设初值
	return 0;
}

int main43()
{
	Mat E = Mat::eye(4, 4, CV_64F);//单位矩阵
	cout << "E =" << endl << " " << E << endl << endl;

	Mat O = Mat::ones(2, 2, CV_32F);//幺矩阵（矩阵元素全是1）
	cout << "O =" << endl << " " << O << endl << endl;

	Mat Z = Mat::zeros(3, 3, CV_8UC1);//零矩阵
	cout << "Z =" << endl << " " << Z << endl << endl;
	
	return 0;
}

int main44()
{
	Mat C = (Mat_<double>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
	cout << "C = " << endl << " " << C << endl;
	return 0;
}

int main45()
{
	Mat C = (Mat_<double>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
	Mat RowClone = C.row(0).clone();//即对矩阵C的第0行设置为Mat类（设置为新的信息头）。
	cout << "RowClone" << endl << " " << RowClone << endl << endl;
	return 0;
}