#include "day14-part2.h"

#include "../readers.h"

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

void day14P2::assignment(string filename) {
	vector<vector<int>> scan = readIntMatrix(filename);

	// Find boundaries of rock map
	int xMin = 500;
	int xMax = 500;
	int yMin = 0;
	int yMax = 0;

	for (vector<int>& path : scan) {
		for (int i = 0; i < path.size()-1; i += 2) {
			if (path[i] < xMin)		xMin = path[i];
			if (path[i] > xMax)		xMax = path[i];
			if (path[i + 1] < yMin)	yMin = path[i + 1];
			if (path[i + 1] > yMax)	yMax = path[i + 1];
		}
	}

	// Expand boundaries to accomodate for floor at ymax + 2
	yMax += 2;

	// Expand boundaries to fit maximum possible sand hill width
	const int sandReach = yMax - yMin;

	if (xMin > 500 - sandReach) xMin = 500 - sandReach;
	if (xMax < 500 + sandReach) xMax = 500 + sandReach;

	// Create a cave with the scanned rocks
	vector<vector<char>> cave(yMax-yMin+1, vector<char>(xMax-xMin+1, '.'));

	for (vector<int>& path : scan) {
		for (int i = 0; i < path.size() - 3; i += 2) {
			addLine(path[i] - xMin, path[i + 1] - yMin, path[i + 2] - xMin, path[i + 3] - yMin, cave);
		}
	}

	addLine(0, yMax-yMin, xMax - xMin, yMax - yMin, cave);

	cave[0 - yMin][500 - xMin] = '+';

	// Simulate falling sand
	bool blocked = false;

	int units = 0;

	while (!blocked) {
		int sandX = 500 - xMin;
		int sandY = 0 - yMin;

		bool moving = true;

		while (moving) {
			if (cave[sandY + 1][sandX] == '.') {
				sandY++;
			}
			else if (cave[sandY + 1][sandX - 1] == '.') {
				sandX--;
				sandY++;
			}
			else if (cave[sandY + 1][sandX + 1] == '.') {
				sandX++;
				sandY++;
			}
			else {
				moving = false;
			}
		}

		if (cave[sandY][sandX] == 'O') {
			blocked = true;
		}
		else {
			units++;
			cave[sandY][sandX] = 'O';
		}
	}

	cout << "\n--- Result ----\n";

	showCave(cave);

	cout << units << " units of sand have come to rest.\n";
}

void day14P2::addLine(int x1, int y1, int x2, int y2, vector<vector<char>>& cave) {
	int dX = x2 - x1;
	int dY = y2 - y1;

	if (dX != 0) dX = dX / abs(dX);
	if (dY != 0) dY = dY / abs(dY);

	int x = x1;
	int y = y1;

	while (x != x2 || y != y2) {
		cave[y][x] = '#';

		x += dX;
		y += dY;
	}

	cave[y][x] = '#';
}

void day14P2::showCave(vector<vector<char>>& cave) {
	for (vector<char> row : cave) {
		for (char c : row) {
			cout << c;
		}
		cout << '\n';
	}
}
