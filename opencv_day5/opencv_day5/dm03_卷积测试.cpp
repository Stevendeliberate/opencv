#include<opencv2\core\core.hpp>
#include<iostream>

using namespace cv;
using namespace std;

//�����㷨

//��һ�� ����.ptr �� []
double rectReduce1(Mat &mat1,Mat &mat2)
{
	int nl = mat1.rows;
	int nc = mat2.cols;
	double sum = 0;
	for (int i = 0; i < nl; i++)
	{
		//��ȡÿһ�е��׵�ַ
		double* data1 = mat1.ptr<double>(i);
		double* data2 = mat2.ptr<double>(i);
		for (int j = 0; j < nc; j++)
		{
			//����ÿһ�е��׵�ַ������������ÿ��Ԫ��
			sum = sum + data1[j] * data2[j];
		}
	}
	return sum;
}

//�ڶ��ַ��� ����.ptr �� *++
double rectReduce2(Mat &mat1, Mat &mat2)
{
	int nl = mat1.rows;
	int nc = mat2.cols;
	double sum = 0;
	
	for (int i = 0; i < nl; i++)
	{
		//������ͬ��
		double* data1 = mat1.ptr<double>(i);
		double* data2 = mat2.ptr<double>(i);
		for (int j = 0; j < nc; j++)
		{
			//����û���������ʽ����ʹ�õĲ�����ַ����ʽ��
			sum = sum + *data1*(*data2);
			data1++;
			data2++;
		}
	}

	return sum;
}

//������ ���ö�̬��ַ�������at
double rectReduce3(Mat &mat1, Mat &mat2)
{
	int nl = mat1.rows;
	int nc = mat2.cols;
	double sum = 0;


	for (int i = 0; i < nl; i++)
	{
		for (int j = 0; j < nc; j++)
		{
			//��̬��ַ��������Ϊ������double���͵ĵ�ͨ������������ Mat.at<double>(i,j)
			//������ʽuchar��ͨ������ ����ʹ��Mat.at<Vec3b>(i,j)[x].   ��i��j��Ԫ�صĵڡ�x��ͨ��Ԫ��
			sum = sum + mat1.at<double>(i, j)*mat2.at<double>(i, j);
		}
	}

	return sum;
}

//������ ������iterate�Լ�λ����
double rectReduce4(Mat &mat1, Mat &mat2)
{
	double sum = 0;
	//��ȡ������
	Mat_<double>::iterator start1 = mat1.begin<double>();//��������ʼ��־
	Mat_<double>::iterator end1 = mat1.end<double>();//������������־
	Mat_<double>::iterator start2 = mat2.begin<double>();
	Mat_<double>::iterator end2 = mat2.end<double>();

	for (; start1 != end1; ++start1,++start2)//����������ͬʱ����
	{
		sum = sum + *start2*(*start1);
	}

	return sum;
}



void main()
{
	Mat f = (Mat_<double>(3, 3) << 49, 53, 68, 50, 50, 58, 50, 50, 52);
	Mat g = (Mat_<double>(3, 3) << 0.1, 0.1, 0.1, 0.1, 0.2, 0.1, 0.1, 0.1, 0.1);
	
	cout << "��һ�ַ�����"<<rectReduce1(f, g) << endl;
	cout << "�ڶ��ַ�����" << rectReduce2(f, g) << endl;
	cout << "�����ַ�����" << rectReduce3(f, g) << endl;
	cout << "�����ַ�����" << rectReduce4(f, g) << endl;
}

//�Բ���
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