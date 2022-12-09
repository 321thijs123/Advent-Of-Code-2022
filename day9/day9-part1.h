#pragma once

#include <string>

using namespace std;

class Day9P1 {
public:
	Day9P1(string filename);
private:
	struct position {
		void operator=(int pos[2]) {
			row = pos[2];
			col = pos[1];
		}

		int row;
		int col;
	};
};
