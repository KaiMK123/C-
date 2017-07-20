#ifndef _CV_LIB_H_
#define _CV_LIB_H_

#include "opencv2\opencv.hpp"

namespace cv_lib {
	int create_histogram(cv::Mat src, std::vector<std::vector<int>> &hist, bool integrate=1);

};

#endif