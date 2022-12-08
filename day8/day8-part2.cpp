#include "day8-part2.h"

#include "../readers.h"

#include <iostream>

using namespace std;

Day8P2::Day8P2(string filename) {
	vector<vector<int>> forest = readDigitMatrix(filename);

	cout << "The forest:\n";

	for (vector<int> row : forest) {
		for (int tree : row) {
			cout << tree;
		}
		cout << '\n';
	}

	const int forestRows = forest.size();
	const int forestCols = forest[0].size();

	int maxScenery = 0;

	for (int row = 0; row < forestRows; row++) {
		for (int col = 0; col < forestCols; col++) {
			const int scenery = evaluateScenery(forest,row,col);
			if (scenery > maxScenery) maxScenery = scenery;
		}
	}

	cout << "\nMaximum scenery score: " << maxScenery << '\n';
}

int Day8P2::evaluateScenery(const vector<vector<int>> forest, const int posRow, const int posCol) {

	const int ownHeight = forest[posRow][posCol];

	int view = 0;
	int score = 1;

	for (int row = posRow + 1; row < forest.size(); row++) {
		if (forest[row][posCol] < ownHeight) {
			view++;
		}
		else {
			view++;
			break;
		}
	}

	score *= view;
	view = 0;

	for (int row = posRow - 1; row >= 0; row--) {
		if (forest[row][posCol] < ownHeight) {
			view++;
		}
		else {
			view++;
			break;
		}
	}

	score *= view;
	view = 0;

	for (int col = posCol + 1; col < forest[0].size(); col++) {
		if (forest[posRow][col] < ownHeight) {
			view++;
		}
		else {
			view++;
			break;
		}
	}

	score *= view;
	view = 0;

	for (int col = posCol - 1; col >= 0; col--) {
		if (forest[posRow][col] < ownHeight) {
			view++;
		}
		else {
			view++;
			break;
		}
	}

	score *= view;

	return score;
}
