#include "affine.hpp"
#include "opencv2\opencv.hpp"
#include <fstream>
#include <string>


int main() {
	double r_theta, p_theta, y_theta, x_trans, y_trans, z_trans;
	std::string buf;
	std::ifstream ifs, param;
	param.open("param.txt", std::ios::in);
	param >> buf >> r_theta >>
		     buf >> p_theta >>
		     buf >> y_theta >>
		     buf >> x_trans >>
		     buf >> y_trans >>
		     buf >> z_trans;
	param.close();

	ifs.open("sl_lid_113.txt", std::ios::in);

	D_MAT m_roll, m_pitch, m_yaw, m_trans, affine;
	m_roll = roll(r_theta);
	m_pitch = pitch(p_theta);
	m_yaw = yaw(y_theta);
	m_trans = trans(x_trans, y_trans, z_trans);

	mat_mul(m_roll, m_pitch , affine);
	mat_mul(affine, m_yaw, affine);
	mat_mul(affine, m_trans, affine);

	std::vector<pcd> lidar;
	
	cv::Mat img;
	img = cv::imread("sl_cam__rect113.pgm", 0);
	//cv::imshow("input", img);
	//cv::waitKey(5);
	int x_zero = img.cols / 2;
	int y_zero = img.rows / 2;

	int buff;
	while (!ifs.fail()) {
		pcd p;
		ifs >> buff >> buff >> p.x >> p.y >> p.z;
		lidar.push_back(p);
	}
	ifs.close();

	for (int l = 0; l < (int)lidar.size(); l++) {
		lidar[l] = projection(lidar[l], affine);
		lidar[l].x = lidar[l].x - x_zero;
		lidar[l].y = lidar[l].y - y_zero;
		printf("x:%lf  y:%lf \n", lidar[l].x, lidar[l].y);
		if (lidar[l].x >= 0 && lidar[l].x < img.cols && lidar[l].y >= 0 && lidar[l].y < img.rows) {
			cv::circle(img, cv::Point((int)lidar[l].x, (int)lidar[l].y), 2, cv::Scalar(255, 255, 0), -1);
		}
	}
	
	cv::resize(img, img, cv::Size(640, 480));
	cv::imshow("proj", img);
	cv::waitKey();

	return 0;
}