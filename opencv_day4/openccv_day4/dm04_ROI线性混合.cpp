#include<opencv2\opencv.hpp>
using namespace cv;
using namespace std;


bool ROI_LinearBlending()
{
	Mat srcImage1 = imread("1.jpg",1);
	Mat srcImage2 = imread("2.jpg");

	if (!srcImage1.data)
	{
		cout << "读取srcImage1图片错误" << endl;
		return false;
	}
	if (!srcImage2.data)
	{
		cout << "读取srcImage2图片错误" << endl;
		return false;
	}

	Mat ImageROI;
	//方法一：rect（）法
	//ImageROI = srcImage1(Rect(200, 250, srcImage2.cols, srcImage2.rows));
	//方法二：range（）法
	ImageROI = srcImage1(Range(250, 250 + srcImage2.rows), Range(200, 200 + srcImage2.cols));
	addWeighted(ImageROI, 0.5, srcImage2, 0.5, 0, ImageROI);
	imshow("效果图", srcImage1);
	waitKey(0);

	return false;
}

void main41()
{
	ROI_LinearBlending();
}