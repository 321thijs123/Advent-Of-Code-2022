#pragma once

#include <string>
#include <vector>

using namespace std;

namespace day12P1 {
	void assignment(string filename);

	class Planner {
	public:
		Planner(vector<vector<int>> map_, int row = 0, int col = 0);

		int getCost(int row, int col);
	private:
		vector<vector<int>> costmap;
		vector<vector<int>> map;

		void explore(int row, int col);
	};
}
