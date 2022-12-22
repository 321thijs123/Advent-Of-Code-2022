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
	string stlSquare(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3, float x4, float y4, float z4, float n1, float n2, float n3);
}
