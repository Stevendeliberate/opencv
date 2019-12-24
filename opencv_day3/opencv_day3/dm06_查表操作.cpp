#include<opencv2\opencv.hpp>

using namespace cv;


//��ͨ������
void main61()

{
	Mat J;
	Mat I = imread("1.jpg",CV_LOAD_IMAGE_GRAYSCALE);//�Ҷ�ͼ���ȡ

	uchar lutdata[256];//������
	int divideWith = 10;

	for (int i = 0; i < 256; i++)
	{
		lutdata[i] = divideWith*(i / divideWith);//������õ�ֵ�������
	}

	Mat lut(1, 256, CV_8UC1,lutdata);//�������Mat������

	imshow("I", I);
	moveWindow("I", 0, 0);
	LUT(I, lut, J);//���
	imshow("J", J);
	moveWindow("J", J.cols, 0);
	waitKey(0);
}

//��ͨ������
void main62()
{
	Mat ImageTo;
	Mat ImageFrom = imread("1.jpg", CV_LOAD_IMAGE_ANYCOLOR);

	uchar lutdata[256 * 3];
	int divideWith = 10;

	for (int i = 0; i < 256 * 3; i += 3)
	{
		lutdata[i] = divideWith*(i / divideWith);
		lutdata[i+1] = divideWith*((i+1) / divideWith);
		lutdata[i+2] = divideWith*((i+2) / divideWith);
	}

	Mat lut(1, 256, CV_8UC3, lutdata);

	imshow("ImageFrom", ImageFrom);
	moveWindow("ImageFrom", 0, 0);
	LUT(ImageFrom, lut, ImageTo);//���
	imshow("ImageTo", ImageTo);
	moveWindow("ImageTo", ImageTo.cols, 0);
	waitKey(0);
	
}

//ͼ���ֵ��
void main63()
{
	double time = static_cast<double>(getTickCount());//��ʼ��ʱ
	Mat ImageTo;
	Mat ImageFrom = imread("1.jpg", CV_LOAD_IMAGE_GRAYSCALE);

	uchar lutdata[256];

	for (int i = 0; i < 256; i++)//��ֵ��
	{
		if (i < (256) / 2)
		{
			lutdata[i] = 0;
		}
		else
		{
			lutdata[i] = 255;
		}
	}

	Mat lut(1, 256, CV_8U, lutdata);

	imshow("ImageFrom", ImageFrom);
	moveWindow("ImageFrom", 0, 0);
	LUT(ImageFrom, lut, ImageTo);//���
	imshow("ImageTo", ImageTo);
	moveWindow("ImageTo", ImageTo.cols, 0);
	time = ((double)getTickCount() - time) / getTickFrequency();
	std::cout << time << std::endl;
	waitKey(0);

}