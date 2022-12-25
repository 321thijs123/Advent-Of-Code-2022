#pragma once

#include <string>

using namespace std;

namespace day20P1 {
	void assignment(string filename);

	struct Key {
		Key(int val) {
			this->val = val;
			done = false;
		}

		int val;
		int done;
	};
}
