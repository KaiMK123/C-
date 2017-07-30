#pragma once

#ifndef _STD_LIB_H_
#define _STD_LIB_H_

#include <vector>
#include <string>
#include <sstream>

namespace std_lib {

	template <class T> 	
	int init_vec(std::vector<T> &vec, T num) {
		for (unsigned int i = 0; i < vec.size(); i++) {
			vec[i] = num;
		}
		return 0;
	}

	std::vector<std::string> split(std::string sentense, char *key) {
		std::vector<std::string> str;
		std::stringstream ss(sentense);
		std::string buf;
		while (std::getline(ss, buf, *key)) {
			str.push_back(buf);
		}
		return str;
	}

	std::string get_file_name_with_ext(std::string filepath) {
		std::vector<std::string> str;
		str = split(filepath, "/");
		return str[str.size()-1];
	}

	std::string get_file_name(std::string filepath) {
		std::vector<std::string> str;
		std::string name;
		name = get_file_name_with_ext(filepath);
		str = split(name, ".");
		return str[0];		
	}

};

#endif