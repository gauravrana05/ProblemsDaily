#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

struct Cow {
	int start, end;
};

int main() {
	freopen("lifeguards.in", "r", stdin);
	int n;
	cin >> n;

	vector<Cow> lifeguards(n);
	int max_time = 0;  // Max time we'll have to process up to
	for (Cow &l : lifeguards) {
		cin >> l.start >> l.end;
		max_time = max(max_time, l.end);
	}

	/*
	 * Simulate firing each lifeguard and compute the total
	 * time covered by the remaining lifeguards
	 */
	int max_cover = 0;
	for (int i = 0; i < n; i++) {
		int time_covered = 0;
		// Try to find a cow that can cover this interval
		for (int t = 1; t <= max_time; t++) {
			for (int j = 0; j < n; j++) {
				// Check that it's not the fired cow
				if (j != i) {
					if (lifeguards[j].start <= t && t < lifeguards[j].end) {
						// One more time slot covered- no need to search further
						time_covered++;
						break;
					}
				}
			}
		}
		max_cover = max(max_cover, time_covered);
	}

	freopen("lifeguards.out", "w", stdout);
	cout << max_cover << endl;
}