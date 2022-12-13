#pragma once

#include <string>
#include <vector>

using namespace std;

namespace day13P1 {
	void assignment(string filename);

	enum order { in, out, unknown };

	order compare(vector<string> packetA, vector<string> packetB);

	vector<string> split(string packet);
}
