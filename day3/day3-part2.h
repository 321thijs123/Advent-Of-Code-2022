#pragma once

#include <string>

using namespace std;

class Day3P2 {
public:
	Day3P2(string filename);
private:
	char findCommon(string, string, string);
	int getPriority(char);
};