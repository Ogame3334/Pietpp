#pragma once

#include <opencv2/opencv.hpp>

using namespace cv;

namespace Pietpp {
	enum class Orders {
		NUL,
		NUL0,
		ADD,
		NUL1,
		DIV,
		NUL2,
		GREAT,
		NUL3,
		DUP,
		NUL4,
		INC,
		NUL5,
		PUSH,
		NUL6,
		SUB,
		NUL7,
		MOD,
		NUL8,
		POINT,
		NUL9,
		ROLL,
		NUL10,
		OUTN,
		NUL11,
		POP,
		NUL12,
		MUL,
		NUL13,
		NOT,
		NUL14,
		SWITCH,
		NUL15,
		INN,
		NUL16,
		OUTC,
		NUL17
	};

	Vec3b COLORS[] = {
		Vec3b(192, 192, 255),
		Vec3b(192, 224, 255),
		Vec3b(192, 255, 255),
		Vec3b(192, 255, 224),
		Vec3b(192, 255, 192),
		Vec3b(224, 255, 192),
		Vec3b(255, 255, 192),
		Vec3b(255, 224, 192),
		Vec3b(255, 192, 192),
		Vec3b(255, 192, 224),
		Vec3b(255, 192, 255),
		Vec3b(224, 192, 255),
		Vec3b(0, 0, 255),
		Vec3b(0, 127, 255),
		Vec3b(0, 255, 255),
		Vec3b(0, 255, 127),
		Vec3b(0, 255, 0),
		Vec3b(127, 255, 0),
		Vec3b(255, 255, 0),
		Vec3b(255, 127, 0),
		Vec3b(255, 0, 0),
		Vec3b(255, 0, 127),
		Vec3b(255, 0, 255),
		Vec3b(127, 0, 255),
		Vec3b(0, 0, 192),
		Vec3b(0, 96, 192),
		Vec3b(0, 192, 192),
		Vec3b(0, 192, 96),
		Vec3b(0, 192, 0),
		Vec3b(96, 192, 0),
		Vec3b(192, 192, 0),
		Vec3b(192, 96, 0),
		Vec3b(192, 0, 0),
		Vec3b(192, 0, 96),
		Vec3b(192, 0, 192),
		Vec3b(96, 0, 192),

		Vec3b(255, 255, 255),
		Vec3b(0, 0, 0),
	};
}
