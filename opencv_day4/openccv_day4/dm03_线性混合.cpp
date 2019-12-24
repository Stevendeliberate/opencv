#include<opencv2\opencv.hpp>

using namespace cv;
using namespace std;

bool LinearBlending()
{
	double alphaValue = 0.5;
	double betaValue;
	Mat srcImage1, srcImage2, dstImage;

	srcImage1 = imread("mogu.jpg");
	srcImage2 = imread("rain.jpg");

	if (!srcImage1.data)
	{
		cout << "��ȡsrcImage1ͼƬ����" << endl;
	}
	if (!srcImage2.data)
	{
		cout << "��ȡsrcImage2ͼƬ����" << endl;
	}

	betaValue = (1.0 - alphaValue);
	addWeighted(srcImage1, alphaValue, srcImage2, betaValue, 0.0, dstImage);

	imshow("Ч��ͼ", dstImage);
	waitKey(0);
	return true;
}

void main31()
{
	LinearBlending();
}