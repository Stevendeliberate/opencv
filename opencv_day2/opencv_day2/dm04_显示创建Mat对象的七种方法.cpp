#include<opencv2\opencv.hpp>

using namespace cv;
using namespace std;

int main41()//����һ
{
	Mat M(2, 2, CV_8UC3, Scalar(0, 0, 255));//����һ���������е�8λ3ͨ���ĵľ���Ԫ��Ϊscalar��
	cout << "M = " << endl << " " << M << endl << endl;
	return 0;
}

int main42()
{
	Mat m;
	m.create(4, 4, CV_8UC(2)); //����Mat���е�Creat�����������г�ʼ��
	cout << "m = " << endl << " " << m << endl << endl;//�˷��������ֵ
	return 0;
}

int main43()
{
	Mat E = Mat::eye(4, 4, CV_64F);//��λ����
	cout << "E =" << endl << " " << E << endl << endl;

	Mat O = Mat::ones(2, 2, CV_32F);//�۾��󣨾���Ԫ��ȫ��1��
	cout << "O =" << endl << " " << O << endl << endl;

	Mat Z = Mat::zeros(3, 3, CV_8UC1);//�����
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
	Mat RowClone = C.row(0).clone();//���Ծ���C�ĵ�0������ΪMat�ࣨ����Ϊ�µ���Ϣͷ����
	cout << "RowClone" << endl << " " << RowClone << endl << endl;
	return 0;
}