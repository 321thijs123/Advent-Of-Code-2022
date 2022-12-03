#include "day3-part1.h"

#include "../readers.h"

#include <iostream>

using namespace std;

Day3P1::Day3P1(string filename) {
	vector<string> rucksacks = readStringList(filename);

	int prioritySum = 0;

	for (string rucksack : rucksacks) {
		const int compartmentSize = rucksack.size() / 2;

		string compartmentA = rucksack.substr(0, compartmentSize);
		string compartmentB = rucksack.substr(compartmentSize, compartmentSize);

		prioritySum += getPriority(findCommon(compartmentA, compartmentB));
	}

	cout << "\nSum of priorities: " << prioritySum << "\n";
}

char Day3P1::findCommon(string a, string b) {
	for (char c : a) {
		if (b.find(c) != string::npos) {
			return c;
		}
	}
}

int Day3P1::getPriority(char item) {
	if (item <= 'Z') {	// Uppercase
		return item - 'A' + 27;
	}
	
	// Lowercase
	return item - 'a' + 1;
}