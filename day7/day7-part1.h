#pragma once

#include <string>
#include "filesystem.h"

using namespace std;

class Day7P1 {
public:
	Day7P1(string filename);
private:
	void cd(const string line, string& path);
	File createFile(const string line);
};
