#include "day18-part2.h"

#include "../readers.h";

#include <iostream>
#include <fstream>

void day18P2::assignment(string filename) {
	vector<vector<int>> cubes = readIntMatrix(filename);

	int xMin = INT_MAX;
	int yMin = INT_MAX;
	int zMin = INT_MAX;
	int xMax = INT_MIN;
	int yMax = INT_MIN;
	int zMax = INT_MIN;

	for (vector<int> cube : cubes) {
		if (cube[0] < xMin) xMin = cube[0];
		if (cube[0] > xMax) xMax = cube[0];
		if (cube[1] < yMin) yMin = cube[1];
		if (cube[1] > yMax) yMax = cube[1];
		if (cube[2] < zMin) zMin = cube[2];
		if (cube[2] > zMax) zMax = cube[2];
	}

	xMin--;
	yMin--;
	zMin--;
	xMax++;
	yMax++;
	zMax++;

	vector<vector<vector<char>>> voxelmap(xMax-xMin+1, vector<vector<char>>(yMax - yMin + 1, vector<char>(zMax - zMin + 1, '.')));

	for (vector<int> cube : cubes) {
		voxelmap[cube[0]-xMin][cube[1]-yMin][cube[2]-zMin] = '#';
	}

	flood(voxelmap, 0, 0, 0);

	show(voxelmap);

	generateSTL(voxelmap, '#');

	cout << getArea(voxelmap, '~') << '\n';
}

void day18P2::flood(vector<vector<vector<char>>>& voxelmap, const int x, const int y, const int z) {
	voxelmap[x][y][z] = '~';

	if (x > 0 && voxelmap[x - 1][y][z] == '.') flood(voxelmap, x - 1, y, z);
	if (y > 0 && voxelmap[x][y - 1][z] == '.') flood(voxelmap, x, y - 1, z);
	if (z > 0 && voxelmap[x][y][z - 1] == '.') flood(voxelmap, x, y, z - 1);

	if (x < voxelmap.size() - 1       && voxelmap[x + 1][y][z] == '.') flood(voxelmap, x + 1, y, z);
	if (y < voxelmap[0].size() - 1    && voxelmap[x][y + 1][z] == '.') flood(voxelmap, x, y + 1, z);
	if (z < voxelmap[0][0].size() - 1 && voxelmap[x][y][z + 1] == '.') flood(voxelmap, x, y, z + 1);
}

int day18P2::getArea(const vector<vector<vector<char>>> voxelmap, char c) {
	int area = 0;

	for (int x = 0; x < voxelmap.size(); x++) {
		for (int y = 0; y < voxelmap[0].size(); y++) {
			for (int z = 0; z < voxelmap[0][0].size(); z++) {
				if (voxelmap[x][y][z] == c) {
					if (x > 0 && voxelmap[x - 1][y][z] != c) area++;
					if (y > 0 && voxelmap[x][y - 1][z] != c) area++;
					if (z > 0 && voxelmap[x][y][z - 1] != c) area++;
					
					if (x < voxelmap.size() - 1       && voxelmap[x + 1][y][z] != c) area++;
					if (y < voxelmap[0].size() - 1    && voxelmap[x][y + 1][z] != c) area++;
					if (z < voxelmap[0][0].size() - 1 && voxelmap[x][y][z + 1] != c) area++;
				}
			}
		}
	}

	return area;
}

void day18P2::show(const vector<vector<vector<char>>> voxelmap) {
	for (vector<vector<char>> slice : voxelmap) {
		for (vector<char> row : slice) {
			for (char voxel : row) {
				cout << voxel;
			}
			cout << '\n';
		}
		cout << "\n\n";
	}
}

void day18P2::generateSTL(const vector<vector<vector<char>>> voxelmap, char c) {
	ofstream file;

	file.open("blob.stl", ios::trunc);

	file << "solid \"Blob\"" << '\n';

	for (int x = 0; x < voxelmap.size(); x++) {
		for (int y = 0; y < voxelmap[0].size(); y++) {
			for (int z = 0; z < voxelmap[0][0].size(); z++) {
				if (voxelmap[x][y][z] == c) {
					if (x > 0 && voxelmap[x - 1][y][z] != c) {
						file << stlSquare(x, y, z, x, y + 1, z, x, y + 1, z + 1, x, y, z + 1, -1, 0, 0);
					}
					if (y > 0 && voxelmap[x][y - 1][z] != c) {
						file << stlSquare(x, y, z, x + 1, y, z, x + 1, y, z + 1, x, y, z + 1, 0, -1, 0);
					}
					if (z > 0 && voxelmap[x][y][z - 1] != c) {
						file << stlSquare(x, y, z, x, y + 1, z, x + 1, y + 1, z, x + 1, y, z, 0, 0, -1);
					}
					if (x < voxelmap.size() - 1 && voxelmap[x + 1][y][z] != c) {
						file << stlSquare(x + 1, y, z, x + 1, y + 1, z, x + 1, y + 1, z + 1, x + 1, y, z + 1, 1, 0, 0);
					}
					if (y < voxelmap[0].size() - 1 && voxelmap[x][y + 1][z] != c) {
						file << stlSquare(x, y + 1, z, x + 1, y + 1, z, x + 1, y + 1, z + 1, x, y + 1, z + 1, 0, 1, 0);
					}
					if (z < voxelmap[0][0].size() - 1 && voxelmap[x][y][z + 1] != c) {
						file << stlSquare(x, y, z + 1, x, y + 1, z + 1, x + 1, y + 1, z + 1, x + 1, y, z + 1, 0, 0, 1);
					}
				}
			}
		}
	}

	file << "endsolid \"Blob\"" << '\n';

	file.close();
}

string day18P2::stlSquare(int x1, int y1, int z1, int x2, int y2, int z2, int x3, int y3, int z3, int x4, int y4, int z4, int n1, int n2, int n3) {
	return
		"facet normal " + to_string(n1) + ' ' + to_string(n2) + ' ' + to_string(n3) + '\n' +
		"outer loop" + '\n' +
		"vertex " + to_string(x1) + ' ' + to_string(y1) + ' ' + to_string(z1) + '\n' +
		"vertex " + to_string(x2) + ' ' + to_string(y2) + ' ' + to_string(z2) + '\n' +
		"vertex " + to_string(x3) + ' ' + to_string(y3) + ' ' + to_string(z3) + '\n' +
		"endloop" + '\n' +
		"endfacet" + "\n\n" +
		"facet normal " + to_string(n1) + ' ' + to_string(n2) + ' ' + to_string(n3) + '\n' +
		"outer loop" + '\n' +
		"vertex " + to_string(x1) + ' ' + to_string(y1) + ' ' + to_string(z1) + '\n' +
		"vertex " + to_string(x4) + ' ' + to_string(y4) + ' ' + to_string(z4) + '\n' +
		"vertex " + to_string(x3) + ' ' + to_string(y3) + ' ' + to_string(z3) + '\n' +
		"endloop" + '\n' +
		"endfacet" + "\n\n";
}
