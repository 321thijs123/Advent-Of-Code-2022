#include "day15-part2.h"

#include "../readers.h"

#include <iostream>

void day15P2::assignment(string filename) {
	vector<vector<int>> input = readIntMatrix(filename);

	// Vector of sensor struct
	vector<Sensor> sensors;

	for (vector<int>& row : input) {
		const Sensor sensor(row[0], row[1], row[2], row[3]);
		sensors.push_back(sensor);
	}

	// Maximum X and Y to consider
	const int dimensions = 4000000;

	// Upper and lower limits of sections on each row where the beacon isnt
	vector<vector<pair<int, int>>> limits(dimensions + 1);

	// Marking positions where the beacon isnt
	for (int targetRow = 0; targetRow <= dimensions; targetRow++) {
		for (Sensor& sensor : sensors) {																// Loop through all sensors
			if (sensor.y - sensor.reach <= targetRow && sensor.y + sensor.reach >= targetRow) {			// If the sensor reaches the row we are interested in
				const int xReach = sensor.reach - abs(targetRow - sensor.y);							// Calculate how much it goes to the left and right at that point

				mergeLimits(pair<int, int>(sensor.x - xReach, sensor.x + xReach), limits[targetRow]);
			}
		}
	}

	// Find the position where the beacon is
	for (int y = 0; y < limits.size(); y++) {
		if (limits[y].size() > 1) {
			cout << "Y: " << y << "\tX: ";
			for (const pair<int, int> limit : limits[y]) {
				cout << '[' << limit.first << ',' << limit.second << "] ";
			}
			cout << '\n';

			int x;

			if (limits[y][0].second < limits[y][1].first) {
				x = limits[y][0].second + 1;
			}
			else {
				x = limits[y][1].second + 1;
			}

			long long tuningFrequency = (long long) x * 4000000 + (long long)y;

			cout << "X: " << x << '\n'
				<< "Tuning frequency: " << tuningFrequency << '\n';
		}
	}

	cout << "Done\n";
}

void day15P2::mergeLimits(pair<int, int> limit, vector<pair<int, int>>& limits) {

	for (int i = 0; i < limits.size(); i++) {
		if (limits[i].first <= limit.first && limits[i].second >= limit.second) {			// Self fully contained
			return;
		}
		else if (limit.first <= limits[i].first && limit.second >= limits[i].second) {		// Other fully contained
			limits.erase(limits.begin() + i);
			mergeLimits(limit, limits);
			return;
		}
		else if (limit.first >= limits[i].first && limit.first - 1 <= limits[i].second) {	// Lower limit contained
			limit.first = limits[i].first;
			limits.erase(limits.begin() + i);
			mergeLimits(limit, limits);
			return;
		}
		else if (limit.second + 1 >= limits[i].first && limit.second <= limits[i].second) {	// Upper limit contained
			limit.second = limits[i].second;
			limits.erase(limits.begin() + i);
			mergeLimits(limit, limits);
			return;
		}
	}

	limits.push_back(limit);
}
