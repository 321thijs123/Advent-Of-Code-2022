#include "day1-part1.h"

#include "../readers.h"

#include <iostream>
#include <algorithm>

using namespace std;

Day1P1::Day1P1(string filename) {
	vector<vector<int>> inventories = readIntLists(filename);
	
	int max = 0;

	for (vector<int> inv : inventories) {
		int sum = 0;

		for (int cal : inv) {
			sum += cal;
		}

		if (sum > max) max = sum;
	}

	cout << max;
}
