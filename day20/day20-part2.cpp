#include "day20-part2.h"

#include <fstream>
#include <vector>
#include <iostream>

void day20P2::assignment(string filename) {
	ifstream file(filename);

	long long num;

	vector<Key> sequence;

	long long id = 0;

	cout << "Initial arrangement:\n";

	while (file >> num) {
		sequence.push_back(Key(id, num * 811589153));
		id++;
	};

	const long long length = sequence.size();

	for (int round = 0; round < 10; round++) {
		id = 0;

		for (int moves = 0; moves < length; moves++) {

			long long i = 0;

			while (sequence[i].id != id) {
				i++;
				if (i >= length) i = 0;
			}

			long long newI = i + sequence[i].val;

			if (newI >= length) {
				newI = newI % (length - 1);
			}

			if (newI < 0) {
				newI = newI % (length - 1);
				if (newI < 0) newI += length - 1;
			}

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

			id++;
		}
	}

	for (int i = 0; i < length; i++) {
		if (sequence[i].val == 0) {
			const int ia = (i + 1000) % length;
			const int ib = (i + 2000) % length;
			const int ic = (i + 3000) % length;

			const long long a = sequence[ia].val;
			const long long b = sequence[ib].val;
			const long long c = sequence[ic].val;

			cout << "Zero at " << i << '\n'
				<< "1000th at " << ia << " = " << a << '\n'
				<< "2000th at " << ib << " = " << b << '\n'
				<< "3000th at " << ic << " = " << c << '\n';

			cout << a + b + c << '\n';
			break;
		}
	}
}
