#include<opencv2\opencv.hpp>
#include<time.h>

using namespace cv;
using namespace std;

int main21()
{
	system("color 9F");

	FileStorage fs2("test.txt", FileStorage::READ);

	//��һ�ַ���
	int frameCount = (int)fs2["frameCount"];

	//�ڶ��ַ���
	string date;
	fs2["calibrationData"] >> date;

	Mat cameraMatrix2, distCoeffs2;
	fs2["cameraMatrix"] >> cameraMatrix2;
	fs2["distCoeffs"] >> distCoeffs2;

	cout << "frameCount:" << frameCount << endl
		<< "calibrationData:" << date << endl
		<< "cameraMatrix:" << cameraMatrix2 << endl
		<< "distCoeffs:" << distCoeffs2 << endl;

	FileNode features = fs2["features"];
	FileNodeIterator it = features.begin(), it_end = features.end();
	int idx = 0;
	vector<uchar> lbpval;

	//ʹ��FileNodeIterator��������
	for (; it != it_end; ++it, idx++)
	{
		cout << "feature #" << idx << ": ";
		cout << "x=" << (int)(*it)["x"] << ", y=" << (int)(*it)["y"] << ", lbp: (";
		// ����Ҳ����ʹ��ʹ��filenode > > std::vector�����������׵Ķ���ֵ����
		(*it)["lbp"] >> lbpval;
		for (int i = 0; i < (int)lbpval.size(); i++)
			cout << " " << (int)lbpval[i];
		cout << ")" << endl;
	}
	fs2.release();

	//������������һЩ��������
	printf("\n�ļ���ȡ��ϣ��������������������~");
	getchar();

	return 0;
}