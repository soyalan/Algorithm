#include <iostream>

using namespace std;

int N;
int map[20][20];

int getsum(int uy, int ux, int ly, int lx, int ry, int rx, int dy, int dx) {
	int sum[5] = { 0 };
	int y = 0, x = ux;

	while (y < ly) {
		if (y >= uy) x--;
		for (int i = 0; i <= x; i++) sum[0] += map[y][i];
		y++;
	}

	y = 0, x = ux + 1;
	while (y <= ry) {
		for (int i = x; i < N; i++) sum[1] += map[y][i];
		if (y >= uy) x++;
		y++;
	}

	y = ly, x = lx;
	while (y < N) {
		for (int i = 0; i < x; i++) sum[2] += map[y][i];
		y++;
		if (y <= dy)x++;
	}

	y = ry + 1, x = rx;
	while (y < N) {
		for (int i = x; i < N; i++) sum[3] += map[y][i];
		if (y <= dy) x--;
		y++;
	}

	y = uy;
	int x1 = ux, x2 = ux;
	while (y <= dy) {
		for (int i = x1; i <= x2; i++) sum[4] += map[y][i];
		if (y < ly) x1--;
		else x1++;

		if (y < ry) x2++;
		else x2--;
		y++;
	}

	int amax = 0, amin = 1000000000;
	for (int i = 0; i < 5; i++) {
		if (sum[i] < amin) amin = sum[i];
		if (sum[i] > amax) amax = sum[i];
	}

	return amax - amin;
}

int cal(int uy, int ux) {
	int ly = uy, lx = ux, ry, rx, dy, dx;
	int res = 1000000000;
	while (lx > 0) {
		lx--;
		ly++;
		if (ly == N - 1) break;

		ry = uy;
		rx = ux;
		while (rx < N - 1) {
			rx++;
			ry++;
			if (ry == N - 1)break;

			dy = ry + (ly - uy);
			dx = rx - (ux - lx);
			if (dy > N - 1) continue;
			int sum = getsum(uy, ux, ly, lx, ry, rx, dy, dx);
			if (res > sum) res = sum;
		}
	}

	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cin >> map[i][j];
	int res = 100000000;
	for (int i = 0; i < N - 2; i++) {
		for (int j = 1; j < N - 1; j++) {
			int sum = cal(i, j);
			if (res > sum) res = sum;
		}
	}

	cout << res << "\n";

	return 0;
}