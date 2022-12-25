#pragma once

#include <string>
#include <vector>

using namespace std;

namespace day22P2 {
	void assignment(string filename);

	void walk(vector<string>& map, int& x, int& y, char& dir, const int steps);
}
