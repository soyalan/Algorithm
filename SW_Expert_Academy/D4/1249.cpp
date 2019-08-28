#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

int arr[101][101];
int ldata[101][101];
int n;

void bfs() {
	queue<pair<int, int>> q;
	q.push(pair<int, int>(0, 0));
	int x, y, l;
	ldata[0][0] = 0;
	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();

		if (x > 0) {
			l = ldata[y][x] + arr[y][x - 1];
			if (ldata[y][x - 1] > l) {
				ldata[y][x - 1] = l;
				q.push(pair<int, int>(y, x - 1));	
			}
		}
		if (x + 1 < n) {
			l = ldata[y][x] + arr[y][x + 1];
			if (ldata[y][x + 1] > l) {
				ldata[y][x + 1] = l;
				q.push(pair<int, int>(y, x + 1));
			}
		}
		if (y > 0) {
			l = ldata[y][x] + arr[y - 1][x];
			if (ldata[y - 1][x] > l) {
				ldata[y - 1][x] = l;
				q.push(pair<int, int>(y - 1, x));
			}
		}
		if (y + 1 < n) {
			l = ldata[y][x] + arr[y + 1][x];
			if (ldata[y + 1][x] > l) {
				ldata[y + 1][x] = l;
				q.push(pair<int, int>(y + 1, x));
			}
		}
	}
}

int main() {
	int tk;
	cin >> tk;
	for (int k = 0; k < tk; k++) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%1d", &arr[i][j]);
				ldata[i][j] = 0x7FFFFFFF;
			}
		}

		bfs();

		printf("#%d %d\n", k + 1, ldata[n - 1][n - 1]);
	}

	return 0;
}