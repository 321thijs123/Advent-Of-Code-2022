#include "day20-part1.h"

#include <fstream>
#include <vector>
#include <iostream>

void day20P1::assignment(string filename) {
	ifstream file(filename);

	int num;

	vector<Key> sequence;

	while (file >> num) sequence.push_back(Key(num));

	const int length = sequence.size();

	for (int moves = 0; moves < length; moves++) {
		//for (Key key : sequence) cout << key.val << ' ';
		//cout << '\n';

		int i = 0;

		while (sequence[i].done) {
			i++;
			if (i >= length) i = 0;
		}

		int newI = i + sequence[i].val;

		if (newI >= length) {
			newI = newI % (length - 1);
		}

		if (newI < 0) {
			newI = newI % (length - 1);
			if (newI < 0) newI += length - 1;
		}
		
		sequence[i].done = true;

		if (newI < i) {
			sequence.insert(sequence.begin() + newI, sequence[i]);
			sequence.erase(sequence.begin() + i + 1);
		}
		else if (newI > i) {
			if (newI + 1 == length) {
				sequence.push_back(sequence[i]);
			}
			else {
				sequence.insert(sequence.begin() + newI + 1, sequence[i]);
			}
			sequence.erase(sequence.begin() + i);
		}
	}

	//for (Key key : sequence) cout << key.val << ' ';
	//cout << '\n';

	for (int i = 0; i < length; i++) {
		if (sequence[i].val == 0) {
			const int ia = (i + 1000) % length;
			const int ib = (i + 2000) % length;
			const int ic = (i + 3000) % length;

			const int a = sequence[ia].val;
			const int b = sequence[ib].val;
			const int c = sequence[ic].val;

			cout << "Zero at " << i << '\n'
				<< "1000th at " << ia << " = " << a << '\n'
				<< "2000th at " << ib << " = " << b << '\n'
				<< "3000th at " << ic << " = " << c << '\n';

			cout <<  a + b + c << '\n';
			break;
		}
	}
}
