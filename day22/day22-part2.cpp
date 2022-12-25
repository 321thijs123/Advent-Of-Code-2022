#include "day22-part2.h"

#include <fstream>
#include <vector>
#include <string>
#include <iostream>

void day22P2::assignment(string filename) {

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

	if (numStr.size() > 0) distances.push_back(stoi(numStr));	// Also need to add this to day 1

	// Starting position and orientation
	int y = 0;
	int x = map[0].find('.');
	char dir = '>';

	// Walk, turn, repeat
	for (int i = 0; i < turns.size(); i++) {
		walk(map, x, y, dir, distances[i]);

		switch (dir) {
		case '>':	dir = (turns[i] == 'R' ? 'v' : '^');	break;
		case 'v':	dir = (turns[i] == 'R' ? '<' : '>');	break;
		case '<':	dir = (turns[i] == 'R' ? '^' : 'v');	break;
		case '^':	dir = (turns[i] == 'R' ? '>' : '<');	break;
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

void day22P2::walk(vector<string>& map, int& x, int& y, char& dir, int steps) {
	while (steps > 0) {
		steps--;

		map[y][x] = dir;

		if (dir == '>') {

			int newX = x + 1;

			if (newX >= map[y].size() || map[y][newX] == ' ') {
				if (y < 50) {
					newX = 99;
					int newY = 149 - y;

					if (map[newY][newX] == '#') return;

					x = newX;
					y = newY;
					dir = '<';
					walk(map, x, y, dir, steps);
					map[y][x] = dir;
					return;
				}
				else if (y < 100) {
					newX = y + 50;
					int newY = 49;

					if (map[newY][newX] == '#') return;

					x = newX;
					y = newY;
					dir = '^';
					walk(map, x, y, dir, steps);
					map[y][x] = dir;
					return;
				}
				else if (y < 150) {
					newX = 149;
					int newY = 149 - y;

					if (map[newY][newX] == '#') return;

					x = newX;
					y = newY;
					dir = '<';
					walk(map, x, y, dir, steps);
					map[y][x] = dir;
					return;
				}
				else if (y < 200) {
					newX = y - 100;
					int newY = 149;

					if (map[newY][newX] == '#') return;

					x = newX;
					y = newY;
					dir = '^';
					walk(map, x, y, dir, steps);
					map[y][x] = dir;
					return;
				}
			}

			if (map[y][newX] == '#') return;

			x = newX;
		}
		if (dir == '<') {

			int newX = x - 1;

			if (newX < 0 || map[y][newX] == ' ') {
				if (y < 50) {
					newX = 0;
					int newY = 149 - y;

					if (map[newY][newX] == '#') return;

					x = newX;
					y = newY;
					dir = '>';
					walk(map, x, y, dir, steps);
					map[y][x] = dir;
					return;
				}
				else if (y < 100) {
					newX = y - 50;
					int newY = 100;

					if (map[newY][newX] == '#') return;

					x = newX;
					y = newY;
					dir = 'v';
					walk(map, x, y, dir, steps);
					map[y][x] = dir;
					return;
				}
				else if (y < 150) {
					newX = 50;
					int newY = 149 - y;

					if (map[newY][newX] == '#') return;

					x = newX;
					y = newY;
					dir = '>';
					walk(map, x, y, dir, steps);
					map[y][x] = dir;
					return;
				}
				else if (y < 200) {
					newX = y - 100;
					int newY = 0;

					if (map[newY][newX] == '#') return;

					x = newX;
					y = newY;
					dir = 'v';
					walk(map, x, y, dir, steps);
					map[y][x] = dir;
					return;
				}
			}

			if (map[y][newX] == '#') return;

			x = newX;
		}
		if (dir == '^') {

			int newY = y - 1;

			if (newY < 0 || map[newY][x] == ' ') {
				if (x < 50) {
					newY = x + 50;
					int newX = 50;

					if (map[newY][newX] == '#') return;

					x = newX;
					y = newY;
					dir = '>';
					walk(map, x, y, dir, steps);
					map[y][x] = dir;
					return;
				}
				else if (x < 100) {
					newY = x + 100;
					int newX = 0;

					if (map[newY][newX] == '#') return;

					x = newX;
					y = newY;
					dir = '>';
					walk(map, x, y, dir, steps);
					map[y][x] = dir;
					return;
				}
				else if (x < 150) {
					newY = 199;
					int newX = x - 100;

					if (map[newY][newX] == '#') return;

					x = newX;
					y = newY;
					dir = '^';
					walk(map, x, y, dir, steps);
					map[y][x] = dir;
					return;
				}
			}

			if (map[newY][x] == '#') return;

			y = newY;
		}
		if (dir == 'v') {

			int newY = y + 1;

			if (newY >= map.size() || map[newY][x] == ' ') {	// Still need to do
				if (x < 50) {
					newY = 0;
					int newX = x + 100;

					if (map[newY][newX] == '#') return;

					x = newX;
					y = newY;
					dir = 'v';
					walk(map, x, y, dir, steps);
					map[y][x] = dir;
					return;
				}
				else if (x < 100) {
					newY = x + 100;
					int newX = 49;

					if (map[newY][newX] == '#') return;

					x = newX;
					y = newY;
					dir = '<';
					walk(map, x, y, dir, steps);
					map[y][x] = dir;
					return;
				}
				else if (x < 150) {
					newY = x - 50;
					int newX = 99;

					if (map[newY][newX] == '#') return;

					x = newX;
					y = newY;
					dir = '<';
					walk(map, x, y, dir, steps);
					map[y][x] = dir;
					return;
				}
			}

			if (map[newY][x] == '#') return;

			y = newY;
		}

		map[y][x] = dir;
	}
}
