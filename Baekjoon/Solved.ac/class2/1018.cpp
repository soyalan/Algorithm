#include <iostream>
#include <cmath>

using namespace std;

int N, M;
char map[50][50];
int res = 100000000;

bool check(char a) {
	if (a == 'B') return true;
	else return false;
}

int find(int y, int x, bool black) {
	int cnt = 0;
	for (int i = y; i < y + 8; i++) {
		for (int j = x; j < x + 8; j++) {
			if (check(map[i][j]) != black) cnt++;
			black = !black;
		}
		black = !black;
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) cin >> map[i][j];

	for (int i = 0; i < N - 7; i++) {
		for (int j = 0; j < M - 7; j++) {
			int tmp1 = find(i, j, check(map[i][j]));
			int tmp2 = find(i, j, !check(map[i][j]));
			if (tmp1 < res) res = tmp1;
			if (tmp2 < res) res = tmp2;
		}
	}

	cout << res << "\n";

	return 0;
}