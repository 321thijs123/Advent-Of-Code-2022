#include "day17-part2.h"

#include "../readers.h";

#include <iostream>

void day17P2::assignment(string filename) {
	vector<string> input = readStringList(filename);
	const string jets = input[0];

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
	int rockIndex = 0;

	int x = 3;

	bool repeated = false;

	// Pattern finding variables
	int currentN = 0;				// Amount of rocks since last detection
	int currentH = getHeight(map);	// Height of stack since last detection

	int patternN = 0;				// Amount of rocks in patern
	int patternH = 0;				// Height of pattern

	int initialN = 0;				// Amount of rocks before pattern starts
	int initialH = 0;				// Height of stack before pattern starts 

	cout << "Looking for pattern\n";

	const int targetJetIndex = 1;	// Which jet to look at for pattern detection

	while (!repeated) {
		if (jetIndex == targetJetIndex) {
			currentH = getHeight(map) - currentH;
			cout << "-------------------\n"
				<< "Fallen rocks:   " << currentN << '\n'
				<< "Pattern Height: " << currentH << '\n'
				<< "Last rest x:    " << x << '\n'
				<< "Last rock:      " << rockIndex << '\n';

			if (patternN == currentN && patternH == currentH) {
				repeated = true;
			}
			else {
				initialH = patternH;
				initialN = patternN;
				patternN = currentN;
				patternH = currentH;
			}

			currentN = 0;
			currentH = getHeight(map);
		}

		if (repeated) break;

		currentN++;

		// Select current rock
		const vector<vector<char>> rock = rocks[rockIndex];

		rockIndex++;
		if (rockIndex >= rocks.size()) rockIndex = 0;

		// Starting location of next rock
		x = 3;
		int y = minY - 3 - rock.size();

		growMap(map, y, minY, mapRow);

		moveRock(map, rock, jets, jetIndex, x, y);
		if (y < minY) minY = y;

		addRock(map, rock, x, y);
	}

	int endN = (1000000000000 - (long long)initialN) % (long long)patternN;
	long long repitition = (1000000000000 - (long long)initialN) / (long long)patternN;

	cout << "\nApperant pattern: \n"
		<< " Starts rocks:   " << initialN << '\n'
		<< " Starts height:  " << initialH << '\n'
		<< " Pattern rocks:  " << patternN << '\n'
		<< " Pattern height: " << patternH << '\n'
		<< " Repitition:     " << repitition << '\n'
		<< " End rocks:      " << endN << '\n';

	int beforeEndH = getHeight(map);

	for (int N = 0; N < endN; N++) {
		// Select current rock
		const vector<vector<char>> rock = rocks[rockIndex];

		rockIndex++;
		if (rockIndex >= rocks.size()) rockIndex = 0;

		// Starting location of next rock
		x = 3;
		int y = minY - 3 - rock.size();
		
		// Make map fit next rock
		growMap(map, y, minY, mapRow);

		// Move rock till it stops
		moveRock(map, rock, jets, jetIndex, x, y);
		if (y < minY) minY = y;

		// Add the stopped rock to the map
		addRock(map, rock, x, y);
	}

	int endH = getHeight(map) - beforeEndH;
	cout << " End height:     " << endH << '\n';

	cout << "\nTotal height: " << (long long)initialH + repitition * (long long)patternH + (long long)endH << '\n';
}

bool day17P2::checkCollision(const int x, const int y, const vector<vector<char>> rock, const vector<vector<char>> map) {
	for (int rx = 0; rx < rock[0].size(); rx++) {
		for (int ry = 0; ry < rock.size(); ry++) {
			if (rock[ry][rx] == '#' && map[y+ry][x+rx] != '.') {
				return true;
			}
		}
	}

	return false;
}

void day17P2::drawMap(vector<vector<char>> map, vector<vector<char>> rock, int x, int y) {
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

int day17P2::getHeight(vector<vector<char>> map) {
	for (int i = 0; i < map.size(); i++) {
		for (char c : map[i]) {
			if (c == '#') {
				return map.size() - i - 1;
			}
		}
	}
}

void day17P2::moveRock(vector<vector<char>> map, vector<vector<char>> rock, const string jets, int& jetIndex, int& x, int& y) {
	while (true) {
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
			return;
		}
	}
}

void day17P2::addRock(vector<vector<char>>& map, const vector<vector<char>> rock, const int x, const int y) {
	for (int rx = 0; rx < rock[0].size(); rx++) {
		for (int ry = 0; ry < rock.size(); ry++) {
			if (rock[ry][rx] == '#') {
				map[y + ry][x + rx] = '#';
			}
		}
	}
}

void day17P2::growMap(vector<vector<char>>& map, int& y, int& minY, const vector<char> mapRow) {
	while (y < 0) {
		y++;
		minY++;
		map.insert(map.begin(), mapRow);
	}
}
