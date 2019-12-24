#include<opencv2\opencv.hpp>
using namespace cv;
using namespace std;

bool ROI_AddImage()
{
	//读取图像
	Mat srcImage = imread("1.jpg");
	Mat logoImage = imread("2.jpg");
	if (!srcImage.data)
	{
		cout << "读取srcImage图像错误" << endl;
		return false;
	}
	if (!logoImage.data)
	{
		cout << "读取logoImage图像错误" << endl;
		return false;
	}

	//定义一个Mat类型并给其设定ROI区域
	Mat imageROI = srcImage(Rect(200, 250, logoImage.rows, logoImage.cols));

	//加载掩膜（必须是灰度图）
	Mat mask = imread("2.jpg", CV_LOAD_IMAGE_GRAYSCALE);

	//将掩膜复制到ROI
	logoImage.copyTo(imageROI, mask);//copyTo(outoutArray m,inputArray mask)

	imshow("answer", srcImage);
	waitKey(0);
	return true;
}

void main21()
{
	ROI_AddImage();
}