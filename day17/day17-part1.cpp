#include "day17-part1.h"

#include <fstream>
#include <iostream>

void day17P1::assignment(string filename) {
	ifstream file(filename);
	string jets;
	getline(file, jets);

	vector<vector<vector<char>>> rocks = {
		{	
			{'#','#','#','#'}	
		},

		{	
			{'.','#','.'},
			{'#','#','#'},
			{'.','#','.'}
		},
		{	
			{'.','.','#'},
			{'.','.','#'},
			{'#','#','#'}
		},

		{
			{'#'},
			{'#'},
			{'#'},
			{'#'}
		},

		{
			{'#','#'},
			{'#','#'}		}
		};

	// Generate empty map
	const int width = 7;
	const int height = 5;

	vector<char> mapRow(width+2, '.');
	mapRow[0] = '|';
	mapRow[width + 1] = '|';
	vector<vector<char>> map(height,mapRow);
	map[height - 1] = vector<char>(width+2, '-');
	map[height - 1][0] = '+';
	map[height - 1][width + 1] = '+';

	// Height of heighest rock
	int minY = height - 1;

	int jetIndex = 0;

	for (int i = 0; i < 2022; i++) {
		// Select current rock
		const vector<vector<char>> rock = rocks[i % rocks.size()];

		// Starting location of next rock
		int x = 3;
		int y = minY - 3 - rock.size();

		// Grow map height to fit new rock
		while (y < 0) {
			y++;
			minY++;
			map.insert(map.begin(), mapRow);
		}

		while (true) {
			//drawMap(map, rock, x, y);

			const char jet = jets[jetIndex];

			jetIndex++;
			if (jetIndex >= jets.size()) jetIndex = 0;

			// Move according to jet
			if (jet == '<' && !checkCollision(x - 1, y, rock, map)) {
				x--;
			}
			else if (jet == '>' && !checkCollision(x + 1, y, rock, map)) {
				x++;
			}

			// Move down
			if (!checkCollision(x, y + 1, rock, map)) {
				y++;
			}
			else {
				if (y < minY) minY = y;
				break;
			}
		}

		// Add rock to map
		for (int rx = 0; rx < rock[0].size(); rx++) {
			for (int ry = 0; ry < rock.size(); ry++) {
				if (rock[ry][rx] == '#') {
					map[y + ry][x + rx] = '#';
				}
			}
		}
	}

	cout << '\n';
	for (const vector<char> row : map) {
		for (const char c : row) {
			cout << c;
		}
		cout << '\n';
	}
	cout << "Height: " << map.size()-minY-1 << '\n';
}

bool day17P1::checkCollision(const int x, const int y, const vector<vector<char>> rock, const vector<vector<char>> map) {
	for (int rx = 0; rx < rock[0].size(); rx++) {
		for (int ry = 0; ry < rock.size(); ry++) {
			if (rock[ry][rx] == '#' && map[y+ry][x+rx] != '.') {
				return true;
			}
		}
	}

	return false;
}

void day17P1::drawMap(vector<vector<char>> map, vector<vector<char>> rock, int x, int y) {
	// Add temporary rock to map
	for (int rx = 0; rx < rock[0].size(); rx++) {
		for (int ry = 0; ry < rock.size(); ry++) {
			if (rock[ry][rx] == '#') {
				map[y + ry][x + rx] = '@';
			}
		}
	}

	cout << '\n';

	// Output map
	for (const vector<char> row : map) {
		for (const char c : row) {
			cout << c;
		}
		cout << '\n';
	}
}
