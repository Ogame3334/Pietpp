#include "executer.h"

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

	Executer::Executer(char* path) {
		this->image = cv::imread(path);
		this->pp = { 0, 0, 0, false };
		this->now_color = cv::Vec3b(255, 255, 255);
		this->pre_color = cv::Vec3b(255, 255, 255);
		this->size = {this->image.size().width, this->image.size().height};
		this->cc_changed = false;
		this->slide_num = 0;
		//std::cout << this->size.width << "\n";
	}

	void Executer::next() {
		//std::cout << this->pp.pos.x << ", " << this->pp.pos.y << "\n";
		this->pre_color = this->now_color;
		if (not move()) {
			if (not this->cc_changed) {
				this->change_cc();
			}
			else {
				this->add_dp(1);
			}
		}
		else {
			this->now_color = this->image.at<cv::Vec3b>(this->pp.pos.y, this->pp.pos.x);
		}
		std::cout << this->now_color << std::endl;
	}
}