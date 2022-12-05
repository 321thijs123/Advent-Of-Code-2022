#pragma once

#include <string>
#include <vector>

using namespace std;

class Day5P1 {
public:
	Day5P1(string filename);
private:
	int readStacks(string path);

	vector<vector<char>> stacks;
};
