#pragma once

#include <string>
#include <vector>

using namespace std;

namespace day14P2 {
	void assignment(string filename);
	void addLine(int x1, int y1, int x2, int y2, vector<vector<char>>& canvas);
	void showCave(vector<vector<char>>& canvas);
}
