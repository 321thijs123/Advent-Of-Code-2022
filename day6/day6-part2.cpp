#include "day6-part2.h"

#include <iostream>
#include <fstream>

using namespace std;

Day6P2::Day6P2(string filename) {
	ifstream file(filename);
	string signal;

	getline(file, signal);

	const int markerLength = 14;

	for (int i = 0; i < signal.length() - markerLength + 1; i++) {
		
		bool isMarker = true;

		for (int j = 0; j < markerLength && isMarker; j++) {
			for (int k = j+1; k < markerLength && isMarker; k++) {
				isMarker = signal[i + j] != signal[i + k];
			}
		}

		if (isMarker) {
			cout << "First marker after character " << i + markerLength << '\n';
			break;
		}
	}
}
