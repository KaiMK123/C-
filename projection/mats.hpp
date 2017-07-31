#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <vector>
#include <iostream>

typedef std::vector<std::vector<double> > D_MAT;
typedef unsigned int uint;

class pcd {
public:
	double x;
	double y;
	double z;
};

int mat_mul(D_MAT matrix1, D_MAT matrix2, D_MAT &r) {

	int col1 = (int)matrix1[0].size();
	int row1 = (int)matrix1.size();

	int col2 = (int)matrix2[0].size();
	int row2 = (int)matrix2.size();
	double sum;
	D_MAT mult_mat;
	srand((unsigned)time(NULL));

	//行列の積の条件が満たされない場合のエラー処理
	if (col1 != row2) {
		printf("can't calculate matrix\n");
		return -1;
	}

	//行列の行の動的確保
	mult_mat.resize(row1);

	//行列の列の動的確保
	for (uint i = 0; i < mult_mat.size(); i++) {
		mult_mat[i].resize(col2);
	}

	//std::cout << mult_mat.size() << "  " << mult_mat[0].size() << std::endl;

	//行列の積
	for (int i = 0; i < row1; i++) {
		for (int y = 0; y < col2; y++) {
			sum = 0;
			int x = 0;
			for (int j = 0; j < col1; j++) {
				sum += matrix1[i][j] * matrix2[x][y];
				x++;
			}
			mult_mat[i][y] = sum;
		}
	}

	r = mult_mat;

	return 0;
}

std::vector<double> lid(double x, double y, double z) {
	std::vector<double> mat{x, y, z, 1};
	return mat;
}

pcd projection(pcd p, D_MAT matrix) {

	int dim = 4;
	std::vector<double> proj_p, raw_p;
	raw_p = {p.x, p.y, p.z, 1};

	proj_p.resize(dim);

	//行列の積
	for (int d = 0; d < dim; d++) {
		double sum = 0.0;
		for (int i = 0; i < dim; i++) {		
			sum += raw_p[i] * matrix[i][d];
		}
		proj_p[d] = sum;
	}

	pcd pp;
	pp.x = proj_p[0];
	pp.y = proj_p[1];
	pp.z = proj_p[2];

	return pp;
}