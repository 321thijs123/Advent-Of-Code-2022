#include "day4-part2.h"

#include "../readers.h"

#include <iostream>

using namespace std;

Day4P2::Day4P2(string filename) {
	vector<vector<int>> assignments = readIntMatrix(filename);

	int n = 0;

	for (vector<int> pair : assignments) {
		n += checkOverlap(pair);
	}

	cout << n << " pairs overlap.\n";
}

bool Day4P2::checkOverlap(vector<int> pair) {
	if (pair[1] < pair[2]) return false;
	if (pair[0] > pair[3]) return false;

	return true;
}
