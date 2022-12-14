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
#include "day12/day12-part1.h"
#include "day12/day12-part2.h"
#include "day13/day13-part1.h"
#include "day13/day13-part2.h"
#include "day14/day14-part1.h"
#include "day14/day14-part2.h"
#include "day15/day15-part1.h"
#include "day15/day15-part2.h"
#include "day17/day17-part1.h"
#include "day17/day17-part2.h"
#include "day18/day18-part1.h"
#include "day18/day18-part2.h"
#include "day20/day20-part1.h"
#include "day20/day20-part2.h"
#include "day21/day21-part1.h"
#include "day21/day21-part2.h"
#include "day22/day22-part1.h"
#include "day22/day22-part2.h"
#include "day23/day23-part1.h"
#include "day23/day23-part2.h"

//#define choiceOverride 222;

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
		case 121:	day12P1::assignment("day12/input.txt");	break;	// Day 12 part 1
		case 122:	day12P2::assignment("day12/input.txt");	break;	// Day 12 part 2
		case 131:	day13P1::assignment("day13/input.txt");	break;	// Day 13 part 1
		case 132:	day13P2::assignment("day13/input.txt");	break;	// Day 13 part 2
		case 141:	day14P1::assignment("day14/input.txt");	break;	// Day 14 part 1
		case 142:	day14P2::assignment("day14/input.txt");	break;	// Day 14 part 2
		case 151:	day15P1::assignment("day15/input.txt");	break;	// Day 15 part 1
		case 152:	day15P2::assignment("day15/input.txt");	break;	// Day 15 part 2
		case 171:	day17P1::assignment("day17/input.txt");	break;	// Day 17 part 1
		case 172:	day17P2::assignment("day17/input.txt");	break;	// Day 17 part 2
		case 181:	day18P1::assignment("day18/input.txt");	break;	// Day 18 part 1
		case 182:	day18P2::assignment("day18/input.txt");	break;	// Day 18 part 2
		case 201:	day20P1::assignment("day20/input.txt"); break;	// Day 20 part 1
		case 202:	day20P2::assignment("day20/input.txt"); break;	// Day 20 part 2
		case 211:	day21P1::assignment("day21/input.txt"); break;	// Day 21 part 1
		case 212:	day21P2::assignment("day21/input.txt"); break;	// Day 21 part 2
		case 221:	day22P1::assignment("day22/input.txt"); break;	// Day 22 part 1
		case 222:	day22P2::assignment("day22/input.txt"); break;	// Day 22 part 2
		case 231:	day23P1::assignment("day23/input.txt"); break;	// Day 23 part 1
		case 232:	day23P2::assignment("day23/input.txt"); break;	// Day 23 part 2
		default:	cout << "This day does not exist (yet)";
	}

	return 0;
}
