#include<opencv2\core\core.hpp>
#include<opencv2\highgui\highgui.hpp>
#include<iostream>
#include<opencv2\opencv.hpp>

using namespace cv;
using namespace std;

bool  MultiChannelBlending()
{
	Mat srcImage = imread("1.jpg");
	Mat logoImage = imread("2.jpg",0);
	vector<Mat> channels;

	split(srcImage,channels);


	//��ɫͼ��ͻҶ�ͼ���ϣ��Ҷ�ͼ���ṩ������״����ɫͼ���ṩɫ��
	//ͨ��0����ɫͨ����������Ҷ�ͼ��logoImage��Ϻ�logoImageΪ����ͨ��0��ͼ��
	//�ı�logoImage��Ȩֵ���ɸı�ͼ�ε���ǳ���Ӷ���ɫ��ǳҲ���Ըı䡣
	addWeighted((channels.at(0))(Rect(0,250 , logoImage.cols, logoImage.rows)), 1.0,
		logoImage, 0.5, 0, (channels.at(0))(Rect(0, 250, logoImage.cols, logoImage.rows)));

	merge(channels, srcImage);

	imshow("�����ɫͨ��ͼ��", srcImage);

	//��ɫͨ��
	//��Ҫ���¶�ȡͼƬ��
	srcImage = imread("1.jpg");
	logoImage = imread("2.jpg", 0);

	split(srcImage, channels);//���·���ͨ��
	
	addWeighted((channels.at(1))(Rect(0, 250, logoImage.cols, logoImage.rows)), 1.0,
		logoImage, 0.5, 0, (channels.at(1))(Rect(0, 250, logoImage.cols, logoImage.rows)));

	merge(channels, srcImage);

	imshow("�����ɫͨ��ͼ��", srcImage);

	//��ɫͨ��
	srcImage = imread("1.jpg");
	logoImage = imread("2.jpg", 0);
	split(srcImage, channels);
	addWeighted((channels.at(2))(Rect(0, 250, logoImage.cols, logoImage.rows)), 1.0,
		logoImage, 0.5, 0, (channels.at(2))(Rect(0, 250, logoImage.cols, logoImage.rows)));

	merge(channels, srcImage);

	imshow("��Ϻ�ɫͨ��ͼ��", srcImage);

	return true;
}


int main61()
{
	system("color 9F");

	MultiChannelBlending();
	if (MultiChannelBlending())
	{
		cout << "successed" << endl;
	}

	waitKey(0);
	return 0;
}