#pragma once

#define _USE_MATH_DEFINES
#include "mats.hpp"
#include <math.h>



D_MAT roll(double theta) {
	double rad = theta / M_PI;

	double si = sin(rad);
	double co = cos(rad);

	D_MAT mat{ { 1,   0,   0,   0},
				 { 0,  co,  si,   0},
				 { 0, -si,  co,   0},
				 { 0,   0,   0,   1} };
	return mat;
}

D_MAT pitch(double theta) {
	double rad = theta / M_PI;

	double si = sin(rad);
	double co = cos(rad);

	D_MAT mat{ { co,   0, -si,   0 },
			   {  0,   1,   0,   0 },
			   { si,   0,  co,   0 },
			   {  0,   0,   0,   1 } };
	return mat;
}

D_MAT yaw(double theta) {
	double rad = theta / M_PI;

	double si = sin(rad);
	double co = cos(rad);

	D_MAT mat{ {  co,  si,   0,   0 },
			   { -si,  co,   0,   0 },
		       {   0,   0,   1,   0 },
			   {   0,   0,   0,   1 } };
	return mat;
}

D_MAT trans(double x, double y, double z) {
	D_MAT mat{ { 1, 0, 0, 0 },
		       { 0, 1, 0, 0 },
			   { 0, 0, 1, 0 },
			   { x, y, z, 1 } };
	return mat;
}