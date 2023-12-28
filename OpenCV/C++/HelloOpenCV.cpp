#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	//비디오 캡처 초기화
	VideoCapture cap(0);

	//카메라가 성공적으로 열렸는지 확인을 위한 조건문
	if (!cap.isOpened())
	{
		printf("Can't open the camera");
		return -1;
	}

	//매트릭스 초기화
	Mat img;

	//비디오 캡처 및 표시:
	while (1)
	{
		cap >> img;
		imshow("camera img", img); //창에 캡처된 프레임을 표시합니다.

		if (waitKey(1) == 27)
			break;
	}

	return 0;
}