#include <iostream>

using namespace std;

int N;
int map[128][128];
int white = 0, blue = 0;

bool check(int y, int x, int n) {
	for (int i = y; i < y + n; i++) {
		for (int j = x; j < x + n; j++) {
			if (map[i][j] != map[y][x]) return false;
		}
	}
	return true;
}

void count(int y, int x) {
	if (map[y][x]) blue++;
	else white++;
}

void divide(int y, int x, int n) {
	if (n == 1) {
		count(y, x);
		return;
	}

	if (check(y, x, n)) {
		count(y, x);
	}
	else {
		divide(y, x, n / 2);
		divide(y, x + (n / 2), n / 2);
		divide(y + (n / 2), x, n / 2);
		divide(y + (n / 2), x + (n / 2), n / 2);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cin >> map[i][j];

	divide(0, 0, N);

	cout << white << "\n" << blue << "\n";

	return 0;
}