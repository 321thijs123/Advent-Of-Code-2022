#pragma once

#include <string>
#include <vector>

using namespace std;

namespace day22P1 {
	void assignment(string filename);

	void walk(vector<string>& map, int& x, int& y, const char dir, const int steps);
}
