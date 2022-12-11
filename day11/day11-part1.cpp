#include "day11-part1.h"

#include <fstream>
#include <vector>

#include "../tools.h"

using namespace std;

Day11P1::Day11P1(string filename) {
	ifstream file(filename);

	string line;

	vector<Monkey> monkeys;

	while (getline(file, line)) {
		if (line[0] == 'M') {			// Monkey X
			Monkey monkey;

			getline(file, line);		// Starting items
			monkey.items = getInts(line);

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

	for (int round = 0; round < 20; round++) {
		int i = 0;

		for (Monkey& monkey : monkeys) {
			cout << "Monkey " << i << ":\n";

			monkey.give(monkeys);

			cout << '\n';

			i++;
		}

		i = 0;

		for (Monkey& monkey : monkeys) {
			cout << "Monkey " << i << ": ";
			for (int item : monkey.items) {
				cout << item << " ";
			}
			cout << '\n';

			i++;
		}
	}

	int i = 0;

	cout << '\n';

	int most1 = 0;
	int most2 = 0;

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

void Day11P1::Monkey::receive(int value) {
	items.push_back(value);
}

void Day11P1::Monkey::give(vector<Monkey>& monkeys) {
	while (items.size() > 0) {
		inspections++;

		cout << "  Monkey inspects an item with a worry level of " << items[0] << ".\n";
		if (twoOlds) {
			switch (operation) {
			case '*':
				items[0] *= items[0];
				cout << "    Worry level is multiplied by itself to " << items[0] << ".\n";
				break;
			case '+':
				items[0] += items[0];
				cout << "    Worry level increases by itself to " << items[0] << ".\n";
				break;
			}
		}
		else {
			switch (operation) {
			case '*':
				items[0] *= operand;
				cout << "    Worry level is multiplied by " << operand << " to " << items[0] << ".\n";
				break;
			case '+':
				items[0] += operand;
				cout << "    Worry level increases by " << operand << " to " << items[0] << ".\n";
				break;
			}
		}

		items[0] /= 3;

		cout << "    Monkey gets bored with item. Worry level is divided by 3 to " << items[0] << ".\n";

		if (items[0] % test == 0) {
			monkeys[targetA].receive(items[0]);

			cout << "    Current worry level is divisble by " << test << ".\n"
				<< "    Item with worry level " << items[0] << " is thrown to monkey " << targetA << ".\n";
		}
		else {
			monkeys[targetB].receive(items[0]);

			cout << "    Current worry level is not divisble by " << test << ".\n"
				<< "    Item with worry level " << items[0] << " is thrown to monkey " << targetB << ".\n";
		}

		items.erase(items.begin());
	}
}
