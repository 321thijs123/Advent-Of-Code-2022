#include <iostream>

#include "day1/day1-part1.h"
#include "day1/day1-part2.h"
#include "day2/day2-part1.h"
#include "day2/day2-part2.h"
#include "day3/day3-part1.h"
#include "day3/day3-part2.h"
#include "day4/day4-part1.h"
#include "day4/day4-part2.h"
#include "day5/day5-part1.h"
#include "day5/day5-part2.h"
#include "day6/day6-part1.h"
#include "day6/day6-part2.h"
#include "day7/day7-part1.h"
#include "day7/day7-part2.h"
#include "day8/day8-part1.h"
#include "day8/day8-part2.h"
#include "day9/day9-part1.h"
#include "day9/day9-part2.h"
#include "day10/day10-part1.h"
#include "day10/day10-part2.h"
#include "day11/day11-part1.h"
#include "day11/day11-part2.h"

//#define choiceOverride 112;

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
		case 41:	Day4P1("day4/input.txt");	break;	// Day 4 part 1
		case 42:	Day4P2("day4/input.txt");	break;	// Day 4 part 2
		case 51:	Day5P1("day5/input.txt");	break;	// Day 5 part 1
		case 52:	Day5P2("day5/input.txt");	break;	// Day 5 part 2
		case 61:	Day6P1("day6/input.txt");	break;	// Day 6 part 1
		case 62:	Day6P2("day6/input.txt");	break;	// Day 6 part 2
		case 71:	Day7P1("day7/input.txt");	break;	// Day 7 part 1
		case 72:	Day7P2("day7/input.txt");	break;	// Day 7 part 2
		case 81:	Day8P1("day8/input.txt");	break;	// Day 8 part 1
		case 82:	Day8P2("day8/input.txt");	break;	// Day 8 part 2
		case 91:	Day9P1("day9/input.txt");	break;	// Day 9 part 1
		case 92:	Day9P2("day9/input.txt");	break;	// Day 9 part 2
		case 101:	Day10P1("day10/input.txt");	break;	// Day 10 part 1
		case 102:	Day10P2("day10/input.txt");	break;	// Day 10 part 2
		case 111:	Day11P1("day11/input.txt");	break;	// Day 11 part 1
		case 112:	Day11P2("day11/input.txt");	break;	// Day 11 part 2
		default:	cout << "This day does not exist (yet)";
	}

	return 0;
}
