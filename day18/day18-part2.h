#pragma once

#include <string>
#include <vector>

using namespace std;

namespace day18P2 {
	void assignment(string filename);
	void flood(vector<vector<vector<char>>>& voxelmap, const int x, const int y, const int z);
	int getArea(const vector<vector<vector<char>>> voxelmap, char c);
	void show(const vector<vector<vector<char>>> voxelmap);
}
