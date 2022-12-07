#include "day7-part1.h"

#include "../readers.h"

#include <iostream>


Day7P1::Day7P1(string filename) {
	vector<string> terminal = readStringList(filename);

	string path = "";

	Directory root("");

	for (string line : terminal) {
		if (line[2] == 'c' && line[3] == 'd') {
			cd(line, path);
		}
		else if (line[0] >= '0' && line[0] <= '9') {
			root.addFile(path, createFile(line));
		}
	}

	int sizeSum = 0;

	const int maxSize = 100000;

	root.getSize(maxSize, sizeSum);

	cout << "Sum of folders smaller than " << maxSize << ": " << sizeSum << '\n';
}

void Day7P1::cd(const string line, string &path) {
	if (line[5] == '.' && line[6] == '.') {
		path.pop_back();

		while (path.back() != '/') {
			path.pop_back();
		}
	}
	else {
		for (int i = 5; i < line.size(); i++) {
			path.push_back(line[i]);
		}
		if (path.back() != '/') {
			path.push_back('/');
		}
	}
}

File Day7P1::createFile(const string line) {
	const int spacePos = line.find(' ');
	int size = stoi(line.substr(0, spacePos));

	string name = "";

	for (int i = spacePos + 1; i < line.size(); i++) {
		name.push_back(line[i]);
	}

	return File(name, size);
}