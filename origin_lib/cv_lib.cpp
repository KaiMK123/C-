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

};