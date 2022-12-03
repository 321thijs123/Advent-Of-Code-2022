#include "readers.h"

#include <fstream>

using namespace std;

vector<vector<int>> readIntLists(string path) {
	ifstream file(path);
	vector<vector<int>> ints;
	vector<int> inner;
	string line;

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

vector<string> readStringList(string path) {
	ifstream file(path);
	string line;
	vector<string> lines;

	while (getline(file, line)) {
		lines.push_back(line);
	}

	return lines;
}