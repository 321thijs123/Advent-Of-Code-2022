#include "day18-part1.h"

#include "../readers.h";

#include <iostream>

void day18P1::assignment(string filename) {
	vector<vector<int>> cubes = readIntMatrix(filename);

	int area = 0;

	for (vector<int> cubeA : cubes){
		int freeSides = 6;

		for (vector<int> cubeB : cubes) {
			if ((cubeA[0] == cubeB[0] && cubeA[1] == cubeB[1] && abs(cubeA[2] - cubeB[2]) == 1) ||
				(cubeA[2] == cubeB[2] && cubeA[0] == cubeB[0] && abs(cubeA[1] - cubeB[1]) == 1) ||
				(cubeA[1] == cubeB[1] && cubeA[2] == cubeB[2] && abs(cubeA[0] - cubeB[0]) == 1)) {

				freeSides--;

				if (freeSides == 0) break;
			}
		}
		area += freeSides;
	}

	cout << area;
}
