#include <iostream>
#include <algorithm>

using namespace std;

int arr[50][9];
int lineup[8] = { 2,3,4,5,6,7,8,9 };
int tmp[9] = { 0,0,0,1,0,0,0,0,0 };
int N, res;

void baseball(int ining, int n, int score) {
	if (ining == N) {
		res = max(score, res);
		return;
	}

	int out = 0;
	int map[4] = { 0 };
	while (out < 3) {
		int ball = arr[ining][tmp[n] - 1];

		if (ball == 0) {
			out++;
		}
		else if (ball == 1) {
			if (map[3]) {
				score += 1;
				map[3] = 0;
			}
			if (map[2]) {
				map[3] = 1;
				map[2] = 0;
			}
			if (map[1]) {
				map[2] = 1;
			}
			map[1] = 1;
		}
		else if (ball == 2) {
			if (map[3]) {
				score += 1;
				map[3] = 0;
			}
			if (map[2]) {
				score += 1;
			}
			if (map[1]) {
				map[3] = 1;
				map[1] = 0;
			}
			map[2] = 1;
		}
		else if (ball == 3) {
			if (map[3]) {
				score += 1;
			}
			if (map[2]) {
				score += 1;
				map[2] = 0;
			}
			if (map[1]) {
				score += 1;
				map[1] = 0;
			}
			map[3] = 1;
		}
		else if(ball == 4) {
			if (map[3]) {
				score += 1;
				map[3] = 0;
			}
			if (map[2]) {
				score += 1;
				map[2] = 0;
			}
			if (map[1]) {
				score += 1;
				map[1] = 0;
			}
			score += 1;
		}

		n++;
		if (n == 9) n = 0;
	}
	baseball(ining + 1, n, score);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) for (int j = 0; j < 9; j++) cin >> arr[i][j];

	do {
		for (int i = 0; i < 8; i++) {
			if (i < 3) tmp[i] = lineup[i];
			else tmp[i + 1] = lineup[i];
		}

		baseball(0, 0, 0);
		
	} while (next_permutation(lineup, lineup + 8));

	cout << res << "\n";

	return 0;
}