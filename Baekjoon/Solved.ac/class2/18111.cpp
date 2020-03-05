#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M, B;
int map[500][500];

int find(int n) {
	int cnt = B;
	int time = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int m = map[i][j];
			if (n < m) {
				int tmp = m - n;
				cnt += tmp;
				time += (tmp * 2);
			}
			else if (n > m) {
				int tmp = n - m;
				cnt -= tmp;
				time += tmp;
			}
		}
	}
	if (cnt < 0) return 1000000000;
	return time;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> B;
	int mmin = 100000000, mmax = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			mmin = min(mmin, map[i][j]);
			mmax = max(mmax, map[i][j]);
		}
	}
	mmax = min(mmax, 256);

	int time = 1000000000, res = 0;
	for (int n = mmin; n <= mmax; n++) {
		int tmp = find(n);
		if (tmp <= time) {
			time = tmp;
			res = n;
		}
	}

	cout << time << " " << res << "\n";

	return 0;
}