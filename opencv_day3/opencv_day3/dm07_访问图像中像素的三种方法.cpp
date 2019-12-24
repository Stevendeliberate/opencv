#include<opencv2\opencv.hpp>
#include<opencv2\highgui\highgui.hpp>
#include<iostream>

using namespace std;
using namespace cv;

//ָ����ʣ�C������[ ]���������ɫ�ռ���������
void colorReduce1(Mat& inputImage,Mat& outputImage,int div)
{
	//����׼��
	outputImage = inputImage.clone();//����ʵ�ε���ʱ����
	int rowNumber = outputImage.rows;//����
	int colNumber = outputImage.cols*outputImage.channels();//����*ͨ���� = ÿһ��Ԫ�صĸ���

	//˫��ѭ�����������е�����ֵ
	for (int i = 0; i < rowNumber; i++)//��ѭ��
	{
		uchar* data = outputImage.ptr<uchar>(i);//��ȡ��i�е��׵�ַ
		for (int j = 0; j < colNumber; j++)//��ѭ��
		{
			data[j] = data[j] / div*div + div / 2;//��ʼ����ÿ������
		}
	}
}

//�õ�������������
void colorReduce2(Mat &inputImage, Mat &outputImage, int div)
{
	//����׼��
	outputImage = inputImage.clone();

	//��ȡ������
	Mat_<Vec3b>::iterator it = outputImage.begin<Vec3b>();//��ʼλ�õĵ�����
	Mat_<Vec3b>::iterator itend = outputImage.end<Vec3b>();//��ֹλ�õĵ�����

	//��ȡ��ɫͼ������
	for (; it != itend; ++it)
	{
		//��ʼ����ÿ������
		(*it)[0] = (*it)[0] / div*div + div / 2;
		(*it)[1] = (*it)[1] / div*div + div / 2;
		(*it)[2] = (*it)[2] / div*div + div / 2;
	}
}

//��̬��ַ����
void colorReduce3(Mat &inputImage, Mat &outputImage, int div)
{
	//����׼��
	outputImage = inputImage.clone();
	int rowNumber = outputImage.rows;
	int colNumber = outputImage.cols;

	//��ȡ��ɫͼ������
	for (int i = 0; i < rowNumber; i++)
	{
		for (int j = 0; j < colNumber; j++)
		{
			//��ʼ����ÿ������
			outputImage.at<Vec3b>(i, j)[0] =
				outputImage.at<Vec3b>(i, j)[0] / div*div + div / 2;//��ɫͨ��B
			outputImage.at<Vec3b>(i, j)[1] =
				outputImage.at<Vec3b>(i, j)[1] / div*div + div / 2;//��ɫͨ��G
			outputImage.at<Vec3b>(i, j)[2] =
				outputImage.at<Vec3b>(i, j)[2] / div*div + div / 2;//��ɫͨ��R
		}
	}
}


void main71()
{
	//����ͼ����ʾ
	Mat srcImage = imread("1.jpg");
	imshow("ԭʼͼ��", srcImage);

	//��ԭʼͼ�Ĳ������������Ч��ͼ
	Mat dstImage;
	dstImage.create(srcImage.rows, srcImage.cols, srcImage.type());//Ч��ͼ��С��������ԭͼƬ��ͬ

	double time = static_cast<double>(getTickCount());//��ʼ��ʱ

	colorReduce1(srcImage, dstImage, 32);//������ɫ�ռ���������

	time = ((double)getTickCount() - time) / getTickFrequency();//����ʱ�䲢���
	std::cout << "time1:"<<time << std::endl;

	//��ʾЧ��ͼ
	imshow("Ч��ͼ",dstImage);



	waitKey(0);
}

void main72()
{
	//����ͼ����ʾ
	Mat srcImage = imread("1.jpg");
	imshow("ԭʼͼ��", srcImage);

	//��ԭʼͼ�Ĳ������������Ч��ͼ
	Mat dstImage;
	dstImage.create(srcImage.rows, srcImage.cols, srcImage.type());//Ч��ͼ��С��������ԭͼƬ��ͬ

	double time = static_cast<double>(getTickCount());//��ʼ��ʱ

	colorReduce2(srcImage, dstImage, 32);//������ɫ�ռ���������

	time = ((double)getTickCount() - time) / getTickFrequency();//����ʱ�䲢���
	std::cout << "time1:" << time << std::endl;

	//��ʾЧ��ͼ
	imshow("Ч��ͼ", dstImage);

	waitKey(0);
}

void main()
{
	//����ͼ����ʾ
	Mat srcImage = imread("1.jpg");
	imshow("ԭʼͼ��", srcImage);

	//��ԭʼͼ�Ĳ������������Ч��ͼ
	Mat dstImage;
	dstImage.create(srcImage.rows, srcImage.cols, srcImage.type());//Ч��ͼ��С��������ԭͼƬ��ͬ

	double time = static_cast<double>(getTickCount());//��ʼ��ʱ

	colorReduce3(srcImage, dstImage, 32);//������ɫ�ռ���������

	time = ((double)getTickCount() - time) / getTickFrequency();//����ʱ�䲢���
	std::cout << "time1:" << time << std::endl;

	//��ʾЧ��ͼ
	imshow("Ч��ͼ", dstImage);

	waitKey(0);
}