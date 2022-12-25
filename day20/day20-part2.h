#pragma once

#include <string>

using namespace std;

namespace day20P2 {
	void assignment(string filename);

	struct Key {
		Key(int id, long long val) {
			this->id = id;
			this->val = val;
		}

		long long val;
		int id;
	};
}
