#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main() {
	auto cap = VideoCapture(0);

	int delay = 33;
	Mat img;
	Mat img_gray;

	while (cap.isOpened()) {
		if (waitKey(delay) == 27) break;

		auto ret = cap.read(img);
		cvtColor(img, img_gray, COLOR_BGR2GRAY);

		imshow("Movie1", img);
		imshow("Movie2", img_gray);
	}

	cap.release();
	destroyAllWindows();

	return 0;
}