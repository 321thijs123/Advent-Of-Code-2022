#include "day21-part1.h"

#include <fstream>
#include <iostream>

void day21P1::assignment(string filename) {
	vector<Monkey> monkeys;

	string line;
	ifstream file(filename);

	while (getline(file, line)) {
		const string name = line.substr(0, 4);

		if (line.length() == 17) {
			const string sourceA = line.substr(6, 4);
			const string sourceB = line.substr(13, 4);

			monkeys.push_back(Monkey(name, sourceA, sourceB, line[11]));
		}
		else {
			const int number = stoi(line.substr(6, line.length() - 6));
			monkeys.push_back(Monkey(name, number));
		}
	}

	for (Monkey& monkey : monkeys) {
		if (monkey.getName() == "root") {
			cout << monkey.getNumber(monkeys) << '\n';
			break;
		}
	}
}


day21P1::Monkey::Monkey(string name, string sourceA, string sourceB, char operation) {
	this->name = name;
	this->sourceA = sourceA;
	this->sourceB = sourceB;
	this->operation = operation;
	number = LLONG_MIN;
}

day21P1::Monkey::Monkey(string name, long long number) {
	this->name = name;
	this->number = number;
}

string day21P1::Monkey::getName() {
	return name;
}

long long day21P1::Monkey::getNumber(vector<Monkey>& monkeys) {

	if (number > LLONG_MIN) {
		return number;
	}

	long long valA = 0;
	long long valB = 0;

	for (Monkey& monkey : monkeys) {
		if (monkey.getName() == sourceA) valA = monkey.getNumber(monkeys);
		if (monkey.getName() == sourceB) valB = monkey.getNumber(monkeys);
	}

	switch (operation) {
	case '+':
		number = valA + valB;
		break;
	case '-':
		number = valA - valB;
		break;
	case '*':
		number = valA * valB;
		break;
	case '/':
		number = valA / valB;
		break;
	}

	return number;
}
