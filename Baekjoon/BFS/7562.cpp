#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

int N;
int arr[301][301];
bool visited[301][301];
int x, y, tx, ty;
int dx[] = { -1, -1, -2, -2, 1, 1, 2, 2 };
int dy[] = { -2, 2, -1, 1, -2, 2, -1, 1 };

int bfs(int a, int b) {
	queue<pair<pair<int, int>, int> > q;
	int cnt = 0;
	q.push({ { a, b }, 0 });
	while (!q.empty()) {
		int y = q.front().first.first;
		int x = q.front().first.second;
		cnt = q.front().second;
		if (y == ty && x == tx)break;
		q.pop();
		if (visited[y][x]) continue;
		visited[y][x] = true;
		for (int k = 0; k < 8; k++) {
			int ny = y + dy[k];
			int nx = x + dx[k];
			if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
				q.push({ {ny, nx}, cnt + 1 });
			}
		}
	}
	return cnt;
}

void reset() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			arr[i][j] = 0;
			visited[i][j] = false;
		}
	}
}

int main() {
	int T, cnt;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N;
		reset();
		cin >> x >> y;
		cin >> tx >> ty;
		cnt = bfs(y, x);

		printf("%d\n", cnt);
	}

	return 0;
}