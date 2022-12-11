#pragma once

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Day11P2 {
public:
	Day11P2(string filename);
	struct Monkey;
private:

};

struct Day11P2::Monkey {
	vector<long long> items;
	char operation;
	int operand;
	bool twoOlds;
	int test;
	int targetA;
	int targetB;
	int inspections = 0;

	void give(vector<Monkey>& monkeys, int stressDivider);
	void receive(int);
};