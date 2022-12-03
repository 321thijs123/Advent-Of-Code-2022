#include "day2-part1.h"

#include "../readers.h"

#include <iostream>

using namespace std;

Day2P1::Day2P1(string filename) {
	vector<string> rounds = readStringList(filename);

	int score = 0;

	for (string round : rounds) {
		score += getScore(round);
	}

	cout << "Score: " << score << "\n";
}

int Day2P1::getScore(string round) {
	switch (round[0]) {
	case 'A':		// Oponent chose rock
		switch (round[2]) {
			case 'X': return 1+3;	// You chose rock
			case 'Y': return 2+6;	// You chose paper
			case 'Z': return 3+0;	// You chose scissors
		}
	case 'B':		// Opponent chose paper
		switch (round[2]) {
			case 'X': return 1+0;	// You chose rock
			case 'Y': return 2+3;	// You chose paper
			case 'Z': return 3+6;	// You chose scissors
		}
	case 'C':		// Opponent chose scissors
		switch (round[2]) {
			case 'X': return 1+6;	// You chose rock
			case 'Y': return 2+0;	// You chose paper
			case 'Z': return 3+3;	// You chose scissors
		}
	}

	return -1;
}