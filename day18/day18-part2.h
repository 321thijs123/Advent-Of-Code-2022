#pragma once

#include <string>
#include <vector>

using namespace std;

namespace day18P2 {
	void assignment(string filename);
	void flood(vector<vector<vector<char>>>& voxelmap, const int x, const int y, const int z);
	int getArea(const vector<vector<vector<char>>> voxelmap, char c);
	void show(const vector<vector<vector<char>>> voxelmap);
	void generateSTL(const vector<vector<vector<char>>> voxelmap, char c);
	string stlSquare(int x1, int y1, int z1, int x2, int y2, int z2, int x3, int y3, int z3, int x4, int y4, int z4, int n1, int n2, int n3);
}
