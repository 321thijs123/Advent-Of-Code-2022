#pragma once

#include <string>
#include <vector>

using namespace std;

class Day9P2 {
public:
	Day9P2(string filename);
private:
	struct position {
		void operator=(int pos[2]) {
			row = pos[2];
			col = pos[1];
		}

		int row;
		int col;
	};

	void printTail(vector<position> tail, position minPos, position maxPos);
};
