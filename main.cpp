#include <iostream>

#include "day1/day1-part1.h"
#include "day1/day1-part2.h"
#include "day2/day2-part1.h"
#include "day2/day2-part2.h"
#include "day3/day3-part1.h"
#include "day3/day3-part2.h"

//#define choiceOverride 32;

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
		case 21:	Day2P1("day2/input.txt");	break;	// Day 2 part 1
		case 22:	Day2P2("day2/input.txt");	break;	// Day 2 part 2
		case 31:	Day3P1("day3/input.txt");	break;	// Day 3 part 1
		case 32:	Day3P2("day3/input.txt");	break;	// Day 3 part 2
		default:	cout << "This day does not exist (yet)";
	}

	return 0;
}