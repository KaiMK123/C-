#ifndef _STD_LIB_H_
#define _STD_LIB_H_

#include <vector>

namespace std_lib {
	template <class T> 
	
	int init_vec(std::vector<T> &vec, T num) {
		for (unsigned int i = 0; i < vec.size(); i++) {
			vec[i] = num;
		}
		return 0;
	}
};

#endif