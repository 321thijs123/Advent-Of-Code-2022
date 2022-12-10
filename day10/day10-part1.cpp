#include "day10-part1.h"

#include "../readers.h"

#include <iostream>

using namespace std;

Day10P1::Day10P1(string filename) {
	vector<string> program = readStringList(filename);

	int line = 0;
	int stackSize = 0;

	int reg = 1;

	int strengthSum = 0;

	for (int cycle = 2; cycle <= 220; cycle++) {
		if (cycle % 40 == 20) {
			int strength = cycle * reg;

			cout << "Cycle " << cycle << ": " << strength << '\n';

			strengthSum += strength;
		}

		stackSize--;
		
		if (stackSize <= 0) {
			const string cmd = program[line];

			if (cmd[0] == 'a') {
				reg += stoi(cmd.substr(5, cmd.size() - 5));
			}

			line++;

			if (cmd[0] == 'a') {
				stackSize = 2;
			}
			else if (cmd[0] == 'n') {
				stackSize = 1;
			}
		}
	}

	cout << "\nSum of signal strengths: " << strengthSum << '\n';
}
