#include "day14-part1.h"

#include "../readers.h"

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

void day14P1::assignment(string filename) {
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

	// Expand boundaries with one air space
	xMin--;
	xMax++;
	yMin--;
	yMax++;

	// Create a cave with the scanned rocks
	vector<vector<char>> cave(yMax-yMin+1, vector<char>(xMax-xMin+1, '.'));

	for (vector<int>& path : scan) {
		for (int i = 0; i < path.size() - 3; i += 2) {
			addLine(path[i] - xMin, path[i + 1] - yMin, path[i + 2] - xMin, path[i + 3] - yMin, cave);
		}
	}

	// Simulate falling sand
	bool inVoid = false;

	int units = 0;

	while (!inVoid) {
		int sandX = 500 - xMin;
		int sandY = 0 - yMin;;

		bool moving = true;

		while (moving) {
			if (sandY > yMax) {
				inVoid = true;
				break;
			}

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

		if (!inVoid) {
			units++;
			cave[sandY][sandX] = 'O';
		}
	}

	cout << "\n--- Result ----\n";

	showCave(cave);

	cout << units << " units of sand have come to rest.\n";
}

void day14P1::addLine(int x1, int y1, int x2, int y2, vector<vector<char>>& cave) {
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

void day14P1::showCave(vector<vector<char>>& cave) {
	for (vector<char> row : cave) {
		for (char c : row) {
			cout << c;
		}
		cout << '\n';
	}
}
