#include "file_stream.h"
#include <iostream>
#include <sstream>
#include <string>


namespace file_stream {


	int csv_read_float(std::ifstream &ifs, std::vector<std::vector<float>> &val) {
		std::string str, buf;
		float f_buf;

		if (!ifs) {
			std::cout << "Designated file not found" << std::endl;
			return -1;
		}
		int i = 0;
		while (std::getline(ifs, str)) {
			std::vector<float> line_val;
			std::istringstream stream(str);
			while (std::getline(stream, buf, ',')) {
				f_buf = std::stof(buf);
				line_val.push_back(f_buf);
			}
			val.push_back(line_val);
		}

		return 0;
	}



	int csv_read_int(std::ifstream &ifs, std::vector < std::vector<int>> &val) {
		std::string str, buf;
		int i_buf;

		if (!ifs) {
			std::cout << "Designated file not found" << std::endl;
			return -1;
		}
		int i = 0;
		while (std::getline(ifs, str)) {
			std::vector<int> line_val;
			std::istringstream stream(str);
			while (std::getline(stream, buf, ',')) {
				i_buf = std::stoi(buf);
				line_val.push_back(i_buf);
			}
			val.push_back(line_val);
		}

		return 0;

	}


	int csv_read_string(std::ifstream &ifs, std::vector < std::vector<std::string>> &val) {
		std::string str, buf;

		if (!ifs) {
			std::cout << "Designated file not found" << std::endl;
			return -1;
		}
		int i = 0;
		while (std::getline(ifs, str)) {
			std::vector<std::string> line_val;
			std::istringstream stream(str);
			while (std::getline(stream, buf, ',')) {
				line_val.push_back(buf);
			}
			val.push_back(line_val);
		}

		return 0;

	}

};