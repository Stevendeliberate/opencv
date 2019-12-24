#include<opencv2\imgproc\imgproc.hpp>
#include<opencv2\opencv.hpp>
using namespace std;
using namespace cv;

int main()
{
	Mat Image = imread("1.jpg");
	Mat dstImage, tmpImage;

	Canny(Image, tmpImage, 50, 200, 3);
	cvtColor(tmpImage, dstImage, COLOR_GRAY2BGR);

	vector<Vec2f> lines;
	HoughLines(tmpImage, lines, 1, CV_PI / 180, 150, 0, 0);//CV_PI�� pi��3.1415926�����������㻡��ֵ CV_PI / 180
	for (size_t i = 0; i < lines.size(); i++)
	{
		float rho = lines[i][0], theta = lines[i][1];
		Point pt1, pt2;
		double a = cos(theta), b = sin(theta);
		double x0 = a*rho, y0 = b*rho;



		//cvRound ���ظ�������ӽ�������ֵ���������� 
		//cvFloor ���ز����ڲ������������ֵ������ȡ��
		//cvCeil ���ز�С�ڲ�������С����ֵ������ȡ��
		pt1.x = cvRound(x0 + 1000 * (-b));
		pt1.y = cvRound(y0 + 1000 * (a));
		pt2.x = cvRound(x0 - 1000 * (-b));
		pt2.y = cvRound(x0 - 1000 * (a));
		line(dstImage, pt1, pt2, Scalar(155, 0, 95), 1, CV_AA);//
	}
	imshow("[ԭʼͼ]", Image);
	imshow("[��Ե�����ͼ]", tmpImage);
	imshow("[Ч��ͼ]", dstImage);
	waitKey(0);
	return 0;
}