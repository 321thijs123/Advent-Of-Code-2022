#include "day12-part1.h"

#include "../readers.h"

#include <iostream>
#include <vector>

using namespace std;

day12P1::Planner::Planner(vector<vector<int>> map_, int row, int col) {
	map = map_;
	costmap = vector<vector<int>>(map.size(), vector<int>(map[0].size(), INT_MAX));
	costmap[row][col] = 0;
	explore(row, col);
}

int day12P1::Planner::getCost(int row, int col) {
	return costmap[row][col];
}

// I was original so did not use dijkstra
void day12P1::Planner::explore(int row, int col) {
	vector<vector<bool>> update(map.size(), vector<bool>(map[0].size(), false));
	update[row][col] = true;				// Tells from which positions should be explored from next

	bool done = false;

	const int dirR[] = { -1, 1, 0, 0 };		// Just two arrays to easily look in all directions
	const int dirC[] = { 0, 0, -1, 1 };		// without writing the same code four times

	while (!done) {
		done = true;

		for (row = 0; row < map.size(); row++) {						// Loop through all rows
			for (col = 0; col < map[0].size(); col++) {						// Loop through all columns
				if (update[row][col]) {											// If this position should be explored from								
					update[row][col] = false;										// We are updating it now so we can set it to false

					for (int i = 0; i < 4; i++) {										// Loop 4 times for left, right, up, down
						const int tr = row + dirR[i];										// Row of target we are looking at
						const int tc = col + dirC[i];										// Column of target we are looking at
						if (tr >= 0 && tr < map.size() && tc >= 0 && tc < map[0].size()) {	// Check that its not outside the map
							if (map[tr][tc] <= map[row][col] + 1) {								// Check if its max one up
								const int cost = costmap[row][col] + 1;								// The cost of going there is cost of where we are now +1

								if (cost < costmap[tr][tc]) {										// If that cost is lower than the cheapest route we found there
									costmap[tr][tc] = cost;												// Set the cost to the lower cost we found now
									update[tr][tc] = true;												// Mark this position to be updated in the next
									done = false;														// We are not done yet because this opened up potential cheaper routes
								}
							}
						}
					}
				}
			}
		}
	}
}

void day12P1::assignment(string filename) {
	vector<vector<int>> map = readDigitMatrix(filename, 0);

	int startRow, startCol, targetRow, targetCol;

	for (int row = 0; row < map.size(); row++) {
		for (int col = 0; col < map[0].size(); col++) {
			switch (map[row][col]) {
			case 'S':
				map[row][col] = 'a';

				startRow = row;
				startCol = col;

				break;
			case 'E':
				map[row][col] = 'z';

				targetRow = row;
				targetCol = col;

				break;
			}
		}
	}

	day12P1::Planner planner(map, startRow, startCol);

	int cost = planner.getCost(targetRow, targetCol);

	vector<vector<char>> path(map.size(), vector<char>(map[0].size(), '.'));

	int row = targetRow;
	int col = targetCol;

	path[targetRow][targetCol] = 'E';
	path[startRow][startCol] = 'S';
	
	for (int i = 0; i < cost; i++) {
		const int target = planner.getCost(row, col) - 1;

		if (row - 1 > 0 && planner.getCost(row - 1, col) == target){
			path[--row][col] = 'v';
			continue;
		}

		if (row + 1 < map.size() && planner.getCost(row + 1, col) == target) {
			path[++row][col] = '^';
			continue;
		}

		if (col - 1 > 0 && planner.getCost(row, col - 1) == target) {
			path[row][--col] = '>';
			continue;
		}

		if (col + 1 < map[0].size() && planner.getCost(row, col + 1) == target) {
			path[row][++col] = '<';
			continue;
		}
	}

	for (vector<char> row : path) {
		for (char c : row) {
			cout << c;
		}
		cout << '\n';
	}

	cout << "\nSteps: " << cost << '\n';
}