#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

#pragma warning (disable:4996)

template <class T>
int init_vec(std::vector<T> &vec, T num) {
	for (unsigned int i = 0; i < vec.size(); i++) {
		vec[i] = num;
	}
	return 0;
}

int main() {

	std::ifstream ifs, list;
	std::vector<std::ofstream> ofs;
	std::string str, buf, s_read;
	char name[128];
	list.open("filelist.txt", std::ios::in);
	float f_buf;

	ofs.resize(17);
	for (unsigned int i = 0; i < ofs.size(); i++) {
		sprintf(name, "predict%d.txt", i);
		ofs[i].open(name, std::ios::out);
	}


	while (!list.eof()) {
		std::vector<int> frequency(17, 0);
		list >> str;
		std::sprintf(name, str.c_str());

		ifs.open(name, std::ios::in);
		std::getline(ifs, str);

		std::vector<float> line_val;
		std::istringstream stream(str);

		
		while (std::getline(stream, buf, ',')) {	
			f_buf = std::stof(buf);
			line_val.push_back(f_buf);
			frequency[(int)line_val[5]]++;
			ofs[line_val[5] ] << line_val[0]
		}
		
		for (unsigned int i = 0; i < ofs.size(); i++) {
			ofs[i] << str << " " << frequency[i] << " ";
		}

	}

	

	return 0;
}