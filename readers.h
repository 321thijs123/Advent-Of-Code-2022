#pragma once

#include <vector>
#include <string>

using namespace std;

vector<vector<int>> readIntLists(string path, int offset=0);
vector<string> readStringList(string path, int offset=0);
vector<vector<int>> readIntMatrix(string path, int offset=0);
vector<vector<int>> readDigitMatrix(string path, int zero = '0', int offset=0);