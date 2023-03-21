#include <stdlib.h>
#include "executer.h"
#include "constants.h"

using namespace cv;

namespace Pietpp {
	void Executer::add_dp(int num) {
		//std::cout << "add_dp is called.\n";
		this->pp.dp += num;
		while (this->pp.dp < 0) {
			this->pp.dp += 4;
		}
		while (this->pp.dp > 3) {
			this->pp.dp -= 4;
		}
		this->cc_changed = false;
	}

	void Executer::change_cc() {
		std::cout << "change_cc is called.\n";
		if (this->pp.cc_left) {
			this->pp.cc_left = false;
			this->cc_changed = true;
		}
		else {
			this->pp.cc_left = true;
			this->cc_changed = true;
		}
	}

	void Executer::judge_stack_empty_exit() {
		if (this->stack.empty()) {
			exit(EXIT_FAILURE);
		}
	}

	bool Executer::move() {
		//std::cout << "move is called.\n";
		switch (this->pp.dp)
		{
		case 0:
			if (this->pp.pos.x + 1 == this->size.width) {
				return false;
			}
			this->pp.pos.x += 1;
			break;
		case 1:
			if (this->pp.pos.y + 1 == this->size.height) {
				return false;
			}
			this->pp.pos.y += 1;
			break;
		case 2:
			if (this->pp.pos.x - 1 == -1) {
				return false;
			}
			this->pp.pos.x += -1;
			break;
		case 3:
			if (this->pp.pos.y - 1 == -1) {
				return false;
			}
			this->pp.pos.y += -1;
			break;
		}
		return true;
	}

	int Executer::convert_color_id(Vec3b color) {
		for (int i = 0; i < std::extent<decltype(COLORS)>::value; i++) {
			if (color == COLORS[i]) {
				return i;
			}
		}
		return -1;
	}

	int Executer::calc_color_sub(int pre_color_id, int now_color_id) {
		int sub = now_color_id - pre_color_id;
		if (sub < 0) {
			sub += 36;
		}
		return sub;
	}

	void Executer::exe_order(int order_id) {
		Orders id = static_cast<Orders>(order_id);
		int a, b;
		char t;
		char* s;
		switch (id)
		{
		case Orders::ADD:
			std::cout << "ADD" << std::endl;
			this->judge_stack_empty_exit();
			a = this->stack.top();
			this->stack.pop();
			this->judge_stack_empty_exit();
			b = this->stack.top();
			this->stack.pop();
			this->stack.push(a + b);
			break;
		case Orders::DIV:
			std::cout << "DIV" << std::endl;
			this->judge_stack_empty_exit();
			a = this->stack.top();
			this->stack.pop();
			this->judge_stack_empty_exit();
			b = this->stack.top();
			this->stack.pop();
			this->stack.push(a / b);
			break;
		case Orders::DUP:
			std::cout << "DUP" << std::endl;
			this->judge_stack_empty_exit();
			a = this->stack.top();
			this->stack.push(a);
			break;
		case Orders::GREAT:
			std::cout << "GREAT" << std::endl;
			this->judge_stack_empty_exit();
			a = this->stack.top();
			this->stack.pop();
			this->judge_stack_empty_exit();
			b = this->stack.top();
			this->stack.pop();
			this->stack.push((b >= a) ? 1 : 0);
			break;
		case Orders::INC:
			std::cout << "INC" << std::endl;
			t = this->sentence[this->sentence_index++];
			break;
			
		case Orders::INN:
			std::cout << "INN" << std::endl;
			t = this->sentence[this->sentence_index++];
			break;

		case Orders::MOD:
			std::cout << "MOD" << std::endl;
			this->judge_stack_empty_exit();
			a = this->stack.top();
			this->stack.pop();
			this->judge_stack_empty_exit();
			b = this->stack.top();
			this->stack.pop();
			this->stack.push(b % a);
			break;
		case Orders::MUL:
			std::cout << "MUL" << std::endl;
			this->judge_stack_empty_exit();
			a = this->stack.top();
			this->stack.pop();
			this->judge_stack_empty_exit();
			b = this->stack.top();
			this->stack.pop();
			this->stack.push(b * a);
			break;
		case Orders::NOT:
			std::cout << "NOT" << std::endl;
			this->judge_stack_empty_exit();
			a = this->stack.top();
			this->stack.pop();
			if (a == 0) {
				this->stack.push(1);
			}
			else {
				this->stack.push(0);
			}
			break;
		case Orders::OUTC:
			std::cout << "OUTC" << std::endl;
			break;
		case Orders::OUTN:
			std::cout << "OUTN" << std::endl;
			this->judge_stack_empty_exit();
			a = this->stack.top();
			this->stack.pop();
			std::cout << a;
			break;
		case Orders::POINT:
			std::cout << "POINT" << std::endl;
			this->judge_stack_empty_exit();
			a = this->stack.top();
			this->stack.pop();
			this->add_dp(a);
			break;
		case Orders::POP:
			std::cout << "POP" << std::endl;
			this->judge_stack_empty_exit();
			this->stack.pop();
			break;
		case Orders::PUSH:
			std::cout << "PUSH" << std::endl;
			this->stack.push(this->codel_num);
			break;
		case Orders::ROLL:
			std::cout << "ROLL" << std::endl;
			this->judge_stack_empty_exit();
			a = this->stack.top();
			this->stack.pop();
			this->judge_stack_empty_exit();
			b = this->stack.top();
			this->stack.pop();
			break;
		case Orders::SUB:
			std::cout << "SUB" << std::endl;
			this->judge_stack_empty_exit();
			a = this->stack.top();
			this->stack.pop();
			this->judge_stack_empty_exit();
			b = this->stack.top();
			this->stack.pop();
			this->stack.push(b - a);
			break;
		case Orders::SWITCH:
			std::cout << "SUB" << std::endl;
			this->judge_stack_empty_exit();
			a = this->stack.top();
			this->stack.pop();
			for (int i = 0; i < a; i++) {
				this->change_cc();
			}
			break;
		default:
			std::cout << "NULL" << std::endl;
			break;
		}
	}

	Executer::Executer(char* path) {
		//Mat bgr_image = imread(path);
		//cvtColor(bgr_image, this->image, COLOR_BGR2HSV);
		this->image = imread(path);
		this->pp = { 0, 0, 0, false };
		this->sentence = NULL;
		this->now_color = Vec3b(255, 255, 255);
		this->now_color_id = 36;
		this->pre_color_id = 36;
		this->size = {this->image.size().width, this->image.size().height};
		this->cc_changed = false;
		this->slide_num = 0;
		//std::cout << this->size.width << "\n";
	}
	Executer::Executer(char* path, char* sentence) {
		//Mat bgr_image = imread(path);
		//cvtColor(bgr_image, this->image, COLOR_BGR2HSV);
		this->image = imread(path);
		this->pp = { 0, 0, 0, false };
		this->sentence = sentence;
		this->now_color = Vec3b(255, 255, 255);
		this->now_color_id = 36;
		this->pre_color_id = 36;
		this->size = {this->image.size().width, this->image.size().height};
		this->cc_changed = false;
		this->slide_num = 0;
		//std::cout << this->size.width << "\n";
	}

	void Executer::next() {
		//std::cout << this->pp.pos.x << ", " << this->pp.pos.y << "\n";
		this->pre_color_id = this->now_color_id;
		if (not move()) {
			if (not this->cc_changed) {
				this->change_cc();
			}
			else {
				this->add_dp(1);
			}
		}
		else {
			this->now_color = this->image.at<Vec3b>(this->pp.pos.y, this->pp.pos.x);
			this->now_color_id = this->convert_color_id(this->now_color);
		}
		std::cout << this->now_color << std::endl;
		this->exe_order(this->calc_color_sub(this->pre_color_id, this->now_color_id));

	}

	void Executer::color_view() {
		for (int y = 0; y < this->size.height; y++) {
			for (int x = 0; x < this->size.width; x++) {
				std::cout << this->image.at<Vec3b>(y, x) << std::endl;
			}
		}
	}

	void Executer::color_sub_view() {
		Vec3b pre_color{ 0, 0, 0 };
		Vec3b now_color{ 0, 0, 0 };
		for (int y = 0; y < this->size.height; y++) {
			for (int x = 0; x < this->size.width; x++) {
				now_color = this->image.at<Vec3b>(y, x);
					Vec3b sub = now_color - pre_color;
					std::cout << sub << std::endl;
					pre_color = now_color;
			}
		}
	}
}
