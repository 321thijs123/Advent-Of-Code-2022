#include "day9-part2.h"

#include <fstream>
#include <iostream>

using namespace std;

Day9P2::Day9P2(string filename) {

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

	const int tailLength = 10;

	vector<position> tail(tailLength, headPath[0]);

	int N = 0;

	for (int step = 1; step < headPath.size(); step++) {

		tail[0] = headPath[step];

		for (int i = 1; i < tailLength; i++) {
			if (abs(tail[i-1].row - tail[i].row) > 1 || abs(tail[i-1].col - tail[i].col) > 1) {
				tail[i].row += (tail[i].row < tail[i - 1].row);
				tail[i].row -= (tail[i].row > tail[i - 1].row);
				tail[i].col += (tail[i].col < tail[i - 1].col);
				tail[i].col -= (tail[i].col > tail[i - 1].col);
			}

			if (i == tailLength - 1) {
				N += !tailVisits[tail[i].row - minPos.row][tail[i].col - minPos.col];
				tailVisits[tail[i].row - minPos.row][tail[i].col - minPos.col] = true;
			}
		}

		//printTail(tail, minPos, maxPos);
	}

	cout << "\nThe tail visited " << N << " positions\n";
}

void Day9P2::printTail(vector<position> tail, position minPos, position maxPos) {
	for (int r = 0; r < maxPos.row - minPos.row + 1; r++) {
		for (int c = 0; c < maxPos.col - minPos.col + 1; c++) {
			bool wasATail = false;

			for (int i = 0; i < tail.size(); i++) {
				if (tail[i].col - minPos.col == c && tail[i].row - minPos.row == r) {
					cout << i;
					wasATail = true;
					break;
				}
			}

			if (!wasATail) {
				cout << '.';
			}
		}
		cout << '\n';
	}
	cout << '\n';
}