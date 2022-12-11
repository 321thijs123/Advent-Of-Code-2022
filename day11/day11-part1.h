#pragma once

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Day11P1 {
public:
	Day11P1(string filename);
	struct Monkey;
private:

};

struct Day11P1::Monkey {
	vector<int> items;
	char operation;
	int operand;
	bool twoOlds;
	int test;
	int targetA;
	int targetB;
	int inspections = 0;

	void give(vector<Monkey> &monkeys);
	void receive(int);

	/*friend ostream& operator<<(ostream& os, Day11P1::Monkey monkey) {
		os << "Items: ";
		for (int item : monkey.items) {
			os << item << ' ';
		}

		if (monkey.twoOlds) {
			os << "\nOperation: old " << monkey.operation << " old \n";
		}
		else {
			os << "\nOperation: old " << monkey.operation << ' ' << monkey.operand << '\n';
		}

		os << "Test: " << monkey.test << " -> " << monkey.targetA << " : " << monkey.targetB << '\n';

		return os;
	}*/
};