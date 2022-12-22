#include "day21-part2.h"

#include <fstream>
#include <iostream>

void day21P2::assignment(string filename) {
	vector<Monkey> monkeys;

	string line;
	ifstream file(filename);

	while (getline(file, line)) {
		const string name = line.substr(0, 4);

		if (line.length() == 17) {
			const string sourceA = line.substr(6, 4);
			const string sourceB = line.substr(13, 4);

			const char operation = line[11];

			monkeys.push_back(Monkey(name, sourceA, sourceB, operation));
		}
		else {
			const int number = stoi(line.substr(6, line.length() - 6));
			monkeys.push_back(Monkey(name, number));
		}
	}

	for (Monkey& monkey : monkeys) {
		if (monkey.getName() == "root") {
			bool humanDep = false;
			monkey.getNumber(monkeys, humanDep);

			monkey.requestHuman(monkeys, 0);

			break;
		}
	}
}


day21P2::Monkey::Monkey(string name, string sourceA, string sourceB, char operation) {
	this->name = name;
	this->sourceA = sourceA;
	this->sourceB = sourceB;
	this->operation = operation;
	number = LLONG_MIN;
}

day21P2::Monkey::Monkey(string name, long long number) {
	this->name = name;
	this->number = number;
}

string day21P2::Monkey::getName() {
	return name;
}

long long day21P2::Monkey::getNumber(vector<Monkey>& monkeys, bool& parentHumanDependent) {

	if (name == "humn") {
		parentHumanDependent = true;
	}

	if (number > LLONG_MIN) {
		return number;
	}

	long long valA = 0;
	long long valB = 0;

	for (Monkey& monkey : monkeys) {
		if (monkey.getName() == sourceA) valA = monkey.getNumber(monkeys, humanDependent);
		if (monkey.getName() == sourceB) valB = monkey.getNumber(monkeys, humanDependent);

		if (humanDependent) parentHumanDependent = true;
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

void day21P2::Monkey::requestHuman(vector<Monkey>& monkeys, long long require) {

	if (name == "humn") {
		cout << "Human yells " << require << '\n';
		return;
	}

	if (humanDependent) {
		long long requireA, requireB, valA, valB;

		for (Monkey& monkey : monkeys) {
			bool humanDependent;

			if (monkey.getName() == sourceA) valA = monkey.getNumber(monkeys, humanDependent);
			if (monkey.getName() == sourceB) valB = monkey.getNumber(monkeys, humanDependent);
		}


		cout << name << ":\n"
			<< "Monkey A yells " << valA << '\n'
			<< "Monkey B yells " << valB << '\n';

		if (name == "root") {
			requireA = valB;
			requireB = valA;
		}
		else {
			cout << "Used to yell " << number << '\n'
				<< "Need to yell " << require << '\n'
				<< "Operation: " << operation << '\n';

			switch (operation) {
			case '+':
				requireA = require - valB;
				requireB = require - valA;
				break;
			case '-':
				requireA = valB + require;
				requireB = valA - require;
				break;
			case '/':
				requireA = valB * require;
				requireB = valA / require;
				break;
			case '*':
				requireA = require / valB;
				requireB = require / valA;
				break;
			}
		}

		cout << '\n';

		for (Monkey& monkey : monkeys) {
			bool humanDependent;

			if (monkey.getName() == sourceA) monkey.requestHuman(monkeys, requireA);
			if (monkey.getName() == sourceB) monkey.requestHuman(monkeys, requireB);
		}
	}
}
