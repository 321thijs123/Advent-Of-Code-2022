#include "readers.h"

#include <fstream>

using namespace std;

vector<vector<int>> readIntLists(string path, int offset) {
	ifstream file(path);
	vector<vector<int>> ints;
	vector<int> inner;
	string line;

	for (int i = 0; i < offset; i++) {
		getline(file, line);
	}

	while (getline(file, line)) {
		if (line != "") {
			inner.push_back(stoi(line));
		}
		else {
			ints.push_back(inner);
			inner = vector<int>();
		}
	}

	return ints;
}

vector<string> readStringList(string path, int offset) {
	ifstream file(path);
	string line;
	vector<string> lines;

	for (int i = 0; i < offset; i++) {
		getline(file, line);
	}

	while (getline(file, line)) {
		lines.push_back(line);
	}

	return lines;
}

vector<vector<int>> readIntMatrix(string path, int offset) {
	ifstream file(path);
	string line;
	vector<vector<int>> table;

	for (int i = 0; i < offset; i++) {
		getline(file, line);
	}

	while (getline(file, line)) {
		vector<int> row;
		string num = "";

		for (char c : line) {
			if (c >= '0' && c <= '9') {
				num.push_back(c);
			}
			else if (num != "") {
				row.push_back(stoi(num));
				num = "";
			}
		}

		row.push_back(stoi(num));
		table.push_back(row);
	}

	return table;
}

vector<vector<int>> readDigitMatrix(string path, int zero, int offset) {
	ifstream file(path);
	string line;
	vector<vector<int>> matrix;

	for (int i = 0; i < offset; i++) {
		getline(file, line);
	}

	while (getline(file, line)) {
		vector<int> row;

		for (char c : line) {
			row.push_back(c - zero);
		}

		matrix.push_back(row);
	}

	return matrix;
}
