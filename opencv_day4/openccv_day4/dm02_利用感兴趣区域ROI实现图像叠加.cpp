#include<opencv2\opencv.hpp>
using namespace cv;
using namespace std;

bool ROI_AddImage()
{
	//��ȡͼ��
	Mat srcImage = imread("1.jpg");
	Mat logoImage = imread("2.jpg");
	if (!srcImage.data)
	{
		cout << "��ȡsrcImageͼ�����" << endl;
		return false;
	}
	if (!logoImage.data)
	{
		cout << "��ȡlogoImageͼ�����" << endl;
		return false;
	}

	//����һ��Mat���Ͳ������趨ROI����
	Mat imageROI = srcImage(Rect(200, 250, logoImage.rows, logoImage.cols));

	//������Ĥ�������ǻҶ�ͼ��
	Mat mask = imread("2.jpg", CV_LOAD_IMAGE_GRAYSCALE);

	//����Ĥ���Ƶ�ROI
	logoImage.copyTo(imageROI, mask);//copyTo(outoutArray m,inputArray mask)

	imshow("answer", srcImage);
	waitKey(0);
	return true;
}

void main21()
{
	ROI_AddImage();
}