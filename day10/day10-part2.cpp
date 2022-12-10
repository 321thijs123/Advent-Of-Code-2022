#include "day10-part2.h"

#include "../readers.h"

#include <iostream>

using namespace std;

Day10P2::Day10P2(string filename) {
	vector<string> program = readStringList(filename);

	int programCounter = 0;
	int stackSize = 0;

	int X = 1;

	vector<bool> scanLine(40, false);

	cout << "#";

	for (int cycle = 1; cycle < 240; cycle++) {
		const int scanPos = cycle % 40;

		if (scanPos == 0) {
			cout << '\n';
		}

		scanLine[scanPos] = scanPos == X - 1 || scanPos == X || scanPos == X + 1;

		cout << (scanLine[scanPos] ? '#' : '.');

		stackSize--;
		
		if (stackSize <= 0) {
			const string cmd = program[programCounter];

			if (cmd[0] == 'a') {
				X += stoi(cmd.substr(5, cmd.size() - 5));
			}

			programCounter++;

			if (cmd[0] == 'a') {
				stackSize = 2;
			}
			else if (cmd[0] == 'n') {
				stackSize = 1;
			}
		}
	}

	cout << '\n';
}
