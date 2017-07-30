//#define CV_LIB
#define STD_LIB

#ifdef CV_LIB
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
#endif


#ifdef STD_LIB
#include "std_lib.h"
#include <iostream>

int main() {
	std::string a, b, path;
	std::vector<std::string> c;

	path = "oreore/pantsu/hage_.txt";

	c = std_lib::split(path, "_");

	for (auto i = 0; i < c.size(); i++) {
		std::cout << c[i] << std::endl;
	}
	std::cout << std::endl;

	a = std_lib::get_file_name_with_ext(path);
	b = std_lib::get_file_name(path);

	std::cout << a << std::endl;
	std::cout << b << std::endl;

	return 0;
}

#endif
