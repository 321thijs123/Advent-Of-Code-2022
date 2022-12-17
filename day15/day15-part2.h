#pragma once

#include <string>
#include <vector>

using namespace std;

namespace day15P2 {
	void assignment(string filename);

	void mergeLimits(pair<int, int> limit, vector<pair<int, int>>& limits);

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
