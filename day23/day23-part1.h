#pragma once

#include <string>
#include <vector>

using namespace std;

namespace day23P1 {
	void assignment(string filename);
	
	enum Direction {
		N, S, W, E, stay
	};

	struct Elf {
		bool isElf = false;
		Direction proposal;
	};
}
