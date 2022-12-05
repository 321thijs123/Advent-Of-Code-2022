#pragma once

#include <string>
#include <vector>

using namespace std;

class Day5P2 {
public:
	Day5P2(string filename);
private:
	int readStacks(string path);

	vector<vector<char>> stacks;
};
