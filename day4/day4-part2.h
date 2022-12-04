#pragma once

#include <string>
#include <vector>

using namespace std;

class Day4P2 {
public:
	Day4P2(string filename);
private:
	bool checkOverlap(vector<int> pair);
};