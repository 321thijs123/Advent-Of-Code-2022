#pragma once

#include <string>

using namespace std;

class Day3P1 {
public:
	Day3P1(string filename);
private:
	char findCommon(string, string);
	int getPriority(char);
};