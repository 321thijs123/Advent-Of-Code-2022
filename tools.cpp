#include "tools.h"
#include <iostream>

vector<int> getInts(string str) {

	int i = 0;

	while (str[i] < '0' || str[i] > '9') {
		i++;

		if (i > str.size())
			return vector<int>();
	}

	string curNum;

	vector<int> ints;

	while (i < str.size()) {
		if (str[i] >= '0' && str[i] <= '9') {
			curNum.push_back(str[i]);
		}
		else {
			if (curNum.size() > 0) {
				ints.push_back(stoi(curNum));
			}
			curNum = "";
		}

		i++;
	}

	ints.push_back(stoi(curNum));

	return ints;
}