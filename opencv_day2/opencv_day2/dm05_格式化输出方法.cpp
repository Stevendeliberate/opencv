#include<opencv2\opencv.hpp>

using namespace cv;
using namespace std;

int main51()
{
	system("color 5F");

	Mat r = Mat(10, 3, CV_8UC3);
	randu(r, Scalar::all(0), Scalar::all(255));//randu()���������ֵ������ ����Ԫ��ΪScalar���� ӵ��������
	
	cout << "opencv���" << endl;
	cout << "r = " << endl << " " << r << endl << endl;

	cout << "python���" << endl;
	cout << format(r, "python") << endl;

	cout << "CSV�ָ���" << endl;
	cout << format(r, "csv") << endl;

	cout << "NUMPY���" << endl;
	cout << format(r, "numpy") << endl;

	cout << "C���Է��" << endl;
	cout << format(r, "C") << endl;

	return 0;
}