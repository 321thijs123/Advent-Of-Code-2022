#include "day5-part1.h"

#include "../readers.h"

#include <iostream>
#include <fstream>

using namespace std;

Day5P1::Day5P1(string filename) {
	int linesRead = readStacks(filename);

	vector<vector<int>> moves = readIntMatrix(filename, linesRead + 2);

	for (int i = 0; i < moves.size(); i++) {
		const int N = moves[i][0];
		vector<char> &source = stacks[moves[i][1] - 1];
		vector<char> &target = stacks[moves[i][2] - 1];

		for (int i = 0; i < N; i++) {
			target.push_back(source[source.size()-1]);
			source.pop_back();
		}
	}

	cout << "Top crates:\n";

	for (vector<char> stack : stacks) {
		cout << stack[stack.size() - 1];
	}

	cout << '\n';
}

int Day5P1::readStacks(string filename) {
	ifstream file(filename);
	string line;
	int linesRead = 0;

	while (getline(file, line) && line[1] != '1') {
		linesRead++;

		for (int stack = 0; stack < (line.length() + 1) / 4; stack++) {
			char crate = line[stack * 4 + 1];
			
			if (stacks.size() <= stack)
				stacks.push_back(vector<char>());
			
			if (crate != ' ')
				stacks[stack].push_back(crate);
		}
	}

	for (vector<char>& stack : stacks) {
		reverse(stack.begin(), stack.end());
	}

	return linesRead;
}