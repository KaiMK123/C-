#include "cv_lib.h"
#include "std_lib.h"
#include <stdio.h>

namespace cv_lib {
	int create_histogram(cv::Mat src, std::vector<std::vector<int>> &hist, bool integrate) {
		hist.resize(src.channels());
		int buf, channel;

		channel = src.channels();

		if (integrate == true) {
			for (int c = 0; c < channel; c++) {
				hist[c].resize(256);
				std_lib::init_vec(hist[c], 0);
			}
		}


		for (int i = 0; i < src.rows; i++) {
			for (int j = 0; j < src.cols; j++) {
				for (int c = 0; c < channel; c++) {
					buf = src.data[i*src.step + j*channel + c];
					if (buf < 256) {
						hist[c][buf]++;
					}
					else {
						printf("image color bit is out of range\n");
						return -1;
					}
				}
			}

		}
		return 0;
	}

	cv::Scalar rand_color() {
		int r, g, b;
		r = rand() % 256;
		g = rand() % 256;
		b = rand() % 256;

		return cv::Scalar(b, g, r);
	}

	int drow__bdx(cv::Mat &img, std::vector<float> bdx, float th, std::vector<cv::Scalar> &color) {
		cv::Point p1, p2;
		p1.x = static_cast<int>(round(bdx[2]));
		p1.y = static_cast<int>(round(bdx[3]));
		p2.x = static_cast<int>(round(bdx[4]));
		p2.y = static_cast<int>(round(bdx[5]));

		if (bdx[1] > th) {
			while (bdx[0] >= color.size()) {
				cv::Scalar buf = rand_color();
				color.push_back(buf);
			}
			cv::rectangle(img, p1, p2, color[bdx[0]]);
		}
		return 0;
	}

};