#include "cv_lib.h"

#include <iostream>
#include <string>

int main() {
	std::vector<std::vector<int>> vec;
	cv::Mat img;
	img = cv::imread("oreore.jpg", 1);

	if (cv_lib::create_histogram(img, vec) == -1) return -1;

	for (unsigned int c = 0; c < vec.size(); c++) {
		for (unsigned int i = 0; i < 256; i++) {
			printf("channel : %d   bin:%d : %d\n", c, i, vec[c][i]);
		}
	}

	return 0;
}