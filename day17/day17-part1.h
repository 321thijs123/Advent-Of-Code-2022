#pragma once

#include <string>
#include <vector>

using namespace std;

namespace day17P1 {
	void assignment(string filename);

	bool checkCollision(const int x, const int y, const vector<vector<char>> rock, const vector<vector<char>> map);
	void drawMap(vector<vector<char>> map, vector<vector<char>> rock, int x, int y);
}
