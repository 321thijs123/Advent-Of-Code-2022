#include "day22-part1.h"

#include <fstream>
#include <vector>
#include <string>
#include <iostream>

void day22P1::assignment(string filename) {

	ifstream file(filename);
	string line;

	// Read map
	vector<string> map;
	int maxWidth = 0;

	while (getline(file, line) && line != "") {
		map.push_back(line);

		if (line.size() > maxWidth) maxWidth = line.size();
	}

	// Make map rows same length
	for (string& row : map) {
		while (row.size() < maxWidth) {
			row.push_back(' ');
		}
	}

	// Read movements
	getline(file, line);

	string numStr = "";

	vector<int> distances;
	vector<char> turns;

	for (const char c : line) {
		if (c >= '0' && c <= '9') {
			numStr.push_back(c);
		}
		else {
			turns.push_back(c);

			if (numStr.size() > 0) {
				distances.push_back(stoi(numStr));
				numStr = "";
			}
		}
	}

	// Starting position and orientation
	int y = 0;
	int x = map[0].find('.');
	char dir = '>';

	// Walk, turn, repeat
	for (int i = 0; i < turns.size(); i++) {
		walk(map, x, y, dir, distances[i]);

		switch (dir) {
		case '>':	dir = turns[i] == 'R' ? 'v' : '^';	break;
		case 'v':	dir = turns[i] == 'R' ? '<' : '>';	break;
		case '<':	dir = turns[i] == 'R' ? '^' : 'v';	break;
		case '^':	dir = turns[i] == 'R' ? '>' : '<';	break;
		}
	}

	// Last remaining walking section
	walk(map, x, y, dir, distances.back());

	// Display traversed path
	for (string row : map) {
		cout << row << '\n';
	}

	// Calculate resulting password
	int result;

	switch (dir) {
	case '>':
		result = 1000 * (y + 1) + 4 * (x + 1) + 0;
		break;
	case 'v':
		result = 1000 * (y + 1) + 4 * (x + 1) + 1;
		break;
	case '<':
		result = 1000 * (y + 1) + 4 * (x + 1) + 2;
		break;
	case '^':
		result = 1000 * (y + 1) + 4 * (x + 1) + 3;
		break;
	}

	cout << "Final password: " << result << '\n';
}

void day22P1::walk(vector<string>& map, int& x, int& y, const char dir, const int steps) {
	if (dir == '>') {
		for (int step = 0; step < steps; step++) {
			map[y][x] = dir;

			int newX = x + 1;

			if (newX >= map[y].size() || map[y][newX] == ' ') {
				newX = 0;
				while (map[y][newX] == ' ') newX++;
			}

			if (map[y][newX] == '#') return;

			x = newX;
		}
	}
	if (dir == '<') {
		for (int step = 0; step < steps; step++) {
			map[y][x] = dir;

			int newX = x - 1;

			if (newX < 0 || map[y][newX] == ' ') {
				newX = map[y].size() - 1;
				while (map[y][newX] == ' ') newX--;
			}

			if (map[y][newX] == '#') return;

			x = newX;
		}
		
	}
	if (dir == '^') {
		for (int step = 0; step < steps; step++) {
			map[y][x] = dir;

			int newY = y - 1;

			if (newY < 0 || map[newY][x] == ' ') {
				newY = map.size() - 1;
				while (map[newY][x] == ' ') newY--;
			}

			if (map[newY][x] == '#') return;

			y = newY;
		}
	}
	if (dir == 'v') {
		for (int step = 0; step < steps; step++) {
			map[y][x] = dir;

			int newY = y + 1;

			if (newY >= map.size() || map[newY][x] == ' ') {
				newY = 0;
				while (map[newY][x] == ' ') newY++;
				cout << "Fixed it\n";
			}

			if (map[newY][x] == '#') return;

			y = newY;
		}
	}
}
