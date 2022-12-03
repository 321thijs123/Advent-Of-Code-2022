#include "day3-part2.h"

#include "../readers.h"

#include <iostream>

using namespace std;

Day3P2::Day3P2(string filename) {
	vector<string> rucksacks = readStringList(filename);

	int prioritySum = 0;

	for (int i = 0; i < rucksacks.size(); i+=3) {
		prioritySum += getPriority(findCommon(rucksacks[i], rucksacks[i+1], rucksacks[i+2]));
	}

	cout << "\nSum of priorities: " << prioritySum << "\n";
}

char Day3P2::findCommon(string a, string b,string c) {
	for (char item : a) {
		if (b.find(item) != string::npos && c.find(item) != string::npos) {
			return item;
		}
	}
}

int Day3P2::getPriority(char item) {
	if (item <= 'Z') {	// Uppercase
		return item - 'A' + 27;
	}
	
	// Lowercase
	return item - 'a' + 1;
}