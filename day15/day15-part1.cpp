#include "day15-part1.h"

#include "../readers.h"

#include <iostream>

void day15P1::assignment(string filename) {
	vector<vector<int>> input = readIntMatrix(filename);

	// Variables to know how long to make the map
	int minX = INT_MAX;
	int maxX = INT_MIN;

	// Vector of sensor struct
	vector<Sensor> sensors;

	// Look for largest and smallests X values and add them to the sensors vector
	for (vector<int>& row : input) {
		const Sensor sensor(row[0], row[1], row[2], row[3]);
		sensors.push_back(sensor);

		if (sensor.x - sensor.reach < minX) minX = sensor.x - sensor.reach;
		if (sensor.x + sensor.reach > maxX) maxX = sensor.x + sensor.reach;
	}

	// The map
	string map(maxX - minX + 1, '.');

	// The row to look at
	int targetRow = 2000000;

	// Marking positions where the beacon isnt
	for (Sensor& sensor : sensors) {														// Loop through all sensors
		cout << sensor.x << '\t' << sensor.y << '\t' << sensor.bx << '\t' << sensor.by << '\n';
		if (sensor.y - sensor.reach <= targetRow && sensor.y + sensor.reach >= targetRow) {	// If the sensor reaches the row we are interested in
			const int xReach = sensor.reach - abs(targetRow - sensor.y);					// Calculate how much it goes to the left and right at that point

			for (int x = sensor.x - xReach; x <= sensor.x + xReach; x++) {					// Go through all x that the sensor reaches
				map[x - minX] = '#';
			}
		}
	}

	// Marking positions where beacons are for sure
	for (Sensor& sensor : sensors) {														// Loop through all sensors
		if (sensor.by == targetRow) {
			map[sensor.bx - minX] = 'B';
		}
	}

	// Count of places where the beacon isn't
	int N = 0;

	for (char c : map) {
		if (c == '#') N++;
	}

	//cout << map << '\n';

	cout << "The beacon at least isn't in " << N << " places\n";

	/*
	* Wrong answers
	* 5044284 -> Too ?
	* 3392780 -> Too low
	* 3392788 -> Too ?
	* 5044285 -> Too ?
	* 4880739 -> Too ?
	*/
}
