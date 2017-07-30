#pragma once

#ifndef _FILE_STREAM_H_
#define _FILE_STREAM_H_

#include <fstream>
#include <vector>

namespace file_stream {
	int csv_read_float(std::ifstream &ifs, std::vector<std::vector<float>> &val);
	int csv_read_int(std::ifstream &ifs, std::vector<std::vector<int>> &val);
	int csv_read_string(std::ifstream &ifs, std::vector<std::vector<std::string>> &val);
};

#endif