#pragma once

#include <string>
#include <vector>

using namespace std;

namespace day21P1 {
	void assignment(string filename);

	class Monkey {
	public:
		Monkey(string name, string sourceA, string sourceB, char operation);
		Monkey(string name, long long number);

		long long getNumber(vector<Monkey>& monkeys);
		string getName();

	private:
		string name;
		string sourceA;
		string sourceB;
		char operation;
		long long number;
	};
}
