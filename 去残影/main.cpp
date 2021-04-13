#include <opencv2/objdetect.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <fstream>
#include "Removal.h"
using namespace std;
using namespace cv;

int main()
{
	Removal removal;
	for (int i = 20; i < 42; i++)
	{
		stringstream str;
		str << "..\\finalimg3\\" << i << ".png";
		Mat inputImage = imread(str.str());
		cout << i << " ";
		removal.RemoveImageRetention(removal.inhence(inputImage));
	}
	return 0;
}