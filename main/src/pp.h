#pragma once

namespace Pietpp {
	typedef struct Point {
		unsigned int x;
		unsigned int y;
	}Point;

	typedef struct PP {
		Point pos;
		int dp;
		bool cc_left;
	} PP;
}