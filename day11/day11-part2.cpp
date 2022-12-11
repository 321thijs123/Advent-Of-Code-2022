#include "day11-part2.h"

#include <fstream>
#include <vector>

#include "../tools.h"

using namespace std;

Day11P2::Day11P2(string filename) {
	ifstream file(filename);

	string line;

	vector<Monkey> monkeys;

	while (getline(file, line)) {
		if (line[0] == 'M') {			// Monkey X
			Monkey monkey;

			getline(file, line);		// Starting items
			vector<int> intItems = getInts(line);
			monkey.items = vector<long long>(intItems.begin(), intItems.end());

			getline(file, line);		// Operation
			monkey.operation = line[23];
			monkey.twoOlds = line[25] == 'o';

			if (!monkey.twoOlds) {
				monkey.operand = stoi(line.substr(25, line.size() - 25));
			}

			getline(file, line);		// Test
			monkey.test = getInts(line)[0];

			getline(file, line);		// If true
			monkey.targetA = getInts(line)[0];

			getline(file, line);		// If false
			monkey.targetB = getInts(line)[0];

			monkeys.push_back(monkey);
		}
	}

	long long stressDivider = 1;

	for (Monkey& monkey : monkeys) {
		stressDivider *= monkey.test;
	}

	for (int round = 0; round < 10000; round++) {
		for (Monkey& monkey : monkeys) {
			monkey.give(monkeys, stressDivider);
		}

		int i = 0;
	}

	int i = 0;

	long long most1 = 0;
	long long most2 = 0;

	for (Monkey& monkey : monkeys) {
		cout << "Monkey " << i << " inspected items " << monkey.inspections << " times.\n";

		if (monkey.inspections > most1){
			most2 = most1;
			most1 = monkey.inspections;
		}

		i++;
	}

	cout << "\nLevel of monkey business: " << most1 * most2 << "\n";
}

void Day11P2::Monkey::receive(int value) {
	items.push_back(value);
}

void Day11P2::Monkey::give(vector<Monkey>& monkeys, int stressDivider) {
	while (items.size() > 0) {
		inspections++;

		if (twoOlds) {
			switch (operation) {
			case '*':
				items[0] *= items[0];
				break;
			case '+':
				items[0] += items[0];
				break;
			}
		}
		else {
			switch (operation) {
			case '*':
				items[0] *= operand;
				break;
			case '+':
				items[0] += operand;
				break;
			}
		}

		if (items[0] % test == 0) {
			monkeys[targetA].receive(items[0] % stressDivider);
		}
		else {
			monkeys[targetB].receive(items[0] % stressDivider);
		}

		items.erase(items.begin());
	}
}
