#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<array<int, 3>> cows;
vector<array<int, 4>> air_conditioners;
vector<bool> uses;
int min_cost = numeric_limits<int>().max();

void update() {
	bool is_feasible = true;
	for (int i = 1; i <= 100; i++) {
		int cooling = 0;
		for (int j = 0; j < M; j++) {
			if (!uses[j]) { continue; }
			auto &[a, b, p, m] = air_conditioners[j];
			if (a <= i && i <= b) { cooling += p; }
		}


		int cow_requirement = 0;
		for (int j = 0; j < N; j++) {
			auto &[s, t, c] = cows[j];
			if (s <= i && i <= t) {
				cow_requirement = c;
				break;
			}
		}

		if (cooling < cow_requirement) {
			is_feasible = false;
			break;
		}
	}

	if (is_feasible) {
		int cost = 0;
		for (int i = 0; i < M; i++) {
			if (uses[i]) { cost += air_conditioners[i][3]; }
		}
		min_cost = min(min_cost, cost);
	}
}

void search(int i) {
	if (i == M) {
		update();
	} else {
		uses[i] = false;
		search(i + 1);
		uses[i] = true;
		search(i + 1);
	}
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int s, t, c;
		cin >> s >> t >> c;
		cows.push_back({s, t, c});
	}

	for (int i = 0; i < M; i++) {
		int a, b, p, m;
		cin >> a >> b >> p >> m;
		air_conditioners.push_back({a, b, p, m});
	}

	uses.assign(M, false);
	search(0);

	cout << min_cost << endl;
}