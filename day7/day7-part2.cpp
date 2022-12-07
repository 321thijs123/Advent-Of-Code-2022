#include "day7-part2.h"

#include "../readers.h"

#include <iostream>
#include <algorithm>
#include <numeric>


Day7P2::Day7P2(string filename) {
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

	vector<int> sizes;

	root.getSizes(sizes);

	sort(sizes.begin(), sizes.end());

	const int used = sizes[sizes.size() - 1];
	const int toFree = used - (70000000 - 30000000);
	
	cout << "In use: " << used
		 << "\nTo be freed: " << toFree << '\n';

	for (long long size : sizes) {
		if (size > toFree) {
			cout << "Smallest large enough directory: " << size << '\n';
			return;
		}
	}
}

void Day7P2::cd(const string line, string &path) {
	if (line[5] == '.') {
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

File Day7P2::createFile(const string line) {
	const int spacePos = line.find(' ');
	int size = stoi(line.substr(0, spacePos));

	string name = "";

	for (int i = spacePos + 1; i < line.size(); i++) {
		name.push_back(line[i]);
	}

	return File(name, size);
}