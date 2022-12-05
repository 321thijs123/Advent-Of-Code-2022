#include "day5-part2.h"

#include "../readers.h"

#include <iostream>
#include <fstream>

using namespace std;

Day5P2::Day5P2(string filename) {
	int linesRead = readStacks(filename);

	vector<vector<int>> moves = readIntMatrix(filename, linesRead + 2);

	for (int i = 0; i < moves.size(); i++) {
		const int N = moves[i][0];
		vector<char> &source = stacks[moves[i][1] - 1];
		vector<char> &target = stacks[moves[i][2] - 1];

		for (int i = 0; i < N; i++) {
			target.push_back(source[source.size()-N+i]);
		}
		for (int i = 0; i < N; i++) {
			source.pop_back();
		}
	}

	cout << "Top crates:\n";

	for (vector<char> stack : stacks) {
		cout << stack[stack.size() - 1];
	}

	cout << "\n";
}

int Day5P2::readStacks(string filename) {
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