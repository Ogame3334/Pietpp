#pragma once

#include <stack>
#include <opencv2/opencv.hpp>
#include "pp.h"

using namespace cv;

namespace Pietpp {
	typedef struct Size {
		int width;
		int height;
	} Size;

	class Executer {
	private:
		Mat image;
		PP pp;
		std::stack<int> stack;
		char* sentence;
		int sentence_index = 0;
		Vec3b now_color;
		int now_color_id;
		int pre_color_id;
		Size size;
		int codel_num = 0;

		bool cc_changed;
		unsigned int slide_num;

		void add_dp(int num);
		void change_cc();

		void judge_stack_empty_exit();
		bool move();
		int convert_color_id(Vec3b color);
		int calc_color_sub(int pre_color_id, int now_color_id);
		void exe_order(int order_id);
	public:
		Executer() = default;
		Executer(char* path);
		Executer(char* path, char* sentence);

		void next();
		void color_view();
		void color_sub_view();
	};
}