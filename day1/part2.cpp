#include "part2.h"

#include "../readers.h"

#include <iostream>
#include <algorithm>

using namespace std;

Day1P2::Day1P2(string filename) {
	vector<vector<int>> inventories = readIntLists(filename);

	vector<int> sums;

	for (vector<int> inv : inventories) {
		int sum = 0;

		for (int cal : inv) {
			sum += cal;
		}

		sums.push_back(sum);
	}

	sort(sums.begin(), sums.end(), greater <>());

	cout << sums[0] + sums[1] + sums[2];
}