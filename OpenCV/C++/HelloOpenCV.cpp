#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main() {
	std::cout << "Hello OpenCV" << CV_VERSION << std::endl;

	Mat img = imread("lena.jpg", IMREAD_COLOR);

	namedWindow("image");
	imshow("Lena", img);
	waitKey();
	//destroyAllWindows();

	return 0;
}