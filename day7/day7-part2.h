#pragma once

#include <string>
#include "filesystem.h"

using namespace std;

class Day7P2 {
public:
	Day7P2(string filename);
private:
	void cd(const string line, string& path);
	File createFile(const string line);
};
