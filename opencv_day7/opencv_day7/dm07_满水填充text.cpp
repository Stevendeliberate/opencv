#include<opencv2\imgproc\imgproc.hpp>
#include<opencv2\highgui\highgui.hpp>
#include<core\core.hpp>

using namespace cv;
using namespace std;

int main()
{
	Mat image1 = imread("1.jpg");
	Mat imageMask;

	Rect rect1;
	int flags = 4 + (255 << 8) + CV_FLOODFILL_MASK_ONLY;
	imageMask.create(image1.rows + 2, image1.cols + 2, CV_8UC1);

	Mat grayImage = imread("1.jpg", 0);
	imageMask = Scalar::all(0);
	threshold(imageMask, imageMask, 1, 128, THRESH_BINARY);
	floodFill(image1,imageMask, Point(50, 300), Scalar(155*0.299 ,255*0.587, 55*0.114), &rect1, Scalar(20, 20, 20), Scalar(20, 20, 20), flags);

//	flags = 4 + (150 << 8) + CV_FLOODFILL_FIXED_RANGE;
//	floodFill(image1, Point(50, 300), Scalar(155, 255, 55), &rect1, Scalar(20, 20, 20), Scalar(20, 20, 20), flags);
	imshow("原图", image1);
	imshow("mask", imageMask);
	waitKey(0);
	return 0;

}

