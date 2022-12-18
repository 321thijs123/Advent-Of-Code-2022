#pragma once

#include <string>
#include <vector>

using namespace std;

namespace day17P2 {
	void assignment(string filename);

	bool checkCollision(const int x, const int y, const vector<vector<char>> rock, const vector<vector<char>> map);
	void drawMap(vector<vector<char>> map, vector<vector<char>> rock, int x, int y);
	int getHeight(vector<vector<char>> map);

	void growMap(vector<vector<char>>& map, int& y, int& minY, vector<char> mapRow);
	void moveRock(vector<vector<char>> map, vector<vector<char>> rock, const string jets, int& jetIndex, int& x, int& y);
	void addRock(vector<vector<char>>& map, const vector<vector<char>> rock, const int x, const int y);
}
