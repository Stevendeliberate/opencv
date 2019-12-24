#include <opencv2\opencv.hpp>
#include<opencv2\highgui\highgui.hpp>

using namespace std;
using namespace cv;

void main41()
{
	RNG a;
	int i = 0;

	for (i = 0; i < 10; i++)
	{
		cout << a.next() << endl;
	}

	cout << endl;
	for (i = 0; i < 10; i++)
	{
		cout << a.uniform(1,10) << endl;
	}
}