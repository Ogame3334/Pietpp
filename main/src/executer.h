#pragma once

#include <opencv2/opencv.hpp>
#include "pp.h"

namespace Pietpp {
	typedef struct Size {
		int width;
		int height;
	} Size;

	class Executer {
	private:
		cv::Mat image;
		PP pp;
		cv::Vec3b now_color;
		cv::Vec3b pre_color;
		Size size;

		bool cc_changed;
		unsigned int slide_num;

		void add_dp(int num);
		void change_cc();

		bool move();
	public:
		Executer() = default;
		Executer(char* path);

		void next();
	};
}