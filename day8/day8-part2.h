#pragma once

#include <string>
#include <vector>

using namespace std;

class Day8P2 {
public:
	Day8P2(string filename);
private:
	int evaluateScenery(const vector<vector<int>> forest, const int row, const int col);
};
