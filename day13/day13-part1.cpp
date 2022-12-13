#include "day13-part1.h"

#include <fstream>
#include <iostream>

using namespace std;

void day13P1::assignment(string filename) {
	ifstream file(filename);

	string line;

	int i = 1;

	int sum = 0;

	while (getline(file, line)) {
		if (line == "") continue;

		vector<string> packetA = split(line);
		
		getline(file, line);
		
		vector<string> packetB = split(line);

		cout << "== Pair " << i << " ==\n";

		if (compare(packetA, packetB) == in) {
			sum += i;
			cout << "In order\n\n";
		}
		else {
			cout << "Not in order\n\n";
		}

		i++;
	}

	cout << "\nSum: " << sum << '\n';
}

day13P1::order day13P1::compare(vector<string> packetA, vector<string> packetB) {
	const int shortest = packetA.size() < packetB.size() ? packetA.size() : packetB.size();
	
	if (packetA[0].size() == 0) {		// Empty packet A
		if (packetB[0].size() == 0) {
			return unknown;
		}
		else {
			return in;
		}
	}
	else if (packetB[0].size() == 0) {	// Empty packet B
		return out;
	}

	for (int i = 0; i < shortest; i++) {
		cout << "- Compare " << packetA[i] << " vs " << packetB[i] << '\n';

		if (packetA[i][0] != '[' && packetB[i][0] != '[') {	// Both integers
			const int intA = stoi(packetA[i]);
			const int intB = stoi(packetB[i]);

			if (intA < intB) {
				return in;
			}
			else if (intA > intB) {
				return out;
			}
		}
		else if (packetA[i][0] != '[') {							// A integer, B list
			const day13P1::order result = compare(vector<string>(1, packetA[i]), split(packetB[i]));

			if (result == in) {
				return in;
			}
			else if (result == out) {
				return out;
			}
		}
		else if (packetB[i][0] != '[') {							// A list, B integer
			const day13P1::order result = compare(split(packetA[i]), vector<string>(1, packetB[i]));

			if (result == in) {
				return in;
			}
			else if (result == out) {
				return out;
			}
		}
		else {														// Both lists
			const day13P1::order result = compare(split(packetA[i]), split(packetB[i]));

			if (result == in) {
				return in;
			}
			else if (result == out) {
				return out;
			}
		}
	}

	if (packetA.size() == packetB.size()) return unknown;

	return packetA.size() < packetB.size() ? in : out;
}

vector<string> day13P1::split(string packet) {
	vector<string> result;

	int i = 1;

	bool done = false;

	while (!done && i < packet.size()) {
		string section;

		if (packet[i] == '[') {					// A subpacket
			i++;								// Jump past the bracket
			
			int bracketLevel = 1;				// Amount of open brackets

			section = "[";

			while (bracketLevel != 0) {
				bracketLevel += (packet[i] == '[') - (packet[i] == ']');

				section.push_back(packet[i]);
				
				i++;
			}
		}
		else {											// An integer
			while (packet[i] != ',') {					// Loop untill end of value
				if (packet[i] == ']') {					// If ']' -> end of packet
					done = true;
					break;
				};

				section.push_back(packet[i]);
				i++;
			}
		}

		result.push_back(section);

		i++;
	}

	return result;
}