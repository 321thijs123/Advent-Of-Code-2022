#include "day4-part1.h"

#include "../readers.h"

#include <iostream>

using namespace std;

Day4P1::Day4P1(string filename) {
	vector<vector<int>> assignments = readIntMatrix(filename);

	int n = 0;

	for (vector<int> pair : assignments) {
		n += checkContains(pair);
	}

	cout << n << " pairs fully contain eachother.\n";
}

bool Day4P1::checkContains(vector<int> pair) {
	if (pair[0] >= pair[2]) {
		if (pair[1] <= pair[3]) {
			return true;
		}
	}
	if (pair[2] >= pair[0]) {
		if (pair[3] <= pair[1]) {
			return true;
		}
	}

	return false;
}