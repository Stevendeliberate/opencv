#include<opencv2\opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
	Point2f p(6, 2);
	cout << "二维点p:" << p << endl;

	Point3f p1(1, 2, 3);
	cout << "三维点p1" << p1 << endl;

	vector<float> v;
	v.push_back(3);
	v.push_back(5);
	v.push_back(7);
	cout << "基于Mat的vector shortvec = " << Mat(v) << endl;

	vector<Point2f>points(20);
	for (size_t i = 0; i < points.size(); ++i)
	{
		points[i] = Point2f((float)(i * 5), (float)(i % 7));
	}	
	cout << "二维点向量  points = " << points << endl;
	return 0;
}