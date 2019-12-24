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
	HoughLines(tmpImage, lines, 1, CV_PI / 180, 150, 0, 0);//CV_PI是 pi（3.1415926），用来计算弧度值 CV_PI / 180
	for (size_t i = 0; i < lines.size(); i++)
	{
		float rho = lines[i][0], theta = lines[i][1];
		Point pt1, pt2;
		double a = cos(theta), b = sin(theta);
		double x0 = a*rho, y0 = b*rho;



		//cvRound 返回跟参数最接近的整数值；四舍五入 
		//cvFloor 返回不大于参数的最大整数值；向上取整
		//cvCeil 返回不小于参数的最小整数值；向下取整
		pt1.x = cvRound(x0 + 1000 * (-b));
		pt1.y = cvRound(y0 + 1000 * (a));
		pt2.x = cvRound(x0 - 1000 * (-b));
		pt2.y = cvRound(x0 - 1000 * (a));
		line(dstImage, pt1, pt2, Scalar(155, 0, 95), 1, CV_AA);//
	}
	imshow("[原始图]", Image);
	imshow("[边缘检测后的图]", tmpImage);
	imshow("[效果图]", dstImage);
	waitKey(0);
	return 0;
}