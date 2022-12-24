#include "day23-part2.h" 

#include <vector>
#include <fstream>
#include <iostream>

void day23P2::assignment(string filename) {
	vector<vector<Elf>> elves;

	int padding = 100;

	ifstream file(filename);

	string line;

	while (getline(file, line)) {
		vector<Elf> row;

		for (int i = 0; i < padding; i++) row.push_back(Elf());

		for (char c : line) {
			Elf elf;

			if (c == '#') elf.isElf = true;

			row.push_back(elf);
		}

		for (int i = 0; i < padding; i++) row.push_back(Elf());

		elves.push_back(row);
	}

	for (int i = 0; i < padding; i++) {
		elves.push_back(vector<Elf>(elves[0].size()));
		elves.insert(elves.begin(), vector<Elf>(elves[0].size()));
	}

	vector<Direction> proposalOrder = { N, S, W, E };

	bool allDone = false;

	int round = 0;

	while (!allDone) {
		round++;

		vector<vector<int>> proposalCount(elves.size(),  vector<int>(elves[0].size(), 0));

		allDone = true;

		for (int row = 0; row < elves.size(); row++) {
			for (int col = 0; col < elves[0].size(); col++) {
				if (elves[row][col].isElf) {
					for (Direction direction : proposalOrder) {
						elves[row][col].proposal = stay;

						bool proposed = false;

						if (!(elves[row - 1][col - 1].isElf || elves[row - 1][col].isElf ||
							elves[row - 1][col + 1].isElf || elves[row][col + 1].isElf ||
							elves[row + 1][col + 1].isElf || elves[row + 1][col].isElf ||
							elves[row + 1][col - 1].isElf || elves[row][col - 1].isElf))
							break;

						switch (direction) {
						case N:
							if (!(elves[row - 1][col - 1].isElf || elves[row - 1][col].isElf || elves[row - 1][col + 1].isElf)) {
								elves[row][col].proposal = direction;
								proposalCount[row - 1][col]++;
								proposed = true;
								allDone = false;
								break;
							}
							break;
						case S:
							if (!(elves[row + 1][col - 1].isElf || elves[row + 1][col].isElf || elves[row + 1][col + 1].isElf)) {
								elves[row][col].proposal = direction;
								proposalCount[row + 1][col]++;
								proposed = true;
								allDone = false;
								break;
							}
							break;
						case W:
							if (!(elves[row - 1][col - 1].isElf || elves[row][col - 1].isElf || elves[row + 1][col - 1].isElf)) {
								elves[row][col].proposal = direction;
								proposalCount[row][col - 1]++;
								proposed = true;
								allDone = false;
								break;
							}
							break;
						case E:
							if (!(elves[row - 1][col + 1].isElf || elves[row][col + 1].isElf || elves[row + 1][col + 1].isElf)) {
								elves[row][col].proposal = direction;
								proposalCount[row][col + 1]++;
								proposed = true;
								allDone = false;
								break;
							}
						}

						if (proposed) break;
					}
				}
			}
		}

		for (int row = 0; row < elves.size(); row++) {
			for (int col = 0; col < elves[0].size(); col++) {
				if (elves[row][col].isElf && elves[row][col].proposal != stay) {
					int dRow = 0;
					int dCol = 0;

					switch (elves[row][col].proposal) {
					case N: dRow = -1;	break;
					case S: dRow = 1;	break;
					case W: dCol = -1;	break;
					case E: dCol = 1;	break;
					}

					if (proposalCount[row + dRow][col + dCol] == 1) {
						elves[row + dRow][col + dCol].isElf = true;
						elves[row + dRow][col + dCol].proposal = stay;
						elves[row][col].isElf = false;
					}
				}
			}
		}


		proposalOrder.push_back(proposalOrder[0]);
		proposalOrder.erase(proposalOrder.begin());
	}

	for (vector<Elf> row : elves) {
		for (Elf elf : row) {
			cout << (elf.isElf ? '#' : '.');
		}
		cout << '\n';
	}

	cout << "Done after round " << round;
}
