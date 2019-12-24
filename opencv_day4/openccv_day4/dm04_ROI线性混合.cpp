#include<opencv2\opencv.hpp>
using namespace cv;
using namespace std;


bool ROI_LinearBlending()
{
	Mat srcImage1 = imread("1.jpg",1);
	Mat srcImage2 = imread("2.jpg");

	if (!srcImage1.data)
	{
		cout << "��ȡsrcImage1ͼƬ����" << endl;
		return false;
	}
	if (!srcImage2.data)
	{
		cout << "��ȡsrcImage2ͼƬ����" << endl;
		return false;
	}

	Mat ImageROI;
	//����һ��rect������
	//ImageROI = srcImage1(Rect(200, 250, srcImage2.cols, srcImage2.rows));
	//��������range������
	ImageROI = srcImage1(Range(250, 250 + srcImage2.rows), Range(200, 200 + srcImage2.cols));
	addWeighted(ImageROI, 0.5, srcImage2, 0.5, 0, ImageROI);
	imshow("Ч��ͼ", srcImage1);
	waitKey(0);

	return false;
}

void main41()
{
	ROI_LinearBlending();
}