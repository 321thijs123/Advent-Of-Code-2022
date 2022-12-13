#pragma once

#include <string>
#include <vector>

using namespace std;

namespace day13P2 {
	void assignment(string filename);

	enum order { in, out, unknown };

	order compare(vector<string> packetA, vector<string> packetB);
	bool compare(string packetA, string packetB);

	vector<string> split(string packet);
}
