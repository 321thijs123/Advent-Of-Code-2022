#include "day8-part1.h"

#include "../readers.h"

#include <iostream>

using namespace std;

Day8P1::Day8P1(string filename) {
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

	vector<vector<bool>> visibilities(forestRows, vector<bool>(forestCols, false));

	for (int row = 0; row < forestRows; row++) {		// Look at rows
		int highest = -1;

		for (int col = 0; col < forestCols; col++) {		// Look left to right
			if (forest[row][col] > highest) {
				visibilities[row][col] = true;
				highest = forest[row][col];
			}
		}

		highest = -1;

		for (int col = forestCols - 1; col >= 0; col--) {	// Look right to left
			if (forest[row][col] > highest) {
				visibilities[row][col] = true;
				highest = forest[row][col];
			}
		}
	}

	for (int col = 0; col < forestCols; col++) {		// Look at columns
		int highest = -1;

		for (int row = 0; row < forestRows; row++) {		// Look top to bottom
			if (forest[row][col] > highest) {
				visibilities[row][col] = true;
				highest = forest[row][col];
			}
		}

		highest = -1;

		for (int row = forestRows - 1; row >= 0; row--) {	// Look bottom to top
			if (forest[row][col] > highest) {
				visibilities[row][col] = true;
				highest = forest[row][col];
			}
		}
	}

	cout << "\nVisibile trees:\n";

	int N = 0;

	for (vector<bool> row : visibilities) {
		for (bool visibility : row) {
			N += visibility;
			cout << visibility;
		}
		cout << '\n';
	}

	cout << '\n' << N << " trees are visible\n";
}
