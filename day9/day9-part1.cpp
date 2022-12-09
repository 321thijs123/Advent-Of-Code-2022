#include "day9-part1.h"

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

Day9P1::Day9P1(string filename) {

	vector<position> headPath;

	position curPos = { 0, 0 }, minPos = { 0, 0 }, maxPos = { 0, 0 };

	headPath.push_back({ curPos.row, curPos.col });

	ifstream file(filename);
	string line;

	while (getline(file, line)) {
		const int steps = stoi(line.substr(2, line.size() - 2));

		switch (line[0]) {
		case 'U':
			for (int i = 0; i < steps; i++)	headPath.push_back({ --curPos.row,curPos.col });
			if (curPos.row < minPos.row) minPos.row = curPos.row;
			break;
		case 'D':
			for (int i = 0; i < steps; i++) headPath.push_back({ ++curPos.row, curPos.col });
			if (curPos.row > maxPos.row) maxPos.row = curPos.row;
			break;
		case 'L':
			for (int i = 0; i < steps; i++)	headPath.push_back({ curPos.row, --curPos.col });
			if (curPos.col < minPos.col) minPos.col = curPos.col;
			break;
		case 'R':
			for (int i = 0; i < steps; i++)	headPath.push_back({ curPos.row, ++curPos.col });
			if (curPos.col > maxPos.col) maxPos.col = curPos.col;
			break;
		}
	}

	vector<vector<bool>> tailVisits(maxPos.row - minPos.row + 1, vector<bool>(maxPos.col - minPos.col + 1, false));

	curPos.row = headPath[0].row;
	curPos.col = headPath[0].col;

	int N = 0;

	for (int i = 1; i < headPath.size(); i++) {
		if (abs(headPath[i].row - curPos.row) > 1 || abs(headPath[i].col - curPos.col) > 1) {
			curPos.row = headPath[i - 1].row;
			curPos.col = headPath[i - 1].col;
		}

		N += !tailVisits[curPos.row - minPos.row][curPos.col - minPos.col];
		tailVisits[curPos.row - minPos.row][curPos.col - minPos.col] = true;
	}

	cout << "\nThe tail visited " << N << " positions\n";
}
