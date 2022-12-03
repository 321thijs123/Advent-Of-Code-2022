#include <iostream>

#include "day1/day1-part1.h"
#include "day1/day1-part2.h"

//#define choiceOverride 12;

using namespace std;

int main() {
	int choice;

	#ifdef choiceOverride
		choice = choiceOverride;
	#else
		cout << "Please select a day and assignment\n";
		cin >> choice;
	#endif

	switch (choice) {
		case 11:	Day1P1("day1/input.txt");	break;	// Day 1 part 1
		case 12:	Day1P2("day1/input.txt");	break;	// Day 1 part 2
		default:	cout << "This day does not exist (yet)";
	}

	return 0;
}