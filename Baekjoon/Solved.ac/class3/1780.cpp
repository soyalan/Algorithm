#include <iostream>

using namespace std;

int map[2188][2188];
int one, zero, mone;

void count(int y, int x) {
	if (map[y][x] == -1) mone++;
	else if (map[y][x] == 0) zero++;
	else if (map[y][x] == 1) one++;
}

bool check(int y, int x, int n) {
	for (int i = y; i < y + n; i++) {
		for (int j = x; j < x + n; j++) {
			if (map[y][x] != map[i][j]) return false;
		}
	}
	return true;
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
		int m = n / 3;
		n /= 3;
		divide(y, x, n);
		divide(y, x + m, n);
		divide(y, x + m * 2, n);
		
		divide(y + m, x, n);
		divide(y + m, x + m, n);
		divide(y + m, x + m * 2, n);

		divide(y + m * 2, x, n);
		divide(y + m * 2, x + m, n);
		divide(y + m * 2, x + m * 2, n);
	}

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	divide(0, 0, N);

	cout << mone << "\n" << zero << "\n" << one << "\n";

	return 0;
}