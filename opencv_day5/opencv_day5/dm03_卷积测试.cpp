#include<opencv2\core\core.hpp>
#include<iostream>

using namespace cv;
using namespace std;

//四种算法

//第一种 利用.ptr 和 []
double rectReduce1(Mat &mat1,Mat &mat2)
{
	int nl = mat1.rows;
	int nc = mat2.cols;
	double sum = 0;
	for (int i = 0; i < nl; i++)
	{
		//获取每一行的首地址
		double* data1 = mat1.ptr<double>(i);
		double* data2 = mat2.ptr<double>(i);
		for (int j = 0; j < nc; j++)
		{
			//利用每一行的首地址，操作矩阵中每个元素
			sum = sum + data1[j] * data2[j];
		}
	}
	return sum;
}

//第二种方法 利用.ptr 和 *++
double rectReduce2(Mat &mat1, Mat &mat2)
{
	int nl = mat1.rows;
	int nc = mat2.cols;
	double sum = 0;
	
	for (int i = 0; i < nl; i++)
	{
		//与上面同理
		double* data1 = mat1.ptr<double>(i);
		double* data2 = mat2.ptr<double>(i);
		for (int j = 0; j < nc; j++)
		{
			//这里没用数组的形式，而使用的操作地址的形式。
			sum = sum + *data1*(*data2);
			data1++;
			data2++;
		}
	}

	return sum;
}

//第三种 利用动态地址计算配合at
double rectReduce3(Mat &mat1, Mat &mat2)
{
	int nl = mat1.rows;
	int nc = mat2.cols;
	double sum = 0;


	for (int i = 0; i < nl; i++)
	{
		for (int j = 0; j < nc; j++)
		{
			//动态地址操作，因为矩阵是double类型的单通道矩阵，所以用 Mat.at<double>(i,j)
			//若矩阵式uchar三通道类型 ，则使用Mat.at<Vec3b>(i,j)[x].   （i，j）元素的第【x】通道元素
			sum = sum + mat1.at<double>(i, j)*mat2.at<double>(i, j);
		}
	}

	return sum;
}

//第四种 迭代器iterate以及位运算
double rectReduce4(Mat &mat1, Mat &mat2)
{
	double sum = 0;
	//获取迭代器
	Mat_<double>::iterator start1 = mat1.begin<double>();//迭代器开始标志
	Mat_<double>::iterator end1 = mat1.end<double>();//迭代器结束标志
	Mat_<double>::iterator start2 = mat2.begin<double>();
	Mat_<double>::iterator end2 = mat2.end<double>();

	for (; start1 != end1; ++start1,++start2)//两个迭代器同时运行
	{
		sum = sum + *start2*(*start1);
	}

	return sum;
}



void main()
{
	Mat f = (Mat_<double>(3, 3) << 49, 53, 68, 50, 50, 58, 50, 50, 52);
	Mat g = (Mat_<double>(3, 3) << 0.1, 0.1, 0.1, 0.1, 0.2, 0.1, 0.1, 0.1, 0.1);
	
	cout << "第一种方法："<<rectReduce1(f, g) << endl;
	cout << "第二种方法：" << rectReduce2(f, g) << endl;
	cout << "第三种方法：" << rectReduce3(f, g) << endl;
	cout << "第四种方法：" << rectReduce4(f, g) << endl;
}

//自测试
int main31()
{
	Mat f = (Mat_<double>(3, 3) << 49, 53, 68, 50, 50, 58, 50, 50, 52);
	Mat g = (Mat_<double>(3, 3) << 0.1, 0.1, 0.1, 0.1, 0.2, 0.1, 0.1, 0.1, 0.1);

	double sum = 0;

	for (int i = 0; i < 3; i++)
	{
		double *data1 = g.ptr<double>(i);
		double *data2 = f.ptr<double>(i);
		for (int j = 0; j < 3; j++)
		{
			sum = sum + data1[j] * data2[j];
		}
	}

	std::cout << sum << std::endl;
	return 0;
}