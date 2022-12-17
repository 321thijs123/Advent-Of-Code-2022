#pragma once

#include <string>

using namespace std;

namespace day15P1 {
	void assignment(string filename);

	struct Sensor {
		Sensor(int x, int y, int bx, int by) {
			this->x = x;
			this->y = y;
			this->bx = bx;
			this->by = by;
			this->reach = abs(bx - x) + abs(by - y);
		}

		int x, y, bx, by, reach;
	};
}