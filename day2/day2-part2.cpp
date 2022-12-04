#include "day2-part2.h"

#include "../readers.h"

#include <iostream>

using namespace std;

Day2P2::Day2P2(string filename) {
	vector<string> rounds = readStringList(filename);

	int score = 0;

	for (string round : rounds) {
		score += getScore(round);
	}

	cout << "Score: " << score << "\n";
}

int Day2P2::getScore(string round) {
	switch (round[0]) {
	case 'A':		// Oponent chose rock
		switch (round[2]) {
			case 'X': return 0+3;	// Need to lose, choose scissors
			case 'Y': return 3+1;	// Need to draw, choose rock
			case 'Z': return 6+2;	// Need to win,  choose paper
		}
	case 'B':		// Opponent chose paper
		switch (round[2]) {
			case 'X': return 0+1;	// Need to lose, choose rock
			case 'Y': return 3+2;	// Need to draw, choose paper
			case 'Z': return 6+3;	// Need to win,  choose scissors
		}
	case 'C':		// Opponent chose scissors
		switch (round[2]) {
			case 'X': return 0+2;	// Need to lose, choose paper
			case 'Y': return 3+3;	// Need to draw, choose scissors
			case 'Z': return 6+1;	// Need to win,  choose rock
		}
	}

	return -1;
}
